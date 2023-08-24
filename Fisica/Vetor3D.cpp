#include "Vetor3D.h"
Vetor3D::Vetor3D()
{
	m_X = 0.0f;
	m_Y = 0.0f;
	m_Z = 0.0f;
}
Vetor3D::Vetor3D(float p_x, float p_y, float p_z)
{
	m_X = p_x;
	m_Y = p_y;
	m_Z = p_z;
	m_W = 0;
}


Vetor3D::~Vetor3D()
{
}


Vetor3D::operator float *()
{
	return (float*)& m_X;
}
Vetor3D::operator const float*() const{
	return (const float*)& m_X;
}

void Vetor3D::m_setVetor(Vetor3D p_vetor)
{
	m_X = p_vetor.m_X;
	m_Y = p_vetor.m_Y;
	m_Z = p_vetor.m_Z;
	m_W = 0;
}

void Vetor3D::m_setVetor(float p_x,float p_y, float p_z)
{
	m_X = p_x;
	m_Y = p_y;
	m_Z = p_z;
	m_W = 0;
}

float Vetor3D::m_DistanciaVetor3(const Vetor3D& p_B)
{
	float resultado = sqrt( (p_B.m_X - m_X)*(p_B.m_X - m_X) +
							(p_B.m_Y - m_Y)*(p_B.m_Y - m_Y) +
							(p_B.m_Z - m_Z)*(p_B.m_Z - m_Z));
	return resultado;
}

double Vetor3D::m_AnguloEntreV(Vetor3D p_B)
{
	if (m_MaginitudeVetor3D() == 0)
	{
		return 0;
	}
	if (p_B.m_MaginitudeVetor3D() == 0)
	{
		return 0;
	}
	float m_ProdEscalar = m_DotProduct(p_B);
	float m_Magnitude = m_MaginitudeVetor3D() * p_B.m_MaginitudeVetor3D();
	double m_Angulo = acos(m_ProdEscalar / m_Magnitude);
	return m_Angulo;
}

Vetor3D Vetor3D::operator+(const Vetor3D& p_B) const
{
	Vetor3D resultado;

	resultado.m_X = m_X + p_B.m_X;
	resultado.m_Y = m_Y + p_B.m_Y;
	resultado.m_Z = m_Z + p_B.m_Z;

	return resultado;
}
Vetor3D& Vetor3D::operator+=(const Vetor3D& p_B)
{
	m_X = m_X + p_B.m_X;
	m_Y = m_Y + p_B.m_Y;
	m_Z = m_Z + p_B.m_Z;

	return *this;
}

Vetor3D Vetor3D::operator*(const Matrix& p_matrix) const
{
	Vetor3D resultado;
	resultado.m_X = m_X*p_matrix.m_11 + m_Y*p_matrix.m_12 + m_Z*p_matrix.m_13 + m_W*p_matrix.m_14;
	resultado.m_Y = m_X*p_matrix.m_21 + m_Y*p_matrix.m_22 + m_Z*p_matrix.m_23 + m_W*p_matrix.m_24;
	resultado.m_Z = m_X*p_matrix.m_31 + m_Y*p_matrix.m_32 + m_Z*p_matrix.m_33 + m_W*p_matrix.m_34;
	resultado.m_W = m_X*p_matrix.m_41 + m_Y*p_matrix.m_42 + m_Z*p_matrix.m_43 + m_W*p_matrix.m_44;
	return resultado;
}
Vetor3D& Vetor3D::operator*=(const Matrix& p_matrix)
{
	Vetor3D resultado;
	resultado.m_X = m_X*p_matrix.m_11 + m_Y*p_matrix.m_12 + m_Z*p_matrix.m_13 + m_W*p_matrix.m_14;
	resultado.m_Y = m_X*p_matrix.m_21 + m_Y*p_matrix.m_22 + m_Z*p_matrix.m_23 + m_W*p_matrix.m_24;
	resultado.m_Z = m_X*p_matrix.m_31 + m_Y*p_matrix.m_32 + m_Z*p_matrix.m_33 + m_W*p_matrix.m_34;
	resultado.m_W = m_X*p_matrix.m_41 + m_Y*p_matrix.m_42 + m_Z*p_matrix.m_43 + m_W*p_matrix.m_44;

	m_X = resultado.m_X;
	m_Y = resultado.m_Y;
	m_Z = resultado.m_Z;
	m_W = resultado.m_W;
	return *this;
}

Vetor3D Vetor3D::operator-(const Vetor3D& p_B) const
{
	Vetor3D resultado;

	resultado.m_X = m_X - p_B.m_X;
	resultado.m_Y = m_Y - p_B.m_Y;
	resultado.m_Z = m_Z - p_B.m_Z;

	return resultado;
}
Vetor3D& Vetor3D::operator-=(const Vetor3D& p_B)
{
	m_X = m_X - p_B.m_X;
	m_Y = m_Y - p_B.m_Y;
	m_Z = m_Z - p_B.m_Z;

	return *this;
}
Vetor3D	Vetor3D::operator*(float p_E) const
{
	Vetor3D resultado;

	resultado.m_X = m_X*p_E;
	resultado.m_Y = m_Y*p_E;
	resultado.m_Z = m_Z*p_E;

	return resultado;
}
Vetor3D& Vetor3D::operator*=(float p_E)
{
	m_X = m_X*p_E;
	m_Y = m_Y*p_E;
	m_Z = m_Z*p_E;

	return *this;
}
Vetor3D Vetor3D::operator/(float p_E) const
{
	Vetor3D resultado;
	float m_E = 1.0f / p_E;
	resultado.m_X = m_X*m_E;
	resultado.m_Y = m_Y*m_E;
	resultado.m_Z = m_Z*m_E;

	return resultado;
}
Vetor3D& Vetor3D::operator/=(float p_E)
{
	float m_E = 1.0f / p_E;
	m_X = m_X*m_E;
	m_Y = m_X*m_E;
	m_Z = m_Z*m_E;

	return *this;
}
float Vetor3D::m_DotProduct(const Vetor3D& p_B) const
{
	float resultado = 0;

	resultado = m_X*p_B.m_X + m_Y*p_B.m_Y + m_Z*p_B.m_Z;

	return resultado;
}
Vetor3D Vetor3D::m_CrossProduct(const Vetor3D& p_B) const
{
	Vetor3D resultado;

	resultado.m_X = m_Y*p_B.m_Z - p_B.m_Y*m_Z;
	resultado.m_Y = m_Z*p_B.m_X - p_B.m_Z*m_X;
	resultado.m_Z = m_X*p_B.m_Y - p_B.m_X*m_Y;

	return resultado;
}
Vetor3D& Vetor3D::m_CrossProductNoV(const Vetor3D& p_B)
{
	m_X = m_Y*p_B.m_Z - p_B.m_Y*m_Z;
	m_Y = m_Z*p_B.m_X - p_B.m_Z*m_X;
	m_Z = m_X*p_B.m_Y - p_B.m_X*m_Y;

	return *this;
}
float Vetor3D::m_MaginitudeVetor3D()
{
	float resultado;

	resultado = m_X*m_X + m_Y*m_Y +m_Z*m_Z;
	resultado = sqrt(resultado);

	return resultado;
}
Vetor3D Vetor3D::m_Normalizaçao()
{
	Vetor3D resultado;
	float Norma = 0;
	Norma = m_MaginitudeVetor3D();
	if (Norma == 0)
	{
		Norma = 1;
	}
	Norma = 1.0f / Norma;
	
	
	resultado.m_X = m_X * Norma;
	resultado.m_Y = m_Y * Norma;
	resultado.m_Z = m_Z * Norma;

	return resultado;
}
Vetor3D& Vetor3D::m_NormalizaçaoNoV()
{
	float Norma = m_MaginitudeVetor3D();
	if (fabsf(Norma) < 1e-5f) return *this;
	Norma = 1.0f / Norma; 
	m_X = m_X * Norma;
	m_Y = m_Y * Norma;
	m_Z = m_Z * Norma;

	return *this;
}
Vetor3D Vetor3D::m_RotaçaoRadEZ( float radianos)
{
	Vetor3D resultado;

	resultado.m_X = m_X*cos(radianos) + m_Y*sin(radianos);
	resultado.m_Y = m_X*(-sin(radianos)) + m_Y*cos(radianos);

	return resultado;
}
Vetor3D& Vetor3D::m_RotaçaoRadEZNoV(float radianos)
{
	m_X = m_X*cos(radianos) + m_Y*sin(radianos);
	m_Y = m_X*(-sin(radianos)) + m_Y*cos(radianos);

	return *this;
}
Vetor3D Vetor3D::m_RotaçaoRadEX( float radianos)
{
	Vetor3D resultado;

	resultado.m_X = m_X;
	resultado.m_Y = m_Y*cos(radianos) + m_Z*sin(radianos);
	resultado.m_Z = m_Y*(-sin(radianos)) + m_Z*cos(radianos);

	return resultado;
}
Vetor3D& Vetor3D::m_RotaçaoRadEXNoV(float radianos)
{
	m_X = m_X;
	m_Y = m_Y*cos(radianos) + m_Z*sin(radianos);
	m_Z = m_Y*(-sin(radianos)) + m_Z*cos(radianos);

	return *this;
}
Vetor3D Vetor3D::m_RotaçaoRadEY( float radianos)
{
	Vetor3D resultado;

	resultado.m_X = m_X*cos(radianos) + m_Y*(-sin(radianos));
	resultado.m_Y = resultado.m_Y;
	resultado.m_Z = m_X*sin(radianos) + m_Z*cos(radianos);

	return resultado;
}
Vetor3D& Vetor3D::m_RotaçaoRadEYNoV(float radianos)
{
	return *this;
}
Vetor3D Vetor3D::m_ConversaoPolarCar()
{
	Vetor3D resultado;

	resultado.m_X = m_Raio*sin(m_EixoPolar)*cos(m_Azimute);
	resultado.m_Y = m_Raio*sin(m_EixoPolar)*sin(m_Azimute);
	resultado.m_Z = m_Raio*cos(m_EixoPolar);

	return resultado;
}
Vetor3D& Vetor3D::m_IgualarVetor3(Vetor3D p_B)
{
	m_X = p_B.m_X;
	m_Y = p_B.m_Y;
	m_Z = p_B.m_Z;

	return *this;
}
Vetor3D Vetor3D::operator-() const
{
	return Vetor3D(-m_X, -m_Y, -m_Z);
}