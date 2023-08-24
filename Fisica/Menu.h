#pragma once
#include"Header.h"

class Menu
{
private:

	int qtdbotoes;
	Input * m_Input;
	int mousex, mousey;

public:
	Menu();
	~Menu();

	void Update(SDL_Renderer * render);

	void CheckButton_List();

	void GetMouseInput();

	void Acoes(int botao);



};

