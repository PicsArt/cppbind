/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 08/14/2022-10:59.
 * Please do not change it manually.
 */

import CWrapper
import Foundation

/// This is a template class example.
/// For templates user must explicitly specify all possible types for each template parameter in the API using
/// template attribute.
public class WrapperPairStrings {

  /// An internal property to keep a reference to the original C++ object.
  /// It is intended to be used by the generated code.
  public let cself: CppBindCObject

  /// An internal property to keep track whether Swift is responsible for deallocating the underlying C++ object or not.
  /// It is intended to be used by the generated code.
  public let owner: Bool
  private var refs: [Any]

  /// internal main initializer
  internal required init(_ _cself: CppBindCObject, _ _owner: Bool = false) {
    self.cself = _cself
    self.owner = _owner
    self.refs = []
  }

  deinit {
    release_CppbindExample_WrapperPairStrings(cself, owner)
  }

  /// An internal method to bind the lifetimes of the current and another object.
  /// It is intended to be used by the generated code.
  public func keepCppBindReference(_ object: Any) {
    self.refs.append(object)
  }

  public convenience init(value: (String, String)) {
    let _swifttoscvalueFirst = UnsafeMutablePointer<UnsafeMutablePointer<CChar>>.allocate(capacity: 1)
    let _swifttoscvalueSecond = UnsafeMutablePointer<UnsafeMutablePointer<CChar>>.allocate(capacity: 1)
    var swifttoscvalue = CppBindCDataPair()
    swifttoscvalue.first = UnsafeMutableRawPointer(_swifttoscvalueFirst)
    swifttoscvalue.second = UnsafeMutableRawPointer(_swifttoscvalueSecond)
    let valueFirst = value.0
    let valueSecond = value.1
    let swifttoscvalueFirst = strdup(valueFirst)!
    let swifttoscvalueSecond = strdup(valueSecond)!
    _swifttoscvalueFirst[0] = swifttoscvalueFirst
    _swifttoscvalueSecond[0] = swifttoscvalueSecond
    var cppbindErr = CppBindCObject()
    self.init(create_CppbindExample_WrapperPairStrings(swifttoscvalue, &cppbindErr), true)
    
    swifttoscvalue.first.deallocate()
    swifttoscvalue.second.deallocate()
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

  public var value: (String, String) {
    get {
      var cppbindErr = CppBindCObject()
      let result = _prop_get_CppbindExample_WrapperPairStrings_value(cself, &cppbindErr)
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
      let _resultFirstData = UnsafeBufferPointer<UnsafeMutablePointer<CChar>>(
        start: result.first.assumingMemoryBound(to: UnsafeMutablePointer<CChar>.self),
        count: 1)
      let _resultSecondData = UnsafeBufferPointer<UnsafeMutablePointer<CChar>>(
        start: result.second.assumingMemoryBound(to: UnsafeMutablePointer<CChar>.self),
        count: 1)
      defer {
        _resultFirstData.deallocate()
        _resultSecondData.deallocate()
      }
      let resultFirst = _resultFirstData[0]
      let resultSecond = _resultSecondData[0]
      let sctoswiftresultFirst = String(cString: resultFirst)
      defer {
        resultFirst.deallocate()
      }
      let sctoswiftresultSecond = String(cString: resultSecond)
      defer {
        resultSecond.deallocate()
      }
      let sctoswiftresult: (String, String) = (sctoswiftresultFirst, sctoswiftresultSecond)
      return sctoswiftresult
    }

    set(value) {
      let _swifttoscvalueFirst = UnsafeMutablePointer<UnsafeMutablePointer<CChar>>.allocate(capacity: 1)
      let _swifttoscvalueSecond = UnsafeMutablePointer<UnsafeMutablePointer<CChar>>.allocate(capacity: 1)
      var swifttoscvalue = CppBindCDataPair()
      swifttoscvalue.first = UnsafeMutableRawPointer(_swifttoscvalueFirst)
      swifttoscvalue.second = UnsafeMutableRawPointer(_swifttoscvalueSecond)
      let valueFirst = value.0
      let valueSecond = value.1
      let swifttoscvalueFirst = strdup(valueFirst)!
      let swifttoscvalueSecond = strdup(valueSecond)!
      _swifttoscvalueFirst[0] = swifttoscvalueFirst
      _swifttoscvalueSecond[0] = swifttoscvalueSecond
      var cppbindErr = CppBindCObject()
      _prop_set_CppbindExample_WrapperPairStrings_value(cself, swifttoscvalue, &cppbindErr)
      
      swifttoscvalue.first.deallocate()
      swifttoscvalue.second.deallocate()
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
  }

  /// An internal property to keep an information about the underlying C++ object type.
  /// It is intended to be used by the generated code.
  class var cppbindCxxTypeName : String { return "cppbind::example::Wrapper<std::pair<std::string, std::string>>" }
}

/// This is a template class example.
/// For templates user must explicitly specify all possible types for each template parameter in the API using
/// template attribute.
public class WrapperPairIntInt {

  /// An internal property to keep a reference to the original C++ object.
  /// It is intended to be used by the generated code.
  public let cself: CppBindCObject

  /// An internal property to keep track whether Swift is responsible for deallocating the underlying C++ object or not.
  /// It is intended to be used by the generated code.
  public let owner: Bool
  private var refs: [Any]

  /// internal main initializer
  internal required init(_ _cself: CppBindCObject, _ _owner: Bool = false) {
    self.cself = _cself
    self.owner = _owner
    self.refs = []
  }

  deinit {
    release_CppbindExample_WrapperPairIntInt(cself, owner)
  }

  /// An internal method to bind the lifetimes of the current and another object.
  /// It is intended to be used by the generated code.
  public func keepCppBindReference(_ object: Any) {
    self.refs.append(object)
  }

  public convenience init(value: (Int, Int)) {
    let _swifttoscvalueFirst = UnsafeMutablePointer<CInt>.allocate(capacity: 1)
    let _swifttoscvalueSecond = UnsafeMutablePointer<CInt>.allocate(capacity: 1)
    var swifttoscvalue = CppBindCDataPair()
    swifttoscvalue.first = UnsafeMutableRawPointer(_swifttoscvalueFirst)
    swifttoscvalue.second = UnsafeMutableRawPointer(_swifttoscvalueSecond)
    let valueFirst = value.0
    let valueSecond = value.1
    let swifttoscvalueFirst = CInt(valueFirst)
    let swifttoscvalueSecond = CInt(valueSecond)
    _swifttoscvalueFirst[0] = swifttoscvalueFirst
    _swifttoscvalueSecond[0] = swifttoscvalueSecond
    var cppbindErr = CppBindCObject()
    self.init(create_CppbindExample_WrapperPairIntInt(swifttoscvalue, &cppbindErr), true)
    
    swifttoscvalue.first.deallocate()
    swifttoscvalue.second.deallocate()
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

  public var value: (Int, Int) {
    get {
      var cppbindErr = CppBindCObject()
      let result = _prop_get_CppbindExample_WrapperPairIntInt_value(cself, &cppbindErr)
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
      let _resultFirstData = UnsafeBufferPointer<CInt>(
        start: result.first.assumingMemoryBound(to: CInt.self),
        count: 1)
      let _resultSecondData = UnsafeBufferPointer<CInt>(
        start: result.second.assumingMemoryBound(to: CInt.self),
        count: 1)
      defer {
        _resultFirstData.deallocate()
        _resultSecondData.deallocate()
      }
      let resultFirst = _resultFirstData[0]
      let resultSecond = _resultSecondData[0]
      let sctoswiftresultFirst = Int(resultFirst)
      let sctoswiftresultSecond = Int(resultSecond)
      let sctoswiftresult: (Int, Int) = (sctoswiftresultFirst, sctoswiftresultSecond)
      return sctoswiftresult
    }

    set(value) {
      let _swifttoscvalueFirst = UnsafeMutablePointer<CInt>.allocate(capacity: 1)
      let _swifttoscvalueSecond = UnsafeMutablePointer<CInt>.allocate(capacity: 1)
      var swifttoscvalue = CppBindCDataPair()
      swifttoscvalue.first = UnsafeMutableRawPointer(_swifttoscvalueFirst)
      swifttoscvalue.second = UnsafeMutableRawPointer(_swifttoscvalueSecond)
      let valueFirst = value.0
      let valueSecond = value.1
      let swifttoscvalueFirst = CInt(valueFirst)
      let swifttoscvalueSecond = CInt(valueSecond)
      _swifttoscvalueFirst[0] = swifttoscvalueFirst
      _swifttoscvalueSecond[0] = swifttoscvalueSecond
      var cppbindErr = CppBindCObject()
      _prop_set_CppbindExample_WrapperPairIntInt_value(cself, swifttoscvalue, &cppbindErr)
      
      swifttoscvalue.first.deallocate()
      swifttoscvalue.second.deallocate()
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
  }

  /// An internal property to keep an information about the underlying C++ object type.
  /// It is intended to be used by the generated code.
  class var cppbindCxxTypeName : String { return "cppbind::example::Wrapper<std::pair<int, int>>" }
}

/// This is a template class example.
/// For templates user must explicitly specify all possible types for each template parameter in the API using
/// template attribute.
public class WrapperString {

  /// An internal property to keep a reference to the original C++ object.
  /// It is intended to be used by the generated code.
  public let cself: CppBindCObject

  /// An internal property to keep track whether Swift is responsible for deallocating the underlying C++ object or not.
  /// It is intended to be used by the generated code.
  public let owner: Bool
  private var refs: [Any]

  /// internal main initializer
  internal required init(_ _cself: CppBindCObject, _ _owner: Bool = false) {
    self.cself = _cself
    self.owner = _owner
    self.refs = []
  }

  deinit {
    release_CppbindExample_WrapperString(cself, owner)
  }

  /// An internal method to bind the lifetimes of the current and another object.
  /// It is intended to be used by the generated code.
  public func keepCppBindReference(_ object: Any) {
    self.refs.append(object)
  }

  public convenience init(value: String) {
    let swifttoscvalue = strdup(value)!
    var cppbindErr = CppBindCObject()
    self.init(create_CppbindExample_WrapperString(swifttoscvalue, &cppbindErr), true)
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

  public var value: String {
    get {
      var cppbindErr = CppBindCObject()
      let result = _prop_get_CppbindExample_WrapperString_value(cself, &cppbindErr)
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
      let sctoswiftresult = String(cString: result)
      defer {
        result.deallocate()
      }
      return sctoswiftresult
    }

    set(value) {
      let swifttoscvalue = strdup(value)!
      var cppbindErr = CppBindCObject()
      _prop_set_CppbindExample_WrapperString_value(cself, swifttoscvalue, &cppbindErr)
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
  }

  /// An internal property to keep an information about the underlying C++ object type.
  /// It is intended to be used by the generated code.
  class var cppbindCxxTypeName : String { return "cppbind::example::Wrapper<std::string>" }
}
