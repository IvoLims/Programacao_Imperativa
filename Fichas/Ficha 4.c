#include <stdlib.h>
#include <stdio.h>
#include <string.h> 
#include <ctype.h>
#include <limits.h>

/* 1. Defina uma função int minusculas (char s[]) que substitui na string s todas as
letras maiúsculas pela correspondente letra minúscula. A função deverá retornar 
quantas substituições foram efectuadas. */

int minusculas1 (char s[]){
    int res = 0, len= strlen(s);
    for(int i = 0; i< len ;i++){
        if(*s >= 65 && *s <= 90) {*s+=32;res+=1;}
        *s++;
    }
	  return res;
}

//Ou

int minusculas2 (char s[]){
    int res = 0, len= strlen(s);
    for(int i = 0; i< len ;i++){
        if(s[i] >= 'A' && s[i] <= 'Z') {
          s[i]=tolower(s[i]);
          res+=1;
        }
    }
	  return res;
}

int main()
{
	  char s[20];
    printf("Digite uma String:\n");
    scanf("%[^\n]", s); 
	  int res = minusculas1(s);
    printf("A String mudada é %s e foram mudadas %d.\n", s,res);

	  return 0;
}

/* 2. Defina uma função int contalinhas (char s[]) que calcula quantas linhas tem uma
string (assuma que o caracter que separa duas linhas é '\n').  */

int contalinhas (char s[]){
    int res=0;
    for(int i = 0; s[i];i++){
        if(s[i] == '\n') res++;
    }
    return res;
}

int main()
{
	  char s[20];
    printf("Digite as suas Strings:\n");
    scanf("%[^\t]", s); //tab delimits
    printf("Ao todo existem %d linhas.\n",contalinhas(s));
	  return 0;
}

/* 3. Defina uma função int contaPal (char s[]) que calcula quantas palavras tem uma
string. Assuma que uma palavra é um conjunto de caracteres não brancos terminada
por um caracter branco. Use para isso a função standard (ctype.h) int isspace(int
c). */

int contaPal (char s[]){
    int res=0;
    for(int i = 0;s[i];i++){
        if(s[i] != ' ' && s[i] != '\n' && s[i] != '\t') res++;
    }
    return res;
}

int main()
{
	  char s[20];
    printf("Digite as suas Strings:\n");
    scanf("%[^\t]", s); //tab delimits
    printf("Ao todo existem %d palavras.\n",contaPal(s));
	  return 0;
}

/* 4. Defina uma função int procura (char *p, char *ps[], int N) que procura uma
string p num array de strings ps). */

int procura (char *p, char *ps[], int N){
    int res=-1;
    for(int i = 0; i<N; i++){
        if( strcmp(p, ps[i]) == 0) res = i+1; break;
    }
    return res;
}

// 5. Considere o seguinte tipo para representar stacks de números inteiros.

#define MAX 100

typedef struct stack {
int sp;
int valores [MAX];
} STACK;

/* Defina as seguintes funções sobre este tipo:

(a) void initStack (STACK *s) que inicializa uma stack (passa a representar uma
stack vazia). */

void initStack (STACK *s){
     s -> sp = 0;
}

// (b) int isEmptyS (STACK *s) que testa se uma stack é vazia

int isEmptyS (STACK *s){
    if(s->sp != 0) return 1;
    return 0;
}

/* (c) int push (STACK *s, int x) que acrescenta x ao topo de s; a função deve retornar 0 se a operação 
fˆor feita com sucesso (i.e., se a stack ainda não estiver cheia)e 1 se a operação não fˆor possível 
(i.e., se a stack estiver cheia). */

int push (STACK *s, int x){
    if(s->sp == MAX) return 1;
    s->valores[++s->sp]=x;
    return 0;
}

/* (d) int pop (STACK *s, int *x) que remove de uma stack o elemento que está no
topo. A função deverá colocar no endereço x o elemento removido. A função
deverá retornar 0 se a operação for possível (i.e. a stack não está vazia) e 1 em
caso de erro (stack vazia). */

int pop (STACK *s, int *x){
    if(isEmptyS(s) == 0) return 1;
    *x = s->valores[--(s->sp)];
    return 0;
}

/* (e) int top (STACK *s, int *x) que coloca no endereço x o elemento que está no
topo da stack (sem modificar a stack). A função deverá retornar 0 se a operação
for possível (i.e. a stack não está vazia) e 1 em caso de erro (stack vazia). */

int top (STACK *s, int *x){
    if(isEmptyS(s) == 0) return 1;
    *x = s->valores[(s->sp)-1];
    return 0;
}

// Test

int pop2 (STACK *s){
    if(isEmptyS(s) == 0) return 1;
    return s->valores[--(s->sp)];;
}

int top2 (STACK *s){
    if(isEmptyS(s) == 0) return 1;
    return s->valores[(s->sp)-1]; // otherwise will be 0 always
}

int main(){
  STACK* s = malloc(sizeof(struct stack));
  push(s,10);
  push(s,20);
  push(s,30);
  while(isEmptyS(s) != 0){
        printf("%d the element in the top\n",top2(s));
        printf("%d popped from stack\n", pop2(s));
  }
  return 0;
}