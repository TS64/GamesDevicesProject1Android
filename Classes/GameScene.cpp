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
	Animate * HandlePlayerAnimation();
	Animate * HandleMummyAnimation(int i);

	auto player =
		Sprite::create();
	auto mummy =
		Sprite::create();
	playerPos = cocos2d::Vec2(100, 100);
	mummyPos = cocos2d::Vec2(200, 100);
	chestPos = cocos2d::Vec2(400, 300);
	enemyPos[0] = cocos2d::Vec2(390, 45);
	enemyPos[1] = cocos2d::Vec2(50, 310);
	enemyPos[2] = cocos2d::Vec2(390, 570);
	enemyPos[3] = cocos2d::Vec2(750, 310);
	
	player->runAction(RepeatForever::create(HandlePlayerAnimation()));
	mummy->runAction(RepeatForever::create(HandleMummyAnimation(3))); // 0 = Up, 1 = Right, 2 = Down, 3 = Left

	

	auto bg =
		Sprite::create("GameScreen/Room1bg.png");
	auto chest =
		Sprite::create("GameScreen/Chest.png");
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
	//dieItem->setPosition(Point(origin.x + visibleSize.width / 2, visibleSize.height - 100 - dieItem->getContentSize().height));
	dieItem->setPosition(Point(800 - dieItem->getContentSize().width/2, origin.y + visibleSize.height - dieItem->getContentSize().height / 2));
	player->setPosition(playerPos);
	mummy->setPosition(mummyPos);
	chest->setPosition(chestPos);
	bg->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	bg->setScaleX(visibleSize.width / bg->getContentSize().width);
	bg->setScaleY(visibleSize.height / bg->getContentSize().height);
	
	auto menu = Menu::create(pauseItem, dieItem, NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(bg);
	this->addChild(chest);
	this->addChild(menu);
	this->addChild(player);
	std::vector<CCSprite*> enemySprites;
	//std::vector<std::string> spriteNames = { "GameScreen/MummySprite.png" };

	for (int i = 0; i <= 3; i++)
	{
		CCSprite* mummy = cocos2d::CCSprite::create();
		mummy->setPosition(enemyPos[i]);
		
		mummy->runAction(RepeatForever::create(HandleMummyAnimation(i)));
		enemySprites.push_back(mummy);

		addChild(mummy);
	}

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

Animate * HandlePlayerAnimation(){
	Vector<SpriteFrame*> animFramesPlayer;
	animFramesPlayer.reserve(4);
	animFramesPlayer.pushBack(SpriteFrame::create("GameScreen/PlayerSprite1.png", Rect(0, 0, 22, 44)));
	animFramesPlayer.pushBack(SpriteFrame::create("GameScreen/PlayerSprite2.png", Rect(0, 0, 22, 44)));
	animFramesPlayer.pushBack(SpriteFrame::create("GameScreen/PlayerSprite3.png", Rect(0, 0, 22, 44)));
	animFramesPlayer.pushBack(SpriteFrame::create("GameScreen/PlayerSprite2.png", Rect(0, 0, 22, 44)));
	Animation* playerAnimation = Animation::createWithSpriteFrames(animFramesPlayer, 0.1f);
	Animate* playerAnimate = Animate::create(playerAnimation);
	return playerAnimate;
}

Animate * HandleMummyAnimation(int i){
	Vector<SpriteFrame*> animFramesMummy;
	animFramesMummy.reserve(7);
	if (i == 0)
	{	
		animFramesMummy.pushBack(SpriteFrame::create("GameScreen/MummySpriteUp1.png", Rect(0, 0, 40, 31)));
		animFramesMummy.pushBack(SpriteFrame::create("GameScreen/MummySpriteUp2.png", Rect(0, 0, 40, 31)));
		animFramesMummy.pushBack(SpriteFrame::create("GameScreen/MummySpriteUp3.png", Rect(0, 0, 40, 31)));
		animFramesMummy.pushBack(SpriteFrame::create("GameScreen/MummySpriteUp4.png", Rect(0, 0, 40, 31)));
		animFramesMummy.pushBack(SpriteFrame::create("GameScreen/MummySpriteUp5.png", Rect(0, 0, 40, 31)));
		animFramesMummy.pushBack(SpriteFrame::create("GameScreen/MummySpriteUp6.png", Rect(0, 0, 40, 31)));
		animFramesMummy.pushBack(SpriteFrame::create("GameScreen/MummySpriteUp7.png", Rect(0, 0, 40, 31)));
	}
	else if (i == 1)
	{
		animFramesMummy.pushBack(SpriteFrame::create("GameScreen/MummySpriteRight1.png", Rect(0, 0, 25, 37)));
		animFramesMummy.pushBack(SpriteFrame::create("GameScreen/MummySpriteRight2.png", Rect(0, 0, 25, 37)));
		animFramesMummy.pushBack(SpriteFrame::create("GameScreen/MummySpriteRight3.png", Rect(0, 0, 25, 37)));
		animFramesMummy.pushBack(SpriteFrame::create("GameScreen/MummySpriteRight4.png", Rect(0, 0, 25, 37)));
		animFramesMummy.pushBack(SpriteFrame::create("GameScreen/MummySpriteRight5.png", Rect(0, 0, 25, 37)));
		animFramesMummy.pushBack(SpriteFrame::create("GameScreen/MummySpriteRight6.png", Rect(0, 0, 25, 37)));
		animFramesMummy.pushBack(SpriteFrame::create("GameScreen/MummySpriteRight7.png", Rect(0, 0, 25, 37)));
	}
	else if (i == 2)
	{
		animFramesMummy.pushBack(SpriteFrame::create("GameScreen/MummySpriteDown1.png", Rect(0, 0, 44, 30)));
		animFramesMummy.pushBack(SpriteFrame::create("GameScreen/MummySpriteDown2.png", Rect(0, 0, 44, 30)));
		animFramesMummy.pushBack(SpriteFrame::create("GameScreen/MummySpriteDown3.png", Rect(0, 0, 44, 30)));
		animFramesMummy.pushBack(SpriteFrame::create("GameScreen/MummySpriteDown4.png", Rect(0, 0, 44, 30)));
		animFramesMummy.pushBack(SpriteFrame::create("GameScreen/MummySpriteDown5.png", Rect(0, 0, 44, 30)));
		animFramesMummy.pushBack(SpriteFrame::create("GameScreen/MummySpriteDown6.png", Rect(0, 0, 44, 30)));
		animFramesMummy.pushBack(SpriteFrame::create("GameScreen/MummySpriteDown7.png", Rect(0, 0, 44, 30)));
	}
	else if (i == 3)
	{
		animFramesMummy.pushBack(SpriteFrame::create("GameScreen/MummySpriteLeft1.png", Rect(0, 0, 25, 37)));
		animFramesMummy.pushBack(SpriteFrame::create("GameScreen/MummySpriteLeft2.png", Rect(0, 0, 25, 37)));
		animFramesMummy.pushBack(SpriteFrame::create("GameScreen/MummySpriteLeft3.png", Rect(0, 0, 25, 37)));
		animFramesMummy.pushBack(SpriteFrame::create("GameScreen/MummySpriteLeft4.png", Rect(0, 0, 25, 37)));
		animFramesMummy.pushBack(SpriteFrame::create("GameScreen/MummySpriteLeft5.png", Rect(0, 0, 25, 37)));
		animFramesMummy.pushBack(SpriteFrame::create("GameScreen/MummySpriteLeft6.png", Rect(0, 0, 25, 37)));
		animFramesMummy.pushBack(SpriteFrame::create("GameScreen/MummySpriteLeft7.png", Rect(0, 0, 25, 37)));
	}
	Animation* mummyAnimation = Animation::createWithSpriteFrames(animFramesMummy, 0.1f);
	Animate* mummyAnimate = Animate::create(mummyAnimation);
	return mummyAnimate;
}
void GameScene::Update()
{
	
}
