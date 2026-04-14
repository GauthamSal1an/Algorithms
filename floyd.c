// Online C compiler to run C program online
#include <stdio.h>
#define MAX 20

int a[MAX][MAX], n, d[MAX][MAX];
void input(int [MAX][MAX], int);
void display(int [MAX][MAX], int);
void floyd(int [MAX][MAX], int);
int min(int, int);

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter weight matrix: \n");
    input(a, n);
    printf("Displaying weight matrix: \n");
    display(a, n);
    floyd(a, n);
    printf("Displaying distance matrix: \n");
    display(d, n);
}

void input(int a[MAX][MAX], int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            scanf("%d", &a[i][j]);
        }
    }
}

void display(int a[MAX][MAX], int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
}

void floyd(int a[MAX][MAX], int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            d[i][j] = a[i][j];
        }
    }
    int i, j, k;
    for (int k = 0; k < n; k++){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                d[i][j] = min(d[i][k] + d[k][j], d[i][j]);
            }
        }
    }
}

int min(int a, int b){
    if (a < b){
        return a;
    }else{
        return b;
    }
}
