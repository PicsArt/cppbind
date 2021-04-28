import Foundation

import CWrapper

/**
 * An example for with overloaded methods.
 */
public class OverloadedFunctions  {
    
    public let cself : UnsafeMutableRawPointer
    public let owner : Bool

    // internal main initializer
    internal required init(_ _cself: UnsafeMutableRawPointer , _ _owner: Bool = false) {
      self.cself = _cself
      self.owner = _owner
    }
    deinit {
      if owner {
        release_OverloadedFunctions(cself)
      }
    }
    
    /**
     * Overload constructor
     * 
     */
    public convenience init() {

        self.init(create_OverloadedFunctions(), true)
    }
    
    /**
     * Concatenate with two strings.
     * 
     */
    public func concatenate(first: String, second: String) -> String {

        let swift_to_sc_first = strdup(first)!
        let swift_to_sc_second = strdup(second)!
        let result = _func_OverloadedFunctions_concatenate(cself, swift_to_sc_first, swift_to_sc_second);
        let sc_to_swift_result = String(cString: result)
        defer{
          result.deallocate()
        }
        return sc_to_swift_result;
    }
    /**
     * Concatenate with three strings.
     * 
     */
    public func concatenate(first: String, second: String, third: String) -> String {

        let swift_to_sc_first = strdup(first)!
        let swift_to_sc_second = strdup(second)!
        let swift_to_sc_third = strdup(third)!
        let result = _func_OverloadedFunctions_concatenate_1(cself, swift_to_sc_first, swift_to_sc_second, swift_to_sc_third);
        let sc_to_swift_result = String(cString: result)
        defer{
          result.deallocate()
        }
        return sc_to_swift_result;
    }
}