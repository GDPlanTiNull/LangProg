'''

Program: [localizar_cursor]

Author: [Matheus Santos Silva Pereira]

Date: [13.03.2024]

Description: [Localizar o cursor, calcular area do circulo e retangulo]

License: [GNU General Public License]

'''

import msvcrt
from ctypes import windll, Structure, c_long, byref

# Definição das estruturas para representar o círculo e o retângulo
class Circle:
    def __init__(self):
        self.raio = 0
        self.comprimento = 0
        self.area = 0

class Rectangle:
    def __init__(self):
        self.comprimento = 0
        self.largura = 0
        self.area = 0
        self.perimetro = 0

# Definição da constante PI
PI = 3.14

# Função para calcular os valores do círculo
def calcular_circulo(c):
    c.raio = float(input("Digite o raio do círculo: "))
    c.comprimento = 2 * PI * c.raio
    c.area = PI * c.raio ** 2

# Função para calcular os valores do retângulo
def calcular_retangulo(r):
    r.comprimento = float(input("Digite o comprimento do retângulo: "))
    r.largura = float(input("Digite a largura do retângulo: "))
    r.area = r.comprimento * r.largura
    r.perimetro = 2 * (r.comprimento + r.largura)

# Função para localizar o cursor
def localizar_cursor(width, height):
    class POINT(Structure):
        _fields_ = [("x", c_long), ("y", c_long)]
    cursor_pos = POINT()
    windll.user32.GetCursorPos(byref(cursor_pos))
    x, y = cursor_pos.x, cursor_pos.y

    if x <= width and y <= height:
        return 'A'
    elif x >= width and y <= height:
        return 'B'
    elif x <= width and y >= height:
        return 'C'
    elif x >= width and y >= height:
        return 'D'
    else:
        return None

# Código principal
def main():
    continua = 's'
    width, height = 960, 540

    while continua == 's':
        print("\nSELECIONE UMA OPCAO:")
        print("1 - Localizar cursor")
        print("2 - Calcular círculo")
        print("3 - Calcular retângulo")
        print("Pressione ESC para sair")

        escolha = input("Escolha uma opção: ")

        if msvcrt.kbhit():
            tecla = ord(msvcrt.getch())
            if tecla == 27:  # ESC
                print("Programa finalizado.")
                break

        if escolha == '1':
            quadrant = localizar_cursor(width, height)
            if quadrant:
                print(f"O ponteiro do mouse está localizado no quadrante {quadrant}")
            else:
                print("O ponteiro do mouse está localizado fora dos quadrantes")

        elif escolha == '2':
            c = Circle()
            for _ in range(3):
                calcular_circulo(c)
                print(f"Comprimento da circunferência: {c.comprimento:.2f}")
                print(f"Área do círculo: {c.area:.2f}")

        elif escolha == '3':
            r = Rectangle()
            for _ in range(3):
                calcular_retangulo(r)
                print(f"Perímetro do retângulo: {r.perimetro:.2f}")
                print(f"Área do retângulo: {r.area:.2f}")

        else:
            print("Opção inválida")

        continua = input("Deseja continuar (s/n)? ").lower()

if __name__ == "__main__":
    main()

