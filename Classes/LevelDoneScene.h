#ifndef __LEVELDONE_SCENE_H__
#define __LEVELDONE_SCENE_H__

#include "cocos2d.h"
#include "GameScene.h"
#include "ConfirmQuitScene.h"
#include "MainMenuScene.h"

class LevelDone : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback

	void goToNextStage(Ref *pSender);

	cocos2d::LabelBMFont* objectiveLabel;
    
    // implement the "static create()" method manually
	CREATE_FUNC(LevelDone);
};

#endif // __LEVELDONE_SCENE_H__
