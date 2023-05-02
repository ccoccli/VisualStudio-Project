#pragma once
/****************************************************************************

 this is system menu scene init, it will be callled at GuideScene.cpp

 ****************************************************************************/

#ifndef _GAME_MENU_SCENE_H_
#define _GAME_MENU_SCENE_H_

#include "cocos2d.h"
#include "audio/include/AudioEngine.h"

class GameMenuScene : public cocos2d::Scene
{
public:
  static cocos2d::Scene* createScene();

  virtual bool init();

  CREATE_FUNC(GameMenuScene);
};

#endif /*_GAME_MENU_SCENE_H_*/