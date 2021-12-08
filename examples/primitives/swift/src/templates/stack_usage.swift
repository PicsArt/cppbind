/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 12/08/2021-09:10.
 * Please do not change it manually.
 */

import CWrapper
import Foundation

public class StackUsage {

  public let cself: UnsafeMutableRawPointer
  public let owner: Bool

  // internal main initializer
  internal required init(_ _cself: UnsafeMutableRawPointer, _ _owner: Bool = false) {
    self.cself = _cself
    self.owner = _owner
  }

  deinit {
    if owner {
      release_StackUsage(cself)
    }
  }

  public convenience init() {
    var err = ErrorObj()
    self.init(create_StackUsage(&err), true)
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
  }

  public func firstItemOfSpecializedStack(p: StackPrj) -> Project {

    let swifttoscp = p.cself
    var err = ErrorObj()
    let result = _func_StackUsage_firstItemOfSpecializedStack(cself, swifttoscp, &err)
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
    let sctoswiftresult = Project(result)
    return sctoswiftresult
  }

  public func firstItemOfTemplateStack(arg0: StackPrj) -> Project {

    let swifttoscarg0 = arg0.cself
    var err = ErrorObj()
    let result = _func_StackUsage_firstItemOfTemplateStackProject(cself, swifttoscarg0, &err)
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
    let sctoswiftresult = Project(result)
    return sctoswiftresult
  }

}
