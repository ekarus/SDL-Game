#pragma once
#include <string>
#include <SDL.h>
#include <map>

class CTextureManager
{
public:
	//���������� ��������� �� ��������� ���������
	static CTextureManager* getInst()
	{
		static CTextureManager inst;
		return &inst;
	}
	//��������� �������� �� ����� � ���������� ��, 0 - ���� ������
	Uint32 LoadTexture(std::string file);
	//������� �������� ��������
	void DeleteTexture(Uint32 id);
	//������ �������� � ����� �,� � ������� w, ������� h � ����� �������� angle
	void DrawTexture(Uint32 id,int x,int y,int w,int h, int angle=0);
	//������ �������� ����� �������� (x2,y2,w2,h2) � ����� �,� � ������� w, ������� h � ����� �������� angle
	void DrawTexture(Uint32 id,int x,int y,int w,int h, int x2,int y2, int w2,int h2 ,int angle=0);
	//������������� ���� ��� �������� �������� � ������� RGBA
	void SetTextureColor(Uint8 r,Uint8 g, Uint8 b, Uint8 a);
	//���������� ������ ��������
	int getTextureWidth(Uint32 id);
	//���������� ������ ��������
	int getTextureHeight(Uint32 id);
	//������� ��� ��������
	void DeleteAllTexture();

private:
	std::map< Uint32, SDL_Texture > m_Textures;
};