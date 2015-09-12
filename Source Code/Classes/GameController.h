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
	void onUpdate();	//������ӿ�
	bool isHit(Point p);//�Ƿ���
	void jump();		//С����

private:	
	Size size;			//���ڴ�С
	Edge *edge;			//��Ϸ��������Ե
	Hero *hero;			//С��
	Layer *layer;		//��Ϸ��
	float positionY;	//
	int curFrame;		//��ǰ֡
	int nextFrame;		//��һ֡

	void addBlock();	//��
	void resetFrame();	//����֡
};

#endif
