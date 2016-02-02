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

    auto closeItem = MenuItemImage::create(
                                           "GameOverScreen/QuitButton.png",
                                           "GameOverScreen/QuitButton.png",
                                           CC_CALLBACK_1(GameOver::quitGame, this));
	auto retryItem =
		MenuItemImage::create("GameOverScreen/RetryButton.png",
		"GameOverScreen/RetryButton.png",
		CC_CALLBACK_1(GameOver::activateGameScene, this));

	auto youDiedText =
		MenuItemImage::create("GameOverScreen/YouDiedText.png",
		"GameOverScreen/YouDiedText.png");
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width/2, visibleSize.height - 250 - closeItem->getContentSize().height));
	retryItem->setPosition(Vec2(origin.x + visibleSize.width/2, visibleSize.height - 150 - retryItem->getContentSize().height));
	youDiedText->setPosition(Vec2(origin.x + visibleSize.width / 2, visibleSize.height - 50 - youDiedText->getContentSize().height));
    // create menu, it's an autorelease object
    auto menu = Menu::create(youDiedText, closeItem, retryItem, NULL);
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

void GameOver::quitGame(Ref* pSender)
{
	auto scene = ConfirmQuit::createScene();
	Director::getInstance()->pushScene(scene);
}
