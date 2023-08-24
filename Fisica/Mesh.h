#include"Poligonos.h"
#include"Materials.h"

class Mesh
{

private:
	
	int qtdpolligonos;
	int count;
	
public:
	Poligon * lstpoligons;
	Mesh(){}

	Materials m_material;

	Mesh(int qtd)
	{
		qtdpolligonos = qtd;
		lstpoligons = new Poligon[qtdpolligonos];
		count = 0;
	}

	void Triangulariza()
	{
		for(int i = 0;i<qtdpolligonos;i++)
		{
			lstpoligons[i].Triangulariza();
		}
	}

	void AddPoligon(Poligon & poligon)
	{
		lstpoligons[count] = poligon;
		count++;
	}

	void DrawMesh()
	{
		int r;
		for(int i = 0;i<qtdpolligonos;i++)
		{
			//r = rand()%6;
			/*switch(i)
			{
				case 0:
					glColor3f(1.0f, 1.0f, 0.0f); 
				break;
				case 1:
					glColor3f(0.0f, 1.0f, 1.0f); 
				break;
				case 2:
					glColor3f(0.0f, 0.0f, 1.0f); 
				break;
				case 3:
					glColor3f(0.0f, 1.0f, 0.0f); 
				break;
				case 4:
					glColor3f(1.0f, 0.0f, 0.0f); 
				break;
				case 5:
					glColor3f(1.0f, 1.0f, 1.0f); 
				break;
			}*/
			/*m_material.UsaCorAmbiente();
			m_material.UsaCorDifusa();
			m_material.UsaCorEmissiva();
			m_material.UsaCorSpecular();
			m_material.UsarCorBrilho();*/
			m_material.UsaMaterial();

			lstpoligons[i].Triangulariza();
			lstpoligons[i].Draw();
		}
		//glBindTexture(GL_TEXTURE_2D,0);
	}
	
	void Load_Pol_Texture(int n)
	{
		for (int i = 0; i < qtdpolligonos; i++)

			lstpoligons[i].SetTexture(n);
	}

	Poligon & GetFace(int n)
	{
		return lstpoligons[n];
	}

	void SetMaterial(Cor A,Cor E,Cor D,Cor S,float opacidade,float brilho)
	{
		m_material.SetAmbiente(A);
		m_material.SetEmissiva(E);
		m_material.SetDifusa(D);
		m_material.SetSpecular(S);
		m_material.SetOpacidade(opacidade);
		m_material.SetBrilho(brilho);
	}

	void UsarTextura(bool b)
	{
		for (int i = 0; i < qtdpolligonos; i++)

			lstpoligons[i].SetT(b);
	}

};