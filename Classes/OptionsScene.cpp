#include "OptionsScene.h"

USING_NS_CC;

Options::Options()
//selectPlayer(0)
{
	
}
Scene* Options::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
	auto layer = Options::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Options::init()
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


	auto bg =
		Sprite::create("OptionsScreen/BackgroundPlayingTemp.jpg");
    auto backItem = 
		MenuItemImage::create("OptionsScreen/BackButton.png", 
		"OptionsScreen/BackButton.png", 
		CC_CALLBACK_1(Options::activateMainMenuScene, this));
	auto choosePlayerText =
		MenuItemImage::create("OptionsScreen/ChoosePlayerText.png",
		"OptionsScreen/ChoosePlayerText.png",
		CC_CALLBACK_1(Options::activateMainMenuScene, this));
	selectionBox =
		MenuItemImage::create("OptionsScreen/SelectedBox.png",
		"OptionsScreen/SelectedBox.png");
	playerOneItem =
		MenuItemImage::create("OptionsScreen/PlayerSprite1.png",
		"OptionsScreen/PlayerSprite1.png",
		CC_CALLBACK_1(Options::selectedPlayerOne, this));
	playerTwoItem =
		MenuItemImage::create("OptionsScreen/Player2Sprite1.png",
		"OptionsScreen/Player2Sprite1.png",
		CC_CALLBACK_1(Options::selectedPlayerTwo, this));
	auto playItem =
		MenuItemImage::create("OptionsScreen/PlayButton.png",
		"OptionsScreen/PlayButton.png",
		CC_CALLBACK_1(Options::activateGameScene, this));
	auto objectiveBack =
		MenuItemImage::create("OptionsScreen/ObjectiveBackdrop.png",
		"OptionsScreen/ObjectiveBackdrop.png");
    
	backItem->setPosition(Vec2(origin.x + visibleSize.width - backItem->getContentSize().width/2 ,
		origin.y + backItem->getContentSize().height/2));
	choosePlayerText->setPosition(Vec2(origin.x + visibleSize.width / 2, visibleSize.height - 10 - playItem->getContentSize().height));
	playItem->setPosition(Vec2(origin.x + visibleSize.width/2, visibleSize.height - 270 - playItem->getContentSize().height));
	playerOneItem->setPosition(Vec2(origin.x + visibleSize.width / 2 - 100, visibleSize.height - 130 - playItem->getContentSize().height));
	playerTwoItem->setPosition(Vec2(origin.x + visibleSize.width / 2 + 100, visibleSize.height - 130 - playItem->getContentSize().height));
	selectionBox->setPosition(Vec2(origin.x + visibleSize.width / 2 - 100, visibleSize.height - 130 - playItem->getContentSize().height));
	objectiveBack->setPosition(400, 130);
	objectiveBack->setScaleX(2.35f); objectiveBack->setScaleY(1.1f);
	//playItem->setPosition(Vec2(origin.x + 200, origin.y + 200));
    // create menu, it's an autorelease object
	playerOneItem->setScale(3); playerTwoItem->setScale(3); selectionBox->setScale(3);
	bg->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	bg->setScaleX(visibleSize.width / bg->getContentSize().width);
	bg->setScaleY(visibleSize.height / bg->getContentSize().height);
    auto menu = Menu::create(choosePlayerText, playItem, playerOneItem, playerTwoItem, backItem, NULL);
    menu->setPosition(Vec2::ZERO);
	this->addChild(bg);
    this->addChild(menu, 1);
	this->addChild(selectionBox);
	this->addChild(objectiveBack);

	objectiveLabel = LabelBMFont::create();
	objectiveLabel->setString("Objective: \nKill mummies, pick up the coins, and drop them in the chest.\nDon't let the mummies reach the chest, or you'll lose points.");
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

void Options::activateGameScene(Ref *pSender)
{
	auto scene = GameScene::createScene();
	//GameScene gs;
	
	//GameScene::setPlayerSprite(selectedPlayer);
	Director::getInstance()->replaceScene(scene);
	//gs.setPlayerSprite(selectedPlayer);
}

void Options::activateMainMenuScene(Ref *pSender)
{
	auto scene = MainMenu::createScene();
	Director::getInstance()->replaceScene(scene);
}

void Options::selectedPlayerOne(Ref *pSender) {
	selectionBox->setPosition(playerOneItem->getPosition()); 
	std::shared_ptr<GameData> ptr = GameData::sharedGameData();
	ptr->m_selectedPlayer = 0;
}

void Options::selectedPlayerTwo(Ref *pSender) {
	selectionBox->setPosition(playerTwoItem->getPosition()); 
	std::shared_ptr<GameData> ptr = GameData::sharedGameData();
	ptr->m_selectedPlayer = 1;
}


