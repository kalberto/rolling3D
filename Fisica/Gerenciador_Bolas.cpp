#include "Gerenciador_Bolas.h"


Gerenciador_Bolas::Gerenciador_Bolas()
{
	moveram = false;
	Cria_Bolas();
	tamanhoatual = m_list_bolas.size();
}

Gerenciador_Bolas::~Gerenciador_Bolas()
{
}

void Gerenciador_Bolas::Cria_Bolas()
{
	//////////////////////// CRIAR  E   POSICIONAR

	Bola * novabola = new Bola(Vetor3D(0, 9, -28), 1, 20, 1); ////BRANCA
	m_list_bolas.push_back(novabola);

	novabola = new Bola(Vetor3D(0, 9, 24), 1, 20, 1); 
	m_list_bolas.push_back(novabola);

	novabola = new Bola(Vetor3D(1, 9, 26), 1, 20, 1);
	m_list_bolas.push_back(novabola);

	novabola = new Bola(Vetor3D(-1, 9, 26), 1, 20, 1);
	m_list_bolas.push_back(novabola);

	novabola = new Bola(Vetor3D(0, 9, 28), 1, 20, 1);
	m_list_bolas.push_back(novabola);

	novabola = new Bola(Vetor3D(2, 9, 28), 1, 20, 1);
	m_list_bolas.push_back(novabola);
	 
	novabola = new Bola(Vetor3D(-2, 9, 28), 1, 20, 1);
	m_list_bolas.push_back(novabola);

	novabola = new Bola(Vetor3D(-3, 9, 30), 1, 20, 1);
	m_list_bolas.push_back(novabola);

	novabola = new Bola(Vetor3D(-1, 9, 30), 1, 20, 1);
	m_list_bolas.push_back(novabola);

	novabola = new Bola(Vetor3D(1, 9, 30), 1, 20, 1);
	m_list_bolas.push_back(novabola);

	novabola = new Bola(Vetor3D(3, 9, 30), 1, 20, 1);
	m_list_bolas.push_back(novabola);

	novabola = new Bola(Vetor3D(-4, 9, 32), 1, 20, 1);
	m_list_bolas.push_back(novabola);

	novabola = new Bola(Vetor3D(-2, 9, 32), 1, 20, 1);
	m_list_bolas.push_back(novabola);

	novabola = new Bola(Vetor3D(0, 9, 32), 1, 20, 1);
	m_list_bolas.push_back(novabola);

	novabola = new Bola(Vetor3D(2, 9, 32), 1, 20, 1);
	m_list_bolas.push_back(novabola);

	novabola = new Bola(Vetor3D(4, 9, 32), 1, 20, 1);
	m_list_bolas.push_back(novabola);

	////////////////////////  COR  ---- MATERIAL
	/////////////////////////////////////    AMBIENTE      EMISSIVA          DIFUSA          SPECULAR        OPACIDADE     BRILHO          
	m_list_bolas[1]->m_corpo->SetMaterial(Cor(0, 0, 0, 1), Cor(0, 0, 1, 1), Cor(0, 0, 0, 1), Cor(0, 0, 0, 1),    0.1f,        3);
	m_list_bolas[2]->m_corpo->SetMaterial(Cor(0, 0, 0, 1), Cor(0, 1, 0, 1), Cor(0, 0, 0, 1), Cor(0, 0, 0, 1),    0.1f,        2);
	m_list_bolas[3]->m_corpo->SetMaterial(Cor(0, 0, 0, 1), Cor(1, 0, 0, 1), Cor(0, 0, 0, 1), Cor(0, 0, 0, 1),    0.1f,        5);
	m_list_bolas[4]->m_corpo->SetMaterial(Cor(0, 0, 0, 1), Cor(1, 1, 0, 1), Cor(0, 0, 0, 1), Cor(0, 0, 0, 1),    0.1f,        3);
	m_list_bolas[5]->m_corpo->SetMaterial(Cor(0, 0, 0, 1), Cor(0, 1, 1, 1), Cor(0, 0, 0, 1), Cor(0, 0, 0, 1),    0.1f,        2);
	m_list_bolas[6]->m_corpo->SetMaterial(Cor(0, 0, 0, 1), Cor(1, 0, 1, 1), Cor(0, 0, 0, 1), Cor(0, 0, 0, 1),    0.1f,        5);

	m_list_bolas[7]->m_corpo->SetMaterial(Cor(0, 0, 0, 1), Cor(0, 0, 1, 1), Cor(0, 0, 0, 1), Cor(0, 0, 0, 1), 0.1f, 3);
	m_list_bolas[8]->m_corpo->SetMaterial(Cor(0, 0, 0, 1), Cor(0, 1, 0, 1), Cor(0, 0, 0, 1), Cor(0, 0, 0, 1), 0.1f, 2);
	m_list_bolas[9]->m_corpo->SetMaterial(Cor(0, 0, 0, 1), Cor(1, 0, 0, 1), Cor(0, 0, 0, 1), Cor(0, 0, 0, 1), 0.1f, 5);
	m_list_bolas[10]->m_corpo->SetMaterial(Cor(0, 0, 0, 1), Cor(1, 1, 0, 1), Cor(0, 0, 0, 1), Cor(0, 0, 0, 1), 0.1f, 3);
	m_list_bolas[11]->m_corpo->SetMaterial(Cor(0, 0, 0, 1), Cor(0, 1, 1, 1), Cor(0, 0, 0, 1), Cor(0, 0, 0, 1), 0.1f, 2);
	m_list_bolas[12]->m_corpo->SetMaterial(Cor(0, 0, 0, 1), Cor(1, 0, 1, 1), Cor(0, 0, 0, 1), Cor(0, 0, 0, 1), 0.1f, 5);
	m_list_bolas[13]->m_corpo->SetMaterial(Cor(0, 0, 0, 1), Cor(0, 0, 1, 1), Cor(0, 0, 0, 1), Cor(0, 0, 0, 1), 0.1f, 3);
	m_list_bolas[14]->m_corpo->SetMaterial(Cor(0, 0, 0, 1), Cor(0, 1, 0, 1), Cor(0, 0, 0, 1), Cor(0, 0, 0, 1), 0.1f, 2);
	

}

void Gerenciador_Bolas::Update()
{
	

	for (int i = 0; i < m_list_bolas.size(); i++)
	{
		m_list_bolas[i]->m_atualiza();
		m_list_bolas[i]->Draw();
	}

}

Bola* Gerenciador_Bolas::GetElement(int index)
{
	return m_list_bolas[index];
}

int Gerenciador_Bolas::GetSize()
{
	return m_list_bolas.size();
}

bool Gerenciador_Bolas::Pararam()
{
	for (int i = 0; i < m_list_bolas.size(); i++)
	{
		if (m_list_bolas[i]->m_velocidade.m_MaginitudeVetor3D() != 0)
			return false;
	}
	return true;
}


void Gerenciador_Bolas::SeMoveram()
{
	if (!moveram)
	{
		for (int i = 0; i < m_list_bolas.size(); i++)
		{
			if (m_list_bolas[i]->m_velocidade.m_MaginitudeVetor3D() != 0)
				moveram = true;
		}
	}
	//moveram = false;
}


int Gerenciador_Bolas::Diminuiubola()
{
	if (tamanhoatual != m_list_bolas.size())
	{
		int aux = tamanhoatual;
		tamanhoatual = m_list_bolas.size();
		return aux - tamanhoatual;
	}
	return 0;
}
