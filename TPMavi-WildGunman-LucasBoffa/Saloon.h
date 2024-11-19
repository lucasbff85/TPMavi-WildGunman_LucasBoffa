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

	Personaje personajes[5] = { {true},{false},{true},{false},{false} };


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
				Vector2f posicion = ventanas[i].posicionVentana();
				personajes[i].Dibujar(wnd, posicion);
			}
				
		}
		alternarVentanas();
		
	}


	void alternarVentanas() {
		//abrir cerrar
		if (_clock.getElapsedTime() > _time)
		{
			int random = std::rand() % 5;

			for (int i = 0; i < 5; i++)
			{
				if (i == random) {
					ventanas[i].setOpen(true);
					
				}
					
				//mostrar personaje en ventana abierta
				//poner un randon entre 2 para que sea bueno o malo
				else
					ventanas[i].setOpen(false);
			}
			_clock.restart();
		}
	}
	
	

	
};