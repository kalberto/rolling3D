#include "Menu.h"


Menu::Menu()
{

}


Menu::~Menu()
{
}



void Menu::Update(SDL_Renderer * render)
{




}

void Menu::CheckButton_List()
{
	for (int i = 0; i < qtdbotoes;i++)
	{


	}


}

void Menu::GetMouseInput()
{
	
	if (!m_Input->RegisterMouse())
	{
		mousex = m_Input->Get_Mouse_X();
		mousey = m_Input->Get_Mouse_Y();
	}


}

void Menu::Acoes(int botao)
{



}