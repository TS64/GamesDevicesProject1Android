#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "GameOverScene.h"
#include "PauseMenu.h"

class GameScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

	void activatePauseScene(Ref *pSender);

	void activateGameOverScene(Ref *pSender);

	//cocos2d::Animate HandleAnimations();

	void Update();

	cocos2d::Vec2 playerPos, mummyPos, chestPos;

	cocos2d::Rect playerRect;

	cocos2d::Vec2 enemyPos[4];

	int currentFrame;
    
    // implement the "static create()" method manually
    CREATE_FUNC(GameScene);
};

#endif // __HELLOWORLD_SCENE_H__
