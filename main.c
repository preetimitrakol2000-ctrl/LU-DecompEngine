#include <stdio.h>
#include "matrix.h"

int main() {
    printf("🧮 Activating LU-DecompEngine Row-Major Factoring Core...\n\n");

    int dim = 2;
    FlatMatrix A = create_matrix_space(dim);
    FlatMatrix L = create_matrix_space(dim);
    FlatMatrix U = create_matrix_space(dim);

    // Initializing linear equation weights flatly: [3.0, 2.0; 1.0, 4.0]
    A.data[0] = 3.0; A.data[1] = 2.0;
    A.data[2] = 1.0; A.data[3] = 4.0;

    execute_lu_factorization(&A, &L, &U);

    printf("✨ Matrix Decomposition Completed Successfully:\n");
    printf("   • L Matrix Diagonal Row Baseline: [%.2f, %.2f]\n", L.data[0], L.data[3]);
    printf("   • U Matrix Output Corners: [%.2f, %.2f]\n", U.data[0], U.data[3]);

    free_matrix_space(&A);
    free_matrix_space(&L);
    free_matrix_space(&U);
    return 0;
}
