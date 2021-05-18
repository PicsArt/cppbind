/*
 * This file was generated by iegen on 05/18/2021-13:33.
 * Please do not change it manually.
 */

import Foundation

import CWrapper

/**
 * An example for with overloaded methods.
 */
public class Counter  {
    
    public let cself : UnsafeMutableRawPointer
    public let owner : Bool

    // internal main initializer
    internal required init(_ _cself: UnsafeMutableRawPointer , _ _owner: Bool = false) {
      self.cself = _cself
      self.owner = _owner
    }
    deinit {
      if owner {
        release_Counter(cself)
      }
    }
    
    /**
     * Counter constructor.
     */
    public convenience init(count: Int) {

        let swift_to_sc_count = CInt(count)
        self.init(create_Counter(swift_to_sc_count), true)
    }
    
    /**
     * Getter for count.
     */
    public var count: Int {
          get {
            let result = _prop_get_Counter_count(cself);
            let sc_to_swift_result = Int(result)
            return sc_to_swift_result
          }
          
    }
    /**
     * Plus operator
     */
    public static func +(cself: Counter, counter: Counter) -> Counter {
        let swift_to_sc_counter = counter.cself
        var err = ErrorObj()
        let result = _func_Counter_operator_add_(cself.cself, swift_to_sc_counter, &err);
        let sc_to_swift_result = Counter(result, true)
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
    /**
     * Comparison operator for kotlin
     */
    public func compareTo(counter: Counter) -> Int {

        let swift_to_sc_counter = counter.cself
        var err = ErrorObj()
        let result = _func_Counter_compareTo(cself, swift_to_sc_counter, &err);
        let sc_to_swift_result = Int(result)
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
    /**
     */
    public static func >(cself: Counter, counter: Counter) -> Bool {
        let swift_to_sc_counter = counter.cself
        var err = ErrorObj()
        let result = _func_Counter_operator_gt_(cself.cself, swift_to_sc_counter, &err);
        
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
    /**
     */
    public static func +=(cself: Counter, counter: Counter) -> Counter {
        let swift_to_sc_counter = counter.cself
        var err = ErrorObj()
        let result = _func_Counter_operator_iadd_(cself.cself, swift_to_sc_counter, &err);
        let sc_to_swift_result = Counter(result)
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
}