/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 07/22/2022-13:29.
 * Please do not change it manually.
 */

package com.examples.misc

import com.examples.cppbind.*
import com.examples.cppbind.exception_helpers.*

private val INIT = run {
    System.loadLibrary("wrapper_jni");
}

fun atoi(num: String): Int {
    val result = jAtoi(num)
    
    return result
}

private external fun jAtoi(num: String?, vararg extraObjs: Any?): Int

private external fun jGettypebyid(id: Long): String
