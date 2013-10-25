#pragma once
#include <SDL.h>
#include <exception>
#include <string>


template<typename Base>
class Singleton
{
public:

	static Base* Instance()
	{
		if(inst_)
		{
			return inst_;
		}
		else
		{
			return inst_ = Create();
		}
	}

	static void Delete()
	{
		delete inst_;
		inst_ = nullptr;
	}

private:
	static Base* Create()
	{
		return  new Base();
	}

	static Base* inst_;
	Singleton& operator=(const Singleton& base);
	Singleton(const Singleton& base);

protected:
	Singleton(){}
	virtual ~Singleton(){}
};

template<typename Base>
Base* Singleton<Base>::inst_ = nullptr;


template<>
class Singleton<SDL_Window>
{
public:
	static SDL_Window* Instance();

	static SDL_Window* Instance(const std::string& title, size_t width, size_t height);

	static void Delete();

private:

	static SDL_Window* Create(const std::string& title, size_t width, size_t height);

	static SDL_Window* window_;

	Singleton& operator=(const Singleton& base);
	Singleton(const Singleton& base);

protected:
	Singleton(){}
	virtual ~Singleton(){}
};




template<>
class Singleton<SDL_Renderer>
{
public:

	static SDL_Renderer* Instance();

	static void Delete();

private:

	static SDL_Renderer* Create();

	static SDL_Renderer* renderer_;

	Singleton& operator=(const Singleton& base);
	Singleton(const Singleton& base);

protected:
	Singleton(){}
	virtual ~Singleton(){}
};


