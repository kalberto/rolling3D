#pragma once
#include "Header.h"

class Particle_System;
class caçapa
{
public:

	vector<Bola*> m_caçapas;
	void m_Criacaçapas();

	vector<Bola*> m_dentrocaçapa;
	void m_draw();

	vector<Particle_System*> m_sistemas;

	void SistemaUpdate();

	caçapa();
	~caçapa();
};

