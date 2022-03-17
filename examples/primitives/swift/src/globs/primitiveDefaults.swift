/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 03/06/2022-18:54.
 * Please do not change it manually.
 */

import CWrapper
import Foundation

/**
 * A global function with enum default argument.
 */
public func optionalColor(c: Color = Color.Red) -> Color {
  let swifttoscc = c.rawValue
  var err = IEGenCObject()
  let result = _func__optionalColor(swifttoscc, &err)
  if err.type != nil {
    let errorType = String(cString: err.type!)
    switch errorType {
    case ("std::exception"):
      let excObj = StdException(err, true)
      ExceptionHandler.handleUncaughtException(excObj.what())
    default:
      err.type.deallocate()
      ExceptionHandler.handleUncaughtException("Uncaught Exception")
    }
  }
  guard let sctoswiftresult = Color(rawValue: result) else {
     ExceptionHandler.handleUncaughtException(
        "Internal error: unresolved reference to non existing field of Color enum.")
  }
  return sctoswiftresult
}

/**
 * A global function with string default argument.
 */
public func optionalString(optionalStr: String = "abc") -> String {
  let swifttoscoptionalStr = strdup(optionalStr)!
  var err = IEGenCObject()
  let result = _func__optionalString(swifttoscoptionalStr, &err)
  if err.type != nil {
    let errorType = String(cString: err.type!)
    switch errorType {
    case ("std::exception"):
      let excObj = StdException(err, true)
      ExceptionHandler.handleUncaughtException(excObj.what())
    default:
      err.type.deallocate()
      ExceptionHandler.handleUncaughtException("Uncaught Exception")
    }
  }
  let sctoswiftresult = String(cString: result)
  defer {
    result.deallocate()
  }
  return sctoswiftresult
}

/**
 * A global function with primitive default value.
 */
public func optionalInt(i: Int = 5) -> Int {
  let swifttosci = CInt(i)
  var err = IEGenCObject()
  let result = _func__optionalInt(swifttosci, &err)
  if err.type != nil {
    let errorType = String(cString: err.type!)
    switch errorType {
    case ("std::exception"):
      let excObj = StdException(err, true)
      ExceptionHandler.handleUncaughtException(excObj.what())
    default:
      err.type.deallocate()
      ExceptionHandler.handleUncaughtException("Uncaught Exception")
    }
  }
  let sctoswiftresult = Int(result)
  return sctoswiftresult
}