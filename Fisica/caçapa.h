#pragma once
#include "Header.h"

class Particle_System;
class ca�apa
{
public:

	vector<Bola*> m_ca�apas;
	void m_Criaca�apas();

	vector<Bola*> m_dentroca�apa;
	void m_draw();

	vector<Particle_System*> m_sistemas;

	void SistemaUpdate();

	ca�apa();
	~ca�apa();
};

