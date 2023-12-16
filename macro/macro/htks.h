#ifndef HTKS_H_INCLUDED
#define HTKS_H_INCLUDED

#include <iostream>
#include <vector>
#include <Windows.h>

class Hotkey {
public:
	int atv;
	bool ctr = false;
	void InputHK(std::vector<BYTE> htks);
};


void Hotkey::InputHK(std::vector<BYTE> htks) {
	std::cout << "\ndigite a tecla que voce usara para ativacao do seu macro: \n" << std::endl;
	std::cin >> atv;
	std::cout << "\npronto macro configurado" << std::endl;
	while (!ctr) {
		if (GetAsyncKeyState(atv)) {
			for (int i = 0; i < htks.size(); i++) {
				keybd_event(htks[i], 0, KEYEVENTF_EXTENDEDKEY, 0);
				Sleep(50);
				keybd_event(htks[i], 0, KEYEVENTF_KEYUP, 0);
			}
		}
		Sleep(50);
	}
	
}

#endif