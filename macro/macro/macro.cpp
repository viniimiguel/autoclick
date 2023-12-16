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
        std::cout << "\nDigite 1 para o macro de clicks: " << std::endl;
        std::cout << "\nDigite 2 para o macro de hotkeys: " << std::endl;
        std::cout << "\nDigite (1) ou (2)" << std::endl;
        std::cout << "*-*-*-*-**-*-*-*-**-*-*-*-**-*-*-*-**-*-*-*-**-*-*-*-*" << std::endl;
        std::cin >> choice;

        if (choice == 1) {
            Clks* cl1 = new Clks();
            cl1->menu();
        }
        else if (choice == 2) {
            Hotkey* h1 = new Hotkey();
            bool controle = false;
            int keys;
            std::vector<BYTE> tcl;

            std::cout << "digite a tecla que voce quer adicionar no macro em hexadecimal exemplo: (0x48)" << std::endl;
            std::cout << "\nDigite 0 para sair" << std::endl;

            while (!controle) {
                Sleep(50);
                std::cout << "\nqual tecla quer adicionar?: " << std::endl;
                std::cin >> std::hex >> keys;
                
                if (keys==0) {
                    controle = true;
                }
                else {
                    tcl.push_back(keys);
                }

            }
            std::cout << keys << std::endl;
            for (int i = 0; i < tcl.size(); i++) {
                std::cout << tcl[i] << std::endl;
            }
            Sleep(50);
            std::cout << "saimos do loop" << std::endl;
    
            h1->InputHK(tcl);
            break;
        }
        else {
            std::cout << "digite uma opção valida!" << std::endl;
        }

    } while (choice != 0);
    


    return 0;
}