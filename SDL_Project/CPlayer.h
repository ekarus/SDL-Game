#pragma once

#include "CMoveObject.h"

class CPlayer: public CMoveObject
{
public:
	CPlayer();
	~CPlayer();

	virtual void OnUpdate( float time );

	virtual void OnRender( SDL_Renderer* render );

	virtual bool OnLoad( std::string file,SDL_Renderer* render );

	virtual void OnCleanUp();

	Vector2d getGoalPoint() const { return goalPoint; }
	void setGoalPoint(Vector2d val) { goalPoint = val; hasGoal=true; }

	virtual bool OnCollision( CEntity* entity );

	virtual void onMove( Vector2d dir );

protected:
	
private:
	Vector2d goalPoint;
	bool hasGoal;
};