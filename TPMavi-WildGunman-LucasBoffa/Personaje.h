#pragma once
#include "stdafx.h";

using namespace sf;

class Personaje {
	Texture tex_villanoMark;
	Texture tex_villanoBilly;
	Texture tex_villanoRandy;
	Texture tex_villanoMarkW;
	Texture tex_villanoBillyW;
	Texture tex_villanoRandyW;

	Texture tex_inocenteBob;
	Texture tex_inocenteSheffer;
	Texture tex_inocenteBobW;
	Texture tex_inocenteShefferW;

	Sprite sprite_villanoMark;
	Sprite sprite_villanoBilly;
	Sprite sprite_villanoRandy;
	Sprite sprite_villanoMarkW;
	Sprite sprite_villanoBillyW;
	Sprite sprite_villanoRandyW;

	Sprite sprite_inocenteBob;
	Sprite sprite_inocenteSheffer;
	Sprite sprite_inocenteBobW;
	Sprite sprite_inocenteShefferW;

	bool esInocente; 
	int tipo;  //tipo va del 1 al 5
	bool inWindow;


public:
	bool estaVivo;

	Personaje(bool _inocente, int _tipo, bool _inWindow) {
		estaVivo = true;
		inWindow = _inWindow;
		esInocente = _inocente;
		tipo = _tipo;
		

		tex_villanoMark.loadFromFile("../Assets/mark.png");
		tex_villanoBilly.loadFromFile("../Assets/billy.png");
		tex_villanoRandy.loadFromFile("../Assets/randy.png");
		tex_villanoMarkW.loadFromFile("../Assets/mark-window.png");
		tex_villanoBillyW.loadFromFile("../Assets/billy-window.png");
		tex_villanoRandyW.loadFromFile("../Assets/randy-window.png");

		tex_inocenteBob.loadFromFile("../Assets/bob.png");
		tex_inocenteSheffer.loadFromFile("../Assets/sheffer.png");
		tex_inocenteBobW.loadFromFile("../Assets/bob-window.png");
		tex_inocenteShefferW.loadFromFile("../Assets/sheffer-window.png");

		sprite_villanoMark.setTexture(tex_villanoMark);
		sprite_villanoBilly.setTexture(tex_villanoBilly);
		sprite_villanoRandy.setTexture(tex_villanoRandy);
		sprite_villanoMarkW.setTexture(tex_villanoMarkW);
		sprite_villanoBillyW.setTexture(tex_villanoBillyW);
		sprite_villanoRandyW.setTexture(tex_villanoRandyW);

		sprite_inocenteBob.setTexture(tex_inocenteBob);
		sprite_inocenteSheffer.setTexture(tex_inocenteSheffer);
		sprite_inocenteBobW.setTexture(tex_inocenteBobW);
		sprite_inocenteShefferW.setTexture(tex_inocenteShefferW);

		setOrigen(sprite_inocenteBob);
		setOrigen(sprite_inocenteBobW);
		setOrigen(sprite_inocenteSheffer);
		setOrigen(sprite_inocenteShefferW);
		setOrigen(sprite_villanoBilly);
		setOrigen(sprite_villanoBillyW);
		setOrigen(sprite_villanoMark);
		setOrigen(sprite_villanoMarkW);
		setOrigen(sprite_villanoRandy);
		setOrigen(sprite_villanoRandyW);


		sprite_inocenteBob.setScale(2, 2);
		sprite_inocenteBobW.setScale(2, 2);
		sprite_inocenteSheffer.setScale(2,2);
		sprite_inocenteShefferW.setScale(2,2);
		sprite_villanoMark.setScale(2, 2);
		sprite_villanoMarkW.setScale(2, 2);
		sprite_villanoBilly.setScale(2.5, 2.5);
		sprite_villanoBillyW.setScale(2.5, 2.5);
		sprite_villanoRandy.setScale(2, 2);
		sprite_villanoRandyW.setScale(2, 2);

		
	}

	void setOrigen(Sprite sprite) {
		sprite.setOrigin(sprite.getGlobalBounds().width / 2,
			sprite.getGlobalBounds().height);
	}

	void Dibujar(RenderWindow* wnd,Vector2f posicion) {
		if (esInocente) {
			if (!inWindow) {
				if (tipo == 1) {
					sprite_inocenteBob.setPosition(posicion);
					wnd->draw(sprite_inocenteBob);
				}else{
					sprite_inocenteSheffer.setPosition(posicion);
					wnd->draw(sprite_inocenteSheffer);
				}
			}
			else {
				if (tipo == 1) {
					sprite_inocenteBobW.setPosition(posicion);
					wnd->draw(sprite_inocenteBobW);
				}
				else {
					sprite_inocenteShefferW.setPosition(posicion);
					wnd->draw(sprite_inocenteShefferW);
				}
			}
			
		}
		else {
			if (!inWindow) {
				if (tipo == 3) {
					sprite_villanoBilly.setPosition(posicion);
					wnd->draw(sprite_villanoBilly);
				}
				else if (tipo == 4) {
					sprite_villanoMark.setPosition(posicion);
					wnd->draw(sprite_villanoMark);
				}else {
					sprite_villanoRandy.setPosition(posicion);
					wnd->draw(sprite_villanoRandy);
				}
			}
			else {
				if (tipo == 3) {
					sprite_villanoBillyW.setPosition(posicion);
					wnd->draw(sprite_villanoBillyW);
				}
				else if (tipo == 4) {
					sprite_villanoMarkW.setPosition(posicion);
					wnd->draw(sprite_villanoMarkW);
				}
				else {
					sprite_villanoRandyW.setPosition(posicion);
					wnd->draw(sprite_villanoRandyW);
				}
			}
		}
	}

	void changeWindow(bool window) {
		inWindow = window;
	}

	bool EstaEncima(float x, float y) {
		//devuelve un rectangulo
		FloatRect bounds;

		if (esInocente) {
			if (!inWindow) {
				if (tipo == 1) 
					bounds = sprite_inocenteBob.getGlobalBounds();
				else 
					bounds = sprite_inocenteSheffer.getGlobalBounds();
			}
			else {
				if (tipo == 1) 
					bounds = sprite_inocenteBobW.getGlobalBounds();
				else 
					bounds = sprite_inocenteShefferW.getGlobalBounds();
			}

		}
		else {
			if (!inWindow) {
				if (tipo == 3) 
					bounds = sprite_villanoBilly.getGlobalBounds();
				else if (tipo == 4) 
					bounds = sprite_villanoMark.getGlobalBounds();
				else 
					bounds = sprite_villanoRandy.getGlobalBounds();
			}
			else {
				if (tipo == 3) 
					bounds = sprite_villanoBillyW.getGlobalBounds();
				else if (tipo == 4) 
					bounds = sprite_villanoMarkW.getGlobalBounds();
				else 
					bounds = sprite_villanoRandyW.getGlobalBounds();
			}
		}


		return bounds.contains(x, y);
	}


};
