#pragma once
#include <iostream>
#include <Windows.h>
#include <vector>
#include "atkclick.h"

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
			std::cout << typeofclick.size() << std::endl;
			std::cout << "botao esquerdo do mouse pressionado" << std::endl;

		}
		else if (GetAsyncKeyState(0x02) & 0x8000) {
			GetCordenates();
			typeofclick.push_back(2);
			SaveXY();
			std::cout << typeofclick.size() << std::endl;
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
	bool control = false;
	bool pause = false;

	while (!control) {
		if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
			pause = !pause;
			Sleep(200);
		}
		if (!pause) {
			for (int i = 0; i < xpositions.size(); ++i) {
				for (int j = 0; j < ypositions.size(); ++j) {
					SetCursorPos(xpositions[i], ypositions[j]);
					for (int t = 0; t < typeofclick.size(); ++t) {
						if (typeofclick[t] = 1) {
							mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
							mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
						}
						else if (typeofclick[t] = 2) {
							mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);
							mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
						}
					}
				}
			}
		}
	}
}

