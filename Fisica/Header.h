#pragma once
const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 768;
#include <SDL.h>
#include<SDL_image.h>
#include <SDL_opengl.h>
#include <GL\GLU.h>
#include <stdio.h>
#include <string>
#include <gl/GL.h>
#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include <math.h>
#include <float.h>
#include <Mmsystem.h>
#include <set>
#include <vector>
#include <algorithm>
#include <map>
#include <assert.h>
#include <TCHAR.h>
#include<time.h>

#include "glut.h"
#include"ENUMS.h"
#include "Camera.h"
#include "CameraFPS.h"
#include "Quaternions.h"
#include"Materials.h"
#include"Texture.h"
#include"Gerenciador_Bolas.h"
#include "Camera.h"
#include <objbase.h>
#include <iostream>
#include "Primitivo.h"
#include "Vetor3D.h"
#include "Matrix.h"
#include "Input.h"
#include "World.h"
#include "Bola.h"
#include "Superficie.h"
#include"Time.h"
#include "Fisica.h"
#include"HUD.h"
#include"Jogador.h"
#include "caçapa.h"

#include"Particle.h"
#include"Particle_System.h"


#include"Objetos_Complexos.h"
#define PI 3.14159265359
#define CAMPO_VISAO_PROXIMO     (0.0f)
#define CAMPO_VISAO_DISTANTE    (15000.0f)


#pragma comment(lib, "opengl32.lib"           )
#pragma comment(lib, "glut32.lib"             )
