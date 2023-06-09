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
  guideSceneBGM = AudioEngine::play2d(GUIDEBGM, true);

  /* get windows size **/
  winSize = Director::getInstance()->getWinSize();

  /* create background */
  auto bg = Sprite::create(TITLEBG);

  bg->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
  bg->setPosition(Point(0, 0));
  bg->setContentSize(winSize);

  /*add sprite to the scene : sprite, floor height, tag*/
  this->addChild(bg, 0, 0);

  /* create logo*/
  auto logo = Sprite::create(LOGO);
  logo->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
  logo->setPosition(Point(winSize.width / 2 - 350, winSize.height + 100));
  logo->setScale(1.5);

  logo->runAction(MoveTo::create(5, \
    Point(winSize.width / 2 - 350, winSize.height / 2 + 250)));
  this->addChild(logo, 1, 1);

  /* create porgrass section one */
  auto prograssDirt = Sprite::create(PROGRASSDIRT);
  prograssDirt->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
  prograssDirt->setPosition(Point(winSize.width / 2 - 350, -100));
  prograssDirt->setScaleX(3.5);
  prograssDirt->setScaleY(2);

  prograssDirt->runAction(MoveTo::create(5, \
    Point(winSize.width / 2 - 350, winSize.height / 2 - 300)));
  this->addChild(prograssDirt, 1, 2);

  /* create prograss sction two */
  auto prograssGrass = Sprite::create(PROGRASSGRASS);
  prograssGrass->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
  prograssGrass->setPosition(Point(winSize.width / 2 - 350, -100));
  prograssGrass->setScaleX(3.5);
  prograssGrass->setScaleY(2);
  prograssGrass->runAction(MoveTo::create(5, \
    Point(winSize.width / 2 - 350, winSize.height / 2 - 250)));
  this->addChild(prograssGrass, 1, 2);

  /*start game button */
  auto label = Label::createWithTTF(STARTGAME, SYSTEMFONT, 40);
  label->setColor(Color3B(106, 210, 51));
  auto backButton = MenuItemLabel::create(label, CC_CALLBACK_1(GuideScene::onStartGame, this));
  auto menu = Menu::create(backButton, NULL);
  menu->setPosition(Point(winSize.width / 2, -100));

  menu->runAction(MoveTo::create(5, \
    Point(winSize.width / 2, winSize.height / 2 - 260)));
  this->addChild(menu, 1, 3);

  /*create remark*/
  auto crlabel = Label::createWithTTF(COPYRIGHT, SYSTEMFONT, 30);
  crlabel->setColor(Color3B(255, 255, 51));
  crlabel->setPosition(Point(winSize.width - crlabel->getContentSize().width + 250, -100));

  crlabel->runAction(MoveTo::create(5, \
    Point(winSize.width - crlabel->getContentSize().width + 250, 20)));
  this->addChild(crlabel, 1, 4);

  return true;
}

void GuideScene::update(float dt)
{

}

void GuideScene::onStartGame(Ref* pSender)
{
  AudioEngine::pause(guideSceneBGM);

  auto gameMenuScene = GameMenuScene::create();

  Director::getInstance()->replaceScene(TransitionFade::create(2, gameMenuScene));
}
