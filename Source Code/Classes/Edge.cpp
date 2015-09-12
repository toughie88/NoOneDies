#include"Edge.h"

bool Edge::init()
{
	if (!Node::init())
		return false;

	//���ڴ�С
	Size size = Director::getInstance()->getWinSize();

	//���ø���
	this->setPhysicsBody(PhysicsBody::createEdgeBox(size));
	this->setContentSize(size);

	return true;
}