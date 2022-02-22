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

            val carUsageObj = CarUsage(cheapCar)
            val returnedCar = carUsageObj.getCar()
            assert(returnedCar.cost == cheapCar.cost)

            // [shared_ptr-usage]

            // const shared_ptr tests
            cheapCar.setCostWithCarConstSharedPtr(newCar)
            assert(cheapCar.cost == newCar.cost)

            val constPtrCar = cheapCar.makeConstSharedPtr(newCar)
            assert(constPtrCar.cost == newCar.cost)

            // testing multiple inheritance without single root in case of shared_ref=True
            var symbolUsageObj = SymbolUsageShared()
            val digitObj = DigitShared()
            val textObj = TextShared()
            val signObj = SignSharedImpl()

            // test virtual methods
            assert(symbolUsageObj.getTextType(digitObj) == "digit")
            assert(symbolUsageObj.getTextType(textObj) == "text")
            assert(symbolUsageObj.getSignType(digitObj) == "digit")
            assert(symbolUsageObj.getSignType(signObj) == "sign")
            assert(digitObj.typeName() == "digit")
            assert(textObj.typeName() == "text")
            assert(signObj.typeName() == "sign")

            symbolUsageObj = SymbolUsageShared(digitObj)
            assert(symbolUsageObj.getTextPtr().typeName() == "digit")
            assert(symbolUsageObj.getSignPtr().typeName() == "digit")

            // test members
            assert(symbolUsageObj.getTextId(digitObj) == 2)
            assert(symbolUsageObj.getTextId(textObj) == 2)
            assert(symbolUsageObj.getSignId(digitObj) == 1)
            assert(symbolUsageObj.getSignId(signObj) == 1)

            // test return object correct casting
            assert(symbolUsageObj.getTextId(symbolUsageObj.getTextPtr()) == 2)
            assert(symbolUsageObj.getSignId(symbolUsageObj.getSignPtr()) == 1)

            // test finalize destructors
            textObj.close()
            signObj.close()
            digitObj.close()
            symbolUsageObj.close()

       }
    }

}
