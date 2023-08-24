#pragma once
#include"Header.h"
class Bola;
class Gerenciador_Bolas
{
public:
	Gerenciador_Bolas();

	//std::vector<int> chupe;
	vector<Bola*> m_list_bolas;

	bool moveram;
	~Gerenciador_Bolas();
	void Cria_Bolas();
	void Update();
	Bola* GetElement(int index);
	int GetSize();
	bool Pararam();
	void SeMoveram();
	int Diminuiubola();
	int tamanhoatual;
};

