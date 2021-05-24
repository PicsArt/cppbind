package hello_user_usage

import com.hello_user.hello.*


class HelloUserApp {

    companion object {
        @JvmStatic
        fun main(args: Array<String>) {

            val user = UserInfo("John", 22)
            val young_user = UserInfo("Kate", 18)

            val host = Host()

            assert(host.hello(user)  == "Hello John")
            assert(host.hello(young_user)  == "Hi Kate")

            assert(host.welcome(user)  == "Welcome John! Let me know if you want something.")
            assert(host.welcome(young_user)  == "Welcome Kate! Let me know if you want something.")

            user.want_a_drink = true
            young_user.want_a_drink = true

            assert(host.welcome(user)  == "Welcome John! Do you want cap of beer?")
            assert(host.welcome(young_user)  == "Welcome Kate! Do you want cap of juice?")

       }

    }
}
