#include "Hero.h"
#include "FlashTool.h"

bool Hero::init()
{
	if (!Sprite::init())
		return false;

	//С�˴�С
	Size size = Size(44, 52);

	//�ܲ�����
	this->runAction(RepeatForever::create(FlashTool::readJsonSpriteSheet("Hero.json", 0.2f)));

	//���ø���
	this->setPhysicsBody(PhysicsBody::createBox(size));
	this->setContentSize(size);
	this->getPhysicsBody()->setRotationEnable(false);
	this->getPhysicsBody()->setContactTestBitmask(1);

	return true;
}