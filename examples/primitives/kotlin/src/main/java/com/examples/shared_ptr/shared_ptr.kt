/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 02/24/2022-12:47.
 * Please do not change it manually.
 */

package com.examples.shared_ptr

import com.examples.iegen.alias.*
import com.examples.iegen.exceptionUtils.*
import com.examples.iegen.exception_helpers.*

open class Car
internal constructor(obj: IEGenObject) : AutoCloseable {
    companion object {
        init {
            System.loadLibrary("wrapper_jni")
        }
        
        protected fun construct_helper(cost: Int): Long {
            val id = jConstructor(cost)
            return id
        }

        @JvmStatic
        private external fun jConstructor(cost: Int): Long
    }
    
    protected var objId = obj.id
    protected val owner = obj.owner
    private var refs: MutableList<Any> = mutableListOf()

    fun keepIEGenReference(ref: Any) {
        refs.add(ref)
    }
    
    open val id: Long
        get() {
            if (objId == 0L) {
                throw RuntimeException("Object is not allocated")
            }
            return objId
        }
    
    constructor(cost: Int): this(IEGenObject(construct_helper(cost), true)) {
    }
    
    /**
     * value getter
     */
    val cost: Int
        get() {
            val result = jCost(id)
            
            return result
        }
    
    fun setCostWithCarSharedPtr(sp: Car): Unit {
        val kotlintojdksp = sp.id
        val result = jSetcostwithcarsharedptr(id, kotlintojdksp)
        
        return result
    }

    fun setCostWithCar(sp: Car): Unit {
        val kotlintojdksp = sp.id
        val result = jSetcostwithcar(id, kotlintojdksp)
        
        return result
    }

    /**
     * comments
     * 
     */
    fun setCostWithCarConstSharedPtr(sp: Car): Unit {
        val kotlintojdksp = sp.id
        val result = jSetcostwithcarconstsharedptr(id, kotlintojdksp)
        
        return result
    }

    /**
     * comments
     * 
     */
    fun makeConstSharedPtr(sp: Car): Car {
        val kotlintojdksp = sp.id
        val result = jMakeconstsharedptr(id, kotlintojdksp)
        val jdktokotlinresult = Car(IEGenObject(result, true))
        return jdktokotlinresult
    }

    fun setCostWithCarRef(sp: Car): Unit {
        val kotlintojdksp = sp.id
        val result = jSetcostwithcarref(id, kotlintojdksp)
        
        return result
    }

    fun setCostWithCarPtr(sp: Car): Unit {
        val kotlintojdksp = sp.id
        val result = jSetcostwithcarptr(id, kotlintojdksp)
        
        return result
    }

    fun getNewCarSharedPtr(): Car {
        val result = jGetnewcarsharedptr(id)
        val jdktokotlinresult = Car(IEGenObject(result, true))
        return jdktokotlinresult
    }

    override fun close() {
        if (owner && objId != 0L) {
            jFinalize(objId)
            objId = 0L
        }
    }

    /**
     * Finalize and deletes the object
     */
    protected fun finalize() {
        close()
    }

    ///// External wrapper functions ////////////
    private external fun jCost(id: Long): Int
    private external fun jSetcostwithcarsharedptr(id: Long, sp: Long): Unit
    private external fun jSetcostwithcar(id: Long, sp: Long): Unit
    private external fun jSetcostwithcarconstsharedptr(id: Long, sp: Long): Unit
    private external fun jMakeconstsharedptr(id: Long, sp: Long): Long
    private external fun jSetcostwithcarref(id: Long, sp: Long): Unit
    private external fun jSetcostwithcarptr(id: Long, sp: Long): Unit
    private external fun jGetnewcarsharedptr(id: Long): Long
    private external fun jFinalize(id: Long): Unit
}

open class CarUsage
internal constructor(obj: IEGenObject) : AutoCloseable {
    companion object {
        init {
            System.loadLibrary("wrapper_jni")
        }
        
        protected fun construct_helper(car: Car): Long {
            val kotlintojdkcar = car.id
            val id = jConstructor(kotlintojdkcar)
            return id
        }

        @JvmStatic
        private external fun jConstructor(car: Long): Long
    }
    
    protected var objId = obj.id
    protected val owner = obj.owner
    private var refs: MutableList<Any> = mutableListOf()

    fun keepIEGenReference(ref: Any) {
        refs.add(ref)
    }
    
    open val id: Long
        get() {
            if (objId == 0L) {
                throw RuntimeException("Object is not allocated")
            }
            return objId
        }
    
    constructor(car: Car): this(IEGenObject(construct_helper(car), true)) {
    }
    
    /**
     * Iegen supports only by value return in case shared_ref is set
     */
    fun getCar(): Car {
        val result = jGetcar(id)
        val jdktokotlinresult = Car(IEGenObject(result, true))
        return jdktokotlinresult
    }

    override fun close() {
        if (owner && objId != 0L) {
            jFinalize(objId)
            objId = 0L
        }
    }

    /**
     * Finalize and deletes the object
     */
    protected fun finalize() {
        close()
    }

    ///// External wrapper functions ////////////
    private external fun jGetcar(id: Long): Long
    private external fun jFinalize(id: Long): Unit
}

private external fun jGettypebyid(id: Long): String
