/*

* Program: [teste_1]

* Author: [Matheus Santos Silva Pereira]

* Date: [05.03.2024]

* Description: [Calculadora de area e comprimento de circulo e retangulo qualquer]

* License: [CC BY-ND]

*/

//Código em C++

// Inclusão de bibliotecas necessárias
#include <iostream>

using namespace std;

// Definindo a estrutura para o círculo
struct Circle {
    float raio;
    float comprimento;
    float area;
};

// Definindo a estrutura para o retângulo
struct Rectangle {
    float comprimento;
    float largura;
    float area;
    float perimetro;
};

// Definição da constante PI
#define PI 3.14

// Função para calcular os atributos do círculo
void Circulo(Circle *c) {
    cout << "Digite o raio do circulo: ";
    cin >> c->raio;
    
    c->comprimento = 2 * PI * c->raio;
    c->area = PI * c->raio * c->raio;
}

// Função para calcular os atributos do retângulo
void Retangulo(Rectangle *r) {
    cout << "Digite o comprimento do retangulo: ";
    cin >> r->comprimento;
    
    cout << "Digite a largura do retangulo: ";
    cin >> r->largura;
    
    r->area = r->comprimento * r->largura;
    r->perimetro = 2 * (r->comprimento + r->largura);
}

int main() {
    char continua = 's'; // Variável para controlar a continuação do programa
    
    while (continua == 's') {
        int escolha;
        
        cout << "\n";
        cout << "CALCULADORA DE AREA E COMPRIMENTO DO CIRCULO OU RETANGULO\n";
        cout << "Selecione a opcao:\n";
        cout << "1 - Calcular circulo\n";
        cout << "2 - Calcular retangulo\n";
        cin >> escolha;
        
        if (escolha == 1) {
            Circle c;
            Circulo(&c);
            cout << "Comprimento da circunferencia: " << c.comprimento << endl;
            cout << "Area do circulo: " << c.area << endl;
        } else if (escolha == 2) {
            Rectangle r;
            Retangulo(&r);
            cout << "Perimetro do retangulo: " << r.perimetro << endl;
            cout << "Area do retangulo: " << r.area << endl;
        } else {
            cout << "Opcao invalida\n";
        }
        
        cout << "Deseja continuar (s/n)? ";
        cin >> continua;
    }
    
    return 0;
}