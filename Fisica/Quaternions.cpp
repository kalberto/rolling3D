#include "Quaternions.h"

Quaternion::Quaternion()
{
	m_X = m_Y = m_Z = 0.0f;
	m_W = 1.0f;
}
Quaternion::Quaternion(float p_xEixo, float p_yEixo, float p_zEixo, float p_wEixo)
{
	m_X = p_xEixo; m_Y = p_yEixo; m_Z = p_zEixo;
	m_W = p_wEixo;
}
void Quaternion::operator=(const Quaternion &p_Quat)
{
	m_X = p_Quat.m_X; m_Y = p_Quat.m_Y; m_Z = p_Quat.m_Z;
	m_W = p_Quat.m_W;
}
Quaternion Quaternion::operator*(const Quaternion &p_Quat)
{
	Quaternion m_resultado;

	m_resultado.m_X = m_W*p_Quat.m_X + m_X* p_Quat.m_W + m_Y* p_Quat.m_Z - m_Z*p_Quat.m_Y;
	m_resultado.m_Y = m_W*p_Quat.m_Y - m_X* p_Quat.m_Z + m_Y* p_Quat.m_W + m_Z*p_Quat.m_X;
	m_resultado.m_Z = m_W*p_Quat.m_Z + m_X* p_Quat.m_Y - m_Y* p_Quat.m_X + m_Z*p_Quat.m_W;
	m_resultado.m_W = m_W*p_Quat.m_W - m_X* p_Quat.m_X - m_Y* p_Quat.m_Y - m_Z*p_Quat.m_Z;

	return m_resultado;
}
Quaternion Quaternion::m_Conjugar()
{
	return Quaternion(-m_X, -m_Y, -m_Z, m_W);
}
void Quaternion::m_Rotaciona(float p_grau, float p_xEixo, float p_yEixo, float p_zEixo)
{
	if ((p_xEixo != 0 && p_xEixo != 1) || (p_yEixo != 0 && p_yEixo != 1) || (p_zEixo != 0 && p_zEixo != 1))
	{
		float tamanho = (float)sqrt(p_xEixo*p_xEixo + p_yEixo*p_yEixo + p_zEixo*p_zEixo);
		p_xEixo /= tamanho;
		p_yEixo /= tamanho;
		p_zEixo /= tamanho;
	}

	float angulo = PEGA_RADIANOS(p_grau);
	float seno = (float)sin(angulo / 2.0f);

	m_X = p_xEixo*seno;
	m_Y = p_yEixo*seno;
	m_Z = p_zEixo*seno;
	m_W = (float)cos(angulo / 2.0f);

	float tamanho = 1 / (float)sqrt(m_X*m_X + m_Y*m_Y + m_Z*m_Z + m_W*m_W);
	m_X *= tamanho;
	m_Y *= tamanho;
	m_Z *= tamanho;

}
void Quaternion::m_CriaMatriz(float* p_Matrix)
{
	if (!p_Matrix)
	{
		return;
	}

	p_Matrix[0] = 1.0f - 2.0f*(m_Y*m_Y + m_Z*m_Z);
	p_Matrix[1] = 2.0f*(m_X*m_Y + m_Z*m_W);
	p_Matrix[2] = 2.0f*(m_X*m_Z - m_Y*m_W);
	p_Matrix[3] = 0.0f;

	p_Matrix[4] = 2.0f*(m_X*m_Y - m_Z*m_W);
	p_Matrix[5] = 1.0f - 2.0f*(m_X*m_X + m_Z*m_Z);
	p_Matrix[6] = 2.0f*(m_Z*m_Y + m_X*m_W);
	p_Matrix[7] = 0.0f;

	p_Matrix[8] = 2.0f*(m_X*m_Z + m_Y*m_W);
	p_Matrix[9] = 2.0f*(m_Y*m_Z - m_X*m_W);
	p_Matrix[10] = 1.0f - 2.0f*(m_X*m_X + m_Y*m_Y);
	p_Matrix[11] = 0.0f;

	p_Matrix[12] = 0;
	p_Matrix[13] = 0;
	p_Matrix[14] = 0;
	p_Matrix[15] = 1.0f;

}