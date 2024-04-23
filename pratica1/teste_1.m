% Definindo a classe para o círculo
classdef Circle
    properties
        raio
        comprimento
        area
    end
end

% Definindo a classe para o retângulo
classdef Rectangle
    properties
        comprimento
        largura
        area
        perimetro
    end
end

% Função para calcular os atributos do círculo
function Circulo(c)
    c.raio = input('Digite o raio do circulo: ');
    c.comprimento = 2 * pi * c.raio;
    c.area = pi * c.raio^2;
end

% Função para calcular os atributos do retângulo
function Retangulo(r)
    r.comprimento = input('Digite o comprimento do retangulo: ');
    r.largura = input('Digite a largura do retangulo: ');
    r.area = r.comprimento * r.largura;
    r.perimetro = 2 * (r.comprimento + r.largura);
end

continua = 's';

while continua == 's'
    escolha = input(['\nCALCULADORA DE AREA E COMPRIMENTO DO CIRCULO OU RETANGULO\n' ...
                    'Selecione a opcao:\n' ...
                    '1 - Calcular circulo\n' ...
                    '2 - Calcular retangulo\n']);
    
    if escolha == 1
        c = Circle();
        Circulo(c);
        fprintf('Comprimento da circunferencia: %.2f\n', c.comprimento);
        fprintf('Area do circulo: %.2f\n', c.area);
    elseif escolha == 2
        r = Rectangle();
        Retangulo(r);
        fprintf('Perimetro do retangulo: %.2f\n', r.perimetro);
        fprintf('Area do retangulo: %.2f\n', r.area);
    else
        disp('Opcao invalida');
    end
    
    continua = input('Deseja continuar (s/n)? ', 's');
end
