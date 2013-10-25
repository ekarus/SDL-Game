#pragma once
#include "Singleton.h"

class CFPS : public Singleton<CFPS>
{
public:
	void onUpdate();
	int getFPS(){return frameRate;};
	float getSpeedFactor(){return speedFactor;};

private:
	friend class Singleton<CFPS>;

	int frameCount;
	int frameRate;
	float speedFactor;
	int oldTime;
	int lastTime;

protected:
	CFPS();
	virtual ~CFPS();
};