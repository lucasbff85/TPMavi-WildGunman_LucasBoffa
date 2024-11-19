#pragma once
#include "stdafx.h"
#include "PlayerCrosshair.h"
#include "Saloon.h"

using namespace sf;

class Game {
	RenderWindow* _wnd;  //variable dinamica porque instanciamos enm el constructor, es el objeto central en SFML
	PlayerCrosshair* _player;
	Saloon* _saloon;
	


public:
	Game() {
		

		
		_wnd = new RenderWindow(VideoMode(1800, 1200, 32), "Wild Gunman");
		_saloon = new Saloon();
		_player = new PlayerCrosshair();
		_wnd->setMouseCursorVisible(false);
	}

	void Loop() {
		while (_wnd->isOpen()) {
			ProcesarEventos();
			Dibujar();
		}
	}


	void ProcesarEventos() {
		Event evt;
		while (_wnd->pollEvent(evt)) {
			if (evt.type == Event::Closed) {
				_wnd->close();
			}
			if (evt.type == Event::MouseMoved) {
				_player->Posicionar(evt.mouseMove.x, evt.mouseMove.y);
			}
			if (evt.type == Event::MouseButtonPressed) {
				if (evt.mouseButton.button == Mouse::Button::Left)
					Disparar();
			}
		}
	}

	void Disparar() {

	}

	void Dibujar() {

		_wnd->clear();
		
		_saloon->Dibujar(_wnd);
		_player->Dibujar(_wnd);
		_wnd->display();
	}
};