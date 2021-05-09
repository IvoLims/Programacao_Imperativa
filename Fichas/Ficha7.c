#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Considere que se pretende armazenar quantas vezes uma determinada palavra aparece num texto.
Para isso definiu-se o seguinte tipo (listas ligadas em que cada elemento armazena uma palavra e o
número de vezes que essa palavra ocorre). */

typedef struct celula {
char *palavra;
int ocorr;
struct celula * prox;
} *Palavras;

/* Assume-se que a lista não tem palavras repetidas.
Apresente definições para as seguintes funções:

1. void libertaLista (Palavras) que liberta todo o espaço (da heap) ocupado pela lista de palavras. */

void libertaLista (Palavras l){
  if(l != NULL){
     libertaLista(l-> prox);
     free(l);
  }
}

//2. Lista quantasP (Palavras l) que calcula quantas palavras (diferentes) existem armazenadas.

int quantasP (Palavras l){
    if(l!=NULL){
       return 1+quantasP(l->prox);
    }else return 0;
}

/* 3. void listaPal (Palavras l) que escreve no ecran, uma por linha, todas as palavras armazenadas, bem 
como o número de ocorrências. */

void listaPal (Palavras l){
     if(l != NULL){
       for(;l!=NULL;l=l->prox)
        printf("A palavra: %s, foi guardada %d vez/vezes.\n",l->palavra,l->ocorr);
     } else {
       printf("A lista esta vazia.\n");
     }
}

//4. char * ultima (Palavras l) que determina qual a última palavra da lista.

char* ultima (Palavras l){
    char* r = "None";
    Palavras j = l;
    if(l==NULL) return r;
    for(;l!=NULL;l=l->prox){
        if(l==NULL){
          break;
        }
    j->prox;
    }
    return j->palavra;
}

/* 5. Palavras acrescentaInicio (Palavras l, char *p) que acrescenta uma palavra no início
da lista (com 1 como número de ocorrências). */

Palavras acrescentaInicio (Palavras l, char *p){
  Palavras ini;
  ini = malloc(sizeof(struct celula));
  ini -> palavra = strdup(p);
  ini -> ocorr = 1;
  ini->prox = l;
  return ini;
}

/* 6. Palavras acrescentaFim (Palavras l, char *p) que acrescenta uma palavra no fim da lista
(com 1 como número de ocorrências). */

Palavras acrescentaFim (Palavras l, char *p){
    while(l!=NULL &&( strcmp ((l)->palavra,p) != 0))
          l= l->prox;
          if(l == NULL){
             l = malloc(sizeof(struct celula));
             strcpy(l-> palavra, p);
             l->ocorr =1;
             l->prox = NULL;
             } else l ->ocorr++;
    return l;
}

/* 7. Palavras acrescenta (Palavras l, char *p) que regista mais uma ocorrência da palavra p.
Se a palavra já existir, o número de ocorrências deve ser incrementado. No outro caso deve ser
inserida uma nova célula. A inserção de uma nova célula pode ser feita no início da lista ou 
ordenadamente, assumindo que a lista está armazenada por ordem alfabética. */

Palavras acrescenta (Palavras l, char *p){
  Palavras ant,pts;
  if(!l || strcmp(l->palavra,p)<0) l = acrescentaInicio(l, p);
  else if(strcmp(l->palavra,p)==0) l-> ocorr++;
  else l->prox=acrescenta(l->prox,p);
  return l;
}

/* 8. struct celula * maisFreq (Palavras l) que calcula a célula correspondente à palavra mais
frequente. */

struct celula * maisFreq (Palavras l){
    if(l == NULL){
       return NULL;
    }
    char* r = l -> palavra;
    int count = l -> ocorr;
    for(; l!=NULL; l=l->prox){
        if(l->ocorr > count){
           r = l->palavra; count = l->ocorr;
        }
    }
    Palavras percorre = acrescentaInicio(percorre, r);
    return percorre;
}

int main () {
    Palavras dic = NULL;

    char * canto1 [44] = {"as", "armas", "e", "os", "baroes", "assinalados",
                          "que", "da", "ocidental", "praia", "lusitana", 
                          "por", "mares", "nunca", "de", "antes", "navegados",
                          "passaram", "ainda", "alem", "da", "taprobana",
                          "em", "perigos", "e", "guerras", "esforcados",
                          "mais", "do", "que", "prometia", "a", "forca", "humana",
                          "e", "entre", "gente", "remota", "edificaram", 
                          "novo", "reino", "que", "tanto", "sublimaram"};

    int i; struct celula *p;
    for (i=0;i<44;i++)
        dic = acrescentaInicio (dic, canto1[i]);

    printf ("Foram inseridas %d palavras\n", quantasP (dic));
    printf ("palavras existentes:\n");
    listaPal (dic);
    printf ("última palavra inserida: %s\n", ultima (dic));

    libertaLista (dic);

    dic = NULL;

    srand(42);
    
    for (i=0; i<1000; i++)
        dic = acrescenta (dic, canto1 [rand() % 44]);
    
    printf ("Foram inseridas %d palavras\n", quantasP (dic));
    printf ("palavras existentes:\n");
    listaPal (dic);
    printf ("última palavra inserida: %s\n", ultima (dic));
    
    p = maisFreq (dic);
    printf ("Palavra mais frequente: %s (%d)\n", p->palavra, p->ocorr);

    return 0;
}
