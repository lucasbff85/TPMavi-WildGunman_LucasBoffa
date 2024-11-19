#pragma once
#include "stdafx.h"

using namespace sf;

class Ventana {
	Texture texture_wopen;
	Texture texture_wclose;
	Texture texture_door;
	Sprite sprite_window;
	bool isOpen = true;
	bool isDoor = false;
	Clock clock;
	float intervalo;
	


public:
	Ventana(bool open, bool door, float tiempo) {
		isOpen = open;
		isDoor = door;
		intervalo = tiempo;

		//cargar texturas
		texture_wopen.loadFromFile("../Assets/window-open.png");
		texture_wclose.loadFromFile("../Assets/window-close.png");
		texture_door.loadFromFile("../Assets/door.png");

		posicionInicial();
		
	}

	void posicionInicial() {
		//asignar textura inicial
		if (isOpen && !isDoor) {
			sprite_window.setTexture(texture_wopen);
			sprite_window.setScale(1.7f, 1.2f);
		}
		else if (!isOpen && !isDoor) {
			sprite_window.setTexture(texture_wclose);
			sprite_window.setScale(3.3f, 2.5f);
		}
		else if (!isOpen && isDoor) {
			sprite_window.setTexture(texture_door);
		}

		//establecerOrigen();
	}


	void establecerOrigen() {
		// Establecer el origen del sprite en su centro
		sprite_window.setOrigin(sprite_window.getGlobalBounds().width / 2,
			sprite_window.getGlobalBounds().height / 2);
	}

	bool getOpen() {
		return isOpen;
	}
	void setOpen(bool open) {
		isOpen = open;
	}

	void posicionar(Vector2f posicion) {
		sprite_window.setPosition(posicion);
	}

	void Dibujar(RenderWindow* wnd) {
		wnd->draw(sprite_window);
	}

	void escalar(Vector2f vector) {
		sprite_window.setScale(vector);
	}

	void alternarEstado() {
		if (clock.getElapsedTime().asSeconds() > intervalo) {
			 
			setOpen(!isOpen);
			posicionInicial();
			//Reinicia el reloj
			clock.restart();
		}
		
	}

};
