/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 08/12/2022-06:48.
 * Please do not change it manually.
 */

package com.examples.inheritance

import com.examples.cppbind.*
import com.examples.cppbind.exceptions.*


interface IParallelogram : AutoCloseable {
    /**
     * An internal getter to get the id of an object.
     * It is intended to be used by the generated code.
     */
    val cppbindObjId: Long
    /**
     * An internal method to bind the lifetimes of the current and another object.
     * It is intended to be used by the generated code.
     */
    fun keepCppBindReference(ref: Any)
    
    open val area: Double
        get() {
            val result = IParallelogramHelper.jArea(cppbindObjId)
            
            return result
        }
    
    open fun perimeter(): Double {
        val result = IParallelogramHelper.jPerimeter(cppbindObjId)
        
        return result
    }

    companion object {
        /**
         * An internal method to create a Kotlin object from a C++ object.
         * It is intended to be used by the generated code.
         */
        public fun cppbindConstructObject(id: Long, owner: Boolean = false): IParallelogram {
            val idType = jGettypebyid(id)
            when (idType) {
                RectangleImpl.cppbindCxxTypeName -> return RectangleImpl(CppBindObject(id, owner))
                RhombusFigureImpl.cppbindCxxTypeName -> return RhombusFigureImpl(CppBindObject(id, owner))
                Square.cppbindCxxTypeName -> return Square(CppBindObject(id, owner))
                else -> return ParallelogramImpl(CppBindObject(id, owner))
            }
        }
    }
}


class IParallelogramHelper {
    companion object {
        @JvmStatic
        external fun jArea(id: Long): Double
        @JvmStatic
        external fun jPerimeter(id: Long): Double
    }
}


open class ParallelogramImpl
internal constructor(obj : CppBindObject) : IParallelogram {
    companion object {
        init {
            System.loadLibrary("wrapper_jni")
        }
        
        /**
         * An internal property to keep an information about the underlying C++ object type.
         * It is intended to be used by the generated code.
         */
        const val cppbindCxxTypeName: String = "cppbind::example::Parallelogram"
    }

    protected var cppbindObj = obj
    private var refs: MutableList<Any> = mutableListOf()

    override fun keepCppBindReference(ref: Any) {
        refs.add(ref)
    }

    override val cppbindObjId: Long
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
     * CppBind generated hashCode method returning the hash of underlying C++ object id.
     */
    override fun hashCode(): Int {
        return cxxId.hashCode()
    }

    /**
     * CppBind generated equals method comparing the underlying C++ object ids.
     */
    override fun equals(other: Any?): Boolean {
        other as ParallelogramImpl
        return cxxId == other.cxxId
    }

    /**
     * CppBind generated toString method returning underlying C++ object type and id.
     */
    override fun toString(): String {
        return "<0x$cxxId: $cxxTypeName>"
    }

    ///// External wrapper functions ////////////
    private external fun jFinalize(id: Long): Unit
    private external fun jGetcxxid(id: Long): Long
}

private external fun jGettypebyid(id: Long): String
