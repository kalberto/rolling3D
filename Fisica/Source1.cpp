/*glColor3f(0.7f, 0.0f, 0.0f);
glBegin(GL_POINTS);
Vetor3D vetor1(0, 0, 0);
Vetor3D vetor2(25, 25, 0);
Vetor3D vetor3(50, 0, 0);
glVertex3fv(vetor1);
glVertex3fv(vetor2);
glVertex3fv(vetor3);
Vetor3D vetor4(25, 0, 0);
glColor3f(1.0f, 1.0f, 1.0f);

for (int i = 0; i < 10000; i++)
{

	int x = rand() % 3 + 1;
	glVertex3fv(vetor4);
	if (x == 1)
	{
		glVertex3fv(vetor1);

		vetor4.m_setVetor(((vetor4.m_X + vetor1.m_X) / 2.0f), ((vetor4.m_Y + vetor1.m_Y) / 2.0f), ((vetor4.m_Z + vetor1.m_Z) / 2.0f));
		glVertex3fv(vetor4);
		//glVertex3fv(vetor4);
	}
	if (x == 2)
	{
		glVertex3fv(vetor2);

		vetor4.m_setVetor(((vetor4.m_X + vetor2.m_X) / 2.0f), ((vetor4.m_Y + vetor2.m_Y) / 2.0f), ((vetor4.m_Z + vetor2.m_Z) / 2.0f));
		glVertex3fv(vetor4);
		//glVertex3fv(vetor4);
	}
	if (x == 3)
	{
		glVertex3fv(vetor3);

		vetor4.m_setVetor(((vetor4.m_X + vetor3.m_X) / 2.0f), ((vetor4.m_Y + vetor3.m_Y) / 2.0f), ((vetor4.m_Z + vetor3.m_Z) / 2.0f));
		glVertex3fv(vetor4);
		//glVertex3fv(vetor4);
	}
}
glEnd();

glBegin(GL_POINTS);
vetor1.m_setVetor(0, 0, 0);
vetor2.m_setVetor(25, 0, 50);
vetor3.m_setVetor(50, 0, 0);
vetor4.m_setVetor(25, 25, 25);
glVertex3fv(vetor1);
glVertex3fv(vetor2);
glVertex3fv(vetor3);
glVertex3fv(vetor4);
Vetor3D vetor5(25, 0, 0);
for (int i = 0; i < 200000; i++)
{

	int x = rand() % 4 + 1;
	glVertex3fv(vetor5);
	if (x == 1)
	{
		glVertex3fv(vetor1);

		vetor5.m_setVetor(((vetor5.m_X + vetor1.m_X) / 2.0f), ((vetor5.m_Y + vetor1.m_Y) / 2.0f), ((vetor5.m_Z + vetor1.m_Z) / 2.0f));
		glVertex3fv(vetor5);
		//glVertex3fv(vetor4);
	}
	if (x == 2)
	{
		glVertex3fv(vetor2);

		vetor5.m_setVetor(((vetor5.m_X + vetor2.m_X) / 2.0f), ((vetor5.m_Y + vetor2.m_Y) / 2.0f), ((vetor5.m_Z + vetor2.m_Z) / 2.0f));
		glVertex3fv(vetor5);
		//glVertex3fv(vetor4);
	}
	if (x == 3)
	{
		glVertex3fv(vetor3);

		vetor5.m_setVetor(((vetor5.m_X + vetor3.m_X) / 2.0f), ((vetor5.m_Y + vetor3.m_Y) / 2.0f), ((vetor5.m_Z + vetor3.m_Z) / 2.0f));
		glVertex3fv(vetor5);
		//glVertex3fv(vetor4);
	}
	if (x == 4)
	{
		vetor5.m_setVetor(((vetor5.m_X + vetor4.m_X) / 2.0f), ((vetor5.m_Y + vetor4.m_Y) / 2.0f), ((vetor5.m_Z + vetor4.m_Z) / 2.0f));
		glVertex3fv(vetor5);
	}
}
glEnd();
glBegin(GL_POINTS);
vetor1.m_setVetor(0, 0, 100);
vetor2.m_setVetor(50, 0, 100);
vetor3.m_setVetor(50, 50, 100);
vetor4.m_setVetor(0, 50, 100);
glVertex3fv(vetor1);
glVertex3fv(vetor2);
glVertex3fv(vetor3);
glVertex3fv(vetor4);
vetor5.m_setVetor(12.5, 0, 100);
for (int i = 0; i < 10000; i++)
{

	int x = rand() % 4 + 1;
	int y = rand() % 3 + 1;
	glVertex3fv(vetor5);
	if (x == 1)
	{
		if (y == 1)
		{
			glVertex3fv(vetor1);
			glVertex3fv(vetor2);
			vetor5.m_setVetor(((vetor5.m_X + vetor2.m_X + vetor1.m_X) / 3.0f), ((vetor5.m_Y + vetor2.m_Y + vetor1.m_Y) / 3.0f), ((vetor5.m_Z + vetor2.m_Z + vetor1.m_Z) / 3.0f));
			glVertex3fv(vetor5);
		}
		if (y == 2)
		{
			glVertex3fv(vetor1);
			glVertex3fv(vetor3);
			vetor5.m_setVetor(((vetor5.m_X + vetor3.m_X + vetor1.m_X) / 3.0f), ((vetor5.m_Y + vetor3.m_Y + vetor1.m_Y) / 3.0f), ((vetor5.m_Z + vetor3.m_Z + vetor1.m_Z) / 3.0f));
			glVertex3fv(vetor5);

		}
		if (y == 30)
		{
			glVertex3fv(vetor1);
			glVertex3fv(vetor4);
			vetor5.m_setVetor(((vetor5.m_X + vetor4.m_X + vetor1.m_X) / 3.0f), ((vetor5.m_Y + vetor4.m_Y + vetor1.m_Y) / 3.0f), ((vetor5.m_Z + vetor4.m_Z + vetor1.m_Z) / 3.0f));
			glVertex3fv(vetor5);
		}
	}
	if (x == 2)
	{
		if (y == 1)
		{
			glVertex3fv(vetor2);
			glVertex3fv(vetor1);
			vetor5.m_setVetor(((vetor5.m_X + vetor2.m_X + vetor1.m_X) / 3.0f), ((vetor5.m_Y + vetor2.m_Y + vetor1.m_Y) / 3.0f), ((vetor5.m_Z + vetor2.m_Z + vetor1.m_Z) / 3.0f));
			glVertex3fv(vetor5);
		}
		if (y == 2)
		{
			glVertex3fv(vetor2);
			glVertex3fv(vetor3);
			vetor5.m_setVetor(((vetor5.m_X + vetor3.m_X + vetor2.m_X) / 3.0f), ((vetor5.m_Y + vetor3.m_Y + vetor2.m_Y) / 3.0f), ((vetor5.m_Z + vetor3.m_Z + vetor2.m_Z) / 3.0f));
			glVertex3fv(vetor5);

		}
		if (y == 3)
		{
			glVertex3fv(vetor2);
			glVertex3fv(vetor4);
			vetor5.m_setVetor(((vetor5.m_X + vetor4.m_X + vetor2.m_X) / 3.0f), ((vetor5.m_Y + vetor4.m_Y + vetor2.m_Y) / 3.0f), ((vetor5.m_Z + vetor4.m_Z + vetor2.m_Z) / 3.0f));
			glVertex3fv(vetor5);
		}
	}
	if (x == 3)
	{
		if (y == 1)
		{
			glVertex3fv(vetor3);
			glVertex3fv(vetor2);
			vetor5.m_setVetor(((vetor5.m_X + vetor2.m_X + vetor3.m_X) / 3.0f), ((vetor5.m_Y + vetor2.m_Y + vetor3.m_Y) / 3.0f), ((vetor5.m_Z + vetor2.m_Z + vetor3.m_Z) / 3.0f));
			glVertex3fv(vetor5);
		}
		if (y == 2)
		{
			glVertex3fv(vetor3);
			glVertex3fv(vetor4);
			vetor5.m_setVetor(((vetor5.m_X + vetor3.m_X + vetor4.m_X) / 3.0f), ((vetor5.m_Y + vetor3.m_Y + vetor4.m_Y) / 3.0f), ((vetor5.m_Z + vetor3.m_Z + vetor4.m_Z) / 3.0f));
			glVertex3fv(vetor5);

		}
		if (y == 3)
		{
			glVertex3fv(vetor3);
			glVertex3fv(vetor1);
			vetor5.m_setVetor(((vetor5.m_X + vetor3.m_X + vetor1.m_X) / 3.0f), ((vetor5.m_Y + vetor3.m_Y + vetor1.m_Y) / 3.0f), ((vetor5.m_Z + vetor3.m_Z + vetor1.m_Z) / 3.0f));
			glVertex3fv(vetor5);
		}
	}
	if (x == 4)
	{
		if (y == 1)
		{
			glVertex3fv(vetor4);
			glVertex3fv(vetor1);
			vetor5.m_setVetor(((vetor5.m_X + vetor4.m_X + vetor1.m_X) / 3.0f), ((vetor5.m_Y + vetor4.m_Y + vetor1.m_Y) / 3.0f), ((vetor5.m_Z + vetor4.m_Z + vetor1.m_Z) / 3.0f));
			glVertex3fv(vetor5);
		}
		if (y == 2)
		{
			glVertex3fv(vetor4);
			glVertex3fv(vetor3);
			vetor5.m_setVetor(((vetor5.m_X + vetor3.m_X + vetor4.m_X) / 3.0f), ((vetor5.m_Y + vetor3.m_Y + vetor4.m_Y) / 3.0f), ((vetor5.m_Z + vetor3.m_Z + vetor4.m_Z) / 3.0f));
			glVertex3fv(vetor5);

		}
		if (y == 3)
		{
			glVertex3fv(vetor2);
			glVertex3fv(vetor4);
			vetor5.m_setVetor(((vetor5.m_X + vetor4.m_X + vetor2.m_X) / 3.0f), ((vetor5.m_Y + vetor4.m_Y + vetor2.m_Y) / 3.0f), ((vetor5.m_Z + vetor4.m_Z + vetor2.m_Z) / 3.0f));
			glVertex3fv(vetor5);
		}
	}
}
glEnd();*/