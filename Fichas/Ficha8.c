#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct entrada{
    char *palavra;
    int ocorr;
    struct entrada *prox;
} *Palavras;

typedef Palavras Dicionario;

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
