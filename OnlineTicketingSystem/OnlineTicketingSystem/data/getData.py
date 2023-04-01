import requests
import pandas as pd
import re
from tqdm import tqdm
#浏览器请求头
headers={
        'user-agent': 'Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/70.0.3538.25 Safari/537.36 Core/1.70.3741.400 QQBrowser/10.5.3868.400'
        }

class Train:
    def __init__(self):
        pass
 #获取所有的省、直辖市名字
    def Province_url(self):
        self.province_url = []
        out_url = 'https://qq.ip138.com/train/'
        response = requests.get(out_url,headers = headers)
        result = re.findall(r'<dd><a href="/train/(.*?)" target="', response.text)
        for province in result:
            self.province_url.append(out_url + province)
#获取所有车站名
    def Station_name(self):
        self.station_name = []
        self.station_name_pinyin = []
        for province_url in self.province_url:
            try:
                response = requests.get(province_url,headers = headers)
                response.encoding = 'utf-8'
                station_name = re.findall(r'<a href="/train/.*?" target="_blank">(.*?)</a></li>',response.text)
                self.station_name.append(station_name)
                station_name_pinyin = re.findall(r'<a href="/train/(.*?)" target="_blank">.*?</a></li>',response.text)
                self.station_name_pinyin.append(station_name_pinyin)              
            except:
                print('{}链接获取失败'.format(province_url))
                pass
                        
        self.station_name = [item for sublist in self.station_name for item in sublist]
        self.station_name_pinyin = [item for sublist in self.station_name_pinyin for item in sublist]
        print('成功获取{}个站点名'.format(len(self.station_name)))
#获取所有车站的信息
    def Station_information(self):
        self.station_data = []
        self.train_num = []
        for i in tqdm(range(len(self.station_name))):
            url_1 = 'https://qq.ip138.com/train/' + self.station_name_pinyin[i]
            try:
                response = requests.get(url_1,headers = headers)
                response.encoding = 'utf-8'
                train_num = re.findall(r'<a href="/train/.*?.htm" target="_blank"><b>(.*?)</b></a>',response.text)
                train_num_count = len(train_num)
                self.train_num.append(train_num)
            except:
                print('{}站车次信息获取失败'.format(self.station_name[i]))
                pass
            
            station_name = self.station_name[i] + '站'
            try:
            #获取经纬度，这里的AG开头后面的一长串就是百度地图密匙
                url_2 = 'https://api.map.baidu.com/geocoding/v3/?address={}&output=json&ak=AG4BbquVB87KwW1hS6wCMQRx1PYKNqhj'.format(station_name)
                dic = requests.get(url_2).json()
                lng = dic['result']['location']['lng']
                lat = dic['result']['location']['lat']
                #这里面有很多站点并不是火车站，使用一个if语句过滤那些不是火车站的站点
                if dic['result']['level'] == '火车站':
                    data = {
                    'station_name':station_name,
                    'lacation':str(lng) + ',' + str(lat),
                    'train_num':train_num,
                    'train_num_count':train_num_count
                    }
                    print(data)
                    self.station_data.append(data)
                else:
                    print('{}不属于火车站！'.format(station_name))
            except:
                pass
            
        self.train_num = [item for sublist in self.train_num for item in sublist]
        self.train_num = list(set(self.train_num))
        result = pd.DataFrame(self.station_data)
        result.to_csv('Station_infomation.csv')
#获取所有的列车信息
    def Train_information(self):
        self.train_data = []
        for train in tqdm(self.train_num):
            try:
                url = 'https://qq.ip138.com/train/' + train + '.htm'
                response = requests.get(url,headers = headers)
                response.encoding = 'utf-8'
                train_info_1 = re.findall(r'<span>(.*?)</span>',response.text)
                train_info_2 = re.findall(r'<a href="/train/.*?.htm" target="_blank">(.*?)</a>',response.text)
                
                train_num,category,departure_time,arrival_time,elapsed_time = train_info_1[9],train_info_1[7],train_info_1[12],train_info_1[15],train_info_1[17]
                data = {'train_num':train_num,
                        'category':category,
                        'departure_time':departure_time,
                        'arrival_time':arrival_time,
                        'elapsed_time':elapsed_time,
                        'stations_alone_way':train_info_2[2:]
                        }
                print(data)
                self.train_data.append(data)
            except:
                print('获取失败')
                pass
        train_infor = pd.DataFrame(self.train_data)
        train_infor.to_csv('train_infor.csv')


if __name__== "__main__" :
        t = Train()

        t.Province_url()

        t.Station_name()
        
        t.Station_information()

        t.Train_information()

