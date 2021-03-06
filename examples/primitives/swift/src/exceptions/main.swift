import XCTest
import Wrapper


func runExceptionExamples() {
// [exceptions-usage-start]
let result = try? ThrowExc.getByKey(m: [1 : 1], key: 0)
assert(result == nil)

do {
    let _ = try ThrowExc.getByKey(m: [1 : 1], key: 0)
} catch is StdOutOfRange {
} catch {
    assert(false)
}

// assert everything is ok for returned pointer value when an exception is raised
do {
  let _ = try ThrowExc.throwsWithReturnValuePtr()
} catch let err as StdInvalidArgument {
  assert(err.what() == "return value error")
} catch {
  assert(false)
}

// assert everything is ok for returned string value when an exception is raised
do {
    let _ = try ThrowExc.throwsWithReturnValueString()
} catch let err as StdInvalidArgument {
    assert(err.what() == "return value error")
} catch {
    assert(false)
}

// checking throwing constructor
do {
    let _ = try ThrowExc(doThrow: true)
} catch let err as StdInvalidArgument {
    assert(err.what() == "inv_arg")
} catch {
    assert(false)
}

do {
    let _ = try MiscExc.returnInteger(doThrow: true)
    assert(false)
} catch is StdOutOfRange {
} catch {
    assert(false)
}

do {
    try MiscExc.raiseErrorByType(errType: "simple_child")
} catch let err as SimpleChildException {
    assert(err.errNum() == 100)
} catch {
    assert(false)
}

// [exceptions-usage-end]

func logger(err_msg : String) -> Never {
    print("Log uncaught exception with user defined logger: \(err_msg)")
    exit(0)
}

func genUncaughtExceptions() {
    ExceptionHandler.setUncaughtExceptionHandler(logger)
    NoThrowExc.noop()
    // check throwing constructor
    let _ = NoThrowExc(doThrow: true)
    // checking throwing setter
    do {
        let obj = try ThrowExc()
        obj.prop1 = "new_value"
    } catch {
        assert(false)
    }
    ExceptionHandler.unsetUncaughtExceptionHandler()
}

// check non-throwing constructor
let _ =  NoThrowExc()

do {
    try MiscExc.raiseErrorByType(errType: "system")
} catch let err as SystemError {
    assert(err.what() == "system error")
} catch {
    assert(false)
}

do {
    try MiscExc.raiseErrorByType(errType: "file")
} catch let err as FileError {
    assert(err.what() == "file error")
} catch {
    assert(false)
}

do {
    try MiscExc.raiseErrorByType(errType: "file")
} catch let err as SystemError {
    assert(err.what() == "file error")
} catch {
    assert(false)
}

do {
    try MiscExc.raiseErrorByType(errType: "runtime")
} catch let err as StdRuntimeError {
    assert(err.what() == "runtime error")
} catch {
    assert(false)
}

do {
    try MiscExc.raiseErrorByType(errType: "runtime")
} catch let err as StdException {
    assert(err.what() == "runtime error")
} catch {
    assert(false)
}

do {
    let n = try MiscExc.returnInteger(doThrow: false)
    assert(n.value == 1)
} catch {
    assert(false)
}

do {
    try MiscExc.raiseErrorByType(errType: "simple_base")
} catch let err as SimpleBaseException {
    assert(err.errNum() == 200)
} catch {
    assert(false)
}

do {
    try MiscExc.raiseErrorByType(errType: "")
} catch let err as StdException {
    assert(err.what() == "std::exception")
} catch {
    assert(false)
}

// check non-throwing properties
// we can't check throwing properties for swift since swift supports throwable getters only for versions >= 5.5
let obj = NoThrowExc()
assert(obj.prop == "prop")
obj.prop = "new_prop"
assert(obj.prop == "new_prop")

// global functions exception handling
// should throw
do {
    try throwExc(doThrow: true)
    assert(false)
} catch let err as StdInvalidArgument {
    assert(err.what() == "inv_arg")
} catch {
    assert(false)
}
// should not throw
do {
    try throwExc(doThrow: false)
} catch {
    assert(false)
}

// because of the exit, it should be called at the end of the test.
genUncaughtExceptions()
}


#if os(Linux)
runExceptionExamples()
#elseif os(OSX)
class ExceptionsTests: XCTestCase {

    func testRun() throws {
        runExceptionExamples()
    }
}
#endif
