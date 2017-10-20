#ifndef MATRIX_MULTIPLICATION_THREADS_DATASTRUCTURE_H
#define MATRIX_MULTIPLICATION_THREADS_DATASTRUCTURE_H

typedef struct Matrix{

    int** matrix;
    int rows;
    int cols;

} Matrix;


typedef struct parameters{
    Matrix* mat1;
    Matrix* mat2;
    int row;
    int col;

}parameters;

typedef struct Thread_info{

    parameters params;

    Matrix* res;

}Thread_info;


#endif //MATRIX_MULTIPLICATION_THREADS_DATASTRUCTURE_H
