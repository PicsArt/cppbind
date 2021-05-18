/*
 * This file was generated by iegen on 05/18/2021-13:33.
 * Please do not change it manually.
 */

import Foundation

import CWrapper

/**
 * comments
 * 
 */
public class Teacher  {
    
    public let cself : UnsafeMutableRawPointer
    public let owner : Bool

    // internal main initializer
    internal required init(_ _cself: UnsafeMutableRawPointer , _ _owner: Bool = false) {
      self.cself = _cself
      self.owner = _owner
    }
    deinit {
      if owner {
        release_Teacher(cself)
      }
    }
    
    /**
     */
    public convenience init() {

        self.init(create_Teacher(), true)
    }
    
    /**
     */
    public func addStudent(s: Student) -> Void {

        let swift_to_sc_s = s.cself
        var err = ErrorObj()
        _func_Teacher_addStudent(cself, swift_to_sc_s, &err);
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
    /**
     */
    public func students() -> Array<Student> {

        var err = ErrorObj()
        let result = _func_Teacher_students(cself, &err);
        let _tmp_result_data = UnsafeBufferPointer<UnsafeMutableRawPointer>(start: result.data.assumingMemoryBound(to: UnsafeMutableRawPointer.self), count: Int(result.size))
        var sc_to_swift_result: [Student] = [] 
        defer {
          _tmp_result_data.deallocate()
        }
        for _i in 0..<Int(result.size) {
          let value_result = _tmp_result_data[_i];
          let sc_to_swift_value_result = Student(value_result)
          sc_to_swift_result.append(sc_to_swift_value_result);
        }
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