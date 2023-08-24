#include "Header.h"
float   xRot = 0.01f;
int     qtdPoligonos = 3;
int     qtdMeshs = 1;
int     qtdPrimitivos = 2;
int     Altura = 0;
int     Largura = 0;

Camera cam;
Sphere esfera(Vertice(10.0f, 0.0f, 10.0f), 10.0f, 10, 10);
Cubo cubo(Vertice(50.0f, 50.0f, 50.0f), 4);
Vetor3D mira(0.0f,0.0f,0.0f);

void Inicializa()
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	 
	esfera.SetTexture("Caixa.bmp");

	cam.m_PosCam = Vetor3D(5.0f, 1.0f, 5.0f);
	cam.m_ViewCam = Vetor3D(0.0f, 0.0f, 0.0f);
	cam.m_UpCam = Vetor3D(0.0f, 1.0f, 0.0f);
}

void Renderiza()
{

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glClear(GL_COLOR_BUFFER_BIT | //Limpa o buffer de cores interno da OpenGL
		GL_DEPTH_BUFFER_BIT);//Limpa o buffer de PROFUNDIDADE interno da OpenGL

	//Foi desabilitado Deph Test devido ao mesmo estar apresentando efeitos indesejados na renderização devido ao
	//"liga/desliga" de Deph tests em materiais / luzes para tratamento de transparencias(Vamos verificar posteriormente)
	//glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);//Habilita Remocao das "Back Faces" de cada triangulo
	glEnable(GL_TEXTURE_2D);//Habilita a Texturização da OpenGL
	glEnable(GL_CCW);

	glEnable(GL_COLOR_MATERIAL);//Habilita a Utilização de Color Material(Padrão , por isto que a glColor3f funcionava antes...
	glEnable(GL_LIGHTING);//Habilita Iluminação(É mutuamente exclusiva a ColorMaterial e somente funciona com as luzes ligadas)
	//glShadeModel(GL_FLAT      );//Habilita o Tipo de Algoritmo de Sombreamento Flat.
	glShadeModel(GL_SMOOTH);//Habilita o Tipo de Algoritmo de Sombreamento Gouraud.
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);//Faz a Luz ambiente levar em conta a posição do Viewer.
	glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);//Habilita Iluminação nos dois lados do Poligono.

	cam.m_PosicionaVisao();

	glDisable(GL_DEPTH_TEST);
	glDisable(GL_CULL_FACE);
	glDisable(GL_COLOR_MATERIAL);
	glDisable(GL_LIGHT0);
	glDisable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	glColor3f(0.7f, 0.7f, 0.7f);
	glBegin(GL_QUADS);
	for (int X = 0; X < 256; X++)
	{
		for (int Z = 0; Z < 256; Z++)
		{
			glVertex3i(X, 0, Z);
			glVertex3i(X, 0, Z + 1);
			glVertex3i(X + 1, 0, Z + 1);
			glVertex3i(X + 1, 0, Z);
		}
	}

	glEnd();
	
	

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1.0f, 1.0f, 0.0f);
	glBegin(GL_TRIANGLES);
	esfera.Draw();
	cubo.Draw();
	glEnd();
	glBegin(GL_POINTS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3fv(cam.m_ViewCam);
	glEnd();
	glutSwapBuffers();
}

void MapeiaMouse()
{

	POINT mousePos;

	int i3dScreenX = Largura >> 1;
	int i3dScreenY = Altura >> 1;

	float i3dAnguloY = 0.0f;
	float i3dAnguloZ = 0.0f;

	Vetor3D i3dVetTemp, i3dEixo;

	static float i3dRotacaoX = 0.0f;


	GetCursorPos(&mousePos);

	if ((mousePos.x == i3dScreenX) && (mousePos.y == i3dScreenY)) return;

	SetCursorPos(i3dScreenX, i3dScreenY);

	i3dAnguloY = (float)((i3dScreenX - mousePos.x)) / 10.0f;
	i3dAnguloZ = (float)((i3dScreenY - mousePos.y)) / 10.0f;

	i3dRotacaoX -= i3dAnguloZ;

	if (i3dRotacaoX > 1.0f)
	{

		i3dRotacaoX = 1.0f;

	}

	if (i3dRotacaoX < -1.0f)
	{

		i3dRotacaoX = -1.0f;

	}


	i3dVetTemp = cam.m_PegarDireçaoCamFPS();
	i3dEixo = i3dVetTemp.m_CrossProduct(cam.m_UpCam);
	i3dEixo.m_NormalizaçaoNoV();

	cam.m_RodarCameraFPS(i3dAnguloZ,
						i3dEixo.m_X,
						i3dEixo.m_Y,
						i3dEixo.m_Z);

	cam.m_RodarCameraFPS(i3dAnguloY, 0, 1, 0);
}

void ProcessaComandos()
{

	MapeiaMouse();

	if (GetAsyncKeyState(0x57) & 0xFF00)
	{
		// (W)
		//cam.m_CameraZoom(1.0f);
		cam.m_CameraAndar(1.0f);

	}
	if (GetAsyncKeyState(0x53) & 0xFF00)
	{
		// (S)
		//cam.m_CameraZoom(-1.0f);
		cam.m_CameraAndar(-1.0f);
	}
	if (GetAsyncKeyState(0x41) & 0xFF00)
	{
		// (A)
		cam.m_CameraFPSStrafe(-1.0f);
	}
	if (GetAsyncKeyState(0x44) & 0xFF00)
	{
		// (D)
		cam.m_CameraFPSStrafe(1.0f);
	}

	if (GetAsyncKeyState(0x1B) & 0xFF00)
	{
		exit(0); // (ESC)
	}

}

void Update(void)
{
	ProcessaComandos();
	glutPostRedisplay();

}

void Dimensiona(int w, int h)
{
	Altura = w;
	Largura = h;

	float   CampoVisao = 90.0f;

	float Aspecto = (float)Altura / (float)Largura;

	glViewport(0, 0, Altura, Largura);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	cam.m_MatrixPerspectiva.m_SetPerspectiveFovRH(CampoVisao / 2, Aspecto, 0.0f, 150000000.0f);
	glLoadMatrixf(cam.m_MatrixPerspectiva);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int _tmain(int argc, char ** argv)
{

	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(0, 0);
	glutCreateWindow(argv[0]);

	ShowCursor(false);

	Inicializa();

	glutDisplayFunc(Renderiza);
	glutReshapeFunc(Dimensiona);
	glutIdleFunc(Update);

	glutMainLoop();

	return 0;
}
