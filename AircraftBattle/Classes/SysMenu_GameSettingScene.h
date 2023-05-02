#pragma once
/****************************************************************************

 this is the son of the system menu that game setting button, it will be 
 
 called at SysMenuScene.cpp

 ****************************************************************************/

#ifndef _SYS_MENU_GAME_SETTING_SCENE_H_
#define _SYS_MENU_GAME_SETTING_SCENE_H_

#include "cocos2d.h"
#include "SysMenuScene.h"

class SysMenuGameSettingScene : public cocos2d::Scene
{
public:
  static cocos2d::Scene* createScene();

  virtual bool init();

  void onCallBackButton(Ref* pSender);
  void onSoundControl(Ref* pSender);
  void onModeControl(Ref* pSender);

  CREATE_FUNC(SysMenuGameSettingScene);
private:
  cocos2d::Size winSize;
};
#endif // _SYS_MENU_GAME_SETTING_SCENE_H_