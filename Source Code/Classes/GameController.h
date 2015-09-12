#ifndef _GAME_CONTROLLER_H_
#define _GAME_CONTROLLER_H_

#include "cocos2d.h"
#include "Edge.h"
#include "Hero.h"

USING_NS_CC;

class GameController : public Ref
{
public:
	static GameController* create(Layer* layer, float positionY);
	virtual bool init(Layer* layer, float positionY);
	void onUpdate();	//更新添加块
	bool isHit(Point p);//是否触摸
	void jump();		//小人跳

private:	
	Size size;			//窗口大小
	Edge *edge;			//游戏控制器边缘
	Hero *hero;			//小人
	Layer *layer;		//游戏层
	float positionY;	//
	int curFrame;		//当前帧
	int nextFrame;		//下一帧

	void addBlock();	//块
	void resetFrame();	//重设帧
};

#endif
