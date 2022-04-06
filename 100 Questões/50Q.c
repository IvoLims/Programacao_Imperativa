#include <stdio.h>
#include <string.h>

/* 1. Defina um programa que lê (usando a função scanf uma sequência de números inteiros 
terminada com o número 0 e imprime no ecran o maior elemento da sequência. */

void maiorElem(){
  int val,mval,flag=0;
  do{
  printf("Insert the value: ");
  scanf("%d",&val);
  if(flag) flag=1, mval = val;
  if(mval < val) mval = val;
  }while(val != 0);
  printf("The biggest value is %d.\n",mval);
}

/* 2. Defina um programa que lê (usando a função scanf uma sequência de números inteiros 
terminada com o número 0 e imprime no ecran a média da sequência. */

void media(){
  int val, tval=0, i=0;
  do{
  printf("Insert the value: ");
  scanf("%d",&val);
  tval+= val, i++;
  }while(val != 0);
  printf("The average is %d",tval/2);
}

/* 3. Defina um programa que lê (usando a função scanf uma sequência de números inteiros 
terminada com o número 0 e imprime no ecran o segundo maior elemento. */

void segMElem(){
  int val,segmval,mval,flag=0;
  do{
  printf("Insert the value: ");
  scanf("%d",&val);
  if(flag) flag=1, mval = val;
  if(mval < val) segmval=mval, mval = val;
  }while(val != 0);
  printf("The second biggest value is %d.\n",segmval);
}

/* 4. Defina uma função int bitsUm (unsigned int n) que calcula o número de bits iguais a 1
usados na representação binária de um dado número n. */

int bitsUm (unsigned int n){
  int res=0;
  for(;n>0;n/=2){
    res+=n%2;
  }
  return res;
}

/* 5. Defina uma função int trailingZ (unsigned int n) que calcula o número de bits a 0 no
final da representação binária de um número (i.e., o expoente da maior potência de 2 que é
divisor desse número). */

int trailingZ(unsigned int n){
    int res = 0;
    while (n > 0){
      if(!(n & 1)){
        res++;
      }
      n = n >> 1; // Shifts the bits in `n` one bit to the right, i.e., n = n / 2
    }
    return res;
}

/* 6. Defina uma função int qDig (unsigned int n) que calcula o número de dígitos necessários
para escrever o inteiro n em base decimal. Por exemplo, qDig (440) deve retornar 3. */

int qDig (unsigned int n){
  int res=0;
  for(;n>0;n/=10){
    res++;
  }
  return res;
}

/* 7. Apresente uma definição da função pré-definida em C char *strcat (char s1[], char
s2[]) que concatena a string s2 a s1 (retornando o endereço da primeira). */

char* mystrcat (char s1[], char s2[]){
  int i = strlen(s1), j=0;
  while(s2[j]){
    s1[i++] = s2[j++];
  }
  s1[i] = '\0';
  return s1;
}

/* 8. Apresente uma definição da função pré-definida em C char *strcpy (char *dest, char
source[]) que copia a string source para dest retornando o valor desta última. */

char* mystrcpy (char *dest, char source[]){
  int i=0;
  while(dest[i] == source[i]){
    i++;
  }
  dest[i] = '\0';
  return &(dest[0]);
}

/* 9. Apresente uma definição da função pré-definida em C int strcmp (char s1[], char s2[])
que compara (lexicograficamente) duas strings. O resultado deverá ser

• 0 se as strings forem iguais
• < 0 se s1 < s2
• > 0 se s1 > s2
*/

int mystrcmp (char s1[], char s2[]){
  int i=0;
  while(s1[i] == s2[i] && s1[i]){
    i++;
  }
  return *s1 - *s2;
}

/* 10. Apresente uma definição da função pré-definida em C char *strstr (char s1[], char
s2[]) que determina a posição onde a string s2 ocorre em s1. A função deverá retornar
NULL caso s2 não ocorra em s1. */

char* mystrstr (char s1[], char s2[]){
  int i=0, j=0, flag=0;
  if(s1 == NULL || s2 == NULL) return NULL;
  do{
    if(flag && s2){
      return &s1[i-j];
    }
    if(s2[j] == s1[i]){
      j++;
      flag = 1;
    }else{
      j=flag=0;
    }
  }while(s1[i++]);
  return NULL;
}

/* 11. Defina uma função void strrev (char s[]) que inverte uma string. */

void mystrrev (char s[]){
  int len = strlen(s), i = len-1, j;
  char copia[i+1];
  for(j=0; i>=0 ;i--,j++){
    copia[j] = s[i];
  }
  printf("The string reverse is %s.",strcpy(s,copia));
}

/* 12. Defina uma função void strnoV (char s[]) que retira todas as vogais de uma string. */

int Vogais(char s) {
    if (s == 'A' || s == 'a' || s == 'E' || s == 'e'
     || s == 'I' || s == 'i' || s == 'O' || s == 'o'
     || s == 'U' || s == 'u') return 1;
    return 0;
}

void mystrnoV (char s[]){
  int len = strlen(s), i, j=0;
  char copia[len]; 
  for(i=0; s[i]; i++){
    if(Vogais(s[i]) == 0){
      copia[j]=s[i];
      j++;
    }
  }
  copia[j]='\0';
  printf("The string without vowels is %s.",strcpy(s,copia));
}

/* 13. Defina uma função void truncW (char t[], int n) que dado um texto t com várias palavras
(as palavras estão separadas em t por um ou mais espaços) e um inteiro n, trunca todas as
palavras de forma a terem no máximo n caracteres. Por exemplo, se a string txt contiver
"liberdade, igualdade e fraternidade", a invocação de truncW (txt, 4) deve fazer
com que passe a estar lá armazenada a string "libe igua e frat". */

int spaces(char s) {
    if (s == ' ' || s == '\n' || s == '\t')  return 1;
    return 0;
}

void mytruncW (char t[], int n){
    int i = 0,j = 0,s = n;
    char copia[strlen(t)];
    strcpy(copia,t);
    while (copia[i]!=0) {
        while (copia[i] != ' ' && copia[i]!= '\0') {
            if (n > 0 && copia[i]!=' ') {
                t[j]=copia[i];
                n--;
                j++;
            }
            i++;
        }
        t[j] = copia[i];
        i++;
        j++;
        n=s;
    }
    t[j] = '\0';
}

/* 14. Defina uma função char charMaisfreq (char s[]) que determina qual o caracter mais 
frequente numa string. A função deverá retornar 0 no caso de s ser a string vazia. */

int freqC(char c, char s[]){
  int freq = 0, j;
  for(j = 0; s[j]; j++){
    if(s[j] == c){
      freq++;
    }
  }
  return freq;
}

char charMaisfreq (char s[]){
  int freq, maisFreq = 0, i;
  char freqChar = 0;
  for(i=0; s[i]; i++){
    if((freq = (freqC(s[i],s))) > maisFreq){
      maisFreq = freq;
      freqChar = s[i];
    }
  }
  printf("The most frequent char is %c appearing %d times.",freqChar,maisFreq);
  return freqChar;
}

/* 15. Defina uma função int iguaisConsecutivos (char s[]) que, dada uma string s calcula o
comprimento da maior sub-string com caracteres iguais. Por exemplo, iguaisConsecutivos
("aabcccaac") deve dar como resultado 3, correspondendo à repetição "ccc". */

int iguaisConsecutivos(char s[]){
  int freq=1, maisFreq = 0, i;
  char freqChar;
  if(s[0] == '\0') return 0;
  for(i = 0; s[i]; i++){
    if(s[i] == s[i+1]){
      freq++;
      freqChar = s[i];
    } else{
      if(freq > maisFreq){
        maisFreq = freq;
      }
      freq = 1;
    }
  }
  printf("The most frequent char is %c appearing %d times.",freqChar,maisFreq);
  return maisFreq;
}

/* 16. Defina uma função int difConsecutivos (char s[]) que, dada uma string s calcula o
comprimento da maior sub-string com caracteres diferentes. Por exemplo, difConsecutivos
("aabcccaac") deve dar como resultado 3, correspondendo à string "abc". */

int difConsecutivos (char s[]){
  int i, maisFreq, freq=1;
  if(s[0] == '\0') return 0;
  for(int i = 0; s[i];i++){
    if(s[i] != s[i+1]){
      freq++;
    }
    else{
      if(maisFreq < freq){
        maisFreq = freq;
      }
      freq = 1;
    }
  }
  printf("The number of most different characters in a sequence is %d.",maisFreq);
  return maisFreq;
}

/* 17. Defina uma função int maiorPrefixo (char s1 [], char s2 []) que calcula o comprimento 
do maior prefixo comum entre as duas strings. */

int maiorPrefixo (char s1 [], char s2 []){
  int i;
  for(i = 0; s1[i] == s2[i] && s1[i];i++);
  printf("The longest common prefix between the two strings has value %d.",i);
  return i;
}

/* 18. Defina uma função int maiorSufixo (char s1 [], char s2 []) que calcula o comprimento 
do maior sufixo comum entre as duas strings. */

int maiorSufixo (char s1 [], char s2 []){
  int res = 0, i, j;
  for(i = 0; s1[i]; i++);
  for(j = 0; s2[j]; j++);
  while(s1[i--] == s2[j--]) res++;
  printf("The longest common suffix between the two strings has value %d.",res);
  return res;
}

/* 19. Defina a função int sufPref (char s1[], char s2[]) que calcula o tamanho do maior
sufixo de s1 que é um prefixo de s2. Por exemplo sufPref("batota","totalidade") deve
dar como resultado 4, uma vez que a string "tota" é um sufixo de "batota" e um prefixo de
"totalidade". */

int sufPref(char s1[], char s2[]){
  int res = 0, i, j=0;
  while(s1[i] != '\0' && s2[j] != '\0'){
    if(s1[i] != s2[j]){
      i++;
    }else{
      if(s1[i] == s2[j]){
        for(;s1[i] == s2[j] && s1[i] != '\0'; i++, j++){
          res++;
        }
      }
    }
  }
  printf("The longest common suffix that is prefix between the two strings has value %d.",res);
  return res;
}

/* 20. Defina uma função int contaPal (char s[]) que conta as palavras de uma string. Uma
palavra é uma sequência de caracteres (diferentes de espaço) terminada por um ou mais
espaços. Assim se a string p tiver o valor "a a bb a", o resultado de contaPal (p) deve ser
4. */

int contaPal (char s[]){
  int i = 0, res=0;
  for(; s[i]; i++){
    if(s[i] == ' ' || s[i] == '\n' || s[i] == '\t'){
      res++;
    }
  }
  return res+1;
}

/* 21. Defina uma função int contaVogais (char s[]) que retorna o número de vogais da string
s. Não se esqueça de considerar tanto maiúsculas como minúsculas. */

int VogaisUpper(char s) {
    if (s == 'A' || s == 'E' || s == 'I' ||  s == 'O' || s == 'U') return 1;
    return 0;
}

int contaVogais (char s[]){
  int i = 0, j = 0, res = 0;
  for(; i < strlen(s); i++){
    s[i] = toupper(s[i]);
  }
  for(; j < strlen(s); j++){
    if(VogaisUpper(s[j]) == 1) res++;
  }
  printf("There's %d vowels in the string.\n", res);
  return res;
}

/* 22. Defina uma função int contida (char a[], char b[]) que testa se todos os caracteres da
primeira string também aparecem na segunda. Por exemplo, contida "braga" "bracara
augusta" deve retornar verdadeiro enquanto que contida "braga" "bracarense" deve retornar falso. */

int contida (char a[], char b[]){
  
}

/* 23. Defina uma função int palindorome (char s[]) que testa se uma palavra é palíndrome,
i.e., lê-se de igual forma nos dois sentidos. */

/* 24. Defina uma função int remRep (char x[]) que elimina de uma string todos os caracteres
que se repetem sucessivamente deixando lá apenas uma cópia. A função deverá retornar o
comprimento da string resultante. Assim, por exemplo, ao invocarmos a função com uma
vector contendo "aaabaaabbbaaa", o vector deve passar a conter a string "ababa" e a função
deverá retornar o valor 5. */

/* 25. Defina uma função int limpaEspacos (char t[]) que elimina repetições sucessivas de espaços
por um único espaço. A função deve retornar o comprimento da string resultante. */

/* 26. Defina uma função void insere (int v[], int N, int x) que insere um elemento (x) num
vector ordenado. Assuma que as N primeiras posições do vector estão ordenadas e que por
isso, após a inserção o vector terá as primeiras N+1 posições ordenadas. */

/* 27. Defina uma função void merge (int r [], int a[], int b[], int na, int nb) que, dados 
vectores ordenados a (com na elementos) e b (com nb elementos), preenche o vector r (com
na+nb elementos) com os elementos de a e b ordenados. */

/* 28. Defina uma função int crescente (int a[], int i, int j) que testa se os elementos do
vector a, entre as posições i e j (inclusivé) estão ordenados por ordem crescente. A função
deve retornar 1 ou 0 consoante o vector esteja ou não ordenado. */

/* 29. Defina uma função int retiraNeg (int v[], int N) que retira os números negativos de
um vector com N inteiros. A função deve retornar o número de elementos que não foram
retirados. */

int retiraNeg (int v[], int N){
  int rem = 0,i,j=0;
  for(i = 0; i < N; i++){
    if(v[i]<0){
      rem++;
    }
    else if(v[i]>0 && j<N-1) v[j] = v[i],j++;
  }
  return N - rem;
}

/* 30. Defina uma função int menosFreq (int v[], int N) que recebe um vector v com N elementos 
ordenado por ordem crescente e retorna o menos frequente dos elementos do vector. Se houver mais 
do que um elemento nessas condições deve retornar o que começa por aparecer no índice mais baixo. */

int menosFreq (int v[], int N){
  int freq = 1,freqMin = N, menor = v[0], indexM = N, i;
  for(i=1;i<N;i++){
    if(v[i] == v[i-1]) freq++;
    else if(v[i] != v[i-1] && freq < freqMin && i < indexM) menor = v[i-1], freqMin = freq, freq = 1;
    else freq = 1;
  }
  return menor;
}

/* 31. Defina uma função int maisFreq (int v[], int N) que recebe um vector v com N elementos ordenado 
por ordem crescente e retorna o mais frequente dos elementos do vector. Se houver mais do que um elemento 
nessas condições deve retornar o que começa por aparecer no índice mais baixo. */

/* 32. Defina uma função int maxCresc (int v[], int N) que calcula o comprimento da maior
sequência crescente de elementos consecutivos num vector v com N elementos. Por exemplo,
se o vector contiver 10 elementos pela seguinte ordem: 1, 2, 3, 2, 1, 4, 10, 12, 5, 4, a
função deverá retornar 4, correspondendo ao tamanho da sequência 1, 4, 10, 12. */

int maxCresc (int v[], int N){
  int seq, mSeq = 0,i,j,k;
  for(i = 0; i<N; i++){
    seq = 1;
    j = i+1;
    for(k=i;v[k]<=v[j];k++) j++, seq++;
    if(seq > mSeq) mSeq = seq;
  }
  return mSeq;
}

int maxCresc2 (int v[], int N){
  int seq, mSeq = 0,i,ant=v[0],j;
  for(i = 1; i<N; i++){
    if(ant <= v[i]) seq++, ant = v[i];
    else if(seq > mSeq) mSeq = seq, seq=1, ant = v[i];
    else seq = 1, ant = v[i];
  }
  return mSeq;
}

/* 33. Defina uma função int elimRep (int v[], int n) que recebe um vector v com n inteiros e
elimina as repetições. A função deverá retornar o número de elementos do vector resultante.
Por exemplo, se o vector v contiver nas suas primeiras 10 posições os números {1, 2, 3, 2, 1, 4, 2, 4, 5, 4}
a invocação elimRep (v,10) deverá retornar 5 e colocar nas primeiras 5 posições do vector
os elementos {1,2,3,4,5}. */

/* 34. Defina uma função int elimRepOrd (int v[], int n) que recebe um vector v com n inteiros ordenado 
por ordem crescente e elimina as repetições. A função deverá retornar o número de elementos do vector resultante. */

/* 35. Defina uma função int comunsOrd (int a[], int na, int b[], int nb) que calcula quantos elementos 
os vectores a (com na elementos) e b (com nb elementos) têm em comum. Assuma que os vectores a e b estão 
ordenados por ordem crescente. */

/* 36. Defina uma função int comuns (int a[], int na, int b[], int nb) que calcula quantos
elementos os vectores a (com na elementos) e b (com nb elementos) têm em comum. Assuma
que os vectores a e b não estão ordenados e defina a função sem alterar os vectores. */

/* 37. Defina uma função int minInd (int v[], int n) que, dado um vector v com n inteiros,
retorna o índice do menor elemento do vector. */

int minInd (int v[], int n){
  int i, ind = 0;
  for(i = 0; i<n; i++){
    if(v[i]<v[ind]) ind = i;
  }
  return ind;
}

/* 38. Defina uma função void somasAc (int v[], int Ac [], int N) que preenche o vector
Ac com as somas acumuladas do vector v. Por exemplo, na posição Ac[3] deve ser calculado como v[0]+v[1]+v[2]+v[3]. */

/* 39. Defina uma função int triSup (int N, float m [N][N]) que testa se uma matriz quadrada é triangular 
superior, i.e., que todos os elementos abaixo da diagonal são zeros. */

/* 40. Defina uma função void transposta (int N, float m [N][N]) que transforma uma matriz na sua transposta. */

/* 41. Defina uma função void addTo (int N, int M, int a [N][M], int b[N][M]) que adiciona a segunda matriz à primeira. */

/* 42. Uma forma de representar conjuntos de índices consiste em usar um array de inteiros contendo
1 ou 0 consoante esse índice pertença ou não ao conjunto. Assim o conjunto {1, 4, 7} seria
representado por um array em que as primeiras 8 posições conteriam {0,1,0,0,1,0,0,1}.
Apresente uma definição da função int unionSet (int N, int v1[N], int v2[N], int
r[N]) que coloca no array r o resultado da união dos conjuntos v1 e v2. */

/* 43. Uma forma de representar conjuntos de índices consiste em usar um array de inteiros contendo
1 ou 0 consoante esse índice pertença ou não ao conjunto. Assim o conjunto {1, 4, 7} seria
representado por um array em que as primeiras 8 posições conteriam {0,1,0,0,1,0,0,1}.
Apresente uma definição da função int intersectSet (int N, int v1[N], int v2[N],
int r[N]) que coloca no array r o resultado da intersecção dos conjuntos v1 e v2. */

/* 44. Uma forma de representar multi-conjuntos de índices consiste em usar um array de inteiros
contendo em cada posição o número de ocorrências desse índice. Assim o multi-conjunto
{1, 1, 4, 7, 7, 7} seria representado por um array em que as primeiras 8 posições conteriam
{0,2,0,0,1,0,0,3}.
Apresente uma definição da função int intersectMSet (int N, int v1[N], int v2[N],
int r[N]) que coloca no array r o resultado da intersecção dos multi-conjuntos v1 e v2. */


/* 45. Uma forma de representar multi-conjuntos de índices consiste em usar um array de inteiros
contendo em cada posição o número de ocorrências desse índice. Assim o multi-conjunto
{1, 1, 4, 7, 7, 7} seria representado por um array em que as primeiras 8 posições conteriam
{0,2,0,0,1,0,0,3}.
Apresente uma definição da função int unionMSet (int N, int v1[N], int v2[N], int
r[N]) que coloca no array r o resultado da união dos multi-conjuntos v1 e v2. */

/* 46. Uma forma de representar multi-conjuntos de índices consiste em usar um array de inteiros
contendo em cada posição o número de ocorrências desse índice. Assim o multi-conjunto
{1, 1, 4, 7, 7, 7} seria representado por um array em que as primeiras 8 posições conteriam
{0,2,0,0,1,0,0,3}.
Apresente uma definição da função int cardinalMSet (int N, int v[N]) que calcula a
número de elementos do multi-conjunto v. */

/* 47. Considere as seguintes definições para representar as posições e movimentos de um robot. */

typedef enum movimento {Norte, Oeste, Sul, Este} Movimento;

typedef struct posicao {
  int x, y;
} Posicao;

/* Defina a função Posicao posFinal (Posicao inicial, Movimento mov[], int N) que,
dada uma posição inicial e um array com N movimentos, calcula a posição final do robot depois
de efectuar essa sequência de movimentos. */

/* 48. Considere as seguintes definições para representar as posições e movimentos de um robot.

typedef enum movimento {Norte, Oeste, Sul, Este} Movimento;

typedef struct posicao {
  int x, y;
} Posicao;

Defina a função int caminho (Posicao inicial, Posicao final, Movimento mov[], int
N) que, dadas as posições inicial e final do robot, preenche o array com os movimentos suficientes para 
que o robot passe de uma posição para a outra.
A função deverá preencher no máximo N elementos do array e retornar o número de elementos
preenchidos. Se não for possível atingir a posição final com N movimentos, a função deverá
retornar um número negativo. */

/* 49. Considere o seguinte tipo para representar a posição de um robot numa grelha.

typedef struct posicao {
  int x, y;
} Posicao; 

Defina a função int maisCentral (Posicao pos[], int N) que, dado um array com N posições, 
determina o índice da posição que está mais perto da origem (note que as coordenadas de cada 
ponto são números inteiros). */

/* 50. Considere o seguinte tipo para representar a posição de um robot numa grelha.

typedef struct posicao {
  int x, y;
} Posicao;

Defina a função int vizinhos (Posicao p, Posicao pos[], int N) que, dada uma posição
e um array com N posições, calcula quantas dessas posições são adjacentes à posição dada. */

/*♅-----------------------------------------------------------------------Main Para Testes----------------------------------------------------------------------♅*/

int main(){
    int question, input;
    char s1[1024],s2[1024],si[1024];
    char newLine;
    printf("What question you want to test?\n");
    scanf("%d",&question);
    switch(question){
        case 1:
        maiorElem();
        break;
        case 2:
        media();
        break;
        case 3:
        segMElem();
        break;
        case 4:
        printf("What value you want to know the number of 1's necessary to represent? ");
        scanf("%d",&input);
        int init1=input;
        printf("The number of 1's needed to represent %d are %d.\n", init1, bitsUm(input));
        break;
        case 5:
        printf("What value you want to know the number of 0's? ");
        scanf("%d",&input);
        int init2=input;
        printf("The number of 0's present in %d are %d.\n", init2, trailingZ(input));
        break;
        case 6:
        printf("What value you want to know the number of digits needed to write in decimal base? ");
        scanf("%d",&input);
        int init3=input;
        printf("The number of digits needed to write the integer %d in decimal base are %d.\n", init3, qDig (input));
        break;
        case 7:
        printf("Write the first string: ");
        scanf("%c",newLine); //eat newline
        scanf("%[^\n]s",s1);
        strcpy(si,s1);
        printf("Write the second string: ");
        scanf("%c",newLine); //eat newline
        scanf("%[^\n]s",s2);
        printf("The concat string of %s and %s is %s.\n", si, s2, mystrcat(s1,s2));
        break;
        case 8:
        printf("Write the string to be copy: ");
        scanf("%c",si); //eat newline
        scanf("%[^\n]s",s1);
        printf("The string has been copied %s.\n", mystrcpy(s2,s1));
        break;
        case 9:
        printf("Write the first string: ");
        scanf("%c",si); //eat newline
        scanf("%[^\n]s",s1);
        printf("Write the second string: ");
        scanf("%[^\n]s",s2);
        printf("The comparison of the string %s with %s has value %d.\n", s1, s2, mystrcmp(s1,s2));
        break;
        case 10:
        printf("Write the first string: ");
        scanf("%c",si); //eat newline
        scanf("%[^\n]s",s1);
        printf("Write the second string: ");
        scanf("%[^\n]s",s2);
        printf("The string %s with %s ocorrs in %s.\n", s1, s2, mystrstr(s1,s2));
        break;
        case 11:
        printf("Write the string you want to reverse: ");
        scanf("%c",si); //eat newline
        scanf("%[^\n]s",s1);
        mystrrev(s1);
        break;
        case 12:
        printf("Write the string you want to remove the vowels: ");
        scanf("%c",si); //eat newline
        scanf("%[^\n]s",s1);
        mystrnoV(s1);
        break;
        case 13:
        printf("How many do you want to remove space and then write the string you want to remove letters from: ");
        scanf("%d %[^\n]s", &input, s1);
        mytruncW(s1,input);
        printf("The final result is %s.",s1);
        break;
        case 14:
        printf("Write the string you want to know the most frequent character: ");
        scanf("%c",si); //eat newline
        scanf("%[^\n]s",s1);
        charMaisfreq(s1);
        break;
        case 15:
        printf("Write the string you want to know the characters in a row: ");
        scanf("%c",si); //eat newline
        scanf("%[^\n]s",s1);
        iguaisConsecutivos(s1);
        break;
        case 16:
        printf("Write the string you want to know the different characters in a row: ");
        scanf("%c",si); //eat newline
        scanf("%[^\n]s",s1);
        difConsecutivos(s1);
        break;
        case 17:
        printf("Write the first string: ");
        scanf("%c",si); //eat newline
        scanf("%[^\n]s",s1);
        printf("Write the second string: ");
        scanf("%c",si); //eat newline
        scanf("%[^\n]s",s2);
        maiorPrefixo(s1,s2);
        break;
        case 18:
        printf("Write the first string: ");
        scanf("%c",si); //eat newline
        scanf("%[^\n]s",s1);
        printf("Write the second string: ");
        scanf("%c",si); //eat newline
        scanf("%[^\n]s",s2);
        maiorSufixo(s1,s2);
        break;
        case 19:
        printf("Write the first string: ");
        scanf("%c",si); //eat newline
        scanf("%[^\n]s",s1);
        printf("Write the second string: ");
        scanf("%c",si); //eat newline
        scanf("%[^\n]s",s2);
        sufPref(s1,s2);
        break;
        case 20:
        printf("Write the string you want to count the words: ");
        scanf("%c",si); //eat newline
        scanf("%[^\n]s",s1);
        contaPal(s1);
        break;
        case 21:
        printf("Write the string you want to count the vowels: ");
        scanf("%c",si); //eat newline
        scanf("%[^\n]s",s1);
        contaVogais(s1);
        break;
        default:
        printf("That question doesn't exist\n");
    }
    return 0;
}
