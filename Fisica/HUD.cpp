#include "HUD.h"
#define CAMPO_VISAO_PROXIMO     (0.0f)
#define CAMPO_VISAO_DISTANTE    (15000.0f)


HUD::HUD()
{
	//m_quad = new Quadrado;
	m_barra = new Plane(Vetor3D(0.84f, -0.4f, 0), Vetor3D(0.1f, 0.3f, 1));
	m_barra->m_corpo->SetAllTexture(BARRA);

	m_medidor = new Plane(Vetor3D(0.84f, -0.125f, -0.1f), Vetor3D(0.09f, 0.03f, 1));
	m_medidor->m_corpo->SetAllTexture(MEDIDOR);


	m_playername = new Plane(Vetor3D(-0.7f, 0.65f, 0), Vetor3D(0.3f, 0.1f, 1));
	m_playername->m_corpo->SetAllTexture(PLAYER1);
	m_jogador = 1;

	pontuacao = new Plane(Vetor3D(0.8f, 0.65f, 0), Vetor3D(0.1f, 0.1f, 1));
	pontuacao->m_corpo->SetAllTexture(NUM0);

	EE1 = new Plane(Vetor3D(0.84f, -0.4f, 0), Vetor3D(0.3f, 0.5f, 1));
	EE1->m_corpo->SetAllTexture(AURA);
}


HUD::~HUD()
{
}


void HUD::Set_Ortographic_Mode()
{
	DimensionaHorto();
}

void  HUD::Update(MODO estado)
{
	
	Set_Ortographic_Mode();


	if (estado == ATIVO)
	{
		
		InputMouse();
		m_barra->Draw();
		m_medidor->Draw();
		m_medidor->m_posiçao.m_Y = -0.125f;
	}
	m_playername->Draw();
	


}


void  HUD::Update(MODO estado, Player& jogador)
{
	if (m_jogador != jogador.ID)
	{
		m_jogador = jogador.ID;
		if (m_jogador == 1)
			m_playername->m_corpo->SetAllTexture(PLAYER1);
		else
			m_playername->m_corpo->SetAllTexture(PLAYER2);
	}

	atualizapontuacao(jogador.pontuacao);


	Set_Ortographic_Mode();
	if (estado == ATIVO)
	{

		InputMouse();
		m_barra->Draw();
		m_medidor->Draw();
		m_medidor->m_posiçao.m_Y = -0.125f;
		
		if (mostra_aura)
		{
			EE1->Draw();
		}

	}
	m_playername->Draw();
	pontuacao->Draw();

}


void HUD::DimensionaHorto()
{
	
	int Largura = SCREEN_WIDTH;
	int Altura = SCREEN_WIDTH;


	GLfloat Aspecto;
	float   CampoVisao = 90.0f;

	/**************************/
	/*Previne divisao por zero*/
	/**************************/
	if (Largura == 0)
		Largura = 1;
	/************************************************************/
	/*Regula o campo de desenho da tela para o tamanho requerido*/
	/************************************************************/
	glViewport(-((Largura - SCREEN_WIDTH) / 2), -((Altura - SCREEN_HEIGHT) / 2), Altura, Largura);
	/*******************************/
	/*Obtem o divisor de aspecto   */
	/*******************************/
	Aspecto = (GLfloat)Altura / (GLfloat)Largura;
	/********************************/
	/*Limpa o sistema de coordenadas*/
	/********************************/
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	{
		/***********************************/
		/*Calcula a Projecao de perspectiva*/
		/***********************************/
		double  esquerda;
		double  direita;
		double  embaixo;
		double  topo;

		direita = CAMPO_VISAO_PROXIMO * tan(CampoVisao / 2.0 * PI / 180.0f);

		topo = direita / Aspecto;

		embaixo = -topo;
		esquerda = -direita;

		glFrustum(esquerda, direita, embaixo, topo, CAMPO_VISAO_PROXIMO, CAMPO_VISAO_DISTANTE);
	}

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


void HUD::AnnounceWinner(TEXTURA txt)
{

}

void HUD::InputMouse()
{
	Input::getInstance().RegisterMouse();
	if (Input::getInstance().Mouse_Left_Is_Pressed() && !tacando)
	{
		tacando = true;
		xi = Input::getInstance().Get_Mouse_X();
		yi = Input::getInstance().Get_Mouse_Y();
		mostra_aura = false;
	}

	if ( tacando)
	{
		
		xf = Input::getInstance().Get_Mouse_X();
		yf = Input::getInstance().Get_Mouse_Y();

		Vetor3D inicio(xi, yi, 0);
		Vetor3D final(xf, yf, 0);
		Vetor3D resultado = inicio - final;

		m_medidor->m_posiçao.m_Y -= resultado.m_MaginitudeVetor3D() * Time::GetDeltaTime() * 0.1;
		std::cout << resultado.m_MaginitudeVetor3D() << std::endl;


		if (resultado.m_MaginitudeVetor3D() >= 300)
		{
			mostra_aura = true;
		}
		else
		{
			mostra_aura = false;
		}
	}
	if (!Input::getInstance().Mouse_Left_Is_Pressed())
	{
		tacando = false;
		xi = xf = yi = yf = 0;
	}
}


void HUD::atualizapontuacao(int p)
{
	switch (p)
	{
	case 0:
		pontuacao->m_corpo->SetAllTexture(NUM0);
		break;
	case 1:
		pontuacao->m_corpo->SetAllTexture(NUM1);
		break;
	case 2:
		pontuacao->m_corpo->SetAllTexture(NUM2);
		break;
	case 3:
		pontuacao->m_corpo->SetAllTexture(NUM3);
		break;
	case 4:
		pontuacao->m_corpo->SetAllTexture(NUM4);
		break;
	case 5:
		pontuacao->m_corpo->SetAllTexture(NUM5);
		break;
	case 6:
		pontuacao->m_corpo->SetAllTexture(NUM6);
		break;
	}




}