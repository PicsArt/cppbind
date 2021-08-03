package com.examples.misc

import com.examples.misc.*
import java.awt.geom.Point2D

class MiscApp {

    companion object {
        @JvmStatic
        fun main(args: Array<String>) {

            // [external-yaml-usage]
            assert(WithExternalAPIComments.retInt(1) == 1)
            assert(WithExternalAPIComments("ab").str == "ab")
            assert(WithExternalAPIComments.max(2, 3) == 3)
            assert(WithExternalAPIComments.max("2", "3") == "3")
            assert(AdderInt.add(1, 2) == 3)
            assert(AdderDouble.add(1.5, 2.5) == 4.0)
            assert(color.RED.ordinal == 0)
            // [external-yaml-usage]

            // [size-usage]
            val sizeInfo = Point2D.Float(10.0F, 20.0F)
            val resultSizeInfo = SizeUsage.multiplyBy(sizeInfo, 5)
            assert(resultSizeInfo.x == 5 * sizeInfo.x && resultSizeInfo.y == 5 * sizeInfo.y)
            // [size-usage]

            // [buffer-usage]
            val bufferUsage = BufferUsage()
            val buffer = BufferInt(100)
            assert(bufferUsage.usage1(buffer) == "buffer print")
            print(bufferUsage.usage2().getObjId())
            // [buffer-usage]

       }
    }

}
