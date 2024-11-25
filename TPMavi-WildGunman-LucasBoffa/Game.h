#pragma once
#include "stdafx.h"
#include "PlayerCrosshair.h"
#include "Saloon.h"

using namespace sf;

class Game {
	RenderWindow* _wnd;
	PlayerCrosshair* _player;
	Saloon* _saloon;
	Font font;
	Text text;
	int puntos = 0;
	


public:
	Game() {
		//font.loadFromFile("../Fuentes/SpicyRice-Regular.ttf");
		//text.setFont(font);
		//text.setCharacterSize(50); // Tamaño de la letra
		//text.setFillColor(sf::Color::White); // Color de la letra
		//text.setStyle(sf::Text::Bold); // Estilo de la letra
		//text.setPosition(200, 250); // Posición en la ventana


		

		
		_wnd = new RenderWindow(VideoMode(1800, 1200, 32), "Wild Gunman");
		_saloon = new Saloon();
		_player = new PlayerCrosshair();
		_wnd->setMouseCursorVisible(false);


		sf::Vector2f posicion = _player->ObtenerPosicion();
		std::string posicionTexto = "Posicion: (" +
			std::to_string(posicion.x) + ", " +
			std::to_string(posicion.y) + ")";
		text.setString(posicionTexto);
	}

	void Loop() {
		while (_wnd->isOpen()) {
			ProcesarEventos();
			Dibujar();
		}
	}


	void ProcesarEventos() {
		std::srand(static_cast<unsigned>(std::time(nullptr)));

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
					disparar();
			}
		}
	}

	void disparar() {
		/*vector2f playerpos = _player->obtenerposicion();
		if (personaje.estaencima(playerpos.x, playerpos.y)) {

		}*/
	}

	void Dibujar() {

		_wnd->clear();
		
		_saloon->Dibujar(_wnd);
		_player->Dibujar(_wnd);
		_wnd->display();
	}


	

};