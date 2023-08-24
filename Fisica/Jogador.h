#pragma once
#include"Header.h"

class HUD;
class Taco;
class Bola;
class CameraPrincipal;

class Jogador
{
private:
	float xi, xf, yi, yf, forca_tacada;
	bool tacando;

	CameraPrincipal * m_camera;

	Taco * m_taco;
	
	Bola * m_end_branca;

	Vetor3D m_normal;

	int tecla_pressed;
	

	bool bateu;
public:
	bool terminoudejogar;
	MODO m_modo;

	Jogador(Bola * p_end_branca);
	~Jogador();

	void Modo_Espectador();
	void Modo_Ativo();
	void Update();
	void ProcessaComandos_Ativo();
	void ProcessaComandos_Espectador();
	void AnimaTaco();
	Vetor3D GetDirecao();
	Vetor3D GetDirecaoXZ();
	Vetor3D TacoBola;
	void SetTacoPos();
	float GetAnguloNovo();
	void m_tacada();

	void PosTaco();

	void InputMouse();
	void PuxaTaco();


	void EspectadorInicial();
	void AtivoInicial();



	void DimensionaHorto();
	void HUDJogador();
};

