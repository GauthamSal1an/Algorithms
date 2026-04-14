// Online C compiler to run C program online
#include <stdio.h>
#define MAX 20

int n, weight[MAX], price[MAX], f[MAX][MAX], cap;
void input(int [], int);
void display(int [], int);
void dfknapsack();
int max(int, int);

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
    dfknapsack();
    printf("The maximum value that can be accomodated in the knapsack is %d", f[n-1][n-1]);
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

void dfknapsack(){
    int i, j;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (i==0 || j==0)//row and column 0 then value 0
                f[i][j] = 0;
            else{
                if (j < weight[i]){//if adding new weight goes past limit then use past value
                    f[i][j] = f[i-1][j];
                }else{
                    f[i][j] = max(f[i-1][j], f[i-1][j-weight[i]] + price[i]);
                }
            }
        }
    }
}

int max(int a, int b){
    if (a > b){
        return a;
    }else{
        return b;
    }
}
