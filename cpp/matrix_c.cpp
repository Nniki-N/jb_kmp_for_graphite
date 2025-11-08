#include "matrix_c.h"

#include <limits>

#include "matrix.h"

struct DenseMatrix* create_dense_matrix_c(unsigned long rows, unsigned long cols) {
    try {
        return create_dense_matrix(rows, cols);
    } catch (...) {
        return nullptr;
    }
}

void set_dense_matrix_data_c(struct DenseMatrix* matrix, const double* src) {
    try {
        set_dense_matrix_data(matrix, src);
    } catch (...) {
        return;
    }
}

struct DenseMatrix* multiply_dense_matrices_c(const struct DenseMatrix* a, const struct DenseMatrix* b) {
    try {
        return multiply_dense_matrices(a, b);
    } catch (...) {
        return nullptr;
    }
}

void print_dense_matrix_c(const struct DenseMatrix* matrix) {
    try {
        print_dense_matrix(matrix);
    } catch (...) {
        return;
    }
}

void free_dense_matrix_c(struct DenseMatrix* matrix) {
    try {
        free_dense_matrix(matrix);
    } catch (...) {
        return;
    }
}

double dense_matrix_get_c(const DenseMatrix* matrix, unsigned long row, unsigned long col) {
    try {
        return dense_matrix_get(matrix, row, col);
    } catch (...) {
        return std::numeric_limits<double>::quiet_NaN();
    }
}
