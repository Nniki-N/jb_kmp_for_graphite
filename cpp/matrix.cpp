#include "matrix.h"

#include <cstring>
#include <cstdio>
#include <stdexcept>

DenseMatrix *create_dense_matrix(const unsigned long rows, const unsigned long cols) {
    if (rows == 0 || cols == 0) {
        throw std::runtime_error("Matrix dimensions must be greater than 0");
    }

    const auto matrix = static_cast<DenseMatrix *>(malloc(sizeof(DenseMatrix)));

    if (!matrix) throw std::runtime_error("Error happened while allocating memory for DenseMatrix");

    matrix->rows = rows;
    matrix->cols = cols;

    matrix->data = static_cast<double *>(calloc(rows * cols, sizeof(double)));

    if (!matrix->data) {
        free(matrix);
        throw std::runtime_error("Error happened while allocating memory for matrix data");
    }

    return matrix;
}


void set_dense_matrix_data(DenseMatrix *matrix, const double *src) {
    if (!matrix || !matrix->data || !src) {
        throw std::runtime_error("Invalid matrix or source");
    }

    memcpy(matrix->data, src, matrix->rows * matrix->cols * sizeof(double));
}

DenseMatrix *multiply_dense_matrices(const DenseMatrix *matrix_a, const DenseMatrix *matrix_b) {
    if (!matrix_a || !matrix_b || !matrix_a->data || !matrix_b->data) {
        throw std::runtime_error("Invalid matrix or data");
    }

    if (matrix_a->cols != matrix_b->rows) {
        throw std::runtime_error("Numbers of columns and rows are not equal");
    }

    DenseMatrix *C = create_dense_matrix(matrix_a->rows, matrix_b->cols);

    for (unsigned long i = 0; i < matrix_a->rows; i++) {
        for (unsigned long j = 0; j < matrix_b->cols; j++) {
            double sum = 0;

            for (unsigned long k = 0; k < matrix_a->cols; k++) {
                sum += matrix_a->data[i * matrix_a->cols + k] * matrix_b->data[k * matrix_b->cols + j];
            }

            C->data[i * matrix_b->cols + j] = sum;
        }
    }

    return C;
}

void print_dense_matrix(const DenseMatrix *matrix) {
    for (unsigned long i = 0; i < matrix->rows; i++) {
        for (unsigned long j = 0; j < matrix->cols; j++) {
            printf("%8.2f ", matrix->data[i * matrix->cols + j]);
        }

        printf("\n");
    }

    printf("\n");
}

void free_dense_matrix(DenseMatrix *matrix) {
    if (!matrix) {
        throw std::runtime_error("Invalid matrix");
    }

    free(matrix->data);
    free(matrix);
}

double dense_matrix_get(const DenseMatrix* matrix, unsigned long row, unsigned long col) {
    if (!matrix || !matrix->data) {
        throw std::runtime_error("Invalid matrix or data");
    }

    if (row >= matrix->rows || col >= matrix->cols) {
        throw std::runtime_error("Index out of bounds");
    }

    return matrix->data[row * matrix->cols + col];
}
