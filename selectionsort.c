// Online C compiler to run C program online
#include <stdio.h>
#define MAX 20

void input(int [], int);
void display(int [], int);
void selectionsort(int [], int);
void swap(int [], int, int);

int main() {
    // Write C code here
    int a[MAX], n;
    printf("Enter number of integers:");
    scanf("%d", &n);
    printf("Enter array elements:");
    input(a, n);
    printf("Displaying array elements:\n");
    display(a, n);
    selectionsort(a, n);
    printf("Displaying sorted array elements:\n");
    display(a, n);
    return 0;
}

void input(int a[], int n){
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

void display(int a[], int n){
    for (int i = 0; i < n; i++){
        printf("%d\t", a[i]);
    }
    printf("\n");
}

void selectionsort(int a[], int n){
    for (int i = 0; i < n-1; i++){ //outer loop to iterate till last one element
        int min = i;
        for (int j = i + 1; j < n; j++){
            //inner loop to iterate from last sorted element to the end
            if (a[j] < a[min])
                min = j; 
        }
        swap(a, i, min);
    }
}

void swap(int a[], int j, int k){
    int temp;
    temp = a[j];
    a[j] = a[k];
    a[k] = temp;
}
