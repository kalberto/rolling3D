#include "Fisica.h"
#include"Music.h"

Fisica::Fisica()
{
	m_gravidade = 0.16f;
}


Fisica::~Fisica()
{
}


void Fisica::m_VerificaColisãoParedes(Gerenciador_Bolas * p_Bola, Mesa * mesa)
{

	for (int i = 0; i < p_Bola->m_list_bolas.size(); i++)
	{
		for (int e = 1; e < 7; e++)
		{
			if (p_Bola->m_list_bolas[i]->m_posiçao.m_Z > mesa->m_objs[e]->m_posiçao.m_Z)
			{
				if (p_Bola->m_list_bolas[i]->m_posiçao.m_Z - p_Bola->m_list_bolas[i]->m_escala.m_Z <= mesa->m_objs[e]->m_posiçao.m_Z + mesa->m_objs[e]->m_escala.m_Z)
				{

				}
			}
			
		}
	}

}

void Fisica::m_caçapas(Gerenciador_Bolas* p_Bolas, caçapa* p_caçapa)
{
	float distancia, raio;
	for (int i = 0; i < p_Bolas->GetSize(); i++)
	{
		for (int e = 0; e < p_caçapa->m_caçapas.size(); e++)
		{
			distancia = (p_Bolas->m_list_bolas[i]->m_posiçao - p_caçapa->m_caçapas[e]->m_posiçao).m_MaginitudeVetor3D();
			raio = (p_Bolas->m_list_bolas[i]->m_escala + (p_caçapa->m_caçapas[e]->m_escala * 0.5f)).m_MaginitudeVetor3D();
			if (distancia <= raio)
			{
				if (i != 0)
				{
					p_caçapa->m_dentrocaçapa.push_back(p_Bolas->m_list_bolas[i]);
					p_Bolas->m_list_bolas.erase(p_Bolas->m_list_bolas.begin() + i);
				}
				else
				{
					p_Bolas->m_list_bolas[0]->m_posiçao = Vetor3D(0,9,-28);
					p_Bolas->m_list_bolas[0]->m_energiaCinetica = Vetor3D(0, 0, 0);
					p_Bolas->m_list_bolas[0]->m_força = Vetor3D(0, 0, 0);
					p_Bolas->m_list_bolas[0]->m_velocidade = Vetor3D(0, 0, 0);
				}
			}
		}
	}	
	
}

void Fisica::Colisaocacapa_Melhorada(Gerenciador_Bolas* p_Bolas, caçapa* p_caçapa)
{
	bool resultado;
	int cacapa;

	for (int e = 0; e < p_Bolas->m_list_bolas.size(); e++)
		{
			if (p_Bolas->m_list_bolas[e]->m_posiçao.m_X >= 0)
			{
				if (p_Bolas->m_list_bolas[e]->m_posiçao.m_Z > 23)
				{
					resultado = SphereCollisionCheck(p_Bolas->m_list_bolas[e],p_caçapa->m_caçapas[1]);
					cacapa = 1;
				}
				else if (p_Bolas->m_list_bolas[e]->m_posiçao.m_Z < -23)
				{
					resultado = SphereCollisionCheck(p_Bolas->m_list_bolas[e], p_caçapa->m_caçapas[2]);
					cacapa = 2;
				}
				else
				{
					resultado = SphereCollisionCheck(p_Bolas->m_list_bolas[e], p_caçapa->m_caçapas[0]);
					cacapa = 0;
				}
			}
			else
			{
				if (p_Bolas->m_list_bolas[e]->m_posiçao.m_Z > 23)
				{
					resultado = SphereCollisionCheck(p_Bolas->m_list_bolas[e], p_caçapa->m_caçapas[4]);
					cacapa = 4;
				}
				else if (p_Bolas->m_list_bolas[e]->m_posiçao.m_Z < -23)
				{
					resultado = SphereCollisionCheck(p_Bolas->m_list_bolas[e], p_caçapa->m_caçapas[5]);
					cacapa = 5;
				}
				else
				{
					resultado = SphereCollisionCheck(p_Bolas->m_list_bolas[e], p_caçapa->m_caçapas[3]);
					cacapa = 3;					
				}
			}

			if (resultado)
			{
				if (e != 0)
				{
					Materials bola_Materials = p_Bolas->m_list_bolas[e]->m_corpo->m_mesh->m_material;
					p_caçapa->m_sistemas[cacapa]->Iniciar(bola_Materials);
					p_caçapa->m_caçapas[cacapa]->m_corpo->m_mesh->m_material = bola_Materials;
					p_caçapa->m_dentrocaçapa.push_back(p_Bolas->m_list_bolas[e]);
					p_Bolas->m_list_bolas.erase(p_Bolas->m_list_bolas.begin() + e);
					
				}
				else
				{
					p_Bolas->m_list_bolas[0]->m_posiçao = Vetor3D(0, 9, -28);
					p_Bolas->m_list_bolas[0]->m_energiaCinetica = Vetor3D(0, 0, 0);
					p_Bolas->m_list_bolas[0]->m_força = Vetor3D(0, 0, 0);
					p_Bolas->m_list_bolas[0]->m_velocidade = Vetor3D(0, 0, 0);
				}
			}

		}
}

void Fisica::m_AplicaAtritoDinâmico(Gerenciador_Bolas* p_Bolas, Superficie p_Superficie)
{
	Vetor3D menor0;
	for (int i = 0; i < p_Bolas->GetSize(); i++)
	{
		if (p_Bolas->m_list_bolas[i]->m_velocidade.m_MaginitudeVetor3D() != 0)
		{
			menor0 = p_Bolas->m_list_bolas[i]->m_velocidade.m_Normalizaçao()*p_Superficie.m_NormalD(p_Bolas->m_list_bolas[i]->m_massa, m_gravidade)*-1;
			p_Bolas->m_list_bolas[i]->m_Impulso = menor0;
		}		
	}	
	
}

void Fisica::m_ReflexãoParede(Bola* p_Bola, Vetor3D p_posição)
{
	//p_Bola->m_Impulso = p_Bola->m_velocidade - (p_posição*(2 * p_Bola->m_velocidade.m_DotProduct(p_posição)));
 	p_Bola->m_velocidade -=  (p_posição*(2* p_Bola->m_velocidade.m_DotProduct(p_posição)))*0.8;
	//p_Bola->m_velocidade.m_NormalizaçaoNoV();
	
	
}

Vetor3D Fisica::m_GetEnergiaCinetica(Bola* p_Bola, float p_cos)
{
	Vetor3D resultado;
	Vetor3D velocidade = p_Bola->m_velocidade*p_cos;
	velocidade.m_X = velocidade.m_X*velocidade.m_X; velocidade.m_Y = velocidade.m_Y*velocidade.m_Y; velocidade.m_Z = velocidade.m_Z*velocidade.m_Z;

	resultado = velocidade*p_Bola->m_massa/2;

	return resultado;
}

float Fisica::m_getAngulocolisao(Bola* p_Bola, Vetor3D p_Normal)
{
	float resultado = 0;
	if (p_Bola->m_quantidadeMov.m_MaginitudeVetor3D() == 0)
	{
		return resultado;
	}
	if (p_Normal.m_MaginitudeVetor3D() == 0)
	{
		return resultado;
	}
	resultado = p_Bola->m_quantidadeMov.m_DotProduct(p_Normal)/(p_Bola->m_quantidadeMov.m_MaginitudeVetor3D()*p_Normal.m_MaginitudeVetor3D());


	return resultado;
}

Vetor3D Fisica::m_refletirEnergia(Bola* p_Bola,Vetor3D p_vetor, Vetor3D p_Normal)
{
	float massa = 1 / p_Bola->m_massa * 2;
	float x = 1, y = 1, z = 1;
	Vetor3D Nvelocidade = p_Bola->m_velocidade;
	p_vetor *= massa;
	if (p_vetor.m_X < 0)
	{
		x = -1;
	}
	if (p_vetor.m_Y < 0)
	{
		y = -1;
	}
	if (p_vetor.m_Z < 0)
	{
		z = -1;
	}
	Nvelocidade.m_X = sqrt(p_vetor.m_X*x); Nvelocidade.m_Y = sqrt(p_vetor.m_Y*y); Nvelocidade.m_Z = sqrt(p_vetor.m_Z*z);

	Nvelocidade.m_X *= x; Nvelocidade.m_Y *= y; Nvelocidade.m_Z *= z;
	
	Vetor3D resultado;

	resultado = Nvelocidade - p_Normal*(1.3*Nvelocidade.m_DotProduct(p_Normal.m_NormalizaçaoNoV()));

	resultado.m_X = resultado.m_X*resultado.m_X; resultado.m_Y = resultado.m_Y*resultado.m_Y; resultado.m_Z = resultado.m_Z*resultado.m_Z;

	resultado *= p_Bola->m_massa / 2;

	return resultado;
}

void Fisica::m_VerificaColisãoBolas(Gerenciador_Bolas* p_Bolas)
{
	int colidindo;
	int quantidade = p_Bolas->GetSize();
	int* array = new int[quantidade];
	for (int i = 0; i < p_Bolas->GetSize(); i++)
	{
		p_Bolas->m_list_bolas[i]->m_AquantidadeMov();
	}
	for (int i = 0; i < p_Bolas->GetSize(); i++)
	{		
		colidindo = -1;
		for (int j = 0; j < p_Bolas->GetSize(); j++)
		{
			if (i != j)
			{
				if (p_Bolas->m_list_bolas[i]->m_quantidadeMov.m_MaginitudeVetor3D() == 0)
				{
					if (p_Bolas->m_list_bolas[j]->m_quantidadeMov.m_MaginitudeVetor3D() == 0)
					{
						p_Bolas->m_list_bolas[j]->m_estacolidindo = false;
					}
					else
					{
						float distancia = 0, raios = 0;
						distancia = (p_Bolas->m_list_bolas[i]->m_posiçao - p_Bolas->m_list_bolas[j]->m_posiçao).m_MaginitudeVetor3D();
						raios = (p_Bolas->m_list_bolas[i]->m_escala + p_Bolas->m_list_bolas[j]->m_escala).m_MaginitudeVetor3D();
						if (distancia <= raios)
						{
							//m_colisoesBolas(p_Bolas->m_list_bolas[i], p_Bolas->m_list_bolas[j]);
							//m_colisaoBola(p_Bolas->m_list_bolas[i], p_Bolas->m_list_bolas[j]);
							Sons::getInstance().TocaSom(0);
							p_Bolas->m_list_bolas[j]->m_estacolidindo = true;
							colidindo++;
							array[colidindo] = j;
						}
					}
				}
				else
				{					
					float distancia = 0, raios = 0;
					distancia = (p_Bolas->m_list_bolas[i]->m_posiçao - p_Bolas->m_list_bolas[j]->m_posiçao).m_MaginitudeVetor3D();
					raios = (p_Bolas->m_list_bolas[i]->m_escala + p_Bolas->m_list_bolas[j]->m_escala).m_MaginitudeVetor3D();
					if (distancia <= raios)
					{
						//m_colisoesBolas(p_Bolas->m_list_bolas[i], p_Bolas->m_list_bolas[j]);
						//m_colisaoBola(p_Bolas->m_list_bolas[i], p_Bolas->m_list_bolas[j]);
						Sons::getInstance().TocaSom(0);
						p_Bolas->m_list_bolas[j]->m_estacolidindo = true;
						colidindo++;
						array[colidindo] = j;
					}
				}
			}
		}	
		if (colidindo > -1)
		{
			m_ColisaoBolas(p_Bolas, i, colidindo, array);
		}
	}				
}		

Vetor3D Fisica::m_retornaMQ(Bola* p_Bola, float p_cos, Vetor3D p_QM)
{
	
	Vetor3D calculo = p_Bola->m_quantidadeMov*p_cos;
	
	if ((p_QM.m_X > 0 && calculo.m_X < 0) || (p_QM.m_X < 0 && calculo.m_X > 0))
	{
		p_QM.m_X += calculo.m_X;
	}
	else
	{
		p_QM.m_X -= calculo.m_X;
	}
	if ((p_QM.m_Z > 0 && calculo.m_Z < 0) || (p_QM.m_Z < 0 && calculo.m_Z > 0))
	{
		p_QM.m_Z += calculo.m_Z;
	}
	else
	{
		p_QM.m_Z -= calculo.m_Z;
	}
	p_QM *= 0.5;

	return p_QM;
}

void Fisica::m_ColisaoBolas(Gerenciador_Bolas* p_Bolas, int p_verificador, int p_quantidade, int* p_array)
{
	Vetor3D Q_M = p_Bolas->m_list_bolas[p_verificador]->m_quantidadeMov;
	Vetor3D VelocidadeResultante = p_Bolas->m_list_bolas[p_verificador]->m_velocidade;
	Vetor3D VelocidadeResultante2;
	
	for (int i = 0; i < p_quantidade+1; i++)
	{

		Vetor3D Normal1 = (p_Bolas->m_list_bolas[p_verificador]->m_posiçao - p_Bolas->m_list_bolas[p_array[i]]->m_posiçao) / 2;
		Vetor3D Normal2 = (p_Bolas->m_list_bolas[p_array[i]]->m_posiçao - p_Bolas->m_list_bolas[p_verificador]->m_posiçao) / 2;		
		Vetor3D velocidade;
		Normal1.m_NormalizaçaoNoV();
		Normal2.m_NormalizaçaoNoV();
		float Cangulocolisao = m_getAngulocolisao(p_Bolas->m_list_bolas[p_verificador], Normal2);

		float Cangulocolisao2 = m_getAngulocolisao(p_Bolas->m_list_bolas[p_array[i]], Normal1);

		float Cangulo = Cangulocolisao;
		float angulo = p_Bolas->m_list_bolas[p_verificador]->m_quantidadeMov.m_AnguloEntreV(Normal2);
		float angulo2 = p_Bolas->m_list_bolas[p_array[i]]->m_quantidadeMov.m_AnguloEntreV(Normal1);
		if ((angulo < PI / 2 && angulo >= 0 )||( angulo > -PI/2 && angulo <= 0))
		{
			Q_M = m_retornaMQ(p_Bolas->m_list_bolas[p_verificador], Cangulo, Q_M);
			velocidade = Q_M / p_Bolas->m_list_bolas[p_verificador]->m_massa;
			if (velocidade.m_MaginitudeVetor3D() == 0)
			{
				VelocidadeResultante = Vetor3D(0, 0, 0);
			}
			else
			{
				VelocidadeResultante = velocidade - Normal1 * (1.9 *(velocidade.m_DotProduct(Normal1.m_NormalizaçaoNoV())));

			}
		}
		if ((angulo2 < PI / 2 && angulo2 >= 0) ||( angulo2 > -PI / 2 && angulo2 <= 0))
		{
			Vetor3D velocidadeaqui = Normal1*p_Bolas->m_list_bolas[p_array[i]]->m_quantidadeMov.m_MaginitudeVetor3D()*Cangulocolisao2 / p_Bolas->m_list_bolas[p_array[i]]->m_massa;
			float sen, cos;
			if (Normal1.m_Z == 0)
			{
				sen = 0;
			}
			else
			{
				sen = Normal1.m_Z / Normal1.m_MaginitudeVetor3D();
			}
			if (Normal1.m_X == 0)
			{
				cos = 0;
			}
			else
			{
				cos = Normal1.m_X / Normal1.m_MaginitudeVetor3D();
			}			
			float força = p_Bolas->m_list_bolas[p_array[i]]->m_quantidadeMov.m_MaginitudeVetor3D()*Cangulocolisao2;
			velocidadeaqui.m_X = cos*força / p_Bolas->m_list_bolas[p_array[i]]->m_massa;
			velocidadeaqui.m_Z = sen*força / p_Bolas->m_list_bolas[p_array[i]]->m_massa;
	
			
			VelocidadeResultante2 += velocidadeaqui*0.9;
		}		
	}
	p_Bolas->m_list_bolas[p_verificador]->m_velocidade = VelocidadeResultante + VelocidadeResultante2;
}




void Fisica::m_VerificaColisãoParede(Gerenciador_Bolas* p_Bolas, int p_quantidade)
{	/*for (int i = 0; i < p_quantidade; i++)
	{
		m_colisaoParedes(p_Bola, p_Objeto[i]);
	}*/
	for (int i = 0; i<p_quantidade; i++)
	{
		if (p_Bolas->m_list_bolas[i]->m_velocidade.m_MaginitudeVetor3D() != 0)
		{
			if (p_Bolas->m_list_bolas[i]->m_posiçao.m_Z + p_Bolas->m_list_bolas[i]->m_escala.m_Z + p_Bolas->m_list_bolas[i]->m_velocidade.m_Z > 46 || p_Bolas->m_list_bolas[i]->m_posiçao.m_Z - p_Bolas->m_list_bolas[i]->m_escala.m_Z + p_Bolas->m_list_bolas[i]->m_velocidade.m_Z < -46)
			{
				m_ReflexãoParede(p_Bolas->m_list_bolas[i], Vetor3D(0, 0, p_Bolas->m_list_bolas[i]->m_posiçao.m_Z + p_Bolas->m_list_bolas[i]->m_escala.m_Z > 46 ? 1.0f : -1.0f));
			}
			if (p_Bolas->m_list_bolas[i]->m_posiçao.m_X + p_Bolas->m_list_bolas[i]->m_escala.m_X + p_Bolas->m_list_bolas[i]->m_velocidade.m_X > 18 || p_Bolas->m_list_bolas[i]->m_posiçao.m_X - p_Bolas->m_list_bolas[i]->m_escala.m_X + p_Bolas->m_list_bolas[i]->m_velocidade.m_X< -18)
			{
				m_ReflexãoParede(p_Bolas->m_list_bolas[i], Vetor3D(p_Bolas->m_list_bolas[i]->m_posiçao.m_X + p_Bolas->m_list_bolas[i]->m_escala.m_X > 18 ? 1.0f : -1.0f, 0, 0));
			}
		}		
	}
	
}

Vetor3D Fisica::m_calculaNormal(Vetor3D p_ponto, Objeto p_colider)
{
	int contador =6;
	int contador2 = 3;
	Vetor3D* posiçoes= new Vetor3D[3];
	int ver = 0;
	int z = 0;
	for (int i = 0; i < contador;i++)
	{
		for (int e = 0; e < contador2; e++)
		{
		
			if (p_ponto.m_Z == p_colider.m_corpo->m_mesh->lstpoligons[i].m_vertices[e].m_Z + p_colider.m_escala.m_Z)
			{
				posiçoes[z] = p_colider.m_corpo->m_mesh->lstpoligons[i].m_vertices[e];
				ver = 0;
				z++;
			}
			else
			{
				if (p_ponto.m_Z == p_colider.m_corpo->m_mesh->lstpoligons[i].m_vertices[e].m_Z - p_colider.m_escala.m_Z)
				{
					posiçoes[z] = p_colider.m_corpo->m_mesh->lstpoligons[i].m_vertices[e];
					ver = 1;
					z++;
				}
				else
				{
					if (p_ponto.m_X == p_colider.m_corpo->m_mesh->lstpoligons[i].m_vertices[e].m_X + p_colider.m_escala.m_X)
					{
						posiçoes[z] = p_colider.m_corpo->m_mesh->lstpoligons[i].m_vertices[e];
						ver = 1;
						z++;
					}
					else
					{
						if (p_ponto.m_X == p_colider.m_corpo->m_mesh->lstpoligons[i].m_vertices[e].m_X - p_colider.m_escala.m_X)
						{
							posiçoes[z] = p_colider.m_corpo->m_mesh->lstpoligons[i].m_vertices[e];
							ver = 1;
							z++;
						}
					}
				}
				
				
			}
		}			
	}
	Vetor3D Normal = (posiçoes[0] - posiçoes[1]).m_CrossProduct(posiçoes[0] - posiçoes[2]);
	return Normal;
}

bool Fisica::SphereCollisionCheck(Objeto * primeiro, Objeto * segundo)
{

	float distatual;
	distatual = (primeiro->m_posiçao - segundo->m_posiçao).m_MaginitudeVetor3D();

	float distmin = (primeiro->m_escala + segundo->m_escala).m_MaginitudeVetor3D();
	//distmin *= 0.5f;

	if (distatual >= distmin * 0.6f)
		return false;


	return true;


}
bool Fisica::SphereBoxCollisionChck(Objeto * cubo, Objeto * esfera)
{
	Vetor3D P;

	int left, right, top, down, front, back;

	
	left = cubo->m_posiçao.m_X - cubo->m_escala.m_X;
	right = cubo->m_posiçao.m_X + cubo->m_escala.m_X;

	top = cubo->m_posiçao.m_Y + cubo->m_escala.m_Y;
	down = cubo->m_posiçao.m_Y - cubo->m_escala.m_Y;

	front = cubo->m_posiçao.m_Z + cubo->m_escala.m_Z;
	back = cubo->m_posiçao.m_Z - cubo->m_escala.m_Z;

	if (esfera->m_posiçao.m_Y > top)
		P.m_Y = top;
	else if (esfera->m_posiçao.m_Y < down)
		P.m_Y = down;
	else
		P.m_Y = esfera->m_posiçao.m_Y;


	if (esfera->m_posiçao.m_X > right)
		P.m_X = right;
	else if (esfera->m_posiçao.m_X < left)
		P.m_X = left;
	else
		P.m_X = esfera->m_posiçao.m_X;


	if (esfera->m_posiçao.m_Z > front)
		P.m_Z = front;
	else if (esfera->m_posiçao.m_Z < back)
		P.m_Z = back;
	else
		P.m_Z = esfera->m_posiçao.m_Z;


	Vetor3D dist_real = esfera->m_posiçao - P;

	if (esfera->m_escala.m_X > dist_real.m_MaginitudeVetor3D())
		return false;
	

		return true;
}



void Fisica::m_AplicaAtritoDinâmicoSolo(Bola* p_Bola, Superficie p_Superficie)
{
	Vetor3D menor0;
	
		if (p_Bola->m_velocidade.m_MaginitudeVetor3D() != 0)
		{
			menor0 = p_Bola->m_velocidade.m_Normalizaçao()*p_Superficie.m_NormalD(p_Bola->m_massa, m_gravidade)*-1;
			p_Bola->m_Impulso = menor0;
		}
}
