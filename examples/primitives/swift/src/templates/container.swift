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

/**
 * An example interface which descendant types are templates. Used for an example of downcast in target language.
 */
public protocol Container {
  var cself: IEGenCObject { get }

  func keepIEGenReference(_ object: Any)
}

extension Container {
}

public class ContainerImpl: Container {
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
    release_IegenExample_ContainerImpl(cself, owner)
  }

  public func keepIEGenReference(_ object: Any) {
    self.refs.append(object)
  }

  class func iegenDowncast(_ iegenObj: IEGenCObject, _ owner: Bool = false) -> Container {
    let typeName = String(cString: iegenObj.type)
    switch(typeName) {
    case("iegen::example::Stack<iegen::example::Project>"):
      return StackPrj(iegenObj, owner)
    case("iegen::example::Stack<iegen::example::Task>"):
      return StackTask(iegenObj, owner)
    case("iegen::example::Stack<iegen::example::Number<int>>"):
      return StackNumInt(iegenObj, owner)
    default:
      return ContainerImpl(iegenObj, owner)
    }
  }
}

/**
 * An example of usage for a type which descendants are template types.
 * Used for an example of downcast in target language.
 */
public class ContainerHolder {

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
    release_IegenExample_ContainerHolder(cself, owner)
  }

  public func keepIEGenReference(_ object: Any) {
    self.refs.append(object)
  }

  public convenience init(container: Container) {
    let swifttosccontainer = container.cself
    var iegenErr = IEGenCObject()
    self.init(create_IegenExample_ContainerHolder(swifttosccontainer, &iegenErr), true)
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

  public var container: Container {
    var iegenErr = IEGenCObject()
    let result = _prop_get_IegenExample_ContainerHolder_container(cself, &iegenErr)
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
    var sctoswiftresult: Container
    sctoswiftresult = ContainerImpl.iegenDowncast(result)
    sctoswiftresult.keepIEGenReference(self)
    return sctoswiftresult
  }

}
