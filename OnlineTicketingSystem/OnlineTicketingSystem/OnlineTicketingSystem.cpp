#include "OnlineTicketingSystem.h"

OnlineTicketingSystem::OnlineTicketingSystem(QWidget* parent) : QMainWindow(parent)
{
  isLogin = false;
  usrId = 0;

  ui.setupUi(this);

  interfaceInit();

  ui.pushButton_12->hide();

  /*sign up ui*/
  ui.signup->hide();
  ui.username->hide();
  ui.pwd->hide();
  ui.phone->hide();
  ui.mail->hide();
  ui.addr->hide();
  ui.namelineEdit->hide();
  ui.pwdlineEdit->hide();
  ui.phonelineEdit->hide();
  ui.maillineEdit->hide();
  ui.addrlineEdit->hide();
  ui.pushButton_13->hide();

  /*signin ui*/
  ui.signin->hide();
  ui.pushButton_14->hide();
  ui.usrIdlineEdit->hide();
  ui.usrId->hide();

  ui.info1->hide();
  ui.info2->hide();
  ui.info3->hide();
  ui.info4->hide();
  ui.info5->hide();
  ui.info6->hide();
  ui.info7->hide();
  ui.info8->hide();
  ui.info9->hide();
  ui.info10->hide();
  ui.info11->hide();

  /*modify info*/
  ui.modifyInfo->hide();
  ui.pushButton_15->hide();

  ui.stars->hide();
  ui.coupon->hide();
  ui.setting->hide();
  ui.tools->hide();
  ui.route->hide();
  ui.funds->hide();
  ui.pb->hide();
}

OnlineTicketingSystem::~OnlineTicketingSystem()
{

}

void OnlineTicketingSystem::paintEvent(QPaintEvent* event)
{
  if (isLogin)
  {
    QString tittle = QString("Tule welcome : username->" + userData.usrName + " userID->" + usrId);
    this->setWindowTitle(tittle);
  }
}
void OnlineTicketingSystem::interfaceInit()
{
  /*menu tittle*/
  ui.label->setPixmap(QPixmap(":/OnlineTicketingSystem/res/icon.png").scaled(ui.label->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

  ui.label_2->setPixmap(QPixmap(":/OnlineTicketingSystem/res/tittle.png").scaled(ui.label_2->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
  ui.label_3->setPixmap(QPixmap(":/OnlineTicketingSystem/res/tittle_setting.png").scaled(ui.label_3->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
  ui.label_4->setPixmap(QPixmap(":/OnlineTicketingSystem/res/tittle_coupon.png").scaled(ui.label_4->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
  ui.label_5->setPixmap(QPixmap(":/OnlineTicketingSystem/res/tittle_stars.png").scaled(ui.label_5->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
  ui.label_6->setPixmap(QPixmap(":/OnlineTicketingSystem/res/tittle_tools.png").scaled(ui.label_6->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
  ui.label_7->setPixmap(QPixmap(":/OnlineTicketingSystem/res/tittle_Piggybank.png").scaled(ui.label_7->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
  ui.label_8->setPixmap(QPixmap(":/OnlineTicketingSystem/res/title_funds.png").scaled(ui.label_8->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
  ui.label_9->setPixmap(QPixmap(":/OnlineTicketingSystem/res/tittle_route.png").scaled(ui.label_9->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
  ui.label_10->setPixmap(QPixmap(":/OnlineTicketingSystem/res/tittle_tips.png").scaled(ui.label_10->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
  
  /*sign up ui*/
  ui.signup->setPixmap(QPixmap(":/OnlineTicketingSystem/res/SignUp_tittle.png").scaled(ui.signup->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
  ui.username->setPixmap(QPixmap(":/OnlineTicketingSystem/res/tittle_username.png").scaled(ui.username->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
  ui.pwd->setPixmap(QPixmap(":/OnlineTicketingSystem/res/tittle_pwd.png").scaled(ui.pwd->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
  ui.phone->setPixmap(QPixmap(":/OnlineTicketingSystem/res/tittle_phone.png").scaled(ui.phone->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
  ui.mail->setPixmap(QPixmap(":/OnlineTicketingSystem/res/tittle_mail.png").scaled(ui.mail->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
  ui.addr->setPixmap(QPixmap(":/OnlineTicketingSystem/res/tittle_addr.png").scaled(ui.addr->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
  ui.pushButton_13->setIcon(QIcon(":/OnlineTicketingSystem/res/btn_ok.png"));
  ui.pushButton_13->setIconSize(ui.pushButton_13->size());
  ui.usrId->setPixmap(QPixmap(":/OnlineTicketingSystem/res/usrId.png").scaled(ui.usrId->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
  /*sign in ui*/
  ui.signin->setPixmap(QPixmap(":/OnlineTicketingSystem/res/tittle_signin.png").scaled(ui.signin->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
  ui.pushButton_14->setIcon(QIcon(":/OnlineTicketingSystem/res/btn_ok.png"));
  ui.pushButton_14->setIconSize(ui.pushButton_14->size());

  /*modify info*/
  ui.modifyInfo->setPixmap(QPixmap(":/OnlineTicketingSystem/res/modifyInfo.png").scaled(ui.modifyInfo->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
  ui.pushButton_15->setIcon(QIcon(":/OnlineTicketingSystem/res/btn_ok.png"));
  ui.pushButton_15->setIconSize(ui.pushButton_15->size());

  /*stars*/
  ui.stars->setPixmap(QPixmap(":/OnlineTicketingSystem/res/tittle_stars.png").scaled(ui.stars->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

  /*coupon*/
  ui.coupon->setPixmap(QPixmap(":/OnlineTicketingSystem/res/tittle_coupon.png").scaled(ui.coupon->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

  /*setting*/
  ui.setting->setPixmap(QPixmap(":/OnlineTicketingSystem/res/tittle_setting.png").scaled(ui.setting->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

  /*tools*/
  ui.tools->setPixmap(QPixmap(":/OnlineTicketingSystem/res/tittle_tools.png").scaled(ui.tools->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
  /*route*/
  ui.route->setPixmap(QPixmap(":/OnlineTicketingSystem/res/tittle_route.png").scaled(ui.route->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
  /*funds*/
  ui.funds->setPixmap(QPixmap(":/OnlineTicketingSystem/res/title_funds.png").scaled(ui.funds->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
  /*Piggybank*/
  ui.pb->setPixmap(QPixmap(":/OnlineTicketingSystem/res/tittle_Piggybank.png").scaled(ui.pb->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
  /*set windows icon*/
  this->setWindowIcon(QIcon(":/OnlineTicketingSystem/res/icon.png"));
  /*menu icon*/
  ui.pushButton->setIcon(QIcon(":/OnlineTicketingSystem/res/Operation tips.png"));
  ui.pushButton->setIconSize(ui.pushButton->size());
  ui.pushButton_2->setIcon(QIcon(":/OnlineTicketingSystem/res/coupon.png"));
  ui.pushButton_2->setIconSize(ui.pushButton_2->size());
  ui.pushButton_3->setIcon(QIcon(":/OnlineTicketingSystem/res/setting.png"));
  ui.pushButton_3->setIconSize(ui.pushButton_3->size());
  ui.pushButton_4->setIcon(QIcon(":/OnlineTicketingSystem/res/evaluate.png"));
  ui.pushButton_4->setIconSize(ui.pushButton_4->size());
  ui.pushButton_5->setIcon(QIcon(":/OnlineTicketingSystem/res/tools.png"));
  ui.pushButton_5->setIconSize(ui.pushButton_5->size());
  ui.pushButton_6->setIcon(QIcon(":/OnlineTicketingSystem/res/Piggy bank.png"));
  ui.pushButton_6->setIconSize(ui.pushButton_6->size());
  ui.pushButton_7->setIcon(QIcon(":/OnlineTicketingSystem/res/Price calculation.png"));
  ui.pushButton_7->setIconSize(ui.pushButton_7->size());
  ui.pushButton_8->setIcon(QIcon(":/OnlineTicketingSystem/res/schedule.png"));
  ui.pushButton_8->setIconSize(ui.pushButton_8->size());

  ui.pushButton_9->setIcon(QIcon(":/OnlineTicketingSystem/res/login.png"));
  ui.pushButton_9->setIconSize(ui.pushButton_9->size());
  ui.pushButton_10->setIcon(QIcon(":/OnlineTicketingSystem/res/user.png"));
  ui.pushButton_10->setIconSize(ui.pushButton_10->size());
  ui.pushButton_11->setIcon(QIcon(":/OnlineTicketingSystem/res/location.png"));
  ui.pushButton_11->setIconSize(ui.pushButton_11->size());

  ui.pushButton_12->setIcon(QIcon(":/OnlineTicketingSystem/res/caret-left.png"));
  ui.pushButton_12->setIconSize(ui.pushButton_12->size());
}

void OnlineTicketingSystem::hideUi()
{
  ui.label->hide();
  ui.label_2->hide();
  ui.label_3->hide();
  ui.label_4->hide();
  ui.label_5->hide();
  ui.label_6->hide();
  ui.label_7->hide();
  ui.label_8->hide();
  ui.label_9->hide();
  ui.label_10->hide();

  ui.pushButton->hide();
  ui.pushButton_2->hide();
  ui.pushButton_3->hide();
  ui.pushButton_4->hide();
  ui.pushButton_5->hide();
  ui.pushButton_6->hide();
  ui.pushButton_7->hide();
  ui.pushButton_8->hide();
  ui.pushButton_9->hide();
  ui.pushButton_10->hide();
  ui.pushButton_11->hide();

  ui.pushButton_12->show();
}

void OnlineTicketingSystem::showUi()
{
  ui.label->show();
  ui.label_2->show();
  ui.label_3->show();
  ui.label_4->show();
  ui.label_5->show();
  ui.label_6->show();
  ui.label_7->show();
  ui.label_8->show();
  ui.label_9->show();
  ui.label_10->show();

  ui.pushButton->show();
  ui.pushButton_2->show();
  ui.pushButton_3->show();
  ui.pushButton_4->show();
  ui.pushButton_5->show();
  ui.pushButton_6->show();
  ui.pushButton_7->show();
  ui.pushButton_8->show();
  ui.pushButton_9->show();
  ui.pushButton_10->show();
  ui.pushButton_11->show();

  ui.pushButton_12->hide();
  
  /*sign up ui*/
  ui.signup->hide();
  ui.username->hide();
  ui.pwd->hide();
  ui.phone->hide();
  ui.mail->hide();
  ui.addr->hide();
  ui.namelineEdit->hide();
  ui.pwdlineEdit->hide();
  ui.phonelineEdit->hide();
  ui.maillineEdit->hide();
  ui.addrlineEdit->hide();
  ui.pushButton_13->hide();

  /*If you return to the main menu, clear everything*/
  ui.namelineEdit->clear();
  ui.pwdlineEdit->clear();
  ui.phonelineEdit->clear();
  ui.maillineEdit->clear();
  ui.addrlineEdit->clear();

  /*signin ui*/
  ui.signin->hide();
  ui.pushButton_14->hide();
  ui.usrIdlineEdit->hide();
  ui.usrId->hide();

  ui.usrIdlineEdit->clear();

  ui.modifyInfo->hide();

  ui.pushButton_15->hide();
}

void OnlineTicketingSystem::on_pushButton_clicked()
{
  ui.label->hide();
  ui.label_2->hide();
  ui.label_3->hide();
  ui.label_4->hide();
  ui.label_5->hide();
  ui.label_6->hide();
  ui.label_7->hide();
  ui.label_8->hide();
  ui.label_9->hide();
  ui.label_10->hide();

  ui.pushButton_12->show();

  ui.pushButton->setGeometry(150, 10, 100, 100);
  ui.pushButton_2->setGeometry(150, 135, 100, 100);
  ui.pushButton_3->setGeometry(150, 260, 100, 100);
  ui.pushButton_4->setGeometry(150, 385, 100, 100);
  ui.pushButton_5->setGeometry(150, 510, 100, 100);
  ui.pushButton_6->setGeometry(150, 635, 100, 100);

  ui.pushButton_7->setGeometry(750, 10, 100, 100);
  ui.pushButton_8->setGeometry(750, 135, 100, 100);
  ui.pushButton_9->setGeometry(750, 260, 100, 100);
  ui.pushButton_10->setGeometry(750, 385, 100, 100);
  ui.pushButton_11->setGeometry(750, 510, 100, 100);

  ui.pushButton->setEnabled(false);
  ui.pushButton_2->setEnabled(false);
  ui.pushButton_3->setEnabled(false);
  ui.pushButton_4->setEnabled(false);
  ui.pushButton_5->setEnabled(false);
  ui.pushButton_6->setEnabled(false);
  ui.pushButton_7->setEnabled(false);
  ui.pushButton_8->setEnabled(false);
  ui.pushButton_9->setEnabled(false);
  ui.pushButton_10->setEnabled(false);
  ui.pushButton_11->setEnabled(false);

  ui.info1->show();
  ui.info2->show();
  ui.info3->show();
  ui.info4->show();
  ui.info5->show();
  ui.info6->show();
  ui.info7->show();
  ui.info8->show();
  ui.info9->show();
  ui.info10->show();
  ui.info11->show();
}

void OnlineTicketingSystem::on_pushButton_2_clicked()
{
  hideUi();

  ui.coupon->show();
}

void OnlineTicketingSystem::on_pushButton_3_clicked()
{
  hideUi();

  ui.setting->show();
}

void OnlineTicketingSystem::on_pushButton_4_clicked()
{
  hideUi();

  ui.stars->show();
}

void OnlineTicketingSystem::on_pushButton_5_clicked()
{
  hideUi();

  ui.tools->show();
}

void OnlineTicketingSystem::on_pushButton_6_clicked()
{
  hideUi();

  ui.pb->show();
}

void OnlineTicketingSystem::on_pushButton_7_clicked()
{
  hideUi();

  ui.funds->show();

}

void OnlineTicketingSystem::on_pushButton_8_clicked()
{
  hideUi();

  ui.route->show();
}

/*main menu sign up btn*/
void OnlineTicketingSystem::on_pushButton_9_clicked()
{
  hideUi();

  ui.signup->show();
  ui.username->show();
  ui.pwd->show();
  ui.phone->show();
  ui.mail->show();
  ui.addr->show();
  ui.namelineEdit->show();
  ui.pwdlineEdit->show();
  ui.phonelineEdit->show();
  ui.maillineEdit->show();
  ui.addrlineEdit->show();
  ui.pushButton_13->show();
}

void OnlineTicketingSystem::on_pushButton_10_clicked()
{
  hideUi();

  ui.signin->show();
  ui.username->show();
  ui.pwd->show();
  ui.namelineEdit->show();
  ui.pwdlineEdit->show();
  ui.pushButton_14->show();
  ui.usrIdlineEdit->show();
  ui.usrId->show();
}

void OnlineTicketingSystem::on_pushButton_11_clicked()
{
  if (isLogin)
  {
    hideUi();

    ui.username->show();
    ui.pwd->show();
    ui.phone->show();
    ui.mail->show();
    ui.addr->show();
    ui.namelineEdit->show();
    ui.pwdlineEdit->show();
    ui.phonelineEdit->show();
    ui.maillineEdit->show();
    ui.addrlineEdit->show();

    ui.modifyInfo->show();

    ui.pushButton_15->show();
  }
  else
  {
    QMessageBox::information(this, "erorr", "Please log in to your account before modifying your information");
  }
}
/*reback btn*/
void OnlineTicketingSystem::on_pushButton_12_clicked()
{
  showUi();

  ui.pushButton->setEnabled(true);
  ui.pushButton_2->setEnabled(true);
  ui.pushButton_3->setEnabled(true);
  ui.pushButton_4->setEnabled(true);
  ui.pushButton_5->setEnabled(true);
  ui.pushButton_6->setEnabled(true);
  ui.pushButton_7->setEnabled(true);
  ui.pushButton_8->setEnabled(true);
  ui.pushButton_9->setEnabled(true);
  ui.pushButton_10->setEnabled(true);
  ui.pushButton_11->setEnabled(true);

  ui.pushButton->setGeometry(260, 130, 100, 100);
  ui.pushButton_2->setGeometry(220, 340, 100, 100);
  ui.pushButton_3->setGeometry(340, 570, 100, 100);
  ui.pushButton_4->setGeometry(860, 570, 100, 100);
  ui.pushButton_5->setGeometry(940, 340, 100, 100);
  ui.pushButton_6->setGeometry(920, 140, 100, 100);

  ui.pushButton_7->setGeometry(710, 20, 100, 100);
  ui.pushButton_8->setGeometry(430, 20, 100, 100);
  ui.pushButton_9->setGeometry(90, 210, 100, 100);
  ui.pushButton_10->setGeometry(10, 400, 100, 100);
  ui.pushButton_11->setGeometry(90, 560, 100, 100);

  ui.info1->hide();
  ui.info2->hide();
  ui.info3->hide();
  ui.info4->hide();
  ui.info5->hide();
  ui.info6->hide();
  ui.info7->hide();
  ui.info8->hide();
  ui.info9->hide();
  ui.info10->hide();
  ui.info11->hide();

  ui.modifyInfo->hide();

  if (isLogin)
  {
    ui.pushButton_10->setEnabled(false);
  }

  ui.stars->hide();
  ui.coupon->hide();
  ui.setting->hide();
  ui.tools->hide();
  
  ui.route->hide();
  ui.funds->hide();
  ui.pb->hide();
}
/*sign up interface ok btn*/
void OnlineTicketingSystem::on_pushButton_13_clicked()
{
  /*create rand user id*/
  srand((unsigned)time(NULL));

  /*用户名不能为空*/
  if (ui.namelineEdit->text() != "")
  {
    /*密码不能为空*/
    if (ui.pwdlineEdit->text() != "")
    {
      /*电话不能为空*/
      if (ui.phonelineEdit->text() != "")
      {
        /*邮箱不能为空*/
        if (ui.maillineEdit->text() != "")
        {
          /*地址不能为空*/
          if (ui.addrlineEdit->text() != "")
          {
            //强制密码8-16位且必须为数字、大小写字母或符号中至少2种
            std::regex rPwd("^(?![\\d]+$)(?![a-zA-Z]+$)(?![^\\da-zA-Z]+$).{8,16}$");
            if (std::regex_match(ui.pwdlineEdit->text().toStdString(), rPwd))
            {
              //验证手机号码
              std::regex r("^1(3|5|8|7|9)\\d{9}$");

              if (std::regex_match(ui.phonelineEdit->text().toStdString(), r))
              {
                //验证邮箱
                std::regex rMail("^[a-z0-9A-Z]+[- | a-z0-9A-Z . _]+@([a-z0-9A-Z]+(-[a-z0-9A-Z]+)?\\.)+[a-z]{2,}$");
                if (std::regex_match(ui.maillineEdit->text().toStdString(), rMail))
                {
                  MYSQL* mysql = connMySQLDataBase("114.116.20.45", "root", "Wan23004517.", 3306, "user_info");

                  int usrId = 0 + rand() % 99999999;
                  if (insertData(mysql, usrId, ui.namelineEdit->text(), ui.pwdlineEdit->text(), ui.phonelineEdit->text(), ui.maillineEdit->text(), ui.addrlineEdit->text()))
                  {
                    QString tittleContent = QString("Sign up success, please remember your id is %0").arg(usrId);

                    QMessageBox::information(this, "Sign up success", tittleContent);

                    showUi();
                  }
                  else
                    QMessageBox::information(this, "Sign up fail", "Sign up fail");
                }
                else
                {
                  QMessageBox::information(this, "Sign up fail", "Please enter the correct email format!");
                  ui.maillineEdit->clear();
                }
              }
              else
              {
                QMessageBox::information(this, "Sign up fail", "Please enter the correct phone number format!");
                ui.phonelineEdit->clear();
              }
            }
            else
            {
              QMessageBox::information(this, "Sign up fail", "The password must be 8-16 digits and must contain at least 2 types of numbers, uppercase and lowercase letters, or symbols!");
              ui.pwdlineEdit->clear();
            }
          }
          else
          {
            QMessageBox::information(this, "Sign up fail", "address cannot be empty!");
          }
        }
        else
        {
          QMessageBox::information(this, "Sign up fail", "mail cannot be empty!");
        }
      }
      else
      {
        QMessageBox::information(this, "Sign up fail", "phone cannot be empty!");
      }
    }
    else
    {
      QMessageBox::information(this, "Sign up fail", "password cannot be empty!");
    }
  }
  else
  {
    QMessageBox::information(this, "Sign up fail", "User name cannot be empty!");
  }
}

void OnlineTicketingSystem::on_pushButton_14_clicked()
{
  MYSQL* mysql = connMySQLDataBase("114.116.20.45", "root", "Wan23004517.", 3306, "user_info");

  userData = selectFromDB(mysql, atoi(ui.usrIdlineEdit->text().toStdString().c_str()));

  /*用户名不能为空*/
  if (ui.namelineEdit->text() != "")
  {
    /*密码不能为空*/
    if (ui.pwdlineEdit->text() != "")
    {
      if (ui.usrIdlineEdit->text() != "")
      {
        if (userData.usrName == ui.namelineEdit->text() && userData.usrPwd == ui.pwdlineEdit->text())
        {
          QMessageBox::information(this, "login success", "login success");

          isLogin = true;

          usrId = ui.usrIdlineEdit->text();

          showUi();

          ui.pushButton_10->setEnabled(false);
        }
        else
        {
          QMessageBox::information(this, "login fail", "name or password or id is error, please try again!");

          ui.namelineEdit->clear();
          ui.pwdlineEdit->clear();
          ui.usrIdlineEdit->clear();
        }
      }
      else
      {
        QMessageBox::information(this, "login fail", "usrId cannot be empty!");
      }
    }
    else
    {
      QMessageBox::information(this, "login fail", "password cannot be empty!");
    }
  }
  else
  {
    QMessageBox::information(this, "login fail", "user name cannot be empty!");
  }
}

void OnlineTicketingSystem::on_pushButton_15_clicked()
{
  /*用户名不能为空*/
  if (ui.namelineEdit->text() != "")
  {
    /*密码不能为空*/
    if (ui.pwdlineEdit->text() != "")
    {
      /*电话不能为空*/
      if (ui.phonelineEdit->text() != "")
      {
        /*邮箱不能为空*/
        if (ui.maillineEdit->text() != "")
        {
          /*地址不能为空*/
          if (ui.addrlineEdit->text() != "")
          {
            //强制密码8-16位且必须为数字、大小写字母或符号中至少2种
            std::regex rPwd("^(?![\\d]+$)(?![a-zA-Z]+$)(?![^\\da-zA-Z]+$).{8,16}$");
            if (std::regex_match(ui.pwdlineEdit->text().toStdString(), rPwd))
            {
              //验证手机号码
              std::regex r("^1(3|5|8|7|9)\\d{9}$");

              if (std::regex_match(ui.phonelineEdit->text().toStdString(), r))
              {
                //验证邮箱
                std::regex rMail("^[a-z0-9A-Z]+[- | a-z0-9A-Z . _]+@([a-z0-9A-Z]+(-[a-z0-9A-Z]+)?\\.)+[a-z]{2,}$");
                if (std::regex_match(ui.maillineEdit->text().toStdString(), rMail))
                {
                  MYSQL* mysql = connMySQLDataBase("114.116.20.45", "root", "Wan23004517.", 3306, "user_info");

                  if (changeData(mysql, usrId.toInt(), ui.namelineEdit->text(), ui.pwdlineEdit->text(), ui.phonelineEdit->text(), ui.maillineEdit->text(), ui.addrlineEdit->text()))
                  {
                    QString tittleContent = QString("modify success, please remember your new information!");

                    QMessageBox::information(this, "modify success", tittleContent);

                    showUi();
                  }
                  else
                    QMessageBox::information(this, "modify fail", "modify fail");
                }
                else
                {
                  QMessageBox::information(this, "modify fail", "Please enter the correct email format!");
                  ui.maillineEdit->clear();
                }
              }
              else
              {
                QMessageBox::information(this, "modify fail", "Please enter the correct phone number format!");
                ui.phonelineEdit->clear();
              }
            }
            else
            {
              QMessageBox::information(this, "modify fail", "The password must be 8-16 digits and must contain at least 2 types of numbers, uppercase and lowercase letters, or symbols!");
              ui.pwdlineEdit->clear();
            }
          }
          else
          {
            QMessageBox::information(this, "modify fail", "address cannot be empty!");
          }
        }
        else
        {
          QMessageBox::information(this, "modify fail", "mail cannot be empty!");
        }
      }
      else
      {
        QMessageBox::information(this, "modify fail", "phone cannot be empty!");
      }
    }
    else
    {
      QMessageBox::information(this, "modify fail", "password cannot be empty!");
    }
  }
  else
  {
    QMessageBox::information(this, "modify fail", "User name cannot be empty!");
  }
}