#pragma once

#include <regex>
#include <QMessageBox>
#include <QPaintEvent>
#include <QtWidgets/QMainWindow>
#include "ui_OnlineTicketingSystem.h"
#include "PublicFunctions.h"
#include <QPropertyAnimation>

static usrInfo userData;
static QString usrId;
class OnlineTicketingSystem : public QMainWindow
{
  Q_OBJECT

public:
  OnlineTicketingSystem(QWidget* parent = nullptr);
  ~OnlineTicketingSystem();

  /*
   * \brief main interface init
   * \param null
   * \return null
   */
  void interfaceInit();

  /*
   * \brief hide all main menu ui
   * \param null
   * \return null
   */
  void hideUi();
  /*
   * \brief show all main menu ui
   * \param null
   * \return null
   */
  void showUi();

private:
  Ui::OnlineTicketingSystemClass ui;

  void paintEvent(QPaintEvent* event);

private slots:

  /*
   * \brief tips Functional interface
   * \param null
   * \return null
   */
  void on_pushButton_clicked();
  /*
   * \brief coupon Functional interface
   * \param null
   * \return null
   */
  void on_pushButton_2_clicked();
  /*
   * \brief setting Functional interface
   * \param null
   * \return null
   */
  void on_pushButton_3_clicked();
  /*
   * \brief stars Functional interface
   * \param null
   * \return null
   */
  void on_pushButton_4_clicked();
  /*
   * \brief tools Functional interface
   * \param null
   * \return null
   */
  void on_pushButton_5_clicked();
  /*
  * \brief piggy bank Functional interface
  * \param null
  * \return null
  */
  void on_pushButton_6_clicked();
  /*
   * \brief funds Functional interface
   * \param null
   * \return null
   */
  void on_pushButton_7_clicked();
  /*
   * \brief route Functional interface
   * \param null
   * \return null
   */
  void on_pushButton_8_clicked();
  /*
   * \brief login Functional interface
   * \param null
   * \return null
   */
  void on_pushButton_9_clicked();
  /*
   * \brief sign in Functional interface
   * \param null
   * \return null
   */
  void on_pushButton_10_clicked();
  /*
   * \brief user Functional interface
   * \param null
   * \return null
   */
  void on_pushButton_11_clicked();
  /*
   * \brief back to main menu
   * \param null
   * \return null
   */
  void on_pushButton_12_clicked();
  /*
   * \brief sign up func
   * \param null
   * \return null
   */
  void on_pushButton_13_clicked();
  /*
  * \brief login func
  * \param null
  * \return null
  */
  void on_pushButton_14_clicked();
  /*
* \brief modify information func
* \param null
* \return null
*/
  void on_pushButton_15_clicked();
};