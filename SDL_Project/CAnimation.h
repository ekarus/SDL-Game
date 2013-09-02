#pragma once

class CAnimation
{
public:
	CAnimation();
	~CAnimation();

	int getCurrFrame() const { return curr_frame; }
	void setCurrFrame(int val) { if(val<=frame_count)curr_frame = val; }
	int getFrameRate() const { return frame_rate; }
	void setFrameRate(int val) { frame_rate = val; }
	int getFrameCount() const { return frame_count; }
	void setFrameCount(int val) { frame_count = val; }
	int getStep() const { return step; }
	void setStep(int val) { step = val; }

	void OnAnimate();

private:
	int frame_rate;
	int frame_count;
	int curr_frame;
	int step;
	int old_time;
};
