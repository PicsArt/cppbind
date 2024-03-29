/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 08/11/2022-09:04.
 * Please do not change it manually.
 */

package com.examples.enums

import com.examples.cppbind.*
import com.examples.cppbind.exceptions.*

private val INIT = run {
    System.loadLibrary("wrapper_jni");
}

enum class LogLevel(val value: Int) {
    DEBUG(0),
    log_info_level(1),
    WARNING(2),
    ERROR(3),
    LOG_CRITICAL(4);

    companion object {
        private val values = values()
        fun getByValue(value: Int) = values.firstOrNull { it.value == value }
    }
}

fun getNextLogLevel(log_level: LogLevel): LogLevel {
    val kotlintojdklog_level = log_level.value
    val result = jGetnextloglevel(kotlintojdklog_level, log_level)
    val jdktokotlinresultOptional = LogLevel.getByValue(result)
    if (jdktokotlinresultOptional == null) {
        ExceptionHandler.handleUncaughtException("Internal error: unresolved reference to non existing field of LogLevel enum.")
    }
    val jdktokotlinresult = jdktokotlinresultOptional!!
    return jdktokotlinresult
}

private external fun jGetnextloglevel(log_level: Int, vararg extraObjs: Any?): Int

private external fun jGettypebyid(id: Long): String
