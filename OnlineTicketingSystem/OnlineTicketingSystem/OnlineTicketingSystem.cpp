#include "OnlineTicketingSystem.h"

OnlineTicketingSystem::OnlineTicketingSystem(QWidget* parent) : QMainWindow(parent)
{
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
}

OnlineTicketingSystem::~OnlineTicketingSystem()
{

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
  /*sign in ui*/
  ui.signin->setPixmap(QPixmap(":/OnlineTicketingSystem/res/tittle_signin.png").scaled(ui.signin->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
  ui.pushButton_14->setIcon(QIcon(":/OnlineTicketingSystem/res/btn_ok.png"));
  ui.pushButton_14->setIconSize(ui.pushButton_13->size());
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
}

void OnlineTicketingSystem::on_pushButton_clicked()
{
  hideUi();

  writeUserDataJsonFile(1, "1", "1", "1", "1", "1");
}

void OnlineTicketingSystem::on_pushButton_2_clicked()
{
  hideUi();
}

void OnlineTicketingSystem::on_pushButton_3_clicked()
{
  hideUi();
}

void OnlineTicketingSystem::on_pushButton_4_clicked()
{
  hideUi();
}

void OnlineTicketingSystem::on_pushButton_5_clicked()
{
  hideUi();
}

void OnlineTicketingSystem::on_pushButton_6_clicked()
{
  hideUi();
}

void OnlineTicketingSystem::on_pushButton_7_clicked()
{
  hideUi();
}

void OnlineTicketingSystem::on_pushButton_8_clicked()
{
  hideUi();
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
}

void OnlineTicketingSystem::on_pushButton_11_clicked()
{
  hideUi();
}
/*reback btn*/
void OnlineTicketingSystem::on_pushButton_12_clicked()
{
  showUi();
}
/*sign up interface ok btn*/
void OnlineTicketingSystem::on_pushButton_13_clicked()
{
  /*create rand user id*/
  srand((unsigned)time(NULL));

  if (ui.namelineEdit->text() != "")
  {
    if (ui.pwdlineEdit->text() != "")
    {
      if (ui.phonelineEdit->text() != "")
      {
        if (ui.maillineEdit->text() != "")
        {
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
                  /*json文件保存数据被舍弃，采用xml保存*/
                  //bool isWrite = writeUserDataJsonFile(0 + rand() % 99999999, ui.namelineEdit->text(), ui.pwdlineEdit->text(), ui.phonelineEdit->text(), ui.maillineEdit->text(), ui.addrlineEdit->text());
                  bool isWrite_2 = writeXmlFile(0 + rand() % 99999999, ui.namelineEdit->text(), ui.pwdlineEdit->text(), ui.phonelineEdit->text(), ui.maillineEdit->text(), ui.addrlineEdit->text());
                  
                  if (isWrite_2)
                  {
                    QMessageBox::information(this, "Sign up success", "Sign up success");

                    /*test read xml*/
                    usrInfo  tmp = readXmlFile();
                    qDebug() << tmp.usrId << " " << tmp.usrName << " " << tmp.usrPwd << " " << tmp.usrPhone << " " << tmp.usrMail << " " << tmp.usrAddr;
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