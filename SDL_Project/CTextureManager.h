#pragma once
#include <string>
#include <SDL.h>
#include <map>

class CTextureManager
{
public:
	//возвращает указатель на экземпляр синглтона
	static CTextureManager* getInst()
	{
		static CTextureManager inst;
		return &inst;
	}
	//загружает текстуру из файла и возвращает ид, 0 - если ошибка
	Uint32 LoadTexture(std::string file);
	//удаляет указанную текстуру
	void DeleteTexture(Uint32 id);
	//рисует текстуру в точке х,у с шириной w, высотой h и углом поворота angle
	void DrawTexture(Uint32 id,int x,int y,int w,int h, int angle=0);
	//рисует текстуру часть текстуры (x2,y2,w2,h2) в точке х,у с шириной w, высотой h и углом поворота angle
	void DrawTexture(Uint32 id,int x,int y,int w,int h, int x2,int y2, int w2,int h2 ,int angle=0);
	//устанавливает цвет для указанной текстуры в формате RGBA
	void SetTextureColor(Uint8 r,Uint8 g, Uint8 b, Uint8 a);
	//возвращает ширину текстуры
	int getTextureWidth(Uint32 id);
	//возвращает высоту текстуры
	int getTextureHeight(Uint32 id);
	//удаляет все текстуры
	void DeleteAllTexture();

private:

	class Texture
	{
	public:
		int w;
		int h;
		SDL_Texture* tex;
		std::string file;
	};

	std::map< Uint32, Texture > m_Textures;
};