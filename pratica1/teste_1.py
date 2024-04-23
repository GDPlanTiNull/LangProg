'''

Program: [teste_1]

Author: [Matheus Santos Silva Pereira - Adaptado para Python3 pelo ChatGPT]

Date: [05.03.2024]

Description: [CALCULADORA DE AREA E COMPRIMENTO DO CIRCULO OU RETANGULO]

License: [CC BY-ND]

'''

import math

# Definindo a classe para o círculo
class Circle:
    def __init__(self):
        self.raio = 0
        self.comprimento = 0
        self.area = 0

# Definindo a classe para o retângulo
class Rectangle:
    def __init__(self):
        self.comprimento = 0
        self.largura = 0
        self.area = 0
        self.perimetro = 0

# Função para calcular os atributos do círculo
def Circulo(c):
    c.raio = float(input("Digite o raio do circulo: "))
    c.comprimento = 2 * math.pi * c.raio
    c.area = math.pi * c.raio ** 2

# Função para calcular os atributos do retângulo
def Retangulo(r):
    r.comprimento = float(input("Digite o comprimento do retangulo: "))
    r.largura = float(input("Digite a largura do retangulo: "))
    r.area = r.comprimento * r.largura
    r.perimetro = 2 * (r.comprimento + r.largura)

if __name__ == "__main__":
    continua = 's'
    
    while continua == 's':
        escolha = int(input("\nCALCULADORA DE AREA E COMPRIMENTO DO CIRCULO OU RETANGULO\nSelecione a opcao:\n1 - Calcular circulo\n2 - Calcular retangulo\n"))
        
        if escolha == 1:
            c = Circle()
            Circulo(c)
            print("Comprimento da circunferencia:", format(c.comprimento, ".2f"))
            print("Area do circulo:", format(c.area, ".2f"))
        elif escolha == 2:
            r = Rectangle()
            Retangulo(r)
            print("Perimetro do retangulo:", format(r.perimetro, ".2f"))
            print("Area do retangulo:", format(r.area, ".2f"))
        else:
            print("Opcao invalida")
        
        continua = input("Deseja continuar (s/n)? ").lower()
