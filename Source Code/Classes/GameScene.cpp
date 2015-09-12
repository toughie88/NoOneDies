#include "GameScene.h"
#include "GameOverScene.h"

int gameType=0;	//游戏难度类型

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

	//碰撞监听
	auto listener = EventListenerPhysicsContact::create();
	listener->onContactBegin = [&](PhysicsContact &contact)
	{
		this->unscheduleUpdate();
		Director::getInstance()->replaceScene(GameOverScene::createScene());
		return true;
	};
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	//触摸监听
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
	//循环处理游戏控制器中的块障碍物
	for (auto gc : gcs)
	{
		gc->onUpdate();
	}
}
