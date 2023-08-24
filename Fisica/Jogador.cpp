#include "Jogador.h"
#include"CHEATS.h"

Jogador::Jogador(Bola * p_end_branca)
{
	m_camera = new CameraPrincipal;
	m_end_branca = p_end_branca;

	m_modo = ESPECTADOR;
	m_camera->ChangePosition_Direction(Vetor3D(0, 70, -88), Vetor3D(0, 0, 0));
	m_camera->m_UpCam = Vetor3D(0.0f, 1.0f, 0.0f);
	forca_tacada = 0;
	m_taco = new Taco;
	bateu = false;
	tacando = false;
	terminoudejogar = false;
	tecla_pressed = 0;
}

Jogador::~Jogador()
{
}

void Jogador::Modo_Espectador()
{
	ProcessaComandos_Espectador();
}
void Jogador::Modo_Ativo()
{
	ProcessaComandos_Ativo();
	if (bateu)
	{ 
		if (m_end_branca->m_velocidade.m_MaginitudeVetor3D() == 0)
		{
			bateu = false;
		}
	}
	else
	{
		AnimaTaco();
		InputMouse();
	}
}
void Jogador::Update()
{


	m_camera->updateCamera(SCREEN_WIDTH, SCREEN_HEIGHT);
	//terminoudejogar = false;
	switch (m_modo)
	{
	case ESPECTADOR:
		Modo_Espectador();
		break;
	case ATIVO:
		Modo_Ativo();
		break;
	}


	

}
void Jogador::ProcessaComandos_Espectador()
{
	int novo = Input::getInstance().RegisterKeyKode();
	if (novo != tecla_pressed)
	{
		if (novo == 31)
		{
			// (0)   FRONTAL
			m_camera->ChangePosition_Direction(Vetor3D(0, 70, -88), Vetor3D(0, 0, 0));
			Cheat::getInstance().Add_to_Code(0);
		}
		if (novo == 32)
		{
			// (1)    CAÇAPA
			m_camera->ChangePosition_Direction(Vetor3D(-22, 24, 70), Vetor3D(0.5f, 4, -0.5f));
			Cheat::getInstance().Add_to_Code(1);

		}
		if (novo == 33)
		{
			// (2)     CAÇAPA
			m_camera->ChangePosition_Direction(Vetor3D(22, 24, 70), Vetor3D(0.5f, 4, -0.5f));
			Cheat::getInstance().Add_to_Code(2);
		}
		if (novo == 34)
		{
			// (3)        CAÇAPA
			m_camera->ChangePosition_Direction(Vetor3D(-30, 24, 0), Vetor3D(-11, 12, 0));
			Cheat::getInstance().Add_to_Code(3);
		}
		if (novo == 35)
		{
			// (4)       CAÇAPA
			m_camera->ChangePosition_Direction(Vetor3D(30, 24, 0), Vetor3D(-11, 12, 0));
			Cheat::getInstance().Add_to_Code(4);
		}
		if (novo == 36)
		{
			// (5)           CAÇAPA
			m_camera->ChangePosition_Direction(Vetor3D(-22, 24, -70), Vetor3D(0.5f, 4, -0.5f));
			Cheat::getInstance().Add_to_Code(5);
		}
		if (novo == 37)
		{
			// (6)         CAÇAPA
			m_camera->ChangePosition_Direction(Vetor3D(22, 24, -70), Vetor3D(0.5f, 4, -0.5f));
			Cheat::getInstance().Add_to_Code(6);
		}
		if (novo == 38)
		{
			// (7)                
			m_camera->ChangePosition_Direction(Vetor3D(69, 62, -5), Vetor3D(0, 6, 0));
			Cheat::getInstance().Add_to_Code(7);
		}
		if (novo == 39)
		{
			// (8)          
			m_camera->ChangePosition_Direction(Vetor3D(0, 11, -32), Vetor3D(0, 6, 0));
			Cheat::getInstance().Add_to_Code(8);
		}
		if (novo == 40)
		{
			// (9)
			m_camera->ChangePosition_Direction(Vetor3D(0, 98, 11), Vetor3D(0, 6, 0));
			Cheat::getInstance().Add_to_Code(9);
		}
		if (novo == 19)
		{
			// (M)  troca de Modo de visualizaçao
			AtivoInicial();
		}

		tecla_pressed = novo;

	}
}

void Jogador::ProcessaComandos_Ativo()
{

	//if (Input::getInstance().RegisterKeyKode() == 4)
	//{
	//	// (A)
	//	m_tacada();
	//	bateu = true;
	//	EspectadorInicial();
	//}
	if (Input::getInstance().RegisterKeyKode() == 5)
	{
		// (A)
		m_camera->Ao_Redor(-1);
		m_taco->m_objs[0]->m_quantidadeRot.m_Z += GetAnguloNovo();
	}
	if (Input::getInstance().RegisterKeyKode() == 6)
	{
		// (S)
		Vetor3D dir = (m_camera->m_ViewCam - m_camera->m_PosCam) * Time::GetDeltaTime();
		m_camera->m_PosCam -= dir;
		//m_camera->m_ViewCam -= dir;
	}

	if (Input::getInstance().RegisterKeyKode() == 7)
	{
		// (D)
		m_camera->Ao_Redor(1);
		m_taco->m_objs[0]->m_quantidadeRot.m_Z += -GetAnguloNovo();
	}
	if (Input::getInstance().RegisterKeyKode() == 8)
	{
		// (W)
		Vetor3D dir = (m_camera->m_ViewCam - m_camera->m_PosCam) * Time::GetDeltaTime();
		m_camera->m_PosCam += dir;
		//m_camera->m_ViewCam -= dir;
	}
	if (Input::getInstance().RegisterKeyKode() == 23)
	{
		// (Q)
		m_camera->GoVertical(-1);
	}
	if (Input::getInstance().RegisterKeyKode() == 11)
	{
		// (E)
		m_camera->GoVertical(1);
		
	}


	if (Input::getInstance().RegisterKeyKode() == 19)
	{
		// (M)  troca de Modo de visualizaçao
		EspectadorInicial();
	}

	

}

Vetor3D Jogador::GetDirecao()
{
	return m_camera->m_ViewCam - m_camera->m_PosCam;
}

Vetor3D Jogador::GetDirecaoXZ()
{
	Vetor3D dir = GetDirecao();
	dir.m_Y = 0;
	return dir;
}

void Jogador::AnimaTaco()
{
	//m_taco->m_objs[0]->m_posiçao = Vetor3D(m_camera->m_PosCam.m_X, m_camera->m_PosCam.m_Y + 1, m_camera->m_PosCam.m_Z - 20);

	SetTacoPos();

	if (tacando)
		PuxaTaco();
	//m_taco->m_objs[0]->m_posiçao = ((m_camera->m_ViewCam - m_camera->m_PosCam) / 2) + m_camera->m_PosCam ;
	
	m_taco->Draw_diferente();
}

void Jogador::m_tacada()
{
	m_end_branca->m_força = GetDirecaoXZ() * 0.003 * forca_tacada;
	
}

void Jogador::SetTacoPos()
{
	m_taco->m_objs[0]->m_posiçao = m_end_branca->m_posiçao;

	
	
	m_taco->m_objs[0]->m_goback = Vetor3D(0, -32 ,0);
}

float Jogador::GetAnguloNovo()
{
	float angle;
	Vetor3D novo_normal = GetDirecaoXZ();
	
	if (m_normal == novo_normal)
		return 0;

	angle = novo_normal.m_AnguloEntreV(m_normal);
	
	m_normal = novo_normal;

	return angle;
}

void Jogador::EspectadorInicial()
{
	m_modo = ESPECTADOR;
	m_camera->ChangePosition_Direction(Vetor3D(0, 70, -88), Vetor3D(0, 0, 0));
}

void Jogador::AtivoInicial()
{
	tacando = false;

	float x = m_end_branca->m_posiçao.m_X;
	float y = m_end_branca->m_posiçao.m_Y;
	float z = m_end_branca->m_posiçao.m_Z;

	Vetor3D pos_helper(x, y + 2, z - 8);
	Vetor3D dir_helper(x, y + 2, z);

	m_modo = ATIVO;
	m_camera->ChangePosition_Direction(pos_helper, dir_helper);

	m_normal = GetDirecaoXZ();

	m_taco->m_objs[0]->m_quantidadeRot = Vetor3D(-80, 0, 0);
}

void Jogador::InputMouse()
{
	Input::getInstance().RegisterMouse();
	if (Input::getInstance().Mouse_Left_Is_Pressed() && !tacando)
	{
		tacando = true;
		xi = Input::getInstance().Get_Mouse_X();
		yi = Input::getInstance().Get_Mouse_Y();
		TacoBola = GetDirecao();
	}

	if (!Input::getInstance().Mouse_Left_Is_Pressed() && tacando)
	{
		terminoudejogar = true;
		tacando = false;
		xf = Input::getInstance().Get_Mouse_X();
		yf = Input::getInstance().Get_Mouse_Y();

		Vetor3D inicio(xi, yi, 0);
		Vetor3D final(xf, yf, 0);
		Vetor3D resultado = inicio - final;

		forca_tacada = resultado.m_MaginitudeVetor3D()*0.5f;
		m_tacada();
		forca_tacada = 0;
		xi = xf = yi = yf = 0;
		bateu = true;
		
		EspectadorInicial();

	}

	if (Input::getInstance().Mouse_Right_Is_Pressed())
	{
		if (m_modo == ATIVO)
			EspectadorInicial();
		/*else if (m_modo == ESPECTADOR)
			AtivoInicial();*/
	}


}

void Jogador::PuxaTaco()
{
	int x = Input::getInstance().Get_Mouse_X();
	int y = Input::getInstance().Get_Mouse_Y();
	Vetor3D inicio(xi,yi,0);
	Vetor3D final(x, y, 0);

	int m = (inicio - final).m_MaginitudeVetor3D();
	m_taco->m_objs[0]->m_goback.m_Y -= m * 2 * Time::GetDeltaTime();
}