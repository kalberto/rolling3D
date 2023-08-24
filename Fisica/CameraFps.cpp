#include "CameraFps.h"


CameraFps::CameraFps()
{
}


CameraFps::~CameraFps()
{
}

void CameraFps::m_CameraAndar(float p_Direçao)
{
	Vetor3D i3Dir;
	i3Dir = m_PegarDireçaoCamFPS();
	i3Dir.m_Y = 0;
	i3Dir.m_NormalizaçaoNoV();
	p_Direçao = p_Direçao*0.1f;

	m_PosCam.m_X += i3Dir.m_X*p_Direçao;
	m_PosCam.m_Y += i3Dir.m_Y*p_Direçao;
	m_PosCam.m_Z += i3Dir.m_Z*p_Direçao;

	m_ViewCam.m_X += i3Dir.m_X*p_Direçao;
	m_ViewCam.m_Y += i3Dir.m_Y*p_Direçao;
	m_ViewCam.m_Z += i3Dir.m_Z*p_Direçao;
}
void CameraFps::m_CameraFPSStrafe(float p_Direçao)
{
	Vetor3D DireçaoCamera, Strafe;

	DireçaoCamera = m_PegarDireçaoCamFPS();
	DireçaoCamera.m_NormalizaçaoNoV();

	Strafe = DireçaoCamera.m_CrossProduct(m_UpCam);

	p_Direçao = p_Direçao* 0.1f;

	m_PosCam.m_X += Strafe.m_X*p_Direçao;
	m_PosCam.m_Y += Strafe.m_Y*p_Direçao;
	m_PosCam.m_Z += Strafe.m_Z*p_Direçao;

	m_ViewCam.m_X += Strafe.m_X*p_Direçao;
	m_ViewCam.m_Y += Strafe.m_Y*p_Direçao;
	m_ViewCam.m_Z += Strafe.m_Z*p_Direçao;
}
Vetor3D CameraFps::m_PegarDireçaoCamFPS()
{
	Vetor3D Direçao;
	Direçao = m_ViewCam - m_PosCam;
	return Direçao;
}
void CameraFps::m_UpdatePerspective()
{
	//Matriz de projeção
	glMatrixMode(GL_PROJECTION);

	//Inicializa com a matriz identidade
	glLoadIdentity();

	//Perspectiva
	gluPerspective(45, GLfloat(768) / GLfloat(1024), 1.0f, 500.0f);

	//Matriz model view
	glMatrixMode(GL_MODELVIEW);
}
void CameraFps::m_PosicionaVisao()
{
	m_UpdatePerspective();
	glLoadIdentity();


	gluLookAt(m_PosCam.m_X, m_PosCam.m_Y, m_PosCam.m_Z,
		m_ViewCam.m_X, m_ViewCam.m_Y, m_ViewCam.m_Z,
		m_UpCam.m_X, m_UpCam.m_Y, m_UpCam.m_Z);

	
}
void CameraFps::m_RodarCameraFPS(float p_AnguloDireçao, float p_PosX, float p_PosY, float p_PosZ)
{
	Vetor3D i3DirVisao;
	Quaternion qRotaçao, qVisao, qNovaVisao;

	qRotaçao.m_Rotaciona(p_AnguloDireçao, p_PosX, p_PosY, p_PosZ);

	i3DirVisao = m_PegarDireçaoCamFPS();
	qVisao.m_X = i3DirVisao.m_X;
	qVisao.m_Y = i3DirVisao.m_Y;
	qVisao.m_Z = i3DirVisao.m_Z;
	qVisao.m_W = 0;

	qNovaVisao = ((qRotaçao*qVisao)*qRotaçao.m_Conjugar());

	m_ViewCam.m_X = m_PosCam.m_X + qNovaVisao.m_X;
	m_ViewCam.m_Y = m_PosCam.m_Y + qNovaVisao.m_Y;
	m_ViewCam.m_Z = m_PosCam.m_Z + qNovaVisao.m_Z;
}
