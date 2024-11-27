#pragma once
#include "stdafx.h"
#include "Ventana.h"
#include "Personaje.h"
#include "Bang.h"

using namespace sf;

class Saloon {
	Texture tex_bar;
	Sprite sprite_bar;
	RenderWindow* _wnd;
	PlayerCrosshair* _player;
	Bang* _bang;
	bool _end = false;
	

public:
	Clock _clock;
	Time _time = seconds(2.0);

	Ventana ventanas[5] = { {false, true, false, 350, 230},
							{false, true,false, 1450, 230},
							{false, false, false, 288, 738},
							{false, false, false, 1512, 738},
							{false, false, true, 750, 555 } };


	//(bool _inocente, int _tipo)
	Personaje personajes[5] = { {true, 1},
								{true,2},
								{false,3},
								{false,4},
								{false,5} };

	Vector2f vectores[5] = {
		{300,116},{1400,118},{250,620},{1450,620},{825,665}
	};


	Saloon() {

		_wnd = new RenderWindow(VideoMode(1800, 1200, 32), "Wild Gunman");
		_bang = new Bang();

		tex_bar.loadFromFile("../Assets/casa.png");
		sprite_bar.setTexture(tex_bar);

	

		// Establecer el origen del sprite en su centro
		sprite_bar.setOrigin(sprite_bar.getGlobalBounds().width / 2,
			sprite_bar.getGlobalBounds().height / 2);	

		sprite_bar.setPosition(900, 600);
		sprite_bar.setScale(2.5f, 2.5f);

		_player = new PlayerCrosshair();
		_wnd->setMouseCursorVisible(false);
	
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
					Disparar();
			}
		}
	}


	void Loop() {
		while (_wnd->isOpen() && !getEnd()) {
			ProcesarEventos();
			Dibujar(_wnd);
		}
	}


	void Dibujar(RenderWindow* wnd) {
		wnd->clear();

		alternarVentanas();
		for (int i = 0; i < 5; i++) {
			if (ventanas[i].getOpen() == true) {
				if (personajes[0]._estaVivo)
					personajes[0].Dibujar(wnd, vectores[i]);
				/*else if (personajes[1]._estaVivo)
					personajes[1].Dibujar(wnd, vectores[i]);
				else if (personajes[2]._estaVivo)
					personajes[2].Dibujar(wnd, vectores[i]);
				else if (personajes[3]._estaVivo)
					personajes[3].Dibujar(wnd, vectores[i]);
				else if (personajes[4]._estaVivo)
					personajes[4].Dibujar(wnd, vectores[i]);*/
					/*else
						end();*/
			}
		}

		wnd->draw(sprite_bar);


		for (int i=0; i < 5; i++) {
			ventanas[i].Dibujar(wnd);
			if (ventanas[i].getOpen() == true) {
				int random = std::rand() % 5;

			}
		}
		_bang->dibujar(_wnd);
		_player->Dibujar(_wnd);
		
		_wnd->display();
	}


	void alternarVentanas() {
		//abrir cerrar
		if (_clock.getElapsedTime() > _time)
		{
			std::random_shuffle(personajes, personajes + 5);
			int random = std::rand() % 5;

			for (int i = 0; i < 5; i++)
			{
				if (i == random) {
					ventanas[i].setOpen(true);
					
				}
				else
					ventanas[i].setOpen(false);
			}

			_clock.restart();
		}
	}	


	void Disparar() {
		Vector2f playerPos = _player->ObtenerPosicion();
		for (int i = 0; i < 5; i++) {
			if (personajes[i].EstaEncima(playerPos.x, playerPos.y)) {
				personajes[i].Derrotar();
				_bang->disparar(playerPos);
			}
		}
		

	}
	void setEnd(bool valor) {
		_end = valor;
	}
	bool getEnd() {
		return _end;
	}

	void end() {
		setEnd(true);
	}
};