#pragma once
/****************************************************************************

 this is system menu scene init, it will be callled at AppDelegat.cpp

 ****************************************************************************/
#ifndef _SYS_MENU_SCENE_H_
#define _SYS_MENU_SCENE_H_

#include "cocos2d.h"
#include "SysMenu_AboutScene.h"
#include "SysMenu_GameSettingScene.h"
#include "SysMenu_NewGameScene.h"

#define BG             "loading.png"
#define LOGO           "logo.png"
#define LOGOBACK       "logoBack.png"
#define BUTTON         "menu.png"
#define MENUTITTLE     "menuTitle.png"

#define CACHE_1        "textureTransparentPack.plist"
#define CACHE_2        "textureOpaquePack.plist"

#define COPYRIGHT      "Power by Cocos2d-X4.0, create by Ccoccli"
#define RETURNMENU     "Return Menu"

#define BUTTONWIDTH    123
#define BUTTONHEIGHT   36

#define SCALING        1.5

class SysMenuScene : public cocos2d::Scene
{
public:
  static cocos2d::Scene* createScene();

  virtual bool init();

  virtual void update(float dt);

  void onNewGame(Ref* pSender);

  void onGameSetting(Ref* pSender);

  void onAbout(Ref* pSender);

  CREATE_FUNC(SysMenuScene);
private:
  cocos2d::Sprite* _ship;

  cocos2d::Size winSize;
};

#endif  //_SYS_MENU_SCENE_H_