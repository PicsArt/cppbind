/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 04/25/2022-05:25.
 * Please do not change it manually.
 */

import CWrapper
import Foundation

/**
 * An example of a type derived from a template.
 */
public class MyStackProject: StackPrj {
  /// internal main initializer
  internal required init(_ _cself: IEGenCObject, _ _owner: Bool = false) {
    super.init(_cself, _owner)
  }

  public convenience init() {
    var iegenErr = IEGenCObject()
    self.init(create_IegenExample_MyStackProject(&iegenErr), true)
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

  override class var iegenCxxTypeName : String { return "iegen::example::MyStack<iegen::example::Project>" }
}

/**
 * An example of a type derived from a template.
 */
public class MyStackTask: StackTask {
  /// internal main initializer
  internal required init(_ _cself: IEGenCObject, _ _owner: Bool = false) {
    super.init(_cself, _owner)
  }

  public convenience init() {
    var iegenErr = IEGenCObject()
    self.init(create_IegenExample_MyStackTask(&iegenErr), true)
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

  override class var iegenCxxTypeName : String { return "iegen::example::MyStack<iegen::example::Task>" }
}
