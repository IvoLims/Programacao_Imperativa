#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define Max 100

//1. Feita na Ficha 4

//2. Considere o seguinte tipo para representar queues de números inteiros.

typedef struct staticQueue {
       int front;
       int length;
       int values [Max];
} QUEUE, *SQueue;

/* Defina as seguintes funções sobre este tipo:
(a) void SinitQueue (SQueue q) que inicializa uma queue (passa a representar uma queue
vazia) */

void SinitQueue (SQueue q){
     q -> length = 0;
}

//(b) int SisEmptyQ (SQueue q) que testa se uma queue é vazia

int SisEmptyQ (SQueue q){
    if(q->length != 0) return 1;
    else return 0;
}

/* (c) int Senqueue (SQueue q, int x) que acrescenta x ao fim de q; a função deve retornar
0 se a operação for feita com sucesso (i.e., se a queue ainda não estiver cheia) e 1 se a
operação não fôr possível (i.e., se a queue estiver cheia). */

int Senqueue (SQueue q, int x){
    if(q->front + q->length >= Max) return 1;
    else
       q->values[q->front + q->length++] = x;
    return 0;       
}

/* (d) int Sdequeue (SQueue q, int *x) que remove de uma queue o elemento que está no
início. A função deverá colocar no endereço x o elemento removido. A função deverá
retornar 0 se a operação for possível (i.e. a queue não está vazia) e 1 em caso de erro
(queue vazia). */

int Sdequeue (SQueue q, int *x){
	if(SisEmptyQ(q)) return 1;
	else 
		*x = q->values[(q->front)++];
	    (q->length)--;
	return 0;
}

/* (e) int Sfront (SQueue q, int *x) que coloca no endereço x o elemento que está no início
da queue (sem modificar a queue). A função deverá retornar 0 se a operação for possível
(i.e. a queue não está vazia) e 1 em caso de erro (queue vazia). */

int Sfront (SQueue q, int *x){
	if(SisEmptyQ(q) == 0) return 1;
	else
		*x = q->values[q->front];
	return 0;
}

//Test

int Sdequeue2 (SQueue q){
	if(SisEmptyQ(q) == 0) return 1;
	else 
	    q->length--;
	return q->values[q->front++];
}

int Sfront2 (SQueue q){
	if(SisEmptyQ(q) == 0) return 1;
	return q->values[q->front];
}

int main(){
    QUEUE* q = malloc(sizeof(struct staticQueue));
    Senqueue(q,10);
    Senqueue(q,20);
    Senqueue(q,30);
    while(SisEmptyQ(q) != 0){
          printf("%d the element on top\n",Sfront2(q));
          printf("%d dequeued from queue\n", Sdequeue2(q));
    }
    return 0;
}

/* 3. Na representação de stacks e queues sugeridas nas alíneas anteriores o array de valores tem
um tamanho fixo (definido pela constante MAX). Uma consequência dessa definição é o facto
de as funções de inserção (push e enqueue) poderem não ser executadas por se ter excedido a
capacidade da estruturas.
Uma definição alternativa consiste em não ter um array com tamanho fixo e sempre que seja
preciso mais espaço, realocar o array para um de tamanho superior (normalmente duplica-se o
tamanho do array).
Considere então as seguintes definições alternativas e adapte as funções definidas atrás para esta
nova representação.
Use as funções malloc e free cujo tipo está definido em stdlib.h. */

typedef struct dinStack {
        int size; // guarda o tamanho do array values
        int sp;
        int *values;
} *DStack;

int dupStack (DStack s) {
	int r = 0, i;
	int *t = malloc (2*s->size*sizeof(int));

	if (t == NULL) r = 1;
	else {
		for (i=0; i<s->size; i++) 
			t[i] = s->values[i];
		free (s->values);
		s->values = t;
		s->size*=2;
	}
	return r;
}

void DinitStack (DStack s) {
	s->size = 5;
	s->sp = 0;
	s->values = malloc(sizeof(int) * s->size);
}

int  DisEmpty (DStack s) {
	return s->sp == 0;
}

int  Dpush (DStack s, int x){
	int r=0;
	
	if (s->sp == s->size) dupStack(s);
	s->values[(s->sp)++] = x;
	
	return r;
}

int  Dpop (DStack s, int *x){
	int r=0;
	
	if (s->sp == 0) r = 1;
	else {
	    *x = s->values[--(s->sp)];
	}
	
	return r;
}

int  Dtop (DStack s, int *x){
	int r=0;
	
	if (s->sp == 0) r = 1;
	else {
	    *x = s->values[s->sp-1];
	}
	
	return r;
}
struct dinQueue {
	int size;
	int front;
	int length;
	int *values;
};

typedef struct dinQueue *DQueue;

int dupQueue (DQueue q) {
    int r = 0, i, p;
    int *t = malloc(sizeof(int) * 2 * q->size);
    
    if (t == NULL) r = 1;
    else {
        for (i = 0, p = q->front; i < q->length; i++) {
            t[i] = q->values[p];
            p = (p+1) % q->size;
        }
        free (q->values);
        q->values = t;
        q->front = 0;
        q->size *= 2;
    }
	return r;
}

void DinitQueue (DQueue q) {
    q->size = 5;
    q->front = 0;
    q->length = 0;
    q->values = malloc(sizeof(int) * q->size);
}

int  DisEmptyQ (DQueue q) {
	return q->length == 0;
}

int  Denqueue (DQueue q, int x){
	int r = 0;
	
	if (q->length == q->size) dupQueue(q);
	q->values[(q->front + (q->length)++) % q->size] = x;
	
	return r;
}

int  Ddequeue (DQueue q, int *x){
    int r = 0;
    
    if (q->length == 0) r = 1;
    else {
        *x = q->values[(q->front)++];
        (q->length)--;
    }
    
	return r;
}

int  Dfront (DQueue q, int *x){
    int r = 0;
    
    if (q->length == 0) r = 1;
    else {
        *x = q->values[q->front];
    }
    
	return r;
}
