package com.examples.templates

import com.examples.templates.*

class TemplatesApp {

    companion object {
        @JvmStatic
        fun main(args: Array<String>) {

            // [stack-usage]
            var stackPrj = StackProject()
            assert(stack.empty())
            val prj = Project("My Project")
            stackPrj.push(prj)
            assert(not stack.empty())
            assert(stack.top().title == prj.title)
            // [stack-usage]

       }

    }
}
