#pragma once
#include "stdafx.h";


using namespace sf;

class Bang {
	
	Texture tex_bang;
	Sprite sprite_bang;
	Clock clock;
	Time time = seconds(1);
	bool _isVisible = false;

	SoundBuffer _buffer;  // Buffer de sonido
	Sound _sound;         // Objeto de sonido

public:
	Bang() {


		tex_bang.loadFromFile("../Assets/bang.png");
		sprite_bang.setTexture(tex_bang);

		// Establecer el origen del sprite en su centro
		sprite_bang.setOrigin(sprite_bang.getGlobalBounds().width / 2,
			sprite_bang.getGlobalBounds().height / 2);
	
		sprite_bang.setScale(5, 5);

		_buffer.loadFromFile("../Sounds/pistol.mp3");
		_sound.setBuffer(_buffer);

	}

	void disparar(Vector2f posicion) {
		sprite_bang.setPosition(posicion);
		// Reiniciar el reloj y activar el sprite
		clock.restart();
		_isVisible = true;
		_sound.play();
	}

	void dibujar(RenderWindow* wnd) {
		if (_isVisible) {
			if (clock.getElapsedTime() < time) {
				wnd->draw(sprite_bang);
			}
		}
			
		else
			_isVisible=false; 	
	}

	

};