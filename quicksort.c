// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>
#define MAX 128

void quicksort(int [], int, int);
int partition(int [], int, int);
void swap(int [], int, int);

int main(){
    int arr[MAX], n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter array elements: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    printf("Displaying array elements: ");
    for(int i = 0; i < n; i++){
        printf("%d", arr[i]);
    }
    quicksort(arr, 0, n-1);
    printf("Displaying sorted array elements: ");
    for(int i = 0; i < n; i++){
        printf("%d", arr[i]);
    }
}

void quicksort(int arr[MAX], int l, int r){
    int s;
    if (l < r){//set s to partition return and run quicksort on subarrays
        s = partition(arr, l, r);
        quicksort(arr, l, s-1);
        quicksort(arr, s+1, r);
    }
}

int partition(int arr[MAX], int l, int r){
    int p = l, i = l, j = r + 1;//set first element as pivot and l to first and r to rightmost
    while (i <= j){
        do{
            i = i + 1;
        }while(arr[i]<=arr[p] && i<=r);//move till right
        do{
            j = j-1;
        }while(arr[j]>arr[p]);//move till left
        if (i < j) { // CRITICAL: Only swap if pointers haven't crossed
            swap(arr, i, j);
        }
    }
    swap(arr, l, j);//swap l and j
    return j;
}

void swap(int a[MAX], int i, int j){
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}
