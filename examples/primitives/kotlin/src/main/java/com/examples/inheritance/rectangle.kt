/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 06/06/2022-05:25.
 * Please do not change it manually.
 */

package com.examples.inheritance

import com.examples.cppbind.alias.*
import com.examples.cppbind.exceptionUtils.*
import com.examples.cppbind.exception_helpers.*


interface IRectangle : IParallelogram {
    
    open override val area: Double
        get() {
            val result = IRectangleHelper.jArea(id)
            
            return result
        }

    val length: Double
        get() {
            val result = IRectangleHelper.jLength(id)
            
            return result
        }

    val width: Double
        get() {
            val result = IRectangleHelper.jWidth(id)
            
            return result
        }
    

    companion object {
        public fun cppbindConstructObject(id: Long, owner: Boolean = false): IRectangle {
            val idType = jGettypebyid(id)
            when (idType) {
                Square.cppbindCxxTypeName -> return Square(CppBindObject(id, owner))
                else -> return RectangleImpl(CppBindObject(id, owner))
            }
        }
    }
}


class IRectangleHelper {
    companion object {
        @JvmStatic
        external fun jArea(id: Long): Double
        @JvmStatic
        external fun jLength(id: Long): Double
        @JvmStatic
        external fun jWidth(id: Long): Double
    }
}


open class RectangleImpl
internal constructor(obj : CppBindObject) : IRectangle {
    companion object {
        init {
            System.loadLibrary("wrapper_jni")
        }
        
        protected fun construct_helper(length: Double, width: Double): Long {
            val id = jConstructor(length, width)
            return id
        }

        @JvmStatic
        private external fun jConstructor(length: Double, width: Double, vararg extraObjs: Any?): Long
        const val cppbindCxxTypeName: String = "cppbind::example::Rectangle"
    }

    protected var cppbindObj = obj
    private var refs: MutableList<Any> = mutableListOf()

    override fun keepCppBindReference(ref: Any) {
        refs.add(ref)
    }

    override val id: Long
        get() {
            if (cppbindObj.id == 0L) {
                throw RuntimeException("Object is not allocated")
            }
            return cppbindObj.id
        }

    /**
     * An internal property returning underlying C++ object id.
     * It is intended to be used by the generated code.
     */
    internal val cxxId: Long by lazy {
        jGetcxxid(cppbindObj.id)
    }

    /**
     * An internal property returning underlying C++ type name.
     * It is intended to be used by the generated code.
     */
    internal val cxxTypeName: String by lazy {
        jGettypebyid(cppbindObj.id)
    }
    
    constructor(length: Double, width: Double): this(CppBindObject(construct_helper(length, width), true)) {
    }

    override fun close() {
        if (cppbindObj.owner && cppbindObj.id != 0L) {
            jFinalize(cppbindObj.id)
            cppbindObj.id = 0L
        }
    }

    /**
    * Finalize and deletes the object
    */
    protected fun finalize() {
        close()
    }
    
    /**
     * CPPBind generated hashCode method returning the hash of underlying C++ object id. .
     */
    override fun hashCode(): Int {
        return cxxId.hashCode()
    }

    /**
     * CPPBind generated equals method comparing the underlying C++ object ids.
     */
    override fun equals(other: Any?): Boolean {
        other as RectangleImpl
        return cxxId == other.cxxId
    }

    /**
     * CPPBind generated toString method returning underlying C++ object type and id.
     */
    override fun toString(): String {
        return "<0x%x: %s>".format(cxxId, cxxTypeName)
    }

    ///// External wrapper functions ////////////
    private external fun jFinalize(id: Long): Unit
    private external fun jGetcxxid(id: Long): Long
}

private external fun jGettypebyid(id: Long): String
