#pragma once
#include "Matrix.h"
#include "Vetor3D.h"
#include "Quaternions.h"
#include "Header.h"

class CameraFps
{
public:

	CameraFps();
	Vetor3D m_PosCam;
	Vetor3D m_ViewCam;
	Vetor3D m_UpCam;
	Vetor3D m_Mira;

	Matrix m_MatrixModelo;
	Matrix m_LookAtMtx;
	Matrix m_MatrixPerspectiva;

	void m_RodarCameraFPS(float p_AnguloDireçao, float p_PosX, float p_PosY, float p_PosZ);
	Vetor3D m_PegarDireçaoCamFPS();
	void m_PosicionaVisao();
	void m_CameraFPSZoom(float p_Direçao);
	void m_CameraAndar(float p_Direçao);
	void m_CameraFPSStrafe(float p_Direçao);
	void m_UpdatePerspective();

	


	~CameraFps();
};

