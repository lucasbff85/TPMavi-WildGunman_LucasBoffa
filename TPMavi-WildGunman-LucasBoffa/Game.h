#pragma once
#include "stdafx.h"
#include "Inicio.h"
#include "Saloon.h"
#include "Final.h"

using namespace sf;

class Game {
	Inicio* _inicio;
	Saloon* _saloon;
	Final* _final;
	Font _font;
	Text _text;
	int _puntos = 0;
	int _vidas = 0;
	


public:
	Game() {
		_final = new Final();
		_saloon = new Saloon();
		_inicio = new Inicio();
	}
	
	void play() {
		_inicio->Loop();
		_saloon->Loop();
		_puntos = _saloon->getPuntos();
		_vidas = _saloon->getVidas();
		_final->setPuntos(_puntos);
		_final->setVidas(_vidas);
		if (_puntos == 10)
			_final->setWin(true);
		_final->Loop();
	}
	
};