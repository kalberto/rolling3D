#pragma once
#include "Header.h"
class Superficie
{
public:

	float m_atritoEstático;
	float m_atritoDinâmico;
	float m_NormalD(float p_massa, float p_gravidade);


	Superficie();
	~Superficie();
};

