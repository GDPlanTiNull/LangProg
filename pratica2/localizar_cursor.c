/*

* Program: [localizar_cursor]

* Author: [Matheus Santos Silva Pereira]

* Date: [13.03.2024]

* Description: [Localizar o cursor, calcular area do circulo e retangulo]

* License: [GNU General Public License]

*/

#include <stdio.h>
#include <windows.h>
#include <conio.h> // Para usar kbhit()

// Definição de estruturas para representar o círculo e o retângulo
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

// Definição da constante PI
#define PI 3.14

// Função para calcular os valores do círculo
void Circulo(Circle *c) {
    // Solicitação do raio do círculo ao usuário
    printf("Digite o raio do circulo: ");
    scanf("%f", &(c->raio));
    
    // Cálculo do comprimento da circunferência e área do círculo
    c->comprimento = 2 * PI * c->raio;
    c->area = PI * c->raio * c->raio;
}

// Função para calcular os valores do retângulo
void Retangulo(Rectangle *r) {
    // Solicitação do comprimento e largura do retângulo ao usuário
    printf("Digite o comprimento do retangulo: ");
    scanf("%f", &(r->comprimento));
    
    printf("Digite a largura do retangulo: ");
    scanf("%f", &(r->largura));
    
    // Cálculo da área e do perímetro do retângulo
    r->area = r->comprimento * r->largura;
    r->perimetro = 2 * (r->comprimento + r->largura);
}

// Função para localizar o cursor
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
    }
    return '\0';
}

// Código principal
int main() {
    int escolha;
    char continua = 's'; // Variável para continuar ou não o programa
    int Width = 960, Height = 540;
    
    // Loop principal para permitir que o usuário faça múltiplos cálculos
    while (continua == 's') {
        printf("\n");
        printf("SELECIONE UMA OPCAO:\n");
        printf("1 - Localizar cursor\n");
        printf("2 - Calcular circulo\n");
        printf("3 - Calcular retangulo\n");
        printf("Pressione ESC para sair\n");
        
        // Verifica se a tecla ESC foi pressionada
        if (_kbhit()) {
            char tecla = _getch();
            if (tecla == 27) {
                printf("Programa finalizado.\n");
                break;
            }
        }
        
        scanf("%d", &escolha);
        
        switch(escolha) {
            case 1: {
                char quadrant = localizarCursor(Width, Height);
                switch(quadrant) {
                    case 'A':
                        printf("O ponteiro do mouse esta localizado no quadrante A\n");
                        break;
                    case 'B':
                        printf("O ponteiro do mouse esta localizado no quadrante B\n");
                        break;
                    case 'C':
                        printf("O ponteiro do mouse esta localizado no quadrante C\n");
                        break;
                    case 'D':
                        printf("O ponteiro do mouse esta localizado no quadrante D\n");
                        break;
                    default:
                        printf("O ponteiro do mouse esta localizado fora dos quadrantes\n");
                        break;
                }
                break;
            }
            case 2: {
                Circle c;
                for (int i = 0; i < 3; ++i) {
                    Circulo(&c);
                    printf("Comprimento da circunferencia: %.2f\n", c.comprimento);
                    printf("Area do circulo: %.2f\n", c.area);
                }
                break;
            }
            case 3: {
                Rectangle r;
                for (int i = 0; i < 3; ++i) {
                    Retangulo(&r);
                    printf("Perimetro do retangulo: %.2f\n", r.perimetro);
                    printf("Area do retangulo: %.2f\n", r.area);
                }
                break;
            }
            default:
                printf("Opcao invalida\n");
                break;
        }
    }
    
    return 0;
}