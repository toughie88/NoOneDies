#ifndef _BLOCK_H_
#define _BLOCK_H_

#include "cocos2d.h"

USING_NS_CC;

class Block : public Sprite
{
public:
	virtual bool init();
	CREATE_FUNC(Block);

	//����λ��
	virtual void update(float t);
};

#endif
