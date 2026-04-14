// Online C compiler to run C program online
#include <stdio.h>
#define MAX 20


int arr[MAX], front=0, rear=0;
int a[MAX][MAX], n, v[MAX], count = 0;
void input(int [MAX][MAX], int);
void display(int [MAX][MAX], int);
void BFS();
void bfs(int);

int main(){
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix: ");
    input(a, n);
    printf("Displaying adjacency matrix: ");
    display(a, n);
    BFS();
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

void BFS(){
    int ver;
    for (int i = 0; i < n; i++)// init to 0
        v[i] = 0;
    printf("Enter initial vertex:");
    scanf("%d", &ver);//read init vertex
    bfs(ver - 1);
    for (int i = 0; i < n; i++)//check if any vertex is unvisited
        if (v[i] == 0)
            bfs(i);
}

void bfs(int i){
    count = count + 1;
    v[i] = count;
    printf("Vertex %d is visited and its count is %d", i+1, count);
    arr[rear] = i;// add visited to element to queue and inc rear
    rear = rear + 1;
    while (rear != front){ // when rear and front not equal
        int q = arr[front]; //remove first element and incremenet
        front = front + 1;
        for(int j = 0; j < n; j++){
            if (a[q][j] == 1 && v[j] == 0){//mark all children of removed element with count and add to queue
                count = count + 1;
                v[j] = count;
                printf("Vertex %d is visited and its count is %d", j+1, count);
                arr[rear] = j;
                rear = rear + 1;
            }
        }
    }
}
