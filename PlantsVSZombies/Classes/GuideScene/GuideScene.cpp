#include "GuideScene.h"

USING_NS_CC;

cocos2d::Scene* GuideScene::createScene()
{
  return GuideScene::create();
}

bool GuideScene::init()
{
  if (!Scene::init())
  {
    return false;
  }
  /* get windows size **/
  winSize = Director::getInstance()->getWinSize();

  /* create background */
  auto bg = Sprite::create(TITLEBG);

  bg->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
  bg->setPosition(Point(0, 0));
  bg->setContentSize(winSize);

  /*add sprite to the scene : sprite, floor height, tag*/
  this->addChild(bg, 0, 0);


  return true;
}

void GuideScene::update(float dt)
{
}
