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
 * A test example for keep_alive policy with shared_ref=False.
 */
public class Child1 {

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
    release_IegenExample_Child1(cself, owner)
  }

  public func keepIEGenReference(_ object: Any) {
    self.refs.append(object)
  }

  public convenience init(name: String) {
    let swifttoscname = strdup(name)!
    var iegenErr = IEGenCObject()
    self.init(create_IegenExample_Child1(swifttoscname, &iegenErr), true)
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

  public var name: String {
    var iegenErr = IEGenCObject()
    let result = _prop_get_IegenExample_Child1_name(cself, &iegenErr)
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

}

/**
 * A test example for keep_alive policy with action=gen_interface.
 */
public protocol Child3 {
  var cself: IEGenCObject { get }

  func keepIEGenReference(_ object: Any)
  var name: String { get }
}

extension Child3 {
  public var name: String {
    var iegenErr = IEGenCObject()
    let result = _prop_get_IegenExample_Child3_name(cself, &iegenErr)
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

}

public class Child3Impl: Child3 {
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
    release_IegenExample_Child3Impl(cself, owner)
  }

  public func keepIEGenReference(_ object: Any) {
    self.refs.append(object)
  }

  public convenience init(name: String) {
    let swifttoscname = strdup(name)!
    var iegenErr = IEGenCObject()
    self.init(create_IegenExample_Child3(swifttoscname, &iegenErr), true)
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

/**
 * A test example for keep_alive policy with shared_ref=True.
 */
public class Child2 {

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
    release_IegenExample_Child2(cself, owner)
  }

  public func keepIEGenReference(_ object: Any) {
    self.refs.append(object)
  }

  public convenience init(name: String) {
    let swifttoscname = strdup(name)!
    var iegenErr = IEGenCObject()
    self.init(create_IegenExample_Child2(swifttoscname, &iegenErr), true)
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

  public var name: String {
    var iegenErr = IEGenCObject()
    let result = _prop_get_IegenExample_Child2_name(cself, &iegenErr)
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

}

/**
 * A test example for keep_alive policy. Container holding shared_ref and non shared_ref class and interface types.
 */
public class Parent1 {

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
    release_IegenExample_Parent1(cself, owner)
  }

  public func keepIEGenReference(_ object: Any) {
    self.refs.append(object)
  }

  public convenience init(name: String, child1: Child1, child2: Child2, child3: Child3) {
    let swifttoscname = strdup(name)!
    let swifttoscchild1 = child1.cself
    let swifttoscchild2 = child2.cself
    let swifttoscchild3 = child3.cself
    var iegenErr = IEGenCObject()
    self.init(create_IegenExample_Parent1(swifttoscname, swifttoscchild1, swifttoscchild2, swifttoscchild3, &iegenErr), true)
    self.keepIEGenReference(child1)
    self.keepIEGenReference(child3)
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

  public var name: String {
    var iegenErr = IEGenCObject()
    let result = _prop_get_IegenExample_Parent1_name(cself, &iegenErr)
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

  public var child1: Child1 {
    get {
      var iegenErr = IEGenCObject()
      let result = _prop_get_IegenExample_Parent1_child1(cself, &iegenErr)
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
      var sctoswiftresult: Child1
      sctoswiftresult = Child1(result)
      sctoswiftresult.keepIEGenReference(self)
      return sctoswiftresult
    }

    set(value) {
      let swifttoscvalue = value.cself
      var iegenErr = IEGenCObject()
      _prop_set_IegenExample_Parent1_child1(cself, swifttoscvalue, &iegenErr)
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

  public var child2: Child2 {
    var iegenErr = IEGenCObject()
    let result = _prop_get_IegenExample_Parent1_child2(cself, &iegenErr)
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
    var sctoswiftresult: Child2
    sctoswiftresult = Child2(result, true)
    return sctoswiftresult
  }

  public var child3: Child3 {
    get {
      let result = _prop_get_IegenExample_Parent1_child3(cself)
      var sctoswiftresult: Child3
      sctoswiftresult = Child3Impl(result)
      sctoswiftresult.keepIEGenReference(self)
      return sctoswiftresult
    }

    set(value) {
      let swifttoscvalue = value.cself
      _prop_set_IegenExample_Parent1_child3(cself, swifttoscvalue)
      self.keepIEGenReference(value)
    }
  }

}

/**
 * A test example for keep_alive policy. Container holding shared_ref and non shared_ref class and interface types.
 */
public class Parent2 {

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
    release_IegenExample_Parent2(cself, owner)
  }

  public func keepIEGenReference(_ object: Any) {
    self.refs.append(object)
  }

  public convenience init(name: String) {
    let swifttoscname = strdup(name)!
    var iegenErr = IEGenCObject()
    self.init(create_IegenExample_Parent2(swifttoscname, &iegenErr), true)
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

  public var name: String {
    var iegenErr = IEGenCObject()
    let result = _prop_get_IegenExample_Parent2_name(cself, &iegenErr)
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

  public var children1: Array<Child1> {
    var iegenErr = IEGenCObject()
    let result = _prop_get_IegenExample_Parent2_children1(cself, &iegenErr)
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
    let _resultBuffer = UnsafeBufferPointer<IEGenCObject>(
      start: result.data.assumingMemoryBound(to: IEGenCObject.self),
      count: Int(result.size))
    var sctoswiftresult: [Child1] = []
    defer {
      _resultBuffer.deallocate()
    }
    for i in 0..<Int(result.size) {
      let resultValue = _resultBuffer[i]
      var sctoswiftresultValue: Child1
      sctoswiftresultValue = Child1(resultValue)
      sctoswiftresult.append(sctoswiftresultValue)
    }
    for valuesctoswiftresult in sctoswiftresult {
      valuesctoswiftresult.keepIEGenReference(self)
    }
    return sctoswiftresult
  }

  public var children2: Array<Child2> {
    var iegenErr = IEGenCObject()
    let result = _prop_get_IegenExample_Parent2_children2(cself, &iegenErr)
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
    let _resultBuffer = UnsafeBufferPointer<IEGenCObject>(
      start: result.data.assumingMemoryBound(to: IEGenCObject.self),
      count: Int(result.size))
    var sctoswiftresult: [Child2] = []
    defer {
      _resultBuffer.deallocate()
    }
    for i in 0..<Int(result.size) {
      let resultValue = _resultBuffer[i]
      var sctoswiftresultValue: Child2
      sctoswiftresultValue = Child2(resultValue, true)
      sctoswiftresult.append(sctoswiftresultValue)
    }
    return sctoswiftresult
  }

  public func addChild1(c: Child1) -> Void {

    let swifttoscc = c.cself
    var iegenErr = IEGenCObject()
    _func_IegenExample_Parent2_addChild1(cself, swifttoscc, &iegenErr)
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

  public func addChildren1(c: Array<Child1>) -> Void {

    let _swifttosccData = UnsafeMutablePointer<IEGenCObject>.allocate(capacity: c.count)
    var swifttoscc = IEGenCDataArray()
    swifttoscc.data = UnsafeMutableRawPointer(_swifttosccData)
    swifttoscc.size = Int64(c.count)
    for i in 0..<c.count {
      let cVal = c[i]
      let swifttosccVal = cVal.cself
      _swifttosccData[i] = swifttosccVal
    }
    var iegenErr = IEGenCObject()
    _func_IegenExample_Parent2_addChildren1(cself, swifttoscc, &iegenErr)
    self.keepIEGenReference(c)
    
    swifttoscc.data.deallocate()
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

  public func addChild2(c: Child2) -> Void {

    let swifttoscc = c.cself
    var iegenErr = IEGenCObject()
    _func_IegenExample_Parent2_addChild2(cself, swifttoscc, &iegenErr)
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

  public func addChildren2(c: Array<Child2>) -> Void {

    let _swifttosccData = UnsafeMutablePointer<IEGenCObject>.allocate(capacity: c.count)
    var swifttoscc = IEGenCDataArray()
    swifttoscc.data = UnsafeMutableRawPointer(_swifttosccData)
    swifttoscc.size = Int64(c.count)
    for i in 0..<c.count {
      let cVal = c[i]
      let swifttosccVal = cVal.cself
      _swifttosccData[i] = swifttosccVal
    }
    var iegenErr = IEGenCObject()
    _func_IegenExample_Parent2_addChildren2(cself, swifttoscc, &iegenErr)
    
    swifttoscc.data.deallocate()
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
