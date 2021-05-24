import CWrapper
public enum Exceptions {

    open class StdException : Error {

        public let cself : UnsafeMutableRawPointer
        public let owner : Bool

        public init(_ _cself: UnsafeMutableRawPointer, _ _owner: Bool = false) {
            self.cself = _cself
            self.owner = _owner
        }
        deinit {
            if owner {
                release_std_exception(cself)
            }
        }

        open func what() -> String {
            let result = _func_std_exception_what(cself);
            let sc_to_swift_result = String(cString: result!)
            return sc_to_swift_result;
        }

    }

    public class StdRuntimeError : StdException {

    }

    public class StdLogicError : StdException {

    }

    public class StdBadAlloc : StdException {

    }

    public class StdBadCast : StdException {

    }

    public class StdBadTypeid : StdException {

    }

    public class StdBadException : StdException {

    }

    public class StdOverflowError : StdRuntimeError {

    }

    public class StdRangeError : StdRuntimeError {

    }

    public class StdUnderflowError : StdRuntimeError {

    }

    public class StdInvalidArgument : StdLogicError {

    }

    public class StdLengthError : StdLogicError {

    }

    public class StdOutOfRange : StdLogicError {

    }

    public class StdDomainError : StdLogicError {

    }

}