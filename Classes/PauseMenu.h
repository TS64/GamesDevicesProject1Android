#pragma once

#include "cocos2d.h"
#include "GameScene.h"
#include "MainMenuScene.h"
<<<<<<< HEAD
#include "QuitMenu.h"
=======
>>>>>>> 4266d7d8e9b9d3fe75ec8c663c8bf0c002e0c062

class PauseMenu : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	void resume(Ref *pSender);
<<<<<<< HEAD
	void quit(Ref *pSender);
=======
>>>>>>> 4266d7d8e9b9d3fe75ec8c663c8bf0c002e0c062
	void activateMainMenuScene(Ref *pSender);
	void retry(Ref *pSender);

	CREATE_FUNC(PauseMenu);
};
