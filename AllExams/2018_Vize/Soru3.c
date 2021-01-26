#include <stdio.h>
#include <stdlib.h>


int *rev(int A[], int i, int j){

    if(i>j){
        return A;
    }

    A = rev(A, i+1, j-1);

    int Temp = A[i];
    A[i] = A[j];
    A[j] = Temp;

    return A;

}

int main(){

    int A[] = {8,7,6,5,4,3,2,1};
    int size = sizeof(A)/sizeof(A[0]);
    int i = 0;
    int *B = rev(A, 0, size-1);

    for(i=0; i<size;i++){
        printf("%d ", B[i]);
    }
    

    return 0;
}
