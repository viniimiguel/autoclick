#include <iostream>
#include <Windows.h>
#include "clks.h"

int main()
{
    Clks* cl1 = new Clks();

    std::cout << "clique onde voce quer que o macro realize cliques." << std::endl;
    std::cout << "a escutar o beep voce pode comecar a gravar seus cliques." << std::endl;
    std::cout << "aperte (F7) para comecar a gravar os cliques." << std::endl;
    while (true) {
        if (GetAsyncKeyState(0x76) & 0x8000) {
            std::cout << "aperte (F8) para parar de gravar os cliques." << std::endl;
            std::cout << "ao escutar o beep significa que o macro ja esta configurado" << std::endl;
            cl1->beep();
            cl1->regclick();
            break;

        }
        Sleep(200);
    }
    std::cout << "clique 'C' para parar ou iniciar o autoclique" << std::endl;
    cl1->macrostart();


    return 0;
}