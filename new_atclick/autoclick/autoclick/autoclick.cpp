#include <iostream>
#include <Windows.h>
#include "atkclick.h"

int main() {
	std::cout << "voce ja pode gravar seus click ou seus clicks com o botao direito ou esquerdo do mouse." << std::endl;
	std::cout << "*-*-**-*-**-*-**-*-**-*-**-*-**-*-**-*-*" << std::endl
		<< "Bem vindo ao macro Clks" << std::endl
		<< "*-*-**-*-**-*-**-*-**-*-**-*-**-*-**-*-*" << std::endl
		<< "Segure a tecla (H) para parar de gravar seus clicks" << std::endl;

	bool controler = false;
	while (!controler) {
	
		if (GetAsyncKeyState(0x48)& 0x8000) {
			Sleep(50);
			Maus* m1 = new Maus();
			m1->Song();
			std::cout << "a tecla (H) foi pressionada, parando o loop." << std::endl;
			controler = true;
			delete m1;
		}
	}
	return 0;
}