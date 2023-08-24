#pragma once
#include "Header.h"
class Bola;
class Superficie;
class Objeto;
class Gerenciador_Bolas;
class Camera;
class caçapa;
class Mesa;

class Fisica
{
public:
	Fisica();

	float m_gravidade;

	void m_caçapas(Gerenciador_Bolas* p_Bolas, caçapa* p_caçapa);
	void Colisaocacapa_Melhorada(Gerenciador_Bolas* p_Bolas, caçapa* p_caçapa);


	void m_AplicaAtritoDinâmico(Gerenciador_Bolas* p_Bolas, Superficie p_Superficie);
	void m_ReflexãoParede(Bola* p_Bola, Vetor3D p_posição);
	void m_colisaoParedes(Bola* p_Bola, Objeto p_partedeCima);
	void m_VerificaColisãoParede(Gerenciador_Bolas* p_Bolas, int p_quantidade);
	void m_VerificaColisãoBolas(Gerenciador_Bolas* p_Bolas);
	void m_colisaoBola(Bola* p_Bola1, Bola* p_Bola2);	

	void m_colisaomelhoradaBolas(Gerenciador_Bolas* p_Bolas, int p_verificador, int p_quantidade, int* p_array);
	Vetor3D m_retornaMQ(Bola* p_Bola, float p_cos, Vetor3D p_QM);


	void m_VerificaColisãoParedes(Gerenciador_Bolas * p_Bola, Mesa * mesa);

	void m_ColisaoBolas(Gerenciador_Bolas* p_Bolas,int p_verificador, int p_quantidade, int* p_array);


	float m_getAngulocolisao(Bola* p_Bola, Vetor3D p_Normal);

	Vetor3D m_refletirEnergia(Bola* p_Bola,Vetor3D p_vetor, Vetor3D p_Normal);

	void m_colisoesBolas(Bola* p_Bola1, Bola* p_Bola2);
	Vetor3D m_GetEnergiaCinetica(Bola* p_Bola, float p_cos);


	Vetor3D m_calculaNormal(Vetor3D p_ponto, Objeto p_colider);

	bool SphereCollisionCheck(Objeto * primeiro, Objeto * segundo);

	bool SphereBoxCollisionChck(Objeto * cubo, Objeto * esfera);

	void m_AplicaAtritoDinâmicoSolo(Bola * p_Bola, Superficie p_Superficie);
	~Fisica();
};

