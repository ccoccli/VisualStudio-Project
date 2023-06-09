#include "PublicFunctions.h"

bool writeUserDataJsonFile(int usrId, QString usrName, QString usrPwd, QString usrPhone, QString usrMail, QString usrAddr)
{
  qWriteJsonObj.insert("id", QJsonValue(usrId));
  qWriteJsonObj.insert("name", QJsonValue(usrName));
  qWriteJsonObj.insert("pwd", QJsonValue(usrPwd));
  qWriteJsonObj.insert("phone", QJsonValue(usrPhone));
  qWriteJsonObj.insert("mail", QJsonValue(usrMail));
  qWriteJsonObj.insert("addr", QJsonValue(usrAddr));

  array.append(QJsonValue(qWriteJsonObj));

  mainObj.insert("User_" + QString::number(usrId), QJsonValue(array));

  QJsonDocument doc(mainObj);

  QByteArray data = doc.toJson();

  QFile file("./data/userInfo/usrInfo_" + QString::number(usrId) + ".json");

  bool ok = file.open(QIODevice::WriteOnly);
  if (ok)
  {
    file.write(data);
    
    file.close();

    return true;
  }
  else
  {
    qDebug()<<"write error!";
    return false;
  }
}

usrInfo readUserDataJsonFile(int usrId)
{
  usrInfo tempData;

  QFile file("./data/jsonUsrInfo/usrInfo_" + QString::number(usrId) + ".json");

  file.open(QIODevice::ReadOnly);

  QByteArray data = file.readAll();

  file.close();

  QJsonParseError parseError;
  QJsonDocument doc = QJsonDocument::fromJson(data, &parseError);


  QJsonObject obj = doc.object();

  if (obj.contains("User_" + QString::number(usrId)))
  {
    QJsonValue arrayTemp = obj.value("User_" + QString::number(usrId));

    QJsonArray array = arrayTemp.toArray();

    QJsonValue sub = array.at(0);

    QJsonObject subObj = sub.toObject();

    QJsonValue idTemp = subObj.value("id");
    QJsonValue nameTemp = subObj.value("name");
    QJsonValue pwdTemp = subObj.value("pwd");
    QJsonValue phoneTemp = subObj.value("phone");
    QJsonValue mailTemp = subObj.value("mail");
    QJsonValue addrTemp = subObj.value("addr");

    tempData.usrId = idTemp.toInt();
    tempData.usrName = nameTemp.toString();
    tempData.usrPwd = pwdTemp.toString();
    tempData.usrPhone = phoneTemp.toString();
    tempData.usrMail = mailTemp.toString();
    tempData.usrAddr = addrTemp.toString();
  }
  else
  {
    qDebug() << "read error!";
    return tempData;
  }

  return tempData;
}

bool writeXmlFile(int usrId, QString usrName, QString usrPwd, QString usrPhone, QString usrMail, QString usrAddr)
{
  TiXmlDocument* writeDoc = new TiXmlDocument; //xml文档指针

  //文档格式声明
  TiXmlDeclaration* decl = new TiXmlDeclaration("1.0", "UTF-8", "yes");

  //写入文档
  writeDoc->LinkEndChild(decl); 


  TiXmlElement* RootElement = new TiXmlElement("userInfo");//根元素

  writeDoc->LinkEndChild(RootElement);


  TiXmlElement* usrElement = new TiXmlElement(usrName.toStdString().c_str());

  usrElement->SetAttribute("id", usrId);

  RootElement->LinkEndChild(usrElement);//父节点写入文档

  //id
  TiXmlElement* idElement = new TiXmlElement("id");
  usrElement->LinkEndChild(idElement);

  TiXmlText* idContent = new TiXmlText(std::to_string(usrId).c_str());
  idElement->LinkEndChild(idContent);

  //name
  TiXmlElement* nameElement = new TiXmlElement("name");
  usrElement->LinkEndChild(nameElement);

  TiXmlText* nameContent = new TiXmlText(usrName.toStdString().c_str());
  nameElement->LinkEndChild(nameContent);

  //pwd
  TiXmlElement* pwdElement = new TiXmlElement("pwd");
  usrElement->LinkEndChild(pwdElement);

  TiXmlText* pwdContent = new TiXmlText(usrPwd.toStdString().c_str());
  pwdElement->LinkEndChild(pwdContent);

  //phone
  TiXmlElement* phoneElement = new TiXmlElement("phone");
  usrElement->LinkEndChild(phoneElement);

  TiXmlText* phoneContent = new TiXmlText(usrPhone.toStdString().c_str());
  phoneElement->LinkEndChild(phoneContent);

  //mail
  TiXmlElement* mailElement = new TiXmlElement("mail");
  usrElement->LinkEndChild(mailElement);

  TiXmlText* mailContent = new TiXmlText(usrMail.toStdString().c_str());
  mailElement->LinkEndChild(mailContent);

  //addr
  TiXmlElement* addrElement = new TiXmlElement("addr");
  usrElement->LinkEndChild(addrElement);

  TiXmlText* addrContent = new TiXmlText(usrAddr.toStdString().c_str());
  addrElement->LinkEndChild(addrContent);

  writeDoc->SaveFile("./data/xmlUsrInfo/usrInfo.xml");
  delete writeDoc;

  return true;
}

usrInfo readXmlFile()
{
  usrInfo tempData;

  TiXmlDocument mydoc("./data/xmlUsrInfo/usrInfo.xml");//xml文档对象

  bool loadOk = mydoc.LoadFile();//加载文档
  if (!loadOk)
  {
    qDebug() << "could not load the test file.Error:" << mydoc.ErrorDesc();
    exit(1);
  }

  TiXmlElement* RootElement = mydoc.RootElement();

  TiXmlElement* pEle = RootElement;

  TiXmlElement* StuElement = pEle->FirstChildElement();

  TiXmlElement* sonElement = StuElement->FirstChildElement();

  tempData.usrId = atoi(sonElement->FirstChild()->Value());

  sonElement = sonElement->NextSiblingElement();
  tempData.usrName = QString(sonElement->FirstChild()->Value());

  sonElement = sonElement->NextSiblingElement();
  tempData.usrPwd = QString(sonElement->FirstChild()->Value());

  sonElement = sonElement->NextSiblingElement();
  tempData.usrPhone = QString(sonElement->FirstChild()->Value());

  sonElement = sonElement->NextSiblingElement();
  tempData.usrMail = QString(sonElement->FirstChild()->Value());

  sonElement = sonElement->NextSiblingElement();
  tempData.usrAddr = QString(sonElement->FirstChild()->Value());

  return tempData;
}

MYSQL* connMySQLDataBase(std::string connIPAddr, std::string usrName, std::string usrPwd, int port, std::string dbName)
{
  MYSQL* mysql = new MYSQL();

  mysql_init(mysql);

  if (!(mysql_real_connect(mysql, connIPAddr.c_str(), usrName.c_str(), usrPwd.c_str(), dbName.c_str(), port, NULL, 0)))
    return mysql;
  else
    return mysql;
}

usrInfo selectFromDB(MYSQL* mysql, int usrId)
{
  usrInfo temp;

  std::string strtemp = "\"";

  std::string strSQL = "select user_name,user_pwd from base_info where user_id =" + strtemp + std::to_string(usrId) + strtemp + ";";

  if (!mysql_real_query(mysql, strSQL.c_str(), (unsigned int)strlen(strSQL.c_str())))
  {
    MYSQL_ROW row;
    MYSQL_RES* result = mysql_store_result(mysql);

    while (row = mysql_fetch_row(result))
    {
      temp.usrName = row[0];
      temp.usrPwd = row[1];
    }

    mysql_close(mysql);

    return temp;
  }
  else
  {
    qDebug() << "select error " << mysql_errno(mysql) << mysql_error(mysql);

    mysql_close(mysql);

    return temp;
  }
}

bool insertData(MYSQL* mysql, int usrId, QString usrName, QString usrPwd, QString usrPhone, QString usrMail, QString usrAddr)
{
  std::string temp = "\"";
  std::string query = "insert into base_info (user_name,user_id,user_sex,user_phone,user_mail,user_pwd,user_home_addr,user_birthday) values (" + temp + usrName.toStdString() + temp + "," + temp + std::to_string(usrId) + temp + "," + temp + "NULL" + temp  + "," + temp + usrPhone.toStdString() + temp + ", " + temp + usrMail.toStdString() + temp + ", " + temp + usrPwd.toStdString() + temp + "," + temp + usrAddr.toStdString() + temp + "," + temp + "NULL" + temp + ")";
  
  if (!mysql_real_query(mysql, query.c_str(), (unsigned int)strlen(query.c_str())))
  {
    qDebug() << "Inserted rows" << (unsigned long)mysql_affected_rows(mysql);

    mysql_close(mysql);

    return true;
  }
  else 
  {
    qDebug() << "Insert error " << mysql_errno(mysql) << mysql_error(mysql);

    mysql_close(mysql);

    return false;
  }
}

bool changeData(MYSQL* mysql, int usrId, QString usrName, QString usrPwd, QString usrPhone, QString usrMail, QString usrAddr)
{
  std::string temp = "\"";
  QString query = QString("update base_info set user_name='%1', user_phone='%2', user_mail='%3',user_pwd='%4',user_home_addr='%5' where user_id='%6';").arg(usrName).arg(usrPhone).arg(usrMail).arg(usrMail).arg(usrAddr).arg(usrId);

  if (!mysql_real_query(mysql, query.toStdString().c_str(), (unsigned int)strlen(query.toStdString().c_str())))
  {
    qDebug() << "update success" << (unsigned long)mysql_affected_rows(mysql);

    mysql_close(mysql);

    return true;
  }
  else
  {
    qDebug() << "update error " << mysql_errno(mysql) << mysql_error(mysql);

    mysql_close(mysql);

    return false;
  }
}

couponInfo getCoupon(MYSQL* mysql, QString code)
{
  couponInfo temp;
  QString query = QString("select No,code,price,isUse from info where code='%1';").arg(code);

  if (!mysql_real_query(mysql, query.toStdString().c_str(), (unsigned int)strlen(query.toStdString().c_str())))
  {
    MYSQL_ROW row;
    MYSQL_RES* result = mysql_store_result(mysql);

    while (row = mysql_fetch_row(result))
    {
      temp.couponId = atoi(row[0]);
      temp.couponCode = row[1];
      temp.couponPirce = std::stold(row[2]);
      temp.isUsing = row[3];
    }

    mysql_close(mysql);

    return temp;
  }
  else
  {
    qDebug() << "select error " << mysql_errno(mysql) << mysql_error(mysql);

    mysql_close(mysql);

    return temp;
  }
}

bool changeCouponData(MYSQL* mysql, QString isUsing, QString usrId, QString code)
{
  QString query = QString("update info set isUse='%1',for_usrID='%2' where code='%3';").arg(isUsing).arg(usrId).arg(code);

  if (!mysql_real_query(mysql, query.toStdString().c_str(), (unsigned int)strlen(query.toStdString().c_str())))
  {
    qDebug() << "update success" << (unsigned long)mysql_affected_rows(mysql);

    mysql_close(mysql);

    return true;
  }
  else
  {
    qDebug() << "update error " << mysql_errno(mysql) << mysql_error(mysql);

    mysql_close(mysql);

    return false;
  }
}

bool insertStarsData(MYSQL* mysql, QString usrId, int score, int No)
{
  QString query = QString("insert into stars (No,for_usrID,score) values ('%1', '%2', '%3');").arg(No).arg(usrId).arg(score);

  if (!mysql_real_query(mysql, query.toStdString().c_str(), (unsigned int)strlen(query.toStdString().c_str())))
  {
    qDebug() << "Inserted rows" << (unsigned long)mysql_affected_rows(mysql);

    mysql_close(mysql);

    return true;
  }
  else
  {
    qDebug() << "Insert error " << mysql_errno(mysql) << mysql_error(mysql);

    mysql_close(mysql);

    return false;
  }
}
