/*
#pragma once
#include <string>
#include <SDL.h>
#include <map>
#include "Singleton.h"
#include <memory>
#include "CRender.h"
#include "CLogger.h"
#include "CAnimation.h"

typedef Uint32 TextureId;
typedef SDL_Rect Rect;
typedef SDL_Texture RawTexture;
typedef RawTexture* RawTexturePtr;

namespace Detail
{
	class Texture;
	class AnimatedTexture;
};

typedef std::shared_ptr<Detail::Texture> TextureSharedPtr;
typedef std::weak_ptr<Detail::Texture> TextureWeakPtr;
typedef std::shared_ptr<Detail::AnimatedTexture> AnimTextureSharedPtr;
typedef std::weak_ptr<Detail::AnimatedTexture> AnimTextureWeakPtr;

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

class CTextureManager : public Singleton<CTextureManager>
{
public:

	TextureSharedPtr LoadTexturePtr(const std::string& file);
	AnimTextureSharedPtr LoadAnimTexturePtr(const std::string& file);
	void DeleteTexture(TextureId id);
	void DeleteAllTexture();

private:
	friend class Singleton<CTextureManager>;
	typedef std::map< TextureId, RawTexturePtr > TexturesContainerByID;
	typedef std::map< std::string, TextureWeakPtr > TextureWeakPtrContainer;

	bool isAlreadyLoaded(const std::string& file);

	TextureWeakPtrContainer textures_;
	TexturesContainerByID textures_by_id_;
	size_t last_id;

protected:

	CTextureManager();
	virtual ~CTextureManager();
};

namespace Detail
{
	class Texture
	{
	public:
		Texture():id_(0),file_(""),tex_(nullptr),width_(0),height_(0)
		{
		}
		Texture(const std::string& file, RawTexturePtr tex, TextureId id, size_t width, size_t height):
		file_(file), id_(id), tex_(tex), width_(width), height_(height)
		{
		}
		virtual void Draw(int x,int y,int w,int h, int angle = 0 );

		virtual void Draw(Rect dst_rect );

		virtual void Draw(int x,int y,int w,int h, int x2,int y2, int w2,int h2 ,int angle/ *=0* / );

		virtual void Draw(const Rect* src_rect,const Rect* dst_rect );

		virtual ~Texture()
		{
			CTextureManager::Instance()->DeleteTexture(id_);
		}
		virtual bool isValid()
		{
			return (id_ != 0) && (tex_ != nullptr);
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
		TextureId id_;
		int width_;
		int height_;
		SDL_Texture* tex_;
		std::string file_;
		Color::Enum color_;
	};

	class AnimatedTexture: public Texture
	{
	public:
		AnimatedTexture(const std::string& file, RawTexturePtr tex, TextureId id, size_t width, size_t height, size_t row_count, size_t column_count):
			Texture(file, tex, id, width, height),row_count_(row_count),column_count_(column_count)
		  {
			  animator.setFrameCount(row_count_);
		  }

		  AnimatedTexture(const Texture& texture, size_t row_count, size_t column_count):
			Texture(texture),row_count_(row_count),column_count_(column_count)
		  {
			  animator.setFrameCount(row_count_);
		  }

		  void Draw(size_t currFrame, size_t frameCount,const Rect* dst_rect );

		  virtual void Draw( int x,int y,int w,int h, int angle );

		  virtual void Draw( Rect dst_rect );

	private:
		CAnimation animator;
		size_t row_count_;
		size_t column_count_;
		size_t animation_col_;
	};
}
*/
