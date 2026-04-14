// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>
#define MAX 128

int table[MAX];
int horspool(char [], char []);
int main() {
    char t[MAX], p[MAX];
    int i;
    printf("Enter text string: ");
    scanf("%s", t);
    printf("Enter pattern string: ");
    scanf("%s", p);
    i = horspool(t, p);
    if (i == -1){
        printf("The pattern is not present in the text");
    }else{
        printf("The pattern is present in position %d", i+1);
    }
}

void shift_table(char p[]){//create shift table
    int m =  strlen(p);
    for (int i = 0; i < MAX; i++){
        table[i] = m;//put length m in all 128 table
    }
    for (int j = 0; j < m-1; j++){
        table[p[j]] = m-1-j;//update value
    }
}

int horspool(char t[], char p[]){
    shift_table(p);
    int m = strlen(p);
    int n = strlen(t);
    int i = m - 1;//start from index end
    while (i < n) {
        int k = 0;//init to 0
        while (k < m && p[m-1-k] == t[i-k]){
            k++;//check all
        }
        if(k==m){
            return i-m+1;//final index if found
        }else{
            i += (int)table[t[i]];//add
        }
    }
    return -1;
}
