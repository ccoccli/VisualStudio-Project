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

  return true;
}

void SysMenuGameSettingScene::onCallBackButton(Ref* pSender)
{
  auto sysMenuScene = SysMenuScene::create();

  Director::getInstance()->replaceScene(TransitionFade::create(1.2, sysMenuScene));
}
