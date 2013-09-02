#pragma once
#include "vector2d.h"
#include "CTexture.h"
#include "timer.h"
#include "SDL.h"
#include <vector>



class GameObject
{
public:
	
	GameObject():pos(0,0),size(20,20),vel(0,0),acc(0,0)
	{
		color=gray;
		live=true;
		speed=1.5;
		normal_speed=1.5;
		boost_speed=3.0;
		can_move=true;
		setGoal(nullptr);
	}

	virtual void Update(float time);
	virtual void Draw(SDL_Renderer* render);
	Vector2d getVelocity() const { return vel; }
	void setVelocity(Vector2d val) {vel = val; }
	Vector2d getPos() const { return pos; }
	void setPos(Vector2d val) { pos = val; }
	Vector2d getAcc() const { return acc; }
	void setAcc(Vector2d val) { acc = val; }
	Colors getColor() const { return color; }
	void setColor(Colors val) { color = val; }
	Vector2d getSize() const { return size; }
	void setSize(Vector2d val) { size = val; }
	void eat(GameObject& obj);
	void kill(){live=false; setGoal(0);setSize(Vector2d(0,0));}
	bool isLive(){return live;}
	float getSpeed() const { return speed; }
	void setSpeed(float val) { speed = val; }
	bool isCan_move() const { return can_move; }
	void setCan_move(bool val) { can_move = val; }
	GameObject* getGoal() const { return goal; }
	void setGoal(GameObject* val) { goal = val; }
	bool isHas_enemy() const { return has_enemy; }
	void setHas_enemy(bool val) { has_enemy = val; }
	void runBoost();
	Vector2d getCenter() const;
	static void load_image(SDL_Renderer* render);
protected:
	bool live;
	Vector2d pos;
	Vector2d size;
	Vector2d vel;
	Vector2d acc;
	Colors color;
	float speed;
	
private:
	static SDL_Texture* image;

	GameObject* goal;
	
	bool can_move;
	bool has_enemy;
	
	Timer boost_timer;
	float boost_speed;
	float normal_speed;
	
};
