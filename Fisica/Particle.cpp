#include "Particle.h"


Particle::Particle()
{
}
Particle::Particle(Vetor3D p_pos, Vetor3D p_v, Vetor3D p_a, Materials p_material)
{
	m_velocity = p_v;
	m_acceleration = p_a;
	m_corpo = new Bola(p_pos, 0.5f, 10, 1);

	//m_corpo->m_corpo->SetMaterial(Cor(0, 0, 0, 1), Cor(0, 0, 1, 1), Cor(0, 0, 0, 1), Cor(0, 0, 0, 1), 0.1f, 3);
	m_corpo->m_corpo->m_mesh->m_material = p_material;
	m_lifespan = 50;
}


Particle::~Particle()
{
}
void Particle::Update()
{
	m_velocity += m_acceleration  * Time::GetDeltaTime();
	m_corpo->m_posiçao += m_velocity * Time::GetDeltaTime();
	
	m_lifespan -= 2;
	
	m_corpo->Draw();
}

bool Particle::IsDead()
{
	if (m_lifespan <= 0)
	{
		return true;
	}
	return false;
}