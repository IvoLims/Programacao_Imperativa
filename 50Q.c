#include <stdio.h>
#include <string.h>
/*Extra stuff*/
void printVector(int v[], int n){
    int i;
    printf("{");
    for(i=0;i<n-1;i++){
        printf("%d,", v[i]);
    }
    printf("%d", v[i]);
    printf("}\n");
}
void printMatrixFloat(int N, int M, float intMatrix[N][M]){
    int x,y;
    for(x=0;x<N;x++){
        printf("| ");
        for(y=0;y<M;y++){
            printf("%1.f ", intMatrix[x][y]);
        }
        printf("|\n");
    }
}
void printMatrixInt(int N, int M, int intMatrix[N][M]){
    int x,y;
    for(x=0;x<N;x++){
        printf("|");
        for(y=0;y<M;y++){
            printf("%d ", intMatrix[x][y]);
        }
        printf("|\n");
    }
}
void removeNewLine(char s[]){
    int i;
    for(i=0;s[i]!='\n';i++);
    s[i]='\0';
}



/*1*/
void mSum (){
    int r, input;
    r=input=0;
    do{
        printf("Number (0 to stop)? ");
        scanf("%d", &input);
        getchar();
        r+=input;
    }while(input!=0);

    printf("Result: %d\n", r);
}
/*2*/
void mBiggest (){
    int r, input;
    r=input=0;
    do{
        printf("Number (0 to stop)? ");
        scanf("%d", &input);
        getchar();
        if (r<input)
        {
            r=input;
        }
    }while(input!=0);
    printf("Result: %d\n", r);
}
/*3*/
void mAverage (){
    float r, input, i;
    r=input=i=0;
    do{
        printf("Number (0 to stop)? ");
        scanf("%f", &input);
        getchar();
        r+=input;
        i++;
    }while(input!=0);
    i--;
    r = r/i;
    printf("Result: %f\n", r);
}
/*4*/
void mSBiggest (){
    int biggest, mSBiggest, input;
    biggest=mSBiggest=input=0;
    do{
        printf("Number (0 to stop)? ");
        scanf("%d", &input);
        getchar();
        if (input>biggest)
        {
            mSBiggest=biggest;
            biggest=input;
        }
    }while(input!=0);

    printf("Result: %d\n", mSBiggest);
}
/*5*/
int mBitsUm (unsigned int n) {
    int r=0;
    while(n>0){
        r+= n % 2;
        n/=2;
    }
    return r;
}
/*6*/
int mTrailingZ(unsigned int n){
    int r, i;
    r=0;
    i=-1;
    while(r!=1 && n){
        r=n%2;
        n/=2;
        i++;
    }
    return i;
}
/*7*/
int mQDig(unsigned int n){
    int i=0;
    while(n){
        n/=10;
        i++;
    }
    return i;
}
/*8*/
int mStrlen(char str[]){
    int i;
    for (i = 0; str[i]; ++i);
    return i;
}
/*9*/
char *mStrcat(char s1[], char s2[]){
    int i,j;
    i=mStrlen(s1);
    j=0;
    while(s2[j]){
        s1[i]=s2[j];
        j++;
        i++;
    }
    s1[i]='\0';
    return s1;
}
/*10*/
char *mStrcpy(char *dest, char source[]){
    int i;
    for (i=0;source[i]; ++i)
    {
        dest[i]=source[i];
    }
    dest[i]='\0';
    return &(dest[0]);
}
/*11*/
int mStrcmp(char s1[], char s2[]){
    int i,j;
    for (i=0; s1[i]; ++i);
    for (j=0; s2[j]; ++j);
    
    return i-j;
}
/*12*/
int mStrstrAux(char s1[], char s2[]){
    int i=0;
    while(s1[i]==s2[i]){
        i++;
        if(s2[i]=='\0')return 1;
    }
    return 0;

}
char *mStrstr(char s1[], char s2[]){
    int i=0;
    while(s1[i]){
        if (s1[i]==s2[0]){
            if(mStrstrAux(&s1[i],s2)){
                return &s1[i];
            }
        }
        i++;
    }
    return NULL;
}
/*13*/
void mStrrev(char s1[]){
    char tmp;
    int i,j;
    j=mStrlen(s1)-1;
    i=0;
    while(i<j){
       tmp=s1[i];
       s1[i]=s1[j];
       s1[j]=tmp;
       i++;j--;
    }
}
/*14*/
void mStrnoV(char s[]){
    int r,w;
    for(r=0, w=0;s[r];++r){
        if(s[r]!='A' && s[r]!='E' && s[r]!='I' && s[r]!='O' && s[r]!='U' && s[r]!='a' && s[r]!='e' && s[r]!='i' && s[r]!='o' && s[r]!='u'){
            s[w]=s[r];
            w++;
        }
    }
    s[w]='\0';
}
/*15*/
void mTruncW(char t[], int n){
    int r, n2=0, w=0;
    for (r=0; t[r]; ++r){

        if(t[r]==' '){
            n2=0;
            t[w]=t[r];
            w++;
        }else{
            if(n2<n){
                t[w]=t[r];
                w++;
                n2++;
            }
        }
    }
    t[w]='\0';
}
/*16*/
int freqChar(char x, char s[]){
    int counter=0,i;
    for (i = 0; s[i]; ++i)
    {
        if(x==s[i]){counter++;}
    }
    return counter;
}
char mCharMaisfreq(char s[]){
    int i,tmp,res;
    tmp=res=0;
    char c='0';
    for (i = 0; s[i]; ++i)
    {
        tmp=freqChar(s[i],s);
        if(res<tmp){
            res=tmp;
            c=s[i];
        }
    }
    return c;
}
/*17*/
int mIguaisConsecutivos(char s[]){
    int i, record, combo;
    combo=record=1;
    if(s[0]){
        for (i = 1; s[i]; ++i)
        {
            if(s[i-1]==s[i]){
                combo++;
            }else{
                combo=1;
            }
            if(combo>record){
                record=combo;
            }
        }
    }
    return record;
}
/*18*/
int mDifConsecutivos(char s[]){
    int i, combo, record;
    record=combo=1;
    if(s[0]){
        for (i=1;s[i]; ++i)
        {
            if(s[i-1]!=s[i]){
                combo++;
            }else{
                combo=1;
            }
            if(combo>record){
                record=combo;
            }
        }
    }
    return record;
}
/*19*/
int mMaiorPrefixo(char s1[], char s2[]){
    int i, counter=0;
    for (i = 0;s1[i] && s2[i]; ++i)
    {
        if(s1[i]==s2[i]){
            counter++;
        }else{
            break;
        }
    }
    return counter;
}
/*20*/
int mMaiorSufixo(char s1[], char s2[]){
    int i, j, counter=0;
    i=mStrlen(s1)-1;
    j=mStrlen(s2)-1;
    for (;i && j; --i, --j){
        if(s1[i]==s2[j]){
            counter++;
        }else{
            break;
        }
    }
    return counter;
}
/*21*/
int sufPref(char s1[], char s2[]){
    int i,j,r;
    for(i=j=r=0;s1[i];i++){
        if(s1[i]==s2[j]){
            r++;
            j++;
        }else{
            j=0;
            r=0;
        }
    }
    return r;
}
/*22*/
int mContaPal(char s[]){
    int r=0,i;
    if(s[0]==' '){
        return 0;
    }
    for(i=1;s[i];i++){
        if(s[i]==' ' && s[i-1]!=' '){
            r++;
        }else{
            if(s[i+1]=='\0' && s[i]!=' '){
                r++;
            }
        }
        
    }
    return r;
}
/*23*/
int mContaVogais(char s[]){
    int r=0,i;
    for(i=0;s[i];i++){
        if(s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'||s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
            r++;
        }
    }
    return r;
}
/*24*/
int elem(char c, char s[]){
    int i;
    for(i=0;s[i];i++){
        if(c==s[i]){
            return 1;
        }
    }
    return 0;
}
int mContida(char s1[], char s2[]){
    int i;
    for(i=0;s1[i];i++){
        if(!elem(s1[i],s2)){
            return 0;
        }
    }
    return 1;
}
/*25*/
int mPalindrome(char s[]){
    int i,j;
    j=mStrlen(s)-1;
    for(i=0;i<j;i++,j--){
        if(s[i]!=s[j]){
            return 0;
        }
    }
    return 1;
}
/*26*/
int mRemRep(char s[]){
    int r,w;
    for(r=1,w=1;s[r];r++){
        if(s[r-1]!=s[r]){
            s[w]=s[r];
            w++;
        }
    }
    s[w]='\0';
    return 0;
}
/*27*/
int mLimpaEspacos(char t[]){
    int r, w;
    if(t[0]=='\0'){return 0;}
    for(r=w=1;t[r];r++){
        if(t[r]==' '){
            if(t[r-1]!=' '){
                t[w]=t[r];
                w++;
            }
        }else{
            t[w]=t[r];
            w++;
        }
    }
    t[w]='\0';
    return 0;
}
/*28*/
void mInsere(int v[], int N, int x){
    int i;
    for(i=N-1;i && x<v[i];i--);
    v[i]=x;
}
/*29*/
void mMerge(int r [], int a[], int b[], int na, int nb){
    int ia,ib,ir;
    ia=ib=ir=0;
    while(ia<na && ib<nb){
        if(a[ia]<b[ib]){
            r[ir]=a[ia];
            ia++;
        }else{
            r[ir]=b[ib];
            ib++;
        }
        ir++;
    }
    if(ia==na){
        while(ib<nb){
            r[ir]=b[ib];
            ib++;
            ir++;
        }
    }else{
        while(ia<na){
            r[ir]=a[ia];
            ia++;
            ir++;
        }
    }
}
/*30*/
int mCrescente(int a[], int i, int j){
    i++;
    while(i<=j){
        if(a[i-1]>a[i]){
            return 0;
        }
        i++;
    }
    return 1;
}
/*31*/
int mRetiraNeg(int v[], int N){
    int n=N;
    int r,w;
    for(r=0;r<N;r++){
        if(v[r]>-1){
            v[w]=v[r];
            w++;
        }else{
            n--;
        }
    }
    return n;
}
/*32*/
int mMenosFreq(int v[], int n){
    int i, leastFreq=0, nLeastFreq=99999, current, nCurrent=0;
    current=v[0];
    for(i=0;i<n;i++){
        if(v[i]==current){
            nCurrent++;
        }else{
            if(nLeastFreq>nCurrent){
                leastFreq=current;
                nLeastFreq=nCurrent;
            }
            current=v[i];
            nCurrent=1;
        }
    }
    if(nLeastFreq>nCurrent){
        leastFreq=current;
        nLeastFreq=nCurrent;
    }
    return leastFreq;
}
/*33*/
int mMaisFreq(int v[], int n){
    int mostFreq=0, nMostFreq=0, current, nCurrent;
    int i;
    for(i=0;i<n;i++){
        if(v[i]==current){
            nCurrent++;
        }else{
            if(nMostFreq<nCurrent){
                mostFreq=current;
                nMostFreq=nCurrent;
            }
            current=v[i];
            nCurrent=1;
        }
    }
    if(nMostFreq<nCurrent){
        mostFreq=current;
        nMostFreq=nCurrent;
    }
    return mostFreq;
}
/*34*/
int mMaxCresc(int v[], int n){
    int r=0,tmp=1,i;
    for(i=1;i<n;i++){
        if(v[i-1]<v[i]){
            tmp++;
        }else{
            if(tmp>r){
                r=tmp;
                tmp=1;
            }
        }
    }
    return r;
}
/*35*/
int mElimRep(int v[], int n){
    int n2=n,i,r,w;
    for(i=0;i<n2;i++){
        for(r=w=i+1;r<n;r++){
            if(v[r]!=v[i]){
                v[w]=v[r];
                w++;
            }else{
                n2--;
            }
        }
        n=n2;
    }
    return n;
}
/*36*/
int mElimRepOrd(int v[], int n){
    int r,w=1;
    for(r=1;r<n;r++){
        if(v[r-1]!=v[r]){
            v[w]=v[r];
            w++;
        }
    }
    return w;
}
/*37*/
int intComp(int a, int b){
    if(a<b){
        return -1;
    }
    if(a>b){
        return 1;
    }
    return 0;
}
int mComunsOrd(int a[], int na, int b[], int nb){
    int ia,ib,r=0;
    ia=ib=0;
    if(a[ia]<b[ib]){
        while(a[ia]<b[ib]){
            ia++;
        }
    }else{
       while(a[ia]>b[ib]){
            ib++;
        } 
    }
    while(ia<na && ib<nb){
        switch(intComp(a[ia],b[ib])){
            case -1 :
                ia++;
            case 0 :
                r++;
                ia++;
                ib++;
            case 1 :
                ib++;
        }
    }
    return r;
}
/*38*/
int elemVector(int x, int b[], int nb){
    int i;
    for(i=0;i<nb;i++){
        if(x==b[i]){
            return 1;
        }
    }
    return 0;
}
int mComuns(int a[], int na, int b[], int nb){
    int i,r;
    r=0;
    for(i=0;i<na;i++){
        if(elemVector(a[i],b,nb)){
            r++;
        }
    }
    return r;
}
/*39*/
int mMinInd(int v[], int n){
    int i, index, smallest;
    i=0;
    smallest=v[i];
    index=0;
    for(i=1;i<n;i++){
        if(smallest>v[i]){
            smallest=v[i];
            index=i;
        }
    }
    return index;
}
/*40*/
void mSomasAc(int v[], int Ac[], int N){
    int i,sum;
    sum=0;
    for(i=0;i<N;i++){
        sum+=v[i];
        Ac[i]=sum;
    }
}
/*41*/
int mTriSup(int N, float m [N][N]){
    int l,c;
    for(l=1;l<N;l++){
        for(c=0;c<l;c++){
            if(m[l][c]!=0){
                return 0;
            }
        }
    }
    return 1;
}
/*42*/
void mTransposta (int N, float m[N][N]){
    int l,c;
    int tmp;
    for(l=0;l<N;l++){
        for(c=0;c<l;c++){
            tmp=m[l][c];
            m[l][c]=m[c][l];
            m[c][l]=tmp;
        }
    }
}
/*43*/
void mAddTo (int N, int M, int a[N][M], int b[N][M]){
    int x,y;
    for(x=0;x<N;x++){
        for(y=0;y<M;y++){
            a[x][y]+=b[x][y];
        }
    }
}
/*44*/
void mSumDiag (int N, int m[N][N]){
    int i,j,sum;
    for(i=0;i<N;i++){
        sum=0;
        for(j=0;j<N;j++){
            if(j!=i){
                sum+=m[i][j];
            }
        }
        m[i][i]=sum;
    }
}
/*45*/
void mAscii(){
    int i;
    char a='a';
    char A='A';
    for (i=0; i<26; ++i)
    {
        printf("%c, %d\n", (A+i),(A+i));
    }

    for (i=0; i<26; ++i)
    {
        printf("%c, %d\n", (a+i),(a+i));
    }
}
/*46*/
int mUnionSet (int N, int v1[N], int v2[N], int r[N]){
    int i;
    for(i=0;i<N;i++){
        r[i]=0;
    }
    for (i = 0; i < N; ++i)
    {
        if (v1[i]==1)r[i]=1;
        if (v2[i]==1)r[i]=1;
    }
    return 0;
}
/*47*/
int mIntersectSet(int N, int v1[N], int v2[N], int r[N]){
    int i;
    for(i=0;i<N;i++){
        if(v1[i]==1 && v2[i]==1){
            r[i]=1;
        }else{
            r[i]=0;
        }
    }
    return 0;
}
/*48*/
int min(int a, int b){
    if(a<b){
        return a;
    }else{
        return b;
    }
}
int mIntersectMSet(int N, int v1[N], int v2[N], int r[N]){
    int i;
    for(i=0;i<N;i++){
        r[i]=min(v1[i],v2[i]);
    }
    return 0;
}
/*49*/
int mUnionMSet(int N, int v1[N], int v2[N], int r[N]){
    int i;
    for(i=0;i<N;i++){
        r[i]=v1[i]+v2[i];
    }
    return 0;
}
/*50*/
int mCardinalMSet(int N, int v[N]){
    int i,r;
    r=0;
    for(i=0;i<N;i++){
        r+=v[i];
    }
    return r;
}
int main()
{
    int decision, intInput, intInput1, intInput2;
    int intVector[4] = {2,4,6,8};
    float fltInput;
    char strInput0[1000], strInput1[1000];
    
    do{
        printf("Question number (0 to exit): ");
        fgets(strInput0, 1000, stdin);
        sscanf(strInput0, "%d", &decision);        
        printf("\n");

        switch (decision){
            case 0 : break;
            case 1 :
                printf("Returns the sum of the given numbers.\n");
                mSum();
                break;
            case 2 :
                printf("Returns the biggest of the given numbers.\n");
                mBiggest();
                break;
            case 3 :
                printf("Returns the average of the given numbers.\n");
                mAverage();
                break;
            case 4 :
                printf("Returns the second biggest number.\n");
                mSBiggest();
                break;
            case 5 :
                printf("Returns the number of 1's required to represent the given number in binary.\n");
                printf("Number? ");
                scanf("%d", &intInput);
                getchar();
                printf("Result: %d\n", mBitsUm(intInput));
                break;
            case 6 :
                printf("Returns the exponent of the biggest power of 2, divisor of the given number.\n");
                printf("Number? ");
                scanf("%d", &intInput);
                getchar();
                printf("Result: %d\n", mTrailingZ(intInput));
                break;
            case 7 :
                printf("Returns the number of digits used to represent the given number.\n");
                printf("Number? ");
                scanf("%d", &intInput);
                getchar();
                printf("Result: %d\n", mQDig(intInput));
                break;
            case 8 :
                printf("Returns the length of the given string.\n");
                printf("String? ");
                fgets(strInput0, 1000, stdin);
                removeNewLine(strInput0);
                printf("Result: %d\n", mStrlen(strInput0));
                break;
            case 9 :
                printf("Concatenates two strings.\n");
                printf("String 1? ");
                fgets(strInput0, 1000, stdin);
                removeNewLine(strInput0);
                printf("String 2? ");
                fgets(strInput1, 1000, stdin);
                removeNewLine(strInput1);
                printf("Result: %s\n", mStrcat(strInput0, strInput1));
                break;
            case 10 :
                printf("Copies a string to the another adress.\n");
                printf("String? ");
                fgets(strInput0, 1000, stdin);
                removeNewLine(strInput0);
                printf("Result: %s\n", mStrcpy(strInput1, strInput0));
                break;
            case 11 :
                printf("Compares the size of 2 strings.\n");
                printf("String 1? ");
                fgets(strInput0, 1000, stdin);
                removeNewLine(strInput0);
                printf("String 2? ");
                fgets(strInput1, 1000, stdin);
                removeNewLine(strInput1);
                printf("Result: %d\n", mStrcmp(strInput0,strInput1));
                break;
            case 12 :
                printf("Returns the adress of where the second string occurs in the first one.\n");
                printf("String 1? ");
                fgets(strInput0, 1000, stdin);
                removeNewLine(strInput0);
                printf("String 2? ");
                fgets(strInput1, 1000, stdin);
                removeNewLine(strInput1);
                printf("Result: %s\n", mStrstr(strInput0, strInput1));
                break;
            case 13 :
                printf("Reverses a string.\n");
                printf("String? ");
                fgets(strInput0, 1000, stdin);
                removeNewLine(strInput0);
                mStrrev(strInput0);
                printf("Result: %s\n", strInput0);
                break;
            case 14 :
                printf("Removes the vowels in a string\n");
                printf("String? ");
                fgets(strInput0, 1000, stdin);
                removeNewLine(strInput0);
                mStrnoV(strInput0);
                printf("Result: %s\n", strInput0);
                break;
            case 15 :
                printf("Cuts all words in a string to be the given size\n");
                printf("String? ");
                fgets(strInput0, 1000, stdin);
                removeNewLine(strInput0);
                printf("Size? ");
                scanf("%d", &intInput);
                getchar();
                mTruncW(strInput0, intInput);
                printf("%s\n", strInput0);
                break;
            case 16 :
                printf("Returns the most frequent character.\n");
                printf("String? ");
                fgets(strInput0, 1000, stdin);
                removeNewLine(strInput0);
                printf("Result: %c\n", mCharMaisfreq(strInput0));
                break;
            case 17 :
                printf("Returns the lenght of the biggest sub-string with equal characters.\n");
                printf("String? ");
                fgets(strInput0, 1000, stdin);
                removeNewLine(strInput0);
                printf("Result: %d\n", mIguaisConsecutivos(strInput0));
                break;
            case 18 :
                printf("Returns the lenght of the biggest sub-string with different characters.\n");
                printf("String? ");
                fgets(strInput0, 1000, stdin);
                removeNewLine(strInput0);
                printf("Result: %d\n", mDifConsecutivos(strInput0));
                break;
            case 19 :
                printf("Returns the lenght of the common prefix.\n");
                printf("String 1? ");
                fgets(strInput0, 1000, stdin);
                removeNewLine(strInput0);
                printf("String 2? ");
                fgets(strInput1, 1000, stdin);
                removeNewLine(strInput1);
                printf("Result: %d\n", mMaiorPrefixo(strInput0,strInput1));
                break;
            case 20 :
                printf("Returns the size of the biggest sufix.\n");
                printf("String 1? ");
                fgets(strInput0, 1000, stdin);
                removeNewLine(strInput0);
                printf("String 2? ");
                fgets(strInput1, 1000, stdin);
                removeNewLine(strInput1);
                printf("Result: %d\n", mMaiorSufixo(strInput0, strInput1));
                break;
            case 21 :
                printf("Returns the size of the common end of the first string and the begining of the second string.\n");
                printf("String 1? ");
                fgets(strInput0, 1000, stdin);
                removeNewLine(strInput0);
                printf("String 2? ");
                fgets(strInput1, 1000, stdin);
                removeNewLine(strInput1);
                printf("Result: %d\n", sufPref(strInput0,strInput1));
                break;
            case 22 :
                printf("Returns the number of words in a string.\n");
                printf("String? ");
                fgets(strInput0, 1000, stdin);
                removeNewLine(strInput0);
                printf("Result: %d\n", mContaPal(strInput0));
                break;
            case 23 :
                printf("Returns the number of vowels.\n");
                printf("String? ");
                fgets(strInput0, 1000, stdin);
                removeNewLine(strInput0);
                printf("Result: %d\n", mContaVogais(strInput0));
                break;
            case 24 :
                printf("Checks if all the characters in the first string are in the second string.\n");
                printf("String 1? ");
                fgets(strInput0, 1000, stdin);
                removeNewLine(strInput0);
                printf("String 2? ");
                fgets(strInput1, 1000, stdin);
                removeNewLine(strInput1);
                if(mContida(strInput0,strInput1)){
                    printf("Result: True\n");
                }else{
                    printf("Result: False\n");
                }
                break;
            case 25 :
                printf("Checks if a string is a palindrome.\n");
                printf("String? ");
                fgets(strInput0, 1000, stdin);
                removeNewLine(strInput0);
                if(mPalindrome(strInput0)){
                    printf("Result: True\n");
                }else{
                    printf("Result: False\n");
                }
                break;
            case 26 :
                printf("Removes consecutive equal characters.\n");
                printf("String? ");
                fgets(strInput0, 1000, stdin);
                removeNewLine(strInput0);
                mRemRep(strInput0);
                printf("Result: %s\n", strInput0);
                break;
            case 27 :
                printf("Removes extra spaces.\n");
                printf("String? ");
                fgets(strInput0, 1000, stdin);
                removeNewLine(strInput0);
                mLimpaEspacos(strInput0);
                printf("Result: %s\n", strInput0);
                break;
            case 28 :
                printf("Inserts a number in a ordered vector.\n");
                printf("Vector = {2,4,6,8}\n");
                printf("Number? ");
                scanf("%d", &intInput);
                getchar();
                mInsere(intVector, 4, intInput);
                printVector(intVector, 4);
                intVector[0] = 2;
                intVector[1] = 4;
                intVector[2] = 6;
                intVector[3] = 8;
                break;
            case 29 :{
                printf("Merges two ordered arrays.\n");
                int size0;
                printf("Vector 1 Size ? ");
                scanf("%d", &size0);
                getchar();
                int intVector0[size0];

                for(intInput=0;intInput<size0;intInput++){
                    printf("Vector 1, Index %d? ", intInput);
                    scanf("%d", &intInput1);
                    getchar();
                    intVector0[intInput]=intInput1;
                }

                int size1;
                printf("Vector 2 Size ? ");
                scanf("%d", &size1);
                getchar();
                int intVector1[size1];

                for(intInput=0;intInput<size1;intInput++){
                    printf("Vector 2, Index %d? ", intInput);
                    scanf("%d", &intInput1);
                    getchar();
                    intVector1[intInput]=intInput1;
                }
                int intVector2[size0+size1];
                printf("Array: ");
                printVector(intVector0, size0);
                printf("Array: ");
                printVector(intVector1, size1);
                if(mCrescente(intVector0, 0, size0-1) && mCrescente(intVector1, 0, size1-1)){
                    mMerge(intVector2, intVector0, intVector1, size0, size1);
                    printf("Result: ");
                    printVector(intVector2, size0+size1);
                }else{
                    printf("Arrays have to be ordered in from smallest to biggest!\n");
                }
                break;}
            case 30 :{
                printf("Tests if the given array is ordered from smallest to biggest.\n");
                int size;
                printf("Vector 1 Size ? ");
                scanf("%d", &size);
                getchar();
                int intVector[size];

                for(intInput=0;intInput<size;intInput++){
                    printf("Vector 1, Index %d? ", intInput);
                    scanf("%d", &intInput1);
                    getchar();
                    intVector[intInput]=intInput1;
                }
                printf("Array: ");
                printVector(intVector, size);
                printf("From which index? ");
                scanf("%d", &intInput);
                getchar();
                printf("To which index? ");
                scanf("%d", &intInput1);
                getchar();
                if(intInput<size && intInput1<size && mCrescente(intVector, intInput, intInput1)){
                    printf("Result: True\n");
                }else{
                    printf("Result: False\n");
                }
                break;}
            case 31 :{
                printf("Removes negative numbers from an array.\n");
                int size;
                printf("Array size? ");
                scanf("%d", &size);
                getchar();
                int intVector[size];

                for(intInput=0;intInput<size;intInput++){
                    printf("Index %d? ", intInput);
                    scanf("%d", &intInput1);
                    getchar();
                    intVector[intInput]=intInput1;
                }
                printf("Array: ");
                printVector(intVector, size);
                size=mRetiraNeg(intVector, size);
                printf("Result: ");
                printVector(intVector, size);
                printf("\n");
                break;}
            case 32 :{
                printf("Returns the least frequent number in an array.\n");
                int size;
                printf("Array size? ");
                scanf("%d", &size);
                getchar();
                int intVector[size];

                for(intInput=0;intInput<size;intInput++){
                    printf("Index %d? ", intInput);
                    scanf("%d", &intInput1);
                    getchar();
                    intVector[intInput]=intInput1;
                }
                printf("Array: ");
                printVector(intVector, size);
                printf("Result: %d\n", mMenosFreq(intVector, size));
                break;}
            case 33 :{
                printf("Returns the most frequent number in an array.\n");
                int size;
                printf("Array size? ");
                scanf("%d", &size);
                getchar();
                int intVector[size];

                for(intInput=0;intInput<size;intInput++){
                    printf("Index %d? ", intInput);
                    scanf("%d", &intInput1);
                    getchar();
                    intVector[intInput]=intInput1;
                }
                printf("Array: ");
                printVector(intVector, size);
                printf("Result: %d\n", mMaisFreq(intVector, size));
                break;}
            case 34 :{
                printf("Returns the length of the biggest ordered sequence.\n");
                int size;
                printf("Array size? ");
                scanf("%d", &size);
                getchar();
                int intVector[size];

                for(intInput=0;intInput<size;intInput++){
                    printf("Index %d? ", intInput);
                    scanf("%d", &intInput1);
                    getchar();
                    intVector[intInput]=intInput1;
                }
                printf("Array: ");
                printVector(intVector, size);
                printf("Result: %d\n", mMaxCresc(intVector, size));
                break;}
            case 35 :{
                printf("Removes the repeated numbers from an array.\n");
                int size;
                printf("Array size? ");
                scanf("%d", &size);
                getchar();
                int intVector[size];

                for(intInput=0;intInput<size;intInput++){
                    printf("Index %d? ", intInput);
                    scanf("%d", &intInput1);
                    getchar();
                    intVector[intInput]=intInput1;
                }
                printf("Array: ");
                printVector(intVector, size);
                size=mElimRep(intVector, size);
                printf("Result: ");
                printVector(intVector, size);
                break;}
            case 36 :{
                printf("Removes the repeated numbers in an ordered array.\n");
                int size;
                printf("Array size? ");
                scanf("%d", &size);
                getchar();
                int intVector0[size];

                for(intInput=0;intInput<size;intInput++){
                    printf("Index %d? ", intInput);
                    scanf("%d", &intInput1);
                    getchar();
                    intVector0[intInput]=intInput1;
                }
                printf("Array: ");
                printVector(intVector, size);
                if(mCrescente(intVector0, 0, size-1)){
                    size=mElimRepOrd(intVector0, size);
                    printf("Result: ");
                    printVector(intVector0, size);
                }else{
                    printf("Array is not ordered!\n");
                }
                break;}
            case 37 :{
                printf("Returns the number of common elements in 2 ordered arrays.\n");
                int size0;
                printf("Vector 1 Size ? ");
                scanf("%d", &size0);
                getchar();
                int intVector0[size0];

                for(intInput=0;intInput<size0;intInput++){
                    printf("Vector 1, Index %d? ", intInput);
                    scanf("%d", &intInput1);
                    getchar();
                    intVector0[intInput]=intInput1;
                }

                int size1;
                printf("Vector 2 Size ? ");
                scanf("%d", &size1);
                getchar();
                int intVector1[size1];

                for(intInput=0;intInput<size1;intInput++){
                    printf("Vector 2, Index %d? ", intInput);
                    scanf("%d", &intInput1);
                    getchar();
                    intVector1[intInput]=intInput1;
                }
                printf("Array 1: ");
                printVector(intVector0, size0);
                printf("Array 2: ");
                printVector(intVector1, size1);
                if(mCrescente(intVector0, 0, size0-1) && mCrescente(intVector1, 0, size1-1)){
                    intInput=mComunsOrd(intVector0, size0, intVector1, size1);
                    printf("Result: %d\n", intInput);
                }else{
                    printf("Arrays have to be ordered from smallest to biggest\n");
                }
                break;}
            case 38 :{
                printf("Returns the number of common elements in 2 arrays.\n");
                int size0;
                printf("Vector 1 Size ? ");
                scanf("%d", &size0);
                getchar();
                int intVector0[size0];

                for(intInput=0;intInput<size0;intInput++){
                    printf("Vector 1, Index %d? ", intInput);
                    scanf("%d", &intInput1);
                    getchar();
                    intVector0[intInput]=intInput1;
                }

                int size1;
                printf("Vector 2 Size ? ");
                scanf("%d", &size1);
                getchar();
                int intVector1[size1];

                for(intInput=0;intInput<size1;intInput++){
                    printf("Vector 2, Index %d? ", intInput);
                    scanf("%d", &intInput1);
                    getchar();
                    intVector1[intInput]=intInput1;
                }
                printf("Array 1: ");
                printVector(intVector0, size0);
                printf("Array 2: ");
                printVector(intVector1, size1);
                intInput=mComuns(intVector0, size0, intVector1, size1);
                printf("Result: %d\n", intInput);
                break;}
            case 39 :{
                printf("Returns the index of the smallest number in an array.\n");
                int size;
                printf("Array size? ");
                scanf("%d", &size);
                getchar();
                int intVector0[size];

                for(intInput=0;intInput<size;intInput++){
                    printf("Index %d? ", intInput);
                    scanf("%d", &intInput1);
                    getchar();
                    intVector0[intInput]=intInput1;
                }
                printf("Result: %d\n", mMinInd(intVector0, size));
                break;}
            case 40 :{
                printf("Fills a new array with the acumulated sums of the given array.\n");
                int size0;
                printf("Vector 1 Size ? ");
                scanf("%d", &size0);
                getchar();
                int intVector0[size0];

                for(intInput=0;intInput<size0;intInput++){
                    printf("Vector 1, Index %d? ", intInput);
                    scanf("%d", &intInput1);
                    getchar();
                    intVector0[intInput]=intInput1;
                }
                int intVector1[size0];
                mSomasAc(intVector0,intVector1,size0);
                printVector(intVector1,size0);
                break;}
            case 41 :{
                printf("Checks if a square matrix is \"Trinagular superior\".\n");
                int size;
                printf("Matrix size? ");
                scanf("%d", &size);
                getchar();
                float intMatrix[size][size];

                for(intInput=0;intInput<size;intInput++){
                    for(intInput1=0;intInput1<size;intInput1++){
                        printf("Line %d, Column %d: ", intInput, intInput1);
                        scanf("%f", &fltInput);
                        getchar();
                        intMatrix[intInput][intInput1]=fltInput;
                    }
                }
                printMatrixFloat(size, size, intMatrix);
                if(mTriSup(size,intMatrix)){
                    printf("Result: True\n");
                }else{
                    printf("Result: False\n");
                }
                break;}
            case 42 :{
                printf("Tranposes the given matrix.\n");
                int size;
                printf("Matrix size? ");
                scanf("%d", &size);
                getchar();
                float intMatrix[size][size];

                for(intInput=0;intInput<size;intInput++){
                    for(intInput1=0;intInput1<size;intInput1++){
                        printf("Line %d, Column %d: ", intInput, intInput1);
                        scanf("%f", &fltInput);
                        getchar();
                        intMatrix[intInput][intInput1]=fltInput;
                    }
                }
                mTransposta(size, intMatrix);
                printf("Result:\n");
                printMatrixFloat(size, size, intMatrix);
                break;}
            case 43 :{
                printf("Adds the second matrix to the first.\n");
                int sizeLine;
                printf("Matrix width? ");
                scanf("%d", &sizeLine);
                getchar();
                int sizeColumn;
                printf("Matrix height? ");
                scanf("%d", &sizeColumn);
                getchar();
                int intMatrix0[sizeLine][sizeColumn];
                printf("Matrix 1:\n");
                for(intInput=0;intInput<sizeLine;intInput++){
                    for(intInput1=0;intInput1<sizeColumn;intInput1++){
                        printf("Line %d, Column %d: ", intInput, intInput1);
                        scanf("%d", &intInput2);
                        getchar();
                        intMatrix0[intInput][intInput1]=intInput2;
                    }
                }
                int intMatrix1[sizeLine][sizeColumn];
                printf("Matrix 2:\n");
                for(intInput=0;intInput<sizeLine;intInput++){
                    for(intInput1=0;intInput1<sizeColumn;intInput1++){
                        printf("Line %d, Column %d: ", intInput, intInput1);
                        scanf("%d", &intInput2);
                        getchar();
                        intMatrix1[intInput][intInput1]=intInput2;
                    }
                }
                mAddTo(sizeLine,sizeColumn,intMatrix0,intMatrix1);
                printMatrixInt(sizeLine, sizeColumn, intMatrix0);
                break;}
            case 44 :{
                printf("Replaces each element of the diagonal with the sum of all other elements of the same line (doesn't work)\n");
                int size;
                printf("Matrix size? ");
                scanf("%d", &size);
                getchar();
                int intMatrix[size][size];

                for(intInput=0;intInput<size;intInput++){
                    for(intInput1=0;intInput1<size;intInput1++){
                        printf("Line %d, Column %d: ", intInput, intInput1);
                        scanf("%d", &intInput2);
                        getchar();
                        intMatrix[intInput][intInput1]=intInput2;
                    }
                }
                mSumDiag(size,intMatrix);
                printMatrixInt(size, size, intMatrix);
                break;}
            case 45 :{
                printf("Prints on the screen all the letters int the alphabet and their respective ASCII code\n");
                mAscii();
                break;}
            case 46 :{
                printf("I can't bother\n");
                printf("Set 1:\n");
                int intVector0[]={0,0,0,0,0,0,0,0};
                do{
                    printf("Pick a number between 0 and 7 (-1 to stop)\n");
                    scanf("%d", &intInput);
                    getchar();
                    if(intInput==-1){break;}
                    if(intInput>-1 && intInput<8){
                        intVector0[intInput]=1;
                    }
                }while(1);
                printf("Set 2:\n");
                int intVector1[]={0,0,0,0,0,0,0,0};
                do{
                    printf("Pick a number between 0 and 7 (-1 to stop)\n");
                    scanf("%d", &intInput);
                    getchar();
                    if(intInput==-1){break;}
                    if(intInput>-1 && intInput<8){
                        intVector1[intInput]=1;
                    }
                }while(1);
                int intVector2[8];
                mUnionSet(8, intVector0, intVector1, intVector2);
                printVector(intVector2, 8);
                break;}
            case 47 :{
                printf("I still can't bother\n");
                printf("Set 1:\n");
                int intVector0[]={0,0,0,0,0,0,0,0};
                do{
                    printf("Pick a number between 0 and 7 (-1 to stop)\n");
                    scanf("%d", &intInput);
                    getchar();
                    if(intInput==-1){break;}
                    if(intInput>-1 && intInput<8){
                        intVector0[intInput]=1;
                    }
                }while(1);
                printf("Set 2:\n");
                int intVector1[]={0,0,0,0,0,0,0,0};
                do{
                    printf("Pick a number between 0 and 7 (-1 to stop)\n");
                    scanf("%d", &intInput);
                    getchar();
                    if(intInput==-1){break;}
                    if(intInput>-1 && intInput<8){
                        intVector1[intInput]=1;
                    }
                }while(1);
                int intVector2[8];
                mIntersectSet(8, intVector0, intVector1, intVector2);
                printVector(intVector2, 8);
                break;}
            case 48 :{
                printf("I hope you're having a fine day\n");
                printf("Set 1:\n");
                int intVector0[]={0,0,0,0,0,0,0,0};
                do{
                    printf("Pick a number between 0 and 7 (-1 to stop)\n");
                    scanf("%d", &intInput);
                    getchar();
                    if(intInput==-1){break;}
                    if(intInput>-1 && intInput<8){
                        intVector0[intInput]+=1;
                    }
                }while(1);
                printf("Set 2:\n");
                int intVector1[]={0,0,0,0,0,0,0,0};
                do{
                    printf("Pick a number between 0 and 7 (-1 to stop)\n");
                    scanf("%d", &intInput);
                    getchar();
                    if(intInput==-1){break;}
                    if(intInput>-1 && intInput<8){
                        intVector1[intInput]+=1;
                    }
                }while(1);
                int intVector2[8];
                mIntersectMSet(8, intVector0, intVector1, intVector2);
                printVector(intVector2, 8);
                break;}
            case 49 :{
                printf("Almost there\n");
                printf("Set 1:\n");
                int intVector0[]={0,0,0,0,0,0,0,0};
                do{
                    printf("Pick a number between 0 and 7 (-1 to stop)\n");
                    scanf("%d", &intInput);
                    getchar();
                    if(intInput==-1){break;}
                    if(intInput>-1 && intInput<8){
                        intVector0[intInput]+=1;
                    }
                }while(1);
                printf("Set 2:\n");
                int intVector1[]={0,0,0,0,0,0,0,0};
                do{
                    printf("Pick a number between 0 and 7 (-1 to stop)\n");
                    scanf("%d", &intInput);
                    getchar();
                    if(intInput==-1){break;}
                    if(intInput>-1 && intInput<8){
                        intVector1[intInput]+=1;
                    }
                }while(1);
                int intVector2[8];
                mUnionMSet(8, intVector0, intVector1, intVector2);
                printVector(intVector2, 8);
                break;}
            case 50 :{
                printf("Yay last one\n");
                printf("Set:\n");
                int intVector0[]={0,0,0,0,0,0,0,0};
                do{
                    printf("Pick a number between 0 and 7 (-1 to stop)\n");
                    scanf("%d", &intInput);
                    getchar();
                    if(intInput==-1){break;}
                    if(intInput>-1 && intInput<8){
                        intVector0[intInput]+=1;
                    }
                }while(1);
                printf("Result: %d\n", mCardinalMSet(8, intVector0));
                printVector(intVector0, 8);
                break;}
            default : 
                printf("Please enter a number between 1 and 50.\n");
        }
    }while(decision!=0);
    return 0;
}
