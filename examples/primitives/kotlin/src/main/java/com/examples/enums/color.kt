package com.examples.enums

import alias.*

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
}