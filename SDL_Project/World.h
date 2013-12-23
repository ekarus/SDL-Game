#pragma once
#include <vector>
#include "Block.h"
#include "Object.h"
#include "CWindow.h"

class World : public Object
{
private:
	typedef std::vector<Block> Blocks;

	Blocks blocks_;

public:

	virtual bool OnInit() override
	{
		int width = WindowSingleton::Instance()->GetWidth();
		int height = WindowSingleton::Instance()->GetHeight();

		int block_size = 10;

		blocks_.clear();

		/*Block block;
		block.OnInit();
		block.setSize(Geometry::Size(width, block_size));
		block.setPos(Geometry::Position(0, 0));
		blocks_.push_back(block);

		block = Block();
		block.OnInit();
		block.setSize(Geometry::Size(width, block_size));
		block.setPos(Geometry::Position(0, height - block_size));
		blocks_.push_back(block);

		block = Block();
		block.OnInit();
		block.setSize(Geometry::Size(block_size, height));
		block.setPos(Geometry::Position(0, 0));
		blocks_.push_back(block);

		block = Block();
		block.OnInit();
		block.setSize(Geometry::Size(block_size, height));
		block.setPos(Geometry::Position(width - block_size, 0));
		blocks_.push_back(block);*/

		return true;
	}

	virtual void OnUpdate( Game::FrameTime time) override
	{
		std::for_each(blocks_.begin(), blocks_.end(), [=](Blocks::value_type& block)
		{
			block.OnUpdate(time);
		});
	}

	virtual void OnRender() override
	{
		std::for_each(blocks_.begin(), blocks_.end(), [=](Blocks::value_type& block)
		{
			block.OnRender();
		});
	}

	virtual void OnCleanUp() override
	{
		std::for_each(blocks_.begin(), blocks_.end(), [=](Blocks::value_type& block)
		{
			block.OnCleanUp();
		});
	}

	virtual void OnRestart() override
	{
		std::for_each(blocks_.begin(), blocks_.end(), [=](Blocks::value_type& block)
		{
			block.OnRestart();
		});
	}

	virtual Geometry::Position GetNextPosition(Game::FrameTime) override
	{
		return position_;
	}
};