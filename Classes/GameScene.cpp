
#include "GameScene.h"
#include "GameData.h"




USING_NS_CC;

GameScene::GameScene() :
started(false),
moving(false),
clicked(false),
enemiesKilled(0),
hitTimer(1000.0f),
nextCoin(0),
nextEnemy(4),
score(0),
heldCoins(0),
health(3),
scoresDrawn(false),
selectedSprite(0),
hitTaken(false),
firstPlay(true)
{
	//Options* options;
	
	//selectedSprite = options->selectPlayer;
}


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

void GameScene::setPlayerSprite(int player) { 
	selectedSprite = player;
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}
	MoveTo * getPlayerPos();
	Animate * HandleMummyAnimation(int i);
	Animate * HandleBulletAnimation();
	Animate * HandleZombieAnimation(int i);
	Animate * HandleCoinAnimation();

	// pre load the audio
	audio = CocosDenshion::SimpleAudioEngine::getInstance();
	audio->preloadEffect("gs.wav");

	// add to get data loading from json file
	std::shared_ptr<GameData> ptr = GameData::sharedGameData();
	//auto optionScene = Options::create();
	//std::shared_ptr<Options> op = Options::oPtr();
	//Options op;

	timeAtStart = clock();
	timeNow = clock();
	auto mummy =
		Sprite::create();
	auto zombie =
		Sprite::create();
	auto coin =
		Sprite::create();
	playerPos = cocos2d::Vec2(300, 300);
	chestPos = cocos2d::Vec2(400, 350);
	mummyPos[0] = cocos2d::Vec2(392, 105); mummyVel[0] = Vec2(0, 50.0f);
	mummyPos[1] = cocos2d::Vec2(33, 350); mummyVel[1] = Vec2(50.0f, 0);
	mummyPos[2] = cocos2d::Vec2(392, 570); mummyVel[2] = Vec2(0, -50.0f);
	mummyPos[3] = cocos2d::Vec2(765, 350); mummyVel[3] = Vec2(-50.0f, 0);
	mummyDirection[0] = 0;
	mummyDirection[1] = 1;
	mummyDirection[2] = 2;
	mummyDirection[3] = 3;
	zombiePos[0] = cocos2d::Vec2(392, 105);
	zombiePos[1] = cocos2d::Vec2(30, 350);
	zombiePos[2] = cocos2d::Vec2(392, 570);
	zombiePos[3] = cocos2d::Vec2(765, 350);
	circlePadPos = cocos2d::Vec2(40, 40);

	initChestPos();

	spawnTimer = 2000;

	paused = false;
	levelCleared = false;
	currentLevel = 1;
	
	pSprite = Player::create(playerPos);
	//Options* option = new Options();
	

	//mummy->runAction(RepeatForever::create(HandleMummyAnimation(3))); // 0 = Up, 1 = Right, 2 = Down, 3 = Left

	bullet =
		Sprite::create("GameScreen/Bullet.png");
	//auto bg =
		//Sprite::create("GameScreen/Room1bg.png");
	bg = Sprite::create(ptr->m_backgroundTextureFile);
	//auto chest =
		//Sprite::create("GameScreen/Chest.png");
	chest = Sprite::create(ptr->m_chestTextureFile);

	//auto circlePadOutline =
		//Sprite::create("GameScreen/CirclePadOutline.png");
	circlePadOutline = Sprite::create(ptr->m_circlePadOutlineTextureFile);

	circlePad =
		Sprite::create("GameScreen/CirclePad.png");
	pauseItem =
		MenuItemImage::create("GameScreen/PauseButton.png",
		"GameScreen/PauseButton.png",
		CC_CALLBACK_1(GameScene::activatePauseScene, this));
	dieItem =
		MenuItemImage::create("GameScreen/DieButton.png",
		"GameScreen/DieButton.png",
		CC_CALLBACK_1(GameScene::activateGameOverScene, this));
	closeItem = MenuItemImage::create("GameDoneScreen/QuitButton.png",
		"GameDoneScreen/QuitButton.png",
		CC_CALLBACK_1(GameScene::quitGame, this));
	youSurvivedText =
		MenuItemImage::create("GameDoneScreen/YouSurvivedText.png",
		"GameDoneScreen/YouSurvivedText.png");

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	/////////////////////////////
	// 2. add a menu item with "X" image, which is clicked to quit the program
	//    you may modify it.

	// add a "close" icon to exit the progress. it's an autorelease object
	youSurvivedText->setPosition(Vec2(origin.x + visibleSize.width / 2, visibleSize.height - 50 - youSurvivedText->getContentSize().height));
	closeItem->setPosition(Vec2(origin.x + visibleSize.width / 2, visibleSize.height - 330 - closeItem->getContentSize().height));
	pauseItem->setPosition(Point(pauseItem->getContentSize().width / 2, origin.y + visibleSize.height - pauseItem->getContentSize().height / 2));
	dieItem->setPosition(Point(800 - dieItem->getContentSize().width / 2, origin.y + visibleSize.height - dieItem->getContentSize().height / 2));
	chest->setPosition(chestPos);
	circlePadOutline->setPosition(cocos2d::Vec2(40, 40));
	circlePad->setPosition(circlePadPos);
	bg->setPosition(Vec2(visibleSize.width / 2, (visibleSize.height / 2) + 40));
	bg->setScaleX(visibleSize.width / bg->getContentSize().width);
	bg->setScaleY(520 / bg->getContentSize().height);

	auto menu = Menu::create(pauseItem, dieItem, closeItem, NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(bg);
	this->addChild(chest);
	this->addChild(menu);
	this->addChild(circlePadOutline);
	this->addChild(circlePad);
	this->addChild(youSurvivedText);
	youSurvivedText->setVisible(false);

	int p = 0;
	for (int i = 4; i < 50; i++, p++)
	{
		p = rand() % 4;
		mummyDirection[i] = p;

		if (p == 0) { mummyVel[i] = Vec2(0, 50.0f); mummyPos[i] = Vec2(392, 105); zombiePos[i] = Vec2(392, 105); }
		if (p == 1) { mummyVel[i] = Vec2(50.0f, 0); mummyPos[i] = Vec2(33, 350); zombiePos[i] = Vec2(30, 350); }
		if (p == 2) { mummyVel[i] = Vec2(0, -50.0f); mummyPos[i] = Vec2(392, 580); zombiePos[i] = Vec2(392, 580); }
		if (p == 3) { mummyVel[i] = Vec2(-50.0f, 0); mummyPos[i] = Vec2(765, 350); zombiePos[i] = Vec2(765, 350); }
	}
	for (int i = 0; i < 50; i++)
	{
		coinPos[i] = Vec2(-100, -100);
		CCSprite* mummy = cocos2d::CCSprite::create();
		CCSprite* zombie = cocos2d::CCSprite::create();
		CCSprite* coin = cocos2d::CCSprite::create();
		mummy->setPosition(mummyPos[i]);
		zombie->setPosition(zombiePos[i]);
		coin->setPosition(coinPos[i]);

		mummy->runAction(RepeatForever::create(HandleMummyAnimation(mummyDirection[i])));
		zombie->runAction(RepeatForever::create(HandleZombieAnimation(2)));
		coin->runAction(RepeatForever::create(HandleCoinAnimation()));
		mummySprites.push_back(mummy);
		zombieSprites.push_back(zombie);
		coinSprites.push_back(coin);
		mummyAlive[i] = false;
		zombieAlive[i] = false;

		addChild(mummy);
		addChild(zombie);
		addChild(coin);
		coinAlive[i] = false;
		mummyStolen[i] = false;
	}
	mummyAlive[0] = true;
	mummyAlive[1] = true;
	mummyAlive[2] = true;
	mummyAlive[3] = true;

	for (int i = 0; i < 50; i++)
	{
		CCSprite* bullet = cocos2d::CCSprite::create();
		bullet->setPosition(bulletPos[i]);

		bullet->runAction(RepeatForever::create(HandleBulletAnimation()));
		bulletSprites.push_back(bullet);

		addChild(bullet);
		bulletAlive[i] = false;
	}

	scoreLabel = LabelBMFont::create();
	scoreLabel->setString("Score: 0"); scoreLabel->setScale(2);
	scoreLabel->setPosition(Vec2(100, 65));
	scoreLabel->setAnchorPoint(ccp(0.0f, 0.5f));
	scoreLabel->setAlignment(kCCTextAlignmentLeft);

	coinLabel = LabelBMFont::create();
	coinLabel->setString("Coins: 0/5"); coinLabel->setScale(2);
	coinLabel->setPosition(Vec2(100, 25));
	coinLabel->setAnchorPoint(ccp(0.0f, 0.5f));
	coinLabel->setAlignment(kCCTextAlignmentLeft);

	enemiesLeftLabel = LabelBMFont::create();
	enemiesLeftLabel->setString("Enemies Left: 0"); enemiesLeftLabel->setScale(2);
	enemiesLeftLabel->setPosition(Vec2(570, 40));
	enemiesLeftLabel->setAnchorPoint(ccp(0.0f, 0.5f));
	enemiesLeftLabel->setAlignment(kCCTextAlignmentLeft);
	
	healthLabel = LabelBMFont::create();
	healthLabel->setString("Health: 3"); healthLabel->setScale(2);
	healthLabel->setPosition(Vec2(300, 40));
	healthLabel->setAnchorPoint(ccp(0.0f, 0.5f));
	healthLabel->setAlignment(kCCTextAlignmentLeft);

	finalScoreLabel = LabelBMFont::create();
	finalScoreLabel->setString("Level 2 with a final score of: 0"); finalScoreLabel->setScale(2);
	finalScoreLabel->setPosition(Vec2(200, 400));
	finalScoreLabel->setAnchorPoint(ccp(0.0f, 0.5f));
	finalScoreLabel->setAlignment(kCCTextAlignmentLeft);
	this->addChild(finalScoreLabel);
	//this->addChild(retryItem);
	//this->addChild(closeItem);
	finalScoreLabel->setVisible(false);
	dieItem->setVisible(false);
	//retryItem->setVisible(false);
	closeItem->setVisible(false);

	this->addChild(coinLabel);
	this->addChild(enemiesLeftLabel);
	this->addChild(healthLabel);
	this->addChild(scoreLabel);

	createPlayer();
	this->scheduleUpdate();
	return true;
}

void GameScene::activatePauseScene(Ref *pSender)
{
	paused = true;
	auto scene = PauseMenu::createScene();
	Director::getInstance()->pushScene(scene);
}

void GameScene::completeLevelOne()
{
	paused = true;
	currentLevel = 2;
	auto scene = LevelDone::createScene();
	Director::getInstance()->pushScene(scene);
}

void GameScene::completeLevelTwo()
{
	for (int i = 0; i <= 50; i++)
	{
		mummyAlive[i] = false;
		zombieAlive[i] = false;
		coinAlive[i] = false;
		bulletAlive[i] = false;
	}
	finalScoreLabel->setVisible(true);
	chest->setVisible(false);
	scoreLabel->setVisible(false);
	coinLabel->setVisible(false);
	enemiesLeftLabel->setVisible(false);
	healthLabel->setVisible(false);
	pSprite->setVisible(false);
	bg->setVisible(false);
	circlePad->setVisible(false);
	circlePadOutline->setVisible(false);
	pauseItem->setVisible(false);
	//retryItem->setVisible(true);
	closeItem->setVisible(true);
	youSurvivedText->setVisible(true);
	
}

void GameScene::activateGameOverScene(Ref *pSender)
{
	auto scene = GameOver::createScene();
	Director::getInstance()->pushScene(scene);
}

Animate * HandleBulletAnimation(){
	Vector<SpriteFrame*> animFramesBullet;
	animFramesBullet.reserve(1);
	animFramesBullet.pushBack(SpriteFrame::create("GameScreen/Bullet.png", Rect(0, 0, 8, 8)));
	Animation* bulletAnimation = Animation::createWithSpriteFrames(animFramesBullet, 0.1f);
	Animate* bulletAnimate = Animate::create(bulletAnimation);
	return bulletAnimate;
}

Animate * HandleZombieAnimation(int i){
	std::shared_ptr<GameData> ptr2 = GameData::sharedGameData();
	Vector<SpriteFrame*> animFramesZombie;
	animFramesZombie.reserve(4);
	if (i == 0)
	{
		animFramesZombie.pushBack(SpriteFrame::create(ptr2->m_zombieUpOneTextureFile, Rect(0, 0, 32, 32)));
		animFramesZombie.pushBack(SpriteFrame::create(ptr2->m_zombieUpTwoTextureFile, Rect(0, 0, 32, 32)));
		animFramesZombie.pushBack(SpriteFrame::create(ptr2->m_zombieUpThreeTextureFile, Rect(0, 0, 32, 32)));
		animFramesZombie.pushBack(SpriteFrame::create(ptr2->m_zombieUpFourTextureFile, Rect(0, 0, 32, 32)));
	}
	else if (i == 1)
	{
		animFramesZombie.pushBack(SpriteFrame::create(ptr2->m_zombieRightOneTextureFile, Rect(0, 0, 32, 32)));
		animFramesZombie.pushBack(SpriteFrame::create(ptr2->m_zombieRightOneTextureFile, Rect(0, 0, 32, 32)));
		animFramesZombie.pushBack(SpriteFrame::create(ptr2->m_zombieRightOneTextureFile, Rect(0, 0, 32, 32)));
		animFramesZombie.pushBack(SpriteFrame::create(ptr2->m_zombieRightOneTextureFile, Rect(0, 0, 32, 32)));
	}
	else if (i == 2)
	{
		animFramesZombie.pushBack(SpriteFrame::create(ptr2->m_zombieDownOneTextureFile, Rect(0, 0, 32, 32)));
		animFramesZombie.pushBack(SpriteFrame::create(ptr2->m_zombieDownTwoTextureFile, Rect(0, 0, 32, 32)));
		animFramesZombie.pushBack(SpriteFrame::create(ptr2->m_zombieDownThreeTextureFile, Rect(0, 0, 32, 32)));
		animFramesZombie.pushBack(SpriteFrame::create(ptr2->m_zombieDownFourTextureFile, Rect(0, 0, 32, 32)));
	}
	else if (i == 3)
	{
		animFramesZombie.pushBack(SpriteFrame::create(ptr2->m_zombieLeftOneTextureFile, Rect(0, 0, 32, 32)));
		animFramesZombie.pushBack(SpriteFrame::create(ptr2->m_zombieLeftTwoTextureFile, Rect(0, 0, 32, 32)));
		animFramesZombie.pushBack(SpriteFrame::create(ptr2->m_zombieLeftThreeTextureFile, Rect(0, 0, 32, 32)));
		animFramesZombie.pushBack(SpriteFrame::create(ptr2->m_zombieLeftFourTextureFile, Rect(0, 0, 32, 32)));
	}
	Animation* zombieAnimation = Animation::createWithSpriteFrames(animFramesZombie, 0.1f);
	Animate* zombieAnimate = Animate::create(zombieAnimation);
	return zombieAnimate;
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

Animate * HandleCoinAnimation(){
	Vector<SpriteFrame*> animFramesCoin;
	animFramesCoin.reserve(1);
	animFramesCoin.pushBack(SpriteFrame::create("GameScreen/Coin.png", Rect(0, 0, 21, 21)));
	Animation* coinAnimation = Animation::createWithSpriteFrames(animFramesCoin, 0.1f);
	Animate* coinAnimate = Animate::create(coinAnimation);
	return coinAnimate;
}

void GameScene::update(float dt)
{
	addEvents(dt);
	bulletFired = false;
	initChestPos();
	bulletHitDetection();
	playerHitDetection();
	m_player.movePlayer(circlePadPos, dt);
	pSprite->setPosition(m_player.getPlayerPosition());
	playerPos = m_player.getPlayerPosition();
	timeNow = clock();
	collectCoins();
	if (currentLevel == 1)
	{
		for (int i = 0; i < 50; i++) {zombieAlive[i] = false; }
		for (int d = 0; d < 50; d++)
		{
			if (mummyPos[d].y < 100)
				mummyAlive[d] = false;
		}
	}
	if (currentLevel == 2)
	{
		updateZombieVel(dt);
		//for (int g = 0; g < 50; g++) 
		//{ mummyAlive[g] = false; }
	}
	
	if (timeNow - timeAtStart > spawnTimer && nextEnemy < 50)
	{
		if (currentLevel == 1) { mummyAlive[nextEnemy] = true; }
		if (currentLevel == 2) { zombieAlive[nextEnemy] = true; }
		timeNow = timeAtStart;
		nextEnemy++;
		timeAtStart = clock();
		if (nextEnemy == 7)
			spawnTimer = 1750;
		if (nextEnemy == 12)
			spawnTimer = 1500;
		if (nextEnemy == 17)
			spawnTimer = 1000;
		if (nextEnemy == 22)
			spawnTimer = 600;
		if (nextEnemy >= 50)
			nextEnemy = 0;
	}
	if (timeNow - countdown > hitTimer && hitTaken == true)
	{
		hitTaken = false;
	}
	if (health <= 0)
	{
		if (currentLevel == 1)
		{
			auto scene = GameOver::createScene();
			Director::getInstance()->pushScene(scene);
		}
		if (currentLevel == 2)
		{
			completeLevelTwo();
		}
	}

	for (int i = 0; i < 50; i++)
	{
		//mummySprites[i]->runAction(RepeatForever::create(HandleMummyAnimation(mummyDirection[i])));
		if (mummyAlive[i] && currentLevel == 1) { mummyPos[i] += Vec2(mummyVel[i].x * dt, mummyVel[i].y * dt); }
		if (currentLevel != 1) { mummyAlive[i] == false; }
		if (currentLevel != 2) { zombieAlive[i] == false; }
		if (zombieAlive[i] && currentLevel == 2) { zombiePos[i] += zombieVel[i]; mummyPos[i] = Vec2(-100, -100); }
		bulletPos[i] += Vec2(bulletVel[i].x * dt, bulletVel[i].y * dt);
		mummySprites[i]->setPosition(mummyPos[i]);
		zombieSprites[i]->setPosition(zombiePos[i]);
		coinSprites[i]->setPosition(coinPos[i]);
		mummySprites[i]->setVisible(mummyAlive[i]);
		zombieSprites[i]->setVisible(zombieAlive[i]);
		bulletSprites[i]->setVisible(bulletAlive[i]);
		coinSprites[i]->setVisible(coinAlive[i]);
		bulletSprites[i]->setPosition(bulletPos[i]);
		if (bulletPos[i].x > 850 || bulletPos[i].x < -50 ||
			bulletPos[i].y > 650 || bulletPos[i].y < -50)
			bulletAlive[i] = false;
		if (enemiesKilled >= 30 && currentLevel == 1 || mummyAlive[49] == true)
		{
			currentLevel = 2;
			nextEnemy = 0;
			nextCoin = 0;
			enemiesKilled = 0;
			for (int i = 0; i < 50; i++)
			{
				mummyAlive[i] = false;
				coinAlive[i] = false;
				mummyStolen[i] = false;
			}
			completeLevelOne();
			
		}
		if (enemiesKilled >= 30 && currentLevel == 2 || zombieAlive[49] == true)
			completeLevelTwo();
	}
	
	std::stringstream sScore;
	std::stringstream sCoin;
	std::stringstream sEnemy;
	std::stringstream sHealth;

	sScore << score;
	sCoin << heldCoins;
	sEnemy << (30 - enemiesKilled);
	sHealth << health;

	std::string scoreStr = sScore.str();
	std::string coinStr = sCoin.str();
	std::string killStr = sEnemy.str();
	std::string healthStr = sHealth.str();

	scoreLabel->setString("Score: " + scoreStr);
	coinLabel->setString("Coins: " + coinStr + "/5");
	enemiesLeftLabel->setString("Enemies Left: " + killStr);
	healthLabel->setString("Health: " + healthStr);
	finalScoreLabel->setString("Level Two with a final score of: " + scoreStr);
}


void GameScene::addEvents(float dt) {
	auto listener1 = EventListenerTouchAllAtOnce::create();
	listener1->onTouchesBegan = [this](const std::vector<Touch*>& touches, Event* event){
		Vec2 pos = touches[0]->getLocation();
		
		moveCirclePad(pos);
		rotateThePlayer(pos);
		
		FireBullet(pos);
		clicked = true;
	};
	
	GameScene* gs = this;
	listener1->onTouchesMoved = [gs](const std::vector<Touch*>& touches, Event* event){
		auto pos = touches.back();
		gs->moveCirclePad(pos->getLocation());

	};
	listener1->onTouchesEnded = [this](const std::vector<Touch*>& touches, Event* event){
		clicked = false;
		moving = false;
		circlePadPos = Vec2(40, 40);
		circlePad->setPosition(circlePadPos);
	};
	listener1->onTouchesCancelled = [this](const std::vector<Touch*>& touches, Event* event){
		clicked = false;
		moving = false;
		circlePadPos = Vec2(40, 40);
		circlePad->setPosition(circlePadPos);
	};
	cocos2d::Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(listener1, 30);
}

void GameScene::collectCoins() {
	Vec2 myPos = m_player.getPlayerPosition();
	for (int c = 0; c < 50; c++)
	{
		if (myPos.x < coinPos[c].x + 21 &&
			myPos.x + 30 > coinPos[c].x &&
			myPos.y < coinPos[c].y + 21 &&
			myPos.y + 30 > coinPos[c].y &&
			coinAlive[c] == true && heldCoins < 5) 
		{
			heldCoins++;
			coinAlive[c] = false;
		}
		if (mummyPos[c].x < chestPos.x + 21 &&
			mummyPos[c].x + 35 > chestPos.x &&
			mummyPos[c].y < chestPos.y + 21 &&
			mummyPos[c].y + 35 > chestPos.y &&
			mummyAlive[c] == true && mummyStolen[c] == false)
		{
			mummyStolen[c] = true;
			score -= 15;
		}
	}
	if (myPos.x < chestPos.x + 20 &&
		myPos.x + 30 > chestPos.x &&
		myPos.y < chestPos.y + 20 &&
		myPos.y + 30 > chestPos.y) 
	{
		score += 10 * heldCoins;
		heldCoins = 0;
	}
}

void GameScene::moveCirclePad(Vec2 pos) {
	if (moving == true ||
		pos.x > circlePadPos.x && pos.x < circlePadPos.x + 20 &&
		pos.y < circlePadPos.y && pos.y > circlePadPos.y - 20 &&
		clicked == true)
	{
		if (sqrt(((circlePadPos.x - 40) * (circlePadPos.x - 40)) +
			((circlePadPos.y - 40) * (circlePadPos.y - 40))) <= 36)
		{
			circlePadPos = pos;
			moving = true;
		}
		if (sqrt(((circlePadPos.x - 40) * (circlePadPos.x - 40)) +
			((circlePadPos.y - 40) * (circlePadPos.y - 40))) > 36)
		{
			float dotProduct = (((40 + 10 - 40) * (pos.x - 40)) +
				((40 - 40) * (pos.y - 40)));
			float A = sqrt(((pos.x - 40) * (pos.x - 40))
				+ ((pos.y - 40)* (pos.y - 40)));
			float angleInDegree = acos(dotProduct / (10 * A));
			if (pos.y < 40)
				angleInDegree *= -1;
			circlePadPos.x = 40 + (cos(angleInDegree) * 36);
			circlePadPos.y = 40 + (sin(angleInDegree) * 36);
		}
		circlePad->setPosition(circlePadPos);
	}

}

void GameScene::rotateThePlayer(Vec2 pos) {
	m_player.rotatePlayer(pos);
	if (pos.y > 82)
	{
		pSprite->setRotation(m_player.getAngleToFace()*-1 + 90);
	}
}

bool GameScene::FireBullet(Vec2 pos) {
	for (int i = 0; i < 50; i++)
	{
		if (bulletAlive[i] == false && bulletFired == false && pos.y > 80)
		{
			float distance = sqrt((pos.x - playerPos.x) * (pos.x - playerPos.x) +
				(pos.y - playerPos.y) * (pos.y - playerPos.y));
			float bulletVelx = 0.1*((pos.x - playerPos.x) / distance);
			float bulletVely = 0.1*((pos.y - playerPos.y) / distance);
			bulletPos[i] = playerPos + Vec2(bulletVelx * 240, bulletVely * 240);
			bulletVel[i] = Vec2(bulletVelx * 5000, bulletVely * 5000);
			bulletAlive[i] = true;
			bulletFired = true;
			audio->playEffect("gs.wav");  // play gunshot sound
			return true;
		}
	}
	return false;
}

void GameScene::bulletHitDetection() {
	for (int m = 0; m < 50; m++) // Bullet-on-Mummy hit detection
	{
		for (int b = 0; b < 50; b++)
		{
			if (bulletPos[b].x < mummyPos[m].x + 35 &&
				bulletPos[b].x + 8 > mummyPos[m].x &&
				bulletPos[b].y < mummyPos[m].y + 35 &&
				bulletPos[b].y + 8 > mummyPos[m].y &&
				bulletAlive[b] && mummyAlive[m])
			{
				mummyAlive[m] = false;
				bulletAlive[b] = false;
				enemiesKilled++;
				coinAlive[nextCoin] = true;
				coinPos[nextCoin] = mummyPos[m];
				mummyPos[m] = Vec2(-100, -100);
				nextCoin++;
			}
		}
	}

	for (int z = 0; z < 50; z++) // Bullet-on-Zombie hit detection
	{
		for (int b = 0; b < 50; b++)
		{
			if (bulletPos[b].x < zombiePos[z].x + 32 &&
				bulletPos[b].x + 8 > zombiePos[z].x &&
				bulletPos[b].y < zombiePos[z].y + 32 &&
				bulletPos[b].y + 8 > zombiePos[z].y &&
				bulletAlive[b] == true && zombieAlive[z])
			{
				zombieAlive[z] = false;
				bulletAlive[b] = false;
				enemiesKilled++;
				coinAlive[nextCoin] = true;
				coinPos[nextCoin] = zombiePos[z];
				zombiePos[z] = Vec2(-100, -100);
				nextCoin++;
			}
		}
	}
}

void GameScene::playerHitDetection() {
	if (currentLevel == 1)
	{
		for (int m = 0; m < 50; m++)
		{
			if (playerPos.x < mummyPos[m].x + 35 &&
				playerPos.x + 30 > mummyPos[m].x &&
				playerPos.y < mummyPos[m].y + 35 &&
				playerPos.y + 30 > mummyPos[m].y &&
				mummyAlive[m] && hitTaken == false)
			{
				health--;
				hitTaken = true;
				countdown = clock();
			}
		}
	}
	if (currentLevel == 2)
	{
		for (int z = 0; z < 50; z++)
		{
			if (playerPos.x < zombiePos[z].x + 32 &&
				playerPos.x + 30 > zombiePos[z].x &&
				playerPos.y < zombiePos[z].y + 32 &&
				playerPos.y + 30 > zombiePos[z].y &&
				zombieAlive[z] && hitTaken == false)
			{
				health--;
				hitTaken = true;
				countdown = clock();
			}
		}
	}
}

void GameScene::updateZombieVel(float dt) {
	for (int z = 0; z < 50; z++)
	{
		float distance = sqrt((zombiePos[z].x - playerPos.x) * (zombiePos[z].x - playerPos.x) +
			(zombiePos[z].y - playerPos.y) * (zombiePos[z].y - playerPos.y));
		zombieVel[z].x = -0.2*((zombiePos[z].x - playerPos.x) / distance) * dt;
		zombieVel[z].y = -0.2*((zombiePos[z].y - playerPos.y) / distance) * dt;
		zombieVel[z] = Vec2(zombieVel[z].x * 15, zombieVel[z].y * 15);
		if (zombieVel[z].x > 0)
			zombieDirection[z] = 2;
		if (zombieVel[z].x < 0)
			zombieDirection[z] = 1;
	}
}

void GameScene::createPlayer() {
	pSprite->setPosition(300, 300);
	std::shared_ptr<GameData> ptr = GameData::sharedGameData();
	if (ptr->m_selectedPlayer == 0)
	{
		pSprite->runAction(RepeatForever::create(m_player.createPlayerSprite(0)));
	}
	if (ptr->m_selectedPlayer == 1)
	{
		pSprite->runAction(RepeatForever::create(m_player.createPlayerSprite(1)));
	}
	this->addChild(pSprite, 1);
}

void GameScene::initChestPos() {

	if (started == false)
	{
		chestPos = cocos2d::Vec2(395, 360);
		started = true;
	}
}

void GameScene::quitGame(Ref *pSender) {
	if (closeItem->isVisible() == true)
	{
		auto scene = ConfirmQuit::createScene();
		Director::getInstance()->pushScene(scene);
	}
}
