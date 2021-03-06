#include"matrixUtils.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int SIZE = 3;

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
            A[i][j] = (double) (rand()/(double)RAND_MAX)*20.0-1.0;
            printf("\t%lf ", A[i][j]);
        }
        printf("\n");
    }


    printf("\n\nB=\n");
    for(int i=0; i<SIZE; i++){
        B[i] = malloc(SIZE * sizeof(double));
        for(int j=0; j<SIZE; j++){
            B[i][j] = (double) (rand()/(double)RAND_MAX)*20.0-1.0;
            printf("\t%lf ", B[i][j]);
        }
        printf("\n");
    }

    C = multMatrizes(A, B, sizeA, sizeB);

    printf("\n\nC=\n");
    printMatrix(C, sizeC);


    printf("\nSUCESSO!\n\n");
    return 0;
}
