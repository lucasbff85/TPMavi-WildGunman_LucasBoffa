#pragma once
#include "stdafx.h"
#include "PlayerCrosshair.h"
#include "Saloon.h"

using namespace sf;

class Game {
	
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


		

		
		
		_saloon = new Saloon();
		while(!_saloon->getEnd())
		_saloon->Loop();
		
		

	}

	


	




	

};