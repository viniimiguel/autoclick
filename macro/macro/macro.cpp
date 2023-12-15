#include <iostream>
#include <Windows.h>
#include "clks.h"
#include "htks.h"


int main()
{
    int choice;

    do {
        std::cout << "*-*-*-*-**-*-*-*-**-*-*-*-**-*-*-*-**-*-*-*-**-*-*-*-*" << std::endl;
        std::cout << "Bem vindo ao MacroCLKS\n" << std::endl;
        std::cout << "\nDigite 1 para o macro de clicks" << std::endl;
        std::cout << "\nDigite 2 para o macro de hotkeys" << std::endl;
        std::cout << "*-*-*-*-**-*-*-*-**-*-*-*-**-*-*-*-**-*-*-*-**-*-*-*-*" << std::endl;
        std::cin >> choice;

        if (choice == 1) {
            Clks* cl1 = new Clks();
            cl1->menu();
        }
        else if (choice == 2) {
            Hotkey* h1 = new Hotkey();
            break;
        }
        else {
            std::cout << "digite uma opção valida!" << std::endl;
        }

    } while (choice != 0);
    


    return 0;
}