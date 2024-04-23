%{

Program: [localizar_cursor]

Author: [Matheus Santos Silva Pereira]

Date: [13.03.2024]

Description: [Localizar o cursor, calcular area do circulo e retangulo]

License: [GNU General Public License]

%}

% Definição da função para calcular os valores do círculo
function [comprimento, area] = Circulo(raio)
    % Cálculo do comprimento da circunferência e área do círculo
    comprimento = 2 * pi * raio;
    area = pi * raio * raio;
end

% Definição da função para calcular os valores do retângulo
function [area, perimetro] = Retangulo(comprimento, largura)
    % Cálculo da área e do perímetro do retângulo
    area = comprimento * largura;
    perimetro = 2 * (comprimento + largura);
end

% Função para localizar o cursor
function quadrant = localizarCursor(Width, Height)
    cursorPos = get(0, 'PointerLocation');
    x = cursorPos(1);
    y = cursorPos(2);
    
    if x <= Width && y <= Height
        quadrant = 'A';
    elseif x >= Width && y <= Height
        quadrant = 'B';
    elseif x <= Width && y >= Height
        quadrant = 'C';
    elseif x >= Width && y >= Height
        quadrant = 'D';
    else
        quadrant = '';
    end
end

% Código principal
clc; clear; close all;

continua = 's'; % Variável para continuar ou não o programa
Width = 960; Height = 540;

while continua == 's'
    fprintf('\n');
    fprintf('SELECIONE UMA OPCAO:\n');
    fprintf('1 - Localizar cursor\n');
    fprintf('2 - Calcular circulo\n');
    fprintf('3 - Calcular retangulo\n');
    fprintf('Pressione ESC para sair\n');
    
    if kbhit()
        tecla = getkey();
        if tecla == 27
            fprintf('Programa finalizado.\n');
            break;
        end
    end
    
    escolha = input('');
    
    switch escolha
        case 1
            quadrant = localizarCursor(Width, Height);
            switch quadrant
                case 'A'
                    fprintf('O ponteiro do mouse esta localizado no quadrante A\n');
                case 'B'
                    fprintf('O ponteiro do mouse esta localizado no quadrante B\n');
                case 'C'
                    fprintf('O ponteiro do mouse esta localizado no quadrante C\n');
                case 'D'
                    fprintf('O ponteiro do mouse esta localizado no quadrante D\n');
                otherwise
                    fprintf('O ponteiro do mouse esta localizado fora dos quadrantes\n');
            end
        case 2
            raio = input('Digite o raio do circulo: ');
            [comprimento, area] = Circulo(raio);
            fprintf('Comprimento da circunferencia: %.2f\n', comprimento);
            fprintf('Area do circulo: %.2f\n', area);
        case 3
            comprimento = input('Digite o comprimento do retangulo: ');
            largura = input('Digite a largura do retangulo: ');
            [area, perimetro] = Retangulo(comprimento, largura);
            fprintf('Perimetro do retangulo: %.2f\n', perimetro);
            fprintf('Area do retangulo: %.2f\n', area);
        otherwise
            fprintf('Opcao invalida\n');
    end
end
