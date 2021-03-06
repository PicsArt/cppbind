/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 06/01/2022-07:54.
 * Please do not change it manually.
 */

package com.examples.globs.primitives

import com.examples.cppbind.alias.*
import com.examples.cppbind.exceptionUtils.*
import com.examples.cppbind.exception_helpers.*
import com.examples.enums.Color

private val INIT = run {
    System.loadLibrary("wrapper_jni");
}

/**
 * A global function with enum default argument.
 */
fun optionalColor(c: Color = Color.Red): Color {
    val kotlintojdkc = c.value
    val result = jOptionalcolor(kotlintojdkc, c)
    val jdktokotlinresult_optional = Color.getByValue(result)
    if (jdktokotlinresult_optional == null) {
        ExceptionHandler.handleUncaughtException("Internal error: unresolved reference to non existing field of Color enum.")
    }
    val jdktokotlinresult = jdktokotlinresult_optional!!
    return jdktokotlinresult
}

/**
 * A global function with string default argument.
 */
fun optionalString(optionalStr: String = "abc"): String {
    val result = jOptionalstring(optionalStr)
    
    return result
}

/**
 * A global function with primitive default value.
 */
fun optionalInt(i: Int = 5): Int {
    val result = jOptionalint(i)
    
    return result
}

private external fun jOptionalcolor(c: Int, vararg extraObjs: Any?): Int
private external fun jOptionalstring(optionalStr: String, vararg extraObjs: Any?): String
private external fun jOptionalint(i: Int, vararg extraObjs: Any?): Int

private external fun jGettypebyid(id: Long): String
