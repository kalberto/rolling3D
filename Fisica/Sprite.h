#pragma once
#include"Header.h"
class Sprite
{
private:
	SDL_Renderer * m_renderer;
	SDL_Rect * m_rect;
	SDL_Texture * m_texture;
public:
	Sprite();
	Sprite(SDL_Renderer * p_r,char nome[]);
	~Sprite();

	void SetRect(int p_x, int p_y, int p_w, int p_h);

	void Draw();
	void Colide(int p_x,int p_y);
};

