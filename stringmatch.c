// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>
#define MAX 20

int strmatch(char [], char [], int, int);

int main(){
    char t[20], p[20];
    int n, m, k;
    printf("Enter text: ");
    scanf("%s", t);
    printf("Enter pattern: ");
    scanf("%s", p);
    n = strlen(t);
    m = strlen(p);
    k = strmatch(t, p , n, m);
    if (k == -1) 
        printf("The pattern is present in the given text.");
    else
        printf("The pattern is present at %d position.", k);
}

int strmatch(char t[], char p[], int n, int m){
    int j;
    for (int i = 0; i < n - m + 1; i++){
        //outer loop to iterate over all elements in the text till the text cannot accomodate the pattern
        j = 0;
        while (j < m && t[i+j] == p[j])
            //inner loop to compare characters and increment
            j = j + 1;
        //if by end of while j=m then exists else continue
        if (j == m){
            return i;
        }
    }
    return -1;
}
