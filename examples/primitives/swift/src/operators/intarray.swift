/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 10/28/2021-10:49.
 * Please do not change it manually.
 */

import CWrapper
import Foundation
/**
 * An example for with overloaded operators.
 */
public protocol IntArray  {

    
    var cself : UnsafeMutableRawPointer { get }
    
    
    
    
    subscript(i: Int) -> Int { get set }

    subscript(i: String) -> Int { get }

    subscript(i: Double) -> Int { get }
}
extension IntArray {
    
    

    public subscript(i: Int) -> Int {
        get {
            let swift_to_sc_i = CInt(i)
            let result = _func_IntArray_operator_getitem_(cself, swift_to_sc_i)
            let sc_to_swift_result = Int(result)
            return sc_to_swift_result
        }
        
        set(value) {
            let swift_to_sc_i = CInt(i)
            let swift_to_sc_value = CInt(value)
            _func_IntArray_operator_setitem_(cself, swift_to_sc_i, swift_to_sc_value)
        }
    }


    public subscript(i: String) -> Int {
        get {
            let swift_to_sc_i = strdup(i)!
            let result = _func_IntArray_operator_getitem__1(cself, swift_to_sc_i)
            let sc_to_swift_result = Int(result)
            return sc_to_swift_result
        }
    }


    public subscript(i: Double) -> Int {
        get {
            
            let result = _func_IntArray_operator_getitem__2(cself, i)
            let sc_to_swift_result = Int(result)
            return sc_to_swift_result
        }
    }
}
public class IntArrayImpl : IntArray {
    public let cself : UnsafeMutableRawPointer
    public let owner : Bool

    // internal main initializer
    internal required init(_ _cself: UnsafeMutableRawPointer, _ _owner: Bool = false) {
      self.cself = _cself
      self.owner = _owner
    }
    deinit {
      if owner {
        release_IntArrayImpl(cself)
      }
    }

    
    public convenience init() {

        self.init(create_IntArray(), true)
    }
}