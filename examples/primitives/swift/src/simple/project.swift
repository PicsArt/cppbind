/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 02/22/2022-09:31.
 * Please do not change it manually.
 */

import CWrapper
import Foundation

/**
 * Class holding project information.
 */
public class Project {

  public let cself: IEGenCObject
  public let owner: Bool
  private var refs: [AnyObject]

  // internal main initializer
  internal required init(_ _cself: IEGenCObject, _ _owner: Bool = false) {
    self.cself = _cself
    self.owner = _owner
    self.refs = []
  }

  deinit {
    release_Project(cself, owner)
  }

  public func keepIEGenReference(_ object: AnyObject) {
    self.refs.append(object)
  }

  /**
   * Project constructor.
   */
  public convenience init(title: String) {
    let swifttosctitle = strdup(title)!
    var err = IEGenCObject()
    self.init(create_Project(swifttosctitle, &err), true)
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
  }

  /**
   * Get project´s title.
   */
  public var title: String {
    get {
      let result = _prop_get_Project_title(cself)
      let sctoswiftresult = String(cString: result)
      defer {
        result.deallocate()
      }
      return sctoswiftresult
    }
  }

  /**
   * Add a task to project.
   */
  public func addTask(task: Task) -> Void {

    let swifttosctask = task.cself
    var err = IEGenCObject()
    _func_Project_addTask(cself, swifttosctask, &err)
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
  }

  /**
   * Get project´s tasks.
   */
  public func tasks() -> Array<Task> {

    var err = IEGenCObject()
    let result = _func_Project_tasks(cself, &err)
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
    let _resultBuffer = UnsafeBufferPointer<IEGenCObject>(
      start: result.data.assumingMemoryBound(to: IEGenCObject.self),
      count: Int(result.size))
    var sctoswiftresult: [Task] = []
    defer {
      _resultBuffer.deallocate()
    }
    for i in 0..<Int(result.size) {
      let resultValue = _resultBuffer[i]
      var sctoswiftresultValue: Task
      sctoswiftresultValue = Task(resultValue)
      sctoswiftresult.append(sctoswiftresultValue)
    }
    return sctoswiftresult
  }

  public func equals(p: Project) -> Bool {

    let swifttoscp = p.cself
    var err = IEGenCObject()
    let result = _func_Project_equals(cself, swifttoscp, &err)
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
    return result
  }

}
