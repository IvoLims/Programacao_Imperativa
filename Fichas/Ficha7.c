#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//1. Considere a seguinte definição de um tipo para representar listas ligadas de inteiros.

typedef struct slist {
int valor;
struct slist * prox;
} Nodo, *LInt;

/* (a) Apresente uma sequência de instruções que coloque na variável a do tipo LInt, uma lista
com 3 elementos: 10, 5 e 15 (por esta ordem). */

void addToa(){
  LInt a = malloc(sizeof(struct slist));
  a->valor = 10;
  a->prox = malloc(sizeof(struct slist));
  a->prox->valor = 5;
  a->prox->prox = malloc(sizeof(struct slist));
  a->prox->prox->valor = 15;
  a->prox->prox->prox = NULL;
}

/* (b) Apresente definições (preferencialmente não recursivas) das seguintes funções sobre listas
ligadas:

i. LInt cons (LInt l, int x) que acrescenta um elemento no inicio da lista. */

LInt cons (LInt l, int x) {
  LInt novo = malloc(sizeof(struct slist));
  novo -> valor = x;
  novo ->prox = l;
  return novo;
}

// ii. LInt tail (LInt l) que remove o primeiro elemento de uma lista não vazia (libertando o correspondente espaço).

LInt tail (LInt l) {
  if(l==NULL){
     return l;
  }else{
  LInt novo = l;
  l = l->prox;
  free(novo);
  }
  return l;
}

/* iii. LInt init (LInt l) que remove o último elemento de uma lista não vazia (libertando
o correspondente espaço). */

LInt init (LInt l){
  if(l==NULL){
    return l;
  }else{
    LInt a = l; 
    LInt end = l->prox;
    for(;end!= NULL;end = end->prox){ a = end; }
        free(end);
        a->prox=NULL;
    }
  return l;
}

//iv. LInt snoc (LInt l, int x) que acrescenta um elemento no fim da lista.

LInt snoc (LInt l, int x){
  if(l==NULL){
    l->valor = x;
    l->prox = NULL;
    return l;
  }else{
    LInt end = l;
    while(l!=NULL){
          end = end->prox;
    }
    LInt toAdd = malloc(sizeof(struct slist));
    toAdd->valor = x;
    toAdd->prox= NULL;
    end ->prox = toAdd;
    }
  return l;
}

/* v. LInt concat (LInt a, LInt b) que acrescenta a lista b a a, retornando o início da
lista resultante). */

LInt concat (LInt a, LInt b){
  LInt la = a;
	while(la != NULL){
    la = la->prox;
  }
  la ->prox = b;
  return a;
}

/* 2. Para gerir a informação sobre os alunos inscritos a uma dada disciplina, é necessário armazenar
os seguintes dados:
• Nome do aluno (string com no máximo 60 caracteres)
• Número do aluno
• Nota

(a) Defina os tipos Aluno e Turma. Para o efeito considere que a informação referente aos
alunos de uma turma é armazenada numa lista ligada de alunos. */

typedef struct Aluno{
char name[60];
int num;
double nota;
}Aluno;

typedef struct Turma {
Aluno aluno;
struct Turma * proxA;
}Turma;

/* (b) Defina uma função int acrescentaAluno (Turma *t, Aluno a) que acrescenta a informação de um dado aluno a 
uma turma. A função deverá retornar 0 se a operação for feita com sucesso. */

int acrescentaAluno (Turma *t, Aluno a){
    Turma* novoA = malloc(sizeof(struct Turma));
    novoA -> aluno = a;
    novoA -> proxA = NULL;
    if(t == NULL) t = novoA;
    else while(t->proxA != NULL){
      t = t->proxA;
    } 
    t->proxA = novoA;
    return 0;
}

/* (c) Defina uma função Aluno *procura (Turma t, int numero) que procura o aluno com
um dado número na turma. A função deve retornar NULL se a informação desse aluno não
existir; caso exista deve retornar o endereço onde essa informação se encontra. */

Aluno *procura (Turma t, int numero){
  Turma* search = &t;
  while(search != NULL){
    if(search -> aluno.num == numero) return &(search->aluno);
  search = search->proxA;
  }
  return NULL;
}

/* (d) Defina uma função que determine quantos alunos obtiveram aproveitamento à disciplina
(nota final maior ou igual a 10). */

int supA10(Turma *t){
  int r = 0;
  while(t!=NULL){
    if(t->aluno.nota >=10) r++;
  t=t->proxA;
  }
  return r;
}

//	For Tests

void printTurma(Turma* t) {
    while(t) {
        printf("Nome: %s - num: %d - nota: %lf\n",t->aluno.name, t->aluno.num, t->aluno.nota);
        t = t->proxA;
    }
}

void printAluno(Turma* t) {
    while(t) {
        printf("%s\n",t->aluno.name);
        t = t->proxA;
    }
}

int main(){
   Turma* t = malloc(sizeof(struct Turma));
   t->aluno = (Aluno){"Gustavina Pereira",12,8};
   t->proxA = NULL;
   Aluno aluno1 = {"Benedita Augusta",895,12.0};
   acrescentaAluno(t,aluno1);
   acrescentaAluno(t,(Aluno){"Fernando Ferreira",69,10.0});
   acrescentaAluno(t,(Aluno){"Solange Quintas",42,7.5});
   printf("Turma:\n");
   printTurma(t);
   printf("Existe o aluno com numero 42, se ele/ela o seu nome é ");
   Aluno ax = *procura(*t,42);
   Turma tx = {ax,NULL};
   printAluno(&tx);
   printf("Notas superiores ou iguais a 10: %d\n",supA10(t));
}

/* 3. O tipo LInt definido acima pode ser usado para implementar stacks de inteiros (a inserção
faz-se no início da lista). */

typedef LInt Stack;

LInt newLInt (int x, LInt xs){
     LInt r = malloc (sizeof (struct slist));
     r->valor = x;
     r->prox  = xs;
     return r;
}

void initStack (Stack *s) {
     (*s) == NULL;
}

int isEmptyS (Stack *s) {
    if(s == NULL) return 0;
    else return 1;
}

int push (Stack *s, int x){
    *s = newLInt(x,*s);
    if(isEmptyS(s) == 0) return 1;
    else return 0;
}

int pop (Stack *s, int *x){
    if(isEmptyS(s) == 0) return 1;
    *x = (*s) -> valor;
    (*s) = (*s)->prox;
    return 0;
}

int top (Stack *s, int *x){
    if(isEmptyS(s) == 0) return 1;
    *x = (*s)->valor;
    return 0;
}

/* 4.  Podemos ainda usar listas ligadas para implementar queues. De forma a garantir a eficiência das
várias operações guardam-se os elementos ligados do primeiro para o último e guarda-se também
o endereço do último elemento armazenado. A inserção faz-se no fim da lista e a remoção no
início*/

typedef struct queue {
LInt front, last;
} Queue;

void initQueue (Queue *q){
  q->front = NULL;
  q->last = NULL;
}

int isEmptyQ (Queue *q){
  if(q -> front == NULL) return 0;
  else return 1;
}

int enqueue (Queue *q, int x){
  LInt temp = newLInt(x,NULL);
  if(isEmptyQ(q) == 0){
     q->front = temp;
     q->last = temp;
  }else {
     q->last->prox = temp;
     q->last = temp;
  }
  return 0;
}

int dequeue (Queue *q, int *x){
  if(isEmptyQ(q) == 0) return 1;
  *x = q->front->valor;
  LInt temp = q->front;
  q->front = q->front->prox;
  free(temp);
  return 0;
}

int front (Queue *q, int *x){
    if(isEmptyQ(q) == 0) return 1;
    *x = q->front->valor;
    return 0;
}
