/****************************************************************************

 this is system menu scene init, it will be callled at AppDelegat.cpp

 ****************************************************************************/

#include "SysMenuScene.h"

USING_NS_CC;

Scene* SysMenuScene::createScene()
{
  return SysMenuScene::create();
}

bool SysMenuScene::init()
{
  if (!Scene::init())
  {
    return false;
  }

  /* load sprite frame cache **/
  SpriteFrameCache::getInstance()->addSpriteFramesWithFile(CACHE_1);
  SpriteFrameCache::getInstance()->addSpriteFramesWithFile(CACHE_2);

  /* create backround sprite **/
  auto bg = Sprite::create(BG);

  bg->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
  bg->setScale(SCALING);

  this->addChild(bg, 0, 1);

  /* get windows size **/
  winSize = Director::getInstance()->getWinSize();

  /* create logo section one sprite **/
  auto logo = Sprite::create(LOGO);

  logo->setAnchorPoint(Vec2::ANCHOR_MIDDLE_TOP);
  logo->setPosition(Point(winSize.width / 2, winSize.height / 2 + 275));
  logo->setScale(SCALING);

  this->addChild(logo, 10, 1);

  /* create logo section two sprite **/
  auto logoBG = Sprite::create(LOGOBACK);
  logoBG->setAnchorPoint(Vec2::ANCHOR_MIDDLE_TOP);
  logoBG->setPosition(Point(winSize.width / 2, winSize.height / 2 + 275));
  logoBG->setScale(SCALING);

  this->addChild(logoBG, 9);

  /* create new game button of the system menu **/
  auto newGameNormal   = Sprite::create(BUTTON, Rect(0, 0, BUTTONWIDTH, BUTTONHEIGHT));
  auto newGameSelected = Sprite::create(BUTTON, Rect(0, BUTTONHEIGHT, BUTTONWIDTH, BUTTONHEIGHT));
  auto newGameDisabled = Sprite::create(BUTTON, Rect(0, BUTTONHEIGHT * 2, BUTTONWIDTH, BUTTONHEIGHT));

  auto newGame = MenuItemSprite::create(newGameNormal, newGameSelected, newGameDisabled, \
    CC_CALLBACK_1(SysMenuScene::onNewGame, this));

  newGame->setTag(19);
  newGame->setScale(SCALING);

  /* create game stting button of the system menu **/
  auto gameSettingNormal   = Sprite::create(BUTTON, Rect(BUTTONWIDTH, 0, BUTTONWIDTH, BUTTONHEIGHT));
  auto gameSettingSelected = Sprite::create(BUTTON, Rect(BUTTONWIDTH, BUTTONHEIGHT, BUTTONWIDTH, BUTTONHEIGHT));
  auto gameSettingDisabled = Sprite::create(BUTTON, Rect(BUTTONWIDTH, BUTTONHEIGHT * 2, BUTTONWIDTH, BUTTONHEIGHT));

  auto gameSetting = MenuItemSprite::create(gameSettingNormal, gameSettingSelected, gameSettingDisabled, \
    CC_CALLBACK_1(SysMenuScene::onGameSetting, this));

  gameSetting->setTag(20);
  gameSetting->setScale(SCALING);

  /* create about button of the system menu **/
  auto aboutNormal   = Sprite::create(BUTTON, Rect(BUTTONWIDTH * 2, 0, BUTTONWIDTH, BUTTONHEIGHT));
  auto aboutSelected = Sprite::create(BUTTON, Rect(BUTTONWIDTH * 2, BUTTONHEIGHT, BUTTONWIDTH, BUTTONHEIGHT));
  auto aboutDisabled = Sprite::create(BUTTON, Rect(BUTTONWIDTH * 2, BUTTONHEIGHT * 2, BUTTONWIDTH, BUTTONHEIGHT));

  auto about = MenuItemSprite::create(aboutNormal, aboutSelected, aboutDisabled, \
    CC_CALLBACK_1(SysMenuScene::onAbout, this));

  about->setTag(21);
  about->setScale(SCALING);

  /* create menu **/
  auto menu = Menu::create(newGame, gameSetting, about, NULL);
  menu->alignItemsVerticallyWithPadding(15);
  this->addChild(menu, 1, 2);
  menu->setPosition(Point(winSize.width / 2, winSize.height / 2 - 100));


  /* create label about copyright **/

  auto label = Label::createWithSystemFont("Power by Cocos2d-X4.0, create by Ccoccli", "Arial", 20);
  label->setColor(Color3B(31, 45, 150));
  this->addChild(label, 1);

  label->setPosition(Point(winSize.width / 2, winSize.height / 2 - 300));

  /* create background animation **/
  _ship = Sprite::createWithSpriteFrameName("ship03.png");
  this->addChild(_ship, 0, 4);

  _ship->setPosition(Point(CCRANDOM_0_1() * winSize.width, 0));

  _ship->runAction(MoveBy::create(2, \
    Point(CCRANDOM_0_1() * winSize.width, Point(CCRANDOM_0_1() * winSize.width, 0).y + winSize.height + 100)));

  this->schedule(CC_SCHEDULE_SELECTOR(SysMenuScene::update), 0.1);
  return true;
}

void SysMenuScene::update(float dt)
{
  if (_ship->getPosition().y > 750)
  {
    _ship->setPosition(Point(CCRANDOM_0_1() * winSize.width, 10));

    _ship->runAction(MoveBy::create(floor(5 * CCRANDOM_0_1()), \
      Point(CCRANDOM_0_1() * winSize.width, Point(CCRANDOM_0_1() * winSize.width, 0).y + winSize.height + 100)));
  }
}

void SysMenuScene::onNewGame(Ref* pSender)
{

}

void SysMenuScene::onGameSetting(Ref* pSender)
{

}

void SysMenuScene::onAbout(Ref* pSender)
{

}