/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 04/05/2022-12:52.
 * Please do not change it manually.
 */

import CWrapper
import Foundation

/**
 * comments
 * 
 */
public class Component: AddressableRoot {

  public let cself: IEGenCObject
  public let owner: Bool
  private var refs: [Any]

  /// internal main initializer
  internal required init(_ _cself: IEGenCObject, _ _owner: Bool = false) {
    self.cself = _cself
    self.owner = _owner
    self.refs = []
  }

  /// internal private initializer to prevent automatic initializer inheritance
  private init(_ _cself: IEGenCObject, _ _owner: Bool, _ _refs: [Any]) {
    fatalError("A private initializer should not be called.")
  }

  deinit {
    release_IegenExample_Component(cself, owner)
  }

  public func keepIEGenReference(_ object: Any) {
    self.refs.append(object)
  }

  /**
   * comments
   * 
   */
  public convenience init(parent: Root, name: String) {
    let swifttoscparent = parent.cself
    let swifttoscname = strdup(name)!
    var iegenErr = IEGenCObject()
    self.init(create_IegenExample_Component(swifttoscparent, swifttoscname, &iegenErr), true)
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

}
