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

package com.examples.templates

import com.examples.iegen.alias.*
import com.examples.iegen.exceptionUtils.*
import com.examples.iegen.exception_helpers.*
import com.examples.simple.Project

open class StackUsage
internal constructor(_id: Long, _owner: Boolean = false) : AutoCloseable {
    companion object {
        init {
            System.loadLibrary("wrapper_jni")
        }
        
        protected fun construct_helper(): Long {
            val id = jConstructor()
            return id
        }

        @JvmStatic
        private external fun jConstructor(): Long
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
    
    constructor(): this(construct_helper(), true) {
    }
    
    fun firstItemOfSpecializedStack(p: StackPrj): Project {
        val kotlintojdkp = p.id
        val result = jFirstitemofspecializedstack(id, kotlintojdkp)
        val jdktokotlinresult = Project(result)
        return jdktokotlinresult
    }

    open fun firstItemOfTemplateStack(arg0: StackPrj): Project {
        val kotlintojdkarg0 = arg0.id
        val result = jFirstitemoftemplatestackProject(id, kotlintojdkarg0)
        val jdktokotlinresult = Project(result)
        return jdktokotlinresult
    }

    /**
     * Example to check typedef argument types
     */
    fun firstItemOfSpecializedStackWithTypedefArg(p: StackPrj): Project {
        val kotlintojdkp = p.id
        val result = jFirstitemofspecializedstackwithtypedefarg(id, kotlintojdkp)
        val jdktokotlinresult = Project(result)
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
    private external fun jFirstitemofspecializedstack(id: Long, p: Long): Long
    private external fun jFirstitemoftemplatestackProject(id: Long, arg0: Long): Long
    private external fun jFirstitemofspecializedstackwithtypedefarg(id: Long, p: Long): Long
    private external fun jFinalize(id: Long): Unit
}

private external fun jGettypebyid(id: Long): String
