#pragma once


#include<SDL_opengl.h>
#include<GL/GLU.h>

class Cor
{
private:

	float * m_cor;
	
public:
	
	Cor();
	Cor(float p_r, float p_g, float p_b, float p_a);
	
	void SetCor(float p_r, float p_g, float p_b, float p_a);
	void SetRed(float p_r);
	void SetGreen(float p_g);
	void SetBlue(float p_b);
	void SetAlpha(float p_a);

	float GetRed();
	float GetGreen();
	float GetBlue();
	float GetAlpha();
};


class Luz
{
private:
	static int m_qtd_luzes;
	int m_valor_luz;
	Cor      difusa;
	Cor      ambiente;
	Cor      specular;
	float  Expoente;
	float  CutOff;
	float  AtenuacaoConstante;
	float  AtenuacaoLinear;
	float  AtenuacaoQuadratica;
	float x;
	float y;
	float z;
	float  dx;
	float  dy;
	float  dz;

public:

	Luz();
	Luz(float p_x,float p_y,float p_z);

	Cor GetDifusa();
	Cor GetAmbiente();

	Cor GetSpecular();
	float GetExpoente();
	float GetAtenuacao_Const();
	float GetAtenuacao_Lin();
	float GetAtenuacao_Quad();


	void SetDifusa(Cor p_dif);
	void SetDifusa(float p_r, float p_g, float p_b, float p_a);

	void SetAmbiente(Cor p_dif);
	void SetAmbiente(float p_r, float p_g, float p_b, float p_a);
	void SetSpecular(Cor p_dif);
	void SetSpecular(float p_r, float p_g, float p_b, float p_a);

	void SetExpoente(float p_exp);
	void SetAtenuacao_Const(float p_exp);
	void SetAtenuacao_Lin(float p_exp);
	void SetAtenuacao_Quad(float p_exp);


	void UseDifuse();

	void UseAmbient();

	void UseSpecular();
	void UsePosition();
	void UseLight();

	void Update();


	void StartLight();

	void LightParameters();
};



class Materials
{
private:
	Cor      difusa;
	Cor      ambiente;
	Cor      emissiva;
	Cor      specular;
	float  opacidade;
	float  brilho;
public:
	Materials();
	~Materials(void);

	Cor GetDifusa();
	Cor GetAmbiente();
	Cor GetEmissiva();
	Cor GetSpecular();
	float GetOpacidade();
	float GetBrilho();

	void SetDifusa(Cor p_dif);
	void SetDifusa(float p_r, float p_g, float p_b, float p_a);
	void SetAmbiente(Cor p_dif);
	void SetAmbiente(float p_r, float p_g, float p_b, float p_a);

	void SetEmissiva(Cor p_dif);
	void SetEmissiva(float p_r, float p_g, float p_b, float p_a);
	
	void SetSpecular(Cor p_dif);
	void SetSpecular(float p_r, float p_g, float p_b, float p_a);
	
	
	
	void SetOpacidade(float p_op);
	
	void SetBrilho(float p_bri);

	void AddOpacidade(float p_op);
	void AddBrilho(float p_bri);
	void UsaCorAmbiente();
	
	void UsaCorDifusa();

	void UsaCorSpecular();
	void UsaCorEmissiva();
	void UsarCorBrilho();
	void ChecarOpacidade();

	void UsaMaterial();
	void Inicializar_GL_Material();

};


