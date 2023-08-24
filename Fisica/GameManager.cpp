#include "GameManager.h"
#include"CHEATS.h"

void CalculaAgua(Gerenciador_Bolas * G_B, std::vector<Paralelepipdo*> m_list_lagos,Fisica fisica,Superficie m_agua)
{
	std::cout << "ENTROU" << std::endl;
	while (true)
	{
		for (int i = 0; i < G_B->m_list_bolas.size(); i++)
		{
			for (int j = 0; j < m_list_lagos.size(); j++)
			{
				if (fisica.SphereBoxCollisionChck(m_list_lagos[j], G_B->m_list_bolas[i]))
				{
					fisica.m_AplicaAtritoDinâmicoSolo(G_B->m_list_bolas[i], m_agua);
					std::cout << "Colidiu" << std::endl;
				}
			}
		}
	}
}

GameManager::GameManager()
{
	G_B = new Gerenciador_Bolas();

	G_J = new Gerenciador_Jogador(G_B->GetElement(0));
	
	m_super.m_atritoDinâmico = 0.01;
	m_agua.m_atritoDinâmico = 1;

	m_hud = new HUD();
	CriaMundo();
	Usa_Agua = false;
	//CriaAgua(0);
	
	th = new std::thread(CalculaAgua,G_B,m_list_lagos,fisica,m_agua);
}

void GameManager::CriaMundo()
{
	novamesa = new Mesa();

	luminaria = new Lampada[3];
	luminaria[0] = Lampada(Vetor3D(0, 60, 20));
	luminaria[1] = Lampada(Vetor3D(0, 60, 0));
	luminaria[2] = Lampada(Vetor3D(0, 60, -20));

	WORLD = new Skybox();
}
void GameManager::DesenhaMundo()
{

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);//Habilita Remocao das "Back Faces" de cada triangulo
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_COLOR_MATERIAL);//Habilita a Utilização de Color Material(Padrão , por isto que a glColor3f funcionava antes...
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_LIGHTING);

	for (int i = 0; i < 3; i++)
		luminaria[i].Draw();

	my_cacapa.m_draw();
	novamesa->Draw();
	G_B->Update();
	WORLD->Draw();

	if (Usa_Agua)
	{
		DesenhaAgua();
	}

}


GameManager::~GameManager()
{
}


void GameManager::UpdatePrincipal()
{
	
	G_J->Update();
	fisica.m_VerificaColisãoBolas(G_B);

	//fisica.m_caçapas(G_B,&my_cacapa);
	fisica.Colisaocacapa_Melhorada(G_B,&my_cacapa);
	my_cacapa.SistemaUpdate();
	fisica.m_VerificaColisãoParede(G_B, G_B->GetSize());
	fisica.m_AplicaAtritoDinâmico(G_B, m_super);

	//std::thread th(CalculaAgua);

	if (G_J->J->terminoudejogar)
	{
		G_B->SeMoveram();
		if (G_B->moveram && G_B->Pararam())
		{
			somabolas = G_B->Diminuiubola();
			if (somabolas != 0)
			{
				G_J->atual->pontuacao += somabolas;
			}
			else
			{
				G_J->Troca();
			}
			G_B->moveram = false;
			G_J->J->terminoudejogar = false;
		}
	}

	DesenhaMundo();
	



	Check_Cheats();

}

void GameManager::UpdateSecundario()
{

	if (G_B->m_list_bolas.size() == 1)
	{
		if (G_J->p1.pontuacao > G_J->p2.pontuacao)
		{
			G_J->atual = &G_J->p1;
		}
		else
		{
			G_J->atual = &G_J->p2;
		}
		m_hud->m_playername->m_posiçao = Vetor3D(0, 0, 0);
		m_hud->m_playername->m_escala = Vetor3D(1, 0.5f, 0);
		//m_hud->Update(G_J->J->m_modo, *G_J->atual);
		//system("pause");
	}
	m_hud->Update(G_J->J->m_modo, *G_J->atual);
}


void GameManager::Check_Cheats()
{
	if (Cheat::getInstance().Get_Rafagan_Cheat())
	{
		WORLD->m_objs[0]->m_corpo->Set_Face_Texture(0,PROF1);
		WORLD->m_objs[0]->m_corpo->Set_Face_Texture(1,PROF2);
		WORLD->m_objs[0]->m_corpo->Set_Face_Texture(2,PROF3);
		WORLD->m_objs[0]->m_corpo->Set_Face_Texture(3,PROF4);
	}
	if (Cheat::getInstance().Get_Water1_Cheat())
	{
		Usa_Agua = true;
		CriaAgua(0);
	}
	if (Cheat::getInstance().Get_Water2_Cheat())
	{
		Usa_Agua = true;
		CriaAgua(1);
	}

}

void GameManager::CriaAgua( int n)
{
	Paralelepipdo * novocubo;
	switch (n)
	{
	case 0:
		novocubo = new Paralelepipdo(Vetor3D(0, 8, 0), Vetor3D(8, 0.5f, 3));
		novocubo->m_corpo->SetAllTexture(AGUA);
		m_list_lagos.push_back(novocubo);
		novocubo = new Paralelepipdo(Vetor3D(-18, 8, 10), Vetor3D(1, 0.5f, 8));
		novocubo->m_corpo->SetAllTexture(AGUA);
		m_list_lagos.push_back(novocubo);
		novocubo = new Paralelepipdo(Vetor3D(16, 8, 20), Vetor3D(4, 0.5f, 17));
		novocubo->m_corpo->SetAllTexture(AGUA);
		m_list_lagos.push_back(novocubo);
		novocubo = new Paralelepipdo(Vetor3D(0, 8, -35), Vetor3D(4, 0.5f, 10));
		novocubo->m_corpo->SetAllTexture(AGUA);
		m_list_lagos.push_back(novocubo);
		break;
	case 1:
		novocubo = new Paralelepipdo(Vetor3D(0, 8, -39), Vetor3D(18, 0.5f, 7));
		novocubo->m_corpo->SetAllTexture(AGUA);
		m_list_lagos.push_back(novocubo);
		novocubo = new Paralelepipdo(Vetor3D(0, 8, 39), Vetor3D(18, 0.5f, 7));
		novocubo->m_corpo->SetAllTexture(AGUA);
		m_list_lagos.push_back(novocubo);
		break;
	}
}
void GameManager::DesenhaAgua()
{
	for (int i = 0; i < m_list_lagos.size(); i++)
	{
		m_list_lagos[i]->Draw();
	}
}

