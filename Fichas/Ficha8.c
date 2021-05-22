#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Vamos definir um tipo Dicionario para armazenar, para cada palavra que já apareceu no
texto, o número de vezes que tal aconteceu. */


typedef struct entrada{
    char *palavra;
    int ocorr;
    struct entrada *prox;
} *Palavras;

typedef Palavras Dicionario;

/* Para cada uma das alternativas que vamos definir para o tipo Dicionario é necessário 
definir as funções:

void initDic (Dicionario *d) que inicializa o dicion´ario a vazio. */
    
void initDic (Dicionario *d){
  while(d != NULL){
        Palavras a = *d;
        *d = a -> prox;
        free(d);
  }
}

//Or

void initDic (Dicionario *d){
  *d = NULL;
}

/* int acrescenta (Dicionario *d, char *pal) que acrescenta uma ocorrência da palavra pal ao
dicionário *d. A função deverá retornar o número de vezes que a palavra pal passou a ter após a
inserção. */

int acrescenta (Dicionario *d, char *pal){
    while (*d != NULL && (strcmp ((*d)->palavra,pal) != 0)){
            d = &((*d)->prox);
            if (*d == NULL) {
                *d = malloc (sizeof (struct entrada));
               (*d)->palavra = strdup (pal);
               (*d)->ocorr = 1;
               (*d)->prox=NULL;
            } else (*d)->ocorr++;
    }
    return (*d)->ocorr;
}

/* char *maisFreq (Dicionario d, int *c) que calcula a palavra mais frequente de um dicionário
(retornando ainda em c o número de ocorrências dessa palavra). */

char *maisFreq (Dicionario d, int *c){
  char *word = NULL; int max = 0;
  if(d != NULL){
     word = d -> palavra; max = d -> ocorr;
     for(;d;d=d->prox)
         if(d->ocorr > max){
           max = d->ocorr;
           word = d -> palavra;
         }
  *c = max;
  return word;
  }
}
