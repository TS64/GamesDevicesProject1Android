#include "QuitMenu.h"

USING_NS_CC;

Scene* QuitMenu::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();
	auto layer = QuitMenu::create();

	scene->addChild(layer);

	return scene;
}

bool QuitMenu::init()
{
	if (!Layer::init())
	{
		//auto label = Label::createWithSystemFont("Hello World", "Arial", 96);
		//label->setAnchorPoint(cocos2d::Vec2(0.0, 0.0));
		//this->addChild(label, 1);
		return false;
	}
	auto bg =
		Sprite::create("MainMenuScreen/BackgroundTemp.jpeg");
	auto areYouSureItem =
		MenuItemImage::create("QuitScreen/AreYouSureText.png",
		"QuitScreen/AreYouSureText.png");
	auto yesItem =
		MenuItemImage::create("QuitScreen/YesButton.png",
		"QuitScreen/YesButton.png",
		CC_CALLBACK_1(QuitMenu::menuCloseCallback, this));
	auto noItem =
		MenuItemImage::create("QuitScreen/NoButton.png",
		"QuitScreen/NoButton.png",
		CC_CALLBACK_1(QuitMenu::resume, this));
	Size visibleSize = Director::getInstance()->getVisibleSize();
	bg->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	bg->setScaleX(visibleSize.width / bg->getContentSize().width);
	bg->setScaleY(visibleSize.height / bg->getContentSize().height);
	auto menu = Menu::create(areYouSureItem, yesItem, noItem, NULL);
	menu->alignItemsVerticallyWithPadding(visibleSize.height / 4);
	this->addChild(bg);
	this->addChild(menu);

	return true;
}

void QuitMenu::resume(Ref *pSender)
{
	auto scene = PauseMenu::createScene();
	Director::getInstance()->pushScene(scene);
}

void QuitMenu::menuCloseCallback(Ref* pSender)
{
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}

