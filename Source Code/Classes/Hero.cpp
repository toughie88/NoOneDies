#include "Hero.h"
#include "FlashTool.h"

bool Hero::init()
{
	if (!Sprite::init())
		return false;

	//小人大小
	Size size = Size(44, 52);

	//跑步动画
	this->runAction(RepeatForever::create(FlashTool::readJsonSpriteSheet("Hero.json", 0.2f)));

	//设置刚体
	this->setPhysicsBody(PhysicsBody::createBox(size));
	this->setContentSize(size);
	this->getPhysicsBody()->setRotationEnable(false);
	this->getPhysicsBody()->setContactTestBitmask(1);

	return true;
}