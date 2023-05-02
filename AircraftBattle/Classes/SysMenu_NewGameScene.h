#pragma once
/****************************************************************************

 this is the son of the system menu that start game button, it will be

 called at SysMenuScene.cpp

 ****************************************************************************/

#ifndef _SYS_MENU_NEW_GAME_SCENE_H_
#define _SYS_MENU_NEW_GAME_SCENE_H_

#include "cocos2d.h"
#include "SysMenuScene.h"

class SysMenuNewGameScene : public cocos2d::Scene
{
public:
  static cocos2d::Scene* createScene();

  virtual bool init();

  void onCallBackButton(Ref* pSender);

  CREATE_FUNC(SysMenuNewGameScene);
};
#endif // _SYS_MENU_NEW_GAME_SCENE_H_