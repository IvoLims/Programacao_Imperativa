#include <stdio.h>
#include <stdlib.h>

/* 1. Defina uma função void insere (int v[], int N, int x) que insere um elemento (x) num vector ordenado. Assuma que as N primeiras posições 
do vector estão ordenadas e que por isso, após a inserção o vector terá as primeiras N+1 posições ordenadas. */

void insere (int v[], int N, int x){
     for(int i=0;i<N;i++){
         if(v[i]>x){
           for(int j=N;j>i;j--){
               v[j] = v[j-1];
           }
               v[i] = x;
               break;
         }
     }if(v[N - 1] < x) v[N] = x;
}

int main(){
    int s[16]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    insere(s,16,2);
    for(int i =0;i<16;i++){
    printf("%d ",s[i]);
    } printf("\n");
    return 0;
}

/* 2. A função ao lado usa a função insere para ordenar um vector. Apresente uma definição alternativa deste algoritmo sem usar a função insert. */

void iSort (int v[], int N) {
     int i;
     for (i=1; (i<N); i++){
          insere(v, i, v[i]);
     }
}

void iSort_Without_insert(int v[], int N){
    int i,j,x;
    for (i=0; i<N; i++){
         x = v[i];
         j=i-1;
         while(j>=0 && v[j]>x){
               v[j+1]=v[j];
               j--;
         }
         v[j+1]=x;
     }
}

int main(){
    int s1[15]={16, 2, 3, 32, 5, 6, 7, 23, 9, 10, 11, 12, 13, 14, 15};
    int s2[15]={16, 2, 3, 32, 5, 6, 7, 23, 9, 10, 11, 12, 13, 14, 15};
    iSort(s1,15);
    iSort_Without_insert(s2, 15);
    //Just to get arrays content
    printf("iSort:   ");
    for(int i =0;i<15;i++){
    printf("%d ",s1[i]);
    } printf("\nMyiSort: ");
    for(int j =0;j<15;j++){
    printf("%d ",s2[j]);
    } printf("\n");

    return 0;
}

/* 3. Defina uma função int maxInd (int v[], int N) que, dado um array com N inteiros, calcula o índice onde está o maior desses inteiros. */

int maxInd (int v[], int N){
    int max = 0;
    for(int i=0;i<N;i++){
        if(v[i]>v[max]) max=i;
    }
    return max;
}

int main(){
    int s[15]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    int res = maxInd(s,15);
    printf("O maior elemento esta na posição %d e é o %d.\n",res,s[res]);
    return 0;
} 

/* 4. Use a função anterior na definição de uma função de ordenação de arrays de inteiros, que vai repetidamente calculando os maiores elementos 
e trocando-os com o elemento que está na última posição. */

void sort_With_maxInd(int v[], int N){
     for(int i = N; i>0 ; i--){
         int j = maxInd(v, i);
         int temp = v[i-1];
             v[i-1] = v[j];
             v[j] = temp;
     }
}

int main(){
    int s[15]={16, 2, 3, 32, 5, 6, 7, 23, 9, 10, 11, 12, 13, 14, 15};
    sort_With_maxInd(s,15);
    for(int i =0;i<15;i++){
    printf("%d ",s[i]);
    } printf("\n");
    return 0;
}

/* 5. Apresente uma definição alternativa do algoritmo da alínea anterior sem usar a função maxInd. */

void sort_Without_maxInd(int v[], int N){
     for(int i = N; i>0 ; i--){
         int max = 0;
         for(int j=0;j<N;j++){
             if(v[j]>v[max]) max=j;
         }
         int temp = v[i-1];
             v[i-1] = v[max];
             v[max] = temp;
     }
}

int main(){
    int s[15]={16, 2, 3, 32, 5, 6, 7, 23, 9, 10, 11, 12, 13, 14, 15};
    sort_Without_maxInd(s,15);
    for(int i =0;i<15;i++){
    printf("%d ",s[i]);
    } printf("\n");
    return 0;
}

/* 6. Considere a definição ao lado da função bubble. Ilustre a execução da função com um pequeno exemplo. Verifique que após
terminar, o maior elemento do vector se encontra na última posição. */

void swap (int v[], int i, int j){
  int temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}

void bubble (int v[], int N) {
     int i;
     for (i=1;(i<N); i++)
          if (v[i-1] > v[i])
              swap(v,i-1, i);
}

int main(){
    int s[15]={16, 2, 3, 32, 5, 6, 7, 23, 9, 10, 11, 12, 13, 14, 15};
    bubble(s,15);
    for(int i =0;i<15;i++){
    printf("%d ",s[i]);
    } printf("\n");
    return 0;
}

/* 7. Use a função bubble na definição de uma função void bubbleSort (int v[], int N) que ordena o array v por sucessivas invocações da função bubble. */

void bubbleSort(int v[], int N) {
    for(int i = 0; i < N; i++)
        bubble(v,N);
}

int main(){
    int s[15]={16, 2, 3, 32, 5, 6, 7, 23, 9, 10, 11, 12, 13, 14, 15};
    bubbleSort(s,15);
    for(int i =0;i<15;i++){
    printf("%d ",s[i]);
    } printf("\n");
    return 0;
}

/* 8. Uma optimização frequente da função bubbleSort consiste em detectar se o array já está ordenado. Para isso basta que uma das passagens pelo 
array não efectue nenhuma troca. Nesse caso podemos concluír que o array já está ordenado. Incorpore essa optimização na função anterior. */

int isSorted(int v[], int N){
    for(int i=1;i<N;i++){
        if(v[i-1]>v[i]) return 1;
    }
    return 0;
}

void bubbleSort_With_Optimization(int v[], int N) {
    for(int i = 0; i < N; i++)
        if(isSorted(v,N) == 0) {printf("It's already sorted. No work to do XD.\nSee: "); break;}
        else bubble(v,N);
}

int main(){
    int s[15]={16, 2, 3, 32, 5, 6, 7, 23, 9, 10, 11, 12, 13, 14, 15};
    //int s[15]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    bubbleSort_With_Optimization(s,15);
    for(int i =0;i<15;i++){
    printf("%d ",s[i]);
    } printf("\n");
    return 0;
}
