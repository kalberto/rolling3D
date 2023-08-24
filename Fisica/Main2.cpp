/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL, SDL OpenGL, standard IO, and, strings
#pragma once

#include<tchar.h>
#include<stdio.h>
#include<iostream>
#include "Header.h"
#include"GameManager.h"
#include"Music.h"
#include"CHEATS.h"
int Luz::m_qtd_luzes = 0;

//Texture Texture::texturas = nullptr;




void MapeiaMouse();

void ProcessaComandos();

bool init();

bool initGL();



//void handleKeys(unsigned char key, int x, int y);

void update();

void render();

void close();


SDL_Window* gWindow = NULL;
SDL_GLContext gContext;


GameManager game;


bool init()
{
	srand(time(NULL));

	bool success = true;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{

		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);

		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{

			gContext = SDL_GL_CreateContext(gWindow);
			if (gContext == NULL)
			{
				printf("OpenGL context could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{

				if (SDL_GL_SetSwapInterval(1) < 0)
				{
					printf("Warning: Unable to set VSync! SDL Error: %s\n", SDL_GetError());
				}

				if (!initGL())
				{
					printf("Unable to initialize OpenGL!\n");
					success = false;
				}
			}
		}
	}
	//mundo.SetGrid_X(256);
	////cam.m_PosCam = Vetor3D(5.0f, 98.0f, 11.0f);
	////cam.m_ViewCam = Vetor3D(0.0f, 6.0f, 0.0f);
	////cam.m_UpCam = Vetor3D(0.0f, 1.0f, 0.0f);
	//

	//novamesa = new Mesa();

	////newsystem = new Particle_System(Vetor3D(0, 12, -28), Vetor3D(0, 0, 1), 100);


	//Bolas = new Gerenciador_Bolas();
	////Bolas->m_list_bolas[0]->m_velocidade = Vetor3D(0, 0, 0.5);
	////bola->m_corpo->Set
	//// ("caixa.bmp");
	//m_jogador = new Jogador(Bolas->GetElement(0));

	//luminaria = new Lampada[3];
	//luminaria[0] = Lampada(Vetor3D(0,60, 20));
	//luminaria[1] = Lampada(Vetor3D(0, 60, 0));
	//luminaria[2] = Lampada(Vetor3D(0, 60, -20));
	//m_caçapa = new caçapa;
	//WORLD = new Skybox();
	//m_super.m_atritoDinâmico = 0.01;
	return success;
}

bool initGL()
{
	bool success = true;
	GLenum error = GL_NO_ERROR;

	error = glGetError();
	if (error != GL_NO_ERROR)
	{
		printf("Error initializing OpenGL! %s\n", gluErrorString(error));
		success = false;
	}

	error = glGetError();
	if (error != GL_NO_ERROR)
	{
		printf("Error initializing OpenGL! %s\n", gluErrorString(error));
		success = false;
	}

	glClearColor(0.f, 0.f, 0.f, 1.f);

	error = glGetError();
	if (error != GL_NO_ERROR)
	{
		printf("Error initializing OpenGL! %s\n", gluErrorString(error));
		success = false;
	}
	

	return success;
}

void TrueUpdate()
{ 	
	game.UpdatePrincipal();
	game.UpdateSecundario();

}


void close()
{

	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	SDL_Quit();
}

int main(int argc, char* args[])
{
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		bool quit = false;

		SDL_Event e;

		SDL_StartTextInput();

		Texture::getInstance().Create();
		Input::getInstance().Create();
		Sons::getInstance().Create();
		Cheat::getInstance().Create();
		while (!quit)
		{

			while (SDL_PollEvent(&e) != 0)
			{

				if (e.type == SDL_QUIT)
				{
					quit = true;
				}

				else if (e.type == SDL_TEXTINPUT)
				{
					int x = 0, y = 0;
					SDL_GetMouseState(&x, &y);
					//handleKeys(e.text.text[0], x, y);
				}
			}

			TrueUpdate();

			SDL_GL_SwapWindow(gWindow);
		}

		SDL_StopTextInput();
	}

	close();

	return 0;
}