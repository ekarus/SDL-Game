#include "CFPS.h"
#include <time.h>


CFPS* CFPS::getInstance()
{
	if(instance==nullptr)
	{
		instance=new CFPS();
		return instance;
	}
	else
		return instance;
}

CFPS::CFPS()
{
	frameCount=0;
	frameRate=0;
	speedFactor=0;
	oldTime=0;
	lastTime=0;
}

void CFPS::onUpdate()
{
	if((oldTime+CLOCKS_PER_SEC)<clock())
	{
		frameRate=frameCount;
		frameCount=0;
		oldTime=clock();
	}
	speedFactor=(float(clock()-lastTime)/CLOCKS_PER_SEC);
	lastTime=clock();
	frameCount++;
}

CFPS* CFPS::instance;
