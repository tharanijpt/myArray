#include<stdio.h>
#include<stdlib.h>

struct Array{
    int *A;
    int size;
    int length;
};

void Display(struct Array arr){
    int n = arr.length;
    for (int i=0;i<n;i++){
        printf("%d ",arr.A[i]);
    }
}

int main(){
    struct Array arr;
    int arr_size = 0;
    int ele_need = 0;
    printf("Enter the size of the array:");
    scanf("%d",&arr_size);
    printf("Enter the total elements:");
    scanf("%d",&ele_need);

    arr.A = (int *)malloc(arr_size * sizeof(int));

    for(int i=0;i<ele_need;i++){
        printf("Enter A[%d]=",i);
        scanf("%d",&arr.A[i]);
    }

    arr.length = ele_need;
    Display(arr);
    return 0;
}