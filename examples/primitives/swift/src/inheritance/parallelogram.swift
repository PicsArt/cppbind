/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 03/30/2022-09:24.
 * Please do not change it manually.
 */

import CWrapper
import Foundation

public protocol Parallelogram {
  var cself: IEGenCObject { get }

  func keepIEGenReference(_ object: Any)
  var area: Double { get }
  func perimeter() -> Double
  func equals(p: Parallelogram) -> Bool
}

extension Parallelogram {
  public var area: Double {
    var iegenErr = IEGenCObject()
    let result = _prop_get_IegenExample_Parallelogram_area(cself, &iegenErr)
    if iegenErr.type != nil {
      let errorType = String(cString: iegenErr.type!)
      switch errorType {
      case ("std::exception"):
        let excObj = StdException(iegenErr, true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        iegenErr.type.deallocate()
        ExceptionHandler.handleUncaughtException("Uncaught Exception")
      }
    }
    return result
  }

  public func perimeter() -> Double {

    var iegenErr = IEGenCObject()
    let result = _func_IegenExample_Parallelogram_perimeter(cself, &iegenErr)
    if iegenErr.type != nil {
      let errorType = String(cString: iegenErr.type!)
      switch errorType {
      case ("std::exception"):
        let excObj = StdException(iegenErr, true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        iegenErr.type.deallocate()
        ExceptionHandler.handleUncaughtException("Uncaught Exception")
      }
    }
    return result
  }

  public func equals(p: Parallelogram) -> Bool {

    let swifttoscp = p.cself
    var iegenErr = IEGenCObject()
    let result = _func_IegenExample_Parallelogram_equals(cself, swifttoscp, &iegenErr)
    if iegenErr.type != nil {
      let errorType = String(cString: iegenErr.type!)
      switch errorType {
      case ("std::exception"):
        let excObj = StdException(iegenErr, true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        iegenErr.type.deallocate()
        ExceptionHandler.handleUncaughtException("Uncaught Exception")
      }
    }
    return result
  }

}

public class ParallelogramImpl: Parallelogram {
  public let cself: IEGenCObject
  public let owner: Bool
  private var refs: [Any]

  // internal main initializer
  internal required init(_ _cself: IEGenCObject, _ _owner: Bool = false) {
    self.cself = _cself
    self.owner = _owner
    self.refs = []
  }

  deinit {
    release_IegenExample_ParallelogramImpl(cself, owner)
  }

  public func keepIEGenReference(_ object: Any) {
    self.refs.append(object)
  }

  class func iegenDowncast(_ iegenObj: IEGenCObject, _ owner: Bool = false) -> Parallelogram {
    let typeName = String(cString: iegenObj.type)
    switch(typeName) {
    case("iegen::example::Rectangle"):
      return RectangleImpl(iegenObj, owner)
    case("iegen::example::Rhombus"):
      return RhombusFigureImpl(iegenObj, owner)
    case("iegen::example::Square"):
      return Square(iegenObj, owner)
    default:
      return ParallelogramImpl(iegenObj, owner)
    }
  }
}
