#include "ca�apa.h"


ca�apa::ca�apa()
{
	m_Criaca�apas();
}


ca�apa::~ca�apa()
{
}

void ca�apa::m_Criaca�apas()
{
	Bola* m_ca�apa = new Bola(Vetor3D(21, 10, 0),4, 20, 0);//0
	m_ca�apas.push_back(m_ca�apa);
	m_ca�apa = new Bola(Vetor3D(21, 10, 43), 4, 20, 0);//1
	m_ca�apas.push_back(m_ca�apa);
	m_ca�apa = new Bola(Vetor3D(21, 10, -43), 4, 20, 0);//2
	m_ca�apas.push_back(m_ca�apa);
	m_ca�apa = new Bola(Vetor3D(-21, 10, 0), 4, 20, 0);//3
	m_ca�apas.push_back(m_ca�apa);
	m_ca�apa = new Bola(Vetor3D(-21, 10, 43), 4, 20, 0);//4
	m_ca�apas.push_back(m_ca�apa);
	m_ca�apa = new Bola(Vetor3D(-21, 10, -43), 4, 20, 0);//5
	m_ca�apas.push_back(m_ca�apa);

	Particle_System* sistema = new Particle_System(Vetor3D(21, 15, 0), Vetor3D(90, 90, 0), 40);//0
	m_sistemas.push_back(sistema);
	sistema = new Particle_System(Vetor3D(21, 15, 43), Vetor3D(90, 90, 0), 40);//1
	m_sistemas.push_back(sistema);
	sistema = new Particle_System(Vetor3D(21, 15, -43), Vetor3D(90, 90, 0), 40);//2
	m_sistemas.push_back(sistema);
	sistema = new Particle_System(Vetor3D(-21, 15, 0), Vetor3D(90, 90, 0), 40);//3
	m_sistemas.push_back(sistema);
	sistema = new Particle_System(Vetor3D(-21, 15, 43), Vetor3D(90, 90, 0), 40);//4
	m_sistemas.push_back(sistema);
	sistema = new Particle_System(Vetor3D(-21, 15, -43), Vetor3D(90, 90, 0), 40);//5
	m_sistemas.push_back(sistema);

}
void ca�apa::m_draw()
{
	for (int i = 0; i < m_ca�apas.size(); i++)
	{
		m_ca�apas[i]->Draw();
	}
}


void ca�apa::SistemaUpdate(){

	for (int i = 0; i < m_sistemas.size(); i++)
	{
		m_sistemas[i]->Update();
	}
}

