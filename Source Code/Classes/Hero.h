#ifndef _HERO_H_
#define _HERO_H_

#include "cocos2d.h"

USING_NS_CC;

class Hero : public Sprite
{
public:
	virtual bool init();

	CREATE_FUNC(Hero);
};

#endif
