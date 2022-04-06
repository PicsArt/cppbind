/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 04/05/2022-18:55.
 * Please do not change it manually.
 */

import CWrapper
import Foundation

public class TemplateMethods {

  public let cself: IEGenCObject
  public let owner: Bool
  private var refs: [Any]

  /// internal main initializer
  internal required init(_ _cself: IEGenCObject, _ _owner: Bool = false) {
    self.cself = _cself
    self.owner = _owner
    self.refs = []
  }

  deinit {
    release_IegenExample_TemplateMethods(cself, owner)
  }

  public func keepIEGenReference(_ object: Any) {
    self.refs.append(object)
  }

  public convenience init() {
    var iegenErr = IEGenCObject()
    self.init(create_IegenExample_TemplateMethods(&iegenErr), true)
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

  public func max(a: Int, b: Int) -> Int {

    let swifttosca = CInt(a)
    let swifttoscb = CInt(b)
    var iegenErr = IEGenCObject()
    let result = _func_IegenExample_TemplateMethods_maxInt(cself, swifttosca, swifttoscb, &iegenErr)
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

  public func max(a: String, b: String) -> String {

    let swifttosca = strdup(a)!
    let swifttoscb = strdup(b)!
    var iegenErr = IEGenCObject()
    let result = _func_IegenExample_TemplateMethods_maxString(cself, swifttosca, swifttoscb, &iegenErr)
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
    defer {
      result.deallocate()
    }
    return sctoswiftresult
  }

  public func makePair(a: Project, b: Project) -> (Project, Project) {

    let swifttosca = a.cself
    let swifttoscb = b.cself
    var iegenErr = IEGenCObject()
    let result = _func_IegenExample_TemplateMethods_makePairProjectProject(cself, swifttosca, swifttoscb, &iegenErr)
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

  public func makePair(a: Root, b: Project) -> (Root, Project) {

    let swifttosca = a.cself
    let swifttoscb = b.cself
    var iegenErr = IEGenCObject()
    let result = _func_IegenExample_TemplateMethods_makePairRootProject(cself, swifttosca, swifttoscb, &iegenErr)
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
