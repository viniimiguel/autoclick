#ifndef CLKS_H_INCLUDE
#define CLKS_H_INCLUDE

#include <iostream>
#include <Windows.h>
#include <vector>

class Clks {
public:
    int x;
    int y;
    bool valida = false;
    std::vector <int> xpositions;
    std::vector <int> ypositions;
    std::vector <int> rorl;
    void getpositionM();
    void test();
    void regclick();
    void salvapositions();
    void macrostart();
    void transition(int targetx, int targety, int duration);
    void beep();
    void menu();

};

void Clks::menu() {
    std::cout << "======================== Menu ========================\n" << std::endl;
    std::cout << "1. Clique onde deseja que o macro realize cliques.\n" << std::endl;
    std::cout << "2. Ao ouvir o beep, você pode começar a gravar seus cliques.\n" << std::endl;
    std::cout << "3. Aperte (F7) para começar a gravar os cliques.\n" << std::endl;
    std::cout << "======================== Menu ========================\n" << std::endl;

    while (true) {
        if (GetAsyncKeyState(0x76) & 0x8000) {
            beep();
            regclick();
            break;
        }
        Sleep(200);
    }
    std::cout << "clique 'C' para parar ou iniciar o autoclique" << std::endl;
    macrostart();
}
void Clks::getpositionM() {
    POINT positionCursor;
    if (GetCursorPos(&positionCursor)) {
        std::cout << "x: " << positionCursor.x << " y: " << positionCursor.y << std::endl;
        x = positionCursor.x;
        y = positionCursor.y;
    }
}

void Clks::beep() {
    int frequencia = 1000;
    int duration = 500;
    Beep(frequencia, duration);
}

void Clks::regclick() {
    std::cout << "========================================================================\n" << std::endl;

    std::cout << "aperte (F8) para parar de gravar os cliques.\n" << std::endl;
    std::cout << "ao escutar o beep significa que o macro ja esta configurado\n" << std::endl
        ;
    std::cout << "========================================================================" << std::endl;

    while (!valida) {
        if (GetAsyncKeyState(0x01)) {
            getpositionM();
            salvapositions();
            rorl.push_back(1);
            Sleep(50);
        }
        if (GetAsyncKeyState(0x02)) {
            getpositionM();
            salvapositions();
            rorl.push_back(2);
            Sleep(50);
        }
        if (GetAsyncKeyState(0x77) & 0x8000) {
            std::cout << "gravacao parada." << std::endl;
            beep();
            break;
        }
        Sleep(50);
    }
}
void Clks::salvapositions() {
    xpositions.push_back(x);
    ypositions.push_back(y);
    std::cout << xpositions.size() << std::endl;
}
void Clks::transition(int targetx, int targety, int duration) {
    POINT currentPos;
    GetCursorPos(&currentPos);

    int startX = currentPos.x;
    int startY = currentPos.y;

    int steps = 1000;
    int delay = duration / steps;

    for (int i = 1; i <= steps; ++i) {
        int xp = startX + ((targetx - startX) * i) / steps;
        int yp = startY + ((targety - startY) * i) / steps;
        SetCursorPos(xp, yp);
        Sleep(delay);
    }
}
void Clks::macrostart() {
    int i = 0;
    while (true) {
        if (GetAsyncKeyState(0x43)) {
            while (true) {
                transition(xpositions[i], ypositions[i], 900);
                if (rorl[i] == 1) {
                    mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
                    Sleep(100);
                    mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
                }
                if (rorl[i] == 2) {
                    mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);
                    Sleep(100);
                    mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
                }
                i++;
                Sleep(200);
                if (i == ypositions.size()) {
                    i = 0;
                }
                if (GetAsyncKeyState(0x43)) {
                    break;
                }
            }

        }
        Sleep(200);
    }
}
void Clks::test() {
    std::cout << "hello world" << std::endl;
}

#endif