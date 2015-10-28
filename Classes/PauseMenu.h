#pragma once

#include "cocos2d.h"
#include "GameScene.h"
#include "MainMenuScene.h"
#include "QuitMenu.h"

class PauseMenu : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	void resume(Ref *pSender);
	void quit(Ref *pSender);
	void activateMainMenuScene(Ref *pSender);
	void retry(Ref *pSender);

	CREATE_FUNC(PauseMenu);
};
