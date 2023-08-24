#include "Particle_System.h"


Particle_System::Particle_System()
{
}

Particle_System::Particle_System(Vetor3D p_pos, Vetor3D p_rot, int p_max)
{
	m_posicao = p_pos;
	m_qtd_rotacao = p_rot;
	m_max_particles = p_max;

	m_max_p_acc =     3;
	m_min_p_acc =    -3;
	m_min_p_speed = -10;
	m_max_p_speed =  10;
	
	start = false;
}

Particle_System::~Particle_System()
{
}

void Particle_System::Update()
{	
	if (start)
	{
		if (m_particle_count < m_max_particles)
		{
			AddParticle_Explosion();
			m_particle_count++;
		}
		//for (std::vector<Particle*>::iterator it = m_list.begin(); it != m_list.end(); it++)
		//{
		//	Particle * p = *it;
		//	p->Update();
		//	if (p->IsDead())
		//		//delete(&*it);
		//	 m_list.erase(it);
		//}
		for (int i = 0; i < m_list.size(); i++)
		{

			m_list[i]->Update();

			if (m_list[i]->IsDead())
				//delete(&*it);
				m_list.erase(m_list.begin() + i);
		}
		/*for (int i = 0; i < m_list.size(); i++)
		{
		m_list[i].Update();

		if (m_list[i].IsDead())
		{
		m_list.erase(m_list.at(i));
		}
		}*/


		if (m_list.size() == 0)
		{
			start = false;
			//Reset();
		}
	}

}

void Particle_System::AddParticle_Explosion()
{

	Vetor3D dir;
	dir.m_X = rand() % 360 - 360;
	dir.m_Y = rand() % 360 - 360;
	dir.m_Z = rand() % 360 - 360;


	Vetor3D vetor_s = dir.m_Normalizaçao();
	vetor_s *= rand() % m_max_p_speed ;

	Vetor3D vetor_a(rand() % 2, rand() % 2, rand() % 2);
	vetor_a *= rand() % m_max_p_acc - m_min_p_acc;

	Particle * addit = new Particle(m_posicao, vetor_s, vetor_a,base_material);

	m_list.push_back(addit);
}
void Particle_System::AddParticle_StraightLine()
{
	
	Vetor3D vetor_s = m_qtd_rotacao;
	vetor_s *= rand() % m_max_p_speed - m_min_p_speed;

	Vetor3D vetor_a(rand() % 2, rand() % 2, rand() % 2);
	vetor_a *= rand() % m_max_p_acc - m_min_p_acc;

	Particle * addit = new Particle(m_posicao, vetor_s, vetor_a,base_material);

	m_list.push_back(addit);
}

void Particle_System::SetSystem(int s_min = -10, int s_max = 10, int a_min = -3, int a_max = 3)
{
	m_max_p_acc = a_max;
	m_min_p_acc = a_min;
	m_min_p_speed = s_min;
	m_max_p_speed = s_max;
}


void Particle_System::Iniciar(Materials p_material)
{
	start = true;
	Reset();
	base_material = p_material;
}


void Particle_System::Reset()
{
	m_particle_count = 0;
}

