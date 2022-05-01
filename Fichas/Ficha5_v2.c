#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*Considere o seguinte tipo para representar a informação sobre um aluno: */

typedef struct aluno {
int numero;
char nome[100];
int miniT [6];
float teste;
} Aluno;

/* 1. Defina uma função int nota (Aluno a) que calcula a nota de um aluno (de acordo com as
regras definidas para Programação Imperativa). A função deverá retornar 0 se o aluno não tiver
aproveitamento. */

int nota (Aluno a){
    if((&a) != NULL){
        float notaF = 0;
        float miniTF = 0;
        int j;
        for(j = 0; j<6;j++){
            miniTF+= a.miniT[j];
        }
        miniTF = 0.25 * miniTF;
        notaF = miniTF + (0.75 * a.teste);
        if(notaF > 9.5){
            return (int) notaF;
        } else return 0;
    } else return 0;
}

/* 2. Defina uma função int procuraNum (int num, Aluno t[], int N) que recebe um número de
aluno e um array de alunos ordenado por ordem crescente de número de aluno e retorna o índice
onde esse aluno está armazenado (retorna -1 se o número não existir). */

int procuraNum (int num, Aluno t[], int N){
    int i = 0;
    for(; i<N;i++){
        if(t[i].numero == num){
            return i;
        }
    }
    return -1;
}

/* 3. Defina uma função void ordenaPorNum (Aluno t [], int N) que ordena um array t de N
alunos, por ordem crescente do seu número. */

void ordenaPorNum (Aluno t [], int N){
    int i = 0, j, min;
    Aluno temp;
    for(;i<N;i++){
        min = i;
        for(j=i+1;j<N;j++){
            if(t[j].numero < t[min].numero){
                min = j;
            }
        }
        temp = t[i];
        t[i] = t[min];
        t[min] = temp;
    }
}

/* 4. Uma alternativa à função anterior consiste em calcular um array de índices em que na posição i se
encontra o índice correespondente ao i-ésimo elemento. Defina uma função void criaIndPorNum
(Aluno t [], int N, int ind[]) que preenche o vector ind com os indices correspondentes
a uma ordenação do array t por ordem crescente do número de aluno.

Por exemplo, para N = 4, se o array tivesse os elementos
{{4444, "André", {2,1,0,2,2,2}, 10.5}
,{2222, "Joana", {2,2,2,1,0,0}, 14.5}
,{7777, "Maria", {2,2,2,2,2,1}, 18.5}
,{3333, "Paulo", {0,0,2,2,2,1}, 8.7}
}
A função criaIndPorNum devia preencher o array com {2,0,3,1}. */

void swapNums(int *x, int*y) {
    int t = *x;
    *x = *y;
    *y = t;
}

void criaIndPorNum(Aluno t[], int N, int ind[]) {
    int i, j;
    int in[N];
    for (i = 0; i < N; i++) in[i] = i;
    for (i = 0; i < N; i++) {
        for (j = i; j < N; j++) 
            if (t[in[j]].numero < t[in[i]].numero) swapNums(in+i, in+j);
        ind[in[i]] = i;
    }
}

/* 5. Defina uma função void imprimeTurma (int ind[], Aluno t[], int N) que recebe uma
turma e um array tal como produzido pela função da alínea anterior e imprime os números,
nomes e notas dos alunos por ordem crescente do número de aluno. */

void imprimeTurma(int ind[], Aluno t[], int N){
    int i, j, k;
    for(i=0; i<N; i++){
        for(j=0; ind[j]!=i; j++);
            printf("Número: %d Nome: %s Mini Testes: ",t[ind[j]].numero,t[ind[j]].nome);
            for(k=1;k<6;k++)printf("%d ",t[ind[j]].miniT[k]);
            printf("Teste: ");
            printf("%5.2f \n",t[ind[j]].teste);
    }
}

/* 6. Adapte a função de procura definida na alinea 2 de forma a receber um array de alunos e um
array tal como produzido pela função criaIndPorNum. */

int procuraInd (int num, Aluno t[], int ind[], int N){
    int i = 0;
    for(; i<N && t[i].numero == num; i++);
    return (i < N && t[i].numero == num) ? ind[i] : -1;
}

/* 7. Defina uma outra função void criaIndPorNome (Aluno t [], int N, int ind[]) que preenche
o vector ind com os indices correspondentes a uma ordenação do array t por ordem crescente
do nome do aluno. */

void criaIndPorNome (Aluno t [], int N, int ind[]){
    int i, j;
    int in[N];
    for (i = 0; i < N; i++) in[i] = i;
    for (i = 0; i < N; i++) {
        for (j = i; j < N; j++) 
            if (strcmp(t[in[j]].nome, t[in[i]].nome) < 0) swapNums(in+i, in+j);
        ind[in[i]] = i;
    }
}

/*♅-----------------------------------------------------------------------Main Para Testes----------------------------------------------------------------------♅*/

void imprimeAluno (Aluno *a){
    int i;
    printf ("%-5d %s (%d", a->numero, a->nome, a->miniT[0]);
    for(i=1; i<6; i++) printf (", %d", a->miniT[i]);
    printf (") %5.2f %d\n", a->teste, nota(*a));
}

void dumpV (int v[], int N){
    int i;
    for (i=0; i<N; i++) printf ("%d ", v[i]);
}

int main(){
   int i;
   Aluno Turma1 [4] = {{4444, "André", {2,1,0,2,2,2}, 10.5}
                       ,{3333, "Paulo", {0,0,2,2,2,1},  8.7}
                       ,{8888, "Carla", {2,1,2,1,0,1}, 14.5}
                       ,{2222, "Joana", {2,0,2,1,0,2},  3.5}
                       };
   printf("O aluno com número 1797 existe? R.:%d\n",procuraNum (1797, Turma1, 4));
   printf("A turma sem ordenação é assim:\n");
   for (i=0; i<4; imprimeAluno (Turma1 + i++));
   printf("A turma ordenada tem a seguinte ordem:\n");
   ordenaPorNum(Turma1, 4);
   for (i=0; i<4; imprimeAluno (Turma1 + i++));
   Aluno Turma2 [7] = {{4444, "André", {2,1,0,2,2,2}, 10.5}
                       ,{3333, "Paulo", {0,0,2,2,2,1},  8.7}
                       ,{8888, "Carla", {2,1,2,1,0,1}, 14.5}
                       ,{2222, "Joana", {2,0,2,1,0,2},  3.5}
                       ,{7777, "Maria", {2,2,2,2,2,1},  5.5}
                       ,{6666, "Bruna", {2,2,2,1,0,0}, 12.5}
                       ,{5555, "Diogo", {2,2,1,1,1,0},  8.5}
                       };
   int indNum[7];
   printf("O indice criado por número é ");
   criaIndPorNum(Turma2, 7, indNum);
   for(i=0;i<7;i++){
       printf("%d ",indNum[i]);
   }
   printf("\nA turma organizada usando o array de índices ");
   imprimeTurma(indNum,Turma2,7);
   int indNome[7];
   criaIndPorNome(Turma2, 7, indNome);
   printf("O indice criado por nome é ");
   for(i=0;i<7;i++){
       printf("%d ",indNome[i]);
   }
}
