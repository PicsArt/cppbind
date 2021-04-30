package com.examples.inheritance

import com.examples.inheritance.*
import com.examples.classes.Task
import com.examples.classes.Root

class InheritanceApp {

    companion object {
        @JvmStatic
        fun main(args: Array<String>) {

            val rectangle = Rectangle(4.0, 2.0)
            assert(rectangle.area == 8.0)
            assert(rectangle.length == 4.0)
            assert(rectangle.perimeter() == 12.0)

            val rhombus = Rhombus(5.0, 6.0)
            assert(rhombus.area == 15.0)

            val square = Square(5.0)
            assert(square.area == 25.0)
            assert(square.length == 5.0)
            assert(square.perimeter() == 20.0)

        }

    }
}
