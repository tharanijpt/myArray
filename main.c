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
    printf("\n");
}

void swap(int* x,int* y){
    int tmp = *x;
    *x = *y;
    *y = tmp;
}


int LinearSearch(struct Array *arr,int target){
    for(int i=0;i<arr->length;i++){
        if(arr->A[i]==target){
            //transposition
            if(i>0)
                swap(&arr->A[i],&arr->A[i-1]);
            return i-1;
        }
        return i;
    }
    return -1;
}

void Insert(struct Array *arr,int index,int value){
    if(index>=0 && index <= arr->length && arr->length < arr->size){
        for(int i=arr->length;i>index;i--){
            arr->A[i] = arr->A[i-1];
        }
        arr->A[index] = value;
        arr->length++;
    }
}

void Add(struct Array *arr,int value){
    if(arr->length < arr-> size){
        arr->A[arr->length] = value;
        arr->length++;
    }
}

void Pop(struct Array *arr){
    if(arr->length != 0)
        arr->length--;
}

int Delete(struct Array *arr,int index){
    int value = 0;
    if(index >= 0 && index < arr->length){
    value = arr->A[index];
        for(int i=index;i<arr->length-1;i++){
            arr->A[i] = arr->A[i+1];
        }
        arr->length--;
        return value;
    }
    return -1;
}

int main(){
    struct Array arr;
    int arr_size = 0;
    int ele_need = 0;
    printf("Enter the size of the array:");
    scanf("%d",&arr_size);
    printf("Enter the total elements:");
    scanf("%d",&ele_need);
    if(ele_need>arr_size){
        printf("Number of elements can't exceed array size");
        return -1;
    }

    arr.A = (int *)malloc(arr_size * sizeof(int));
    arr.size = arr_size;

    for(int i=0;i<ele_need;i++){
        printf("Enter A[%d]=",i);
        scanf("%d",&arr.A[i]);
    }

    arr.length = ele_need;
    Display(arr);
    printf("enter to insert :");
    int index,value;
    scanf("%d %d",&index,&value);
    Insert(&arr,index,value);
    Display(arr);
    free(arr.A);
    return 0;
}