#include "Sprite.h"



Sprite::Sprite()
{

}

Sprite::Sprite(SDL_Renderer * p_r, char nome[])
{
	m_rect = new SDL_Rect();
	
}


Sprite::~Sprite()
{
}



void Sprite::SetRect(int p_x, int p_y, int p_w, int p_h){}
void Sprite::Draw(){}
void Sprite::Colide(int p_x, int p_y){}