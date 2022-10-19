/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 10/18/2022-09:00.
 * Please do not change it manually.
 */

package com.examples.inheritance

import com.examples.cppbind.*
import com.examples.cppbind.exceptions.*

open class Bicycle
internal constructor(obj: CppBindObject) : Vehicle(obj) {
    companion object {
        
        protected fun constructHelper(numberOfSeats: Int): Long {
            val id = jConstructor(numberOfSeats)
            return id
        }

        @JvmStatic
        private external fun jConstructor(numberOfSeats: Int, vararg extraObjs: Any?): Long
        /**
         * An internal property to keep an information about the underlying C++ object type.
         * It is intended to be used by the generated code.
         */
        const val cppbindCxxTypeName: String = "cppbind::example::Bicycle"

        /**
         * An internal method to create a Kotlin object from a C++ object.
         * It is intended to be used by the generated code.
         */
        public fun cppbindConstructObject(id: Long, owner: Boolean = false): Bicycle {
            val idType = jGettypebyid(id)
            val obj : Bicycle
            when (idType) {
                ElectricBicycle.cppbindCxxTypeName -> obj = ElectricBicycle(CppBindObject(id, owner))
                else -> obj = Bicycle(CppBindObject(id, owner))
            }
            return obj
        }
    }
    
    
    constructor(numberOfSeats: Int): this(CppBindObject(constructHelper(numberOfSeats), true)) {
    }
    
    open override fun type(): String {
        val result = jType(cppbindObjId)
        
        return result
    }

    ///// External wrapper functions ////////////
    private external fun jType(id: Long): String
}

open class ElectricBicycle
internal constructor(obj: CppBindObject) : Bicycle(obj) {
    companion object {
        
        protected fun constructHelper(numberOfSeats: Int): Long {
            val id = jConstructor(numberOfSeats)
            return id
        }

        @JvmStatic
        private external fun jConstructor(numberOfSeats: Int, vararg extraObjs: Any?): Long
        /**
         * An internal property to keep an information about the underlying C++ object type.
         * It is intended to be used by the generated code.
         */
        const val cppbindCxxTypeName: String = "cppbind::example::ElectricBicycle"
    }
    
    
    constructor(numberOfSeats: Int): this(CppBindObject(constructHelper(numberOfSeats), true)) {
    }
    
    override fun type(): String {
        val result = jType(cppbindObjId)
        
        return result
    }

    ///// External wrapper functions ////////////
    private external fun jType(id: Long): String
}

private external fun jGettypebyid(id: Long): String
