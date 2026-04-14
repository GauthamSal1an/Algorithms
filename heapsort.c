// Online C compiler to run C program online
#include <stdio.h>
#define MAX 20

void input(int [], int);
void display(int [], int);
void heapsort(int [], int);
void heapify(int [], int);
void swap(int, int);

int arr[MAX], n;

int main(){
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter array elements: ");
    input(arr, n);
    printf("Displaying array elements: ");
    display(arr, n);
    heapsort(arr, n);
    printf("Displaying sorted array elements: ");
    display(arr, n);
}

void input(int arr[], int n){
    for(int i = 1; i <=  n; i++)
        scanf("%d", &arr[i]);
}

void display(int arr[], int n){
    for(int i = 1; i <= n; i++){
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

void heapsort(int arr[], int n){
    heapify(arr, n);//initial heapification
    for (int k = n; k >= 1; k--){
        swap(1, k);//swap
        heapify(arr, k-1);//heapify again
    }
}

void heapify(int arr[], int n){
    for (int i = n/2; i > 0; i--){
        int k = i;//store array element and value
        int v = arr[k];
        while (2*k <= n){//until index is inside range
            int j = 2*k;
            if (j < n){//check if 2 children
                if (arr[j] < arr[j+1]){
                    j = j + 1;
                }
            }
            if (v >= arr[j]){
                break;
            }else{
                arr[k] = arr[j];
                k=j;
            }
        }
        arr[k] = v;
    }
}

void swap(int a, int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}
