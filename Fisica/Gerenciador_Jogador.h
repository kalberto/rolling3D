#pragma once
#include"Jogador.h"
#include"Player.h"

class Gerenciador_Jogador
{
public:
	Player p1, p2;
	Player * atual;
	Jogador *J;

	bool jogou;
	void Update();
	void Troca();
	void Pontuar(int p);


	Gerenciador_Jogador(Bola * p_end_branca);
	~Gerenciador_Jogador();
};

