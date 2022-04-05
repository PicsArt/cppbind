/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 04/05/2022-12:52.
 * Please do not change it manually.
 */

import CWrapper
import Foundation

public class SimpleBaseException : Error {

  public let cself: IEGenCObject
  public let owner: Bool
  private var refs: [Any]

  /// internal main initializer
  internal required init(_ _cself: IEGenCObject, _ _owner: Bool = false) {
    self.cself = _cself
    self.owner = _owner
    self.refs = []
  }

  /// internal private initializer to prevent automatic initializer inheritance
  private init(_ _cself: IEGenCObject, _ _owner: Bool, _ _refs: [Any]) {
    fatalError("A private initializer should not be called.")
  }

  deinit {
    release_IegenExample_SimpleBaseException(cself, owner)
  }

  public func keepIEGenReference(_ object: Any) {
    self.refs.append(object)
  }

  public convenience init(errNum: Int) {
    let swifttoscerrNum = CInt(errNum)
    var iegenErr = IEGenCObject()
    self.init(create_IegenExample_SimpleBaseException(swifttoscerrNum, &iegenErr), true)
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

  public func errNum() -> Int {

    var iegenErr = IEGenCObject()
    let result = _func_IegenExample_SimpleBaseException_errNum(cself, &iegenErr)
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
    let sctoswiftresult = Int(result)
    return sctoswiftresult
  }

  class func iegenDowncast(_ iegenObj: IEGenCObject, _ owner: Bool = false) -> SimpleBaseException {
    let typeName = String(cString: iegenObj.type)
    switch(typeName) {
    case("iegen::example::SimpleChildException"):
      return SimpleChildException(iegenObj, owner)
    default:
      return SimpleBaseException(iegenObj, owner)
    }
  }
}

public class SimpleChildException: SimpleBaseException {
  /// internal main initializer
  internal required init(_ _cself: IEGenCObject, _ _owner: Bool = false) {
    super.init(_cself, _owner)
  }

  /**
   * comments
   * 
   */
  public convenience init(errNum: Int) {
    let swifttoscerrNum = CInt(errNum)
    var iegenErr = IEGenCObject()
    self.init(create_IegenExample_SimpleChildException(swifttoscerrNum, &iegenErr), true)
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

  /**
   * comments
   * 
   */
  public override func errNum() -> Int {

    var iegenErr = IEGenCObject()
    let result = _func_IegenExample_SimpleChildException_errNum(cself, &iegenErr)
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
    let sctoswiftresult = Int(result)
    return sctoswiftresult
  }

}
