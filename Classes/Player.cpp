#include "Player.h"

USING_NS_CC;

Player::Player() :
moving(false),
playerPosition(Vec2(300, 300))
{
	createPlayerSprite();
}

Sprite * Player::create(Vec2 position)
{
	//auto spritecache = SpriteFrameCache::getInstance();
	//spritecache->addSpriteFramesWithFile("GameScreen/PlayerSprite1.png");
	//Player* pSprite = new Player();
	auto playerSprite = Sprite::create("GameScreen/PlayerSprite1.png");
	return playerSprite;

	//CC_SAFE_DELETE(pSprite);
	//return NULL;
}

void Player::initOptions(Vec2 position)
{
	Point origin = Director::getInstance()->getVisibleOrigin();
	this->setPosition(position.x + origin.x, position.y + origin.y + this->getContentSize().height / 4);
	playerPosition = Vec2(300, 300);
}

void Player::movePlayer(Vec2 pos) {
	createPlayerSprite();
	float dotProduct = (((300 + 10 - 300) * (pos.x - 300)) +
		((300 - 300) * (pos.y - 300)));
	float A = sqrt(((pos.x - 300) * (pos.x - 300))
		+ ((pos.y - 300)* (pos.y - 300)));
	float angleInDegree = acos(dotProduct / (10 * A));
	if (pos.y < 300)
		angleInDegree *= -1;
	if (pos.x != 300 || pos.y != 300)
	{
		playerPosition.x += cos(angleInDegree)*sqrt(((pos.x - 300) * (pos.x - 300)) +
			((pos.y - 300) * (pos.y - 300))) * 0.2;
		playerPosition.y += sin(angleInDegree)*sqrt(((pos.x - 300) * (pos.x - 300)) +
			((pos.y - 300) * (pos.y - 300))) * 0.2;
	}
}

void Player::rotatePlayer(Vec2 pos)
{
	angleToFace = atan2(pos.y - playerPosition.y, pos.x - playerPosition.x);
	angleToFace *= (180 / M_PI);
}

Animate* Player::createPlayerSprite()
{
	Vector<SpriteFrame*> animFramesPlayer;
	animFramesPlayer.reserve(4);
	animFramesPlayer.pushBack(SpriteFrame::create("GameScreen/PlayerSprite1.png", Rect(0, 0, 22, 44)));
	animFramesPlayer.pushBack(SpriteFrame::create("GameScreen/PlayerSprite2.png", Rect(0, 0, 22, 44)));
	animFramesPlayer.pushBack(SpriteFrame::create("GameScreen/PlayerSprite3.png", Rect(0, 0, 22, 44)));
	animFramesPlayer.pushBack(SpriteFrame::create("GameScreen/PlayerSprite2.png", Rect(0, 0, 22, 44)));
	Animation* playerAnimation = Animation::createWithSpriteFrames(animFramesPlayer, 0.1f);
	playerAnimate = Animate::create(playerAnimation);
	return playerAnimate;
}

Vec2 Player::getPlayerPosition() {
	return playerPosition;
}

float Player::getAngleToFace() {
	return angleToFace;
}