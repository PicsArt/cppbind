/**
 * ,--.,------. ,----.   ,------.,--.  ,--.
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  |
 * |  ||  `--, |  | .---.|  `--, |  |' '  |
 * |  ||  `---.'  '--'  ||  `---.|  | `   |
 * `--'`------' `------' `------'`--'  `--'
 * 
 * This file is generated by iegen on 12/04/2021-12:27.
 * Please do not change it manually.
 */

package com.examples.extra

import com.examples.exception_helpers.*
import com.examples.iegen.alias.*
import com.examples.iegen.exceptionUtils.*

/**
 * comments
 * 
 */
open class ObjectUsage
internal constructor(_id: Long) : Object(_id) {
    companion object {
        
        /**
         * comments
         * 
         */
        protected fun construct_helper(): Long {
            val id = jConstructor()
            return id
        }

        @JvmStatic
        private external fun jConstructor(): Long
    }
    
    
    /**
     * comments
     * 
     */
    constructor(): this(construct_helper()) {
    }
}