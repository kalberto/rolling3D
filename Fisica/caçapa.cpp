#include "caçapa.h"


caçapa::caçapa()
{
	m_Criacaçapas();
}


caçapa::~caçapa()
{
}

void caçapa::m_Criacaçapas()
{
	Bola* m_caçapa = new Bola(Vetor3D(21, 10, 0),4, 20, 0);//0
	m_caçapas.push_back(m_caçapa);
	m_caçapa = new Bola(Vetor3D(21, 10, 43), 4, 20, 0);//1
	m_caçapas.push_back(m_caçapa);
	m_caçapa = new Bola(Vetor3D(21, 10, -43), 4, 20, 0);//2
	m_caçapas.push_back(m_caçapa);
	m_caçapa = new Bola(Vetor3D(-21, 10, 0), 4, 20, 0);//3
	m_caçapas.push_back(m_caçapa);
	m_caçapa = new Bola(Vetor3D(-21, 10, 43), 4, 20, 0);//4
	m_caçapas.push_back(m_caçapa);
	m_caçapa = new Bola(Vetor3D(-21, 10, -43), 4, 20, 0);//5
	m_caçapas.push_back(m_caçapa);

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
void caçapa::m_draw()
{
	for (int i = 0; i < m_caçapas.size(); i++)
	{
		m_caçapas[i]->Draw();
	}
}


void caçapa::SistemaUpdate(){

	for (int i = 0; i < m_sistemas.size(); i++)
	{
		m_sistemas[i]->Update();
	}
}

