#pragma once
#include <iostream>
#include <Windows.h>
#include <vector>
#include "atkclick.cpp"

void Maus::GetCordenates() {
	POINT cursorPoint;

	if (GetCursorPos(&cursorPoint)) {
		std::cout << "A posicao do cursor e de x: " << cursorPoint.x << " e de y: " << cursorPoint.y << std::endl;
		x = cursorPoint.x;
		y = cursorPoint.y;
	}

}
void Maus::SaveXY() {
	xpositions.push_back(x);
	ypositions.push_back(y);
	std::cout << xpositions.size() << std::endl;
}

void Maus::Song() {
	int frequency = 1000;
	int duration = 500;
	Beep(frequency, duration);
}

void Maus::Recording() {
	bool controler = false;
	while (!controler) {
		if (GetAsyncKeyState(0x01) & 0x8000) {
			GetCordenates();
			typeofclick.push_back(1);
			SaveXY();
			std::cout << "botao esquerdo do mouse pressionado" << std::endl;

		}
		else if (GetAsyncKeyState(0x02) & 0x8000) {
			GetCordenates();
			typeofclick.push_back(2);
			SaveXY();
			std::cout << "botao direito do mouse pressionado" << std::endl;
		}
		if (GetAsyncKeyState(0x48) & 0x8000) {
			Sleep(50);

			Song();
			std::cout << "a tecla (H) foi pressionada, parando o loop." << std::endl;
			controler = true;
		}
	}
	Sleep(100);
}

void Maus::Start() {

}

