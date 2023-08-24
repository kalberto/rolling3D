#include"Materials.h"


////////////////////////////////////////////////////////        COR         ////////////////////////////////////////////////////

	Cor::Cor()
	{
	m_cor = new float[4];
	};
	Cor::Cor(float p_r, float p_g, float p_b, float p_a)
	{
		m_cor = new float[4];

		m_cor[0] = p_r;
		m_cor[1] = p_g;
		m_cor[2] = p_b;
		m_cor[3] = p_a;

	}
	void Cor::SetCor(float p_r, float p_g, float p_b, float p_a)
	{
		m_cor[0] = p_r;
		m_cor[1] = p_g;
		m_cor[2] = p_b;
		m_cor[3] = p_a;
	}
	void Cor::SetRed(float p_r)
	{
		m_cor[0] = p_r;
	}
	void Cor::SetGreen(float p_g)
	{
		m_cor[1] = p_g;
	}
	void Cor::SetBlue(float p_b)
	{
		m_cor[2] = p_b;
	}
	void Cor::SetAlpha(float p_a)
	{
		m_cor[3] = p_a;
	}
	float Cor::GetRed()
	{
		return m_cor[0];
	}
	float Cor::GetGreen()
	{
		return m_cor[1];
	}
	float Cor::GetBlue()
	{
		return m_cor[2];
	}
	float Cor::GetAlpha()
	{
		return m_cor[3];
	}

	////////////////////////////////////////////////////////        LUZ         ////////////////////////////////////////////////////


		Luz::Luz()
		{
			m_qtd_luzes++;

			m_valor_luz = m_qtd_luzes;

			SetDifusa(1, 0, 0, 1);
			SetSpecular(1, 0, 0, 1);
			SetAmbiente(1, 0, 0, 1);


			Expoente = 0.0f;
			CutOff = 180.0f;
			AtenuacaoConstante = 0.5f;
			AtenuacaoLinear = 0.001f;
			AtenuacaoQuadratica = 0.0001f;

		}
		Luz::Luz(float p_x, float p_y, float p_z)
		{			
			m_qtd_luzes++;

			m_valor_luz = m_qtd_luzes;

			SetDifusa(0.1f,0.1f,0.1f, 1);
			//SetSpecular(1.0f, 1.0f, 1.0f, 1);
			SetSpecular(0.3f,0.3f,0.3f, 1);
			SetAmbiente(0.15f, 0.15f, 0.15f, 1);

			x = p_x;
			dx = 0;
			y = p_y;
			dy = 0;
			z = p_z;
			dz = 0;

			Expoente = 0.0f;
			CutOff = 180.0f;
			AtenuacaoConstante = 0.5f;
			AtenuacaoLinear = 0.001f;
			AtenuacaoQuadratica = 0.0001f;

		}
		Cor Luz::GetDifusa()
		{
			return difusa;
		}
		Cor Luz::GetAmbiente()
		{
			return ambiente;
		}
		Cor Luz::GetSpecular()
		{
			return specular;
		}
		float Luz::GetExpoente()
		{
			return Expoente;
		}
		float Luz::GetAtenuacao_Const()
		{
			return AtenuacaoConstante;
		}
		float Luz::GetAtenuacao_Lin()
		{
			return AtenuacaoLinear;
		}
		float Luz::GetAtenuacao_Quad()
		{
			return AtenuacaoQuadratica;
		}
		void Luz::SetDifusa(Cor p_dif)
		{
			difusa = p_dif;
		}
		void Luz::SetDifusa(float p_r, float p_g, float p_b, float p_a)
		{
			if (p_r > 1)
				p_r = 1;
			else if (p_g > 1)
				p_g = 1;
			else if (p_b > 1)
				p_b = 1;
			else if (p_a > 1)
				p_a = 1;
			difusa.SetCor(p_r, p_g, p_b, p_a);
		}
		void Luz::SetAmbiente(Cor p_dif)
		{
			ambiente = p_dif;
		}
		void Luz::SetAmbiente(float p_r, float p_g, float p_b, float p_a)
		{
			if (p_r > 1)
				p_r = 1;
			else if (p_g > 1)
				p_g = 1;
			else if (p_b > 1)
				p_b = 1;
			else if (p_a > 1)
				p_a = 1;
			ambiente.SetCor(p_r, p_g, p_b, p_a);
		}
		void Luz::SetSpecular(Cor p_dif)
		{
			specular = p_dif;
		}
		void Luz::SetSpecular(float p_r, float p_g, float p_b, float p_a)
		{
			if (p_r > 1)
				p_r = 1;
			else if (p_g > 1)
				p_g = 1;
			else if (p_b > 1)
				p_b = 1;
			else if (p_a > 1)
				p_a = 1;
			specular.SetCor(p_r, p_g, p_b, p_a);
		}
		void Luz::SetExpoente(float p_exp)
		{
			Expoente = p_exp;
		}
		void Luz::SetAtenuacao_Const(float p_exp)
		{
			AtenuacaoConstante = p_exp;
		}
		void Luz::SetAtenuacao_Lin(float p_exp)
		{
			AtenuacaoLinear = p_exp;
		}
		void Luz::SetAtenuacao_Quad(float p_exp)
		{
			AtenuacaoQuadratica = p_exp;
		}
		
		void Luz::UseDifuse()
		{
			float cordl[4];

			cordl[0] = difusa.GetRed();
			cordl[1] = difusa.GetGreen();
			cordl[2] = difusa.GetBlue();
			cordl[3] = difusa.GetAlpha();

			glLightfv(GL_LIGHT0, GL_DIFFUSE, cordl);
		}

		void Luz::UseAmbient()
		{
			float coral[4];

			coral[0] = ambiente.GetRed();
			coral[1] = ambiente.GetGreen();
			coral[2] = ambiente.GetBlue();
			coral[3] = ambiente.GetAlpha();

			glLightfv(GL_LIGHT0, GL_AMBIENT, coral);
		}

		void Luz::UseSpecular()
		{
			float corsl[4];

			corsl[0] = specular.GetRed();
			corsl[1] = specular.GetGreen();
			corsl[2] = specular.GetBlue();
			corsl[3] = specular.GetAlpha();

			glLightfv(GL_LIGHT0, GL_SPECULAR, corsl);
		}

		void Luz::UsePosition()
		{
			float pos[4];
			pos[0] = x;
			pos[1] = y;
			pos[2] = z;
			pos[3] = 1.0f;
			glLightfv(GL_LIGHT0, GL_POSITION, pos);

			float dir[4];
			dir[0] = dx;
			dir[1] = dy;
			dir[2] = dz;
			dir[3] = 1.0f;
			glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, dir);


		}

		void Luz::UseLight()
		{
			StartLight();

			Update();
		//	LightParameters();

			
		}

		void Luz::Update()
		{
			float cordl[4];

			cordl[0] = difusa.GetRed();
			cordl[1] = difusa.GetGreen();
			cordl[2] = difusa.GetBlue();
			cordl[3] = difusa.GetAlpha();

			float coral[4];

			coral[0] = ambiente.GetRed();
			coral[1] = ambiente.GetGreen();
			coral[2] = ambiente.GetBlue();
			coral[3] = ambiente.GetAlpha();

			float corsl[4];

			corsl[0] = specular.GetRed();
			corsl[1] = specular.GetGreen();
			corsl[2] = specular.GetBlue();
			corsl[3] = specular.GetAlpha();


			float pos[4];
			pos[0] = x;
			pos[1] = y;
			pos[2] = z;
			pos[3] = 1.0f;

			float dir[4];
			dir[0] = dx;
			dir[1] = dy;
			dir[2] = dz;
			dir[3] = 1.0f;

			switch (m_valor_luz)
			{
			case 1:
				glEnable(GL_LIGHT0);

				glLightfv(GL_LIGHT0, GL_DIFFUSE, cordl);
				glLightfv(GL_LIGHT0, GL_AMBIENT, coral);
				glLightfv(GL_LIGHT0, GL_SPECULAR, corsl);
				glLightfv(GL_LIGHT0, GL_POSITION, pos);
				glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, dir);

				glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 180.0f);
				glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, AtenuacaoConstante);
				glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, AtenuacaoLinear);
				glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, AtenuacaoQuadratica);
				break;
			case 2:
				glEnable(GL_LIGHT1);

				glLightfv(GL_LIGHT1, GL_DIFFUSE, cordl);
				glLightfv(GL_LIGHT1, GL_AMBIENT, coral);
				glLightfv(GL_LIGHT1, GL_SPECULAR, corsl);
				glLightfv(GL_LIGHT1, GL_POSITION, pos);
				glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, dir);

				glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 180.0f);
				glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, AtenuacaoConstante);
				glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, AtenuacaoLinear);
				glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, AtenuacaoQuadratica);
				break;
			case 3:
				glEnable(GL_LIGHT2);

				glLightfv(GL_LIGHT2, GL_DIFFUSE, cordl);
				glLightfv(GL_LIGHT2, GL_AMBIENT, coral);
				glLightfv(GL_LIGHT2, GL_SPECULAR, corsl);
				glLightfv(GL_LIGHT2, GL_POSITION, pos);
				glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, dir);

				glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, 180.0f);
				glLightf(GL_LIGHT2, GL_CONSTANT_ATTENUATION, AtenuacaoConstante);
				glLightf(GL_LIGHT2, GL_LINEAR_ATTENUATION, AtenuacaoLinear);
				glLightf(GL_LIGHT2, GL_QUADRATIC_ATTENUATION, AtenuacaoQuadratica);
				break;
			case 4:
				glEnable(GL_LIGHT3);

				glLightfv(GL_LIGHT3, GL_DIFFUSE, cordl);
				glLightfv(GL_LIGHT3, GL_AMBIENT, coral);
				glLightfv(GL_LIGHT3, GL_SPECULAR, corsl);
				glLightfv(GL_LIGHT3, GL_POSITION, pos);
				glLightfv(GL_LIGHT3, GL_SPOT_DIRECTION, dir);

				glLightf(GL_LIGHT3, GL_SPOT_CUTOFF, 180.0f);
				glLightf(GL_LIGHT3, GL_CONSTANT_ATTENUATION, AtenuacaoConstante);
				glLightf(GL_LIGHT3, GL_LINEAR_ATTENUATION, AtenuacaoLinear);
				glLightf(GL_LIGHT3, GL_QUADRATIC_ATTENUATION, AtenuacaoQuadratica);
				break;
			case 5:
				glEnable(GL_LIGHT4);

				glLightfv(GL_LIGHT4, GL_DIFFUSE, cordl);
				glLightfv(GL_LIGHT4, GL_AMBIENT, coral);
				glLightfv(GL_LIGHT4, GL_SPECULAR, corsl);
				glLightfv(GL_LIGHT4, GL_POSITION, pos);
				glLightfv(GL_LIGHT4, GL_SPOT_DIRECTION, dir);

				glLightf(GL_LIGHT4, GL_SPOT_CUTOFF, 180.0f);
				glLightf(GL_LIGHT4, GL_CONSTANT_ATTENUATION, AtenuacaoConstante);
				glLightf(GL_LIGHT4, GL_LINEAR_ATTENUATION, AtenuacaoLinear);
				glLightf(GL_LIGHT4, GL_QUADRATIC_ATTENUATION, AtenuacaoQuadratica);
				break;
			}

		}

		void Luz::StartLight()
		{
			glShadeModel(GL_SMOOTH);//Habilita o Tipo de Algoritmo de Sombreamento Gouraud.
			glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);//Faz a Luz ambiente levar em conta a posição do Viewer.
			//glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);//Habilita Iluminação nos dois lados do Poligono.
			//
			
		}
		void Luz::LightParameters()
		{
			//Repassa para OpenGL parametros de calculo de Iluminação da Luz
			
		}



///////////////////////////////////////////////              MATERIAL               //////////////////////////////////////




			Materials::Materials()
			{
				SetDifusa(1, 1, 1, 1);
				SetAmbiente(0.5f, 0.5f, 0.5f, 1);
				SetEmissiva(0.5f, 0.5f, 0.5f, 1);
				SetSpecular(0.5f, 0.5f, 0.5f, 1);
				SetOpacidade(2);
				SetBrilho(60);
			}
			Materials::~Materials(void)
			{

			}

			Cor Materials::GetDifusa()
			{
				return difusa;
			}
			Cor Materials::GetAmbiente()
			{
				return ambiente;
			}
			Cor Materials::GetEmissiva()
			{
				return emissiva;
			}
			Cor Materials::GetSpecular()
			{
				return specular;
			}
			float Materials::GetOpacidade()
			{
				return opacidade;
			}
			float Materials::GetBrilho()
			{
				return brilho;
			}

			void Materials::SetDifusa(Cor p_dif)
			{
				difusa = p_dif;
			}
			void Materials::SetDifusa(float p_r, float p_g, float p_b, float p_a)
			{
				if (p_r > 1)
					p_r = 1;
				else if (p_g > 1)
					p_g = 1;
				else if (p_b > 1)
					p_b = 1;
				else if (p_a > 1)
					p_a = 1;
				difusa.SetCor(p_r, p_g, p_b, p_a);
			}

			void Materials::SetAmbiente(Cor p_dif)
			{
				ambiente = p_dif;
			}
			void Materials::SetAmbiente(float p_r, float p_g, float p_b, float p_a)
			{
				if (p_r > 1)
					p_r = 1;
				else if (p_g > 1)
					p_g = 1;
				else if (p_b > 1)
					p_b = 1;
				else if (p_a > 1)
					p_a = 1;
				ambiente.SetCor(p_r, p_g, p_b, p_a);
			}

			void Materials::SetEmissiva(Cor p_dif)
			{
				emissiva = p_dif;
			}
			void Materials::SetEmissiva(float p_r, float p_g, float p_b, float p_a)
			{
				if (p_r > 1)
					p_r = 1;
				else if (p_g > 1)
					p_g = 1;
				else if (p_b > 1)
					p_b = 1;
				else if (p_a > 1)
					p_a = 1;
				emissiva.SetCor(p_r, p_g, p_b, p_a);
			}

			void Materials::SetSpecular(Cor p_dif)
			{
				specular = p_dif;
			}
			void Materials::SetSpecular(float p_r, float p_g, float p_b, float p_a)
			{
				if (p_r > 1)
					p_r = 1;
				else if (p_g > 1)
					p_g = 1;
				else if (p_b > 1)
					p_b = 1;
				else if (p_a > 1)
					p_a = 1;
				specular.SetCor(p_r, p_g, p_b, p_a);
			}
			void Materials::SetOpacidade(float p_op)
			{
				if (p_op <= 1)
					opacidade = p_op;
				else
					opacidade = 1;
			}
			void Materials::SetBrilho(float p_bri)
			{
				if (p_bri <= 1)
					brilho = p_bri;
				else
					brilho = 1;
			}

			void Materials::AddOpacidade(float p_op)
			{
				opacidade += p_op;
				if (opacidade > 1)
					opacidade = 1;
			}
			void Materials::AddBrilho(float p_bri)
			{
				brilho += p_bri;
				if (brilho > 1)
					brilho = 1;
			}

			void Materials::UsaCorAmbiente()
			{
				float cora[4];
				cora[0] = ambiente.GetRed();
				cora[1] = ambiente.GetGreen();
				cora[2] = ambiente.GetBlue();
				cora[3] = ambiente.GetAlpha();

				glMaterialfv(GL_FRONT, GL_AMBIENT, cora);
			}

			void Materials::UsaCorDifusa()
			{
				float cora[4];
				cora[0] = difusa.GetRed();
				cora[1] = difusa.GetGreen();
				cora[2] = difusa.GetBlue();
				cora[3] = difusa.GetAlpha();

				glMaterialfv(GL_FRONT, GL_DIFFUSE, cora);
			}

			void Materials::UsaCorSpecular()
			{
				float cora[4];
				cora[0] = specular.GetRed();
				cora[1] = specular.GetGreen();
				cora[2] = specular.GetBlue();
				cora[3] = specular.GetAlpha();

				glMaterialfv(GL_FRONT, GL_SPECULAR, cora);
			}
			void Materials::UsaCorEmissiva()
			{
				float cora[4];
				cora[0] = emissiva.GetRed();
				cora[1] = emissiva.GetGreen();
				cora[2] = emissiva.GetBlue();
				cora[3] = emissiva.GetAlpha();

				glMaterialfv(GL_FRONT, GL_EMISSION, cora);
			}
			void Materials::UsarCorBrilho()
			{
				glMaterialf(GL_FRONT, GL_SHININESS, brilho);
			}

			void Materials::ChecarOpacidade()
			{
				if (opacidade < 1.0f)
				{
					glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
					glDepthMask(GL_FALSE);
				}
				else
				{
					glDisable(GL_BLEND);
					glDepthMask(GL_TRUE);
				}
			}

			void Materials::UsaMaterial()
			{
				//Inicializar_GL_Material();
				UsaCorAmbiente();
				UsaCorDifusa();
				UsaCorEmissiva();
				UsaCorSpecular();
				UsarCorBrilho();
			}
			void Materials::Inicializar_GL_Material()
			{
				glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
				//glDepthMask(GL_FALSE);
				ChecarOpacidade();
			}
			