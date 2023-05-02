#include "SysMenu_AboutScene.h"

USING_NS_CC;

Scene* SysMenuAboutScene::createScene()
{
  return SysMenuAboutScene::create();;
}

bool SysMenuAboutScene::init()
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

  auto backButton = MenuItemLabel::create(label, CC_CALLBACK_1(SysMenuAboutScene::onCallBackButton, this));

  auto menu = Menu::create(backButton, NULL);

  menu->setPosition(winSize.width / 2, 60);

  this->addChild(menu);

  /* create label about copyright **/
  auto labelAbout = Label::createWithSystemFont(COPYRIGHT, "Arial", 20);
  labelAbout->setColor(Color3B(31, 45, 150));
  labelAbout->setPosition(Point(winSize.width / 2, winSize.height / 2));

  this->addChild(labelAbout, 1);

  /*create menu tittle**/
  auto cacheImage = Director::getInstance()->getTextureCache()->addImage(MENUTITTLE);

  auto tittle = Sprite::createWithTexture(cacheImage, Rect(0, 40, 120, 38));

  tittle->setPosition(Vec2(winSize.width / 2, winSize.height / 2 + 200));

  this->addChild(tittle);

  return true;
}

void SysMenuAboutScene::onCallBackButton(Ref* pSender)
{
  auto sysMenuScene = SysMenuScene::create();

  Director::getInstance()->replaceScene(TransitionFade::create(1.2, sysMenuScene));
}
