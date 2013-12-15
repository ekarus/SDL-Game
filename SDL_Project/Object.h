#pragma once
#include "vector2d.h"
#include "Types.h"
#include "Factory.h"
#include <vector>

class Object
{
public:

	/*typedef Factory<Object> Factory;
	typedef std::vector<Factory::ObjectPtr> ObjectsList;

	static ObjectsList list_;*/

	Object():is_visible_(true), position_(Geometry::Position(0,0)), size_(Geometry::Size(10,10))
	{

	}

	virtual ~Object()
	{

	}

	virtual void OnUpdate(Game::FrameTime) = 0;
	virtual void OnRender() = 0;
	virtual bool OnInit() = 0;
	virtual void OnCleanUp() = 0;
	virtual void OnRestart() = 0;

	virtual Geometry::Rect getRect();

	virtual void setX(float val){position_.x = val;}
	virtual void setY(float val){position_.y = val;}
	virtual void setW(float val){size_.x = val;}
	virtual void setH(float val){size_.y = val;}

	virtual Geometry::Position getPos() const { return position_; }

	virtual void setPos(Geometry::Position val) { position_ = val; }

	virtual Geometry::Size getSize() const { return size_; }

	virtual void setSize(Geometry::Size val) { size_ = val; }

	virtual Geometry::Position getCenter() const;

	virtual bool IsVisible() const { return is_visible_; }

	virtual void setVisible(bool val) { is_visible_ = val; }

protected:
	bool is_visible_;

	Geometry::Position position_;
	Geometry::Size size_;
};
