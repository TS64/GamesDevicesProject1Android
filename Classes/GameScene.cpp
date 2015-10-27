#include "GameScene.h"

USING_NS_CC;

Scene* GameScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = GameScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

	auto bg =
		Sprite::create("GameScreen/BackgroundPlayingTemp.jpg");
	auto pauseItem =
		MenuItemImage::create("GameScreen/PauseButton.png",
		"GameScreen/PauseButton.png",
		CC_CALLBACK_1(GameScene::activatePauseScene, this));
	auto dieItem =
		MenuItemImage::create("GameScreen/DieButton.png",
		"GameScreen/DieButton.png",
		CC_CALLBACK_1(GameScene::activateGameOverScene, this));

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
	/*pauseItem->setPosition(Point(pauseItem->getContentSize().width -
		(pauseItem->getContentSize().width / 4) + origin.x,
		visibleSize.height - pauseItem->getContentSize().height +
		(pauseItem->getContentSize().width / 4) + origin.y));*/
	pauseItem->setPosition(Point(pauseItem->getContentSize().width / 2, origin.y + visibleSize.height - pauseItem->getContentSize().height/2));
	dieItem->setPosition(Point(origin.x + visibleSize.width / 2, visibleSize.height - 100 - dieItem->getContentSize().height));
	bg->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	bg->setScaleX(visibleSize.width / bg->getContentSize().width);
	bg->setScaleY(visibleSize.height / bg->getContentSize().height);

	auto menu = Menu::create(pauseItem, dieItem, NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(bg);
	this->addChild(menu);
    
    return true;
}

void GameScene::activatePauseScene(Ref *pSender)
{
	auto scene = PauseMenu::createScene();
	Director::getInstance()->pushScene(scene);
}

void GameScene::activateGameOverScene(Ref *pSender)
{
	auto scene = GameOver::createScene();
	Director::getInstance()->pushScene(scene);
}
