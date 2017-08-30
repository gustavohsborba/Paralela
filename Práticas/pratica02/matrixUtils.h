#include<stdlib.h>

/******************************************************************************
    STRUCT MATRIX DEFINITION AND INSTANTIATION FUNCTIONS
 ******************************************************************************/
struct matrix2D{
    int nRows;
    int nCols;
    double **M;
};

struct matrix2D zeros(int nRows, int nCols){
    struct matrix2D mat = (struct matrix2D) {nRows,nCols,malloc(nRows*nCols*sizeof(double))};

    for(int i=0; i<nRows; i++){
        mat.M[i] = malloc(nCols * sizeof(double));
        for(int j=0; j<nCols; j++){
            mat.M[i][j] = 0;
        }
    }
    return mat;
}

struct matrix2D ones(int nRows, int nCols){
    struct matrix2D mat = (struct matrix2D) {nRows,nCols,malloc(nRows*nCols*sizeof(double))};

    for(int i=0; i<nRows; i++){
        mat.M[i] = malloc(nCols * sizeof(double));
        for(int j=0; j<nCols; j++){
            mat.M[i][j] = 1;
        }
    }
    return mat;
}

struct matrix2D urand(int nRows, int nCols, double factor, int neg){
    struct matrix2D mat = (struct matrix2D) {nRows,nCols,malloc(nRows*nCols*sizeof(double))};

    for(int i=0; i<nRows; i++){
        mat.M[i] = malloc(nCols * sizeof(double));
        for(int j=0; j<nCols; j++){
            mat.M[i][j] = (double)rand()/RAND_MAX*factor - neg;
        }
    }
    return mat;
}


/******************************************************************************
    MATRIX OPERATIONS WITH THOIS SCTRUCTURE
 ******************************************************************************/



double **multMatrizes(double **A, double **B, int *sizeA, int *sizeB){
    double r1 = sizeA[0];
    double r2 = sizeB[0];
    double c1 = sizeA[1];
    double c2 = sizeB[1];

    //if(c1 != r2) // cols A != rows B

    double **result = malloc(r1 * c2 * sizeof(double));
    double r;

    // iniciate with zeros // bzero
    for(int i=0; i<r1; ++i){
        result[i] = malloc(c2*sizeof(double));
        for(int j=0; j<c2; ++j)
            result[i][j] = 0;
    }

    for(int i=0; i<r1; ++i){
        for(int k=0; k<c1; ++k){
            r = A[i][k];
            for(int j=0; j<c2; ++j){
                result[i][j]+= r*B[k][j];
            }
        }
    }
    return result;
}
