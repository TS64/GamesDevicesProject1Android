#ifndef __OPTIONS_SCENE_H__
#define __OPTIONS_SCENE_H__

#include "cocos2d.h"
#include "GameScene.h"
#include "MainMenuScene.h"
#include "GameData.h"
#include <memory>

class Options : public cocos2d::Layer
{
public:
	Options();
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

	static std::shared_ptr<Options> oPtr();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback

	void activateGameScene(Ref *pSender);

	void activateMainMenuScene(Ref *pSender);

	void selectedPlayerOne(Ref *pSender);

	void selectedPlayerTwo(Ref *pSender);

	int returnSelectedPlayer();

	cocos2d::MenuItemImage* selectionBox;
	cocos2d::MenuItemImage* playerOneItem;
	cocos2d::MenuItemImage* playerTwoItem;

	cocos2d::LabelBMFont* objectiveLabel;

    
    // implement the "static create()" method manually
	CREATE_FUNC(Options);
};

#endif // __GAMEOVER_SCENE_H__
