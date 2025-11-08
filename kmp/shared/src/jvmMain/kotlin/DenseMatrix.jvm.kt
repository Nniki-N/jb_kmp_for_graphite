
actual class DenseMatrix actual constructor(actual val rows: Int, actual val cols: Int) {
    init {
        System.loadLibrary("matrix")
    }

    private external fun createDenseMatrix(rows: Int, cols: Int): Long
    private external fun setDenseMatrixData(matrixPtr: Long, data: DoubleArray)
    private external fun multiplyDenseMatrices(matrixA: Long, matrixB: Long): Long
    private external fun printDenseMatrix(matrixPtr: Long)
    private external fun freeDenseMatrix(matrixPtr: Long)
    private external fun denseMatrixGet(matrixPtr: Long, rows: Int, cols: Int): Double

    private var ptr: Long = createDenseMatrix(rows, cols)

    private constructor(ptr: Long, rows: Int, cols: Int) : this(rows,cols) {
        this.ptr = ptr
    }

    actual fun setData(data: DoubleArray) {
        setDenseMatrixData(ptr, data)
    }

    actual fun multiply(other: DenseMatrix): DenseMatrix {
        val resultPtr = multiplyDenseMatrices(ptr, other.ptr)

        return DenseMatrix(resultPtr, this.rows, other.cols)
    }

    actual fun print() {
        printDenseMatrix(ptr)
    }

    actual fun close() {
        freeDenseMatrix(ptr)
    }

    actual fun get(row: Int, col: Int): Double {
        return denseMatrixGet(ptr, row, col)
    }
}
