#include "SysMenu_GameSettingScene.h"

USING_NS_CC;

Scene* SysMenuGameSettingScene::createScene()
{
  return SysMenuGameSettingScene::create();;
}

bool SysMenuGameSettingScene::init()
{
  if (!Scene::init())
  {
    return false;
  }
  /* get windows size **/
  winSize = Director::getInstance()->getWinSize();

  /* create backround sprite **/
  auto bg = Sprite::create(BG);

  bg->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);

  bg->setScale(SCALING);

  this->addChild(bg, 0, 1);

  /* create go back to system menu button**/
  auto label = Label::createWithSystemFont(RETURNMENU, "Arial", 20);
  label->setColor(Color3B(31, 45, 150));

  auto backButton = MenuItemLabel::create(label, CC_CALLBACK_1(SysMenuGameSettingScene::onCallBackButton, this));

  auto menu = Menu::create(backButton, NULL);

  menu->setPosition(winSize.width / 2, 60);

  this->addChild(menu);

  /*create menu tittle**/
  auto cacheImage = Director::getInstance()->getTextureCache()->addImage(MENUTITTLE);

  auto tittle = Sprite::createWithTexture(cacheImage, Rect(0, 0, 135, 38));

  tittle->setPosition(Vec2(winSize.width / 2, winSize.height / 2 + 200));

  this->addChild(tittle);

  /*create sound control button**/
  auto title1 = MenuItemFont::create("Sound");
  title1->setFontName("Arial");
  title1->setFontSize(25);
  title1->setEnabled(false);
  title1->setColor(Color3B(31, 45, 150));
  title1->setPosition(Vec2(winSize.width / 2 - 100, winSize.height / 2 + 50));

  this->addChild(title1, 1);

  auto item1 = MenuItemToggle::createWithCallback(CC_CALLBACK_1(SysMenuGameSettingScene::onSoundControl, this),\
    MenuItemFont::create("On"), MenuItemFont::create("Off"), NULL);

  item1->setPosition(Vec2(winSize.width / 2 - 100, winSize.height / 2));
  this->addChild(item1, 1);

  /*create mode control button**/
  auto title2 = MenuItemFont::create("Mode");
  title2->setFontName("Arial");
  title2->setFontSize(25);
  title2->setEnabled(false);
  title2->setColor(Color3B(31, 45, 150));
  title2->setPosition(Vec2(winSize.width / 2 + 100, winSize.height / 2 + 50));

  this->addChild(title2, 1);

  auto item2 = MenuItemToggle::createWithCallback(CC_CALLBACK_1(SysMenuGameSettingScene::onModeControl, this), \
    MenuItemFont::create("Easy"), MenuItemFont::create("Normal"), MenuItemFont::create("Hard"), NULL);

  item2->setPosition(Vec2(winSize.width / 2 + 100, winSize.height / 2));
  this->addChild(item2, 1);

  return true;
}

void SysMenuGameSettingScene::onCallBackButton(Ref* pSender)
{
  auto sysMenuScene = SysMenuScene::create();

  Director::getInstance()->replaceScene(TransitionFade::create(1.2, sysMenuScene));
}

void SysMenuGameSettingScene::onSoundControl(Ref* pSender)
{
  /*啥都没有*/
}

void SysMenuGameSettingScene::onModeControl(Ref* pSender)
{
  /*啥都没有*/
}
