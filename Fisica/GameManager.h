#pragma once
#include"Gerenciador_Bolas.h"
#include"Gerenciador_Jogador.h"
#include"HUD.h"
#include"Fisica.h"
#include"caçapa.h"
#include<thread>
class GameManager
{
private:
	Gerenciador_Bolas * G_B;
	Gerenciador_Jogador * G_J;

	Fisica fisica;
	Superficie m_super;
	Superficie m_agua;
	caçapa my_cacapa;

	std::thread * th;

	std::vector<Paralelepipdo*> m_list_lagos;


	HUD * m_hud;

	Mesa * novamesa;
	Skybox * WORLD;
	Lampada  * luminaria;

	int somabolas;
	bool Usa_Agua;
public:
	GameManager();
	~GameManager();
	void UpdatePrincipal();
	void UpdateSecundario();
	void CriaMundo();
	void DesenhaMundo();
	void Check_Cheats();

	void CriaAgua(int n);
	void DesenhaAgua();

};

