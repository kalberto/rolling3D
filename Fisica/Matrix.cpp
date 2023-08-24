#include "Matrix.h"

#include "Vetor3D.h"

Matrix::Matrix()
{
	m_11 = m_12 = m_13 = m_14 = 0.0f;
	m_21 = m_22 = m_23 = m_24 = 0.0f;
	m_31 = m_32 = m_33 = m_34 = 0.0f;
	m_41 = m_42 = m_43 = m_44 = 0.0f;
	m_Linhas = 4; m_Colunas = 4;
}
Matrix::Matrix(float** p_Matrix)
{
	m_11 = p_Matrix[0][0]; m_12 = p_Matrix[0][1]; m_13 = p_Matrix[0][2]; m_14 = p_Matrix[0][3];
	m_21 = p_Matrix[1][0]; m_22 = p_Matrix[1][1]; m_23 = p_Matrix[1][2]; m_24 = p_Matrix[1][3];
	m_31 = p_Matrix[2][0]; m_32 = p_Matrix[2][1]; m_33 = p_Matrix[2][2]; m_34 = p_Matrix[2][3];
	m_41 = p_Matrix[3][0]; m_42 = p_Matrix[3][1]; m_43 = p_Matrix[3][2]; m_44 = p_Matrix[3][3];
	m_Linhas = 4; m_Colunas = 4;
}
Matrix::Matrix(Matrix& p_Matrix)
{
	m_11 = p_Matrix.m_11; m_12 = p_Matrix.m_12; m_13 = p_Matrix.m_13; m_14 = p_Matrix.m_14;
	m_21 = p_Matrix.m_21; m_22 = p_Matrix.m_22; m_23 = p_Matrix.m_23; m_24 = p_Matrix.m_24;
	m_31 = p_Matrix.m_31; m_32 = p_Matrix.m_32; m_33 = p_Matrix.m_33; m_34 = p_Matrix.m_34;
	m_41 = p_Matrix.m_41; m_42 = p_Matrix.m_42; m_43 = p_Matrix.m_43; m_44 = p_Matrix.m_44;
	m_Linhas = 4; m_Colunas = 4;
}
Matrix::Matrix(float p_11, float p_12, float p_13, float p_14,
				float p_21, float p_22, float p_23, float p_24,
				float p_31, float p_32, float p_33, float p_34,
				float p_41, float p_42, float p_43, float p_44)
{
	m_11 = p_11; m_12 = p_12; m_13 = p_13; m_14 = p_14;
	m_21 = p_21; m_22 = p_22; m_23 = p_23; m_24 = p_24;
	m_31 = p_31; m_32 = p_32; m_33 = p_33; m_34 = p_34;
	m_41 = p_41; m_42 = p_42; m_43 = p_43; m_44 = p_44;
	m_Linhas = 4; m_Colunas = 4;
}

Matrix::operator float *()
{
	return (float*)& m_11;
}
Matrix::operator const float*() const{
	return (const float*)& m_11;
}

void Matrix::m_SetMatrix(float p_11, float p_12, float p_13, float p_14,
						float p_21, float p_22, float p_23, float p_24,
						float p_31, float p_32, float p_33, float p_34,
						float p_41, float p_42, float p_43, float p_44)
{
	m_11 = p_11; m_12 = p_12; m_13 = p_13; m_14 = p_14;
	m_21 = p_21; m_22 = p_22; m_23 = p_23; m_24 = p_24;
	m_31 = p_31; m_32 = p_32; m_33 = p_33; m_34 = p_34;
	m_41 = p_41; m_42 = p_42; m_43 = p_43; m_44 = p_44;
}
void Matrix::m_SetMatrix(float** p_Matrix)
{
	m_11 = p_Matrix[0][0]; m_12 = p_Matrix[0][1]; m_13 = p_Matrix[0][2]; m_14 = p_Matrix[0][3];
	m_21 = p_Matrix[1][0]; m_22 = p_Matrix[1][1]; m_23 = p_Matrix[1][2]; m_24 = p_Matrix[1][3];
	m_31 = p_Matrix[2][0]; m_32 = p_Matrix[2][1]; m_33 = p_Matrix[2][2]; m_34 = p_Matrix[2][3];
	m_41 = p_Matrix[3][0]; m_42 = p_Matrix[3][1]; m_43 = p_Matrix[3][2]; m_44 = p_Matrix[3][3];
}

Matrix::~Matrix()
{
}

float Matrix::m_DeterminanteM3( int contador, int verificador)
{
	float det;
	float cont = 0;
	float a, b, c, d;
	if (m_Linhas - contador == 2)
	{
		if (verificador == 0)
		{
			a = m_Matrix[contador][contador] * m_Matrix[contador + 1][contador + 1];
			return a;
		}
		else if (verificador == 1)
		{
			b = m_Matrix[contador][contador - 1] * m_Matrix[contador + 1][contador + 2];
			return b;
		}
		else if (verificador == 2)
		{
			c = m_Matrix[contador][contador - 1] * m_Matrix[contador + 1][contador];
			return c;
		}
	}

	for (int i = 0; i < m_Linhas; i++)
	{
		cont = m_Matrix[0 + contador][i + contador] * pow(-1, 1 + i + 1)*m_DeterminanteM3( contador + 1, i) + cont;
	}
	det = cont;
	return det;
}

float Matrix::m_Determinante()
{
	float resultado = 0;
	resultado = m_DeterminanteM3(0, 0);
	return resultado;
}


Matrix& Matrix::m_NovaMatrixIdentidade()
{
	m_12 = m_13 = m_14 = 0.0f; m_11 = 1.0f;
	m_21 = m_23 = m_24 = 0.0f; m_22 = 1.0f;
	m_31 = m_32 = m_34 = 0.0f; m_33 = 1.0f;
	m_41 = m_42 = m_43 = 0.0f; m_44 = 1.0f;

	return *this;
}
Matrix& Matrix::m_NovaMatrixZero()
{
	m_11 = m_12 = m_13 = m_14 = 0.0f;
	m_21 = m_22 = m_23 = m_24 = 0.0f;
	m_31 = m_32 = m_33 = m_34 = 0.0f;
	m_41 = m_42 = m_43 = m_44 = 0.0f;

	return *this;
}
Matrix& Matrix::m_Inverse()
{
	float Determinante = 0.0f;
	Determinante = m_Determinante();
	
	return *this;
}
Matrix& Matrix::operator+=(const Matrix& p_Matrix)
{
	m_11 += p_Matrix.m_11; m_12 += p_Matrix.m_12; m_13 += p_Matrix.m_13; m_14 += p_Matrix.m_14;
	m_21 += p_Matrix.m_21; m_22 += p_Matrix.m_22; m_23 += p_Matrix.m_23; m_24 += p_Matrix.m_24;
	m_31 += p_Matrix.m_31; m_32 += p_Matrix.m_32; m_33 += p_Matrix.m_33; m_34 += p_Matrix.m_34;
	m_41 += p_Matrix.m_41; m_42 += p_Matrix.m_42; m_43 += p_Matrix.m_43; m_44 += p_Matrix.m_44;

	return *this;
}
Matrix& Matrix::operator-=(const Matrix& p_Matrix)
{
	m_11 -= p_Matrix.m_11; m_12 -= p_Matrix.m_12; m_13 -= p_Matrix.m_13; m_14 -= p_Matrix.m_14;
	m_21 -= p_Matrix.m_21; m_22 -= p_Matrix.m_22; m_23 -= p_Matrix.m_23; m_24 -= p_Matrix.m_24;
	m_31 -= p_Matrix.m_31; m_32 -= p_Matrix.m_32; m_33 -= p_Matrix.m_33; m_34 -= p_Matrix.m_34;
	m_41 -= p_Matrix.m_41; m_42 -= p_Matrix.m_42; m_43 -= p_Matrix.m_43; m_44 -= p_Matrix.m_44;

	return *this;
}
Matrix& Matrix::operator*=(const Matrix& p_Matrix)
{
	Matrix m_matrix;
	for (int g = 0; g < m_Linhas; g++)
	{
		for (int w = 0; w < m_Colunas; w++)
		{
			for (int e = 0; e < m_Colunas; e++)
			{
				m_matrix.m_Matrix[g][w] += m_Matrix[g][e] * p_Matrix.m_Matrix[e][g];

			}
		}
	}
	m_11 = p_Matrix.m_Matrix[0][0]; m_12 = p_Matrix.m_Matrix[0][1]; m_13 = p_Matrix.m_Matrix[0][2]; m_14 = p_Matrix.m_Matrix[0][3];
	m_21 = p_Matrix.m_Matrix[1][0]; m_22 = p_Matrix.m_Matrix[1][1]; m_23 = p_Matrix.m_Matrix[1][2]; m_24 = p_Matrix.m_Matrix[1][3];
	m_31 = p_Matrix.m_Matrix[2][0]; m_32 = p_Matrix.m_Matrix[2][1]; m_33 = p_Matrix.m_Matrix[2][2]; m_34 = p_Matrix.m_Matrix[2][3];
	m_41 = p_Matrix.m_Matrix[3][0]; m_42 = p_Matrix.m_Matrix[3][1]; m_43 = p_Matrix.m_Matrix[3][2]; m_44 = p_Matrix.m_Matrix[3][3];
	return *this;
}
Matrix& Matrix::operator*=(float p_Escalar)
{
	m_11 *= p_Escalar; m_12 *= p_Escalar; m_13 *= p_Escalar; m_14 *= p_Escalar;
	m_21 *= p_Escalar; m_22 *= p_Escalar; m_23 *= p_Escalar; m_24 *= p_Escalar;
	m_31 *= p_Escalar; m_32 *= p_Escalar; m_33 *= p_Escalar; m_34 *= p_Escalar;
	m_41 *= p_Escalar; m_42 *= p_Escalar; m_43 *= p_Escalar; m_44 *= p_Escalar;

	return *this;
}
Matrix& Matrix::operator/=(float p_Escalar)
{
	float escalar = 1.0f / p_Escalar;
	m_11 *= escalar; m_12 *= escalar; m_13 *= escalar; m_14 *= escalar;
	m_21 *= escalar; m_22 *= escalar; m_23 *= escalar; m_24 *= escalar;
	m_31 *= escalar; m_32 *= escalar; m_33 *= escalar; m_34 *= escalar;
	m_41 *= escalar; m_42 *= escalar; m_43 *= escalar; m_44 *= escalar;

	return *this;
}

Matrix Matrix::operator/(float p_Escalar)
{
	float escalar = 1.0f / p_Escalar;
	return Matrix(m_11 * escalar, m_12 * escalar, m_13 * escalar, m_14 * escalar,
					m_21 * escalar, m_22 * escalar, m_23 * escalar, m_24 * escalar,
					m_31 * escalar, m_32 * escalar, m_33 * escalar, m_34 * escalar,
					m_41 * escalar, m_42 * escalar, m_43 * escalar, m_44 * escalar);
}
Matrix Matrix::operator*(float p_Escalar)
{
	return Matrix(m_11 * p_Escalar, m_12 * p_Escalar, m_13 * p_Escalar, m_14 * p_Escalar,
					m_21 * p_Escalar, m_22 * p_Escalar, m_23 * p_Escalar, m_24 * p_Escalar,
					m_31 * p_Escalar, m_32 * p_Escalar, m_33 * p_Escalar, m_34 * p_Escalar,
					m_41 * p_Escalar, m_42 * p_Escalar, m_43 * p_Escalar, m_44 * p_Escalar);
}

Matrix Matrix::operator*(const Matrix& p_Matrix)
{
	Matrix m_matrix;
	for (int g = 0; g < m_Linhas; g++)
	{
		for (int w = 0; w < m_Colunas; w++)
		{
			for (int e = 0; e < m_Colunas; e++)
			{
				m_matrix.m_Matrix[g][w] += m_Matrix[g][e] * p_Matrix.m_Matrix[e][g];

			}
		}
	}
	return m_matrix;
}
Matrix Matrix::operator+(const Matrix& p_Matrix)
{
	return Matrix(m_11 + p_Matrix.m_11, m_12 + p_Matrix.m_12, m_13 + p_Matrix.m_13, m_14 + p_Matrix.m_14,
					m_21 + p_Matrix.m_21, m_22 + p_Matrix.m_22, m_23 + p_Matrix.m_23, m_24 + p_Matrix.m_24,
					m_31 + p_Matrix.m_31, m_32 + p_Matrix.m_32, m_33 + p_Matrix.m_33, m_34 + p_Matrix.m_34,
					m_41 + p_Matrix.m_41, m_42 + p_Matrix.m_42, m_43 + p_Matrix.m_43, m_44 + p_Matrix.m_44);
}
Matrix Matrix::operator-(const Matrix& p_Matrix)
{
	return Matrix(m_11 - p_Matrix.m_11, m_12 - p_Matrix.m_12, m_13 - p_Matrix.m_13, m_14 - p_Matrix.m_14,
					m_21 - p_Matrix.m_21, m_22 - p_Matrix.m_22, m_23 - p_Matrix.m_23, m_24 - p_Matrix.m_24,
					m_31 - p_Matrix.m_31, m_32 - p_Matrix.m_32, m_33 - p_Matrix.m_33, m_34 - p_Matrix.m_34,
					m_41 - p_Matrix.m_41, m_42 - p_Matrix.m_42, m_43 - p_Matrix.m_43, m_44 - p_Matrix.m_44);	
}

Matrix Matrix::m_GetInverse()
{

	Matrix matrixIn;
	
	Matrix matrixA;
	matrixA.m_SetMatrix(matrixA.m_Adjunta());
	
	float Idet = 0;
	float determinante = m_Determinante();

	if (determinante == 0)
	{
		cout << "Det igual a zero, sem inversa" << endl;
		return *this;
	}
	else
	{
		Idet = 1 / determinante;
		for (int w = 0; w < m_Linhas; w++)
		{
			for (int e = 0; e < m_Colunas; e++)
			{
				matrixIn.m_Matrix[w][e] = Idet*matrixA.m_Matrix[w][e];
			}
		}
	}
	return matrixIn;
}
Matrix Matrix::m_RetIdentidade()
{
	Matrix m_identidade;
	m_identidade.m_SetMatrix(1.0f,0.0f,0.0f,0.0f,
								0.0f,1.0f,0.0f,0.0f,
								0.0f,0.0f,1.0f,0.0f,
								0.0f,0.0f,0.0f,1.0f);


	return m_identidade;
}


float** Matrix::m_Cofator(int p_linha, int p_coluna)
{
	float** cofator;

	cofator= (float**)calloc(m_Linhas - 1 , sizeof(float*));

	for (int i = 0; i < m_Linhas - 1; i++)
	{
		cofator[i] = (float*)calloc(m_Colunas - 1, sizeof(float));
	}
	int size = m_Linhas - 1;


	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (i >= p_linha)
			{
				if (j >= p_coluna)
				{
					cofator[i][j] = m_Matrix[i + 1][j + 1];
				}
				else if (j<p_coluna)
				{
					cofator[i][j] = m_Matrix[i + 1][j];
				}
			}
			else if (i<p_linha)
			{
				if (j >= p_coluna)
				{
					cofator[i][j] = m_Matrix[i][j + 1];
				}
				else if (j<p_coluna)
				{
					cofator[i][j] = m_Matrix[i][j];
				}
			}
		}
	}

	return cofator;
}
float** Matrix::m_Adjunta()
{
	float** cofator = m_NovaMatrixZeroF(m_Linhas - 1, m_Colunas - 1);
	Matrix m_cofator;
	float** adjunta = m_NovaMatrixZeroF(m_Linhas, m_Colunas);
	
	float** transposta = m_NovaMatrixZeroF(m_Linhas, m_Colunas);
	transposta = m_Transposta();
	Matrix m_transposta(transposta);
	for (int i = 0; i < m_Linhas; i++)
	{
		for (int j = 0; j < m_Colunas; j++)
		{
			cofator = m_transposta.m_Cofator(i,j);
			m_cofator.m_SetMatrix(cofator[0][0], cofator[0][1], cofator[0][2], 0.0f,
									cofator[0][1], cofator[1][1], cofator[1][2], 0.0f,
									cofator[0][2], cofator[1][2], cofator[2][2], 0.0f,
									0.0f	,		0.0f ,			0.0f ,		 1.0f );
			m_cofator.m_Linhas = 3; m_cofator.m_Colunas = 3;
			adjunta[i][j] = pow(-1, i + j)*m_cofator.m_Determinante();
		}
	}
	return adjunta;
}
float** Matrix::m_NovaMatrixZeroF(int p_Linhas, int p_Colunas)
{
	float** resultado;

	resultado = (float**)calloc(p_Linhas, sizeof(float*));

	for (int i = 0; i < p_Linhas; i++)
	{
		resultado[i] = (float*)calloc(p_Colunas, sizeof(float));
	}

	return resultado;
}
float** Matrix::m_Transposta()
{
	float** transposta = m_NovaMatrixZeroF(m_Linhas, m_Colunas);

	for (int i = 0; i < m_Linhas; i++)
	{
		for (int k = 0; k < m_Colunas; k++)
		{
			transposta[i][k] = m_Matrix[k][i];
		}
	}

	return transposta;
}

bool Matrix::m_SetLookAtRH(const Vetor3D& p_Pos, const Vetor3D& p_lookat, const Vetor3D& p_up)
{
	Vetor3D uAxis, vAxis, nAxis;
	nAxis = -(p_lookat - p_Pos);
	nAxis.m_NormalizaçaoNoV();

	vAxis = p_up - nAxis * p_up.m_DotProduct(nAxis);

	if (vAxis.m_MaginitudeVetor3D() < 1e-5f) {
		vAxis.m_X = -nAxis.m_Y * nAxis.m_X;
		vAxis.m_Y = 1.0f - nAxis.m_Y * nAxis.m_Y;
		vAxis.m_Z = -nAxis.m_Y * nAxis.m_Z;
		if (vAxis.m_MaginitudeVetor3D() < 1e-5f) {
			vAxis.m_X = -nAxis.m_Z * nAxis.m_X;
			vAxis.m_Y = -nAxis.m_Z * nAxis.m_Y;
			vAxis.m_Z = 1.0f - nAxis.m_Z * nAxis.m_Z;

			if (vAxis.m_MaginitudeVetor3D() < 1e-5f)
			{
				return false;
			}				
		} 
	} 

	vAxis.m_NormalizaçaoNoV();
	uAxis = vAxis.m_CrossProduct(nAxis);

	m_11 = uAxis.m_X; m_12 = vAxis.m_X; m_13 = nAxis.m_X; m_14 = 0.0f;
	m_21 = uAxis.m_Y; m_22 = vAxis.m_Y; m_23 = nAxis.m_Y; m_24 = 0.0f;
	m_31 = uAxis.m_Z; m_32 = vAxis.m_Z; m_33 = nAxis.m_Z; m_34 = 0.0f;
	m_41 = -p_Pos.m_DotProduct(uAxis);
	m_42 = -p_Pos.m_DotProduct(vAxis);
	m_43 = -p_Pos.m_DotProduct(nAxis);
	m_44 = 1.0f;

	return true;
}
bool Matrix::m_SetPerspectiveFovRH(const float& p_FovY, const float& p_Aspect, const float& p_NearPlane, const float& p_FarPlane)
{
	float nfRatio, cotFovY, fFOV;

	nfRatio = p_FarPlane - p_NearPlane;
	if (fabsf(nfRatio) < 1e-2f) return false;
	nfRatio = p_FarPlane / nfRatio;

	fFOV = p_FovY * 0.5f;
	cotFovY = sinf(fFOV);
	if (fabsf(cotFovY) < 1e-5f) return false;
	cotFovY = cosf(fFOV) / cotFovY;

	m_11 = cotFovY / p_Aspect;
	m_22 = cotFovY;
	m_33 = -nfRatio;
	m_34 = -1.0f;
	m_43 = -nfRatio * p_NearPlane;

	m_12 = 0.0f; m_13 = 0.0f; m_14 = 0.0f;
	m_21 = 0.0f; m_23 = 0.0f; m_24 = 0.0f;
	m_31 = 0.0f; m_32 = 0.0f;
	m_41 = 0.0f; m_42 = 0.0f; m_44 = 0.0f;

	return true;
}