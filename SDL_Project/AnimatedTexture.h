#pragma once

#include "Texture.h"
#include "CAnimation.h"
#include <memory>

namespace Detail
{
	class AnimatedTexture: public Texture
	{
	public:
		typedef AnimatedTexture* Ptr;

		AnimatedTexture(const std::string& file, RawTexturePtr tex, size_t width, size_t height, size_t row_count, size_t column_count):
		Texture(file, tex, width, height),row_count_(row_count),column_count_(column_count)
		{
			animator.setFrameCount(row_count_);
		}

		AnimatedTexture(const Texture& texture, size_t row_count, size_t column_count):
		Texture(texture),row_count_(row_count),column_count_(column_count)
		{
			animator.setFrameCount(row_count_);
		}

		CAnimation& getAnimator()
		{
			return animator;
		}

		virtual void Draw( int x,int y,int w,int h, int angle );

		virtual void Draw( Rect dst_rect );

	private:
		void Draw(size_t currFrame, size_t frameCount,const Rect* dst_rect );

		CAnimation animator;
		size_t row_count_;
		size_t column_count_;
		size_t animation_col_;
	};
}

typedef Detail::AnimatedTexture AnimatedTexture;

typedef std::shared_ptr<Detail::AnimatedTexture> AnimatedTextureSharedPtr;