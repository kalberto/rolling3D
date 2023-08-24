#pragma once

#include<stdio.h>
#include<SDL.h>
#include<SDL_image.h>
#include<iostream>

class Input
{

private:

	const Uint8 * m_key;
	Uint32  m_mouse;
	bool esquerda_pressionado;
	bool direita_pressionado;
	int  m_mouse_x;
	int  m_mouse_y;

public:
	
	Input(){};
	void Create()
	{
		esquerda_pressionado = direita_pressionado = false;	
	}
	//~Input();

	void Update_Key_Event()
	{
		SDL_PumpEvents();

		m_key = SDL_GetKeyboardState(NULL);
	}
	void Update_Mouse_Event()
	{
		SDL_PumpEvents();

		m_mouse = SDL_GetMouseState(&m_mouse_x,&m_mouse_y);
	}

	int RegisterKeyKode()
	{
		Update_Key_Event();

		
			if (m_key[SDL_SCANCODE_LEFT])
			{
				return 0;
			}
			else if (m_key[SDL_SCANCODE_RIGHT])
			{
				return 1;
			}
			else if (m_key[SDL_SCANCODE_UP])
			{
				return 2;
			}
			else if (m_key[SDL_SCANCODE_DOWN])
			{
				return 3;
			}
			else if (m_key[SDL_SCANCODE_SPACE])
			{
				return 4;
			}
			else if (m_key[SDL_SCANCODE_A])
			{
				return 5;
			}
			else if (m_key[SDL_SCANCODE_S])
			{
				return 6;
			}
			else if (m_key[SDL_SCANCODE_D])
			{
				return 7;
			}
			else if (m_key[SDL_SCANCODE_W])
			{
				return 8;
			}
			else if (m_key[SDL_SCANCODE_B])
			{
				return 9;
			}
			else if (m_key[SDL_SCANCODE_C])
			{
				return 10;
			}

			else if (m_key[SDL_SCANCODE_E])
			{
				return 11;
			}
			else if (m_key[SDL_SCANCODE_F])
			{
				return 12;
			}
			else if (m_key[SDL_SCANCODE_G])
			{
				return 13;
			}
			else if (m_key[SDL_SCANCODE_H])
			{
				return 14;
			}
			else if (m_key[SDL_SCANCODE_I])
			{
				return 15;
			}
			else if (m_key[SDL_SCANCODE_J])
			{
				return 16;
			}
			else if (m_key[SDL_SCANCODE_K])
			{
				return 17;
			}
			else if (m_key[SDL_SCANCODE_L])
			{
				return 18;
			}
			else if (m_key[SDL_SCANCODE_M])
			{
				return 19;
			}
			else if (m_key[SDL_SCANCODE_N])
			{
				return 20;
			}
			else if (m_key[SDL_SCANCODE_O])
			{
				return 21;
			}
			else if (m_key[SDL_SCANCODE_P])
			{
				return 22;
			}
			else if (m_key[SDL_SCANCODE_Q])
			{
				return 23;
			}
			else if (m_key[SDL_SCANCODE_R])
			{
				return 24;
			}

			else if (m_key[SDL_SCANCODE_T])
			{
				return 25;
			}
			else if (m_key[SDL_SCANCODE_U])
			{
				return 26;
			}
			else if (m_key[SDL_SCANCODE_V])
			{
				return 27;
			}
			else if (m_key[SDL_SCANCODE_X])
			{
				return 28;
			}
			else if (m_key[SDL_SCANCODE_Y])
			{
				return 29;
			}
			else if (m_key[SDL_SCANCODE_Z])
			{
				return 30;
			}
			else if (m_key[SDL_SCANCODE_0])
			{
				return 31;
			}
			else if (m_key[SDL_SCANCODE_1])
			{
				return 32;
			}
			else if (m_key[SDL_SCANCODE_2])
			{
				return 33;
			}
			else if (m_key[SDL_SCANCODE_3])
			{
				return 34;
			}
			else if (m_key[SDL_SCANCODE_4])
			{
				return 35;
			}
			else if (m_key[SDL_SCANCODE_5])
			{
				return 36;
			}
			else if (m_key[SDL_SCANCODE_6])
			{
				return 37;
			}
			else if (m_key[SDL_SCANCODE_7])
			{
				return 38;
			}
			else if (m_key[SDL_SCANCODE_8])
			{
				return 39;
			}
			else if (m_key[SDL_SCANCODE_9])
			{
				return 40;
			}
			else
				return 5000;
		
	}

	bool Mouse_Left_Is_Pressed()
	{
		return getInstance().esquerda_pressionado;
	}

	bool Mouse_Right_Is_Pressed()
	{
		return getInstance().direita_pressionado;
	}

	int RegisterMouse()
	{
		Update_Mouse_Event();

			switch (m_mouse)
			{
			case SDL_BUTTON_LEFT:
				getInstance().esquerda_pressionado = true;
				return 0;
				break;
			case SDL_BUTTON_RIGHT:
				getInstance().direita_pressionado = true;
				return 1;
				break;
			default:
				getInstance().esquerda_pressionado = false;
				getInstance().direita_pressionado = false;
				break;
			}			

			
	}
	int Get_Mouse_X()
	{
		return getInstance().m_mouse_x;
	}
	int Get_Mouse_Y()
	{
		return getInstance().m_mouse_y;
	}

	static Input & getInstance()
	{
		static Input input;

		return input;
	}
	
	
};

