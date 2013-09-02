#pragma once

#include "CEntity.h"

class CMoveObject: public CEntity
{
public:
	CMoveObject();
	~CMoveObject();

	virtual void OnUpdate( float time );
	virtual void onMove(Vector2d dir);
	virtual void stopMove();

	virtual bool eat(CEntity* entity);

	virtual void onDanger(Vector2d point);

	Vector2d getVelocity() const { return vel; }
	void setVelocity(Vector2d val) {vel = val; }
	Vector2d getAcc() const { return acc; }
	void setAcc(Vector2d val) { acc = val; }
	float getSpeed() const { return speed; }
	void setSpeed(float val) { speed = val; }

	virtual bool OnCollision( CEntity* entity );

	virtual void OnRestart();

	virtual void OnEntityNear(CEntity* entity);

protected:
	Vector2d vel;
	Vector2d acc;
	Vector2d maxVel;
	float speed;

private:
};