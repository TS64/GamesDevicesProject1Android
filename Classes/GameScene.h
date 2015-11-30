#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "GameOverScene.h"
#include "PauseMenu.h"
#include "Player.h"
#include <math.h>

class GameScene : public cocos2d::Layer
{
public:
	GameScene();
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

	void activatePauseScene(Ref *pSender);

	void activateGameOverScene(Ref *pSender);

	void update(float dt);
	void addEvents();
	void moveCirclePad(cocos2d::Vec2);
	void initChestPos();
	void createPlayer();
	void GameScene::rotateThePlayer(cocos2d::Vec2 pos);
	bool started;

	std::vector<cocos2d::CCSprite*> bulletSprites;

	cocos2d::Vec2 playerPos, mummyPos, chestPos, circlePadPos;
	void movePlayer();
	bool FireBullet(cocos2d::Vec2 pos);
	bool moving, clicked, bulletFired;

	cocos2d::Rect playerRect;

	cocos2d::Vec2 enemyPos[4];
	cocos2d::Vec2 bulletPos[50];
	cocos2d::Vec2 bulletVel[50];
	bool bulletAlive[50];

	int currentFrame;
	Player m_player;
	Player* player;
	cocos2d::Sprite * pSprite;
	cocos2d::Sprite * circlePad;
	cocos2d::Sprite * bullet;
    
    // implement the "static create()" method manually
    CREATE_FUNC(GameScene);
};

#endif // __HELLOWORLD_SCENE_H__
