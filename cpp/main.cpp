#include <cstdio>

#include "matrix.h"

int main() {
    const double a_data[] = {1, 2, 3, 4, 5, 6};
    double const b_data[] = {7, 8, 9, 10, 11, 12};

    DenseMatrix* matrix_a = create_dense_matrix(2, 3);
    DenseMatrix* matrix_b = create_dense_matrix(3, 2);

    set_dense_matrix_data(matrix_a, a_data);
    set_dense_matrix_data(matrix_b, b_data);

    printf("Matrix A:\n");
    print_dense_matrix(matrix_a);

    printf("Matrix B:\n");
    print_dense_matrix(matrix_b);

    DenseMatrix* matrix_c = multiply_dense_matrices(matrix_a, matrix_b);

    if (matrix_c) {
        printf("A * B =\n");
        print_dense_matrix(matrix_c);
        free_dense_matrix(matrix_c);
    }


    free_dense_matrix(matrix_a);
    free_dense_matrix(matrix_b);
    return 0;
}
