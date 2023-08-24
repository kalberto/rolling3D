#pragma once
#include <math.h>

#define PI              3.1415926535897932 
#define PEGA_RADIANOS(grau) (float)((grau*PI)/180.0f);

class Quaternion
{
public:
	Quaternion();
	Quaternion(float p_xEixo, float p_yEixo, float p_zEixo, float p_wEixo);

	Quaternion operator*(const Quaternion &p_Quat);
	Quaternion m_Conjugar(); // INVERTER X,Y,Z

	void operator=(const Quaternion &p_Quat);
	void m_Rotaciona(float p_grau, float p_xEixo, float p_yEixo, float p_zEixo);
	void m_CriaMatriz(float *p_Matrix);

	float m_X, m_Y, m_Z, m_W;
};