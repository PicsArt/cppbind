package com.examples.shared_ptr

import com.examples.shared_ptr.*

class SharedPtrApp {

    companion object {
        @JvmStatic
        fun main(args: Array<String>) {

            // [shared_ptr-usage]
            val cheapCar = Car(1000)
            val expensiveCar = Car(10000)
            val newCar = cheapCar.getNewCarSharedPtr()
            assert(newCar.cost == cheapCar.cost)

            cheapCar.setCostWithCarSharedPtr(expensiveCar)
            assert(cheapCar.cost == expensiveCar.cost)
            // [shared_ptr-usage]

       }
    }

}
