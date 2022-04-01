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

public class StackUsage {

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
    release_IegenExample_StackUsage(cself, owner)
  }

  public func keepIEGenReference(_ object: Any) {
    self.refs.append(object)
  }

  public convenience init() {
    var iegenErr = IEGenCObject()
    self.init(create_IegenExample_StackUsage(&iegenErr), true)
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

  public func firstItemOfSpecializedStack(p: StackPrj) -> Project {

    let swifttoscp = p.cself
    var iegenErr = IEGenCObject()
    let result = _func_IegenExample_StackUsage_firstItemOfSpecializedStack(cself, swifttoscp, &iegenErr)
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
    var sctoswiftresult: Project
    sctoswiftresult = Project(result)
    return sctoswiftresult
  }

  public func firstItemOfTemplateStack(p: StackPrj) -> Project {

    let swifttoscp = p.cself
    var iegenErr = IEGenCObject()
    let result = _func_IegenExample_StackUsage_firstItemOfTemplateStackProject(cself, swifttoscp, &iegenErr)
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
    var sctoswiftresult: Project
    sctoswiftresult = Project(result)
    return sctoswiftresult
  }

  /**
   * Example to check typedef argument types
   */
  public func firstItemOfSpecializedStackWithTypedefArg(p: StackPrj) -> Project {

    let swifttoscp = p.cself
    var iegenErr = IEGenCObject()
    let result = _func_IegenExample_StackUsage_firstItemOfSpecializedStackWithTypedefArg(cself, swifttoscp, &iegenErr)
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
    var sctoswiftresult: Project
    sctoswiftresult = Project(result)
    return sctoswiftresult
  }

}
