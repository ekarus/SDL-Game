#pragma once
#include "vector2d.h"
#include "AnimatedTexture.h"
#include <SDL2/SDL.h>
#include <vector>
#include <string>

 class CEntity
 {
 public:

	 static std::vector<CEntity*> entity_list;

	 CEntity();
	 virtual ~CEntity();

	 virtual void OnUpdate(float time);
	 virtual void OnRender(SDL_Renderer* render);
	 virtual bool OnLoad(std::string file,SDL_Renderer* render,int frame_count);
	 virtual bool OnLoad(std::string file,SDL_Renderer* render);
	 virtual bool OnCollision(CEntity* entity);
	 virtual void OnCleanUp();
	 virtual void OnRestart();
	 virtual void OnEntityNear(CEntity* entity);
	 virtual SDL_Rect getRect()
	 {
		 SDL_Rect rect;
		 rect.x=pos.x;
		 rect.y=pos.y;
		 rect.w=size.x;
		 rect.h=size.y;
		 return rect;
	 }

	 void setX(float val){pos.x=val;}
	 void setY(float val){pos.y=val;}
	 void setW(float val){size.x=val;}
	 void setH(float val){size.y=val;}
	 Vector2d getPos() const { return pos; }
	 void setPos(Vector2d val) { pos = val; }
	 Vector2d getSize() const { return size; }
	 void setSize(Vector2d val) { size = val; }
	 bool getIsVisible() const { return isVisible; }
	 void setVisible(bool val) { isVisible = val; }
	 Color::Enum getColor() const { return color; }
	 void setColor(Color::Enum val) { color = val; }
	 Vector2d getCenter() const;
	 bool isLive() const { return live; }
	 void setLive(bool val) { live = val; }

 protected:

	 bool isCollide(CEntity* entity,float x,float y);
	 bool postValid(float newX, float newY);
	 bool checkEntityCollide(CEntity*, float x,float y);
	 bool checkMapCollide(CEntity* entity, float x,float y);
	 virtual void OnMapCollide(float x, float y);

	 bool live;

	 Vector2d pos;
	 Vector2d size;
	 Color::Enum color;

	 //TextureId tex;
	 AnimatedTextureSharedPtr anim_tex;
	 //CAnimation animator;
	 bool isVisible;
 };
