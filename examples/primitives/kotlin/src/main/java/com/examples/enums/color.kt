/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 10/19/2021-07:58.
 * Please do not change it manually.
 */

package com.examples.enums

import alias.*
import com.examples.exception_helpers.*
import exceptionUtils.*
enum class Color(val value: Int) {
    /**
     * Red = 1
     */
    Red(1),
    /**
     * Green = 1
     */
    Green(2),
    /**
     * Blue = 20
     */
    Blue(20);

    companion object {
        private val values = values();
        fun getByValue(value: Int) = values.firstOrNull { it.value == value }
    }

    override fun toString(): String {
        return this.value.toString()
    }
}
enum class ColorShade(val value: Int) {
    ShadeLight(1),
    ShadeDark(2);

    companion object {
        private val values = values();
        fun getByValue(value: Int) = values.firstOrNull { it.value == value }
    }
}