// Online C compiler to run C program online
#include <stdio.h>
#define MAX 20

int n, weight[MAX], price[MAX], f[MAX][MAX], cap;
void input(int [], int);
int mfknapsack(int, int);
int max(int, int);
void display(int [], int );

void main(){
    printf("Enter number of items:");
    scanf("%d", &n);
    printf("Enter total capacity of knapsack: ");
    scanf("%d", &cap);
    printf("Enter weight matrix: ");
    input(weight, n);
    printf("Enter price matrix: ");
    input(price, n);
    printf("Displaying weight matrix:");
    display(weight, n);
    printf("Displaying price matrix: ");
    display(price, n);
    for (int i= 0; i <= n; i++){
        for (int j = 0; j <= cap; j++){
            if (i == 0 || j == 0)
                f[i][j] = 0;
            else
                f[i][j] = -1;
        }
    }
    int v = mfknapsack(n,cap);
    printf("The maximum value that can be accomodated in the knapsack is %d", v);
}

void input(int a[MAX], int n){
    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
}

void display(int a[MAX], int n){
    for (int j = 0; j < n; j++){
        printf("%d", a[j]);
    }
}

int mfknapsack(int i, int j){
    int v;
    if (f[i][j] < 0){
        if (j < weight[i])
           v = mfknapsack(i-1, j);
        else{
            v = max(mfknapsack(i-1, j),price[i] + mfknapsack(i-1, j-weight[i]));
        }
        f[i][j] = v;
    }
    return f[i][j];

}

int max(int a, int b){
    if (a > b){
        return a;
    }else{
        return b;
    }
}
