# Matematica_Computacional

## aproximaE

Entrada: Um número ponto flutuante com precisão dupla epsilon.

Saída: O menor valor e(n) tal que  o erro relativo entre duas aproximações seja menor que epsilon.

## dieta_professor_mil_grau

Entrada: A entrada possui dois inteiros N ( 25 <= N <= 65 )e  M ( 50 <= M <= 70) separados por um espaço.

Saída: Imprima um número ponto flutuante com 5 casas decimais depois da vírgula representando a cota aproximada de calorias para um homem de N anos que pesa M kg.

## gauss_com_pivoteamento_parcial

Entrada: A primeira linha possui um inteiro N, representando a dimensão a matriz. Cada uma das N linhas seguintes contém N+1 números reais, sendo o último número real representando o termo independente.

Saída: A saída contém N linhas. Cada linha contém N+1 números reais, escritos com a precisão de cinco casas decimais. Seguindo de mais N linhas. A i-ésima linha seguinte tem o formato "x[i] = v",onde v é um número real, escrito como a precisão de cinco casas decimais, representando o valor da variável i no sistema de equação.

## gauss_seidel

Entrada: A primeira linha possui um inteiro N, representando a dimensão a matriz. Cada uma das N linhas seguintes contém N+1 números reais, sendo o último número real representando o termo independente do sistema linear. Seguido de 1 linha contendo N números reais representando uma aproximação inicial para o solução do sistema. Na linha seguinte, um número real   \epsilon   representando a precisão tolerada. Na última linha, um inteiro MAX_ITER representando o número máximo de iterações do método.

Saída: A saída contém N+1 linhas por iteração do método. Na primeira linha, temos o identificador da iteração no seguinte formato "ITERACAO n", onde n é o número da iteração. As N linhas seguintes, temos os valores do vetor de solução no seguinte formato "x[i] = v", onde i é o identificador da variável variando entre 0 e n-1 e v o valor da variável i na iteração corrente.

## professor_mil_grau

Entrada: A entrada do problema é composta por duas linhas. A primeira linha possui um inteiro N representando o comprimento da sequência dada. A segunda linha contém N números inteiros X1,X2,..,XN separados por um espaço. Esses números forma a sequência dada. 

Saída: Imprima um inteiro D representando o menor grau possível de um polinômio P(n) tal que P(i) = Xi, para todo i = 1, .., n.
