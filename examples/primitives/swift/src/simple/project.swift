/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 09/24/2021-07:25.
 * Please do not change it manually.
 */

import CWrapper
import Foundation
/**
 * Class holding project information.
 */
public class Project  {
    
    public let cself : UnsafeMutableRawPointer
    public let owner : Bool

    // internal main initializer
    internal required init(_ _cself: UnsafeMutableRawPointer, _ _owner: Bool = false) {
        self.cself = _cself
        self.owner = _owner
    }
    deinit {
        if owner {
            release_Project(cself)
        }
    }
    
    /**
     * Project constructor.
     */
    public convenience init(title: String) {

        let swift_to_sc_title = strdup(title)!
        self.init(create_Project(swift_to_sc_title), true)
    }
    /**
     * Get project´s title.
     */
    public var title: String {
        get {
            let result = _prop_get_Project_title(cself)
            let sc_to_swift_result = String(cString: result)
            defer{
              result.deallocate()
            }
            return sc_to_swift_result
        }
        
    }
    /**
     * Add a task to project.
     */
    public func addTask(task: Task) -> Void {

        let swift_to_sc_task = task.cself
        var err = ErrorObj()
        _func_Project_addTask(cself, swift_to_sc_task, &err)
        let err_type = Int(err.err_type)
        if (err_type != 0) {
            switch(err_type) {
                case(1):
                    let exc_obj = StdException(err.err_ptr, true)
                    ExceptionHandler.handleUncaughtException(exc_obj.what())
                default:
                    ExceptionHandler.handleUncaughtException("Uncaught Exception")
            }
        }
    }
    /**
     * Get project´s tasks.
     */
    public func tasks() -> Array<Task> {

        var err = ErrorObj()
        let result = _func_Project_tasks(cself, &err)
        let _tmp_result_data = UnsafeBufferPointer<UnsafeMutableRawPointer>(start: result.data.assumingMemoryBound(to: UnsafeMutableRawPointer.self), count: Int(result.size))
        var sc_to_swift_result: [Task] = []
        defer {
          _tmp_result_data.deallocate()
        }
        for _i in 0..<Int(result.size) {
          let value_result = _tmp_result_data[_i]
          let sc_to_swift_value_result = Task(value_result)
          sc_to_swift_result.append(sc_to_swift_value_result)
        }
        let err_type = Int(err.err_type)
        if (err_type != 0) {
            switch(err_type) {
                case(1):
                    let exc_obj = StdException(err.err_ptr, true)
                    ExceptionHandler.handleUncaughtException(exc_obj.what())
                default:
                    ExceptionHandler.handleUncaughtException("Uncaught Exception")
            }
        }
        return sc_to_swift_result
    }
}