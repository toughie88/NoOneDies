#include "SplashScene.h"
#include "GameScene.h"

USING_NS_CC;

Scene * SplashScene::createScene()
{
	auto scene = Scene::create();
	auto layer = SplashScene::create();
	scene->addChild(layer);
	return scene;
}

bool SplashScene::init()
{
	if(!Layer::init())
		return false;

	auto size = Director::getInstance()->getWinSize();

	TTFConfig config("fonts/Marker Felt.ttf", 50);

	//游戏名称
	auto GameName = Label::createWithTTF(config, "No One Dies");
	GameName->setColor(Color3B::WHITE);
	GameName->setPosition(Point(size.width / 2, size.height * 6 / 8));
	this->addChild(GameName);

	//作者
	auto author = Label::createWithTTF(config, "Game By JJY");
	author->setColor(Color3B::WHITE);
	author->setScale(0.5);
	author->setPosition(Point(size.width / 2, size.height * 5 /8));
	this->addChild(author);

	//按钮
	auto menuItemStartEasy = MenuItemFont::create("Easy", CC_CALLBACK_1(SplashScene::menuCallBack, this));
	menuItemStartEasy->setColor(Color3B::WHITE);
	menuItemStartEasy->setTag(2);
	auto menuItemStartMedium = MenuItemFont::create("Medium", CC_CALLBACK_1(SplashScene::menuCallBack, this));
	menuItemStartMedium->setColor(Color3B::WHITE);
	menuItemStartMedium->setTag(3);
	auto menuItemStartHard = MenuItemFont::create("Hard", CC_CALLBACK_1(SplashScene::menuCallBack, this));
	menuItemStartHard->setColor(Color3B::WHITE);
	menuItemStartHard->setTag(4);

	auto menu = Menu::create(menuItemStartEasy, menuItemStartMedium, menuItemStartHard, NULL);
	menu->setPosition(Point::ZERO);
	menuItemStartEasy->setPosition(Point(size.width/2, size.height*0.4));
	menuItemStartMedium->setPosition(Point(size.width / 2, size.height*0.3));
	menuItemStartHard->setPosition(Point(size.width / 2, size.height*0.2));
	this->addChild(menu);

	return true;
}

void SplashScene::menuCallBack(Ref* obj)
{
	auto target = (Node*)obj;

	Scene *scene;

	switch (target->getTag())
	{
	case 2:
		scene = GameScene::createScene(2);
		break;
	case 3:
		scene = GameScene::createScene(3);
		break;
	case 4:
		scene = GameScene::createScene(4);
		break;
	default:
		break;
	}
	Director::getInstance()->replaceScene(scene);
}