/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 07/12/2021-09:14.
 * Please do not change it manually.
 */

import Foundation
import CWrapper



/**
 * comments
 * 
 */
public class StackProject  {
    
    public let cself : UnsafeMutableRawPointer
    public let owner : Bool

    // internal main initializer
    internal required init(_ _cself: UnsafeMutableRawPointer, _ _owner: Bool = false) {
      self.cself = _cself
      self.owner = _owner
    }
    deinit {
      if owner {
        release_StackProject(cself)
      }
    }
    
    
    public convenience init() {

        self.init(create_StackProject(), true)
    }

    public convenience init(st: Project) {

        let swift_to_sc_st = st.cself
        self.init(create_StackProject_1(swift_to_sc_st), true)
    }
    
    
    public func push(item: Project) -> Void {

        let swift_to_sc_item = item.cself
        var err = ErrorObj()
        _func_StackProject_push(cself, swift_to_sc_item, &err);
        if (err.is_err) {
            let err_type = Int(err.err_type)
            switch(err_type) {
                case(1):
                    let exc_obj = Exceptions.StdException(err.err_ptr, true)
                    ExceptionHandler.handleUncaughtException(exc_obj.what())
                default:
                    ExceptionHandler.handleUncaughtException("Uncaught Exception")
            }
        }
    }

    public func pop() -> Void {

        var err = ErrorObj()
        _func_StackProject_pop(cself, &err);
        if (err.is_err) {
            let err_type = Int(err.err_type)
            switch(err_type) {
                case(1):
                    let exc_obj = Exceptions.StdException(err.err_ptr, true)
                    ExceptionHandler.handleUncaughtException(exc_obj.what())
                default:
                    ExceptionHandler.handleUncaughtException("Uncaught Exception")
            }
        }
    }

    public func top() -> Project {

        var err = ErrorObj()
        let result = _func_StackProject_top(cself, &err);
        let sc_to_swift_result = Project(result)
        if (err.is_err) {
            let err_type = Int(err.err_type)
            switch(err_type) {
                case(1):
                    let exc_obj = Exceptions.StdException(err.err_ptr, true)
                    ExceptionHandler.handleUncaughtException(exc_obj.what())
                default:
                    ExceptionHandler.handleUncaughtException("Uncaught Exception")
            }
        }
        return sc_to_swift_result;
    }

    public func empty() -> Bool {

        var err = ErrorObj()
        let result = _func_StackProject_empty(cself, &err);
        
        if (err.is_err) {
            let err_type = Int(err.err_type)
            switch(err_type) {
                case(1):
                    let exc_obj = Exceptions.StdException(err.err_ptr, true)
                    ExceptionHandler.handleUncaughtException(exc_obj.what())
                default:
                    ExceptionHandler.handleUncaughtException("Uncaught Exception")
            }
        }
        return result;
    }
}
/**
 * comments
 * 
 */
public class StackTask  {
    
    public let cself : UnsafeMutableRawPointer
    public let owner : Bool

    // internal main initializer
    internal required init(_ _cself: UnsafeMutableRawPointer, _ _owner: Bool = false) {
      self.cself = _cself
      self.owner = _owner
    }
    deinit {
      if owner {
        release_StackTask(cself)
      }
    }
    
    
    public convenience init() {

        self.init(create_StackTask(), true)
    }

    public convenience init(st: Task) {

        let swift_to_sc_st = st.cself
        self.init(create_StackTask_1(swift_to_sc_st), true)
    }
    
    
    public func push(item: Task) -> Void {

        let swift_to_sc_item = item.cself
        var err = ErrorObj()
        _func_StackTask_push(cself, swift_to_sc_item, &err);
        if (err.is_err) {
            let err_type = Int(err.err_type)
            switch(err_type) {
                case(1):
                    let exc_obj = Exceptions.StdException(err.err_ptr, true)
                    ExceptionHandler.handleUncaughtException(exc_obj.what())
                default:
                    ExceptionHandler.handleUncaughtException("Uncaught Exception")
            }
        }
    }

    public func pop() -> Void {

        var err = ErrorObj()
        _func_StackTask_pop(cself, &err);
        if (err.is_err) {
            let err_type = Int(err.err_type)
            switch(err_type) {
                case(1):
                    let exc_obj = Exceptions.StdException(err.err_ptr, true)
                    ExceptionHandler.handleUncaughtException(exc_obj.what())
                default:
                    ExceptionHandler.handleUncaughtException("Uncaught Exception")
            }
        }
    }

    public func top() -> Task {

        var err = ErrorObj()
        let result = _func_StackTask_top(cself, &err);
        let sc_to_swift_result = Task(result)
        if (err.is_err) {
            let err_type = Int(err.err_type)
            switch(err_type) {
                case(1):
                    let exc_obj = Exceptions.StdException(err.err_ptr, true)
                    ExceptionHandler.handleUncaughtException(exc_obj.what())
                default:
                    ExceptionHandler.handleUncaughtException("Uncaught Exception")
            }
        }
        return sc_to_swift_result;
    }

    public func empty() -> Bool {

        var err = ErrorObj()
        let result = _func_StackTask_empty(cself, &err);
        
        if (err.is_err) {
            let err_type = Int(err.err_type)
            switch(err_type) {
                case(1):
                    let exc_obj = Exceptions.StdException(err.err_ptr, true)
                    ExceptionHandler.handleUncaughtException(exc_obj.what())
                default:
                    ExceptionHandler.handleUncaughtException("Uncaught Exception")
            }
        }
        return result;
    }
}