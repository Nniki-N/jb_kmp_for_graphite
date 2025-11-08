
fun main() {
    val a = DenseMatrix(2, 3)
    val b = DenseMatrix(3, 2)

    a.setData(doubleArrayOf(100.0, 2.0, 3.0, 4.0, 5.0, 6.0))
    b.setData(doubleArrayOf(7.0, 8.0, 9.0, 10.0, 11.0, 12.0))

    val c = a.multiply(b)
    println("A * B =")
    c.print()

    a.close()
    b.close()
    c.close()
}
