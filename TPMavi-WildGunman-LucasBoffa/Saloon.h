#pragma once
#include "stdafx.h"
#include "Ventana.h"
#include "Personaje.h"
#include "Bang.h"

using namespace sf;

class Saloon{
	Texture tex_bar;
	Sprite sprite_bar;
	RenderWindow* _wnd;
	PlayerCrosshair* _player;
	Bang* _bang;
	Clock _clock;
	Time _time = seconds(2.0);
	Time _timeDisparar = seconds(1.8);
	int _puntos;
	int _vidas;
	Font _font;
	Text _text;
	int anterior = 6;
	

public:
	

	Ventana ventanas[5] = { {false, true, false, 350, 230},
							{false, true,false, 1450, 230},
							{false, false, false, 288, 738},
							{false, false, false, 1512, 738},
							{false, false, true, 750, 555 } };


	//(bool _inocente, int _tipo)
	Personaje personajes[13] = { {true, 1},
								{true,2},
								{false,3},
								{false,4},
								{false,5},
								{true, 1},
								{true,2},
								{false,3},
								{false,4},
								{false,5},
								{false,3},
								{false,4},
								{false,5} };

	Vector2f vectores[5] = {
		{330,466},{1430,468},{280,950},{1480,950},{880,985}
	};


	Saloon() {
		_puntos = 0;
		_vidas = 3;

		_wnd = new RenderWindow(VideoMode(1800, 1200, 32), "Wild Gunman");
		_bang = new Bang();

		tex_bar.loadFromFile("../Assets/casa.png");
		sprite_bar.setTexture(tex_bar);



		_font.loadFromFile("../Fuentes/SpicyRice-Regular.ttf");
		_text.setFont(_font);
		_text.setPosition(50, 50);
		_text.setCharacterSize(50.0f);
		_text.setFillColor(Color::Yellow);
		_text.setPosition(1100, 40);

		actualizarTexto();

	

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
		sleep(seconds(0.8));
		while (_wnd->isOpen()) {
			if (_puntos < 10 && _vidas > 0) {
				ProcesarEventos();
				Dibujar(_wnd);
			}
			else {
				_wnd->close();
			}
			
		}
	}


	void Dibujar(RenderWindow* wnd) {
		wnd->clear();

		alternarVentanas();
		for (int i = 0; i < 5; i++) {
			if (ventanas[i].getOpen() == true) {
				personajes[0].Dibujar(wnd, vectores[i]);
				enemigoDisparar();
			}
		}

		wnd->draw(sprite_bar);
		wnd->draw(_text);


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

		for (int i = 1; i < 13; i++) {
			personajes[i]._derrotado = false;
		}

		//abrir cerrar
		if (_clock.getElapsedTime() > _time)
		{
			std::random_shuffle(personajes, personajes + 13);
			int random = std::rand() % 5;
			if (random == anterior)
				random++;

			for (int i = 0; i < 5; i++)
			{
				if (i == random) {
					ventanas[i].setOpen(true);
					
				}
				else
					ventanas[i].setOpen(false);
			}

			_clock.restart();
			anterior = random;
		}
	}	


	void Disparar() {
		Vector2f playerPos = _player->ObtenerPosicion();

		if (personajes[0].EstaEncima(playerPos.x, playerPos.y)) {
					personajes[0].Derrotar();
					if (personajes[0].getInocente()) {
						_vidas--;
						if (_puntos > 1) {
							_puntos -= 2;  // resta 2 puntos solamente cuando tiene más de 1 punto
						}
						else {
							_puntos = 0;   // para evitar tener puntos negativos
						}

					}
					else {
						_puntos++;
					}
					_bang->disparar(playerPos);
		}
		actualizarTexto();

	}

	void enemigoDisparar() {
		if (!personajes[0].getInocente() && _clock.getElapsedTime() > _timeDisparar&& !personajes[0]._derrotado) {
			Vector2f posicion(personajes[0].posicion().x,personajes[0].posicion().y-135);
			_bang->disparar(posicion);
			_vidas--;
			actualizarTexto();
			_clock.restart();
		}
	}

	int getVidas() {
		return _vidas;
	}

	int getPuntos() {
		return _puntos;
	}

	void actualizarTexto() {
		_text.setString("VIDAS: " + std::to_string(_vidas)+"   PUNTOS: "+std::to_string(_puntos));
	}

	~Saloon() {
		delete _player;
		delete _bang;
		delete _wnd;
	}

};