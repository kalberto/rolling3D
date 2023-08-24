#include "Bola.h"


/////////////////////CLASSE OBJETO

void Objeto::Draw()
{
	
	glPushMatrix();
	//glLoadIdentity();
	glTranslatef(m_posiçao.m_X, m_posiçao.m_Y, m_posiçao.m_Z); 
	//glTranslatef(m_corpo->m_pos->m_X, m_corpo->m_pos->m_Y, m_corpo->m_pos->m_Z);
	//std::cout << "X : " << m_posiçao.m_X << "  Y :  " << m_posiçao.m_Y << "  Z :  " << m_posiçao.m_Z<<std::endl;
	glRotatef(m_quantidadeRot.m_X*180/PI, 1, 0, 0);
	glRotatef(m_quantidadeRot.m_Y, 0, 1, 0);
	glRotatef(m_quantidadeRot.m_Z*180/PI, 0, 0, 1);
	glScalef(m_escala.m_X, m_escala.m_Y, m_escala.m_Z);
	m_corpo->Draw();
	glPopMatrix();
	//glPopMatrix();
}

void Objeto::Draw2()
{

	glPushMatrix();
	//glLoadIdentity();


	glTranslatef(m_posiçao.m_X, m_posiçao.m_Y, m_posiçao.m_Z);

	glRotatef(m_quantidadeRot.m_X * 180 / PI, 1, 0, 0);
	glRotatef(m_quantidadeRot.m_Y, 0, 1, 0);
	glRotatef(m_quantidadeRot.m_Z * 180 / PI, 0, 0, 1);
	//glTranslatef(m_corpo->m_pos->m_X, m_corpo->m_pos->m_Y, m_corpo->m_pos->m_Z);
	//std::cout << "X : " << m_posiçao.m_X << "  Y :  " << m_posiçao.m_Y << "  Z :  " << m_posiçao.m_Z<<std::endl;
	glTranslatef(m_goback.m_X, m_goback.m_Y, m_goback.m_Z);

	glScalef(m_escala.m_X, m_escala.m_Y, m_escala.m_Z);
	m_corpo->Draw();
	glPopMatrix();
	//glPopMatrix();
}



///////////////////// CLASSE BOLA




Bola::Bola(Vetor3D p_posiçao,float p_raio, int p_vertices, float p_massa)
{
	m_posiçao = p_posiçao;
	m_escala = Vetor3D(p_raio,p_raio,p_raio);
	m_vertices = p_vertices;
	m_massa = p_massa;
	m_corpo = new Sphere(m_vertices, m_vertices);
	m_corpo->UseTexture(false);
	m_estacolidindo = false;
}


Bola::~Bola()
{
}

Vetor3D Bola::m_GetEnergiacinetica()
{
	m_energiaCinetica = Vetor3D(m_velocidade.m_X*m_velocidade.m_X*m_massa / 2, m_velocidade.m_Y*m_velocidade.m_Y*m_massa / 2, m_velocidade.m_Z*m_velocidade.m_Z*m_massa / 2);
	return m_energiaCinetica;
}

void Bola::m_AquantidadeMov()
{
	m_quantidadeMov = m_velocidade*m_massa;
}

void Bola::m_atualizaEnergia()
{
	float massa = 1 / m_massa *2;
	float x = 1, y = 1, z = 1;
	Vetor3D Nvelocidade = m_velocidade;
	m_energiaCinetica *= massa;
	if (m_energiaCinetica.m_X < 0)
	{
		x = -1;
	}
	if (m_energiaCinetica.m_Y < 0)
	{
		y = -1;
	}
	if (m_energiaCinetica.m_Z < 0)
	{
		z = -1;
	}
	Nvelocidade.m_X = sqrt(m_energiaCinetica.m_X*x); Nvelocidade.m_Y = sqrt(m_energiaCinetica.m_Y*y); Nvelocidade.m_Z = sqrt(m_energiaCinetica.m_Z*z);

	Nvelocidade.m_X *= x; Nvelocidade.m_Y *= y; Nvelocidade.m_Z *= z;
	m_velocidade = Nvelocidade;

	if (m_velocidade.m_MaginitudeVetor3D() < 0.001)
	{
		m_velocidade.m_X = m_velocidade.m_Y = m_velocidade.m_Z = 0;
	}

}

void Bola::m_atualiza()
{
	
	//m_atualizaEnergia();
	float massa = 1 / m_massa;
	
	//m_Impulso.m_X += m_força.m_X; m_Impulso.m_Y += m_força.m_Y; m_Impulso.m_Z += m_força.m_Z;
	if (m_força.m_MaginitudeVetor3D() != 0)
	{
		m_velocidade += m_força*massa;
		m_força.m_X = 0; m_força.m_Y = 0; m_força.m_Z = 0;
	}
	Vetor3D menor0 = m_velocidade;
	menor0.m_X += m_Impulso.m_X; menor0.m_Y += m_Impulso.m_Y; menor0.m_Z += m_Impulso.m_Z;
	m_posiçao.m_X += m_velocidade.m_X; m_posiçao.m_Y += m_velocidade.m_Y; m_posiçao.m_Z+= m_velocidade.m_Z;
	m_velocidade.m_Y = 0;
	
	if (m_velocidade.m_X > 0 && menor0.m_X < 0)
	{
		menor0.m_X = 0;
	}
	if (m_velocidade.m_X < 0 && menor0.m_X > 0)
	{
		menor0.m_X = 0;
	}
	if (m_velocidade.m_Z > 0 && menor0.m_Z < 0)
	{
		menor0.m_Z = 0;
	}
	if (m_velocidade.m_Z < 0 && menor0.m_Z > 0)
	{
		menor0.m_Z = 0;
	}
	m_velocidade = menor0;

	if (m_velocidade.m_MaginitudeVetor3D() < 0.01)
	{
		m_velocidade.m_X = m_velocidade.m_Y = m_velocidade.m_Z = 0;
	}

	//m_quantidadeRot.m_X = m_velocidade.m_Z / m_escala.m_X;
	//m_quantidadeRot.m_Z = m_velocidade.m_X / m_escala.m_Z;

}



bool Bola::m_isMovi()
{
	if (m_velocidade.m_MaginitudeVetor3D() == 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}


////////////////////CLASSE PARALELEPIPEDO


Paralelepipdo::Paralelepipdo(Vetor3D p_posiçao, Vetor3D p_escala)
{
	m_posiçao = p_posiçao;
	m_posiçao.m_W = 1;
	m_escala = p_escala;
	m_quantidadeRot = Vetor3D(0,0,0);

	m_corpo = new Cubo();
}

////////////////SBOX


Sbox::Sbox(Vetor3D p_posiçao, Vetor3D p_escala)
{
	m_posiçao = p_posiçao;
	m_posiçao.m_W = 1;
	m_escala = p_escala;
	m_quantidadeRot = Vetor3D(0, 0, 0);

	m_corpo = new Sky();
}

/////////////////CILINDRO
Cilindro::Cilindro(Vetor3D p_posiçao, Vetor3D p_escala,int p_vertices, float r1, float r2)
{
	m_posiçao = p_posiçao;
	m_posiçao.m_W = 1;
	m_escala = p_escala;
	m_quantidadeRot = Vetor3D(0, 0, 0);

	m_corpo = new Cylinder(p_vertices,r1,r2);
}

/////////////// CONE 
Cone::Cone(Vetor3D p_posiçao, Vetor3D p_escala, int p_vertices, float r1)
{
	m_posiçao = p_posiçao;
	m_posiçao.m_W = 1;
	m_escala = p_escala;
	m_quantidadeRot = Vetor3D(0, 0, 0);

	m_corpo = new Piramide(p_vertices);
}

/////////////////////PLANE


Plane::Plane(Vetor3D p_posiçao, Vetor3D p_escala)
{
	m_corpo = new Quadrado();
	m_posiçao = p_posiçao;
	m_escala = p_escala;
	m_quantidadeRot = Vetor3D(0,0,0);

}

