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

package com.examples.enums

import com.examples.cppbind.alias.*
import com.examples.cppbind.exceptionUtils.*
import com.examples.cppbind.exception_helpers.*

/**
 * Class Frame.
 */
open class Frame
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
        const val cppbindCxxTypeName: String = "cppbind::example::Frame"
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
    
    var backgroundColor: Color
        get() {
            val result = jBackgroundcolor(cppbindObjId)
            val jdktokotlinresult_optional = Color.getByValue(result)
            if (jdktokotlinresult_optional == null) {
                ExceptionHandler.handleUncaughtException("Internal error: unresolved reference to non existing field of Color enum.")
            }
            val jdktokotlinresult = jdktokotlinresult_optional!!
            return jdktokotlinresult
        }
        set(value) {
            val kotlintojdkvalue = value.value
            jSetbackgroundcolor(cppbindObjId, kotlintojdkvalue, value)
        }
        

    var backgroundColorShade: ColorShade
        get() {
            val result = jBackgroundcolorshade(cppbindObjId)
            val jdktokotlinresult_optional = ColorShade.getByValue(result)
            if (jdktokotlinresult_optional == null) {
                ExceptionHandler.handleUncaughtException("Internal error: unresolved reference to non existing field of ColorShade enum.")
            }
            val jdktokotlinresult = jdktokotlinresult_optional!!
            return jdktokotlinresult
        }
        set(value) {
            val kotlintojdkvalue = value.value
            jSetbackgroundcolorshade(cppbindObjId, kotlintojdkvalue, value)
        }
        
    
    fun getNextColor(color: Color): Color {
        val kotlintojdkcolor = color.value
        val result = jGetnextcolor(cppbindObjId, kotlintojdkcolor, color)
        val jdktokotlinresult_optional = Color.getByValue(result)
        if (jdktokotlinresult_optional == null) {
            ExceptionHandler.handleUncaughtException("Internal error: unresolved reference to non existing field of Color enum.")
        }
        val jdktokotlinresult = jdktokotlinresult_optional!!
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
        other as Frame
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
    private external fun jBackgroundcolor(id: Long): Int
    private external fun jSetbackgroundcolor(id: Long, value: Int, valueObj: Any?): Unit
    private external fun jBackgroundcolorshade(id: Long): Int
    private external fun jSetbackgroundcolorshade(id: Long, value: Int, valueObj: Any?): Unit
    private external fun jGetnextcolor(id: Long, color: Int, vararg extraObjs: Any?): Int
    private external fun jFinalize(id: Long): Unit
    private external fun jGetcxxid(id: Long): Long
}

private external fun jGettypebyid(id: Long): String
