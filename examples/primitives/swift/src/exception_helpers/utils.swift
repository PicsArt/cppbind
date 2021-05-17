public class ExceptionHandler {

    static var uncaughtExceptionHandler = defaultHandler;

    static func defaultHandler(_ err_msg: String) {
        print("Uncaught exception is found: \(err_msg)")
        fatalError("Unexpected Exception")
    }

    static func handleUncaughtException(_ err_msg : String) {
        uncaughtExceptionHandler(err_msg)
    }

    public static func setUncaughtExceptionHandler(_ handler: @escaping (String) -> Void) {
        uncaughtExceptionHandler = handler;
    }

    public static func unsetUncaughtExceptionHandler() {
        uncaughtExceptionHandler = defaultHandler;
    }
}