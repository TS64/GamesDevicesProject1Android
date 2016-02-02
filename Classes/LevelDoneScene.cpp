#include "LevelDoneScene.h"

USING_NS_CC;

Scene* LevelDone::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
	auto layer = LevelDone::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool LevelDone::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object

	auto nextLevelItem =
		MenuItemImage::create("LevelDoneScreen/NextLevelButton.png",
		"LevelDoneScreen/NextLevelButton.png",
		CC_CALLBACK_1(LevelDone::goToNextStage, this));
	auto levelCompleteText =
		MenuItemImage::create("LevelDoneScreen/LevelCompleteText.png",
		"LevelDoneScreen/LevelCompleteText.png");
	auto bg =
		Sprite::create("LevelDoneScreen/BackgroundPlayingTemp.jpg");
	auto objectiveBack =
		MenuItemImage::create("OptionsScreen/ObjectiveBackdrop.png",
		"OptionsScreen/ObjectiveBackdrop.png");
	nextLevelItem->setPosition(Vec2(origin.x + visibleSize.width / 2, visibleSize.height - 150 - nextLevelItem->getContentSize().height));
	levelCompleteText->setPosition(Vec2(origin.x + visibleSize.width / 2, visibleSize.height - 50 - levelCompleteText->getContentSize().height));
	bg->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	bg->setScaleX(visibleSize.width / bg->getContentSize().width);
	bg->setScaleY(visibleSize.height / bg->getContentSize().height);
	objectiveBack->setPosition(400, 130);
	objectiveBack->setScaleX(2.35f); objectiveBack->setScaleY(1.3f);
    // create menu, it's an autorelease object
	auto menu = Menu::create(nextLevelItem, NULL);
    menu->setPosition(Vec2::ZERO);
	this->addChild(bg);
    this->addChild(menu, 1);
	this->addChild(levelCompleteText);
	this->addChild(objectiveBack);

	objectiveLabel = LabelBMFont::create();
	objectiveLabel->setString("Objective:\nSurvive.\nKill as many zombies as you can before your inevitable death.\nGrab the coins and drop them in the chest."); 
	objectiveLabel->setPosition(400, 130);
	objectiveLabel->setScale(2);
	objectiveLabel->setColor(ccc3(0, 0, 0));
	this->addChild(objectiveLabel);


    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    return true;
}

void LevelDone::goToNextStage(Ref *pSender)
{
	Director::getInstance()->popScene();
}
