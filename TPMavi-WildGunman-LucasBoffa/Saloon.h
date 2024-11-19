#pragma once
#include "stdafx.h"
#include "Ventana.h"

using namespace sf;

class Saloon {
	Texture tex_bar;
	Sprite sprite_bar;
	Ventana* window1;
	Ventana* window2;
	Ventana* window3;
	Ventana* window4;
	Ventana* window5;

public:

	Saloon() {
		tex_bar.loadFromFile("../Assets/casa.png");
		sprite_bar.setTexture(tex_bar);

		// Establecer el origen del sprite en su centro
		sprite_bar.setOrigin(sprite_bar.getGlobalBounds().width / 2,
			sprite_bar.getGlobalBounds().height / 2);

		sprite_bar.setPosition(900, 600);
		sprite_bar.setScale(2.5f, 2.5f);

		window1 = new Ventana(false, false, 4.0f);
		window2 = new Ventana(false, false, 5.8f);
		window3 = new Ventana(false, false, 4.5f);
		window4 = new Ventana(false, false, 5.3f);
		window5 = new Ventana(false, true, 4.6f);

		posicionarVentanas();
		
	
	}

	void posicionarVentanas() {

		//CONFIGURACIONES PARA POSICIONAR LAS VENTANAS CORRECTAMENTE:

		Vector2f vector_w1Close(168.f, 107.f);
		Vector2f vector_w2Close(1268.f, 107.f);
		Vector2f vector_w3Close(105.f, 575.f);
		Vector2f vector_w4Close(1327.f, 575.f);
		Vector2f vector_w5Close(750.f, 553.f);
		Vector2f vector6_close(3.3f, 3.2f);
		Vector2f vector7(1.65f, 1.31f);
		Vector2f vector_w1Open(108.f, 103.f);
		Vector2f vector_w2Open(1205.f, 103.f);
		Vector2f vector_w3Open(47.f, 572.f);
		Vector2f vector_w4Open(1265.f, 572.f);
		Vector2f vector_scaleOpen(1.7f, 1.55f);


		if (window1->getOpen()==true) {
			window1->posicionar(vector_w1Open);
		}
		else {
			window1->posicionar(vector_w1Close);
		}
		if (window2->getOpen()==true) {
			window2->posicionar(vector_w2Open);
		}
		else {
			window2->posicionar(vector_w2Close);
		}
		if (window3->getOpen()==true) {
			window3->posicionar(vector_w3Open);
			window3->escalar(vector_scaleOpen);
		}
		else {
			window3->posicionar(vector_w3Close);
			window3->escalar(vector6_close);
		}
		if (window4->getOpen()==true) {
			window4->posicionar(vector_w4Open);
			window4->escalar(vector_scaleOpen);
		}
		else {
			window4->posicionar(vector_w4Close);
			window4->escalar(vector6_close);
		}
		if (window5->getOpen()==true) {
		}
		else {

			window5->posicionar(vector_w5Close);
			window5->escalar(vector7);
		}
	}


	void actualizarVentanas() {
		window1->alternarEstado();
		window2->alternarEstado();
		window3->alternarEstado();
		window4->alternarEstado();
		//window5->alternarEstado();

	}

	void Dibujar(RenderWindow* wnd) {
		wnd->draw(sprite_bar);

		actualizarVentanas();
		posicionarVentanas();
		window1->Dibujar(wnd);
		window2->Dibujar(wnd);
		window3->Dibujar(wnd);
		window4->Dibujar(wnd);
		window5->Dibujar(wnd);
	}

	
};