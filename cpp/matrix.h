#ifndef CPP_LIBRARY_H
#define CPP_LIBRARY_H

#ifdef __cplusplus
extern "C" {
#endif

    struct DenseMatrix {
        unsigned long rows;
        unsigned long cols;
        double* data;
    };


    DenseMatrix* create_dense_matrix(unsigned long rows, unsigned long cols);

    void set_dense_matrix_data(DenseMatrix* matrix, const double* src);

    DenseMatrix* multiply_dense_matrices(const DenseMatrix* matrix_a, const DenseMatrix* matrix_b);

    void print_dense_matrix(const DenseMatrix* matrix);

    void free_dense_matrix(DenseMatrix* matrix);

    double dense_matrix_get(const struct DenseMatrix* matrix, unsigned long row, unsigned long col);


#ifdef __cplusplus
}
#endif

#endif // CPP_LIBRARY_H
