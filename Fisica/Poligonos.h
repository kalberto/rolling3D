#pragma once
#include"Header.h"


class Vertice
{
protected:
	float x;
	float y;
	float z;
public:
	Vertice(){};
	Vertice(float p_x, float p_y, float p_z)
	{
		x = p_x;
		y = p_y;
		z = p_z;
	}
	~Vertice(){};
	float Getx()
	{
		return x;
	}
	float Gety()
	{
		return y;
	}
	float Getz()
	{
		return z;
	}
	void Setx(float p_x)
	{
		x = p_x;
	}
	void Sety(float p_y)
	{
		y = p_y;
	}
	void Setz(float p_z)
	{
		z = p_z;
	}
	void Addx(float p_x)
	{
		x +=p_x;
	}
	void Addy(float p_y)
	{
		y +=p_y;
	}
	void Addz(float p_z)
	{
		z +=p_z;
	}
};
 

class Anel // um receptaculo para vertices
{
private:
	Vetor3D * m_vertices;
	int num_vert;
	int count;

public:
	Anel(){};
	Anel(int num)
	{
		num_vert = num;
		m_vertices = new Vetor3D[num_vert];
		count = 0;
	}

	void AddVert(float x,float y,float z)
	{
		if(count < num_vert)
		{
			m_vertices[count].m_X = x;
			m_vertices[count].m_Y = y;
			m_vertices[count].m_Z = z;
			count ++;
		}
		else
		{
			system("pause");
		}
	}

	void AddVertIn(int pos, float x, float y, float z)
	{
		if (count < num_vert)
		{
			m_vertices[pos].m_X = x;
			m_vertices[pos].m_Y = y;
			m_vertices[pos].m_Z = z;
		}
		else
		{
			system("pause");
		}
	}

	Vetor3D *  GetVert(int Index)
	{
		return &m_vertices[Index];
	}

	int GetNumVert()
	{
		return num_vert;
	}

};

class Poligon
{

private:
	int m_qtdvert, qtdindices;

	int *m_lstindices;
	int index;
	
	GLuint my_texture;
	bool T;

	Vetor3D m_normal;
	// Responsaveis por recortar a textura
	float u;
	float v;
public:
	Vetor3D * m_vertices;
	Poligon()
	{
		my_texture = CAIXA;
	}
	Poligon(int p_qtd)
	{
		index = 0;
		m_qtdvert = p_qtd;
		m_vertices = new Vetor3D[m_qtdvert];
		qtdindices = (m_qtdvert - 2) * 3;
		m_lstindices = new int[qtdindices];
		my_texture = CAIXA;
		T = true;

	}
	
	void Descobre_Normal()
	{
		Vetor3D A, B;
		A = m_vertices[0] - m_vertices[1];
		B = m_vertices[2] - m_vertices[1];

		A.m_NormalizaçaoNoV();
		B.m_NormalizaçaoNoV();

		m_normal = B.m_CrossProduct(A);
	}

	void AddVertice(Vetor3D * p_vertice)
	{
		if(index < m_qtdvert)
		{
			m_vertices[index].m_X = (p_vertice->m_X);
			m_vertices[index].m_Y = (p_vertice->m_Y); 
			m_vertices[index].m_Z = (p_vertice->m_Z);

			index++;
		}
		if (index == 3)
		{
			Descobre_Normal();
		}

	}

	void Triangulariza()
	{
		int  Index;
	    int VerticeA,
		    VerticeB,
		    VerticeC;

	for (Index = 0; Index < qtdindices / 3; Index++)
	{
		if (Index == 0)
		{
			VerticeA = Index;
			VerticeB = Index + 1;
			VerticeC = Index + 2;
		}
		else
		{
			VerticeB = VerticeC;
			VerticeC++;
		}

		m_lstindices[Index * 3]       = VerticeA;
		m_lstindices[(Index * 3) + 1] = VerticeB;
		m_lstindices[(Index * 3) + 2] = VerticeC;
	}
	}

	void Draw()
	{
		if (T == true)
			Use_Texture();
		else
			glBindTexture(GL_TEXTURE_2D,0);


		
			glBegin(GL_TRIANGLES);

			glNormal3f(m_normal.m_X, m_normal.m_Y, m_normal.m_Z);
			for (int i = 0; i < qtdindices; i += 3)
			{
				TextureSettings(i);
				glTexCoord2f(u, v);

				glVertex3f(m_vertices[m_lstindices[0]].m_X, m_vertices[m_lstindices[0]].m_Y, m_vertices[m_lstindices[0]].m_Z);

				TextureSettings(i + 1);
				glTexCoord2f(u, v);

				glVertex3f(m_vertices[m_lstindices[i + 1]].m_X, m_vertices[m_lstindices[i + 1]].m_Y, m_vertices[m_lstindices[i + 1]].m_Z);

				TextureSettings(i + 2);
				glTexCoord2f(u, v);

				glVertex3f(m_vertices[m_lstindices[i + 2]].m_X, m_vertices[m_lstindices[i + 2]].m_Y, m_vertices[m_lstindices[i + 2]].m_Z);
			}
			glEnd();

	}

	void SetT(bool b)
	{
		T = b;
	}

	Vetor3D GetNormal()
	{
		return m_normal;
	}

	void SetNormal(float p_x,float p_y,float p_z)
	{
		m_normal.m_X = p_x;
		m_normal.m_Y = p_y;
		m_normal.m_Z = p_z;

	}
	void Negativa_Normal()
	{
		m_normal = - m_normal;
	}

	//void MoveX(float p_x)
	//{
	//	for(int i = 0;i < m_qtdvert;i++)
	//	{
	//		m_vertices[i].m_X += p_x;
	//	}
	//}
	//void MoveY(float p_y)
	//{
	//	for(int i = 0;i < m_qtdvert;i++)
	//	{
	//		m_vertices[i].m_Y += p_y;
	//	}
	//}
	//void MoveZ(float p_z)
	//{
	//	for(int i = 0;i < m_qtdvert;i++)
	//	{
	//		m_vertices[i].m_Z = p_z;
	//	}
	//}
	//void SetX(float p_x)
	//{
	//	for (int i = 0; i < m_qtdvert; i++)
	//	{
	//		m_vertices[i].m_X = p_x;
	//	}
	//}
	//void SetY(float p_y)
	//{
	//	for (int i = 0; i < m_qtdvert; i++)
	//	{
	//		m_vertices[i].m_Y = p_y;
	//	}
	//}
	//void SetZ(float p_z)
	//{
	//	for (int i = 0; i < m_qtdvert; i++)
	//	{
	//		m_vertices[i].m_Z = p_z;
	//	}
	//}

	//void RotateX(float p_angle)
	//{
	//	for (int i = 0; i < m_qtdvert; i++)
	//	{
	//		m_vertices[i].m_RotaçaoRadEXNoV(p_angle);
	//	}
	//}
	//void RotateY(float p_angle)
	//{
	//	for (int i = 0; i < m_qtdvert; i++)
	//	{
	//		m_vertices[i].m_RotaçaoRadEYNoV(p_angle);
	//	}
	//}
	//void RotateZ(float p_angle)
	//{
	//	for (int i = 0; i < m_qtdvert; i++)
	//	{
	//		m_vertices[i].m_RotaçaoRadEZNoV(p_angle);
	//	}
	//}

	

	void Use_Texture()
	{
		
		int t = Texture::GetTexture(my_texture);	
			glBindTexture(GL_TEXTURE_2D, t);
	}

	

	void SetTexture(int n)
	{
		my_texture = n;
	}
	

	void TextureSettings(int i)
	{
		switch (i)
		{
		case 0:
			u = 0;
			v = 0;
			break;
		case 1:
			u = 1;
			v = 0;
			break;
		case 2:
			u = 1;
			v = 1;
			break;
		case 3:
			u = 0;
			v = 0;
			break;
		case 4:
			u = 1;
			v = 1;
			break;
		case 5:
			u = 0;
			v = 1;
			break;

		}
	}

	//~Poligon();




};


