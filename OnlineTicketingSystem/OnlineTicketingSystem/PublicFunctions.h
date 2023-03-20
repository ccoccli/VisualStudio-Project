#pragma once
#pragma comment(lib,"ws2_32.lib")
#include "tinyxml.h"

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

typedef struct usrInfo
{
  int     usrId;
  QString usrName; 
  QString usrPwd;
  QString usrPhone;
  QString usrMail;
  QString usrAddr;
};
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