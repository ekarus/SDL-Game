#include "AnimatedTexture.h"

void Detail::AnimatedTexture::Draw( int x,int y,int w,int h, int angle )
{
	animator.OnAnimate();

	Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;

	Draw(animator.getCurrFrame(), animator.getFrameCount(), &rect);
}

void Detail::AnimatedTexture::Draw( Rect dst_rect )
{
	animator.OnAnimate();

	Draw(animator.getCurrFrame(),animator.getFrameCount(),&dst_rect);
}

void Detail::AnimatedTexture::Draw( size_t currFrame, size_t frameCount,const Rect* dst_rect )
{
	Rect rect;
	rect.w = width_;
	rect.h = height_;
	if (frameCount == 0) frameCount=1;
	int slide_width=rect.w / frameCount;
	rect.x = slide_width * currFrame;
	rect.y = 0;
	rect.w = slide_width;

	Texture::Draw(&rect, dst_rect);
}