#pragma once
#include "Vetor3D.h"
#include "Matrix.h"
#include "Header.h"
#include"Input.h"


class Input;

class Camera
{
private:
	

public:

	Camera();

	Vetor3D m_PosCam;
	Vetor3D m_ViewCam;
	Vetor3D m_UpCam;
	Vetor3D m_Mira;

	Matrix m_MatrixModelo;
	Matrix m_LookAtMtx;
	Matrix m_MatrixPerspectiva;

	void m_RodarCamera(float p_AnguloDireçao, float p_PosX, float p_PosY, float p_PosZ);
	Vetor3D m_PegarDireçaoCam();
	void m_PosicionaVisao();
	void m_CameraZoom(float Direçao);
	void m_CameraStrafe(float Direçao);
	void m_UpdatePerspective();


	void MapeiaMouse(int w, int h);
	void ProcessaComandos(int w, int h);
	void updateCamera(int w, int h);

	~Camera();
};

class CameraPrincipal
{
private:


public:

	CameraPrincipal();
	bool ativa;
	Vetor3D m_PosCam;
	Vetor3D m_ViewCam;
	Vetor3D m_UpCam;
	Vetor3D m_Mira;

	Matrix m_MatrixModelo;
	Matrix m_LookAtMtx;
	Matrix m_MatrixPerspectiva;

	void m_RodarCamera(float p_AnguloDireçao, float p_PosX, float p_PosY, float p_PosZ);
	Vetor3D m_PegarDireçaoCam();
	void m_PosicionaVisao();
	void m_CameraZoom(float Direçao);
	void m_CameraStrafe(float Direçao);
	void m_UpdatePerspective();


	void MapeiaMouse(int w, int h);
	void Ao_Redor(int d);
	void ProcessaComandos(int w, int h);
	void updateCamera(int w, int h);

	void ChangePosition_Direction(Vetor3D p_pos, Vetor3D p_dir);

	void GoVertical(int i);

	~CameraPrincipal();
};
