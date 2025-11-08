
expect class DenseMatrix(rows: Int, cols: Int) {
    val rows: Int
    val cols: Int

    fun setData(data: DoubleArray)
    fun multiply(other: DenseMatrix): DenseMatrix
    fun print()
    fun close()
    fun get(row: Int, col: Int): Double
}
