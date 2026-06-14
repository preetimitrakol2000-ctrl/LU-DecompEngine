#ifndef MATRIX_H
#define MATRIX_H

typedef struct {
    int n; // Matrix dimension (n x n)
    double* data;
} FlatMatrix;

FlatMatrix create_matrix_space(int n);
void execute_lu_factorization(FlatMatrix* A, FlatMatrix* L, FlatMatrix* U);
void free_matrix_space(FlatMatrix* m);

#endif
