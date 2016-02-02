#pragma once 
#include <utility>
#include "cocos2d.h"

class Player : public cocos2d::Sprite
{
private:

public:
	bool moving;
	Player();
	static cocos2d::Sprite * create(cocos2d::Vec2 position);
	//static cocos2d::Sprite * playerSprite;
	void initOptions(cocos2d::Vec2 position);
	void movePlayer(cocos2d::Vec2 position, float dt);
	void rotatePlayer(cocos2d::Vec2 position);
	cocos2d::Animate* playerAnimate;
	cocos2d::Vec2 getPlayerPosition();
	float getAngleToFace();
	float angleToFace;

	cocos2d::Animate* createPlayerSprite(int i);
	void updatePlayer(cocos2d::Vec2 position);
	cocos2d::Vec2 playerPosition;
};