// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>
#define MAX 20

void input(int [], int);
void display(int [], int);
int binsearch(int[], int, int);

int main(){
    int a[MAX], n, i, k;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter array elements: ");
    input(a, n);
    printf("Enter key element: ");
    scanf("%d", &k);
    printf("Displaying array elements: ");
    display(a, n);
    i = binsearch(a, n, k);
    if (i == -1){
        printf("Key element is not present in the list.");
    }else{
        printf("Key element is present in %d position.", i+1);
    }
}

void input(int a[], int n){
    for(int i=0; i < n; i++)
        scanf("%d", &a[i]);
}

void display(int a[], int n){
    for(int i=0; i < n; i++)
        printf("%d\t", a[i]);
    printf("\n");
}

int binsearch(int a[], int n, int k){
    int low, high, mid;
    low = 0;
    high = n-1;
    while (low <= high){ // run the while loop till low becomes less than high
        mid = (low + high)/2;
        if (a[mid] == k){
            return mid;
        }else if (a[mid] > k){
            high = mid -1;
        }else{
            low = mid + 1;
        }
    }
    return -1;
}
