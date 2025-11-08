#include <exception>
#include <jni.h>
#include "matrix.h"

extern "C" {

    JNIEXPORT jlong JNICALL Java_DenseMatrix_createDenseMatrix(JNIEnv* env, jclass clazz, jint rows, jint cols) {
        try {
            DenseMatrix* matrix = create_dense_matrix((unsigned long)rows, (unsigned long)cols);
            return reinterpret_cast<jlong>(matrix);
        } catch (const std::exception& e) {
            jclass exClass = env->FindClass("java/lang/IllegalArgumentException");
            env->ThrowNew(exClass, e.what());

            return 0;
        }
    }

    JNIEXPORT void JNICALL Java_DenseMatrix_setDenseMatrixData(JNIEnv* env, jclass clazz, jlong ptr, jdoubleArray data) {
        try {
            DenseMatrix* matrix = reinterpret_cast<DenseMatrix*>(ptr);
            jdouble* elems = env->GetDoubleArrayElements(data, nullptr);
            set_dense_matrix_data(matrix, elems);
            env->ReleaseDoubleArrayElements(data, elems, 0);
        } catch (const std::exception& e) {
            jclass exClass = env->FindClass("java/lang/IllegalArgumentException");
            env->ThrowNew(exClass, e.what());
        }
    }

    JNIEXPORT jlong JNICALL Java_DenseMatrix_multiplyDenseMatrices(JNIEnv* env, jclass clazz, jlong ptrA, jlong ptrB) {
        try {
            DenseMatrix* a = reinterpret_cast<DenseMatrix*>(ptrA);
            DenseMatrix* b = reinterpret_cast<DenseMatrix*>(ptrB);
            DenseMatrix* c = multiply_dense_matrices(a, b);

            if (!c) {
                jclass exClass = env->FindClass("java/lang/IllegalArgumentException");
                env->ThrowNew(exClass, "Numbers of columns and rows are not equal!");
            }

            return reinterpret_cast<jlong>(c);
        } catch (const std::exception& e) {
            jclass exClass = env->FindClass("java/lang/IllegalArgumentException");
            env->ThrowNew(exClass, e.what());

            return 0;
        }
    }

    JNIEXPORT void JNICALL Java_DenseMatrix_printDenseMatrix(JNIEnv* env, jclass clazz, jlong ptr) {
        DenseMatrix* matrix = reinterpret_cast<DenseMatrix*>(ptr);
        print_dense_matrix(matrix);
    }

    JNIEXPORT void JNICALL Java_DenseMatrix_freeDenseMatrix(JNIEnv* env, jclass clazz, jlong ptr) {
        try {
            DenseMatrix* matrix = reinterpret_cast<DenseMatrix*>(ptr);
            free_dense_matrix(matrix);
        } catch (const std::exception& e) {
            jclass exClass = env->FindClass("java/lang/IllegalArgumentException");
            env->ThrowNew(exClass, e.what());
        }
    }


    JNIEXPORT jdouble JNICALL Java_DenseMatrix_denseMatrixGet(JNIEnv* env, jclass clazz, jlong ptr, jint row, jint col) {
        try {
            DenseMatrix* matrix = reinterpret_cast<DenseMatrix*>(ptr);
            return dense_matrix_get(matrix, row, col);
        } catch (const std::exception& e) {
            jclass exClass = env->FindClass("java/lang/IllegalArgumentException");
            env->ThrowNew(exClass, e.what());

            return 0;
        }
    }
}
