/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 07/01/2022-11:59.
 * Please do not change it manually.
 */

import CWrapper
import Foundation

public class ArrayFloat2 {

  /**
   * An internal property to keep a reference to the original C++ object.
   * It is intended to be used by the generated code.
   */
  public let cself: CppBindCObject

  /**
   * An internal property to keep track whether Swift is responsible for deallocating the underlying C++ object or not.
   * It is intended to be used by the generated code.
   */
  public let owner: Bool
  private var refs: [Any]

  /// internal main initializer
  internal required init(_ _cself: CppBindCObject, _ _owner: Bool = false) {
    self.cself = _cself
    self.owner = _owner
    self.refs = []
  }

  deinit {
    release_CppbindExample_ArrayFloat2(cself, owner)
  }

  /**
   * An internal method to bind the lifetimes of the current and another object.
   * It is intended to be used by the generated code.
   */
  public func keepCppBindReference(_ object: Any) {
    self.refs.append(object)
  }

  public convenience init(array: ArrayFloat2) {
    let swifttoscarray = array.cself
    var cppbindErr = CppBindCObject()
    self.init(create_CppbindExample_ArrayFloat2(swifttoscarray, &cppbindErr), true)
    if cppbindErr.type != nil {
      let errorType = String(cString: cppbindErr.type!)
      switch errorType {
      case ("std::exception"):
        let excObj = StdException(cppbindErr, true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        cppbindErr.type.deallocate()
        ExceptionHandler.handleUncaughtException("Uncaught Exception")
      }
    }
  }

  public convenience init(array: Array<Float>) {
    let _swifttoscarrayData = UnsafeMutablePointer<CFloat>.allocate(capacity: array.count)
    var swifttoscarray = CppBindCDataArray()
    swifttoscarray.data = UnsafeMutableRawPointer(_swifttoscarrayData)
    swifttoscarray.size = Int64(array.count)
    for i in 0..<array.count {
      let arrayVal = array[i]
      
      _swifttoscarrayData[i] = arrayVal
    }
    var cppbindErr = CppBindCObject()
    self.init(create_CppbindExample_ArrayFloat2_1(swifttoscarray, &cppbindErr), true)
    
    swifttoscarray.data.deallocate()
    if cppbindErr.type != nil {
      let errorType = String(cString: cppbindErr.type!)
      switch errorType {
      case ("std::exception"):
        let excObj = StdException(cppbindErr, true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        cppbindErr.type.deallocate()
        ExceptionHandler.handleUncaughtException("Uncaught Exception")
      }
    }
  }

  

  public subscript(idx: Int) -> Float {
    get {
      let swifttoscidx = CInt(idx)
      let result = _func_CppbindExample_ArrayFloat2__getitem_(cself, swifttoscidx)
      return result
    }

    set(value) {
      let swifttoscidx = CInt(idx)
      _func_CppbindExample_ArrayFloat2__setitem_(cself, swifttoscidx, value)
    }
  }

  public static func +(cself: ArrayFloat2, rhs: ArrayFloat2) -> ArrayFloat2 {
    let swifttoscrhs = rhs.cself
    var cppbindErr = CppBindCObject()
    let result = _func_CppbindExample_ArrayFloat2__add_(cself.cself, swifttoscrhs, &cppbindErr)
    if cppbindErr.type != nil {
      let errorType = String(cString: cppbindErr.type!)
      switch errorType {
      case ("std::exception"):
        let excObj = StdException(cppbindErr, true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        cppbindErr.type.deallocate()
        ExceptionHandler.handleUncaughtException("Uncaught Exception")
      }
    }
    var sctoswiftresult: ArrayFloat2
    sctoswiftresult = ArrayFloat2(result, true)
    return sctoswiftresult
  }

  public static func -(cself: ArrayFloat2, rhs: ArrayFloat2) -> ArrayFloat2 {
    let swifttoscrhs = rhs.cself
    var cppbindErr = CppBindCObject()
    let result = _func_CppbindExample_ArrayFloat2__sub_(cself.cself, swifttoscrhs, &cppbindErr)
    if cppbindErr.type != nil {
      let errorType = String(cString: cppbindErr.type!)
      switch errorType {
      case ("std::exception"):
        let excObj = StdException(cppbindErr, true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        cppbindErr.type.deallocate()
        ExceptionHandler.handleUncaughtException("Uncaught Exception")
      }
    }
    var sctoswiftresult: ArrayFloat2
    sctoswiftresult = ArrayFloat2(result, true)
    return sctoswiftresult
  }

  public static func ==(cself: ArrayFloat2, rhs: ArrayFloat2) -> Bool {
    let swifttoscrhs = rhs.cself
    var cppbindErr = CppBindCObject()
    let result = _func_CppbindExample_ArrayFloat2__eq_(cself.cself, swifttoscrhs, &cppbindErr)
    if cppbindErr.type != nil {
      let errorType = String(cString: cppbindErr.type!)
      switch errorType {
      case ("std::exception"):
        let excObj = StdException(cppbindErr, true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        cppbindErr.type.deallocate()
        ExceptionHandler.handleUncaughtException("Uncaught Exception")
      }
    }
    return result
  }

  /**
   * Kotlin equals covers also !=.
   */
  public static func !=(cself: ArrayFloat2, rhs: ArrayFloat2) -> Bool {
    let swifttoscrhs = rhs.cself
    var cppbindErr = CppBindCObject()
    let result = _func_CppbindExample_ArrayFloat2__ne_(cself.cself, swifttoscrhs, &cppbindErr)
    if cppbindErr.type != nil {
      let errorType = String(cString: cppbindErr.type!)
      switch errorType {
      case ("std::exception"):
        let excObj = StdException(cppbindErr, true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        cppbindErr.type.deallocate()
        ExceptionHandler.handleUncaughtException("Uncaught Exception")
      }
    }
    return result
  }

  public func data() -> Array<Float> {

    var cppbindErr = CppBindCObject()
    let result = _func_CppbindExample_ArrayFloat2_data(cself, &cppbindErr)
    if cppbindErr.type != nil {
      let errorType = String(cString: cppbindErr.type!)
      switch errorType {
      case ("std::exception"):
        let excObj = StdException(cppbindErr, true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        cppbindErr.type.deallocate()
        ExceptionHandler.handleUncaughtException("Uncaught Exception")
      }
    }
    let _resultBuffer = UnsafeBufferPointer<CFloat>(
      start: result.data.assumingMemoryBound(to: CFloat.self),
      count: Int(result.size))
    var sctoswiftresult: [Float] = []
    defer {
      _resultBuffer.deallocate()
    }
    for i in 0..<Int(result.size) {
      let resultValue = _resultBuffer[i]
      
      sctoswiftresult.append(resultValue)
    }
    return sctoswiftresult
  }

  /**
   * An internal property to keep an information about the underlying C++ object type.
   * It is intended to be used by the generated code.
   */
  class var cppbindCxxTypeName : String { return "cppbind::example::Array<float, 2>" }
}

public class ArrayFloat3 {

  /**
   * An internal property to keep a reference to the original C++ object.
   * It is intended to be used by the generated code.
   */
  public let cself: CppBindCObject

  /**
   * An internal property to keep track whether Swift is responsible for deallocating the underlying C++ object or not.
   * It is intended to be used by the generated code.
   */
  public let owner: Bool
  private var refs: [Any]

  /// internal main initializer
  internal required init(_ _cself: CppBindCObject, _ _owner: Bool = false) {
    self.cself = _cself
    self.owner = _owner
    self.refs = []
  }

  deinit {
    release_CppbindExample_ArrayFloat3(cself, owner)
  }

  /**
   * An internal method to bind the lifetimes of the current and another object.
   * It is intended to be used by the generated code.
   */
  public func keepCppBindReference(_ object: Any) {
    self.refs.append(object)
  }

  public convenience init(array: ArrayFloat3) {
    let swifttoscarray = array.cself
    var cppbindErr = CppBindCObject()
    self.init(create_CppbindExample_ArrayFloat3(swifttoscarray, &cppbindErr), true)
    if cppbindErr.type != nil {
      let errorType = String(cString: cppbindErr.type!)
      switch errorType {
      case ("std::exception"):
        let excObj = StdException(cppbindErr, true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        cppbindErr.type.deallocate()
        ExceptionHandler.handleUncaughtException("Uncaught Exception")
      }
    }
  }

  public convenience init(array: Array<Float>) {
    let _swifttoscarrayData = UnsafeMutablePointer<CFloat>.allocate(capacity: array.count)
    var swifttoscarray = CppBindCDataArray()
    swifttoscarray.data = UnsafeMutableRawPointer(_swifttoscarrayData)
    swifttoscarray.size = Int64(array.count)
    for i in 0..<array.count {
      let arrayVal = array[i]
      
      _swifttoscarrayData[i] = arrayVal
    }
    var cppbindErr = CppBindCObject()
    self.init(create_CppbindExample_ArrayFloat3_1(swifttoscarray, &cppbindErr), true)
    
    swifttoscarray.data.deallocate()
    if cppbindErr.type != nil {
      let errorType = String(cString: cppbindErr.type!)
      switch errorType {
      case ("std::exception"):
        let excObj = StdException(cppbindErr, true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        cppbindErr.type.deallocate()
        ExceptionHandler.handleUncaughtException("Uncaught Exception")
      }
    }
  }

  

  public subscript(idx: Int) -> Float {
    get {
      let swifttoscidx = CInt(idx)
      let result = _func_CppbindExample_ArrayFloat3__getitem_(cself, swifttoscidx)
      return result
    }

    set(value) {
      let swifttoscidx = CInt(idx)
      _func_CppbindExample_ArrayFloat3__setitem_(cself, swifttoscidx, value)
    }
  }

  public static func +(cself: ArrayFloat3, rhs: ArrayFloat3) -> ArrayFloat3 {
    let swifttoscrhs = rhs.cself
    var cppbindErr = CppBindCObject()
    let result = _func_CppbindExample_ArrayFloat3__add_(cself.cself, swifttoscrhs, &cppbindErr)
    if cppbindErr.type != nil {
      let errorType = String(cString: cppbindErr.type!)
      switch errorType {
      case ("std::exception"):
        let excObj = StdException(cppbindErr, true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        cppbindErr.type.deallocate()
        ExceptionHandler.handleUncaughtException("Uncaught Exception")
      }
    }
    var sctoswiftresult: ArrayFloat3
    sctoswiftresult = ArrayFloat3(result, true)
    return sctoswiftresult
  }

  public static func -(cself: ArrayFloat3, rhs: ArrayFloat3) -> ArrayFloat3 {
    let swifttoscrhs = rhs.cself
    var cppbindErr = CppBindCObject()
    let result = _func_CppbindExample_ArrayFloat3__sub_(cself.cself, swifttoscrhs, &cppbindErr)
    if cppbindErr.type != nil {
      let errorType = String(cString: cppbindErr.type!)
      switch errorType {
      case ("std::exception"):
        let excObj = StdException(cppbindErr, true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        cppbindErr.type.deallocate()
        ExceptionHandler.handleUncaughtException("Uncaught Exception")
      }
    }
    var sctoswiftresult: ArrayFloat3
    sctoswiftresult = ArrayFloat3(result, true)
    return sctoswiftresult
  }

  public static func ==(cself: ArrayFloat3, rhs: ArrayFloat3) -> Bool {
    let swifttoscrhs = rhs.cself
    var cppbindErr = CppBindCObject()
    let result = _func_CppbindExample_ArrayFloat3__eq_(cself.cself, swifttoscrhs, &cppbindErr)
    if cppbindErr.type != nil {
      let errorType = String(cString: cppbindErr.type!)
      switch errorType {
      case ("std::exception"):
        let excObj = StdException(cppbindErr, true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        cppbindErr.type.deallocate()
        ExceptionHandler.handleUncaughtException("Uncaught Exception")
      }
    }
    return result
  }

  /**
   * Kotlin equals covers also !=.
   */
  public static func !=(cself: ArrayFloat3, rhs: ArrayFloat3) -> Bool {
    let swifttoscrhs = rhs.cself
    var cppbindErr = CppBindCObject()
    let result = _func_CppbindExample_ArrayFloat3__ne_(cself.cself, swifttoscrhs, &cppbindErr)
    if cppbindErr.type != nil {
      let errorType = String(cString: cppbindErr.type!)
      switch errorType {
      case ("std::exception"):
        let excObj = StdException(cppbindErr, true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        cppbindErr.type.deallocate()
        ExceptionHandler.handleUncaughtException("Uncaught Exception")
      }
    }
    return result
  }

  public func data() -> Array<Float> {

    var cppbindErr = CppBindCObject()
    let result = _func_CppbindExample_ArrayFloat3_data(cself, &cppbindErr)
    if cppbindErr.type != nil {
      let errorType = String(cString: cppbindErr.type!)
      switch errorType {
      case ("std::exception"):
        let excObj = StdException(cppbindErr, true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        cppbindErr.type.deallocate()
        ExceptionHandler.handleUncaughtException("Uncaught Exception")
      }
    }
    let _resultBuffer = UnsafeBufferPointer<CFloat>(
      start: result.data.assumingMemoryBound(to: CFloat.self),
      count: Int(result.size))
    var sctoswiftresult: [Float] = []
    defer {
      _resultBuffer.deallocate()
    }
    for i in 0..<Int(result.size) {
      let resultValue = _resultBuffer[i]
      
      sctoswiftresult.append(resultValue)
    }
    return sctoswiftresult
  }

  /**
   * An internal property to keep an information about the underlying C++ object type.
   * It is intended to be used by the generated code.
   */
  class var cppbindCxxTypeName : String { return "cppbind::example::Array<float, 3>" }
}

public class ArrayInt2 {

  /**
   * An internal property to keep a reference to the original C++ object.
   * It is intended to be used by the generated code.
   */
  public let cself: CppBindCObject

  /**
   * An internal property to keep track whether Swift is responsible for deallocating the underlying C++ object or not.
   * It is intended to be used by the generated code.
   */
  public let owner: Bool
  private var refs: [Any]

  /// internal main initializer
  internal required init(_ _cself: CppBindCObject, _ _owner: Bool = false) {
    self.cself = _cself
    self.owner = _owner
    self.refs = []
  }

  deinit {
    release_CppbindExample_ArrayInt2(cself, owner)
  }

  /**
   * An internal method to bind the lifetimes of the current and another object.
   * It is intended to be used by the generated code.
   */
  public func keepCppBindReference(_ object: Any) {
    self.refs.append(object)
  }

  public convenience init(array: ArrayInt2) {
    let swifttoscarray = array.cself
    var cppbindErr = CppBindCObject()
    self.init(create_CppbindExample_ArrayInt2(swifttoscarray, &cppbindErr), true)
    if cppbindErr.type != nil {
      let errorType = String(cString: cppbindErr.type!)
      switch errorType {
      case ("std::exception"):
        let excObj = StdException(cppbindErr, true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        cppbindErr.type.deallocate()
        ExceptionHandler.handleUncaughtException("Uncaught Exception")
      }
    }
  }

  public convenience init(array: Array<Int>) {
    let _swifttoscarrayData = UnsafeMutablePointer<CInt>.allocate(capacity: array.count)
    var swifttoscarray = CppBindCDataArray()
    swifttoscarray.data = UnsafeMutableRawPointer(_swifttoscarrayData)
    swifttoscarray.size = Int64(array.count)
    for i in 0..<array.count {
      let arrayVal = array[i]
      let swifttoscarrayVal = CInt(arrayVal)
      _swifttoscarrayData[i] = swifttoscarrayVal
    }
    var cppbindErr = CppBindCObject()
    self.init(create_CppbindExample_ArrayInt2_1(swifttoscarray, &cppbindErr), true)
    
    swifttoscarray.data.deallocate()
    if cppbindErr.type != nil {
      let errorType = String(cString: cppbindErr.type!)
      switch errorType {
      case ("std::exception"):
        let excObj = StdException(cppbindErr, true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        cppbindErr.type.deallocate()
        ExceptionHandler.handleUncaughtException("Uncaught Exception")
      }
    }
  }

  

  public subscript(idx: Int) -> Int {
    get {
      let swifttoscidx = CInt(idx)
      let result = _func_CppbindExample_ArrayInt2__getitem_(cself, swifttoscidx)
      let sctoswiftresult = Int(result)
      return sctoswiftresult
    }

    set(value) {
      let swifttoscidx = CInt(idx)
      let swifttoscvalue = CInt(value)
      _func_CppbindExample_ArrayInt2__setitem_(cself, swifttoscidx, swifttoscvalue)
    }
  }

  public static func +(cself: ArrayInt2, rhs: ArrayInt2) -> ArrayInt2 {
    let swifttoscrhs = rhs.cself
    var cppbindErr = CppBindCObject()
    let result = _func_CppbindExample_ArrayInt2__add_(cself.cself, swifttoscrhs, &cppbindErr)
    if cppbindErr.type != nil {
      let errorType = String(cString: cppbindErr.type!)
      switch errorType {
      case ("std::exception"):
        let excObj = StdException(cppbindErr, true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        cppbindErr.type.deallocate()
        ExceptionHandler.handleUncaughtException("Uncaught Exception")
      }
    }
    var sctoswiftresult: ArrayInt2
    sctoswiftresult = ArrayInt2(result, true)
    return sctoswiftresult
  }

  public static func -(cself: ArrayInt2, rhs: ArrayInt2) -> ArrayInt2 {
    let swifttoscrhs = rhs.cself
    var cppbindErr = CppBindCObject()
    let result = _func_CppbindExample_ArrayInt2__sub_(cself.cself, swifttoscrhs, &cppbindErr)
    if cppbindErr.type != nil {
      let errorType = String(cString: cppbindErr.type!)
      switch errorType {
      case ("std::exception"):
        let excObj = StdException(cppbindErr, true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        cppbindErr.type.deallocate()
        ExceptionHandler.handleUncaughtException("Uncaught Exception")
      }
    }
    var sctoswiftresult: ArrayInt2
    sctoswiftresult = ArrayInt2(result, true)
    return sctoswiftresult
  }

  public static func ==(cself: ArrayInt2, rhs: ArrayInt2) -> Bool {
    let swifttoscrhs = rhs.cself
    var cppbindErr = CppBindCObject()
    let result = _func_CppbindExample_ArrayInt2__eq_(cself.cself, swifttoscrhs, &cppbindErr)
    if cppbindErr.type != nil {
      let errorType = String(cString: cppbindErr.type!)
      switch errorType {
      case ("std::exception"):
        let excObj = StdException(cppbindErr, true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        cppbindErr.type.deallocate()
        ExceptionHandler.handleUncaughtException("Uncaught Exception")
      }
    }
    return result
  }

  /**
   * Kotlin equals covers also !=.
   */
  public static func !=(cself: ArrayInt2, rhs: ArrayInt2) -> Bool {
    let swifttoscrhs = rhs.cself
    var cppbindErr = CppBindCObject()
    let result = _func_CppbindExample_ArrayInt2__ne_(cself.cself, swifttoscrhs, &cppbindErr)
    if cppbindErr.type != nil {
      let errorType = String(cString: cppbindErr.type!)
      switch errorType {
      case ("std::exception"):
        let excObj = StdException(cppbindErr, true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        cppbindErr.type.deallocate()
        ExceptionHandler.handleUncaughtException("Uncaught Exception")
      }
    }
    return result
  }

  public func data() -> Array<Int> {

    var cppbindErr = CppBindCObject()
    let result = _func_CppbindExample_ArrayInt2_data(cself, &cppbindErr)
    if cppbindErr.type != nil {
      let errorType = String(cString: cppbindErr.type!)
      switch errorType {
      case ("std::exception"):
        let excObj = StdException(cppbindErr, true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        cppbindErr.type.deallocate()
        ExceptionHandler.handleUncaughtException("Uncaught Exception")
      }
    }
    let _resultBuffer = UnsafeBufferPointer<CInt>(
      start: result.data.assumingMemoryBound(to: CInt.self),
      count: Int(result.size))
    var sctoswiftresult: [Int] = []
    defer {
      _resultBuffer.deallocate()
    }
    for i in 0..<Int(result.size) {
      let resultValue = _resultBuffer[i]
      let sctoswiftresultValue = Int(resultValue)
      sctoswiftresult.append(sctoswiftresultValue)
    }
    return sctoswiftresult
  }

  /**
   * An internal property to keep an information about the underlying C++ object type.
   * It is intended to be used by the generated code.
   */
  class var cppbindCxxTypeName : String { return "cppbind::example::Array<int, 2>" }
}

public class ArrayInt3 {

  /**
   * An internal property to keep a reference to the original C++ object.
   * It is intended to be used by the generated code.
   */
  public let cself: CppBindCObject

  /**
   * An internal property to keep track whether Swift is responsible for deallocating the underlying C++ object or not.
   * It is intended to be used by the generated code.
   */
  public let owner: Bool
  private var refs: [Any]

  /// internal main initializer
  internal required init(_ _cself: CppBindCObject, _ _owner: Bool = false) {
    self.cself = _cself
    self.owner = _owner
    self.refs = []
  }

  deinit {
    release_CppbindExample_ArrayInt3(cself, owner)
  }

  /**
   * An internal method to bind the lifetimes of the current and another object.
   * It is intended to be used by the generated code.
   */
  public func keepCppBindReference(_ object: Any) {
    self.refs.append(object)
  }

  public convenience init(array: ArrayInt3) {
    let swifttoscarray = array.cself
    var cppbindErr = CppBindCObject()
    self.init(create_CppbindExample_ArrayInt3(swifttoscarray, &cppbindErr), true)
    if cppbindErr.type != nil {
      let errorType = String(cString: cppbindErr.type!)
      switch errorType {
      case ("std::exception"):
        let excObj = StdException(cppbindErr, true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        cppbindErr.type.deallocate()
        ExceptionHandler.handleUncaughtException("Uncaught Exception")
      }
    }
  }

  public convenience init(array: Array<Int>) {
    let _swifttoscarrayData = UnsafeMutablePointer<CInt>.allocate(capacity: array.count)
    var swifttoscarray = CppBindCDataArray()
    swifttoscarray.data = UnsafeMutableRawPointer(_swifttoscarrayData)
    swifttoscarray.size = Int64(array.count)
    for i in 0..<array.count {
      let arrayVal = array[i]
      let swifttoscarrayVal = CInt(arrayVal)
      _swifttoscarrayData[i] = swifttoscarrayVal
    }
    var cppbindErr = CppBindCObject()
    self.init(create_CppbindExample_ArrayInt3_1(swifttoscarray, &cppbindErr), true)
    
    swifttoscarray.data.deallocate()
    if cppbindErr.type != nil {
      let errorType = String(cString: cppbindErr.type!)
      switch errorType {
      case ("std::exception"):
        let excObj = StdException(cppbindErr, true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        cppbindErr.type.deallocate()
        ExceptionHandler.handleUncaughtException("Uncaught Exception")
      }
    }
  }

  

  public subscript(idx: Int) -> Int {
    get {
      let swifttoscidx = CInt(idx)
      let result = _func_CppbindExample_ArrayInt3__getitem_(cself, swifttoscidx)
      let sctoswiftresult = Int(result)
      return sctoswiftresult
    }

    set(value) {
      let swifttoscidx = CInt(idx)
      let swifttoscvalue = CInt(value)
      _func_CppbindExample_ArrayInt3__setitem_(cself, swifttoscidx, swifttoscvalue)
    }
  }

  public static func +(cself: ArrayInt3, rhs: ArrayInt3) -> ArrayInt3 {
    let swifttoscrhs = rhs.cself
    var cppbindErr = CppBindCObject()
    let result = _func_CppbindExample_ArrayInt3__add_(cself.cself, swifttoscrhs, &cppbindErr)
    if cppbindErr.type != nil {
      let errorType = String(cString: cppbindErr.type!)
      switch errorType {
      case ("std::exception"):
        let excObj = StdException(cppbindErr, true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        cppbindErr.type.deallocate()
        ExceptionHandler.handleUncaughtException("Uncaught Exception")
      }
    }
    var sctoswiftresult: ArrayInt3
    sctoswiftresult = ArrayInt3(result, true)
    return sctoswiftresult
  }

  public static func -(cself: ArrayInt3, rhs: ArrayInt3) -> ArrayInt3 {
    let swifttoscrhs = rhs.cself
    var cppbindErr = CppBindCObject()
    let result = _func_CppbindExample_ArrayInt3__sub_(cself.cself, swifttoscrhs, &cppbindErr)
    if cppbindErr.type != nil {
      let errorType = String(cString: cppbindErr.type!)
      switch errorType {
      case ("std::exception"):
        let excObj = StdException(cppbindErr, true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        cppbindErr.type.deallocate()
        ExceptionHandler.handleUncaughtException("Uncaught Exception")
      }
    }
    var sctoswiftresult: ArrayInt3
    sctoswiftresult = ArrayInt3(result, true)
    return sctoswiftresult
  }

  public static func ==(cself: ArrayInt3, rhs: ArrayInt3) -> Bool {
    let swifttoscrhs = rhs.cself
    var cppbindErr = CppBindCObject()
    let result = _func_CppbindExample_ArrayInt3__eq_(cself.cself, swifttoscrhs, &cppbindErr)
    if cppbindErr.type != nil {
      let errorType = String(cString: cppbindErr.type!)
      switch errorType {
      case ("std::exception"):
        let excObj = StdException(cppbindErr, true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        cppbindErr.type.deallocate()
        ExceptionHandler.handleUncaughtException("Uncaught Exception")
      }
    }
    return result
  }

  /**
   * Kotlin equals covers also !=.
   */
  public static func !=(cself: ArrayInt3, rhs: ArrayInt3) -> Bool {
    let swifttoscrhs = rhs.cself
    var cppbindErr = CppBindCObject()
    let result = _func_CppbindExample_ArrayInt3__ne_(cself.cself, swifttoscrhs, &cppbindErr)
    if cppbindErr.type != nil {
      let errorType = String(cString: cppbindErr.type!)
      switch errorType {
      case ("std::exception"):
        let excObj = StdException(cppbindErr, true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        cppbindErr.type.deallocate()
        ExceptionHandler.handleUncaughtException("Uncaught Exception")
      }
    }
    return result
  }

  public func data() -> Array<Int> {

    var cppbindErr = CppBindCObject()
    let result = _func_CppbindExample_ArrayInt3_data(cself, &cppbindErr)
    if cppbindErr.type != nil {
      let errorType = String(cString: cppbindErr.type!)
      switch errorType {
      case ("std::exception"):
        let excObj = StdException(cppbindErr, true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        cppbindErr.type.deallocate()
        ExceptionHandler.handleUncaughtException("Uncaught Exception")
      }
    }
    let _resultBuffer = UnsafeBufferPointer<CInt>(
      start: result.data.assumingMemoryBound(to: CInt.self),
      count: Int(result.size))
    var sctoswiftresult: [Int] = []
    defer {
      _resultBuffer.deallocate()
    }
    for i in 0..<Int(result.size) {
      let resultValue = _resultBuffer[i]
      let sctoswiftresultValue = Int(resultValue)
      sctoswiftresult.append(sctoswiftresultValue)
    }
    return sctoswiftresult
  }

  /**
   * An internal property to keep an information about the underlying C++ object type.
   * It is intended to be used by the generated code.
   */
  class var cppbindCxxTypeName : String { return "cppbind::example::Array<int, 3>" }
}

/**
 * An example of template function with an argument of Array<T, 2> type.
 */
public func getFirstElement(a: ArrayFloat2) -> Float {
  let swifttosca = a.cself
  var cppbindErr = CppBindCObject()
  let result = _func_CppbindExample_getFirstElementFloat(swifttosca, &cppbindErr)
  if cppbindErr.type != nil {
    let errorType = String(cString: cppbindErr.type!)
    switch errorType {
    case ("std::exception"):
      let excObj = StdException(cppbindErr, true)
      ExceptionHandler.handleUncaughtException(excObj.what())
    default:
      cppbindErr.type.deallocate()
      ExceptionHandler.handleUncaughtException("Uncaught Exception")
    }
  }
  return result
}

/**
 * An example of template function with an argument of Array<T, 2> type.
 */
public func getFirstElement(a: ArrayInt2) -> Int {
  let swifttosca = a.cself
  var cppbindErr = CppBindCObject()
  let result = _func_CppbindExample_getFirstElementInt(swifttosca, &cppbindErr)
  if cppbindErr.type != nil {
    let errorType = String(cString: cppbindErr.type!)
    switch errorType {
    case ("std::exception"):
      let excObj = StdException(cppbindErr, true)
      ExceptionHandler.handleUncaughtException(excObj.what())
    default:
      cppbindErr.type.deallocate()
      ExceptionHandler.handleUncaughtException("Uncaught Exception")
    }
  }
  let sctoswiftresult = Int(result)
  return sctoswiftresult
}

/**
 * An example of template function with an argument of Array<int, 2> type.
 */
public func multiplyElements(a: ArrayInt2, num: Int) -> ArrayInt2 {
  let swifttosca = a.cself
  let swifttoscnum = CInt(num)
  var cppbindErr = CppBindCObject()
  let result = _func_CppbindExample_multiplyElements(swifttosca, swifttoscnum, &cppbindErr)
  if cppbindErr.type != nil {
    let errorType = String(cString: cppbindErr.type!)
    switch errorType {
    case ("std::exception"):
      let excObj = StdException(cppbindErr, true)
      ExceptionHandler.handleUncaughtException(excObj.what())
    default:
      cppbindErr.type.deallocate()
      ExceptionHandler.handleUncaughtException("Uncaught Exception")
    }
  }
  var sctoswiftresult: ArrayInt2
  sctoswiftresult = ArrayInt2(result, true)
  return sctoswiftresult
}

/**
 * An example of template function with an argument of typedef on Array.
 */
public func addToElements(a: ArrayFloat2, num: Int) -> ArrayFloat2 {
  let swifttosca = a.cself
  let swifttoscnum = CInt(num)
  var cppbindErr = CppBindCObject()
  let result = _func_CppbindExample_addToElements(swifttosca, swifttoscnum, &cppbindErr)
  if cppbindErr.type != nil {
    let errorType = String(cString: cppbindErr.type!)
    switch errorType {
    case ("std::exception"):
      let excObj = StdException(cppbindErr, true)
      ExceptionHandler.handleUncaughtException(excObj.what())
    default:
      cppbindErr.type.deallocate()
      ExceptionHandler.handleUncaughtException("Uncaught Exception")
    }
  }
  var sctoswiftresult: ArrayFloat2
  sctoswiftresult = ArrayFloat2(result, true)
  return sctoswiftresult
}

/**
 * An example of template function with an argument of typedef on Array.
 */
public func addToElements(a: ArrayInt2, num: Int) -> ArrayInt2 {
  let swifttosca = a.cself
  let swifttoscnum = CInt(num)
  var cppbindErr = CppBindCObject()
  let result = _func_CppbindExample_addToElements_1(swifttosca, swifttoscnum, &cppbindErr)
  if cppbindErr.type != nil {
    let errorType = String(cString: cppbindErr.type!)
    switch errorType {
    case ("std::exception"):
      let excObj = StdException(cppbindErr, true)
      ExceptionHandler.handleUncaughtException(excObj.what())
    default:
      cppbindErr.type.deallocate()
      ExceptionHandler.handleUncaughtException("Uncaught Exception")
    }
  }
  var sctoswiftresult: ArrayInt2
  sctoswiftresult = ArrayInt2(result, true)
  return sctoswiftresult
}

/**
 * An example with template argument with expression.
 */
public class Array3 {

  /**
   * An internal property to keep a reference to the original C++ object.
   * It is intended to be used by the generated code.
   */
  public let cself: CppBindCObject

  /**
   * An internal property to keep track whether Swift is responsible for deallocating the underlying C++ object or not.
   * It is intended to be used by the generated code.
   */
  public let owner: Bool
  private var refs: [Any]

  /// internal main initializer
  internal required init(_ _cself: CppBindCObject, _ _owner: Bool = false) {
    self.cself = _cself
    self.owner = _owner
    self.refs = []
  }

  deinit {
    release_CppbindExample_Array3(cself, owner)
  }

  /**
   * An internal method to bind the lifetimes of the current and another object.
   * It is intended to be used by the generated code.
   */
  public func keepCppBindReference(_ object: Any) {
    self.refs.append(object)
  }

  public convenience init(arr: Array<Float>) {
    let _swifttoscarrData = UnsafeMutablePointer<CFloat>.allocate(capacity: arr.count)
    var swifttoscarr = CppBindCDataArray()
    swifttoscarr.data = UnsafeMutableRawPointer(_swifttoscarrData)
    swifttoscarr.size = Int64(arr.count)
    for i in 0..<arr.count {
      let arrVal = arr[i]
      
      _swifttoscarrData[i] = arrVal
    }
    var cppbindErr = CppBindCObject()
    self.init(create_CppbindExample_Array3(swifttoscarr, &cppbindErr), true)
    
    swifttoscarr.data.deallocate()
    if cppbindErr.type != nil {
      let errorType = String(cString: cppbindErr.type!)
      switch errorType {
      case ("std::exception"):
        let excObj = StdException(cppbindErr, true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        cppbindErr.type.deallocate()
        ExceptionHandler.handleUncaughtException("Uncaught Exception")
      }
    }
  }

  /**
   * An internal property to keep an information about the underlying C++ object type.
   * It is intended to be used by the generated code.
   */
  class var cppbindCxxTypeName : String { return "cppbind::example::Array3" }
}
