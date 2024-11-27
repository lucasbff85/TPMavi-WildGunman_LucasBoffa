#pragma once
#include "stdafx.h"
#include "PlayerCrosshair.h"

using namespace sf;


class Final {
	Texture _tex;
	Sprite _sprite;
	Font _font;
	Text _text;
	RenderWindow* _wnd;
	bool _win;
	bool _exit = false;
	int _puntos = 0;
	int _vidas = 0;


public:
	Final() {
		_win = false;
		_wnd = new RenderWindow(VideoMode(1800, 1200, 32), "Wild Gunman");

		_tex.loadFromFile("../Assets/final.png");
		_sprite.setTexture(_tex);


		_font.loadFromFile("../Fuentes/SpicyRice-Regular.ttf");
		_text.setFont(_font);
		_text.setPosition(50, 50);
		_text.setCharacterSize(50.0f);
		_text.setFillColor(Color::Red);
		_text.setPosition(200, 650);
	
		
	}


	void ProcesarEventos() {

		Event evt;
		while (_wnd->pollEvent(evt)) {
			if (evt.type == Event::Closed) {
				_wnd->close();
			}
			if (evt.type == Event::KeyPressed) {
				if (evt.key.code == Keyboard::Escape)
					_exit = true;
			}
		}
	}

	void Loop() {
		while (_wnd->isOpen()) {
			if (!_exit) {
				ProcesarEventos();
				actualizarTexto();
				Dibujar();
			}
			else {
				_wnd->close();
			}

		}
	}


	void actualizarTexto() {
		if (_win) {
			_text.setString("BUENA PARTIDA!!\n\nLograste aniquilar a 10 enemigos...\n\n"
				"Tus puntos: " + std::to_string(_puntos) + "\nTus vidas : " + std::to_string(_vidas));
		}
		else {
			_text.setString("PERDISTE!!! ... te quedaste sin vidas.\n\n-Mejor suerte la próxima vez\n\n"
				"Tus puntos: " + std::to_string(_puntos)+"\nTus vidas : " + std::to_string(_vidas));
		}
	}

	void Dibujar() {
		_wnd->clear();
		_wnd->draw(_sprite);
		_wnd->draw(_text);
		_wnd->display();
	}

	void setWin(bool valor) {
		_win = valor;
	}

	void setPuntos(int puntos) {
		_puntos = puntos;
	}

	void setVidas(int vidas) {
		_vidas = vidas;
	}
};
