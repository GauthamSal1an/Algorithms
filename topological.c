// Online C compiler to run C program online
#include <stdio.h>
#define MAX 20

int n;
struct queue{
    int rear;
    int front;
    int arr[MAX];
};

void qinsert(struct queue *q, int n){
    q->arr[++q->rear] = n;
}

int qdelete(struct queue *q){
    return q->arr[++q->front];
}


void topological(int mat[MAX][MAX]){
    struct queue q1;//init queue
    q1.front = q1.rear = -1;
    int vertices[MAX], indegree[MAX], T[MAX], k=0, v;
    for(int i = 0; i < n; i++){//set all indegree and visited as 0
        for (int j = 0; j < n; j++){
            indegree[i] = 0;
            vertices[i] = 0;
        }
    }
    for(int i = 0; i < n; i++){//count all indegrees
        for (int j = 0; j < n; j++){
            if (mat[j][i] == 1){
                indegree[i] = indegree[i] + 1;
            }
        }
    }
    for(int i = 0; i < n; i++){//insert all vertices with indegree 0
        if (indegree[i] == 0){
            qinsert(&q1, i);
        }
    }
    while (q1.rear != q1.front){//when q not empty pop first element
        v = qdelete(&q1);
        T[k++] = v;//add it to T and mark it as visited
        vertices[v] = 1;
        for(int i = 0; i < n; i++){//reduce the indegree of all adjacent vertices
            if (mat[v][i] == 1 && vertices[i] == 0){
                indegree[i] = indegree[i] - 1;
                if (indegree[i] == 0){//check for isolated vertex and add
                    qinsert(&q1, i);
                }
            }
        }
    }
    printf("Displaying vertices:");//display
    for(int i=0; i < n; i++){
        printf("%d\t", T[i]);
    }
}

int main(){
    int mat[MAX][MAX];
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &mat[i][j]);
    topological(mat);
}
