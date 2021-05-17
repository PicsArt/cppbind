import Foundation

import CWrapper

/**
 * This class contains a private string field and getter/setter methods for it.
 */
public class Person  {
    
    public let cself : UnsafeMutableRawPointer
    public let owner : Bool

    // internal main initializer
    internal required init(_ _cself: UnsafeMutableRawPointer , _ _owner: Bool = false) {
      self.cself = _cself
      self.owner = _owner
    }
    deinit {
      if owner {
        release_Person(cself)
      }
    }
    
    /**
     */
    public convenience init(name: String, email: String, age: Int) {

        let swift_to_sc_name = strdup(name)!
        let swift_to_sc_email = strdup(email)!
        let swift_to_sc_age = CInt(age)
        self.init(create_Person(swift_to_sc_name, swift_to_sc_email, swift_to_sc_age), true)
    }
    
    /**
     */
    public var fullName: String {
          get {
            let result = _prop_get_Person_fullName(cself);
            let sc_to_swift_result = String(cString: result)
            defer{
              result.deallocate()
            }
            return sc_to_swift_result
          }
          
          
          set(value) {
            let swift_to_sc_value = strdup(value)!
            _prop_set_Person_setFullName(cself, swift_to_sc_value)
          }
          
    }

    /**
     */
    public var email: String {
          get {
            let result = _prop_get_Person_email(cself);
            let sc_to_swift_result = String(cString: result)
            defer{
              result.deallocate()
            }
            return sc_to_swift_result
          }
          
          
          set(value) {
            let swift_to_sc_value = strdup(value)!
            _prop_set_Person_email(cself, swift_to_sc_value)
          }
          
    }

    /**
     */
    public var age: Int {
          get {
            let result = _prop_get_Person_age(cself);
            let sc_to_swift_result = Int(result)
            return sc_to_swift_result
          }
          
          
          set(value) {
            let swift_to_sc_value = CInt(value)
            _prop_set_Person_age(cself, swift_to_sc_value)
          }
          
    }
    
}