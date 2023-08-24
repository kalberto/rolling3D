#pragma once
#include"Particle.h"


class Particle;
class Particle_System
{
private:
	int m_min_p_speed, m_max_p_speed;
	int m_min_p_acc, m_max_p_acc;
	int m_particle_count;
	int m_max_particles;
	Materials base_material;
	Vetor3D m_posicao;
	Vetor3D m_qtd_rotacao;
	std::vector<Particle*> m_list;

	bool start;

	
public:
	Particle_System();
	Particle_System(Vetor3D p_pos,Vetor3D p_rot,int p_max);
	void SetSystem(int s_min,int s_max,int a_min,int a_max);
	~Particle_System();

	void AddParticle_StraightLine();
	void AddParticle_Explosion();
	void Update();

	void Iniciar(Materials p_material);
	void Reset();
};

