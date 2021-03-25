#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 1. Defina uma função int contaVogais (char *s) que conta quantas vogais uma string tem. */

int contaVogais (char *s){
    int res=0;
    for(int i = 0; s[i] != '\0';i++){
        if (s[i] == 'a' || s[i] == 'A' || s[i] == 'e' || s[i] == 'E' || s[i] == 'i' || s[i] == 'I' || s[i] =='o' || s[i]=='O' || s[i] == 'u' || s[i] == 'U') res++;
    }
    return res;
}

int main(){
    char s[20];
    printf("Digite uma String:\n");
    scanf("%[^\n]", s);
    int res = contaVogais(s);
    printf("Da String ' %s ' foram contadas %d vogais.\n", s,res);
    return 0;
} 

/* 2. Defina uma função int retiraVogaisRep (char *s) que remove de uma string todas as repetições consecutivas 
de vogais. A função deverá retornar o número de vogas removidas. Por exemplo, se a string a == "Estaa e umaa string 
coom duuuplicadoos" depois de invocarmos retiraVogaisRep a, a string a deverá ter o valor "Esta e uma string com duplicados". */

int retiraVogaisRep(char *s) {
    int i, j, last;
    for (i = j = last = 0; s[i]; last = s[i], i++) {
        if (s[i] != last || !strchr("aeiouAEIOU", s[i]))
            s[j++] = s[i];
    }
    s[j] = '\0';  // set the null terminator
    return i - j;
}

int main() {
    char s[100];
    printf("Digite uma String:\n");
    if (scanf("%99[^\n]", s) != 1)
        return 1;
    int res = retiraVogaisRep(s);
    printf("A String sem duplicados fica assim ' %s ' e foram retiradas %d vogais.\n", s, res);
    return 0;
}

// Can see in here: https://stackoverflow.com/questions/66790357/how-do-i-remove-duplicate-vowels-from-a-string

//Another one more difficult to understand

int isVowel(char ch){
    if (ch >= 'A' && ch <= 'Z')
        ch = (ch - 'A') + 'a';
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
} 
 
int removeVowels(char *s){
    int removed = 0;
    if (s){
        while (*s != '\0'){
               char ch = *s++; 
               if (isVowel(ch) && (*s == ch)){
                   char *src = s, *dst = s;
                   do {
                       ++src;
                       ++removed;
                   }while (*src == ch);
				       while (*src != '\0') {*dst++ = *src++;
				       }
				       *dst = '\0';
            }
        }
    } 
    return removed;
}
 
int main(){
	char s[] = "Estaa e umaa string coom duuuplicadoos";
	int removed = removeVowels(s);
	printf("%s\nRemoved: %d\n", s, removed);
	return 0;
}

/* 3. Defina uma função int duplicaVogais (char *s) que duplica todas as vogais de uma string. A função deve retornar
o número de caracteres acrescentados. Assuma que o array recebido como argumento tem capacidade para armazenar o resultado pretendido. */

int duplicaVogais (char *s){
    int res=0;
    return res;
}

int main() {
    char s[100];
    printf("Digite uma String:\n");
    if (scanf("%99[^\n]", s) != 1)
        return 1;
    int res = duplicaVogais(s);
    printf("A String com duplicados fica assim ' %s ' e foram duplicadas %d vogais.\n", s, res);
    return 0;
}

/* 4. Defina uma função int ordenado (int v[], int N) que testa se um array de inteiros está ordenado por ordem crescente. */

/* 5. Defina uma função void merge (int a[], int na, int b[], int nb, int r[]) que recebe dois arrays ordenados a e b (com 
tamanhos na e nb respectivamente) e os funde num só array ordenado r. Assuma que o array r tem capacidade para armazenar os na+nb elementos. */

/*6. Defina uma função int partition (int v[], int N, int x) que, dado um array v de tamanho N e um inteiro x, reorganiza o 
array de forma a que come¸cam por aparecer todos os elementos menores ou iguais a x seguidos dos restantes elementos. A função 
retorna o número de elementos que ficaram na primeira parte do array (i.e., que são menores ou iguais a x). */