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
import com.examples.inheritance.mammals.IMammals


interface IAnimal : AutoCloseable {
    val id: Long
    fun keepCppBindReference(ref: Any)
    
    
    open fun typeName(): String {
        val result = IAnimalHelper.jTypename(id)
        
        return result
    }

    fun isEqualTo(a: IAnimal): Boolean {
        val kotlintojdka = a.id
        val result = IAnimalHelper.jIsequalto(id, kotlintojdka, a)
        
        return result
    }

    companion object {
        public fun cppbindConstructObject(id: Long, owner: Boolean = false): IAnimal {
            val idType = jGettypebyid(id)
            when (idType) {
                LittleFrog.cppbindCxxTypeName -> return LittleFrog(CppBindObject(id, owner))
                Frog.cppbindCxxTypeName -> return Frog(CppBindObject(id, owner))
                IMammals.Dolphin.cppbindCxxTypeName -> return IMammals.Dolphin(CppBindObject(id, owner))
                AquaticAnimal.cppbindCxxTypeName -> return AquaticAnimal(CppBindObject(id, owner))
                TerrestrialAnimalImpl.cppbindCxxTypeName -> return TerrestrialAnimalImpl(CppBindObject(id, owner))
                else -> return AnimalImpl(CppBindObject(id, owner))
            }
        }
    }
}


class IAnimalHelper {
    companion object {
        @JvmStatic
        external fun jTypename(id: Long): String
        @JvmStatic
        external fun jIsequalto(id: Long, a: Long, vararg extraObjs: Any?): Boolean
    }
}


open class AnimalImpl
internal constructor(obj : CppBindObject) : IAnimal {
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
        const val cppbindCxxTypeName: String = "cppbind::example::Animal"
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
    
    constructor(): this(CppBindObject(construct_helper(), true)) {
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
        other as AnimalImpl
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


interface ITerrestrialAnimal : IAnimal {
    
    
    open override fun typeName(): String {
        val result = ITerrestrialAnimalHelper.jTypename(id)
        
        return result
    }

    companion object {
        public fun cppbindConstructObject(id: Long, owner: Boolean = false): ITerrestrialAnimal {
            val idType = jGettypebyid(id)
            when (idType) {
                LittleFrog.cppbindCxxTypeName -> return LittleFrog(CppBindObject(id, owner))
                Frog.cppbindCxxTypeName -> return Frog(CppBindObject(id, owner))
                else -> return TerrestrialAnimalImpl(CppBindObject(id, owner))
            }
        }
    }
}


class ITerrestrialAnimalHelper {
    companion object {
        @JvmStatic
        external fun jTypename(id: Long): String
    }
}


open class TerrestrialAnimalImpl
internal constructor(obj : CppBindObject) : ITerrestrialAnimal {
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
        const val cppbindCxxTypeName: String = "cppbind::example::TerrestrialAnimal"
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
    
    constructor(): this(CppBindObject(construct_helper(), true)) {
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
        other as TerrestrialAnimalImpl
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

open class AquaticAnimal
internal constructor(obj: CppBindObject) : IAnimal, AutoCloseable {
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
        const val cppbindCxxTypeName: String = "cppbind::example::AquaticAnimal"

        public fun cppbindConstructObject(id: Long, owner: Boolean = false): AquaticAnimal {
            val idType = jGettypebyid(id)
            when (idType) {
                LittleFrog.cppbindCxxTypeName -> return LittleFrog(CppBindObject(id, owner))
                Frog.cppbindCxxTypeName -> return Frog(CppBindObject(id, owner))
                IMammals.Dolphin.cppbindCxxTypeName -> return IMammals.Dolphin(CppBindObject(id, owner))
                else -> return AquaticAnimal(CppBindObject(id, owner))
            }
        }
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
    
    constructor(): this(CppBindObject(construct_helper(), true)) {
    }
    
    open override fun typeName(): String {
        val result = jTypename(id)
        
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
        other as AquaticAnimal
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
    private external fun jTypename(id: Long): String
    private external fun jFinalize(id: Long): Unit
    private external fun jGetcxxid(id: Long): Long
}

open class Frog
internal constructor(obj: CppBindObject) : ITerrestrialAnimal, AquaticAnimal(obj) {
    companion object {
        
        protected fun construct_helper(): Long {
            val id = jConstructor()
            return id
        }

        @JvmStatic
        private external fun jConstructor(): Long
        const val cppbindCxxTypeName: String = "cppbind::example::Frog"
    }
    
    override val id: Long
        get() {
            if (cppbindObj.id == 0L) {
                throw RuntimeException("Object is not allocated")
            }
            return cppbindObj.id
        }
    
    constructor(): this(CppBindObject(construct_helper(), true)) {
    }
    
    open override fun typeName(): String {
        val result = jTypename(id)
        
        return result
    }

    ///// External wrapper functions ////////////
    private external fun jTypename(id: Long): String
}

/**
 * Class to help checking the empty case of descendants list
 */
open class LittleFrog
internal constructor(obj: CppBindObject) : Frog(obj) {
    companion object {
        
        protected fun construct_helper(): Long {
            val id = jConstructor()
            return id
        }

        @JvmStatic
        private external fun jConstructor(): Long
        const val cppbindCxxTypeName: String = "cppbind::example::LittleFrog"
    }
    
    
    constructor(): this(CppBindObject(construct_helper(), true)) {
    }
}

open class AnimalUsage
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

        protected fun construct_helper(little_frog: LittleFrog): Long {
            val kotlintojdklittle_frog = little_frog.id
            val id = jConstructor_1(kotlintojdklittle_frog, little_frog)
            return id
        }

        @JvmStatic
        private external fun jConstructor_1(little_frog: Long, vararg extraObjs: Any?): Long

        fun getAnimalTypeName(animal: IAnimal): String {
            val kotlintojdkanimal = animal.id
            val result = jGetanimaltypename(kotlintojdkanimal, animal)
            
            return result
        }
        @JvmStatic
        private external fun jGetanimaltypename(animal: Long, vararg extraObjs: Any?): String

        fun getAquaticAnimalTypeName(animal: AquaticAnimal): String {
            val kotlintojdkanimal = animal.id
            val result = jGetaquaticanimaltypename(kotlintojdkanimal, animal)
            
            return result
        }
        @JvmStatic
        private external fun jGetaquaticanimaltypename(animal: Long, vararg extraObjs: Any?): String
        const val cppbindCxxTypeName: String = "cppbind::example::AnimalUsage"
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
    
    constructor(): this(CppBindObject(construct_helper(), true)) {
    }

    constructor(little_frog: LittleFrog): this(CppBindObject(construct_helper(little_frog), true)) {
    }
    
    fun getAnimal(): IAnimal {
        val result = jGetanimal(id)
        
        val jdktokotlinresult : IAnimal
        jdktokotlinresult = IAnimal.cppbindConstructObject(result)
        return jdktokotlinresult
    }

    fun getAquaticAnimal(): AquaticAnimal {
        val result = jGetaquaticanimal(id)
        
        val jdktokotlinresult : AquaticAnimal
        jdktokotlinresult = AquaticAnimal.cppbindConstructObject(result)
        return jdktokotlinresult
    }

    fun getFrog(): Frog {
        val result = jGetfrog(id)
        val jdktokotlinresult = Frog(CppBindObject(result))
        return jdktokotlinresult
    }

    /**
     * Method to check that any downcast is not done when descendants=[]
     */
    fun getLittleFrog(): Frog {
        val result = jGetlittlefrog(id)
        val jdktokotlinresult = Frog(CppBindObject(result))
        return jdktokotlinresult
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
        other as AnimalUsage
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
    private external fun jGetanimal(id: Long): Long
    private external fun jGetaquaticanimal(id: Long): Long
    private external fun jGetfrog(id: Long): Long
    private external fun jGetlittlefrog(id: Long): Long
    private external fun jFinalize(id: Long): Unit
    private external fun jGetcxxid(id: Long): Long
}

private external fun jGettypebyid(id: Long): String
