#pragma once
/****************************************************************************

 this is system menu scene init, it will be callled at AppDelegat.cpp

 ****************************************************************************/

#ifndef _GUIDE_SCENE_H_
#define _GUIDE_SCENE_H_

#include "cocos2d.h"

#define TITLEBG "./images/titlescreen.jpg"

class GuideScene : public cocos2d::Scene 
{
public:
  static cocos2d::Scene* createScene();

  virtual bool init();

  virtual void update(float dt);

  CREATE_FUNC(GuideScene);
private:
  cocos2d::Size winSize;
};


#endif /* _GUIDE_SCENE_H_ */
