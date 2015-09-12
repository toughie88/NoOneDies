#include "GameController.h"
#include "Block.h"

GameController* GameController::create(Layer* layer, float positionY)
{
	GameController* pRet = new GameController();
	if (pRet && pRet->init(layer, positionY))
	{
		pRet->autorelease();
		return pRet;
	}
	else
	{
		delete pRet;
		pRet = NULL;
		return NULL;
	}
}

bool GameController::init(Layer* layer, float positionY)
{
	this->layer = layer;
	this->positionY = positionY;
	this->size = Director::getInstance()->getWinSize();

	//��������Ե
	edge = Edge::create();
	edge->setPosition(Point(0, positionY));
	layer->addChild(edge);

	//½��
	auto ground = Sprite::create();
	ground->setTextureRect(Rect(0, 0, size.width, 3));
	ground->setColor(Color3B(0, 0, 0));
	ground->setPosition(Point(size.width / 2, positionY + 1.5));
	layer->addChild(ground);

	//С��
	hero = Hero::create();
	hero->setPosition(Point(100, hero->getContentSize().height / 2 + positionY));
	layer->addChild(hero);

	//����֡Ƶ��
	resetFrame();

	return true;
}

void GameController::onUpdate()
{
	//��ӿ�
	curFrame++;
	if (curFrame >= nextFrame)
	{
		resetFrame();
		addBlock();
	}
}

void GameController::resetFrame()
{
	curFrame = 0;
	nextFrame = rand() % 120 + 100;
}

void GameController::addBlock()
{
	auto block = Block::create();
	block->setPositionY(block->getContentSize().height / 2 + positionY);
	layer->addChild(block);
}

bool GameController::isHit(Point p)
{
	return edge->getBoundingBox().containsPoint(p);
}

void GameController::jump()
{
	hero->getPhysicsBody()->setVelocity(Vec2(0, 400));
}