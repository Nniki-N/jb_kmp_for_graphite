#ifndef MATRIX_C_H
#define MATRIX_C_H

#ifdef __cplusplus
extern "C" {
#endif

    // Wraps create_dense_matrix and catches exceptions
    struct DenseMatrix* create_dense_matrix_c(unsigned long rows, unsigned long cols);

    // Wraps set_dense_matrix_data and catches exceptions
    void set_dense_matrix_data_c(struct DenseMatrix* matrix, const double* src);

    // Wraps multiply_dense_matrices and catches exceptions
    struct DenseMatrix* multiply_dense_matrices_c(const struct DenseMatrix* a, const struct DenseMatrix* b);

    // Wraps print_dense_matrix and catches exceptions
    void print_dense_matrix_c(const struct DenseMatrix* matrix);

    // Wraps free_dense_matrix and catches exceptions
    void free_dense_matrix_c(struct DenseMatrix* matrix);

    // Wraps dense_matrix_get and catches exceptions
    double dense_matrix_get_c(const struct DenseMatrix* matrix, unsigned long row, unsigned long col);


#ifdef __cplusplus
}
#endif

#endif // MATRIX_C_H
