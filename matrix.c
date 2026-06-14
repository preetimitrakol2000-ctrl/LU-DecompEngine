#include <stdlib.h>
#include "matrix.h"

FlatMatrix create_matrix_space(int n) {
    FlatMatrix m;
    m.n = n;
    m.data = (double*)calloc(n * n, sizeof(double));
    return m;
}

void execute_lu_factorization(FlatMatrix* A, FlatMatrix* L, FlatMatrix* U) {
    int n = A->n;

    for (int i = 0; i < n; i++) {
        // Upper Matrix calculations
        for (int k = i; k < n; k++) {
            double sum = 0.0;
            for (int j = 0; j < i; j++) {
                sum += L->data[i * n + j] * U->data[j * n + k];
            }
            U->data[i * n + k] = A->data[i * n + k] - sum;
        }

        // Lower Matrix calculations
        for (int k = i; k < n; k++) {
            if (i == k) {
                L->data[i * n + i] = 1.0; // Diagonal identity setup
            } else {
                double sum = 0.0;
                for (int j = 0; j < i; j++) {
                    sum += L->data[k * n + j] * U->data[j * n + i];
                }
                L->data[k * n + i] = (A->data[k * n + i] - sum) / U->data[i * n + i];
            }
        }
    }
}

void free_matrix_space(FlatMatrix* m) {
    free(m->data);
}
