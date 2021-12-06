/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 11/25/2021-10:01.
 * Please do not change it manually.
 */

import CWrapper
import Foundation
/**
 * This class contains a private string field and getter/setter methods for it.
 */
public class Person  {
    
    public let cself : UnsafeMutableRawPointer
    public let owner : Bool

    // internal main initializer
    internal required init(_ _cself: UnsafeMutableRawPointer, _ _owner: Bool = false) {
        self.cself = _cself
        self.owner = _owner
    }
    deinit {
        if owner {
            release_Person(cself)
        }
    }
    
    
    public convenience init(name: String, email: String, age: Int) {

        let swift_to_sc_name = strdup(name)!
        let swift_to_sc_email = strdup(email)!
        let swift_to_sc_age = CInt(age)
        var err = ErrorObj()
        self.init(create_Person(swift_to_sc_name, swift_to_sc_email, swift_to_sc_age, &err), true)
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
    
    public var name: String {
        get {
            let result = _prop_get_Person_name(cself)
            let sc_to_swift_result = String(cString: result)
            defer {
              result.deallocate()
            }
            return sc_to_swift_result
        }
        
        
        set(value) {
            let swift_to_sc_value = strdup(value)!
            _prop_set_Person_name(cself, swift_to_sc_value)
        }
        
    }


    public var email: String {
        get {
            let result = _prop_get_Person_email(cself)
            let sc_to_swift_result = String(cString: result)
            defer {
              result.deallocate()
            }
            return sc_to_swift_result
        }
    }


    public var age: Int {
        get {
            let result = _prop_get_Person_age(cself)
            let sc_to_swift_result = Int(result)
            return sc_to_swift_result
        }
        
        set(value) {
            let swift_to_sc_value = CInt(value)
            _prop_set_Person_age(cself, swift_to_sc_value)
        }
        
    }
    
}