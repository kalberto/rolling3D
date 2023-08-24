#pragma once
#include <math.h>
#include "Matrix.h"
class Vetor3D
{
public:

	union {
		struct {
			float m_X, m_Y, m_Z, m_W;
		};
		float Vetor[4];
		};

	operator const float* () const;
	operator float* ();

	void m_setVetor(float p_x,float p_y, float p_z);
	void m_setVetor(Vetor3D p_vetor);

	float m_Azimute, m_Raio, m_EixoPolar;
	float m_MaginitudeVetor3D();
	float m_DotProduct(const  Vetor3D& p_B) const; // MESMA COISA QUE PRODUTO ESCALAR
	float m_DistanciaVetor3(const Vetor3D& p_B);

	double m_AnguloEntreV(Vetor3D p_B); // RAD, angulo vetores

	Vetor3D operator-() const;
	Vetor3D operator+() const;

	// NAO SETA O VALOR NO VETOR
	Vetor3D operator+(const Vetor3D& p_B) const;
	// SETA O VALOR NO VETOR
	Vetor3D& operator+=(const Vetor3D& p_B);
	Vetor3D operator-(const Vetor3D& p_B) const;// RETORNO
	Vetor3D& m_Subtra�aoNoVetor3(const Vetor3D& p_B);
	Vetor3D& operator-=(const Vetor3D& p_B);// NO VETOR
	Vetor3D operator*(float p_E) const ;// Retorno

	

	 // NO VETOR
	Vetor3D& operator*=(float p_E);
	Vetor3D& operator*=(const Matrix& p_matrix );
	Vetor3D operator*(const Matrix& p_matrix) const;
	Vetor3D operator/(float p_E) const ;
	Vetor3D& operator/=(float p_E);// NO VETOR
	Vetor3D m_CrossProduct(const Vetor3D& p_B) const ;
	Vetor3D& m_CrossProductNoV(const Vetor3D& p_B); // NO VETOR
	Vetor3D m_Normaliza�ao() ;
	Vetor3D& m_Normaliza�aoNoV();
	Vetor3D m_Rota�aoRadEZ( float radianos) ; //Retorna vetor RoT
	Vetor3D& m_Rota�aoRadEZNoV(float radianos); // Rotaciona VETOR
	Vetor3D m_Rota�aoRadEX( float radianos);
	Vetor3D& m_Rota�aoRadEXNoV(float radianos); //ROTACIONA VETOR
	Vetor3D m_Rota�aoRadEY( float radianos);
	Vetor3D& m_Rota�aoRadEYNoV(float radianos); // ROTACIONA VETOR
	Vetor3D& m_IgualarVetor3(Vetor3D p_B);
	Vetor3D m_ConversaoPolarCar();
	
	

	Vetor3D();
	Vetor3D(float p_x, float p_y, float p_z);
	~Vetor3D();
};

