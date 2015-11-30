#ifndef __GAMEOVER_SCENE_H__
#define __GAMEOVER_SCENE_H__

#include "cocos2d.h"
#include "GameScene.h"
#include "MainMenuScene.h"

class GameOver : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback
<<<<<<< HEAD
    void menuCloseCallback(cocos2d::Ref* pSender);
=======
<<<<<<< HEAD
=======
    void menuCloseCallback(cocos2d::Ref* pSender);
>>>>>>> 4266d7d8e9b9d3fe75ec8c663c8bf0c002e0c062
>>>>>>> 74f70ad2e7e511ee9da6b306c9310e5294db5989

	void activateGameScene(Ref *pSender);

	void activateMainMenuScene(Ref *pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(GameOver);
};

#endif // __GAMEOVER_SCENE_H__