#include "Superficie.h"


Superficie::Superficie()
{
}


Superficie::~Superficie()
{
}
float Superficie::m_NormalD(float p_massa, float p_gravidade)
{
	float resultado = 0;

	resultado = p_massa*m_atritoDin�mico*p_gravidade;

	return resultado;
}