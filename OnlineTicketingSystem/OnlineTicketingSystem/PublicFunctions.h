#pragma once

#pragma comment(lib,"ws2_32.lib")

#include "tinyxml.h"
#include <mysql.h>
#include <QFile>
#include <QString>
#include <QByteArray>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QGraphicsDropShadowEffect>
/*
 * this file include some public functions and some public global variables
 */

static QJsonObject mainObj = QJsonObject();
static QJsonObject qWriteJsonObj = QJsonObject();
static QJsonArray array;

static bool       isLogin;
typedef struct usrInfo
{
  int     usrId;
  QString usrName; 
  QString usrPwd;
  QString usrPhone;
  QString usrMail;
  QString usrAddr;
};

static MYSQL_RES* m_SelectResult;
/*
 * \brief read json data
 * \param usrId     : id
 * \param usrName   : name
 * \param usrPwd    : pwd
 * \param usrAge    : age
 * \param usrPhone  : phone
 * \param usrMail   : mail
 * \param usrAddr   : addr
 * \return write to json file success or fail
 */
bool writeUserDataJsonFile(int usrId, QString usrName, QString usrPwd, QString usrPhone, QString usrMail, QString usrAddr);
/*
 * \brief read json data
 * \param usrId : id
 * \return usrInfo : userinfo
 */
usrInfo readUserDataJsonFile(int usrId);

/*
 * \brief 创建xml文件
 * \param usrId     : id
 * \param usrName   : name
 * \param usrPwd    : pwd
 * \param usrAge    : age
 * \param usrPhone  : phone
 * \param usrMail   : mail
 * \param usrAddr   : addr
 */
bool writeXmlFile(int usrId, QString usrName, QString usrPwd, QString usrPhone, QString usrMail, QString usrAddr);
/*
 * \brief read xml data
 * \return usrInfo : userinfo
 */
usrInfo readXmlFile();


/*
 * \brief connect mysql databse
 * \param connIPAddr->ip address
 * \param usrName->database name
 * \param usrPwd->database password
 * \param port-> database connect port
 * \param dbName->database name
 * \return connect mysql database success or fail
 */
MYSQL* connMySQLDataBase(std::string connIPAddr, std::string usrName, std::string usrPwd, int port, std::string dbName);

/*
 * \brief select data from database
 * \param usrId     : id
 * \return usrInfo : userinfo
 */
usrInfo selectFromDB(MYSQL* mysql, int usrId);

/*
 * \brief insert user data to database
 * \param usrId     : id
 * \param usrName   : name
 * \param usrPwd    : pwd
 * \param usrAge    : age
 * \param usrPhone  : phone
 * \param usrMail   : mail
 * \param usrAddr   : addr
 * \return usrInfo : userinfo
 */
bool insertData(MYSQL* mysql, int usrId, QString usrName, QString usrPwd, QString usrPhone, QString usrMail, QString usrAddr);