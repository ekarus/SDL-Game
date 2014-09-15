#include "UnZip.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "CRender.h"
#include <iostream>
#include <boost/filesystem/path.hpp>

class MemoryStream
{
public:
	MemoryStream(void* data, size_t size)
	{
		rw_ = SDL_RWFromMem(reinterpret_cast<char*>(data), size);
	}

	~MemoryStream()
	{
		Close();
	}
	void Close()
	{
		if (rw_)
			SDL_FreeRW(rw_);
		rw_ = nullptr;
	}

	SDL_RWops* GetRaw()
	{
		return rw_;
	}

private:
	SDL_RWops* rw_;
};

class Content
{
public:
	Content(const boost::filesystem::path& content) : content_(content)
	{

	}

	SDL_Texture* LoadTexture(const boost::filesystem::path& file_path)
	{
		UnZip::InnerFile file = content_.GetFile(file_path);

		/*while(!file.IsFile())
			file = content_.GetNextFile();*/

		UnZip::Buffer buffer;

		file.GetContent(&buffer);

		MemoryStream memory(&buffer[0], buffer.size());

		SDL_Texture* tex = IMG_LoadTexture_RW(RendererSingleton::Instance()->Get(), memory.GetRaw(), 0); 

		return tex;
	}

private:
	UnZip content_;
};

