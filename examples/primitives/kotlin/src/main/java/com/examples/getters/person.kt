/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 02/22/2022-09:26.
 * Please do not change it manually.
 */

package com.examples.getters

import com.examples.iegen.alias.*
import com.examples.iegen.exceptionUtils.*
import com.examples.iegen.exception_helpers.*

/**
 * This class contains a private string field and getter/setter methods for it.
 */
open class Person
internal constructor(_id: Long, _owner: Boolean = false) : AutoCloseable {
    companion object {
        init {
            System.loadLibrary("wrapper_jni")
        }
        
        protected fun construct_helper(name: String, email: String, age: Int): Long {
            val id = jConstructor(name, email, age)
            return id
        }

        @JvmStatic
        private external fun jConstructor(name: String, email: String, age: Int): Long
    }
    
    protected var objId = _id
    protected val owner = _owner
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
    
    constructor(name: String, email: String, age: Int): this(construct_helper(name, email, age), true) {
    }
    
    var name: String
        get() {
            val result = jName(id)
            
            return result
        }
        set(value) {
            
            jSetfullname(id, value)
        }

    val email: String
        get() {
            val result = jEmail(id)
            
            return result
        }

    var age: Int
        get() {
            val result = jAge(id)
            
            return result
        }
        set(value) {
            
            jSetage(id, value)
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
    private external fun jName(id: Long): String
    private external fun jSetfullname(id: Long, value: String): Unit
    private external fun jEmail(id: Long): String
    private external fun jAge(id: Long): Int
    private external fun jSetage(id: Long, value: Int): Unit
    private external fun jFinalize(id: Long): Unit
}

private external fun jGettypebyid(id: Long): String
