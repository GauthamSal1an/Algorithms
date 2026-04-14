// Online C compiler to run C program online
#include <stdio.h>
#define MAX 20

void input(int [], int);
void display(int [], int);
void mergesort(int[], int, int);
void merge(int[], int, int, int);

int main() {
    // Write C code here
    int a[MAX], n;
    printf("Enter number or characters:");
    scanf("%d", &n);
    printf("Enter array elements:");
    input(a, n);
    printf("Displaying array elements: ");
    display(a, n);
    mergesort(a, 0, n-1);
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

void mergesort(int a[], int low, int high){
    int mid;
    if (low != high){// keep divding array to sub array until low == high
        mid = (low + high)/2;
        mergesort(a, low, mid);
        mergesort(a, mid+1, high);
        merge(a, low, mid, high); // merge the 2 subarrays
    }
}

void merge(int a[], int low, int mid, int high){
    int i, j, k, b[MAX];
    i = low; // first index of one half
    j = mid + 1; // first index of second half
    k = low; //first index of temp array
    while (i <= mid && j <= high){
        if (a[i] > a[j]){
            b[k] = a[j];
            j = j + 1;
        }else{
            b[k] = a[i];
            i = i + 1;
        }
        k = k + 1;
    }
    //remaining elements of first and second half appended
    while (i <= mid){
        b[k] = a[i];
        i = i + 1;
        k = k + 1;
    }
    while (j <= high){
        b[k] = a[j];
        j = j + 1;
        k = k + 1;
    }
    //add the sorted array to the main array
    for (i = low; i <= high; i++)
        a[i] = b[i];
}
