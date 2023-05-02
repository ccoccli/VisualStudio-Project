#include "SysMenu_NewGameScene.h"

USING_NS_CC;

Scene* SysMenuNewGameScene::createScene()
{
  return SysMenuNewGameScene::create();;
}

bool SysMenuNewGameScene::init()
{
  if (!Scene::init())
  {
    return false;
  }

  /* create backround sprite **/
  auto bg = Sprite::create(BG);

  bg->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);

  bg->setScale(SCALING);

  this->addChild(bg, 0, 1);

  return true;
}

void SysMenuNewGameScene::onCallBackButton(Ref* pSender)
{
}
