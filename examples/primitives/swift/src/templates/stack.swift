/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 12/06/2021-14:37.
 * Please do not change it manually.
 */

import CWrapper
import Foundation
/**
 * comments
 * 
 */
public class StackPrj : Container {
    
    public let cself : CObject
    public let owner : Bool

    // internal main initializer
    internal required init(_ _cself: CObject, _ _owner: Bool = false) {
        self.cself = _cself
        self.owner = _owner
    }
    deinit {
        if owner {
            release_StackPrj(cself)
            cself.type?.deallocate()
        }
    }
    
    
    public convenience init() {

        var err = ErrorObj()
        self.init(create_StackPrj(&err), true)
        let err_type = Int(err.err_type)
        if (err_type != 0) {
            switch(err_type) {
                case(1):
                    let exc_obj = StdException(err.err_ptr, true)
                    ExceptionHandler.handleUncaughtException(exc_obj.what())
                default:
                    ExceptionHandler.handleUncaughtException("Uncaught Exception")
            }
        }
    }

    public convenience init(st: Project) {

        let swift_to_sc_st = st.cself
        var err = ErrorObj()
        self.init(create_StackPrj_1(swift_to_sc_st, &err), true)
        let err_type = Int(err.err_type)
        if (err_type != 0) {
            switch(err_type) {
                case(1):
                    let exc_obj = StdException(err.err_ptr, true)
                    ExceptionHandler.handleUncaughtException(exc_obj.what())
                default:
                    ExceptionHandler.handleUncaughtException("Uncaught Exception")
            }
        }
    }
    
    
    public func push(item: Project) -> Void {

        let swift_to_sc_item = item.cself
        var err = ErrorObj()
        _func_StackPrj_push(cself, swift_to_sc_item, &err)
        let err_type = Int(err.err_type)
        if (err_type != 0) {
            switch(err_type) {
                case(1):
                    let exc_obj = StdException(CObject(type: nil, ptr: err.err_ptr), true)
                    ExceptionHandler.handleUncaughtException(exc_obj.what())
                default:
                    ExceptionHandler.handleUncaughtException("Uncaught Exception")
            }
        }
    }

    public func pop() -> Void {

        var err = ErrorObj()
        _func_StackPrj_pop(cself, &err)
        let err_type = Int(err.err_type)
        if (err_type != 0) {
            switch(err_type) {
                case(1):
                    let exc_obj = StdException(CObject(type: nil, ptr: err.err_ptr), true)
                    ExceptionHandler.handleUncaughtException(exc_obj.what())
                default:
                    ExceptionHandler.handleUncaughtException("Uncaught Exception")
            }
        }
    }

    public func top() -> Project {

        var err = ErrorObj()
        let result = _func_StackPrj_top(cself, &err)
        let err_type = Int(err.err_type)
        if (err_type != 0) {
            switch(err_type) {
                case(1):
                    let exc_obj = StdException(CObject(type: nil, ptr: err.err_ptr), true)
                    ExceptionHandler.handleUncaughtException(exc_obj.what())
                default:
                    ExceptionHandler.handleUncaughtException("Uncaught Exception")
            }
        }
      var sc_to_swift_result: Project
        sc_to_swift_result = Project(result)
      return sc_to_swift_result
    }

    public func empty() -> Bool {

        var err = ErrorObj()
        let result = _func_StackPrj_empty(cself, &err)
        let err_type = Int(err.err_type)
        if (err_type != 0) {
            switch(err_type) {
                case(1):
                    let exc_obj = StdException(CObject(type: nil, ptr: err.err_ptr), true)
                    ExceptionHandler.handleUncaughtException(exc_obj.what())
                default:
                    ExceptionHandler.handleUncaughtException("Uncaught Exception")
            }
        }
      
      return result
    }
}
/**
 * comments
 * 
 */
public class StackTask : Container {
    
    public let cself : CObject
    public let owner : Bool

    // internal main initializer
    internal required init(_ _cself: CObject, _ _owner: Bool = false) {
        self.cself = _cself
        self.owner = _owner
    }
    deinit {
        if owner {
            release_StackTask(cself)
            cself.type?.deallocate()
        }
    }
    
    
    public convenience init() {

        var err = ErrorObj()
        self.init(create_StackTask(&err), true)
        let err_type = Int(err.err_type)
        if (err_type != 0) {
            switch(err_type) {
                case(1):
                    let exc_obj = StdException(err.err_ptr, true)
                    ExceptionHandler.handleUncaughtException(exc_obj.what())
                default:
                    ExceptionHandler.handleUncaughtException("Uncaught Exception")
            }
        }
    }

    public convenience init(st: Task) {

        let swift_to_sc_st = st.cself
        var err = ErrorObj()
        self.init(create_StackTask_1(swift_to_sc_st, &err), true)
        let err_type = Int(err.err_type)
        if (err_type != 0) {
            switch(err_type) {
                case(1):
                    let exc_obj = StdException(err.err_ptr, true)
                    ExceptionHandler.handleUncaughtException(exc_obj.what())
                default:
                    ExceptionHandler.handleUncaughtException("Uncaught Exception")
            }
        }
    }
    
    
    public func push(item: Task) -> Void {

        let swift_to_sc_item = item.cself
        var err = ErrorObj()
        _func_StackTask_push(cself, swift_to_sc_item, &err)
        let err_type = Int(err.err_type)
        if (err_type != 0) {
            switch(err_type) {
                case(1):
                    let exc_obj = StdException(CObject(type: nil, ptr: err.err_ptr), true)
                    ExceptionHandler.handleUncaughtException(exc_obj.what())
                default:
                    ExceptionHandler.handleUncaughtException("Uncaught Exception")
            }
        }
    }

    public func pop() -> Void {

        var err = ErrorObj()
        _func_StackTask_pop(cself, &err)
        let err_type = Int(err.err_type)
        if (err_type != 0) {
            switch(err_type) {
                case(1):
                    let exc_obj = StdException(CObject(type: nil, ptr: err.err_ptr), true)
                    ExceptionHandler.handleUncaughtException(exc_obj.what())
                default:
                    ExceptionHandler.handleUncaughtException("Uncaught Exception")
            }
        }
    }

    public func top() -> Task {

        var err = ErrorObj()
        let result = _func_StackTask_top(cself, &err)
        let err_type = Int(err.err_type)
        if (err_type != 0) {
            switch(err_type) {
                case(1):
                    let exc_obj = StdException(CObject(type: nil, ptr: err.err_ptr), true)
                    ExceptionHandler.handleUncaughtException(exc_obj.what())
                default:
                    ExceptionHandler.handleUncaughtException("Uncaught Exception")
            }
        }
      var sc_to_swift_result: Task
        sc_to_swift_result = Task(result)
      return sc_to_swift_result
    }

    public func empty() -> Bool {

        var err = ErrorObj()
        let result = _func_StackTask_empty(cself, &err)
        let err_type = Int(err.err_type)
        if (err_type != 0) {
            switch(err_type) {
                case(1):
                    let exc_obj = StdException(CObject(type: nil, ptr: err.err_ptr), true)
                    ExceptionHandler.handleUncaughtException(exc_obj.what())
                default:
                    ExceptionHandler.handleUncaughtException("Uncaught Exception")
            }
        }
      
      return result
    }
}
/**
 * comments
 * 
 */
public class StackNumInt : Container {
    
    public let cself : CObject
    public let owner : Bool

    // internal main initializer
    internal required init(_ _cself: CObject, _ _owner: Bool = false) {
        self.cself = _cself
        self.owner = _owner
    }
    deinit {
        if owner {
            release_StackNumInt(cself)
            cself.type?.deallocate()
        }
    }
    
    
    public convenience init() {

        var err = ErrorObj()
        self.init(create_StackNumInt(&err), true)
        let err_type = Int(err.err_type)
        if (err_type != 0) {
            switch(err_type) {
                case(1):
                    let exc_obj = StdException(err.err_ptr, true)
                    ExceptionHandler.handleUncaughtException(exc_obj.what())
                default:
                    ExceptionHandler.handleUncaughtException("Uncaught Exception")
            }
        }
    }

    public convenience init(st: NumberInt) {

        let swift_to_sc_st = st.cself
        var err = ErrorObj()
        self.init(create_StackNumInt_1(swift_to_sc_st, &err), true)
        let err_type = Int(err.err_type)
        if (err_type != 0) {
            switch(err_type) {
                case(1):
                    let exc_obj = StdException(err.err_ptr, true)
                    ExceptionHandler.handleUncaughtException(exc_obj.what())
                default:
                    ExceptionHandler.handleUncaughtException("Uncaught Exception")
            }
        }
    }
    
    
    public func push(item: NumberInt) -> Void {

        let swift_to_sc_item = item.cself
        var err = ErrorObj()
        _func_StackNumInt_push(cself, swift_to_sc_item, &err)
        let err_type = Int(err.err_type)
        if (err_type != 0) {
            switch(err_type) {
                case(1):
                    let exc_obj = StdException(CObject(type: nil, ptr: err.err_ptr), true)
                    ExceptionHandler.handleUncaughtException(exc_obj.what())
                default:
                    ExceptionHandler.handleUncaughtException("Uncaught Exception")
            }
        }
    }

    public func pop() -> Void {

        var err = ErrorObj()
        _func_StackNumInt_pop(cself, &err)
        let err_type = Int(err.err_type)
        if (err_type != 0) {
            switch(err_type) {
                case(1):
                    let exc_obj = StdException(CObject(type: nil, ptr: err.err_ptr), true)
                    ExceptionHandler.handleUncaughtException(exc_obj.what())
                default:
                    ExceptionHandler.handleUncaughtException("Uncaught Exception")
            }
        }
    }

    public func top() -> NumberInt {

        var err = ErrorObj()
        let result = _func_StackNumInt_top(cself, &err)
        let err_type = Int(err.err_type)
        if (err_type != 0) {
            switch(err_type) {
                case(1):
                    let exc_obj = StdException(CObject(type: nil, ptr: err.err_ptr), true)
                    ExceptionHandler.handleUncaughtException(exc_obj.what())
                default:
                    ExceptionHandler.handleUncaughtException("Uncaught Exception")
            }
        }
      var sc_to_swift_result: NumberInt
        sc_to_swift_result = NumberInt(result)
      return sc_to_swift_result
    }

    public func empty() -> Bool {

        var err = ErrorObj()
        let result = _func_StackNumInt_empty(cself, &err)
        let err_type = Int(err.err_type)
        if (err_type != 0) {
            switch(err_type) {
                case(1):
                    let exc_obj = StdException(CObject(type: nil, ptr: err.err_ptr), true)
                    ExceptionHandler.handleUncaughtException(exc_obj.what())
                default:
                    ExceptionHandler.handleUncaughtException("Uncaught Exception")
            }
        }
      
      return result
    }
}