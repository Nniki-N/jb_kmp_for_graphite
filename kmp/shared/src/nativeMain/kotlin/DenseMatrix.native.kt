import kotlinx.cinterop.*
import matrix.*

@OptIn(ExperimentalForeignApi::class)
actual class DenseMatrix actual constructor(actual val rows: Int, actual val cols: Int) {
    private var ptr: CPointer<cnames.structs.DenseMatrix>? = create_dense_matrix_c(rows.convert(), cols.convert())

    private constructor(ptr: CPointer<cnames.structs.DenseMatrix>, rows: Int, cols: Int) : this(rows, cols) {
        this.ptr = ptr
    }

    actual fun setData(data: DoubleArray) {
        data.usePinned { pinned ->
            set_dense_matrix_data_c(ptr, pinned.addressOf(0))
        }
    }

    actual fun multiply(other: DenseMatrix): DenseMatrix {
        val resultPtr = multiply_dense_matrices_c(ptr, other.ptr)
        return DenseMatrix(resultPtr!!, this.rows, other.cols)
    }

    actual fun print() {
        print_dense_matrix_c(ptr)
    }

    actual fun close() {
        free_dense_matrix_c(ptr)
        ptr = null
    }

    actual fun get(row: Int, col: Int): Double {
        return dense_matrix_get_c(ptr, row.convert(), col.convert())
    }
}
