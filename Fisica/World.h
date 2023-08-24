#pragma once
#include<SDL_opengl.h>
#include<GL/GLU.h>

class World
{

private:
	int m_grid_x;
	int m_grid_y;
	int m_grid_z;


public:
	World();
	~World();

	void SetGrid_X(float p_x)
	{
		m_grid_x = p_x;
	}
	void SetGrid_Y(float p_y)
	{
		m_grid_y = p_y;
	}
	void SetGrid_Z(float p_z)
	{
		m_grid_z = p_z;
	}

	void CreateGrid_XZ()
	{
		//glColor3f(0.2f,0.2f,0.2f);
		//glColor3f(255,255,255);
		for (float i = -m_grid_x; i <= m_grid_x; i += 2)
		{
			glBegin(GL_LINES);

			//Linhas no eixo X
			glVertex3f(-m_grid_x, 0, i);
			glVertex3f(m_grid_x, 0, i);

			//Linhas no eixo Z
			glVertex3f(i, 0, -m_grid_x);
			glVertex3f(i, 0, m_grid_x);

			glEnd();
		}
	}
	void CreateGrid_XY()
	{
	//	glColor3f(0.2f, 0.2f, 0.2f);

		glBegin(GL_LINES);


		for (float i = -m_grid_y; i <= m_grid_y; i += 2)
		{
			//Linhas no eixo X
			glVertex3f(-m_grid_y, 0, i);
			glVertex3f(m_grid_y, 0, i);

			//Linhas no eixo Z
			glVertex3f(i, -m_grid_y, 0);
			glVertex3f(i,  m_grid_y, 0);


		}
		glEnd();
	}
	void CreateGrid_YZ()
		{
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glBegin(GL_QUADS);
			for (int Y = -m_grid_y; Y < m_grid_y; Y++)
			{
				for (int Z = -m_grid_z; Z < m_grid_z; Z++)
				{
					glVertex3i(0, Y, Z);
					glVertex3i(0, Y, Z + 1);
					glVertex3i(0, Y + 1, Z + 1);
					glVertex3i(0, Y + 1, Z);
				}
			}
			glEnd();
		}
	

};

