#pragma once

#include "CMoveObject.h"

class CNpc: public CMoveObject
{
public:
	CNpc();
	~CNpc();

	virtual void OnUpdate( float time );

	virtual void OnRender( SDL_Renderer* render );

	virtual bool OnLoad( std::string file,SDL_Renderer* render );

	virtual void OnCleanUp();

	CEntity* getGoal() const { return goal; }
	void setGoal(CEntity* val) { goal = val; }

	virtual bool OnCollision( CEntity* entity );

	virtual void OnRestart();

	virtual void OnEntityNear( CEntity* entity );

	virtual bool onEat( CEntity* entity );

protected:

	

private:

	CEntity* goal;
	SDL_Texture* target_tex;
	
};