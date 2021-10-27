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

            val car1 = Car(10000)
            cheapCar.setCostWithCar(car1)
            assert(cheapCar.cost == car1.cost)

            val car2 = Car(20000)
            cheapCar.setCostWithCarRef(car2)
            assert(cheapCar.cost == car2.cost)

            val car3 = Car(30000)
            cheapCar.setCostWithCarPtr(car3)
            assert(cheapCar.cost == car3.cost)
            // [shared_ptr-usage]

       }
    }

}
