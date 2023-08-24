#pragma once
#include"Header.h"

//#define TEXTURAS Texture::getInstance()
#define QTD_TEXTURES 29



class Texture
{
private:
	int m_textura_atual = 0;
	GLuint m_list_textures[QTD_TEXTURES];
	

public:
	Texture()
	{	}

	static GLuint GetTexture(int n)
	{		
			return getInstance().m_list_textures[n];
	}

	GLuint createTexture(char* name){
		SDL_Surface *imagem = IMG_Load(name);
		if (!imagem) return -1;

		//unsigned 
		
		GLuint textura = 0;
		glGenTextures(1, &textura);

		//std::cout << glGetError() << std::endl;


		glBindTexture(GL_TEXTURE_2D, textura);
		//std::cout << glGetError() << std::endl;


		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

		GLint format = imagem->format->BytesPerPixel == 3 ? GL_RGB : GL_RGBA;
		glTexImage2D(GL_TEXTURE_2D,
			0,
			format,
			imagem->w,
			imagem->h,
			0,
			format,
			GL_UNSIGNED_BYTE,
			imagem->pixels);
		SDL_FreeSurface(imagem);

	//	glBindTexture(GL_TEXTURE_2D,textura);
		return textura;
	}
	
	static bool TrocarTextura(GLuint p_text_obj)
	{
		if (p_text_obj == getInstance().m_textura_atual)
		{
			return false;
		}
		else
		{
			getInstance().m_textura_atual = p_text_obj;
			return true;
		}
	}
	
	static Texture & getInstance()
	{
		static Texture texturas;
	
		return texturas;
	}
	
	void Create()
	{
		m_list_textures[0] = createTexture("caixa.jpg");
		m_list_textures[1] = createTexture("grass.jpg");
		m_list_textures[2] = createTexture("stone_wall.jpg");
		m_list_textures[3] = createTexture("brick_wall.jpg");
		m_list_textures[4] = createTexture("stone_corridor.jpg");
		m_list_textures[5] = createTexture("crazystone_wall.jpg");
		m_list_textures[6] = createTexture("stone_floor.jpg");
		m_list_textures[7] = createTexture("ceiling.jpg");
		m_list_textures[8] = createTexture("darkgrass.jpg");
		m_list_textures[9] = createTexture("Taco.jpg");
		m_list_textures[10] = createTexture("Marrom.jpg");
		m_list_textures[11] = createTexture("Preto.jpg");
		m_list_textures[12] = createTexture("Medidor.png");
		m_list_textures[13] = createTexture("Parcial_medidor.png");
		m_list_textures[14] = createTexture("player1.png");
		m_list_textures[15] = createTexture("player2.png");
		m_list_textures[16] = createTexture("num0.png");
		m_list_textures[17] = createTexture("num1.png");
		m_list_textures[18] = createTexture("num2.png");
		m_list_textures[19] = createTexture("num3.png");
		m_list_textures[20] = createTexture("num4.png");
		m_list_textures[21] = createTexture("num5.png");
		m_list_textures[22] = createTexture("num6.png");
		m_list_textures[23] = createTexture("DBZ_aura.png");
		m_list_textures[24] = createTexture("prof1.jpg");
		m_list_textures[25] = createTexture("prof2.jpg");
		m_list_textures[26] = createTexture("prof3.jpg");
		m_list_textures[27] = createTexture("prof4.jpg");
		m_list_textures[28] = createTexture("water_txt.png");
	}

};


