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

public class Square: RhombusFigure, Rectangle {

  public let cself: CObject
  public let owner: Bool

  // internal main initializer
  internal required init(_ _cself: CObject, _ _owner: Bool = false) {
    self.cself = _cself
    self.owner = _owner
  }

  deinit {
    release_Square(cself, owner)
  }

  public convenience init(side: Double) {
    var err = ErrorObj()
    self.init(create_Square(side, &err), true)
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

  public var area: Double {
    get {
      let result = _prop_get_Square_area(cself)
      return result
    }
  }

  public func perimeter() -> Double {

    var err = ErrorObj()
    let result = _func_Square_perimeter(cself, &err)
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
    return result
  }

}
