#include "GameScene.h"

USING_NS_CC;

<<<<<<< HEAD
GameScene::GameScene() :
started(false),
moving(false),
clicked(false)
{

}


=======
>>>>>>> 74f70ad2e7e511ee9da6b306c9310e5294db5989
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
<<<<<<< HEAD
	MoveTo * getPlayerPos();
	Animate * HandleMummyAnimation(int i);
	Animate * HandleBulletAnimation();

	auto mummy =
		Sprite::create();
	playerPos = cocos2d::Vec2(300, 300);
=======
	Animate * HandlePlayerAnimation();
	Animate * HandleMummyAnimation(int i);

	auto player =
		Sprite::create();
	auto mummy =
		Sprite::create();
	playerPos = cocos2d::Vec2(100, 100);
>>>>>>> 74f70ad2e7e511ee9da6b306c9310e5294db5989
	mummyPos = cocos2d::Vec2(200, 100);
	chestPos = cocos2d::Vec2(400, 300);
	enemyPos[0] = cocos2d::Vec2(390, 45);
	enemyPos[1] = cocos2d::Vec2(50, 310);
	enemyPos[2] = cocos2d::Vec2(390, 570);
	enemyPos[3] = cocos2d::Vec2(750, 310);
<<<<<<< HEAD
	circlePadPos = cocos2d::Vec2(300, 300);

	initChestPos();

	pSprite = Player::create(playerPos);
	pSprite->runAction(RepeatForever::create(m_player.createPlayerSprite()));
	mummy->runAction(RepeatForever::create(HandleMummyAnimation(3))); // 0 = Up, 1 = Right, 2 = Down, 3 = Left

	bullet =
		Sprite::create("GameScreen/Bullet.png");
=======
	
	player->runAction(RepeatForever::create(HandlePlayerAnimation()));
	mummy->runAction(RepeatForever::create(HandleMummyAnimation(3))); // 0 = Up, 1 = Right, 2 = Down, 3 = Left

	

>>>>>>> 74f70ad2e7e511ee9da6b306c9310e5294db5989
	auto bg =
		Sprite::create("GameScreen/Room1bg.png");
	auto chest =
		Sprite::create("GameScreen/Chest.png");
<<<<<<< HEAD
	auto circlePadOutline =
		Sprite::create("GameScreen/CirclePadOutline.png");
	circlePad =
		Sprite::create("GameScreen/CirclePad.png");
=======
>>>>>>> 74f70ad2e7e511ee9da6b306c9310e5294db5989
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
<<<<<<< HEAD
	pauseItem->setPosition(Point(pauseItem->getContentSize().width / 2, origin.y + visibleSize.height - pauseItem->getContentSize().height/2));
	dieItem->setPosition(Point(800 - dieItem->getContentSize().width/2, origin.y + visibleSize.height - dieItem->getContentSize().height / 2));
	mummy->setPosition(mummyPos);
	chest->setPosition(chestPos);
	circlePadOutline->setPosition(cocos2d::Vec2(300, 300));
	circlePad->setPosition(circlePadPos);
=======
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
>>>>>>> 74f70ad2e7e511ee9da6b306c9310e5294db5989
	bg->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	bg->setScaleX(visibleSize.width / bg->getContentSize().width);
	bg->setScaleY(visibleSize.height / bg->getContentSize().height);
	
	auto menu = Menu::create(pauseItem, dieItem, NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(bg);
	this->addChild(chest);
	this->addChild(menu);
<<<<<<< HEAD
	//this->addChild(player);
	this->addChild(circlePadOutline);
	this->addChild(circlePad);
	//this->addChild(bullet);
	std::vector<CCSprite*> enemySprites;
	//std::vector<CCSprite*> bulletSprites;
	//std::vector<std::string> spriteNames = { "GameScreen/MummySprite.png" };
	//bulletPos[0] = Vec2(100, 100);
=======
	this->addChild(player);
	std::vector<CCSprite*> enemySprites;
	//std::vector<std::string> spriteNames = { "GameScreen/MummySprite.png" };

>>>>>>> 74f70ad2e7e511ee9da6b306c9310e5294db5989
	for (int i = 0; i <= 3; i++)
	{
		CCSprite* mummy = cocos2d::CCSprite::create();
		mummy->setPosition(enemyPos[i]);
		
		mummy->runAction(RepeatForever::create(HandleMummyAnimation(i)));
		enemySprites.push_back(mummy);

		addChild(mummy);
	}
<<<<<<< HEAD
	for (int i = 0; i < 50; i++)
	{
		CCSprite* bullet = cocos2d::CCSprite::create();
		bullet->setPosition(bulletPos[i]);

		bullet->runAction(RepeatForever::create(HandleBulletAnimation()));
		bulletSprites.push_back(bullet);
		addChild(bullet);
		bulletAlive[i] = false;
	}
	createPlayer();
	this->scheduleUpdate();
=======

>>>>>>> 74f70ad2e7e511ee9da6b306c9310e5294db5989
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
<<<<<<< HEAD
Animate * HandleBulletAnimation(){
	Vector<SpriteFrame*> animFramesBullet;
	animFramesBullet.reserve(1);
	animFramesBullet.pushBack(SpriteFrame::create("GameScreen/Bullet.png", Rect(0, 0, 8, 8)));
	Animation* bulletAnimation = Animation::createWithSpriteFrames(animFramesBullet, 0.1f);
	Animate* bulletAnimate = Animate::create(bulletAnimation);
	return bulletAnimate;
}
=======

>>>>>>> 74f70ad2e7e511ee9da6b306c9310e5294db5989
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
<<<<<<< HEAD


void GameScene::movePlayer() {
	cocos2d::MoveBy * moveBy = MoveBy::create(10, Vec2(10, 0));
}
void GameScene::update(float dt)
{
	addEvents();
	bulletFired = false;
	initChestPos();
	m_player.movePlayer(circlePadPos);
	pSprite->setPosition(m_player.getPlayerPosition());
	playerPos = m_player.getPlayerPosition();
	
	
	for (int i = 0; i < 50; i++)
	{
		bulletPos[i] += bulletVel[i];
		bulletSprites[i]->setPosition(bulletPos[i]);
		if (bulletPos[i].x > 850 || bulletPos[i].x < -50 ||
			bulletPos[i].y > 650 || bulletPos[i].y < -50)
			bulletAlive[i] = false;
	}
}

void GameScene::addEvents() {
	auto listener1 = EventListenerTouchOneByOne::create();
	listener1->onTouchBegan = [this](Touch* touch, Event* event){
		Vec2 pos = touch->getLocation();
		moveCirclePad(pos);
		rotateThePlayer(pos);
		FireBullet(pos);
		clicked = true;
		return true;
	};
	GameScene* gs = this;
	listener1->onTouchMoved = [gs](Touch* touch, Event* event){
		Vec2 pos = touch->getLocation();
		gs->moveCirclePad(pos);
		
	};
	listener1->onTouchEnded = [this](Touch* touch, Event* event){
		clicked = false;
		moving = false;
		circlePadPos = Vec2(300, 300);
		circlePad->setPosition(circlePadPos);
	};
	listener1->onTouchCancelled = [this](Touch* touch, Event* event){
		clicked = false;
		moving = false;
		circlePadPos = Vec2(300, 300);
		circlePad->setPosition(circlePadPos);
	};
	cocos2d::Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(listener1, 30);
}

void GameScene::moveCirclePad(Vec2 pos) {
	if (moving == true ||
		pos.x > circlePadPos.x && pos.x < circlePadPos.x + 20 &&
		pos.y < circlePadPos.y && pos.y > circlePadPos.y - 20 &&
		clicked == true)
	{
		if (sqrt(((circlePadPos.x - 300) * (circlePadPos.x - 300)) +
			((circlePadPos.y - 300) * (circlePadPos.y - 300))) <= 36)
		{
			circlePadPos = pos;
			moving = true;
		}
		if (sqrt(((circlePadPos.x - 300) * (circlePadPos.x - 300)) +
			((circlePadPos.y - 300) * (circlePadPos.y - 300))) > 36)
		{
			float dotProduct = (((300 + 10 - 300) * (pos.x - 300)) +
				((300 - 300) * (pos.y - 300)));
			float A = sqrt(((pos.x - 300) * (pos.x - 300))
				+ ((pos.y - 300)* (pos.y - 300)));
			float angleInDegree = acos(dotProduct / (10 * A));
			if (pos.y < 300)
				angleInDegree *= -1;
			circlePadPos.x = 300 + (cos(angleInDegree) * 36);
			circlePadPos.y = 300 + (sin(angleInDegree) * 36);
		}
		circlePad->setPosition(circlePadPos);
	}
	
}

void GameScene::rotateThePlayer(Vec2 pos) {
	m_player.rotatePlayer(pos);
	pSprite->setRotation(m_player.getAngleToFace()*-1 + 90);
}

bool GameScene::FireBullet(Vec2 pos) {
	for (int i = 0; i < 50; i++)
	{
		if (bulletAlive[i] == false && bulletFired == false)
		{
			float distance = sqrt((pos.x - playerPos.x) * (pos.x - playerPos.x) +
				(pos.y - playerPos.y) * (pos.y - playerPos.y));
			float bulletVelx = 0.1*((pos.x - playerPos.x) / distance);
			float bulletVely = 0.1*((pos.y - playerPos.y) / distance);
			bulletPos[i] = playerPos + Vec2(bulletVelx * 240, bulletVely * 240);
			bulletVel[i] = Vec2(bulletVelx * 50, bulletVely * 50);
			bulletAlive[i] = true;
			bulletFired = true;
			return true;
		}
	}
	return false;
}
void GameScene::createPlayer() {
	pSprite->setPosition(300, 300);
	this->addChild(pSprite, 1);
}

void GameScene::initChestPos() {
	
	if (started == false)
	{
		chestPos = cocos2d::Vec2(400, 300);
		started = true;
	}
	if (started == true)
	{
		chestPos.x++;
		started = false;
	}

=======
void GameScene::Update()
{
	
>>>>>>> 74f70ad2e7e511ee9da6b306c9310e5294db5989
}
