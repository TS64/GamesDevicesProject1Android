#pragma once

#include "cocos2d.h"
#include "PauseMenu.h"

class QuitMenu : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	void resume(Ref *pSender);
	void activateMainMenuScene(Ref *pSender);
	void retry(Ref *pSender);
	void menuCloseCallback(Ref* pSender);

	CREATE_FUNC(QuitMenu);
};
