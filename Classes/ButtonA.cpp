#include "ButtonA.h"
#include "Animation.h"//$

//update:2014-9-26 01:59:07

bool ButtonA::init()
{
    return Button::init();
}
//如果按钮图不是右边是按下的
void ButtonA::initSprite()
{
    CCTexture2D* HumanEntityTexture=CCTextureCache::sharedTextureCache()->addImage(BUTTONA_IMG_PATH);
    buttonImg=CCSprite::createWithTexture(HumanEntityTexture);
    int aa=buttonImg->getContentSize().height;
    buttonImg->setTextureRect(CCRectMake(0,0,aa,aa));
    buttonImg->setTag(IMGSP);addChild(buttonImg);
}

void ButtonA::ccTouchesBegan(CCSet* pTouches, CCEvent *pEvent)
{
	if(hero->isWalking) enable=false;
    if(!enable)return;

    //判断按到按钮木有
    CCPoint TouchesLocation = getTouchPos(pTouches);
    if(!(getBoundingBox().containsPoint(TouchesLocation)))return;

    //按钮动画响应
    int aa=buttonImg->getContentSize().height;
    buttonImg->setTextureRect(CCRectMake(aa*1,0,aa,aa));

    //监听对象响应
    if(controllerListener!=NULL)
    {
	controllerListener->respond(0);
	if(controllerListener->hasTouchEnded())
	{
		this->setControllerListener(NULL);
		eManager->next();
	    this->enableDirButton();
	}
    }
    //如果没有监听对象
    else 
	trigEvent();
	
    //@else if(sGlobal->superPower->speed>2.0f){ //hero->run=true; //}
    //else if(!doShrink)hero->speed=3.0f;//$
    //if(!hero->isHeroWalking&&!doShrink)hero->speed=3.0f;//$

    return;
}

void ButtonA::ccTouchesEnded(CCSet* pTouches, CCEvent *pEvent)
{
    buttonImg->setTextureRect(CCRectMake(0,0,50,50));
    //hero->speed=1.0f;//$
}

void ButtonA::setPointers(Hero* hero,DiaWindow* diawindow,BigWindow* bigwindow)
{
    this->hero=hero;
    this->diawindow=diawindow;
    this->bigwindow=bigwindow;
}

void ButtonA::disableDirButton()
{
    disaDistr=0*BUTTONA+1*DIRBUTTON;
}

void ButtonA::enableDirButton()
{
    disaDistr=0*BUTTONA+0*DIRBUTTON;
}

void ButtonA::trigEvent()
{
    CCPoint facingTile = hero->getHeroTilePos()+
	ccp((hero->move/(hero->map->getTileSize().height)).x,
		-(hero->move/(hero->map->getTileSize().height)).y);
    //@EventManager takes over from here
    ControllerListener* lst=eManager->happen(facingTile,A_TRIG);
    if(lst!=NULL) this->setControllerListener(lst);
}
