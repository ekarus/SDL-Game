#pragma once
#include "Object.h"
#include "TextureManager.h"
#include "CLogger.h"
#include "Types.h"

class Block : public Object
{
public:

	Block()
	{
	}

	virtual ~Block()
	{
	}

	virtual void OnUpdate( Game::FrameTime time)
	{
	}

	virtual void OnRender()
	{
		texture_->Draw(getRect());
	}

	virtual bool OnInit()
	{
		if(texture_ = TextureManagerSingleton::Instance()->Load("..//Res//menu.png"))
		{
			return true;
		}
		else
		{
			LOG_ERROR("Could't load block texture");
			return false;
		}
	}

	virtual void OnCleanUp()
	{
	}

	virtual void OnRestart()
	{
	}

	virtual Geometry::Position GetNextPosition(Game::FrameTime) override
	{
		return position_;
	}

private:
	TextureSharedPtr texture_;
};