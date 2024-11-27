#pragma once
#include "stdafx.h"
#include "PlayerCrosshair.h"

using namespace sf;


class Inicio {
	Texture _tex;
	Sprite _sprite;
	Font _font;
	Text _text;
	RenderWindow* _wnd;
	bool _play;

public:
	Inicio() {
		_play = false;
		_wnd = new RenderWindow(VideoMode(1800, 1200, 32), "Wild Gunman");

		_tex.loadFromFile("../Assets/menu.jpg");
		_sprite.setTexture(_tex);
		_sprite.setScale(1.8, 1.8);


		_font.loadFromFile("../Fuentes/SpicyRice-Regular.ttf");
		_text.setFont(_font);
		_text.setPosition(50, 50);
		_text.setCharacterSize(50.0f);
		_text.setFillColor(Color::Cyan);
		_text.setString("TP1 MODELOS Y ALGORITMOS PARA VIDEOJUEGOS I\n Instrucciones:\n-Se apunta y dispara con el puntero del ratón\n"
			"-Cada disparo acertado a un enemigo suma 1 punto\n"
			"-Cada disparo acertado a un inocente resta 1 vida y 1 punto\n"
			"-Si el enemigo dispara resta 1 vida\n"
			"-Se gana matando 10 enemigos\n"
			"-Se pierde si gastamos 3 vidas\n\n\n"
			"PRESIONA BARRA ESPACIADORA PARA COMENZAR A JUGAR!!");
	}


	void ProcesarEventos() {

		Event evt;
		while (_wnd->pollEvent(evt)) {
			if (evt.type == Event::Closed) {
				_wnd->close();
			}
			if (evt.type == Event::KeyPressed) {
				if (evt.key.code == Keyboard::Space)
					_play = true;
			}
		}
	}

	void Loop() {
		while (_wnd->isOpen()) {
			if (!_play) {
				ProcesarEventos();
				Dibujar();
			}
			else {
				_wnd->close();
			}
			
		}
	}

	void Dibujar() {
		_wnd->clear();
		_wnd->draw(_sprite);
		_wnd->draw(_text);
		_wnd->display();
	}

};
