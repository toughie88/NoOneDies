#ifndef  _GAME_SCENE_H_
#define  _GAME_SCENE_H_

#include "cocos2d.h"
#include "GameController.h"

USING_NS_CC;

class GameScene : public LayerColor
{
public:
    static Scene* createScene(int type);
    virtual bool init();
    CREATE_FUNC(GameScene);
	virtual void update(float t);

private:
	Vector<GameController*> gcs;	//游戏控制器向量
};

#endif
