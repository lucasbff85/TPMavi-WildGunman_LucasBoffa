#pragma once
#include "stdafx.h";

using namespace sf;

class Personaje {
	Texture tex_villanoMark;
	Texture tex_villanoBilly;
	Texture tex_villanoRandy;

	Texture tex_inocenteBob;
	Texture tex_inocenteSheffer;

	Sprite sprite_villanoMark;
	Sprite sprite_villanoBilly;
	Sprite sprite_villanoRandy;

	Sprite sprite_inocenteBob;
	Sprite sprite_inocenteSheffer;

	bool esInocente; 
	int tipo;  //tipo va del 1 al 5


public:
	bool _estaVivo;

	Personaje(bool _inocente, int _tipo) {
		_estaVivo = true;
		esInocente = _inocente;
		tipo = _tipo;
		

		tex_villanoMark.loadFromFile("../Assets/mark.png");
		tex_villanoBilly.loadFromFile("../Assets/billy.png");
		tex_villanoRandy.loadFromFile("../Assets/randy.png");

		tex_inocenteBob.loadFromFile("../Assets/bob.png");
		tex_inocenteSheffer.loadFromFile("../Assets/sheffer.png");

		sprite_villanoMark.setTexture(tex_villanoMark);
		sprite_villanoBilly.setTexture(tex_villanoBilly);
		sprite_villanoRandy.setTexture(tex_villanoRandy);

		sprite_inocenteBob.setTexture(tex_inocenteBob);
		sprite_inocenteSheffer.setTexture(tex_inocenteSheffer);

		setOrigen(sprite_inocenteBob);
		setOrigen(sprite_inocenteSheffer);
		setOrigen(sprite_villanoBilly);
		setOrigen(sprite_villanoMark);
		setOrigen(sprite_villanoRandy);


		sprite_inocenteBob.setScale(2, 2);
		sprite_inocenteSheffer.setScale(2,2);
		sprite_villanoMark.setScale(2, 2);
		sprite_villanoBilly.setScale(2.5, 2.5);
		sprite_villanoRandy.setScale(2, 2);

		
	}

	void setOrigen(Sprite sprite) {
		sprite.setOrigin(sprite.getGlobalBounds().width / 2,
			sprite.getGlobalBounds().height);
	}

	void Dibujar(RenderWindow* wnd,Vector2f posicion) {
		if (esInocente) {
			if (tipo == 1) {
				sprite_inocenteBob.setPosition(posicion);
				wnd->draw(sprite_inocenteBob);
			}
			else {
				sprite_inocenteSheffer.setPosition(posicion);
				wnd->draw(sprite_inocenteSheffer);
			}
			
		}
		else {
			if (tipo == 3) {
				sprite_villanoBilly.setPosition(posicion);
				wnd->draw(sprite_villanoBilly);
			}
			else if (tipo == 4) {
				sprite_villanoMark.setPosition(posicion);
				wnd->draw(sprite_villanoMark);
			}
			else {
				sprite_villanoRandy.setPosition(posicion);
				wnd->draw(sprite_villanoRandy);
			}
		}
	}


	bool EstaEncima(float x, float y) {
		//devuelve un rectangulo
		FloatRect bounds;

		if (esInocente) {
			if (tipo == 1)
				bounds = sprite_inocenteBob.getGlobalBounds();
			else
				bounds = sprite_inocenteSheffer.getGlobalBounds();

		}
		else {
			if (tipo == 3)
				bounds = sprite_villanoBilly.getGlobalBounds();
			else if (tipo == 4)
				bounds = sprite_villanoMark.getGlobalBounds();
			else
				bounds = sprite_villanoRandy.getGlobalBounds();
		}


		return bounds.contains(x, y);
	}

	void Derrotar() {
		_estaVivo = false;
	}


};
