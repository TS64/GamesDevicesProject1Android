#include "ConfirmQuitScene.h"

USING_NS_CC;

Scene* ConfirmQuit::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
	auto layer = ConfirmQuit::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool ConfirmQuit::init()
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

    auto AreYouSureItem = 
		MenuItemImage::create("ConfirmQuitScreen/AreYouSureText.png", 
		"ConfirmQuitScreen/AreYouSureText.png");
	auto YesItem =
		MenuItemImage::create("ConfirmQuitScreen/YesButton.png",
		"ConfirmQuitScreen/YesButton.png",
		CC_CALLBACK_1(ConfirmQuit::quit, this));
	auto NoItem =
		MenuItemImage::create("ConfirmQuitScreen/NoButton.png",
		"ConfirmQuitScreen/NoButton.png",
		CC_CALLBACK_1(ConfirmQuit::resume, this));
    
	AreYouSureItem->setPosition(Vec2(origin.x + visibleSize.width / 2, visibleSize.height - 50 - AreYouSureItem->getContentSize().height));
	YesItem->setPosition(Vec2(origin.x + visibleSize.width / 2, visibleSize.height - 150 - YesItem->getContentSize().height));
	NoItem->setPosition(Vec2(origin.x + visibleSize.width / 2, visibleSize.height - 250 - NoItem->getContentSize().height));
    // create menu, it's an autorelease object
    auto menu = Menu::create(AreYouSureItem, YesItem, NoItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    return true;
}

void ConfirmQuit::resume(Ref *pSender) {
	Director::getInstance()->popScene();
}

void ConfirmQuit::quit(Ref* pSender)
{
	auto scene = MainMenu::createScene();
	Director::getInstance()->replaceScene(scene);
}
