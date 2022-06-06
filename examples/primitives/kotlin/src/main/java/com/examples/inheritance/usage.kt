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

open class GeometricFigure
internal constructor(obj: CppBindObject) : AutoCloseable {
    companion object {
        init {
            System.loadLibrary("wrapper_jni")
        }
        
        protected fun construct_helper(p: IParallelogram): Long {
            val kotlintojdkp = p.id
            val id = jConstructor(kotlintojdkp, p)
            return id
        }

        @JvmStatic
        private external fun jConstructor(p: Long, vararg extraObjs: Any?): Long
        const val cppbindCxxTypeName: String = "cppbind::example::GeometricFigure"
    }
    
    protected var cppbindObj = obj
    private var refs: MutableList<Any> = mutableListOf()

    fun keepCppBindReference(ref: Any) {
        refs.add(ref)
    }
    
    open val id: Long
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
    
    constructor(p: IParallelogram): this(CppBindObject(construct_helper(p), true)) {
    }
    
    var parallelogram: IParallelogram
        get() {
            val result = jParallelogram(id)
            
            val jdktokotlinresult : IParallelogram
            jdktokotlinresult = IParallelogram.cppbindConstructObject(result)
            jdktokotlinresult.keepCppBindReference(this)
            return jdktokotlinresult
        }
        set(value) {
            val kotlintojdkvalue = value.id
            jSetparallelogram(id, kotlintojdkvalue, value)
        }

    var nullableParallelogram: IParallelogram?
        get() {
            val result = jNullableparallelogram(id)
            
            val jdktokotlinresult : IParallelogram?
            if (result == 0L)
                jdktokotlinresult = null
            else {
                jdktokotlinresult = IParallelogram.cppbindConstructObject(result)
            }
            jdktokotlinresult?.let {
                jdktokotlinresult.keepCppBindReference(this)
            }
            return jdktokotlinresult
        }
        set(value) {
            val kotlintojdkvalue = value?.id ?: 0L
            jSetnullableparallelogram(id, kotlintojdkvalue, value)
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
        other as GeometricFigure
        return cxxId == other.cxxId
    }

    /**
     * CPPBind generated toString method returning underlying C++ object type and id.
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
    private external fun jParallelogram(id: Long): Long
    private external fun jSetparallelogram(id: Long, value: Long, valueObj: Any?): Unit
    private external fun jNullableparallelogram(id: Long): Long
    private external fun jSetnullableparallelogram(id: Long, value: Long, valueObj: Any?): Unit
    private external fun jFinalize(id: Long): Unit
    private external fun jGetcxxid(id: Long): Long
}

open class MyVehicle
internal constructor(obj: CppBindObject) : AutoCloseable {
    companion object {
        init {
            System.loadLibrary("wrapper_jni")
        }
        
        protected fun construct_helper(v: Vehicle, cv: Vehicle): Long {
            val kotlintojdkv = v.id
            val kotlintojdkcv = cv.id
            val id = jConstructor(kotlintojdkv, kotlintojdkcv, v, cv)
            return id
        }

        @JvmStatic
        private external fun jConstructor(v: Long, cv: Long, vararg extraObjs: Any?): Long
        const val cppbindCxxTypeName: String = "cppbind::example::MyVehicle"
    }
    
    protected var cppbindObj = obj
    private var refs: MutableList<Any> = mutableListOf()

    fun keepCppBindReference(ref: Any) {
        refs.add(ref)
    }
    
    open val id: Long
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
    
    constructor(v: Vehicle, cv: Vehicle): this(CppBindObject(construct_helper(v, cv), true)) {
    }
    
    var vehicle: Vehicle?
        get() {
            val result = jVehicle(id)
            
            val jdktokotlinresult : Vehicle?
            if (result == 0L)
                jdktokotlinresult = null
            else {
                jdktokotlinresult = Vehicle.cppbindConstructObject(result, true)
            }
            return jdktokotlinresult
        }
        set(value) {
            val kotlintojdkvalue = value?.id ?: 0L
            jSetvehicle(id, kotlintojdkvalue, value)
        }

    var constVehicle: Vehicle?
        get() {
            val result = jConstvehicle(id)
            
            val jdktokotlinresult : Vehicle?
            if (result == 0L)
                jdktokotlinresult = null
            else {
                jdktokotlinresult = Vehicle.cppbindConstructObject(result, true)
            }
            return jdktokotlinresult
        }
        set(value) {
            val kotlintojdkvalue = value?.id ?: 0L
            jSetconstvehicle(id, kotlintojdkvalue, value)
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
        other as MyVehicle
        return cxxId == other.cxxId
    }

    /**
     * CPPBind generated toString method returning underlying C++ object type and id.
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
    private external fun jVehicle(id: Long): Long
    private external fun jSetvehicle(id: Long, value: Long, valueObj: Any?): Unit
    private external fun jConstvehicle(id: Long): Long
    private external fun jSetconstvehicle(id: Long, value: Long, valueObj: Any?): Unit
    private external fun jFinalize(id: Long): Unit
    private external fun jGetcxxid(id: Long): Long
}

open class MyBicycle
internal constructor(obj: CppBindObject) : AutoCloseable {
    companion object {
        init {
            System.loadLibrary("wrapper_jni")
        }
        
        protected fun construct_helper(b: Bicycle): Long {
            val kotlintojdkb = b.id
            val id = jConstructor(kotlintojdkb, b)
            return id
        }

        @JvmStatic
        private external fun jConstructor(b: Long, vararg extraObjs: Any?): Long
        const val cppbindCxxTypeName: String = "cppbind::example::MyBicycle"
    }
    
    protected var cppbindObj = obj
    private var refs: MutableList<Any> = mutableListOf()

    fun keepCppBindReference(ref: Any) {
        refs.add(ref)
    }
    
    open val id: Long
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
    
    constructor(b: Bicycle): this(CppBindObject(construct_helper(b), true)) {
    }
    
    var bicycle: Bicycle
        get() {
            val result = jBicycle(id)
            val jdktokotlinresult = Bicycle(CppBindObject(result, true))
            return jdktokotlinresult
        }
        set(value) {
            val kotlintojdkvalue = value.id
            jSetbicycle(id, kotlintojdkvalue, value)
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
        other as MyBicycle
        return cxxId == other.cxxId
    }

    /**
     * CPPBind generated toString method returning underlying C++ object type and id.
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
    private external fun jBicycle(id: Long): Long
    private external fun jSetbicycle(id: Long, value: Long, valueObj: Any?): Unit
    private external fun jFinalize(id: Long): Unit
    private external fun jGetcxxid(id: Long): Long
}

open class MyCalendar
internal constructor(obj: CppBindObject) : AutoCloseable {
    companion object {
        init {
            System.loadLibrary("wrapper_jni")
        }
        
        protected fun construct_helper(events: List<Date>): Long {
            val kotlintojdkevents = LongArray(events.size) 
            var index_events = 0
            for (value_events in events) {
                val kotlintojdkvalue_events = value_events.id
                kotlintojdkevents[index_events] = kotlintojdkvalue_events
                ++index_events
            }
            val id = jConstructor(kotlintojdkevents, events)
            return id
        }

        @JvmStatic
        private external fun jConstructor(events: LongArray, vararg extraObjs: Any?): Long
        const val cppbindCxxTypeName: String = "cppbind::example::MyCalendar"
    }
    
    protected var cppbindObj = obj
    private var refs: MutableList<Any> = mutableListOf()

    fun keepCppBindReference(ref: Any) {
        refs.add(ref)
    }
    
    open val id: Long
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
    
    constructor(events: List<Date>): this(CppBindObject(construct_helper(events), true)) {
    }
    
    val events: List<Date>
        get() {
            val result = jEvents(id)
            val jdktokotlinresult: MutableList<Date> = mutableListOf()
            for (value_result in result) {
                
                val jdktokotlinvalue_result : Date
                jdktokotlinvalue_result = Date.cppbindConstructObject(value_result, true)
                jdktokotlinresult.add(jdktokotlinvalue_result)
            }
            return jdktokotlinresult
        }
    
    fun addEvent(e: Date): Unit {
        val kotlintojdke = e.id
        val result = jAddevent(id, kotlintojdke, e)
        
        return result
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
        other as MyCalendar
        return cxxId == other.cxxId
    }

    /**
     * CPPBind generated toString method returning underlying C++ object type and id.
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
    private external fun jAddevent(id: Long, e: Long, vararg extraObjs: Any?): Unit
    private external fun jEvents(id: Long): LongArray
    private external fun jFinalize(id: Long): Unit
    private external fun jGetcxxid(id: Long): Long
}

private external fun jGettypebyid(id: Long): String
