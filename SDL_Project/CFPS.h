#pragma once

class CFPS
{
public:
	
	void onUpdate();
	int getFPS(){return frameRate;};
	float getSpeedFactor(){return speedFactor;};
	static CFPS* getInstance();

private:
	static CFPS* instance;
	CFPS();
	int frameCount;
	int frameRate;
	float speedFactor;
	int oldTime;
	int lastTime;
};