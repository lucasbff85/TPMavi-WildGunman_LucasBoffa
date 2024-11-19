#pragma once
#include "stdafx.h";

using namespace sf;

class Personaje {
	Texture tex_window;
	Texture tex_personaje;
	Sprite sprite_window;
	Sprite sprite_personaje;
	bool esInocente = true; 


public:
	Personaje(bool inocente) {
		if (inocente) {
			esInocente = inocente;
			tex_personaje.loadFromFile("../Assets/sheffer-fall.png");
		}
		else {
			esInocente = inocente;
			tex_personaje.loadFromFile("../Assets/randy-aim-eyes-not-shine.png");
		}
	}
};
