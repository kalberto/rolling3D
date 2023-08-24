#pragma once
#include"Header.h"
#include"Player.h"
class Plane;
class HUD
{
private:
	bool tacando;
	int xi, xf, yi, yf;
	int m_jogador;
	bool mostra_aura;
public:
	Plane * m_barra;
	Plane * m_medidor;
	Plane * m_playername;
	Plane * pontuacao;
	Plane * EE1;
	HUD();
	~HUD();


	void Set_Ortographic_Mode();
	void Update(MODO estado);
	void Update(MODO estado,Player& jogador);
	void InputMouse();
	void atualizapontuacao(int p);

	void AnnounceWinner(TEXTURA txt);
	//void DimensionaPersp(int w, int h)
	//{
	//	int Altura = w;
	//	int Largura = h;

	//	float   CampoVisao = 90.0f;

	//	float Aspecto = (float)Altura / (float)Largura;

	//	glViewport(-((Largura - SCREEN_WIDTH) / 2), -((Altura - SCREEN_HEIGHT) / 2), Altura, Largura);
	//	glMatrixMode(GL_PROJECTION);
	//	glLoadIdentity();
	//	player->camera->perspectiveMatrix.SetPerspectiveFovRH(CampoVisao / 2, Aspecto, 0.1f, 15000.0f);

	//	glLoadMatrixf(player->camera->perspectiveMatrix);

	//	glMatrixMode(GL_MODELVIEW);
	//	glLoadIdentity();

	//}

	void DimensionaHorto();

};

