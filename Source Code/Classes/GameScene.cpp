#include "GameScene.h"
#include "GameOverScene.h"

int gameType=0;	//��Ϸ�Ѷ�����

Scene* GameScene::createScene(int type)
{
	gameType = type;

	auto scene = Scene::createWithPhysics();
//	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	scene->getPhysicsWorld()->setGravity(Vec2(0, -1000));

    auto layer = GameScene::create();
    scene->addChild(layer);

    return scene;
}

bool GameScene::init()
{
    if ( !LayerColor::initWithColor(Color4B(255, 255, 255, 255)) )
    {
        return false;
    }
   
	Size size = Director::getInstance()->getWinSize();

	for (int i = 0; i < gameType; ++i)
	{
		gcs.insert(0, GameController::create(this, size.height * i / gameType));
	}

	this->scheduleUpdate();

	//��ײ����
	auto listener = EventListenerPhysicsContact::create();
	listener->onContactBegin = [&](PhysicsContact &contact)
	{
		this->unscheduleUpdate();
		Director::getInstance()->replaceScene(GameOverScene::createScene());
		return true;
	};
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	//��������
	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = [&](Touch *t, Event *e)
	{
		for (auto it = gcs.begin(); it != gcs.end(); it++)
		{
			if ((*it)->isHit(t->getLocation()))
			{
				(*it)->jump();
				break;
			}
		}
		return true;
	};
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);

    return true;
}

void GameScene::update(float t)
{
	//ѭ��������Ϸ�������еĿ��ϰ���
	for (auto gc : gcs)
	{
		gc->onUpdate();
	}
}
