/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 12/08/2021-11:58.
 * Please do not change it manually.
 */

import CWrapper
import Foundation

/**
 * An example for with overloaded operators.
 */
public protocol IntArray {
  var cself: CObject { get }

  subscript(i: Int) -> Int { get set }
  subscript(i: String) -> Int { get }
  subscript(i: Double) -> Int { get }
}

extension IntArray {
  
  public subscript(i: Int) -> Int {
    get {
      let swifttosci = CInt(i)
      let result = _func_IntArray_operator_getitem_(cself, swifttosci)
      let sctoswiftresult = Int(result)
      return sctoswiftresult
    }

    set(value) {
      let swifttosci = CInt(i)
      let swifttoscvalue = CInt(value)
      _func_IntArray_operator_setitem_(cself, swifttosci, swifttoscvalue)
    }
  }


  public subscript(i: String) -> Int {
    get {
      let swifttosci = strdup(i)!
      let result = _func_IntArray_operator_getitem__1(cself, swifttosci)
      let sctoswiftresult = Int(result)
      return sctoswiftresult
    }
  }


  public subscript(i: Double) -> Int {
    get {
      let result = _func_IntArray_operator_getitem__2(cself, i)
      let sctoswiftresult = Int(result)
      return sctoswiftresult
    }
  }

}

public class IntArrayImpl: IntArray {
  public let cself: CObject
  public let owner: Bool

  // internal main initializer
  internal required init(_ _cself: CObject, _ _owner: Bool = false) {
    self.cself = _cself
    self.owner = _owner
  }

  deinit {
    release_IntArrayImpl(cself, owner)
  }

  public convenience init() {
    var err = ErrorObj()
    self.init(create_IntArray(&err), true)
    let errorType = Int(err.err_type)
    if errorType != 0 {
      switch errorType {
      case (1):
        let excObj = StdException(CObject(type: strdup("std::exception"), ptr: err.err_ptr), true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        ExceptionHandler.handleUncaughtException("Uncaught Exception")
      }
    }
  }

}