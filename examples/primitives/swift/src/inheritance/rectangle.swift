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

public protocol Rectangle: Parallelogram {
  var area: Double { get }
  var length: Double { get }
  var width: Double { get }
}

extension Rectangle {
  public var area: Double {
    var iegenErr = IEGenCObject()
    let result = _prop_get_IegenExample_Rectangle_area(cself, &iegenErr)
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

  public var length: Double {
    var iegenErr = IEGenCObject()
    let result = _prop_get_IegenExample_Rectangle_length(cself, &iegenErr)
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

  public var width: Double {
    var iegenErr = IEGenCObject()
    let result = _prop_get_IegenExample_Rectangle_width(cself, &iegenErr)
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

public class RectangleImpl: Rectangle {
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
    release_IegenExample_RectangleImpl(cself, owner)
  }

  public func keepIEGenReference(_ object: Any) {
    self.refs.append(object)
  }

  public convenience init(length: Double, width: Double) {
    var iegenErr = IEGenCObject()
    self.init(create_IegenExample_Rectangle(length, width, &iegenErr), true)
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
  }

  class func iegenDowncast(_ iegenObj: IEGenCObject, _ owner: Bool = false) -> Rectangle {
    let typeName = String(cString: iegenObj.type)
    switch(typeName) {
    case("iegen::example::Square"):
      return Square(iegenObj, owner)
    default:
      return RectangleImpl(iegenObj, owner)
    }
  }
}
