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

void Maus::Song() {
	int frequency = 1000;
	int duration = 500;
	Beep(frequency, duration);
}

