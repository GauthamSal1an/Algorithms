// Online C compiler to run C program online
#include <stdio.h>
#define MAX 20

void input(int [], int);
void display(int [], int);
int linearsearch(int [], int, int);

int main() {
    // Write C code here
    int a[MAX], n, i, k;
    printf("Enter number of integers:");
    scanf("%d", &n);
    printf("Enter array elements:");
    input(a, n);
    printf("Enter key element:");
    scanf("%d", &k);
    printf("Displaying array elements:\n");
    display(a, n);
    i = linearsearch(a, n, k);
    if (i == -1)
        printf("Key element not present in the list.");
    else
        printf("Key element is present in the %d position", i+1);
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

int linearsearch(int a[], int n, int k){
    for (int i = 0; i < n; i++){
        if (a[i] == k)
            return i;
    }
    return -1;
}
