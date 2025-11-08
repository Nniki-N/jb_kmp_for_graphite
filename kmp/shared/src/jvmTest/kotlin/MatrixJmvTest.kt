import kotlin.test.Test

import kotlin.test.assertEquals
import kotlin.test.assertFails

class MatrixJvmTest {

    @Test
    fun testMultiplicationWithCorrectRowsAndColumns() {
        val a = DenseMatrix(2, 3)
        a.setData(doubleArrayOf(1.0, 2.0, 3.0, 4.0, 5.0, 6.0))

        val b = DenseMatrix(3, 2)
        b.setData(doubleArrayOf(7.0, 8.0, 9.0, 10.0, 11.0, 12.0))

        val c = a.multiply(b)

        assertEquals(2, c.rows)
        assertEquals(2, c.cols)

        a.close()
        b.close()
        c.close()
    }

    @Test
    fun testMultiplicationWithMismatchedRowsAndColumns() {
        val a = DenseMatrix(2, 1)
        val b = DenseMatrix(4, 2)

        a.setData(doubleArrayOf(1.0, 2.0))
        b.setData(doubleArrayOf(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0))

        assertFails {
            val c = a.multiply(b)
            c.close()
        }

        a.close()
        b.close()
    }

    @Test
    fun testValueAtIndex() {
        val a = DenseMatrix(2, 3)
        a.setData(doubleArrayOf(1.0, 2.0, 3.0, 4.0, 5.0, 6.0))

        val b = DenseMatrix(3, 2)
        b.setData(doubleArrayOf(7.0, 8.0, 9.0, 10.0, 11.0, 12.0))

        val c = a.multiply(b)

        assertEquals(58.0, c.get(0,0))
        assertEquals(64.0, c.get(0,1))
        assertEquals(139.0, c.get(1,0))
        assertEquals(154.0, c.get(1,1))

        a.close()
        b.close()
        c.close()
    }

    @Test
    fun testValueAtWrongIndex() {
        val a = DenseMatrix(2, 3)
        a.setData(doubleArrayOf(1.0, 2.0, 3.0, 4.0, 5.0, 6.0))

        assertFails {
            a.get(100,100)
        }

        a.close()
    }
}
