#include "Camera.h"

/////////////////////////////////////// CAMERA NORMAL
//Camera::Camera()
//{
//}
//
//Camera::~Camera()
//{
//}
//
//void Camera::m_RodarCamera(float p_AnguloDireçao, float p_PosX, float p_PosY, float p_PosZ)
//{
//	Vetor3D i3DirVisao;
//	Quaternion qRotaçao, qVisao, qNovaVisao;
//
//	qRotaçao.m_Rotaciona(p_AnguloDireçao, p_PosX, p_PosY, p_PosZ);
//
//	i3DirVisao = m_PegarDireçaoCam();
//	qVisao.m_X = i3DirVisao.m_X;
//	qVisao.m_Y = i3DirVisao.m_Y;
//	qVisao.m_Z = i3DirVisao.m_Z;
//	qVisao.m_W = 0;
//
//	qNovaVisao = ((qRotaçao*qVisao)*qRotaçao.m_Conjugar());
//
//	m_ViewCam.m_X = m_PosCam.m_X + qNovaVisao.m_X;
//	m_ViewCam.m_Y = m_PosCam.m_Y + qNovaVisao.m_Y;
//	m_ViewCam.m_Z = m_PosCam.m_Z + qNovaVisao.m_Z;
//
//}
//Vetor3D Camera::m_PegarDireçaoCam()
//{
//	Vetor3D Direçao;
//	Direçao = m_ViewCam - m_PosCam;
//	return Direçao;
//
//}
//void Camera::m_UpdatePerspective()
//{
//	//Matriz de projeção
//	glMatrixMode(GL_PROJECTION);
//
//	//Inicializa com a matriz identidade
//	glLoadIdentity();
//
//	//Perspectiva
//	gluPerspective(45, GLfloat(768) / GLfloat(1024), 1.0f, 300.0f);
//
//	//Matriz model view
//	glMatrixMode(GL_MODELVIEW);
//}
//void Camera::m_PosicionaVisao()
//{
//	m_UpdatePerspective();
//	glLoadIdentity();
//	gluLookAt(m_PosCam.m_X, m_PosCam.m_Y, m_PosCam.m_Z,
//		m_ViewCam.m_X, m_ViewCam.m_Y, m_ViewCam.m_Z,
//		m_UpCam.m_X, m_UpCam.m_Y, m_UpCam.m_Z);
//	
//
//}
//void Camera::m_CameraZoom(float Direçao)
//{
//	Vetor3D i3Dir;
//
//	i3Dir = m_PegarDireçaoCam();
//	i3Dir.m_NormalizaçaoNoV();
//
//	Direçao = Direçao * 0.1f;
//
//	m_PosCam.m_X += i3Dir.m_X*Direçao;
//	m_PosCam.m_Y += i3Dir.m_Y*Direçao;
//	m_PosCam.m_Z += i3Dir.m_Z*Direçao;
//
//	m_ViewCam.m_X += i3Dir.m_X*Direçao;
//	m_ViewCam.m_Y += i3Dir.m_Y*Direçao;
//	m_ViewCam.m_Z += i3Dir.m_Z*Direçao;
//}
//void Camera::m_CameraStrafe(float Direçao)
//{
//	Vetor3D DireçaoCamera, Strafe;
//
//	DireçaoCamera = m_PegarDireçaoCam();
//	DireçaoCamera.m_NormalizaçaoNoV();
//
//	Strafe = DireçaoCamera.m_CrossProduct(m_UpCam);
//
//	Direçao = Direçao* 0.1f;
//
//	m_PosCam.m_X += Strafe.m_X*Direçao;
//	m_PosCam.m_Y += Strafe.m_Y*Direçao;
//	m_PosCam.m_Z += Strafe.m_Z*Direçao;
//
//	m_ViewCam.m_X += Strafe.m_X*Direçao;
//	m_ViewCam.m_Y += Strafe.m_Y*Direçao;
//	m_ViewCam.m_Z += Strafe.m_Z*Direçao;
//}
//
//void Camera::MapeiaMouse(int w, int h)
//{
//
//	POINT mousePos;
//
//	int i3dScreenX = w >> 1;
//	int i3dScreenY = h >> 1;
//
//	float i3dAnguloY = 0.0f;
//	float i3dAnguloZ = 0.0f;
//
//	Vetor3D i3dVetTemp, i3dEixo;
//
//	static float i3dRotacaoX = 0.0f;
//
//
//	GetCursorPos(&mousePos);
//
//	if ((mousePos.x == i3dScreenX) && (mousePos.y == i3dScreenY)) return;
//
//	SetCursorPos(i3dScreenX, i3dScreenY);
//
//	i3dAnguloY = (float)((i3dScreenX - mousePos.x)) / 10.0f;
//	i3dAnguloZ = (float)((i3dScreenY - mousePos.y)) / 10.0f;
//
//	i3dRotacaoX -= i3dAnguloZ;
//
//	if (i3dRotacaoX > 1.0f)
//	{
//
//		i3dRotacaoX = 1.0f;
//
//	}
//
//	if (i3dRotacaoX < -1.0f)
//	{
//
//		i3dRotacaoX = -1.0f;
//
//	}
//
//
//	i3dVetTemp = m_PegarDireçaoCam();
//	i3dEixo = i3dVetTemp.m_CrossProduct(m_UpCam);
//	i3dEixo.m_NormalizaçaoNoV();
//
//	m_RodarCamera(i3dAnguloZ,
//		i3dEixo.m_X,
//		i3dEixo.m_Y,
//		i3dEixo.m_Z);
//
//
//	m_RodarCamera(i3dAnguloY, 0, 1, 0);
//
//
//}
//
//void Camera::ProcessaComandos(int w, int h)
//{
//
//	MapeiaMouse(w, h);
//
//	if (teclado.RegisterKeyKode() == 8)
//	{
//		// (W)
//		m_CameraZoom(1.0f);
//		//cam.m_CameraAndar(1.0f);
//
//	}
//	if (teclado.RegisterKeyKode() == 6)
//	{
//		// (S)
//		m_CameraZoom(-1.0f);
//		//cam.m_CameraAndar(-1.0f);
//	}
//	if (teclado.RegisterKeyKode() == 5)
//	{
//		// (A)
//		m_CameraStrafe(-1.0f);
//	}
//	if (teclado.RegisterKeyKode() == 7)
//	{
//		// (D)
//		m_CameraStrafe(1.0f);
//	}
//
//
//
//	if (GetAsyncKeyState(0x1B) & 0xFF00)
//	{
//		exit(0); // (ESC)
//	}
//
//
//	if (teclado.RegisterKeyKode() == 31)
//	{
//		// (0)   FRONTAL
//		m_PosCam = Vetor3D(0, 70, -88);
//		m_ViewCam = Vetor3D(0, 0, 0);
//	}
//	if (teclado.RegisterKeyKode() == 32)
//	{
//		// (1)    CAÇAPA
//		m_PosCam = Vetor3D(-20,12,49);
//		m_ViewCam = Vetor3D(0.5f,4,-0.5f);
//	}
//	if (teclado.RegisterKeyKode() == 33)
//	{
//		// (2)     CAÇAPA
//		m_PosCam = Vetor3D(20, 12, 49);
//		m_ViewCam = Vetor3D(0.5f, 4, -0.5f);
//	}
//	if (teclado.RegisterKeyKode() == 34)
//	{
//		// (3)        CAÇAPA
//		m_PosCam = Vetor3D(-23, 13, 0);
//		m_ViewCam = Vetor3D(-11, 12, 0);
//	}
//	if (teclado.RegisterKeyKode() == 35)
//	{
//		// (4)       CAÇAPA
//		m_PosCam = Vetor3D(23, 13, 0);
//		m_ViewCam = Vetor3D(-11, 12, 0);
//	}
//	if (teclado.RegisterKeyKode() == 36)
//	{
//		// (5)           CAÇAPA
//		m_PosCam = Vetor3D(-20, 12, -49);
//		m_ViewCam = Vetor3D(0.5f, 4, -0.5f);
//	}
//	if (teclado.RegisterKeyKode() == 37)
//	{
//		// (6)         CAÇAPA
//		m_PosCam = Vetor3D(20, 12, -49);
//		m_ViewCam = Vetor3D(0.5f, 4, -0.5f);
//	}
//	if (teclado.RegisterKeyKode() == 38)
//	{
//		// (7)                
//		m_PosCam = Vetor3D(69,62,-5);
//		m_ViewCam = Vetor3D(0, 6, 0);
//	}
//	if (teclado.RegisterKeyKode() == 39)
//	{
//		// (8)          
//		m_PosCam = Vetor3D(0,11,-32);
//		m_ViewCam = Vetor3D(0, 6, 0);
//	}
//	if (teclado.RegisterKeyKode() == 40)
//	{
//		// (9)
//		m_PosCam = Vetor3D(0, 98, 11);
//		m_ViewCam = Vetor3D(0, 6, 0);
//	}
//
//	if (teclado.RegisterKeyKode() == 4)
//	{
//	std::cout << "X :  " << m_PosCam.m_X << "      Y  :  " << m_PosCam.m_Y << "    Z :  " << m_PosCam.m_Z << std::endl;
//	std::cout << "VIEW X :  " << m_ViewCam.m_X << "     VIEW  Y  :  " << m_ViewCam.m_Y << "   VIEW  Z :  " << m_ViewCam.m_Z << std::endl;
//		std::cout << "TIME ::: " << Time::GetDeltaTime() << std::endl;
//	}
//}
//
//void Camera::updateCamera(int w, int h)
//{
//	Time::Time_Update();
//	ProcessaComandos(w,h);
//	m_PosicionaVisao();
//
//}

/////////////////////////////////////    CAMERA PRINCIPAL

CameraPrincipal::CameraPrincipal()
{
	ativa = false;
}

CameraPrincipal::~CameraPrincipal()
{
}

void CameraPrincipal::m_RodarCamera(float p_AnguloDireçao, float p_PosX, float p_PosY, float p_PosZ)
{
	Vetor3D i3DirVisao;
	Quaternion qRotaçao, qVisao, qNovaVisao;

	qRotaçao.m_Rotaciona(p_AnguloDireçao, p_PosX, p_PosY, p_PosZ);

	i3DirVisao = m_PegarDireçaoCam();
	qVisao.m_X = i3DirVisao.m_X;
	qVisao.m_Y = i3DirVisao.m_Y;
	qVisao.m_Z = i3DirVisao.m_Z;
	qVisao.m_W = 0;

	qNovaVisao = ((qRotaçao*qVisao)*qRotaçao.m_Conjugar());

	m_ViewCam.m_X = m_PosCam.m_X + qNovaVisao.m_X;
	m_ViewCam.m_Y = m_PosCam.m_Y + qNovaVisao.m_Y;
	m_ViewCam.m_Z = m_PosCam.m_Z + qNovaVisao.m_Z;

}
Vetor3D CameraPrincipal::m_PegarDireçaoCam()
{
	Vetor3D Direçao;
	Direçao = m_ViewCam - m_PosCam;
	return Direçao;

}
void CameraPrincipal::m_UpdatePerspective()
{
	//Matriz de projeção
	glMatrixMode(GL_PROJECTION);

	//Inicializa com a matriz identidade
	glLoadIdentity();

	//Perspectiva
	gluPerspective(45, GLfloat(SCREEN_HEIGHT) / GLfloat(SCREEN_WIDTH), 1.0f, 300.0f);

	//Matriz model view
	glMatrixMode(GL_MODELVIEW);




	glClear(GL_COLOR_BUFFER_BIT | //Limpa o buffer de cores interno da OpenGL
		GL_DEPTH_BUFFER_BIT);//Limpa o buffer de PROFUNDIDADE interno da OpenGL



}
void CameraPrincipal::m_PosicionaVisao()
{
	m_UpdatePerspective();
	glLoadIdentity();
	gluLookAt(m_PosCam.m_X, m_PosCam.m_Y, m_PosCam.m_Z,
		m_ViewCam.m_X, m_ViewCam.m_Y, m_ViewCam.m_Z,
		m_UpCam.m_X, m_UpCam.m_Y, m_UpCam.m_Z);


}
void CameraPrincipal::m_CameraZoom(float Direçao)
{
	Vetor3D i3Dir;

	i3Dir = m_PegarDireçaoCam();
	i3Dir.m_NormalizaçaoNoV();

	Direçao = Direçao * 0.1f;

	m_PosCam.m_X += i3Dir.m_X*Direçao;
	m_PosCam.m_Y += i3Dir.m_Y*Direçao;
	m_PosCam.m_Z += i3Dir.m_Z*Direçao;

	m_ViewCam.m_X += i3Dir.m_X*Direçao;
	m_ViewCam.m_Y += i3Dir.m_Y*Direçao;
	m_ViewCam.m_Z += i3Dir.m_Z*Direçao;
}
void CameraPrincipal::m_CameraStrafe(float Direçao)
{
	Vetor3D DireçaoCamera, Strafe;

	DireçaoCamera = m_PegarDireçaoCam();
	DireçaoCamera.m_NormalizaçaoNoV();

	Strafe = DireçaoCamera.m_CrossProduct(m_UpCam);

	Direçao = Direçao* 0.1f;

	m_PosCam.m_X += Strafe.m_X*Direçao;
	m_PosCam.m_Y += Strafe.m_Y*Direçao;
	m_PosCam.m_Z += Strafe.m_Z*Direçao;

	m_ViewCam.m_X += Strafe.m_X*Direçao;
	m_ViewCam.m_Y += Strafe.m_Y*Direçao;
	m_ViewCam.m_Z += Strafe.m_Z*Direçao;
}

void CameraPrincipal::MapeiaMouse(int w, int h)
{

	POINT mousePos;

	int i3dScreenX = w >> 1;
	int i3dScreenY = h >> 1;

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


	i3dVetTemp = m_PegarDireçaoCam();
	i3dEixo = i3dVetTemp.m_CrossProduct(m_UpCam);
	i3dEixo.m_NormalizaçaoNoV();

	m_RodarCamera(i3dAnguloZ,
		i3dEixo.m_X,
		i3dEixo.m_Y,
		i3dEixo.m_Z);


	m_RodarCamera(i3dAnguloY, 0, 1, 0);


}

void CameraPrincipal::ProcessaComandos(int w, int h)
{

//	MapeiaMouse(w, h);

	
	



	if (GetAsyncKeyState(0x1B) & 0xFF00)
	{
		exit(0); // (ESC)
	}


	

	if (Input::getInstance().RegisterKeyKode() == 4)
	{
		std::cout << "X :  " << m_PosCam.m_X << "      Y  :  " << m_PosCam.m_Y << "    Z :  " << m_PosCam.m_Z << std::endl;
		std::cout << "VIEW X :  " << m_ViewCam.m_X << "     VIEW  Y  :  " << m_ViewCam.m_Y << "   VIEW  Z :  " << m_ViewCam.m_Z << std::endl;
		std::cout << "TIME ::: " << Time::GetDeltaTime() << std::endl;
	}
}

void CameraPrincipal::updateCamera(int w, int h)
{
	Time::Time_Update();
	ProcessaComandos(w, h);
	m_PosicionaVisao();

}

void CameraPrincipal::Ao_Redor(int d)
{
	Vetor3D dir = m_ViewCam - m_PosCam;

	Vetor3D straf = dir.m_CrossProduct(m_UpCam);

	straf.m_NormalizaçaoNoV();

	m_PosCam += straf * 0.3f * d;
}

void CameraPrincipal::ChangePosition_Direction(Vetor3D p_pos, Vetor3D p_dir)
{
	m_PosCam = p_pos;
	m_ViewCam = p_dir;
}

void CameraPrincipal::GoVertical(int i)
{
	m_PosCam += m_UpCam * i * Time::GetDeltaTime();
}
