#pragma once
#include "stdafx.h"

using namespace sf;

class Personaje {
	Texture tex_villanoMark;
	Texture tex_villanoBilly;
	Texture tex_villanoRandy;

	Texture tex_inocenteBob;
	Texture tex_inocenteSheffer;

	Sprite sprite;  

	bool esInocente;
	int tipo;  // tipo va del 1 al 5

public:
	bool _derrotado;

	Personaje(bool _inocente, int _tipo) {
		_derrotado = false;
		esInocente = _inocente;
		tipo = _tipo;

		// Cargar las texturas
		tex_villanoMark.loadFromFile("../Assets/mark.png");
		tex_villanoBilly.loadFromFile("../Assets/billy.png");
		tex_villanoRandy.loadFromFile("../Assets/randy.png");

		tex_inocenteBob.loadFromFile("../Assets/bob.png");
		tex_inocenteSheffer.loadFromFile("../Assets/sheffer.png");

		// Asignar la textura correcta según el tipo
		if (esInocente) {
			if (tipo == 1) {
				sprite.setTexture(tex_inocenteBob);
			}
			else if (tipo == 2) {
				sprite.setTexture(tex_inocenteSheffer);
			}
		}
		else {
			if (tipo == 3) {
				sprite.setTexture(tex_villanoBilly);
			}
			else if (tipo == 4) {
				sprite.setTexture(tex_villanoMark);
			}
			else if (tipo == 5) {
				sprite.setTexture(tex_villanoRandy);
			}
		}

		//configuro el origen en la base
		sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height); 
		sprite.setScale(2.2, 2.2);

	}

	void Dibujar(RenderWindow* wnd, Vector2f posicion) {
		sprite.setPosition(posicion);
		wnd->draw(sprite);
	}

	// Comprobar si el mouse está encima del personaje
	bool EstaEncima(float x, float y) {
		FloatRect bounds = sprite.getGlobalBounds();
		return bounds.contains(x, y);
	}

	
	void Derrotar() {
		_derrotado = true;
	}

	bool getInocente() {
		return esInocente;
	}

	Vector2f posicion() {
		return sprite.getPosition();
	}
};
