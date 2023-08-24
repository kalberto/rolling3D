#pragma once
#include"Header.h"
#include"Materials.h"
class Objeto;
class Objetos_Complexos
{
protected:
	
	
public:
	Objetos_Complexos();
	~Objetos_Complexos();
	Objeto Getobj(int n);
	Objeto* Getobjs();
	int geqtdobjs();
	Objeto ** m_objs;
	int m_qtd_objs;
};

class Mesa : public Objetos_Complexos
{
public:
	Mesa();
	void Draw();
	void CriaCorpo();

};

class Skybox : public Objetos_Complexos
{
public:
	Skybox();
	void Draw();
	void CriaCorpo();

};

class Lampada : public Objetos_Complexos
{
private:
	Luz  * Light;
public:
	Lampada();
	Lampada(Vetor3D p_pos);
	void Draw();
	void CriaCorpo(Vetor3D p_pos);
};

class Taco: public Objetos_Complexos
{
private:
	int m_qtd_vert;
public:
	Taco();
	Taco(Vetor3D p_pos,Vetor3D p_dir);
	void Draw();
	void Draw_diferente();
};

