#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "GameOverScene.h"
#include "PauseMenu.h"
#include "OptionsScene.h"
#include "Player.h"
#include "LevelDoneScene.h"
#include <math.h>
#include <time.h>
#include <sstream>
#include <string>
#include <iostream>
#include "MainMenuScene.h"
#include "SimpleAudioEngine.h"

class Options;

class GameScene : public cocos2d::Layer
{
public:
	GameScene();
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::Scene* createScene();
	void setPlayerSprite(int i);
	int selectedSprite;

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();

	// a selector callback
	void menuCloseCallback(cocos2d::Ref* pSender);

	void activatePauseScene(Ref *pSender);

	void activateGameOverScene(Ref *pSender);

	void update(float dt);
	void addEvents(float dt);
	void moveCirclePad(cocos2d::Vec2);
	void initChestPos();
	void createPlayer();
	void rotateThePlayer(cocos2d::Vec2 pos);
	void bulletHitDetection();
	void playerHitDetection();
	void collectCoins();
	void updateZombieVel(float dt);
	void completeLevelOne();
	void completeLevelTwo();
	void quitGame(Ref *pSender);
	bool started;
	int enemiesKilled;
	clock_t timeNow;
	clock_t timeAtStart;
	clock_t countdown;
	float spawnTimer;
	float hitTimer;
	bool hitTaken;
	int health;
	int score;
	int heldCoins;
	bool scoresDrawn;
	cocos2d::LabelBMFont* scoreLabel;
	cocos2d::LabelBMFont* coinLabel;
	cocos2d::LabelBMFont* enemiesLeftLabel;
	cocos2d::LabelBMFont* healthLabel;
	cocos2d::LabelBMFont* finalScoreLabel;


	std::vector<cocos2d::CCSprite*> bulletSprites;
	std::vector<cocos2d::CCSprite*> mummySprites;
	std::vector<cocos2d::CCSprite*> zombieSprites;
	std::vector<cocos2d::CCSprite*> coinSprites;
	cocos2d::CCSprite* bg;
	cocos2d::CCSprite* chest;
	cocos2d::CCSprite* circlePadOutline;
	cocos2d::MenuItemImage* pauseItem;
	cocos2d::MenuItemImage* dieItem;
	cocos2d::MenuItemImage* youSurvivedText;
	cocos2d::MenuItemImage* closeItem;
	cocos2d::MenuItemImage* retryItem;

	cocos2d::Vec2 playerPos, chestPos, circlePadPos;
	bool FireBullet(cocos2d::Vec2 pos);
	bool moving, clicked, bulletFired;
	bool firstPlay;

	cocos2d::Rect playerRect;

	cocos2d::Vec2 mummyPos[50];
	cocos2d::Vec2 mummyVel[50];
	cocos2d::Vec2 mummyVelocity[50];
	bool mummyAlive[50];
	bool mummyStolen[50];
	int mummyDirection[50];
	int nextEnemy;

	cocos2d::Vec2 zombiePos[50], zombieVel[50];
	bool zombieAlive[50];
	int zombieDirection[50];

	cocos2d::Vec2 coinPos[50];
	bool coinAlive[50];
	int nextCoin;

	cocos2d::Vec2 bulletPos[50];
	cocos2d::Vec2 bulletVel[50];
	bool bulletAlive[50];

	int currentFrame;
	Player m_player;
	Player* player;
	cocos2d::Sprite * pSprite;
	cocos2d::Sprite * circlePad;
	cocos2d::Sprite * bullet;

	bool paused, levelCleared;
	int currentLevel;

	CocosDenshion::SimpleAudioEngine *audio;


	// implement the "static create()" method manually
	CREATE_FUNC(GameScene);
};

#endif // __HELLOWORLD_SCENE_H__

