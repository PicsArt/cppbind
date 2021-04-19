
import Wrapper
let user = UserInfo(name: "Jhon", age: 22)
let young_user = UserInfo(name: "Kate", age: 18)

let host = Host()

assert(host.hello(user)  == "Hello Jhon")
assert(host.hello(young_user)  == "Hi Kate")

assert(host.welcome(user)  == "Welcome Jhon! Let me know if you want something.")
assert(host.welcome(young_user)  == "Welcome Kate! Let me know if you want something.")

user.want_a_drink = true
young_user.want_a_drink = true

assert(host.welcome(user)  == "Welcome Jhon! Do you want cap of beer?")
assert(host.welcome(young_user)  == "Welcome Kate! Do you want cap of juice?")
