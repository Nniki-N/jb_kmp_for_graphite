#ifndef MATRIX_C_H
#define MATRIX_C_H

#ifdef __cplusplus
extern "C" {
#endif

    struct DenseMatrix* create_dense_matrix_c(unsigned long rows, unsigned long cols);

    void set_dense_matrix_data_c(struct DenseMatrix* matrix, const double* src);

    struct DenseMatrix* multiply_dense_matrices_c(const struct DenseMatrix* a, const struct DenseMatrix* b);

    void print_dense_matrix_c(const struct DenseMatrix* matrix);

    void free_dense_matrix_c(struct DenseMatrix* matrix);

    double dense_matrix_get_c(const struct DenseMatrix* matrix, unsigned long row, unsigned long col);


#ifdef __cplusplus
}
#endif

#endif // MATRIX_C_H
