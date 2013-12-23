#pragma once
#include "Object.h"
#include "Factory.h"
#include <vector>
#include "AnimatedTexture.h"
#include <boost/shared_ptr.hpp>

class Pawn : public Object
{
public:
	typedef boost::shared_ptr<Pawn> PawnSharedPtr;
	//typedef std::vector<PawnSharedPtr> PawnsList;

	//static PawnsList list_;

	Pawn();
	virtual ~Pawn();

	virtual void OnUpdate(Game::FrameTime) override;
	virtual void OnRender() override;
	virtual bool OnInit() override;
	virtual void OnCleanUp() override;
	virtual void OnRestart() override;

	virtual Color::Enum getColor() const { return color_; }

	virtual void setColor(Color::Enum val) { color_ = val; }

	virtual bool isLive() const { return is_live_; }

	virtual void setLive(bool val) { is_live_ = val; }

	virtual Physics::Velocity GetVelocity() const { return velocity_; }

	virtual void SetVelocity(Physics::Velocity val) { velocity_ = val; }

	virtual Physics::Acceleration GetAcceleration() const { return acceleration_; }

	virtual void SetAcceleration(Physics::Acceleration val) { acceleration_ = val; }

	virtual Physics::Velocity GetMaxVelocity() const { return max_velocity_; }

	void SetMaxVelocity(Physics::Velocity val) { max_velocity_ = val; }

	virtual void StopMove();

	virtual Geometry::Position GetNextPosition(Game::FrameTime) override;

protected:
	bool is_live_;

	Color::Enum color_;
	AnimatedTextureSharedPtr texture_;

	Physics::Velocity velocity_;
	Physics::Velocity max_velocity_;
	Physics::Acceleration acceleration_;
	float speed_value_;
};
