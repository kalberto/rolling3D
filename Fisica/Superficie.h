#pragma once
#include "Header.h"
class Superficie
{
public:

	float m_atritoEst�tico;
	float m_atritoDin�mico;
	float m_NormalD(float p_massa, float p_gravidade);


	Superficie();
	~Superficie();
};

