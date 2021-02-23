#include <stdlib.h>
#include <stdio.h>

/* 1. Diga, justificando, qual o output de cada um dos seguintes excertos de código C.

(a) R.: O printf vai apresentar o seguinte resultado: 

1 1 4
2 2 6
3 3 8
4 4 10
5 5 12

*/

void printaCenas(){
	 int x [15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
	 int *y, *z, i;
	 y = x; z = x+3;
	 for (i=0; (i<5); i++) {
  		 printf ("%d %d %d\n", x[i], *y, *z);
  		 y = y+1; z = z+2;
     }
}

int main(){
  	printaCenas();
  	return 0;
}


/* (b) R.: a = endereço de i; b = endereço de j; -> i = 4 -> j = 4 + 5 -> b = 4 -> j = 9+4
Nota: Todas as alterações do valor continuaram a ser feitas no endereço logo 'a' toma valor 4 e
não 3. */

int main () {
	int i, j, *a, *b;
	i=3; j=5;
	a = &i; b = &j;
	i++;
	j = i + *b;
	b = a;
	j = j + *b;
	printf ("%d\n", j);
return 0;
}


/* 2. Defina uma função void swapM (int *x, int *y) que troca o valor de duas variáveis. Por exemplo, 
o código ao lado deverá imprimir no ecran 5 3. */

void swapM(int* x,int* y){
     int temp;
     temp = *x;
     *x = *y;
     *y = temp;
}

int main(){
    int x = 3, y = 5;
    swapM (&x, &y);
    printf ("%d %d\n", x, y);
return 0;
}

/* 3. Defina uma função void swap (int v[], int i, int j) que troca o valor das posições i e
j do vector v. */

void swap (int v[], int i, int j){
  int temp = v[i];
  v[i] = v[j];
  v[j] = temp;
  
}

int main(){
    int v [15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    int i = 3, j = 5;
    swap(v,j,i);
    for(int k = 0; k < 15; k++) {
        printf("%d ", v[k]);
    }
return 0;
}

//R.: 1 2 3 6 5 4 7 8 9 10 11 12 13 14 15

/* 4. Defina uma função int soma (int v[], int N) que calcula a soma dos elementos de um vector
v com N inteiros. */

int soma (int v[], int N){
  int i=0, sum=0;
  while(i<N){
  sum+=v[i];
  i++;
  }
  return sum;
}

int main(){
    int v [15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    int res = soma(v,15);
    printf("%d\n", res);
return 0;
}

/* 5. Defina uma função int maximum (int v[], int N, int *m) que coloca em *m o maior dos
elementos do vector v. A função deverá retornar 0 sse tal for possível (i.e., quando N>0). */

int maximum (int v[], int N, int *m){
    if(N<1) return 1;
    else {
      *m = v[0];
      for(int i=0; i<N; i++){
        if(v[i] > *m) *m = v[i];
      }
    }
    return 0;
}

int main(){
    int v [15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    int m;
    int res = maximum(v,15,&m);
    printf("%d\n", res);
return 0;
}

/* 6. Defina uma função void quadrados (int q[], int N) que preenche o vector q com os quadrados dos 
primeiros N números naturais. */

void quadrados (int q[], int N){
     int i = 0;
     while(i<N){
     q[i] = (i+1)*(i+1);
     i++;
     }
}

int main(){
    int q[5] = {};
    quadrados(q,5);
    for(int k = 0; k < 5; k++) {
        printf("%d ", q[k]);
    }
return 0;
}

/* 7. O triângulo de Pascal é uma forma de calcular os coeficientes da expansão do binómio de Newton.
Ao lado relembramos as 5 primeiras linhas. Note que a linha n do triângulo tem n elementos
e que a linha n + 1 pode ser obtida a partir da linha n usando o seguinte processo:

      1
     1 1
    1 2 1
   1 3 3 1
  1 4 6 4 1
1 5 10 10 5 1

• acrescenta-se um 1 no final, i.e., coloca-se 1 na posição n.
• para todos os elementos (desde n-1 até 1, por esta ordem) substitui-se o elemento nessa
posição pela sua soma com o que está na posição anterior.

Defina uma função void pascal (int v[], int N) que preenche o vector v com a N-ésima
linha do triângulo de Pascal. */

void pascal (int v[], int N) {
    if(N == 1) v[0] = 1;
    else {
        int prevLine[N - 1];
        pascal(prevLine,N-1);
        v[0] = 1;
        v[N - 1] = 1;
        for(int i = 1; i < N - 1; i++) {
            v[i] = prevLine[i - 1] + prevLine[i];
        }
    }
}

int main(){
    int q[5] = {};
    pascal(q,5);
return 0;
}

// Parecido mas não igual: https://www.geeksforgeeks.org/pascal-triangle/