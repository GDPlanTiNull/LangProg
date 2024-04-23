/*

* Program: [localizar_cursor]

* Author: [Matheus Santos Silva Pereira]

* Date: [13.03.2024]

* Description: [Localizar o cursor, calcular area do circulo e retangulo]

* License: [GNU General Public License]

*/

#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

typedef struct {
    float raio;
    float comprimento;
    float area;
} Circle;

typedef struct {
    float comprimento;
    float largura;
    float area;
    float perimetro;
} Rectangle;

#define PI 3.14

void Circulo(Circle *c) {
    cout << "Digite o raio do circulo: ";
    cin >> c->raio;
    
    c->comprimento = 2 * PI * c->raio;
    c->area = PI * c->raio * c->raio;
}

void Retangulo(Rectangle *r) {
    cout << "Digite o comprimento do retangulo: ";
    cin >> r->comprimento;
    
    cout << "Digite a largura do retangulo: ";
    cin >> r->largura;
    
    r->area = r->comprimento * r->largura;
    r->perimetro = 2 * (r->comprimento + r->largura);
}

char localizarCursor(int Width, int Height) {
    POINT cursorPos;
    GetCursorPos(&cursorPos);
    int x = cursorPos.x; 
    int y = cursorPos.y;
    
    if (x <= Width && y <= Height){
        return 'A'; 
    } else if (x >= Width && y <= Height){
        return 'B';
    } else if (x <= Width && y >= Height){
        return 'C';
    } else if (x >= Width && y >= Height){
        return 'D';
    } else {
        return '\0';
    }
}

int main() {
    int escolha;
    char continua = 's';
    int Width = 960, Height = 540;
    
    while (continua == 's') {
        cout << "\n";
        cout << "SELECIONE UMA OPCAO:\n";
        cout << "1 - Localizar cursor\n";
        cout << "2 - Calcular circulo\n";
        cout << "3 - Calcular retangulo\n";
        cout << "Pressione ESC para sair\n";
        
        if (_kbhit()) {
            char tecla = _getch();
            if (tecla == 27) {
                cout << "Programa finalizado.\n";
                break;
            }
        }
        
        cin >> escolha;
        
        switch(escolha) {
            case 1: {
                char quadrant = localizarCursor(Width, Height);
                if(quadrant == 'A') {
                    cout << "O ponteiro do mouse esta localizado no quadrante A\n";
                } else if(quadrant == 'B') {
                    cout << "O ponteiro do mouse esta localizado no quadrante B\n";
                } else if(quadrant == 'C') {
                    cout << "O ponteiro do mouse esta localizado no quadrante C\n";
                } else if(quadrant == 'D') {
                    cout << "O ponteiro do mouse esta localizado no quadrante D\n";
                } else {
                    cout << "O ponteiro do mouse esta localizado fora dos quadrantes\n";
                }
                break;
            }
            case 2: {
                Circle c;
                for (int i = 0; i < 3; ++i) {
                    Circulo(&c);
                    cout << "Comprimento da circunferencia: " << c.comprimento << endl;
                    cout << "Area do circulo: " << c.area << endl;
                }
                break;
            }
            case 3: {
                Rectangle r;
                for (int i = 0; i < 3; ++i) {
                    Retangulo(&r);
                    cout << "Perimetro do retangulo: " << r.perimetro << endl;
                    cout << "Area do retangulo: " << r.area << endl;
                }
                break;
            }
            default:
                cout << "Opcao invalida\n";
                break;
        }
    }
    
    return 0;
}
