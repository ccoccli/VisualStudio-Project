#pragma once
/****************************************************************************

 this is the son of the system menu that about button, it will be called at 

 SysMenuScene.cpp

 ****************************************************************************/

#ifndef _SYS_MENU_ABOUT_SCENE_H_
#define _SYS_MENU_ABOUT_SCENE_H_

#include "cocos2d.h"
#include "SysMenuScene.h"

class SysMenuAboutScene : public cocos2d::Scene
{
public:
  static cocos2d::Scene* createScene();

  virtual bool init();

  void onCallBackButton(Ref* pSender);

  CREATE_FUNC(SysMenuAboutScene);
private:
  cocos2d::Size winSize;
};
#endif // _SYS_MENU_ABOUT_SCENE_H_