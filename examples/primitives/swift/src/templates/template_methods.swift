/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 01/31/2022-08:51.
 * Please do not change it manually.
 */

import CWrapper
import Foundation

public class TemplateMethods {

  public let cself: IEGenCObject
  public let owner: Bool

  // internal main initializer
  internal required init(_ _cself: IEGenCObject, _ _owner: Bool = false) {
    self.cself = _cself
    self.owner = _owner
  }

  deinit {
    release_TemplateMethods(cself, owner)
  }

  public convenience init() {
    var err = IEGenCErrorObj()
    self.init(create_TemplateMethods(&err), true)
    let errorType = Int(err.err_type)
    if errorType != 0 {
      switch errorType {
      case (1):
        let excObj = StdException(IEGenCObject(type: strdup("std::exception"), ptr: err.err_ptr), true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        ExceptionHandler.handleUncaughtException("Uncaught Exception")
      }
    }
  }

  public func max(arg0: Int, arg1: Int) -> Int {

    let swifttoscarg0 = CInt(arg0)
    let swifttoscarg1 = CInt(arg1)
    var err = IEGenCErrorObj()
    let result = _func_TemplateMethods_maxInt(cself, swifttoscarg0, swifttoscarg1, &err)
    let errorType = Int(err.err_type)
    if errorType != 0 {
      switch errorType {
      case (1):
        let excObj = StdException(IEGenCObject(type: strdup("std::exception"), ptr: err.err_ptr), true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        ExceptionHandler.handleUncaughtException("Uncaught Exception")
      }
    }
    let sctoswiftresult = Int(result)
    return sctoswiftresult
  }

  public func max(arg0: String, arg1: String) -> String {

    let swifttoscarg0 = strdup(arg0)!
    let swifttoscarg1 = strdup(arg1)!
    var err = IEGenCErrorObj()
    let result = _func_TemplateMethods_maxString(cself, swifttoscarg0, swifttoscarg1, &err)
    let errorType = Int(err.err_type)
    if errorType != 0 {
      switch errorType {
      case (1):
        let excObj = StdException(IEGenCObject(type: strdup("std::exception"), ptr: err.err_ptr), true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        ExceptionHandler.handleUncaughtException("Uncaught Exception")
      }
    }
    let sctoswiftresult = String(cString: result)
    defer {
      result.deallocate()
    }
    return sctoswiftresult
  }

  public func makePair(arg0: Project, arg1: Project) -> (Project, Project) {

    let swifttoscarg0 = arg0.cself
    let swifttoscarg1 = arg1.cself
    var err = IEGenCErrorObj()
    let result = _func_TemplateMethods_makePairProjectProject(cself, swifttoscarg0, swifttoscarg1, &err)
    let errorType = Int(err.err_type)
    if errorType != 0 {
      switch errorType {
      case (1):
        let excObj = StdException(IEGenCObject(type: strdup("std::exception"), ptr: err.err_ptr), true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        ExceptionHandler.handleUncaughtException("Uncaught Exception")
      }
    }
    let _resultFirstData = UnsafeBufferPointer<IEGenCObject>(
      start: result.first.assumingMemoryBound(to: IEGenCObject.self),
      count: 1)
    let _resultSecondData = UnsafeBufferPointer<IEGenCObject>(
      start: result.second.assumingMemoryBound(to: IEGenCObject.self),
      count: 1)
    defer {
      _resultFirstData.deallocate()
      _resultSecondData.deallocate()
    }
    let resultFirst = _resultFirstData[0]
    let resultSecond = _resultSecondData[0]
    var sctoswiftresultFirst: Project
    sctoswiftresultFirst = Project(resultFirst)
    var sctoswiftresultSecond: Project
    sctoswiftresultSecond = Project(resultSecond)
    let sctoswiftresult: (Project, Project) = (sctoswiftresultFirst, sctoswiftresultSecond)
    return sctoswiftresult
  }

  public func makePair(arg0: Root, arg1: Project) -> (Root, Project) {

    let swifttoscarg0 = arg0.cself
    let swifttoscarg1 = arg1.cself
    var err = IEGenCErrorObj()
    let result = _func_TemplateMethods_makePairRootProject(cself, swifttoscarg0, swifttoscarg1, &err)
    let errorType = Int(err.err_type)
    if errorType != 0 {
      switch errorType {
      case (1):
        let excObj = StdException(IEGenCObject(type: strdup("std::exception"), ptr: err.err_ptr), true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        ExceptionHandler.handleUncaughtException("Uncaught Exception")
      }
    }
    let _resultFirstData = UnsafeBufferPointer<IEGenCObject>(
      start: result.first.assumingMemoryBound(to: IEGenCObject.self),
      count: 1)
    let _resultSecondData = UnsafeBufferPointer<IEGenCObject>(
      start: result.second.assumingMemoryBound(to: IEGenCObject.self),
      count: 1)
    defer {
      _resultFirstData.deallocate()
      _resultSecondData.deallocate()
    }
    let resultFirst = _resultFirstData[0]
    let resultSecond = _resultSecondData[0]
    var sctoswiftresultFirst: Root
    sctoswiftresultFirst = Root(resultFirst)
    var sctoswiftresultSecond: Project
    sctoswiftresultSecond = Project(resultSecond)
    let sctoswiftresult: (Root, Project) = (sctoswiftresultFirst, sctoswiftresultSecond)
    return sctoswiftresult
  }

}
