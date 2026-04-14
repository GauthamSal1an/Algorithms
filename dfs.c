// Online C compiler to run C program online
#include <stdio.h>
#define MAX 20

int a[MAX][MAX], n, v[MAX], count = 0;
void input(int [MAX][MAX], int);
void display(int [MAX][MAX], int);
void DFS();
void dfs(int);

int main(){
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix: ");
    input(a, n);
    printf("Displaying adjacency matrix: ");
    display(a, n);
    DFS();
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

void DFS(){
    int ver;
    for (int i = 0; i < n; i++)// init to 0
        v[i] = 0;
    printf("Enter initial vertex:");
    scanf("%d", &ver);//read init vertex
    dfs(ver - 1);
    for (int i = 0; i < n; i++)//check if any vertex is unvisited
        if (v[i] == 0)
            dfs(i);
}

void dfs(int i){
    count = count + 1;
    v[i] = count;
    printf("Vertex %d is visited and its count is %d", i+1, count);
    for(int j = 0; j < n; j++)//check the adjacent vertices marked with 0 and call dfs
        if (v[j] == 0 && a[i][j] == 1)
            dfs(j);
}
