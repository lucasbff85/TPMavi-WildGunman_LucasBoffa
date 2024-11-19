#pragma once
#include "stdafx.h"

using namespace sf;

class Ventana {
	Texture texture_wopen;
	Texture texture_wclose;
	Texture texture_door;
	Sprite sprite_wopen;
	Sprite sprite_wclose;
	Sprite sprite_door;
	bool isOpen = true;
	bool isDoor = false;
	bool isUp;
	float x;
	float y;
	


public:
	Ventana(bool _isOpen, bool _isUp, bool _isDoor , float _x, float _y) {
		isOpen = _isOpen;
		isUp = _isUp;
		isDoor = _isDoor;
		x = _x;
		y = _y;



		//cargar texturas
		texture_wopen.loadFromFile("../Assets/window-open.png");
		texture_wclose.loadFromFile("../Assets/window-close.png");
		texture_door.loadFromFile("../Assets/door.png");

		sprite_wopen.setTexture(texture_wopen);
		sprite_wclose.setTexture(texture_wclose);
		sprite_door.setTexture(texture_door);


		// Establecer el origen del sprite en su centro
		sprite_wopen.setOrigin(sprite_wopen.getGlobalBounds().width / 2,sprite_wopen.getGlobalBounds().height / 2);
		sprite_wclose.setOrigin(sprite_wclose.getGlobalBounds().width / 2, sprite_wclose.getGlobalBounds().height / 2);


		sprite_wclose.setPosition(x, y);
		sprite_wclose.setScale(1.8f, 1.8f);
		sprite_wopen.setPosition(x, y);
		sprite_wopen.setScale(2, 2);
		sprite_door.setPosition(x, y);

		
	}
	void Dibujar(RenderWindow* wnd) {
		if (isOpen && !isDoor) {
			if (isUp)
			{
				sprite_wopen.setScale(1.6, 1.3);
			}
			else {
				sprite_wopen.setScale(1.7, 1.7);
			}
			wnd->draw(sprite_wopen);
		}
		else if (!isOpen && !isDoor) {
			if (isUp)
			{
				sprite_wclose.setScale(3.3,2.5);
			}
			else {
				sprite_wclose.setScale(3.3, 3.3);
			}
			wnd->draw(sprite_wclose);
		}
		else if (!isOpen && isDoor) {
			sprite_door.setScale(1.65,1.3);
			wnd->draw(sprite_door);
		}

	}

	Vector2f posicionVentana() {
		return Vector2f(x, y);
	}


	bool getOpen() {
		return isOpen;
	}
	void setOpen(bool open) {
		isOpen = open;
	}
};
