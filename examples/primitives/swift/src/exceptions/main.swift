import Wrapper

let result = try? Exc.getByKey(m: [1 : 1], key: 0)
assert(result == nil)

do {
   let _ = try Exc.getByKey(m: [1 : 1], key: 0)
} catch let err as StdOutOfRange {
   assert(err.what() == "map::at")
} catch {
    assert(false)
}

do {
    let n = try Exc.returnInteger(do_throw: false)
    assert(n.value == 1)
} catch {
    assert(false)
}

do {
    let _ = try Exc.returnInteger(do_throw: true)
    assert(false)
} catch is StdOutOfRange {
} catch {
    assert(false)
}

func logger(err_msg : String) -> Void {
    print("Log uncaught exception with user defined logger: \(err_msg)")
}

func genUncaughtExceptions() {
    ExceptionHandler.setUncaughtExceptionHandler(logger)
    Exc.noop()
    ExceptionHandler.unsetUncaughtExceptionHandler()
}

genUncaughtExceptions()

do {
    try Exc.raiseErrorByType(err_type: "system")
} catch let err as SystemError {
    assert(err.what() == "system error")
} catch {
    assert(false)
}

do {
    try Exc.raiseErrorByType(err_type: "file")
} catch let err as FileError {
    assert(err.what() == "file error")
} catch {
    assert(false)
}

do {
    try Exc.raiseErrorByType(err_type: "file")
} catch let err as SystemError {
    assert(err.what() == "file error")
} catch {
    assert(false)
}

do {
    try Exc.raiseErrorByType(err_type: "runtime")
} catch let err as StdRuntimeError {
    assert(err.what() == "runtime error")
} catch {
    assert(false)
}

do {
    try Exc.raiseErrorByType(err_type: "runtime")
} catch let err as StdException {
    assert(err.what() == "runtime error")
} catch {
    assert(false)
}

do {
    try Exc.raiseErrorByType(err_type: "simple_child")
} catch let err as SimpleChildException {
    assert(err.errNum() == 100)
} catch {
    assert(false)
}

do {
    try Exc.raiseErrorByType(err_type: "simple_base")
} catch let err as SimpleBaseException {
    assert(err.errNum() == 200)
} catch {
    assert(false)
}

do {
    try Exc.raiseErrorByType(err_type: "")
} catch let err as StdException {
    assert(err.what() == "std::exception")
} catch {
    assert(false)
}
