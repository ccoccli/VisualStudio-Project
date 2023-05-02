#include "GameMenuScene.h"

cocos2d::Scene* GameMenuScene::createScene()
{
  return GameMenuScene::create();
}

bool GameMenuScene::init()
{
  if (!Scene::init())
  {
    return false;
  }


  return true;
}