#include "Objetos_Complexos.h"


Objetos_Complexos::Objetos_Complexos()
{
}


Objetos_Complexos::~Objetos_Complexos()
{
}


Mesa::Mesa()
{
	m_qtd_objs = 11;
	m_objs = new Objeto*[m_qtd_objs];
	CriaCorpo();
}
void Mesa::Draw()
{
	for (int i = 0; i < m_qtd_objs; i++)
	{
		m_objs[i]->Draw();
	}

}
void Mesa::CriaCorpo()
{
	m_objs[0] = new Paralelepipdo(Vetor3D(0,2, 0), Vetor3D(20,6,46));
	m_objs[1] = new Paralelepipdo(Vetor3D(0, 10, -47), Vetor3D(17, 2, 2)); /// Baixo
	m_objs[2] = new Paralelepipdo(Vetor3D(0, 10, 47), Vetor3D(17, 2, 2));// Cima
	m_objs[3] = new Paralelepipdo(Vetor3D(-21, 10, 21), Vetor3D(2, 2, 17)); /// Esquerda
	m_objs[4] = new Paralelepipdo(Vetor3D(21, 10, -21), Vetor3D(2, 2, 17));///Direita

	m_objs[5] = new Paralelepipdo(Vetor3D(-21, 10, -21), Vetor3D(2, 2, 17)); /// Esquerda
	m_objs[6] = new Paralelepipdo(Vetor3D(21, 10, 21), Vetor3D(2, 2, 17));///Direita

	m_objs[7] = new Paralelepipdo(Vetor3D(-15, -21, -39), Vetor3D(4, 18, 6)); /// perna
	m_objs[8] = new Paralelepipdo(Vetor3D(-15, -21, 39), Vetor3D(4, 18, 6));// perna
	m_objs[9] = new Paralelepipdo(Vetor3D(15, -21, -39), Vetor3D(4, 18, 6)); /// perna
	m_objs[10] = new Paralelepipdo(Vetor3D(15, -21, 39), Vetor3D(4, 18, 6));///perna

	



	m_objs[0]->m_corpo->Set_Face_Texture(4, DARK_GRASS);
	m_objs[1]->m_corpo->Set_Face_Texture(2, GRASS);
	m_objs[2]->m_corpo->Set_Face_Texture(0, GRASS);
	m_objs[3]->m_corpo->Set_Face_Texture(1, GRASS);
	m_objs[4]->m_corpo->Set_Face_Texture(3, GRASS);
	m_objs[5]->m_corpo->Set_Face_Texture(1, GRASS);
	m_objs[6]->m_corpo->Set_Face_Texture(3, GRASS);

}




Skybox::Skybox()
{
	m_qtd_objs = 1;
	m_objs = new Objeto*[m_qtd_objs];
	m_objs[0] = new Sbox(Vetor3D(0, 31, 0), Vetor3D(70, 70, 100));
	CriaCorpo();
}
void Skybox::Draw()
{
	m_objs[0]->Draw();
}
void Skybox::CriaCorpo()
{
	m_objs[0]->m_corpo->Set_Face_Texture(0,STONE_WALL);
	m_objs[0]->m_corpo->Set_Face_Texture(1, STONE_CORRIDOR);
	m_objs[0]->m_corpo->Set_Face_Texture(2, CRAZYWALL);
	m_objs[0]->m_corpo->Set_Face_Texture(3, BRICK_WALL);
	m_objs[0]->m_corpo->Set_Face_Texture(4, CEILING);
	m_objs[0]->m_corpo->Set_Face_Texture(5, FLOOR);

	//m_objs->m_corpo->m_mesh->GetFace(4).Negativa_Normal();
}





Lampada::Lampada()
{
	m_qtd_objs = 2;
	m_objs = new Objeto*[m_qtd_objs];
	
	CriaCorpo(Vetor3D(0,0,0));
}
Lampada::Lampada(Vetor3D p_pos)
{
	m_qtd_objs = 2;
	m_objs = new Objeto*[m_qtd_objs];

	CriaCorpo(p_pos);
}
void Lampada::Draw()
{
	for (int i = 0; i < m_qtd_objs; i++)
	{
		m_objs[i]->Draw();
	}
	Light->UseLight();
}
void Lampada::CriaCorpo(Vetor3D p_pos)
{
	//////////////LUZ
	Light = new Luz(p_pos.m_X, p_pos.m_Y - 4, p_pos.m_Z);






	////////////////////////////////CORPO
	m_objs[0] = new Cone(p_pos, Vetor3D(4, 12, 4), 20, 1);
	m_objs[1] = new Cilindro(Vetor3D(p_pos.m_X, p_pos.m_Y + 25, p_pos.m_Z), Vetor3D(1, 18, 1), 20, 1, 1);

	m_objs[0]->m_corpo->UseTexture(false);
	m_objs[1]->m_corpo->UseTexture(false);


	m_objs[0]->m_corpo->SetMaterial(Cor(0, 0, 0, 1), Cor(0, 0, 0, 1), Cor(0, 0, 0, 1), Cor(0, 0, 0, 1), 1, 1);;
	m_objs[1]->m_corpo->SetMaterial(Cor(0, 0, 0, 1), Cor(0, 0, 0, 1), Cor(0, 0, 0, 1), Cor(0, 0, 0, 1), 1, 1);
	//m_objs[0]->m_corpo->SetAllTexture(PRETO);
	//m_objs[1]->m_corpo->SetAllTexture(PRETO);
}



Taco::Taco()
{
	m_qtd_vert = 20;
	m_qtd_objs = 1;
	m_objs = new Objeto*[m_qtd_objs];

	m_objs[0] = new Cilindro(Vetor3D(55,0,0),Vetor3D(1,30,1),m_qtd_vert,0.2f,0.8);

	for (int i = 0; i < m_qtd_vert * 2;i++)
		m_objs[0]->m_corpo->Set_Face_Texture(i,MARROM);

	for (int i = m_qtd_vert * 2; i < m_qtd_vert * 3; i++)
		m_objs[0]->m_corpo->Set_Face_Texture(i, TACO);
	
	


}
Taco::Taco(Vetor3D p_pos,Vetor3D p_dir)
{
	m_qtd_vert = 20;
	m_qtd_objs = 1;
	m_objs = new Objeto*[m_qtd_objs];

	m_objs[0] = new Cilindro(Vetor3D(55, 0, 0), Vetor3D(1, 30, 1), m_qtd_vert, 0.2f, 0.8);

	for (int i = 0; i < m_qtd_vert * 2; i++)
		m_objs[0]->m_corpo->Set_Face_Texture(i, MARROM);

	for (int i = m_qtd_vert * 2; i < m_qtd_vert * 3; i++)
		m_objs[0]->m_corpo->Set_Face_Texture(i, TACO);

	m_objs[0]->m_goback = p_pos;


}

void Taco::Draw()
{
	m_objs[0]->Draw();
}

void Taco::Draw_diferente()
{
	m_objs[0]->Draw2();
}