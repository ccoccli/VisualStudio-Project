#pragma once
/****************************************************************************

 this is system menu scene init, it will be callled at AppDelegat.cpp

 ****************************************************************************/

#ifndef _GUIDE_SCENE_H_
#define _GUIDE_SCENE_H_

#include "cocos2d.h"

#define TITLEBG       "./images/titlescreen.jpg"
#define LOGO          "./images/Logo.png"
#define PROGRASSDIRT  "./images/LoadBar_dirt.png"
#define PROGRASSGRASS "./images/LoadBar_grass.png"

#define STARTGAME     "Click here to start !"
#define COPYRIGHT     "Power by Cocos2d-x4.0, overwrite by Ccoccli"

#define SYSTEMFONT    "./fonts/Brianne_s_hand.ttf"

class GuideScene : public cocos2d::Scene 
{
public:
  static cocos2d::Scene* createScene();

  virtual bool init();

  virtual void update(float dt);

  void onStartGame(Ref* pSender);
  CREATE_FUNC(GuideScene);
private:
  cocos2d::Size winSize;
};

#endif /* _GUIDE_SCENE_H_ */
