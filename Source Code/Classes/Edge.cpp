#include"Edge.h"

bool Edge::init()
{
	if (!Node::init())
		return false;

	//窗口大小
	Size size = Director::getInstance()->getWinSize();

	//设置刚体
	this->setPhysicsBody(PhysicsBody::createEdgeBox(size));
	this->setContentSize(size);

	return true;
}