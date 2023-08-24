#include "Gerenciador_Jogador.h"


Gerenciador_Jogador::Gerenciador_Jogador(Bola * p_end_branca)
{
	p1.ID = 1;
	p1.pontuacao = 0;

	p2.ID = 2;
	p2.pontuacao = 0;
	atual = &p1;
	
	J = new Jogador(p_end_branca);

	jogou = false;

}

Gerenciador_Jogador::~Gerenciador_Jogador()
{
}

void Gerenciador_Jogador::Troca()
{
	if (atual->ID == 1)
	{
		atual = &p2;
	}
	else if (atual->ID == 2)
	{
		atual = &p1;
	}
}

void Gerenciador_Jogador::Update()
{
	J->Update();
}

void Gerenciador_Jogador::Pontuar(int p)
{
	atual->pontuacao += p;
}

