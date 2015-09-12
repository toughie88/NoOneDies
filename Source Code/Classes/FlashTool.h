#ifndef _Flash_Tool_H_
#define _Flash_Tool_H_

#include <iostream>
#include <cocos2d.h>

USING_NS_CC;

class FlashTool {
    
public:
    static Animate * readJsonSpriteSheet(std::string jsonFile,float delayPerUnit);
};


#endif
