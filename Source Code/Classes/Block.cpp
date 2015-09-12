#include "Block.h"

bool Block::init()
{
	if (!Sprite::init())
		return false;

	//���С�����ڴ�С
	Size blocksize = Size(rand() % 20 + 5, rand() % 30 + 10);
	Size size = Director::getInstance()->getWinSize();

	//���ÿ����
	this->setPhysicsBody(PhysicsBody::createBox(blocksize));
	this->setTextureRect(Rect(0, 0, blocksize.width, blocksize.height));
	this->setContentSize(blocksize);
	this->setColor(Color3B(0, 0, 0));
	this->getPhysicsBody()->setDynamic(false);
	this->setPositionX(size.width);
	this->getPhysicsBody()->setContactTestBitmask(1);

	//��������
	this->scheduleUpdate();

	return true;
}

void Block::update(float t)
{
	this->setPositionX(getPositionX() - 4);

	//�Ƴ���Ļ������
	if (getPositionY() < 0)
	{
		this->unscheduleUpdate();
		this->removeFromParent();
	}
}