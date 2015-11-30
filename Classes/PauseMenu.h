#pragma once

#include "cocos2d.h"
#include "GameScene.h"
#include "MainMenuScene.h"
<<<<<<< HEAD
=======
<<<<<<< HEAD
#include "QuitMenu.h"
=======
>>>>>>> 4266d7d8e9b9d3fe75ec8c663c8bf0c002e0c062
>>>>>>> 74f70ad2e7e511ee9da6b306c9310e5294db5989

class PauseMenu : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	void resume(Ref *pSender);
<<<<<<< HEAD
=======
<<<<<<< HEAD
	void quit(Ref *pSender);
=======
>>>>>>> 4266d7d8e9b9d3fe75ec8c663c8bf0c002e0c062
>>>>>>> 74f70ad2e7e511ee9da6b306c9310e5294db5989
	void activateMainMenuScene(Ref *pSender);
	void retry(Ref *pSender);

	CREATE_FUNC(PauseMenu);
};
