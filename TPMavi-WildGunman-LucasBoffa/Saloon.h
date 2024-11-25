#pragma once
#include "stdafx.h"
#include "Ventana.h"
#include "Personaje.h"

using namespace sf;

class Saloon {
	Texture tex_bar;
	Sprite sprite_bar;
	
	

public:
	Clock _clock;
	Time _time = seconds(2.0);

	Ventana ventanas[5] = { {false, true, false, 350, 230},
							{false, true,false, 1450, 230},
							{false, false, false, 288, 740},
							{false, false, false, 1512, 740},
							{false, false, true, 750, 555 } };


	//(bool _inocente, int _tipo, bool _inWindow)
	Personaje personajes[5] = { {true, 1, true},
								{true,2,true},
								{false,3,true},
								{false,4,true},
								{false,5,true} };


	Vector2f vectores[5] = {
		{300,116},{1400,118},{250,660},{1450,660},{825,665}
	};


	//Personaje* personajePrueba= new Personaje(true, 1, false);

	Saloon() {


		tex_bar.loadFromFile("../Assets/casa.png");
		sprite_bar.setTexture(tex_bar);

		// Establecer el origen del sprite en su centro
		sprite_bar.setOrigin(sprite_bar.getGlobalBounds().width / 2,
			sprite_bar.getGlobalBounds().height / 2);	

		sprite_bar.setPosition(900, 600);
		sprite_bar.setScale(2.5f, 2.5f);
	
	}



	void Dibujar(RenderWindow* wnd) {
		wnd->draw(sprite_bar);
		for (int i=0; i < 5; i++) {
			ventanas[i].Dibujar(wnd);
			if (ventanas[i].getOpen() == true) {
				int random = std::rand() % 5;
				


			}
		}

		//personajePrueba->Dibujar(wnd, vectores[4]);
		alternarVentanas();
		for (int i = 0; i < 5; i++) {
			if (ventanas[i].getDoor()) {
				personajes[0].changeWindow(false);
				Vector2f posicion = ventanas[i].posicionVentana();	
			}
			else {
				personajes[0].changeWindow(true);
			}
			if (ventanas[i].getOpen() == true) {
				personajes[0].Dibujar(wnd, vectores[i]);
			}
		}

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
};