/**
 * ,--.,------. ,----.   ,------.,--.  ,--.
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  |
 * |  ||  `--, |  | .---.|  `--, |  |' '  |
 * |  ||  `---.'  '--'  ||  `---.|  | `   |
 * `--'`------' `------' `------'`--'  `--'
 * 
 * This file is generated by iegen on 11/12/2021-15:17.
 * Please do not change it manually.
 */

import CWrapper
import Foundation

/**
 * A global function example.
 */
public func concat(str1: String, str2: String) -> String {
  let swiftToScStr1 = strdup(str1)!
  let swiftToScStr2 = strdup(str2)!
  var err = ErrorObj()
  let result = _func__concat(swiftToScStr1, swiftToScStr2, &err)
  let scToSwiftResult = String(cString: result)
  defer {
    result.deallocate()
  }
  let errorType = Int(err.err_type)
  if errorType != 0 {
    switch errorType {
    case (1):
      let excObj = StdException(err.err_ptr, true)
      ExceptionHandler.handleUncaughtException(excObj.what())
    default:
      ExceptionHandler.handleUncaughtException("Uncaught Exception")
    }
  }
  return scToSwiftResult
}

/**
 * A global template function example.
 */
public func max(arg0: Int, arg1: Int) -> Int {
  let swiftToScArg0 = CInt(arg0)
  let swiftToScArg1 = CInt(arg1)
  var err = ErrorObj()
  let result = _func__maxInt(swiftToScArg0, swiftToScArg1, &err)
  let scToSwiftResult = Int(result)
  let errorType = Int(err.err_type)
  if errorType != 0 {
    switch errorType {
    case (1):
      let excObj = StdException(err.err_ptr, true)
      ExceptionHandler.handleUncaughtException(excObj.what())
    default:
      ExceptionHandler.handleUncaughtException("Uncaught Exception")
    }
  }
  return scToSwiftResult
}

/**
 * A global template function example.
 */
public func max(arg0: String, arg1: String) -> String {
  let swiftToScArg0 = strdup(arg0)!
  let swiftToScArg1 = strdup(arg1)!
  var err = ErrorObj()
  let result = _func__maxString(swiftToScArg0, swiftToScArg1, &err)
  let scToSwiftResult = String(cString: result)
  defer {
    result.deallocate()
  }
  let errorType = Int(err.err_type)
  if errorType != 0 {
    switch errorType {
    case (1):
      let excObj = StdException(err.err_ptr, true)
      ExceptionHandler.handleUncaughtException(excObj.what())
    default:
      ExceptionHandler.handleUncaughtException("Uncaught Exception")
    }
  }
  return scToSwiftResult
}

/**
 * A global template function example.
 */
public func makePair(arg0: Project, arg1: Project) -> (Project, Project) {
  let swiftToScArg0 = arg0.cself
  let swiftToScArg1 = arg1.cself
  var err = ErrorObj()
  let result = _func_IegenExample_makePairProjectProject(swiftToScArg0, swiftToScArg1, &err)
  let _resultFirstData = UnsafeBufferPointer<UnsafeMutableRawPointer>(start: result.first.assumingMemoryBound(to: UnsafeMutableRawPointer.self), count: 1)
  let _resultSecondData = UnsafeBufferPointer<UnsafeMutableRawPointer>(start: result.second.assumingMemoryBound(to: UnsafeMutableRawPointer.self), count: 1)
  defer {
    _resultFirstData.deallocate()
    _resultSecondData.deallocate()
  }
  let resultFirst = _resultFirstData[0]
  let resultSecond = _resultSecondData[0]
  let scToSwiftResultFirst = Project(resultFirst)
  let scToSwiftResultSecond = Project(resultSecond)
  let scToSwiftResult: (Project, Project) = (scToSwiftResultFirst, scToSwiftResultSecond)
  let errorType = Int(err.err_type)
  if errorType != 0 {
    switch errorType {
    case (1):
      let excObj = StdException(err.err_ptr, true)
      ExceptionHandler.handleUncaughtException(excObj.what())
    default:
      ExceptionHandler.handleUncaughtException("Uncaught Exception")
    }
  }
  return scToSwiftResult
}

/**
 * A global template function example.
 */
public func makePair(arg0: Root, arg1: Project) -> (Root, Project) {
  let swiftToScArg0 = arg0.cself
  let swiftToScArg1 = arg1.cself
  var err = ErrorObj()
  let result = _func_IegenExample_makePairRootProject(swiftToScArg0, swiftToScArg1, &err)
  let _resultFirstData = UnsafeBufferPointer<UnsafeMutableRawPointer>(start: result.first.assumingMemoryBound(to: UnsafeMutableRawPointer.self), count: 1)
  let _resultSecondData = UnsafeBufferPointer<UnsafeMutableRawPointer>(start: result.second.assumingMemoryBound(to: UnsafeMutableRawPointer.self), count: 1)
  defer {
    _resultFirstData.deallocate()
    _resultSecondData.deallocate()
  }
  let resultFirst = _resultFirstData[0]
  let resultSecond = _resultSecondData[0]
  let scToSwiftResultFirst = Root(resultFirst)
  let scToSwiftResultSecond = Project(resultSecond)
  let scToSwiftResult: (Root, Project) = (scToSwiftResultFirst, scToSwiftResultSecond)
  let errorType = Int(err.err_type)
  if errorType != 0 {
    switch errorType {
    case (1):
      let excObj = StdException(err.err_ptr, true)
      ExceptionHandler.handleUncaughtException(excObj.what())
    default:
      ExceptionHandler.handleUncaughtException("Uncaught Exception")
    }
  }
  return scToSwiftResult
}
