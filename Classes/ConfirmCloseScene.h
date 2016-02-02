#ifndef __CONFIRMCLOSE_SCENE_H__
#define __CONFIRMCLOSE_SCENE_H__

#include "cocos2d.h"
#include "MainMenuScene.h"

class ConfirmClose : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback

	void resume(Ref* pSender);

	void quit(Ref* pSender);
    
    // implement the "static create()" method manually
	CREATE_FUNC(ConfirmClose);
};

#endif // __CONFIRMCLOSE_SCENE_H__
