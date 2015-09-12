#include "GameOverScene.h"
#include "SplashScene.h"

Scene* GameOverScene::createScene()
{
	auto scene = Scene::create();

	auto layer = GameOverScene::create();

	scene->addChild(layer);

	return scene;
}

bool GameOverScene::init()
{
	if (!LayerColor::initWithColor(Color4B::WHITE))
	{
		return false;
	}

	Size size = Director::getInstance()->getWinSize();

	//ÓÎÏ·½áÊølabel
	auto label = Label::createWithSystemFont("Game Over", "Consolas", 40);
	label->setPosition(size / 2);
	label->setColor(Color3B::BLACK);
	this->addChild(label);

	//°´Å¥
	auto menuItemReStart = MenuItemFont::create("Restart", CC_CALLBACK_1(GameOverScene::menuRestartCallBack, this));
	menuItemReStart->setColor(Color3B::BLACK);
	auto menuItemQuit = MenuItemFont::create("Quit", CC_CALLBACK_1(GameOverScene::menuCloseCallBack, this));
	menuItemQuit->setColor(Color3B::BLACK);

	auto menu = Menu::create(menuItemReStart, menuItemQuit, NULL);
	menu->setPosition(Point::ZERO);
	menuItemReStart->setPosition(size.width / 6, size.height / 8);
	menuItemQuit->setPosition(size.width * 6 / 7, size.height / 8);
	this->addChild(menu);

	return true;
}

void GameOverScene::menuRestartCallBack(Ref* obj)
{
	auto scene = SplashScene::createScene();
	Director::getInstance()->replaceScene(scene);
}

void GameOverScene::menuCloseCallBack(Ref* obj)
{
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}