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


    // Creates matrix of zeros, allocates memory
    DenseMatrix* create_dense_matrix(unsigned long rows, unsigned long cols);

    // Fills matrix wtih values
    void set_dense_matrix_data(DenseMatrix* matrix, const double* src);

    // Multiplies two matrices if passes dimension validation
    DenseMatrix* multiply_dense_matrices(const DenseMatrix* matrix_a, const DenseMatrix* matrix_b);

    // Prints the matrix in console (used just for tests)
    void print_dense_matrix(const DenseMatrix* matrix);

    // Frees the memory associated with a matrix
    void free_dense_matrix(DenseMatrix* matrix);

    // Returns the value at the given row and col indexes
    double dense_matrix_get(const struct DenseMatrix* matrix, unsigned long row, unsigned long col);


#ifdef __cplusplus
}
#endif

#endif // CPP_LIBRARY_H
