#include "GameOverScene.h"

USING_NS_CC;

Scene* GameOver::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = GameOver::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameOver::init()
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

<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
>>>>>>> 74f70ad2e7e511ee9da6b306c9310e5294db5989
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(GameOver::menuCloseCallback, this));
<<<<<<< HEAD
=======
>>>>>>> 4266d7d8e9b9d3fe75ec8c663c8bf0c002e0c062
>>>>>>> 74f70ad2e7e511ee9da6b306c9310e5294db5989
	auto retryItem =
		MenuItemImage::create("GameOverScreen/RetryButton.png",
		"GameOverScreen/RetryButton.png",
		CC_CALLBACK_1(GameOver::activateGameScene, this));
    
<<<<<<< HEAD
=======
<<<<<<< HEAD
	retryItem->setPosition(Vec2(origin.x + visibleSize.width/2, visibleSize.height - 50 - retryItem->getContentSize().height));
    // create menu, it's an autorelease object
    auto menu = Menu::create(retryItem, NULL);
=======
>>>>>>> 74f70ad2e7e511ee9da6b306c9310e5294db5989
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));
	retryItem->setPosition(Vec2(origin.x + visibleSize.width/2, visibleSize.height - 50 - retryItem->getContentSize().height));
    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, retryItem, NULL);
<<<<<<< HEAD
=======
>>>>>>> 4266d7d8e9b9d3fe75ec8c663c8bf0c002e0c062
>>>>>>> 74f70ad2e7e511ee9da6b306c9310e5294db5989
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    return true;
}

void GameOver::activateGameScene(Ref *pSender)
{
	auto scene = GameScene::createScene();
	Director::getInstance()->replaceScene(scene);
}

void GameOver::activateMainMenuScene(Ref *pSender)
{
	auto scene = MainMenu::createScene();
	Director::getInstance()->replaceScene(scene);
}
<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
>>>>>>> 74f70ad2e7e511ee9da6b306c9310e5294db5989

void GameOver::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
<<<<<<< HEAD
=======
>>>>>>> 4266d7d8e9b9d3fe75ec8c663c8bf0c002e0c062
>>>>>>> 74f70ad2e7e511ee9da6b306c9310e5294db5989
