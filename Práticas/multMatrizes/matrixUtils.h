#include<stdlib.h>
#include<stdio.h>



void printMatrix(double **M, int *sizeM){
    for(int i=0; i<sizeM[0]; i++){
        for(int j=0; j<sizeM[1]; j++){
            printf("\t%lf ", M[i][j]);
        }
        printf("\n");
    }
}

double **multMatrizes(double **A, double **B, int *sizeA, int *sizeB){
    double r1 = sizeA[0];
    double r2 = sizeB[0];
    double c1 = sizeA[1];
    double c2 = sizeB[1];

    //if(c1 != r2) // cols A != rows B

    double **result = malloc(r1 * c2 * sizeof(int));
    double r;

    // iniciate with zeros // bzero
    for(int i=0; i<r1; ++i){
        result[i] = malloc(c2 * sizeof(int));
        for(int j=0; j<c2; ++j)
            result[i][j] = 0;
    }

    for(int i=0; i<r1; ++i){
        for(int k=0; k<c1; ++k){
            r = A[i][k];
            for(int j=0; j<c2; ++j){
                result[i][j]+=r*B[k][j];
            }
        }
    }
    return result;
}
