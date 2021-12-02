import XCTest
import Wrapper


func runExceptionExamples() {
    // [exceptions-usage]

    let result = try? ThrowExc.getByKey(m: [1 : 1], key: 0)
    assert(result == nil)

    do {
        let _ = try ThrowExc.getByKey(m: [1 : 1], key: 0)
    } catch let err as StdOutOfRange {
        assert(err.what().contains("key not found"))
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


    do {
        let _ = try MiscExc.returnInteger(do_throw: true)
        assert(false)
    } catch is StdOutOfRange {
    } catch {
        assert(false)
    }

    do {
        try MiscExc.raiseErrorByType(err_type: "simple_child")
    } catch let err as SimpleChildException {
        assert(err.errNum() == 100)
    } catch {
        assert(false)
    }

    // [exceptions-usage]

    func logger(err_msg : String) -> Void {
        print("Log uncaught exception with user defined logger: \(err_msg)")
    }

    func genUncaughtExceptions() {
        ExceptionHandler.setUncaughtExceptionHandler(logger)
        NoThrowExc.noop()
        ExceptionHandler.unsetUncaughtExceptionHandler()
    }

    genUncaughtExceptions()

    do {
        try MiscExc.raiseErrorByType(err_type: "system")
    } catch let err as SystemError {
        assert(err.what() == "system error")
    } catch {
        assert(false)
    }

    do {
        try MiscExc.raiseErrorByType(err_type: "file")
    } catch let err as FileError {
        assert(err.what() == "file error")
    } catch {
        assert(false)
    }

    do {
        try MiscExc.raiseErrorByType(err_type: "file")
    } catch let err as SystemError {
        assert(err.what() == "file error")
    } catch {
        assert(false)
    }

    do {
        try MiscExc.raiseErrorByType(err_type: "runtime")
    } catch let err as StdRuntimeError {
        assert(err.what() == "runtime error")
    } catch {
        assert(false)
    }

    do {
        try MiscExc.raiseErrorByType(err_type: "runtime")
    } catch let err as StdException {
        assert(err.what() == "runtime error")
    } catch {
        assert(false)
    }

    do {
        let n = try MiscExc.returnInteger(do_throw: false)
        assert(n.value == 1)
    } catch {
        assert(false)
    }

    do {
        try MiscExc.raiseErrorByType(err_type: "simple_base")
    } catch let err as SimpleBaseException {
        assert(err.errNum() == 200)
    } catch {
        assert(false)
    }

    do {
        try MiscExc.raiseErrorByType(err_type: "")
    } catch let err as StdException {
        assert(err.what() == "std::exception")
    } catch {
        assert(false)
    }
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
