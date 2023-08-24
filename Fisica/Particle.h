#pragma once
#include"Header.h"

class Bola;

class Particle
{
private:
	Bola * m_corpo;
	Vetor3D m_velocity;
	Vetor3D m_acceleration;
	float m_lifespan;


public:
	
	Particle();
	Particle(Vetor3D p_pos, Vetor3D p_v, Vetor3D m_a, Materials p_material);
	~Particle();
	void Update();

	bool IsDead();
};

