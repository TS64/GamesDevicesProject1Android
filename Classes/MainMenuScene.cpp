#include "MainMenuScene.h"

USING_NS_CC;

Scene* MainMenu::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MainMenu::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MainMenu::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
	auto bg =
		Sprite::create("MainMenuScreen/BackgroundTemp.jpeg");
	auto menuTitle =
		MenuItemImage::create("MainMenuScreen/TreasureDefendTitle.png",
		"MainMenuScreen/TreasureDefendTitle.png");
	auto playItem =
		MenuItemImage::create("MainMenuScreen/StartGameButton.png",
		"MainMenuScreen/StartGameButton.png",
		CC_CALLBACK_1(MainMenu::activateGameScene, this));
	//menuTitle->setPosition(Vec2(origin.x + visibleSize.width/2, origin.y + visibleSize.height - menuTitle->getContentSize().height/2));
	//playItem->setPosition(Vec2(origin.x + visibleSize.width/2, origin.y + visibleSize.height - 100));
	bg->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2));
	bg->setScaleX(visibleSize.width / bg->getContentSize().width);
	bg->setScaleY(visibleSize.height / bg->getContentSize().height);
	menuTitle->setPosition(Vec2(0, 100));
	playItem->setPosition(Vec2(0, 0));
	//background->setPosition(Vec2(100, 100));

	auto menu = Menu::create(menuTitle, playItem, NULL);

	//menu->alignItemsVerticallyWithPadding(visibleSize.height / 4);
	this->addChild(bg);
	this->addChild(menu);
    
    return true;
}

void MainMenu::activateGameScene(Ref *pSender)
{
	auto scene = GameScene::createScene();
	Director::getInstance()->replaceScene(scene);
}
