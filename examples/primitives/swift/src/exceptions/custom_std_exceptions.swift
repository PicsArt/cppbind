/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 03/29/2022-15:47.
 * Please do not change it manually.
 */

import CWrapper
import Foundation

public class SystemError: StdException {
  /**
   * comments
   * 
   */
  public convenience init(message: String) {
    let swifttoscmessage = strdup(message)!
    var iegenErr = IEGenCObject()
    self.init(create_IegenExample_SystemError(swifttoscmessage, &iegenErr), true)
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
  public override func what() -> String {

    var iegenErr = IEGenCObject()
    let result = _func_IegenExample_SystemError_what(cself, &iegenErr)
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
    let sctoswiftresult = String(cString: result)
    return sctoswiftresult
  }

  override class func iegenDowncast(_ iegenObj: IEGenCObject, _ owner: Bool = false) -> SystemError {
    let typeName = String(cString: iegenObj.type)
    switch(typeName) {
    case("iegen::example::FileError"):
      return FileError(iegenObj, owner)
    default:
      return SystemError(iegenObj, owner)
    }
  }
}

public class FileError: SystemError {
  public convenience init(message: String) {
    let swifttoscmessage = strdup(message)!
    var iegenErr = IEGenCObject()
    self.init(create_IegenExample_FileError(swifttoscmessage, &iegenErr), true)
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
  public override func what() -> String {

    var iegenErr = IEGenCObject()
    let result = _func_IegenExample_FileError_what(cself, &iegenErr)
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
    let sctoswiftresult = String(cString: result)
    return sctoswiftresult
  }

}
