/*

* Program: [teste_1]

* Author: [Matheus Santos Silva Pereira]

* Date: [05.03.2024]

* Description: [Calculadora de area e comprimento de circulo e retangulo qualquer]

* License: [CC BY-ND]

*/

//Código em C

// Inclusão de bibliotecas necessárias
#include <stdio.h>

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

// Código principal
int main() {
    int escolha;
    char continua = 's'; // Variável para continuar ou não o programa
    
    // Loop principal para permitir que o usuário faça múltiplos cálculos
    while (continua == 's')  // enquanto for igual a 's'
{
    printf("\n");
    printf("CALCULADORA DE AREA E COMPRIMENTO DO CIRCULO OU RETANGULO\n");
    printf("Selecione a opcao:\n");
    printf("1 - Calcular circulo\n");
    printf("2 - Calcular retangulo\n");
    scanf("%d", &escolha);
    
     // Condições de escolha para círculo ou retângulo
    if (escolha == 1) {
        Circle c;
        Circulo(&c);
        printf("Comprimento da circunferencia: %.2f\n", c.comprimento);
        printf("Area do circulo: %.2f\n", c.area);
    } else if (escolha == 2) {
        Rectangle r;
        Retangulo(&r);
        printf("Perimetro do retangulo: %.2f\n", r.perimetro);
        printf("Area do retangulo: %.2f\n", r.area);
    } else {
        printf("Opcao invalida\n");
    }

      // Pergunta ao usuário se deseja continuar
        printf("\nDeseja continuar (s/n)? ");
        scanf(" %c", &continua);
    
}
    return 0;
}
