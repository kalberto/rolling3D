#pragma once
#include"Mesh.h"
#include<math.h>
#include"MathUtil.h"
#include "Header.h"



using namespace std;
using namespace math;


class Primitivo
{
protected:
	
	
	


public:
	Vetor3D *  m_pos;
	Primitivo(){};
	Mesh * m_mesh;

	void Draw()
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

		//glBegin(GL_TRIANGLES);
		m_mesh->DrawMesh();
		//glEnd();
	}

	void UseTexture(bool b)
	{
		m_mesh->UsarTextura(b);
	}

	void SetAllTexture(int n)
	{
		m_mesh->Load_Pol_Texture(n);
	}

	void Set_Face_Texture(int f,int n)
	{
		m_mesh->GetFace(f).SetTexture(n);
	}

	void SetMaterial(Cor A, Cor E, Cor D, Cor S, float opacidade, float brilho)
	{
		m_mesh->SetMaterial(A,E,D,S,opacidade,brilho);
	}

};


class Triangulo : public Primitivo
{
private:

public:
	Triangulo( )
	{
		m_pos = new Vetor3D(0.0f, 0.0f, 0.0f);
		m_mesh = new Mesh(1);
		CriaMesh();
	}
	
	void CriaMesh()
	{
		Vetor3D v1(m_pos->m_X - 1, m_pos->m_Y - 1, m_pos->m_Z);
		Vetor3D v2(m_pos->m_X + 1, m_pos->m_Y - 1, m_pos->m_Z);
		Vetor3D v3(m_pos->m_X, m_pos->m_Y + 1, m_pos->m_Z);


		Poligon p1(3);
		p1.AddVertice(&v1);
		p1.AddVertice(&v2);
		p1.AddVertice(&v3);

		m_mesh->AddPoligon(p1);
	}

	void Update()
	{
		Draw();
	}

};

class Quadrado : public Primitivo
{
public:
	Quadrado( )
	{
		m_pos = new Vetor3D(0.0f, 0.0f, 0.0f);	
		m_mesh = new Mesh(1);
		CriaMesh();
	}
	void CriaMesh()
	{
		Vetor3D v1(m_pos->m_X - 1, m_pos->m_Y - 1, m_pos->m_Z);
		Vetor3D v2(m_pos->m_X + 1, m_pos->m_Y - 1, m_pos->m_Z);
		Vetor3D v3( m_pos->m_X+1 ,m_pos->m_Y+1 ,m_pos->m_Z);
		Vetor3D v4( m_pos->m_X-1 ,m_pos->m_Y+1 ,m_pos->m_Z);


		Poligon p1(4);
		p1.AddVertice(&v1);
		p1.AddVertice(&v2);
		p1.AddVertice(&v3);
		p1.AddVertice(&v4);

		m_mesh->AddPoligon(p1);
	}
	void Update()
	{
		Draw();
	}

};



class Circle : public Primitivo
{
private:
	float m_angle;
	int qtd_vert ;
	int m_frente;
	int m_cima;
	int m_lado;
public:
	Circle(  int numvertices, int frente, int cima, int lado)
	{
		m_pos = new Vetor3D(0.0f, 0.0f, 0.0f);		

		m_frente = frente;
		m_cima = cima;
		m_lado = lado;

		qtd_vert = numvertices;
		m_mesh = new Mesh(1);
		CriaMesh();
	}
	void CriaMesh()
	{
		float m_angle = 2*PI/qtd_vert;

		Poligon p1(qtd_vert + 2);
		
		Vetor3D * v;

		v = new Vetor3D( m_pos->m_X ,m_pos->m_Y ,m_pos->m_Z);
		p1.AddVertice(v);

		if(m_frente == 1 || m_lado == 1 || m_cima == 1)
		{
			for(float i = 0;i < 2*PI + m_angle;i += m_angle)
			{
				if(m_frente == 1)
				{
					v = new Vetor3D( m_pos->m_X - (cos(i) ) ,m_pos->m_Y - (sin(i) ) ,m_pos->m_Z);
				}

				else if(m_cima == 1)
				{
					v = new Vetor3D( m_pos->m_X - (cos(i) ) ,m_pos->m_Y ,m_pos->m_Z - (sin(i) ) );
				}
				else if(m_lado == 1)
				{
					v = new Vetor3D( m_pos->m_X ,m_pos->m_Y - (cos(i) ) ,m_pos->m_Z - (sin(i) ) );
				}
			
				p1.AddVertice(v);			
			}
		}
		else if(m_frente == -1 || m_lado == -1 || m_cima == -1)
		{
			for(float i = 0;i > -2*PI - m_angle;i -= m_angle)
			{
				if(m_frente == -1)
				{
					v = new Vetor3D( m_pos->m_X - (cos(i) ) ,m_pos->m_Y - (sin(i)) ,m_pos->m_Z);
				}
				else if(m_cima == -1)
				{
					v = new Vetor3D( m_pos->m_X - (cos(i) ) ,m_pos->m_Y  ,m_pos->m_Z - (sin(i) ));
				}
				else if(m_lado == -1)
				{
					v = new Vetor3D( m_pos->m_X ,m_pos->m_Y - (cos(i) )  ,m_pos->m_Z - (sin(i)));
				}
				p1.AddVertice(v);			
			}
		}

		
		m_mesh->AddPoligon(p1);
	}
	void Update()
	{
		Draw();
	}
};

class Cubo : public Primitivo
{
private:


public:

	Cubo( )
	{
		m_pos = new Vetor3D(0.0f, 0.0f, 0.0f);
		m_mesh = new Mesh(6);
		CriaMesh();
	}

	void CriaMesh()
	{
		Vetor3D v1( m_pos->m_X - 1 ,m_pos->m_Y - 1 ,m_pos->m_Z - 1);
		Vetor3D v2( m_pos->m_X + 1 ,m_pos->m_Y - 1 ,m_pos->m_Z - 1);
		Vetor3D v3( m_pos->m_X + 1 ,m_pos->m_Y + 1 ,m_pos->m_Z - 1);
		Vetor3D v4( m_pos->m_X - 1 ,m_pos->m_Y + 1 ,m_pos->m_Z - 1);
		Vetor3D v5( m_pos->m_X - 1 ,m_pos->m_Y - 1 ,m_pos->m_Z + 1);
		Vetor3D v6( m_pos->m_X + 1 ,m_pos->m_Y - 1 ,m_pos->m_Z + 1);
		Vetor3D v7( m_pos->m_X + 1 ,m_pos->m_Y + 1 ,m_pos->m_Z + 1);
		Vetor3D v8( m_pos->m_X - 1 ,m_pos->m_Y + 1 ,m_pos->m_Z + 1);
		

		Poligon p1(4);
		p1.AddVertice(&v4);
		p1.AddVertice(&v3);
		p1.AddVertice(&v2);
		p1.AddVertice(&v1);

		Poligon p2(4);
		p2.AddVertice(&v3);
		p2.AddVertice(&v7);
		p2.AddVertice(&v6);
		p2.AddVertice(&v2);

		Poligon p3(4);
		p3.AddVertice(&v7);
		p3.AddVertice(&v8);
		p3.AddVertice(&v5);
		p3.AddVertice(&v6);

		Poligon p4(4);
		p4.AddVertice(&v8);
		p4.AddVertice(&v4);
		p4.AddVertice(&v1);
		p4.AddVertice(&v5);

		Poligon p5(4);
		p5.AddVertice(&v8);
		p5.AddVertice(&v7);
		p5.AddVertice(&v3);
		p5.AddVertice(&v4);

		Poligon p6(4);
		p6.AddVertice(&v6);
		p6.AddVertice(&v5);
		p6.AddVertice(&v1);
		p6.AddVertice(&v2);

		m_mesh->AddPoligon(p1);
		m_mesh->AddPoligon(p2);
		m_mesh->AddPoligon(p3);
		m_mesh->AddPoligon(p4);
		m_mesh->AddPoligon(p5);
		m_mesh->AddPoligon(p6);

	}
	void Update()
	{
		Draw();
	}

};





class Piramide : public Primitivo
{
private:
	int m_qtd_vert;
	float m_rot_ang;
	
public:
	Piramide(){};
	Piramide(int p_num_vert)
	{
		m_qtd_vert = p_num_vert;
		m_pos = new Vetor3D(0.0f, 0.0f, 0.0f);
		m_mesh = new Mesh(m_qtd_vert * 2);
		m_rot_ang = (2 * PI) / m_qtd_vert;
		CriaMesh();
	}

	void CriaMesh()
	{
		Anel * anel;
		anel = new Anel(m_qtd_vert);


		/////// CALCULA VERTICES DO ANEL
		float X, Y, Z;
		float epi = math::FLOAT_DELTA;
		float c, s;
		float cosj, sinj;

		for (float j = 0; j < 2 * PI; j += m_rot_ang)
		{

			c = cos(j);
			s = sin(j);

			if (c > epi || c < -epi)
				cosj = c;
			else
				cosj = 0;

			if (s > epi || s < -epi)
				sinj = s;
			else
				sinj = 0;

			X = cosj;
			Y = 0;
			Z = sinj;
			anel->AddVert(X, Y, Z);
		}

		///////////CRIAR PARTE DE CIMA 


		for (int i = m_qtd_vert - 1; i >  0; i--)
		{
			Poligon p(3);

			p.AddVertice(new Vetor3D(0,1,0));
			p.AddVertice(anel->GetVert(i));
			p.AddVertice(anel->GetVert(i - 1));

			m_mesh->AddPoligon(p);
		}
		Poligon p(3);

		p.AddVertice(new Vetor3D(0, 1, 0));
		p.AddVertice(anel->GetVert(0));
		p.AddVertice(anel->GetVert(m_qtd_vert - 1));

		m_mesh->AddPoligon(p);


		///////////CRIAR PARTE DE BAIXO


		for (int i = 0; i < m_qtd_vert - 1; i++)
		{
			Poligon p(3);

			p.AddVertice(new Vetor3D(0, 0, 0));
			p.AddVertice(anel->GetVert(i));
			p.AddVertice(anel->GetVert(i + 1));

			m_mesh->AddPoligon(p);
		}

		Poligon t(3);

		t.AddVertice(new Vetor3D(0, 0, 0));
		t.AddVertice(anel->GetVert(m_qtd_vert - 1));
		t.AddVertice(anel->GetVert(0));

		m_mesh->AddPoligon(t);


	}

};

class Cylinder :public Primitivo
{
private:
	float m_height;
	float m_raio_cima;
	float m_raio_baixo;
	int num_circle_vert;
	float angle_rot;
	Anel ** m_aneis;


public:

	Cylinder(){};
	Cylinder(int qtd_vert_hori)
	{
		m_pos = new Vetor3D(0.0f,0.0f, 0.0f);
		m_height = 1;
		m_raio_cima = m_raio_baixo = 1;
		num_circle_vert = qtd_vert_hori;
		angle_rot = (2 * PI) / num_circle_vert;
		m_aneis =  new Anel*[2];
		m_mesh = new Mesh(3 * num_circle_vert);
		CriaMesh();
	}
	Cylinder(int qtd_vert_hori, float p_raio_cima, float p_raio_baixo)
	{
		m_pos = new Vetor3D(0.0f, 0.0f, 0.0f);
		m_height = 1;
		m_raio_cima = p_raio_cima;
		m_raio_baixo = p_raio_baixo;
		num_circle_vert = qtd_vert_hori;
		angle_rot = (2 * PI) / num_circle_vert;
		m_aneis = new Anel*[2];
		m_mesh = new Mesh(3 * num_circle_vert);
		CriaMesh();
	}

	void Cria_Cima()
	{
		m_aneis[0] = new Anel(num_circle_vert);

		float X, Y, Z;

		float epi = math::FLOAT_DELTA;
		float c, s;
		float cosj, sinj;

		for (float j = 0; j < 2 * PI; j += angle_rot)
		{

			c = cos(j);
			s = sin(j);
			
			if (c > epi || c < -epi)
				cosj = c;
			else
				cosj = 0;
			
			if (s > epi || s < -epi)
				sinj = s;
			else
				sinj = 0;

			X = cosj * m_raio_cima;
			Y = 1;
			Z = sinj * m_raio_cima;
			m_aneis[0]->AddVert(X, Y, Z);
		}


		for (int i = num_circle_vert - 1; i > 0; i--)
		{
			Poligon  p(3);
			Vetor3D v1(0, 1, 0);
			Vetor3D v2(m_aneis[0]->GetVert(i)->m_X, m_aneis[0]->GetVert(i)->m_Y, m_aneis[0]->GetVert(i)->m_Z);
			Vetor3D v3(m_aneis[0]->GetVert(i - 1)->m_X, m_aneis[0]->GetVert(i - 1)->m_Y, m_aneis[0]->GetVert(i - 1)->m_Z);

			p.AddVertice(&v1);
			p.AddVertice(&v2);
			p.AddVertice(&v3);

			m_mesh->AddPoligon(p);
		}

		Poligon  p(3);
		Vetor3D v1(0, 1, 0);
		Vetor3D v2(m_aneis[0]->GetVert(0)->m_X, m_aneis[0]->GetVert(0)->m_Y, m_aneis[0]->GetVert(0)->m_Z);
		Vetor3D v3(m_aneis[0]->GetVert(num_circle_vert - 1)->m_X, m_aneis[0]->GetVert(num_circle_vert - 1)->m_Y, m_aneis[0]->GetVert(num_circle_vert - 1)->m_Z);

		p.AddVertice(&v1);
		p.AddVertice(&v2);
		p.AddVertice(&v3);

		m_mesh->AddPoligon(p);

		
	}
	void Cria_Baixo()
	{
		m_aneis[1] = new Anel(num_circle_vert);

		float X, Y, Z;

		float epi = math::FLOAT_DELTA;
		float c, s;
		float cosj, sinj;

		for (float j = 0; j < 2 * PI; j += angle_rot)
		{

			c = cos(j);
			s = sin(j);

			if (c > epi || c < -epi)
				cosj = c;
			else
				cosj = 0;

			if (s > epi || s < -epi)
				sinj = s;
			else
				sinj = 0;

			X = cosj * m_raio_baixo;
			Y = -1;
			Z = sinj * m_raio_baixo;
			m_aneis[1]->AddVert(X, Y, Z);
		}

		for (int i = 0; i < num_circle_vert - 1; i++)
		{
			Poligon  p(3);
			Vetor3D v1(0, -1, 0);
			Vetor3D v2(m_aneis[1]->GetVert(i)->m_X, m_aneis[1]->GetVert(i)->m_Y, m_aneis[1]->GetVert(i)->m_Z);
			Vetor3D v3(m_aneis[1]->GetVert(i + 1)->m_X, m_aneis[1]->GetVert(i + 1)->m_Y, m_aneis[1]->GetVert(i + 1)->m_Z);

			p.AddVertice(&v1);
			p.AddVertice(&v2);
			p.AddVertice(&v3);

			m_mesh->AddPoligon(p);
		}

		Poligon  p(3);
		Vetor3D v1(0, -1, 0);
		Vetor3D v2(m_aneis[1]->GetVert(num_circle_vert - 1)->m_X, m_aneis[1]->GetVert(num_circle_vert - 1)->m_Y, m_aneis[1]->GetVert(num_circle_vert - 1)->m_Z);
		Vetor3D v3(m_aneis[1]->GetVert(0)->m_X, m_aneis[1]->GetVert(0)->m_Y, m_aneis[1]->GetVert(0)->m_Z);

		p.AddVertice(&v1);
		p.AddVertice(&v2);
		p.AddVertice(&v3);

		m_mesh->AddPoligon(p);


		
	}

	void CriaMesh()
		{
			Cria_Cima();
			Cria_Baixo();

			
			for (int i = num_circle_vert - 1; i > 0; i--)
			{
				Poligon  p(4);
				p.AddVertice( m_aneis[0]->GetVert(i));
				p.AddVertice( m_aneis[1]->GetVert(i));
				p.AddVertice( m_aneis[1]->GetVert(i - 1));
				p.AddVertice( m_aneis[0]->GetVert(i - 1));

				m_mesh->AddPoligon(p);
			}

			Poligon  p(4);
			p.AddVertice(m_aneis[0]->GetVert(0));
			p.AddVertice(m_aneis[1]->GetVert(0));
			p.AddVertice(m_aneis[1]->GetVert(num_circle_vert - 1));
			p.AddVertice(m_aneis[0]->GetVert(num_circle_vert - 1));

			m_mesh->AddPoligon(p);

		}
	};

class Sphere : public Primitivo
	{
	private:
		int vertical;
		int horizontal;
		float m_angle_vert;
		float m_angle_hori;
		int num_faces;
		Circle * cima;
		Circle * baixo;

		Anel ** m_aneis;
	public:

		Sphere(  int num_vert_vert, int num_vert_hori)
		{
			m_pos = new Vetor3D(0.0f, 0.0f, 0.0f);
			vertical = num_vert_vert;
			horizontal = num_vert_hori;

			m_angle_vert = PI / vertical;
			m_angle_hori = 2 * PI / horizontal;

			//num_faces = (horizontal * (vertical - 1)) + 2;
			num_faces = (horizontal * (vertical - 1)) + 2 * vertical;

			m_aneis = new Anel*[vertical];


			for (int i = 0; i < vertical; i++)
			{
				m_aneis[i] = new Anel(horizontal + 1);
			}



			m_mesh = new Mesh(num_faces);
			CriaMesh();
		}

		void CriaMesh()
		{
			/*float x_angle;
			float y_angle;*/


			Vetor3D cima(0, 1, 0);
			Vetor3D baixo(0, -1, 0);
			float X, Y, Z;

			float epi = math::FLOAT_DELTA;
			float cosi, sini, cosj, sinj;
			//Vetor3D * v;
			int anel = 0;
			for (float j = 0; j < PI; j += m_angle_vert)
			{

				//if(equals())

				for (float i = 0; i <= 2 * PI; i += m_angle_hori)
				{

					if (cos(i) > epi || cos(i) < -epi)
						cosi = cos(i);
					else
						cosi = 0;

					if (sin(i) > epi || sin(i) < -epi)
						sini = sin(i);
					else
						sini = 0;

					if (cos(j) > epi || cos(j) < -epi)
						cosj = cos(j);
					else
						cosj = 0;

					if (sin(j) > epi || sin(j) < -epi)
						sinj = sin(j);
					else
						sinj = 0;


					X =  sinj * cosi;
					Y =  cosj;
					Z =  sinj * sini;

					if (i == 0)
					{
						m_aneis[anel]->AddVertIn(horizontal, X, Y, Z);
					}

					m_aneis[anel]->AddVert(X, Y, Z);
					//v = new Vetor3D(X,Y,Z);
				}
				anel++;
			}



			Poligon *p;
			int qualanel = 0;
			//int count = 0;
			calcularcima(&cima);
			calcularbaixo(&baixo);
			for (int j = 0; j < vertical - 1; j++)
			{
				for (int i = horizontal; i > 0; i--)
				{

					p = new Poligon(4);






					Vetor3D * v1 = m_aneis[j + 1]->GetVert(i);
					Vetor3D * v2 = m_aneis[j + 1]->GetVert(i - 1);
					Vetor3D * v3 = m_aneis[j]->GetVert(i - 1);
					Vetor3D * v4 = m_aneis[j]->GetVert(i);




					p->AddVertice(v1);
					p->AddVertice(v2);
					p->AddVertice(v3);
					p->AddVertice(v4);

					m_mesh->AddPoligon(*p);

				}
			}

		}

		void calcularcima(Vetor3D * v)
		{
			Poligon * p;


			for (int i = horizontal; i > 0; i--)
			{
				p = new Poligon(3);
				Vetor3D * v1 = m_aneis[0]->GetVert(i);
				Vetor3D * v2 = m_aneis[0]->GetVert(i - 1);


				p->AddVertice(v);
				p->AddVertice(v1);
				p->AddVertice(v2);



				m_mesh->AddPoligon(*p);
			}
		}

		void calcularbaixo(Vetor3D * v)
		{
			Poligon * p;


			for (int i = horizontal; i > 0; i--)
			{
				p = new Poligon(3);
				Vetor3D * v1 = m_aneis[vertical - 1]->GetVert(i - 1);
				Vetor3D * v2 = m_aneis[vertical - 1]->GetVert(i);


				p->AddVertice(v);
				p->AddVertice(v1);
				p->AddVertice(v2);



				m_mesh->AddPoligon(*p);
			}
		}

		void Update()
		{
			Draw();
		}
	};




	class Sky : public Primitivo
	{
	private:


	public:

		Sky()
		{
			m_pos = new Vetor3D(0.0f, 0.0f, 0.0f);
			m_mesh = new Mesh(6);
			CriaMesh();
		}

		void CriaMesh()
		{
			Vetor3D v1(m_pos->m_X - 1, m_pos->m_Y - 1, m_pos->m_Z - 1);
			Vetor3D v2(m_pos->m_X + 1, m_pos->m_Y - 1, m_pos->m_Z - 1);
			Vetor3D v3(m_pos->m_X + 1, m_pos->m_Y + 1, m_pos->m_Z - 1);
			Vetor3D v4(m_pos->m_X - 1, m_pos->m_Y + 1, m_pos->m_Z - 1);
			Vetor3D v5(m_pos->m_X - 1, m_pos->m_Y - 1, m_pos->m_Z + 1);
			Vetor3D v6(m_pos->m_X + 1, m_pos->m_Y - 1, m_pos->m_Z + 1);
			Vetor3D v7(m_pos->m_X + 1, m_pos->m_Y + 1, m_pos->m_Z + 1);
			Vetor3D v8(m_pos->m_X - 1, m_pos->m_Y + 1, m_pos->m_Z + 1);


			Poligon p1(4);
			p1.AddVertice(&v1);
			p1.AddVertice(&v2);
			p1.AddVertice(&v3);
			p1.AddVertice(&v4);

			Poligon p2(4);
			p2.AddVertice(&v2);
			p2.AddVertice(&v6);
			p2.AddVertice(&v7);
			p2.AddVertice(&v3);

			Poligon p3(4);
			p3.AddVertice(&v6);
			p3.AddVertice(&v5);
			p3.AddVertice(&v8);
			p3.AddVertice(&v7);

			Poligon p4(4);
			p4.AddVertice(&v5);
			p4.AddVertice(&v1);
			p4.AddVertice(&v4);
			p4.AddVertice(&v8);

			Poligon p5(4);
			p5.AddVertice(&v4);
			p5.AddVertice(&v3);
			p5.AddVertice(&v7);
			p5.AddVertice(&v8);

			Poligon p6(4);
			p6.AddVertice(&v2);
			p6.AddVertice(&v1);
			p6.AddVertice(&v5);
			p6.AddVertice(&v6);

			m_mesh->AddPoligon(p1);
			m_mesh->AddPoligon(p2);
			m_mesh->AddPoligon(p3);
			m_mesh->AddPoligon(p4);
			m_mesh->AddPoligon(p5);
			m_mesh->AddPoligon(p6);

		}
		void Update()
		{
			Draw();
		}

	};
