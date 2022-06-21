import XCTest
import Wrapper

func runHelloUserTests() {

    let user = UserInfo(userName: "John", userAge: 22)
    let young_user = UserInfo(userName: "Kate", userAge: 18)

    let host = Wrapper.Host()

    assert(host.hello(user: user) == "Hello John")
    assert(host.hello(user: young_user) == "Hi Kate")

    assert(host.welcome(user: user) == "Welcome John! Let me know if you want something.")
    assert(host.welcome(user: young_user) == "Welcome Kate! Let me know if you want something.")

    user.want_a_drink = true
    young_user.want_a_drink = true

    assert(host.welcome(user: user) == "Welcome John! Do you want cap of beer?")
    assert(host.welcome(user: young_user) == "Welcome Kate! Do you want cap of juice?")

}

#if os(Linux)
runHelloUserTests()
#elseif os(OSX)
class HelloUserTests: XCTestCase {
    func testRun() throws {
        runHelloUserTests()
    }
}
#endif
