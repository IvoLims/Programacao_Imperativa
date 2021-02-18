#include <stdlib.h>
#include <stdio.h>

//1. Diga, justificando, qual o output de cada um dos seguintes excertos de código C.

int main() {
  int x , y ;
  x = 3; y = x + 1;
  x = x * y ; y = x + y ;
  printf (" %d %d\n " ,x ,y );
return 0;
  }

/* R.: Inicialmente x=3 e y=4, depois da primeira execução x=12=3*4 e y=7=12+4
e finalemnte é printado para o utilizador "12 16" */

int main () {
  int x , y ;
   x = 0;
   printf (" %d %d\n " ,x ,y );
return 0;
}

/* R.: Inicialmente x=0 pois foi-lhe atribuido esse valor, já o y não tem nada 
atribuido a ele. Logo vai ser printado "0 q" sendo q qualquer coisa que esteja
no sistema e que vai ser atribuido a y,ou seja 'lixo'.

Assuma que os códigos ASCII dos caracteres 'A', '0', ' ' e 'a' são respectivamente 65, 48, 32 e 97) */

int main() {
  char a , b , c ;
  a = 'A'; b = ' '; c = '0';
  printf ( " %c %d\n " ,a ,a );
  a = a + 1; c = c + 2;
  printf ( " %c %d %c %d\n " ,a ,a ,c ,c );
  c = a + b ;
  printf (" %c %d\n " ,c ,c );
return 0;
} 

/* R.: A 65
       B 66 2 50
       b 98

Nota: %d is used to print decimal(integer) number ,while %c is used to print character. */

int main() {
 int x, y;
 x = 200; y = 100;
 x = x + y ; y = x - y ; x = x - y ;
 printf ( " %d %d\n " ,x ,y );
return 0;
}

//R.: 100 200

//2. Output de códigos mais complexos.

int main() {
 int x , y ;
 x = 3; y = 5;
 if ( x > y )
     y = 6;
 printf ( " %d %d\n " , x, y);
return 0;
}

/* R.: O programa vai pegar em x e y ver se a a condição se verifica, visto que não se 
verifica o resultado será " 3 5 ", pois o y não vai mudar para 6.
Nota: if sem else apenas vai funcionar se a proposição for verdadeira. */

int main() {
  int x , y ;
  x = y = 0;
  while ( x != 11) {
          x = x + 1; y += x;
  }
  printf ( " %d %d\n " ,x ,y );
  return 0;
}

/* R.: Ele vai ver se o x é diferente de 11 como é um caso afirmativo este vai realizar a conta x+1 
até que o resultado seja 11 e depois vai fazer continuamente a conta y+x que fica y=66 no final. 
Logo o resultado é " 11 66 ".
Nota:  != é o mesmo que diferente. */

int main() {
  int x , y ;
  x = y = 0;
  while ( x != 11) {
          x = x + 2; y += x ;
}
  printf ( " %d %d\n " ,x ,y );
  return 0;
}

/* R.: O programa vai fazer repetivamente a conta x+2 enquanto o resultado x diferente de 11 se comprovar, 
assim como a conta y = y+x. Logo o resultado final seria 'overflow' pois nunca termina. */

int main() {
  int i ;
  for ( i =0; (i <20) ; i++)
      if ( i %2 == 0) putchar ('_');
      else putchar ('#');
  return 0;
}

/* R.: O programa começa com i= 0 e se i é menor que 20 vai continuar a fazer i+1. Assim enquanto é 
feita essa conta também vai resultar o padrão ’#_#_#_#_#_#_#_#_#_#_’
Nota: i % 2 divisão inteira de i por 2. */

int main() {
 char i, j;
 for ( i = 'a'; ( i != 'h'); i++) {
     for ( j = i ; ( j != 'h'); j++)
          putchar ( j );
          putchar ( '\n');
      }
  return 0;
}

/* R.: 
abcdefg
bcdefg
cdefg
defg
efg
fg
g
*/

void f ( int n ) {
 while (n > 0) {
     if ( n %2 == 0) putchar ( '0');
     else putchar ( '1');
     n = n /2;
    }
 putchar ( '\n') ;
 }

int main () {
 int i;
 for ( i =0;( i <16) ; i ++)
     f ( i );
 return 0;
}

/* R.:
1
01
11
001
101
011
111
0001
1001
0101
1101
0011
1011
0111
1111

Nota: void f significa uma declaração mas não um prototype. 
Prototype: is necessary in order to provide information to the compiler about function, about return type,
parameter list and function name etc. In C, declaration of function is called as prototype declaration.
*/

/*2. Escreva um programa que desenhe no ecrã (usando o caracter #) um quadrado de dimensão 5. Defina para
isso uma funçãoo que desenha um quadrado de dimensão n. Use a função putchar. O resultado da invocação 
dessa função com um argumento 5 deverá ser o que se apresenta à direita. */

void formaQ(int n){
  for(int i=0; i<n ;i++){
  for(int j=0; j<n; j++) 
  putchar('#');
  putchar('\n');
  }
}

int main(){
  int n;
  printf("Digite o tamanho do quadrado:\n");
  scanf("%d", &n);
  formaQ(n);
return 0;
}

/* 3. Escreva um programa que desenhe no ecrã (usando os caracteres # e _) um tabuleiro de xadrez. Defina para 
isso uma função que desenha um tabuleiro de xadrez de dimensão n. Use a função putchar. O resultado da invocação 
dessa função com um argumento 5 deverá ser o que se apresenta à direita. */

void formaTab(int n){
  for(int i=0; i<n;i++){
    for(int j=0;j<n;j++)
    if ((j+i) %2 == 0)  putchar('#');
    else putchar('_');
  putchar('\n');
  }
}

int main(){
  int n;
  printf("Digite o tamanho do tabuleiro:\n");
  scanf("%d", &n);
  formaTab(n);
return 0;
}

/*4. Escreva duas funções que desenham triangulos (usando o caracter #). O resultado da invocação dessas funções
com um argumento 5 deverá ser o que se apresenta à direita.*/

void formaTri1(int n){
  for(int i=0; i<n*2;i++){
    for(int j=0;j<n*2-i;j++)
    if(j<i) putchar('#');
  putchar('\n');
  }
}

int main(){
  int n;
  printf("Digite o tamanho do triangulo:\n");
  scanf("%d", &n);
  formaTri1(n);
return 0;
}

/* 1º Triângulo:

#
##
###
####
#####
####
###
##
# 

*/

void formaTri2(int n){
  for(int i=1; i<=n;i+=1){
    for(int j=n-1;j>=i;j-=1) printf(" "); 
    for(int k=1;k<=i*2-1;k++) printf("#");
    putchar('\n');
  }
}

int main(){
  int n;
  printf("Digite o tamanho do triangulo:\n");
  scanf("%d", &n);
  formaTri2(n);
return 0;
}

/* 2º Triângulo:

    #
   ###
  #####
 #######
#########

*/

int main(int argc, char const *argv[])
{
    formaTri1(5);
    formaTri2(5);
    return 0;
}
