#include <iostream>
#include <Windows.h>
#include "atkclick.h"

int main() {
	Maus* m1 = new Maus();
	std::cout << "voce ja pode gravar seus click ou seus clicks com o botao direito ou esquerdo do mouse." << std::endl;
	std::cout << "*-*-**-*-**-*-**-*-**-*-**-*-**-*-**-*-*" << std::endl
		<< "Bem vindo ao macro Clks" << std::endl
		<< "*-*-**-*-**-*-**-*-**-*-**-*-**-*-**-*-*" << std::endl
		<< "Segure a tecla (H) para parar de gravar seus clicks" << std::endl;

	m1->Recording();
	m1->Start();
	return 0;
}