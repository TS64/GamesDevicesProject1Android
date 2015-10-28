#include "PauseMenu.h"

USING_NS_CC;

Scene* PauseMenu::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();
	auto layer = PauseMenu::create();

	scene->addChild(layer);

	return scene;
}

bool PauseMenu::init()
{
	if (!Layer::init())
	{
		//auto label = Label::createWithSystemFont("Hello World", "Arial", 96);
		//label->setAnchorPoint(cocos2d::Vec2(0.0, 0.0));
		//this->addChild(label, 1);
		return false;
	}

	auto resumeItem =
		MenuItemImage::create("PauseScreen/ResumeGameButton.png",
		"PauseScreen/ResumeGameButton.png",
		CC_CALLBACK_1(PauseMenu::resume, this));
<<<<<<< HEAD
	auto quitItem =
		MenuItemImage::create("PauseScreen/QuitButton.png",
		"PauseScreen/QuitButton.png",
		CC_CALLBACK_1(PauseMenu::quit, this));
	auto bg =
		Sprite::create("PauseScreen/BackgroundPlayingTemp.jpg");
	auto menu = Menu::create(resumeItem, quitItem, NULL);
=======
	auto bg =
		Sprite::create("PauseScreen/BackgroundPlayingTemp.jpg");
	auto menu = Menu::create(resumeItem, NULL);
>>>>>>> 4266d7d8e9b9d3fe75ec8c663c8bf0c002e0c062
	Size visibleSize = Director::getInstance()->getVisibleSize();
	bg->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	bg->setScaleX(visibleSize.width / bg->getContentSize().width);
	bg->setScaleY(visibleSize.height / bg->getContentSize().height);
	menu->alignItemsVerticallyWithPadding(visibleSize.height / 4);
	this->addChild(bg);
	this->addChild(menu);

	return true;
}

void PauseMenu::resume(Ref *pSender)
{
<<<<<<< HEAD
	//Director::getInstance()->popScene();
	auto scene = GameScene::createScene();
	Director::getInstance()->pushScene(scene);
=======
	Director::getInstance()->popScene();
>>>>>>> 4266d7d8e9b9d3fe75ec8c663c8bf0c002e0c062
}

void PauseMenu::activateMainMenuScene(Ref *pSender)
{
	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
	auto scene = MainMenu::createScene();
	Director::getInstance()->popScene();
	Director::getInstance()->replaceScene(scene);
}

<<<<<<< HEAD
void PauseMenu::quit(Ref* pSender)
{
	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
	auto scene = QuitMenu::createScene();
	Director::getInstance()->popScene();
	Director::getInstance()->replaceScene(scene);
}

=======
>>>>>>> 4266d7d8e9b9d3fe75ec8c663c8bf0c002e0c062
void PauseMenu::retry(Ref *pSender)
{
	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
	auto scene = GameScene::createScene();
	Director::getInstance()->popScene();
	Director::getInstance()->replaceScene(scene);
}

