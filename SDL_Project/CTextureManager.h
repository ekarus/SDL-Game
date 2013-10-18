#pragma once
#include <string>
#include <SDL.h>
#include <map>
#include "Singleton.h"

typedef Uint32 TextureId;

struct Color
{
	enum Enum
	{
		green,
		blue,
		gray,
		orange,
		red,
		dark_gray,
		white,
		black
	};
};

class CTextureManager : public Singleton<CTextureManager>
{
public:
	//��������� �������� �� ����� � ���������� ��, 0 - ���� ������
	TextureId LoadTexture(const std::string& file);
	//������� ��������� ��������
	void DeleteTexture(TextureId id);
	//������ �������� � ����� �,� � ������� w, ������� h � ����� �������� angle
	void DrawTexture(TextureId id,int x,int y,int w,int h, int angle=0);
	//������ �������� ����� �������� (x2,y2,w2,h2) � ����� �,� � ������� w, ������� h � ����� �������� angle
	void DrawTexture(TextureId id,int x,int y,int w,int h, int x2,int y2, int w2,int h2 ,int angle=0);
	//������������� ���� ��� ��������� �������� � ������� RGBA
	void SetTextureColor(TextureId id, Uint8 r,Uint8 g, Uint8 b, Uint8 a);
	void SetTextureColor(TextureId id, Color::Enum color);
	//���������� ������ ��������
	int getTextureWidth(TextureId id);
	//���������� ������ ��������
	int getTextureHeight(TextureId id);
	//������� ��� ��������
	void DeleteAllTexture();

private:
	friend class Singleton<CTextureManager>;

	struct Texture
	{
		int w;
		int h;
		SDL_Texture* tex;
		std::string file;
		TextureId id;
	};

	typedef std::map< std::string, Texture > TexturesContainerByPath;
	typedef std::map< TextureId, Texture > TexturesContainerByID;
	TexturesContainerByPath textures_by_path_;
	TexturesContainerByID textures_by_id_;
	size_t last_id;

	void InsertTexture(Texture& texture);

protected:

	CTextureManager();
	virtual ~CTextureManager();
};