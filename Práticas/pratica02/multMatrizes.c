#include"matrixUtils.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 3



int main(){
    double **A = malloc(SIZE * SIZE * sizeof(double));
    double **B = malloc(SIZE * SIZE * sizeof(double));
    double **C = malloc(SIZE * SIZE * sizeof(double));
    int sizeA[] = {SIZE, SIZE};
    int sizeB[] = {SIZE, SIZE};
    int sizeC[] = {SIZE, SIZE};

    srand((unsigned)time(NULL));

    printf("\n\nA=\n");
    for(int i=0; i<SIZE; i++){
        A[i] = malloc(SIZE * sizeof(double));
        for(int j=0; j<SIZE; j++){
            A[i][j] = (double)rand()/RAND_MAX*20.0-1.0;
            printf("%lf ", A[i][j]);
        }
        printf("\n");
    }


    printf("\n\nB=\n");
    for(int i=0; i<SIZE; i++){
        B[i] = malloc(SIZE * sizeof(double));
        for(int j=0; j<SIZE; j++){
            B[i][j] = (double)rand()/RAND_MAX*20.0-1.0;
            printf("%lf ", B[i][j]);
        }
        printf("\n");
    }

    C = multMatrizes(A, B, sizeA, sizeB);

    printf("\n\nC=\n");
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            printf("%lf ", C[i][j]);
        }
        printf("\n");
    }


    printf("\nSUCESSO!\n\n");
    return 0;
}
