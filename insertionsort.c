// Online C compiler to run C program online
#include <stdio.h>
#define MAX 20

void input(int [], int);
void display(int [], int);
void insertionsort(int[], int);

int main() {
    // Write C code here
    int a[MAX], n;
    printf("Enter number or characters:");
    scanf("%d", &n);
    printf("Enter array elements:");
    input(a, n);
    printf("Displaying array elements: ");
    display(a, n);
    insertionsort(a, n);
    printf("Displaying sorted array elements: ");
    display(a, n);
}

void input(int a[], int n){
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

void display(int a[], int n){
    for (int i = 0; i < n; i++)
        printf("%d\t", a[i]);
    printf("\n");
}

void insertionsort(int a[], int n){
    int j, v;
    for (int i = 1; i < n; i++){
        v = a[i]; // store ith element for later
        j = i - 1; //start while loop from one lower than current
        while (j>=0 && a[j] >= v){
            a[j+1] = a[j];// continuosly swap element and decrement
            j = j - 1;
        }
        a[j+1] = v; //add the v element to the correct position 
    }
}
