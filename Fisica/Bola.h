#pragma once
#include "Primitivo.h"

class Primitivo;

class Objeto
{

public:
	Vetor3D m_posiçao;
	Vetor3D m_escala;
	Vetor3D m_quantidadeRot;
	Vetor3D m_goback;
	Primitivo * m_corpo;

	Objeto(){};

	void Draw();
	void Draw2();
	
};



class Bola : public Objeto
{
public:
	Bola(){};
	Bola(Vetor3D p_posiçao, float p_raio, int m_vertices, float p_massa);
	
	Vetor3D m_Impulso;
	Vetor3D m_velocidade;
	Vetor3D m_força;
	Vetor3D m_quantidadeMovA;
	Vetor3D m_quantidadeMov;
	Vetor3D m_energiaCinetica;

	void m_AquantidadeMov();

	float m_massa;
	float m_angulo;
	bool m_isMovi();
	Vetor3D m_GetEnergiacinetica();

	bool m_estacolidindo;


	float m_vertices;
	
	void m_andar(Vetor3D Impulso);
	void m_atualiza();
	void m_atualizaEnergia();

	~Bola();
};


class Paralelepipdo : public Objeto
{
public :
	Paralelepipdo(Vetor3D p_posiçao,Vetor3D p_escala);

};


class Sbox : public Objeto
{
public:
	Sbox(){};
	Sbox(Vetor3D p_posiçao, Vetor3D p_escala);
};


class Cilindro : public Objeto
{
	
public:
	
	Cilindro(){};
	Cilindro(Vetor3D p_posiçao, Vetor3D p_escala, int p_vertices,float r1, float r2);
	
};

class Cone : public Objeto
{

public:
	Cone(){};
	Cone(Vetor3D p_posiçao, Vetor3D p_escala, int p_vertices, float r1);

};

class Plane : public Objeto
{
public:
	Plane(){};
	Plane(Vetor3D p_posiçao, Vetor3D p_escala);
};
