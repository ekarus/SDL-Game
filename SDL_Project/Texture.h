#pragma once

#include <SDL.h>
#include <string>
#include <memory>

typedef SDL_Rect Rect;

struct Color
{
	enum Enum
	{
		green,
		blue,
		gray,
		orange,
		red,
		dark_gray,
		white,
		black
	};
};

namespace Detail
{
	class Texture
	{
	public:
		typedef Texture* Ptr;
		typedef SDL_Texture RawTexture;
		typedef RawTexture* RawTexturePtr;

		Texture():file_(""),tex_(nullptr),width_(0),height_(0)
		{
		}

		Texture(const std::string& file, RawTexturePtr tex, size_t width, size_t height):
		file_(file), tex_(tex), width_(width), height_(height)
		{
		}

		virtual void Draw(int x,int y,int w,int h, int angle = 0 );

		virtual void Draw(Rect dst_rect );

		virtual void Draw(int x,int y,int w,int h, int x2,int y2, int w2,int h2 ,int angle/*=0*/ );

		virtual void Draw(const Rect* src_rect,const Rect* dst_rect );

		virtual ~Texture()
		{
		}

		virtual RawTexturePtr GetRaw()
		{
			return tex_;
		}

		std::string getFileName() const
		{
			return file_;
		}

		size_t getWidth() const
		{
			return width_;
		}

		size_t getHeight() const
		{
			return height_;
		}

		void setColor(Color::Enum color);

	protected:
		int width_;
		int height_;
		RawTexturePtr tex_;
		std::string file_;
		Color::Enum color_;
	};
}

typedef Detail::Texture Texture;

typedef std::shared_ptr<Detail::Texture> TextureSharedPtr;
