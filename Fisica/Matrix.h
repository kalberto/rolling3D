#pragma once
#include <iostream>
#include <math.h>

using namespace std;

class Vetor3D;

class Matrix
{
public:
	Matrix();
	Matrix(float** p_Matrix);
	Matrix(Matrix& p_Matrix);
	Matrix(float p_11, float p_12, float p_13, float p_14,
			float p_21, float p_22, float p_23, float p_24,
			float p_31, float p_32, float p_33, float p_34,
			float p_41, float p_42, float p_43, float p_44);
	int m_Linhas, m_Colunas;

	operator const float* () const;
	operator float* ();

	union  {
		struct {
			float m_11, m_12, m_13, m_14;
			float m_21, m_22, m_23, m_24;
			float m_31, m_32, m_33, m_34;
			float m_41, m_42, m_43, m_44;
		};
		float m_Matrix[4][4];
	};
	float m_DeterminanteM3( int contador, int verificador);
	float m_Determinante();
	
	

	void m_SetMatrix(float p_11, float p_12, float p_13, float p_14,
						float p_21, float p_22, float p_23, float p_24,
						float p_31, float p_32, float p_33, float p_34,
						float p_41, float p_42, float p_43, float p_44);
	void m_SetMatrix(float** p_Matrix);

	

	Matrix& m_NovaMatrixIdentidade();
	Matrix& m_NovaMatrixZero();
	Matrix& m_Inverse();
	Matrix& operator+=(const Matrix& p_Matrix);
	Matrix& operator-=(const Matrix& p_Matrix);
	Matrix& operator*=(const Matrix& p_Matrix);
	Matrix& operator*=(float p_Escalar);
	Matrix& operator/=(float p_Escalar);



	Matrix m_DivisaoMatrxEscalar(float p_Escalar);
	Matrix operator/(float p_Escalar);
	Matrix operator*(float p_Escalar);
	Matrix operator*(const Matrix& p_Matrix);
	Matrix operator+(const Matrix& p_Matrix);
	Matrix operator-(const Matrix& p_Matrix);
	Matrix m_RetIdentidade();
	Matrix m_GetInverse();

	float** m_Adjunta();
	float** m_Cofator(int p_linha, int p_coluna);
	float** m_Transposta();
	float** m_NovaMatrixZeroF(int p_Linhas, int p_Colunas);

	bool m_SetLookAtRH(const Vetor3D& p_Pos, const Vetor3D& p_lookat, const Vetor3D& p_up);
	bool m_SetPerspectiveFovRH(const float& p_FovY, const float& p_Aspect, const float& p_NearPlane, const float& p_FarPlane);
	~Matrix();
};

