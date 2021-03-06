/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 06/06/2022-15:10.
 * Please do not change it manually.
 */

package com.examples.misc

import com.examples.cppbind.alias.*
import com.examples.cppbind.exceptionUtils.*
import com.examples.cppbind.exception_helpers.*
import java.awt.geom.Point2D

/**
 * comments
 * 
 */
open class SizeUsage
internal constructor(obj: CppBindObject) : AutoCloseable {
    companion object {
        init {
            System.loadLibrary("wrapper_jni")
        }
        
        /**
         * comments
         * 
         */
        fun multiplyBy(size: Point2D.Float, n: Int): Point2D.Float {
            val width_size = size.getX().toFloat()
            val height_size = size.getY().toFloat()
            val kotlintojdksize = FloatArray(2)
            kotlintojdksize.set(0, width_size)
            kotlintojdksize.set(1, height_size)
            val result = jMultiplyby(kotlintojdksize, n, size)
            val width_result = result[0]
            val height_result = result[1]
            val jdktokotlinresult = Point2D.Float(width_result, height_result)
            return jdktokotlinresult
        }
        @JvmStatic
        private external fun jMultiplyby(size: FloatArray, n: Int, vararg extraObjs: Any?): FloatArray

        /**
         * comments
         * 
         */
        fun doubleSizeF(): Point2D.Float {
            val result = jDoublesizef_1()
            val width_result = result[0]
            val height_result = result[1]
            val jdktokotlinresult = Point2D.Float(width_result, height_result)
            return jdktokotlinresult
        }
        @JvmStatic
        private external fun jDoublesizef_1(): FloatArray


        /**
         * comments
         * 
         */
        fun doubleSizeF(resolution: Point2D.Float): Point2D.Float {
            val width_resolution = resolution.getX().toFloat()
            val height_resolution = resolution.getY().toFloat()
            val kotlintojdkresolution = FloatArray(2)
            kotlintojdkresolution.set(0, width_resolution)
            kotlintojdkresolution.set(1, height_resolution)
            val result = jDoublesizef(kotlintojdkresolution, resolution)
            val width_result = result[0]
            val height_result = result[1]
            val jdktokotlinresult = Point2D.Float(width_result, height_result)
            return jdktokotlinresult
        }
        @JvmStatic
        private external fun jDoublesizef(resolution: FloatArray, vararg extraObjs: Any?): FloatArray
        /**
         * An internal property to keep an information about the underlying C++ object type.
         * It is intended to be used by the generated code.
         */
        const val cppbindCxxTypeName: String = "cppbind::example::SizeUsage"
    }
    
    protected var cppbindObj = obj
    private var refs: MutableList<Any> = mutableListOf()

    /**
     * An internal method to bind the lifetimes of the current and another object.
     * It is intended to be used by the generated code.
     */
    fun keepCppBindReference(ref: Any) {
        refs.add(ref)
    }
    /**
     * An internal getter to get the id of an object.
     * It is intended to be used by the generated code.
     */
    
    open val cppbindObjId: Long
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
        other as SizeUsage
        return cxxId == other.cxxId
    }

    /**
     * CppBind generated toString method returning underlying C++ object type and id.
     */
    override fun toString(): String {
        return "<0x%x: %s>".format(cxxId, cxxTypeName)
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

    ///// External wrapper functions ////////////
    private external fun jFinalize(id: Long): Unit
    private external fun jGetcxxid(id: Long): Long
}

/**
 * comments
 * 
 */
open class BufferUsage
internal constructor(obj: CppBindObject) : AutoCloseable {
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
        /**
         * An internal property to keep an information about the underlying C++ object type.
         * It is intended to be used by the generated code.
         */
        const val cppbindCxxTypeName: String = "cppbind::example::BufferUsage"
    }
    
    protected var cppbindObj = obj
    private var refs: MutableList<Any> = mutableListOf()

    /**
     * An internal method to bind the lifetimes of the current and another object.
     * It is intended to be used by the generated code.
     */
    fun keepCppBindReference(ref: Any) {
        refs.add(ref)
    }
    /**
     * An internal getter to get the id of an object.
     * It is intended to be used by the generated code.
     */
    
    open val cppbindObjId: Long
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
    
    constructor(): this(CppBindObject(construct_helper(), true)) {
    }
    
    fun usage1(b: BufferInt): String {
        val kotlintojdkb = b.getObjId()
        val result = jUsage1(cppbindObjId, kotlintojdkb, b)
        
        return result
    }

    fun usage2(): BufferInt {
        val result = jUsage2(cppbindObjId)
        val jdktokotlinresult = BufferInt(result)
        return jdktokotlinresult
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
        other as BufferUsage
        return cxxId == other.cxxId
    }

    /**
     * CppBind generated toString method returning underlying C++ object type and id.
     */
    override fun toString(): String {
        return "<0x%x: %s>".format(cxxId, cxxTypeName)
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

    ///// External wrapper functions ////////////
    private external fun jUsage1(id: Long, b: Long, vararg extraObjs: Any?): String
    private external fun jUsage2(id: Long): Long
    private external fun jFinalize(id: Long): Unit
    private external fun jGetcxxid(id: Long): Long
}

private external fun jGettypebyid(id: Long): String
