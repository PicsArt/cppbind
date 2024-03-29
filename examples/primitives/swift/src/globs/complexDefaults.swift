/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 08/14/2022-10:58.
 * Please do not change it manually.
 */

import CWrapper
import Foundation

public func singleComplexDefaultValue() -> Task {
  var cppbindErr = CppBindCObject()
  let result = _func__singleComplexDefaultValue_1(&cppbindErr)
  if cppbindErr.type != nil {
    let errorType = String(cString: cppbindErr.type!)
    switch errorType {
    case ("std::exception"):
      let excObj = StdException(cppbindErr, true)
      ExceptionHandler.handleUncaughtException(excObj.what())
    default:
      cppbindErr.type.deallocate()
      ExceptionHandler.handleUncaughtException("Uncaught Exception")
    }
  }
  var sctoswiftresult: Task
  sctoswiftresult = Task(result, true)
  return sctoswiftresult
}

public func singleComplexDefaultValue(task: Task) -> Task {
  let swifttosctask = task.cself
  var cppbindErr = CppBindCObject()
  let result = _func__singleComplexDefaultValue(swifttosctask, &cppbindErr)
  if cppbindErr.type != nil {
    let errorType = String(cString: cppbindErr.type!)
    switch errorType {
    case ("std::exception"):
      let excObj = StdException(cppbindErr, true)
      ExceptionHandler.handleUncaughtException(excObj.what())
    default:
      cppbindErr.type.deallocate()
      ExceptionHandler.handleUncaughtException("Uncaught Exception")
    }
  }
  var sctoswiftresult: Task
  sctoswiftresult = Task(result, true)
  return sctoswiftresult
}

/// A global function with mixed default values.
public func multipleMixedDefaultValues() -> String {
  var cppbindErr = CppBindCObject()
  let result = _func__multipleMixedDefaultValues_1(&cppbindErr)
  if cppbindErr.type != nil {
    let errorType = String(cString: cppbindErr.type!)
    switch errorType {
    case ("std::exception"):
      let excObj = StdException(cppbindErr, true)
      ExceptionHandler.handleUncaughtException(excObj.what())
    default:
      cppbindErr.type.deallocate()
      ExceptionHandler.handleUncaughtException("Uncaught Exception")
    }
  }
  let sctoswiftresult = String(cString: result)
  defer {
    result.deallocate()
  }
  return sctoswiftresult
}

/// A global function with mixed default values.
public func multipleMixedDefaultValues(task: Task, i: Int = 1) -> String {
  let swifttosctask = task.cself
  let swifttosci = CInt(i)
  var cppbindErr = CppBindCObject()
  let result = _func__multipleMixedDefaultValues_2(swifttosctask, swifttosci, &cppbindErr)
  if cppbindErr.type != nil {
    let errorType = String(cString: cppbindErr.type!)
    switch errorType {
    case ("std::exception"):
      let excObj = StdException(cppbindErr, true)
      ExceptionHandler.handleUncaughtException(excObj.what())
    default:
      cppbindErr.type.deallocate()
      ExceptionHandler.handleUncaughtException("Uncaught Exception")
    }
  }
  let sctoswiftresult = String(cString: result)
  defer {
    result.deallocate()
  }
  return sctoswiftresult
}

/// A global function with mixed default values.
public func multipleMixedDefaultValues(task: Task, i: Int = 1, r: Root) -> String {
  let swifttosctask = task.cself
  let swifttosci = CInt(i)
  let swifttoscr = r.cself
  var cppbindErr = CppBindCObject()
  let result = _func__multipleMixedDefaultValues(swifttosctask, swifttosci, swifttoscr, &cppbindErr)
  if cppbindErr.type != nil {
    let errorType = String(cString: cppbindErr.type!)
    switch errorType {
    case ("std::exception"):
      let excObj = StdException(cppbindErr, true)
      ExceptionHandler.handleUncaughtException(excObj.what())
    default:
      cppbindErr.type.deallocate()
      ExceptionHandler.handleUncaughtException("Uncaught Exception")
    }
  }
  let sctoswiftresult = String(cString: result)
  defer {
    result.deallocate()
  }
  return sctoswiftresult
}
