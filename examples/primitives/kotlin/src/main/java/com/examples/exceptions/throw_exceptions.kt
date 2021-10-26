/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 10/26/2021-07:50.
 * Please do not change it manually.
 */

package com.examples.exceptions

import alias.*
import com.examples.exception_helpers.*
import exceptionUtils.*

open class ThrowExc
internal constructor(_id: Long) : AutoCloseable {
    companion object {
        init {
            System.loadLibrary("wrapper_jni");
        }
        
        fun getByKey(m: Map<Int, Int>, key: Int): Int {
            
            val tmp_key_kotlin_to_jdk_m = IntArray(m.size) 
            val tmp_val_kotlin_to_jdk_m = IntArray(m.size) 
            val kotlin_to_jdk_m = Pair<IntArray, IntArray>(tmp_key_kotlin_to_jdk_m, tmp_val_kotlin_to_jdk_m)
            var index_m = 0
            for ((key_m, value_m) in m) {
                
                
                tmp_key_kotlin_to_jdk_m[index_m] = key_m
                tmp_val_kotlin_to_jdk_m[index_m] = value_m
                ++index_m
            }
            val result = jGetbykey(kotlin_to_jdk_m, key)
            
            return result
        }
        @JvmStatic
        private external fun jGetbykey(m: Pair<IntArray, IntArray>, key: Int): Int
    }
    
    protected var objId = _id
    
    open val id: Long
        get() {
            if (objId == 0L) {
                throw RuntimeException("Object is not allocated")
            }
            return objId;
        }

    override fun close() {
        if (objId != 0L) {
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
    private external fun jFinalize(id: Long): Unit
}