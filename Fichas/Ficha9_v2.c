#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Considere o seguinte tipo para representar árvores binárias de inteiros.

typedef struct nodo {
int valor;
struct nodo *esq, *dir;
} * ABin;

ABin newABin (int r, ABin e, ABin d) {
ABin a = malloc (sizeof(struct nodo));
if (a!=NULL) {
a->valor = r; a->esq = e; a->dir = d;
}
return a;
}

/* 1. Apresente definições das seguintes funções sobre árvores.
(a) int altura (ABin a) que calcula a altura de uma árvore. */

int altura (ABin a){
    if(a == NULL) return 0;
    
    int e = altura(a->esq);
    int d = altura(a->dir);
    
    return ((e > d) ? e:d) +1;
}

/* (b) int nFolhas (ABin a) que calcula o número de folhas (i.e., nodos cujas sub-árvores são
ambas vazias). */

int nFolhas (ABin a){
    if(a == NULL) return 0;
    if(a->esq == NULL && a->dir == NULL) return 1;
    return nFolhas(a->esq) + nFolhas(a->dir);
}

// (c) ABin maisEsquerda (ABin a) que calcula o nodo mais à esquerda de uma árvore.

ABin maisEsquerda (ABin a){
    if(a == NULL) return NULL;
    while(a->esq != NULL){
        a = a->esq;
    }
    return a;
}

/* (d) void imprimeNivel (ABin a, int l) que escreve no ecran os elementos da árvore que
estão ao nível l (Considere que a raiz de uma árvore se encontra no nível 0). */

void imprimeNivel (ABin a, int l){
    if(l == 0) printf("%d ",a->valor);
    else if (l > 0){
             if(a->esq != NULL) imprimeNivel(a->esq,l-1);
             if(a->dir != NULL) imprimeNivel(a->dir,l-1);
    }
}

/* (e) int procuraE (ABin a, int x) que testa se x ocorre na árvore. Não assuma qualquer
propriedade sobre a árvore a. */

int procuraE (ABin a, int x){
    if (a == NULL) return -1;
    if (a->valor == x) return 0;
    int res = -1;
    res = procuraE(a->esq, x);
    if (res == 0) return 0;
    return procuraE(a->dir, x);
}

/* 2. Apresente definições sobre as seguintes funções sobre árvores binárias de procura.

(f) struct nodo *procura (ABin a, int x) que procura um elemento numa árvore. A
função deverá retornar o endere¸co da célula onde o elemento ocorre ou NULL caso o elemento não exista na árvore. */

struct nodo *procura (ABin a, int x){
        while(a!= NULL && a->valor != x){
          a = (a->valor > x) ? a->esq : a->dir;
    }
    return a;
}

/* (g) int nivel (ABin a, int x) que calcula o nível a que o elemento ocorre na árvore (-1
caso não exista). */

int nivel (ABin a, int x){
    int count = 0;
    while(a!= NULL && a->valor != x){
          a = (a->valor > x) ? a->esq : a->dir;
          count++;
    }
    return (a == NULL) ? -1 : count;
}

/* (h) void imprimeAte (ABin a, int x) que imprime no ecran, por ordem crescente, todos os
elementos da árvore que são (estritamente) menores do que um dado valor. */

void imprimeAte (ABin a, int x){
    if(a != NULL){
        if(a->esq != NULL) {
            imprimeAte(a->esq,x);
        }
        if(a->dir != NULL) {
            imprimeAte(a->dir,x);
        }
        if(a->valor < x){
            printf("%d ",a->valor);
        }
    }
}

//For Tests

ABin newABin (int r, ABin e, ABin d) {
   ABin a = malloc (sizeof(struct nodo));
   if (a!=NULL) {
      a->valor = r; a->esq = e; a->dir = d;
   }
   return a;
}

ABin RandArvFromArray (int v[], int N) {
   ABin a = NULL;
    int m;
    if (N > 0){
    	m = rand() % N;
    	a = newABin (v[m], RandArvFromArray (v,m), RandArvFromArray (v+m+1,N-m-1));
    }
    return a;	
}

void dumpABin (ABin a, int N){
   if(a!=NULL){
       dumpABin(a->esq, N);
       printf("%d ",a->valor);
       dumpABin(a->dir,N);
   }
}

void freeABin (ABin a){
    if(a){
        freeABin(a->esq);
        freeABin(a->dir);
        free(a);
    }
}


int main (){
  int v1[15] = { 1, 3, 5, 7, 9,11,13,15,17,19,21,23,25,27,29},
      v2[15] = {21, 3,15,27, 9,11,23, 5,17,29, 1,13,25, 7,19},
      N=15;
  ABin a1, a2,r;
  
  srand(time(NULL));
  
  printf ("_______________ Testes _______________\n\n");
  a1 = RandArvFromArray (v2, N);
  printf ("Primeira árvore de teste (%d elementos)\n", N);
  dumpABin (a1, N);
  
  printf ("altura = %d\n", altura (a1));
  printf ("numero de folhas: %d\n", nFolhas (a1));
  printf ("Nodo mais à esquerda: ");
  r = maisEsquerda (a1);
  if (r==NULL) printf ("(NULL)\n"); else printf ("%d\n", r->valor);
  printf ("Elementos no nivel 3_______\n");
  imprimeNivel (a1, 3);
  printf ("\n___________________________\n");

  printf ("procura de 2: %d\n", procuraE (a1, 2));
  printf ("procura de 9: %d\n", procuraE (a1, 9));
  
  freeABin (a1);
  
  a2 = RandArvFromArray (v1, N);
  printf ("\nSegunda árvore de teste (%d elementos)\n", N);
  dumpABin (a2, N);
  
  printf ("procura de 9: ");
  r = procura (a2, 9);
  if (r==NULL) printf ("(NULL)\n"); else printf ("%d\n", r->valor);   
  printf ("procura de 2: ");
  r = procura (a2, 2);
  if (r==NULL) printf ("(NULL)\n"); else printf ("%d\n", r->valor);   
  printf ("nível do elemento 2: %d\n", nivel (a2, 2));
  printf ("nível do elemento 9: %d\n", nivel (a2, 9));
  imprimeAte (a2, 20);

  freeABin (a1);

  printf ("\n\n___________ Fim dos testes ___________\n\n");
  return 0;
} 
