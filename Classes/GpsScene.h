#ifndef __Gps_SCENE_H__
#define __Gps_SCENE_H__

#include "cocos2d.h"
#include "CsvUtil.h"
using namespace cocos2d;

class Gps : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);
    
    // implement the "static node()" method manually
    CREATE_FUNC(Gps);
	void updateView(float dt);
	void showPoint(int num);

	CCPoint getpointPos(int num);
	int Distance();
	CCString* getpointName();
	void showPosName(int num);
	void menu3CallBack(CCObject* pSender);
public:
     double longitude;
	 double latitude;
	 CCLabelTTF* pLabel;
	  CCLabelTTF* pLabel2;
	 CCSprite* mapPoint;
	 CCSprite* wholeMap;
};

#endif // __Gps_SCENE_H__
