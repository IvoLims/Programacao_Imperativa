#include <stdlib.h>
#include <stdio.h>

/*1. Podemos calcular o produto de um número m por um inteiro n através de um somatório
de n parcelas constantes (e iguais a m).
Assim n × m = Somatório (i=1) m = m + m + · · · + m
                                      n vezes

Este cálculo pode ser efectuado somando n vezes a quantidade m a uma variável inicialmente com o valor 0.
Apresente uma definição da função float multInt (int n, float m) baseada nesta
observação: a uma variável r (inicialmente com o valor 0) será somado o valor de m,
n vezes. Essa variável r vai ter os valores 0, m, 2*m, 3*m, . . . , e no final terá o valor
desejado n*m. */

float multInt (int n, float m){
	float r=0;
	for(int i=0; i<n; i++) r+=m, printf("%.6f\n",r);
	return r;
}

int main()
{
	int n;
	float m;
    printf("Digite um valor para n e para m:\n");
    scanf("%d %f", &n, &m);
	multInt(n,m);
	return 0;
}

/* 2. Uma forma alternativa (e muito mais eficiente) consiste em aproveitar a representação binária dos inteiros
(onde a multiplicação e divisão por 2 são pelo menos tão eficientes como a adição). Dados dois números m e n podemos
construir uma tabela em que vamos dividindo (divisão inteira) n por 2 e multiplicando m por 2. A primeira linha da 
tabela tem o valor original de n enquanto que a última corresponde a n ser 1. Para obter o valor do produto de n por 
m basta somar os valores de m correspondentes às linhas em que n é impar. A tabela ao lado corresponde a um exemplo em 
que n=81 e m=423.

  n  m
1 81 423
2 40 846
3 20 1692
4 10 3384
5 5 6768
6 2 13536
7 1 27072

Se somarmos os valores de m para os quais n e impar (i.e., as linhas 1, 5 e 7) obtemos
423 + 6768 + 27072 = 34263 = 81 ∗ 423.

Apresente uma definição alternativa da função float multInt (int n, float m) usando este processo. */

float multInt2 (int n, float m){
  float r=0;
  while(n>0){
    if(n%2!= 0) r+=m, printf("%.6f\n",r);
    n/=2;
    m*=2;
  }
  printf("%.6f\n",r);
  return  r;
}

int main()
{
	int n;
	float m;
    printf("Digite um valor para n e para m:\n");
    scanf("%d %f", &n, &m);
	multInt2(n,m);
	return 0;
}

/* 3. O cálculo do máximo divisor comum entre dois números inteiros não negativos pode ser feito, de uma forma muito pouco
eficiente, procurando de entre os divisores do menor deles, o maior que é também divisor do outro. Defina uma função 
int mdc (int a, int b) que usa esse método para calcular o máximo divisor comum entre dois números). */

int maior(int a, int b){
    if(a>b) return a;
    else return b;
}

int mdc (int a, int b){
    int r=1, max;
    max=maior(a,b);
    for(int i=1;i<=max;i++){
        if(a%i==0 && b%i==0) r=i;
    }
    return r;
}

int main()
{
	  int a,b;
      printf("Digite um valor para a e para b:\n");
      scanf("%d %d", &a, &b);
	  mdc(a,b);
	  return 0;
}

/* 4. Uma forma alternativa de calcular o máximo divisor comum (mdc) baseia-se na seguinte propriedade demonstrada por 
Euclides: para a e b inteiros positivos, mdc (a, b) = mdc (a + b, b).
Desta propriedade podemos concluir que:

            | mdc (a − b, b) Se a > b
mdc (a, b) =| mdc (a, b − a) Se a < b
            | a Se a = b

O cálculo do máximo divisor comum pode ser feito por um processo repetitivo em que substituimos o maior dos argumentos pela 
diferença entre eles, até que um deles seja 0. Nessa altura, o valor do outro corresponde ao valor pretendido. Por exemplo,
para calcularmos o máximo divisor comum entre 126 e 45 passaríamos pelos estados que se apresentam à direita.

a            b
126          45
81 (=126-45) 45
36 (=81-45)  45
36 9         (=45-36)
27 (=36-9)   9
18 (=27-9)   9
9 (=18-9)    9
0 (=9-9)     9

Apresente uma definição alternativa da função int mdc (int a, int b) que usa esse método. */

int mdc2 (int a, int b){
    while(a!=0 || b!=0){
      if(a==b) return a;
      else if(a>b) a-=b;
      else b-=a;
    }
    if (a == 0) return b;
    else return a;
}

int main()
{
	  int a,b;
      printf("Digite um valor para a e para b:\n");
      scanf("%d %d", &a, &b);
	  mdc2(a,b);
	  return 0;
}

/* 5. Uma forma de melhorar o comportamento do algoritmo de Euclides consiste em substituir as operações de subtracção por operações de 
% (resto da divisão inteira). Repita o exercício da alínea anterior para essa variante do algoritmo. */

int mdc3 (int a, int b){
    while(a!=0 || b!=0){
      if(a==b) return a;
      else if(a>b) a%=b;
      else b%=a;
    }
    if (a == 0) return b;
    else return a;
}

int main()
{
	  int a,b;
      printf("Digite um valor para a e para b:\n");
      scanf("%d %d", &a, &b);
	  mdc3(a,b);
	  return 0;
}

/* 6. A sequência de Fibonacci define-se como

         |1 Se n < 2
fib (n) =|
         |fib (n − 1) + fib (n − 2) Se n ≥ 2

(a) Apresente uma definição recursiva de uma função que int fib (int n) calcula o n-ésimo número desta sequência. */

int fib (int n){
    if(n<=2) return 1;
    else return fib(n-1)+fib(n-2);
}

int main()
{
	  int n;
      printf("Digite um valor para n:\n");
      scanf("%d", &n);
	  fib(n);
	  return 0;
}

/* (b) O cálculo do n-ésimo número de Fibonacci pode ser definido de uma forma mais eficiente (e iterativa) se repararmos que ele apenas 
necessita de conhecer os valores dos 2 valores anteriores. Apresente uma definição alternativa (e iterativa) da função da alínea anterior 
que calcula o n-ésimo número de Fibonacci, usando duas variáveis auxiliares que guardam os dois valores anteriores. */

int fib2 (int n){
    int temp, acc1 = 1, acc2 = 1;
    for(int i = 3; i <= n; i++) {
        temp = acc2;
        acc2 += acc1;
        acc1 = temp;
    }
    return acc2;
}

int main()
{
	  int n;
    printf("Digite um valor para n:\n");
    scanf("%d", &n);
	  fib2(n);
	  return 0;
}