import Foundation

import CWrapper

/**
 * An example with overloaded methods.
 */
public class Utils  {
    
    public let cself : UnsafeMutableRawPointer
    public let owner : Bool

    // internal main initializer
    internal required init(_ _cself: UnsafeMutableRawPointer , _ _owner: Bool = false) {
      self.cself = _cself
      self.owner = _owner
    }
    deinit {
      if owner {
        release_Utils(cself)
      }
    }
    
    /**
     */
    public convenience init() {

        self.init(create_Utils(), true)
    }
    
    /**
     * Sum two ints.
     */
    public static func sum(first: Int, second: Int) -> Int {

        let swift_to_sc_first = CInt(first)
        let swift_to_sc_second = CInt(second)
        let result = _func_Utils_sum(swift_to_sc_first, swift_to_sc_second);
        let sc_to_swift_result = Int(result)
        return sc_to_swift_result;
    }
    /**
     * Sum two floats.
     */
    public static func sum(first: Float, second: Float) -> Float {

        
        
        let result = _func_Utils_sum_1(first, second);
        
        return result;
    }
    /**
     * Concatenate with two strings.
     */
    public func concatenate(first: String, second: String) -> String {

        let swift_to_sc_first = strdup(first)!
        let swift_to_sc_second = strdup(second)!
        let result = _func_Utils_concatenate(cself, swift_to_sc_first, swift_to_sc_second);
        let sc_to_swift_result = String(cString: result)
        defer{
          result.deallocate()
        }
        return sc_to_swift_result;
    }
    /**
     * Concatenate with three strings.
     */
    public func concatenate(first: String, second: String, third: String) -> String {

        let swift_to_sc_first = strdup(first)!
        let swift_to_sc_second = strdup(second)!
        let swift_to_sc_third = strdup(third)!
        let result = _func_Utils_concatenate_1(cself, swift_to_sc_first, swift_to_sc_second, swift_to_sc_third);
        let sc_to_swift_result = String(cString: result)
        defer{
          result.deallocate()
        }
        return sc_to_swift_result;
    }
}