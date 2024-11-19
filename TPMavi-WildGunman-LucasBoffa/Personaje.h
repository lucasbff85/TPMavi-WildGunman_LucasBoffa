#pragma once
#include "stdafx.h";

using namespace sf;

class Personaje {
	Texture tex_villano;
	Texture tex_inocente;
	Sprite sprite_villano;
	Sprite sprite_inocente;
	bool esInocente; 
	int tipo;
	bool inWindow;


public:
	Personaje(bool status, int tipo) {
		esInocente = status;
		tex_inocente.loadFromFile("../Assets/sheffer-fall.png");
		tex_villano.loadFromFile("../Assets/randy-aim-eyes-not-shine.png");
		sprite_inocente.setTexture(tex_inocente);
		sprite_villano.setTexture(tex_villano);
		
	}

	void Dibujar(RenderWindow* wnd,Vector2f posicion) {
		if (esInocente) {
			sprite_inocente.setPosition(posicion);
			wnd->draw(sprite_inocente);
		}
		else {
			sprite_villano.setPosition(posicion);
			wnd->draw(sprite_villano);
		}
	}
};
