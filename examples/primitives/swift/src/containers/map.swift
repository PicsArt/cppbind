/**
 * ,--.,------. ,----.   ,------.,--.  ,--.
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  |
 * |  ||  `--, |  | .---.|  `--, |  |' '  |
 * |  ||  `---.'  '--'  ||  `---.|  | `   |
 * `--'`------' `------' `------'`--'  `--'
 * 
 * This file is generated by iegen on 12/04/2021-19:53.
 * Please do not change it manually.
 */

import CWrapper
import Foundation

/**
 * comments
 * 
 */
public class MapItem {

  public let cself: UnsafeMutableRawPointer
  public let owner: Bool

  // internal main initializer
  internal required init(_ _cself: UnsafeMutableRawPointer, _ _owner: Bool = false) {
    self.cself = _cself
    self.owner = _owner
  }

  deinit {
    if owner {
      release_MapItem(cself)
    }
  }

  /**
   * comments
   * 
   */
  public convenience init(value: Int) {
    let swiftToScValue = CInt(value)
    self.init(create_MapItem(swiftToScValue), true)
  }

  /**
   * comments
   * 
   */
  public var value: Int {
    get {
      let result = _prop_get_MapItem_value(cself)
      let scToSwiftResult = Int(result)
      return scToSwiftResult
    }

    set(value) {
      let swiftToScValue = CInt(value)
      _prop_set_MapItem_value(cself, swiftToScValue)
    }
  }

}

/**
 * comments
 * 
 */
public class MapExamples {

  public let cself: UnsafeMutableRawPointer
  public let owner: Bool

  // internal main initializer
  internal required init(_ _cself: UnsafeMutableRawPointer, _ _owner: Bool = false) {
    self.cself = _cself
    self.owner = _owner
  }

  deinit {
    if owner {
      release_MapExamples(cself)
    }
  }

  /**
   * comments
   * 
   */
  public convenience init() {
    self.init(create_MapExamples(), true)
  }

  /**
   * comments
   * 
   */
  public func addStringPair(info: (String, String)) -> Void {

    let _swiftToScInfoFirst = UnsafeMutablePointer<UnsafeMutablePointer<CChar>>.allocate(capacity: 1)
    let _swiftToScInfoSecond = UnsafeMutablePointer<UnsafeMutablePointer<CChar>>.allocate(capacity: 1)
    defer {
      _swiftToScInfoFirst.deallocate()
      _swiftToScInfoSecond.deallocate()
    }
    var swiftToScInfo = CDataPair()
    swiftToScInfo.first = UnsafeMutableRawPointer(_swiftToScInfoFirst)
    swiftToScInfo.second = UnsafeMutableRawPointer(_swiftToScInfoSecond)
    let infoFirst = info.0
    let infoSecond = info.1
    let swiftToScInfofirst = strdup(infoFirst)!
    let swiftToScInfosecond = strdup(infoSecond)!
    _swiftToScInfoFirst[0] = swiftToScInfofirst
    _swiftToScInfoSecond[0] = swiftToScInfosecond
    var err = ErrorObj()
    _func_MapExamples_addStringPair(cself, swiftToScInfo, &err)
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

  /**
   * comments
   * 
   */
  public func addIntMap(info: Dictionary<Int, Int>) -> Void {

    let _swiftToScInfoKey = UnsafeMutablePointer<CInt>.allocate(
      capacity: info.count)
    let _swiftToScInfoVal = UnsafeMutablePointer<CInt>.allocate(
      capacity: info.count)
    var swiftToScInfo = CDataMap()
    swiftToScInfo.keys = UnsafeMutableRawPointer(_swiftToScInfoKey)
    swiftToScInfo.values = UnsafeMutableRawPointer(_swiftToScInfoVal)
    swiftToScInfo.size = Int64(info.count)
    var infoIdx = 0
    for (infoKey, infoVal) in info {
      let swiftToScInfokey = CInt(infoKey)
      let swiftToScInfoval = CInt(infoVal)
      _swiftToScInfoKey[infoIdx] = swiftToScInfokey
      _swiftToScInfoVal[infoIdx] = swiftToScInfoval
      infoIdx += 1
    }
    var err = ErrorObj()
    _func_MapExamples_addIntMap(cself, swiftToScInfo, &err)
    
    swiftToScInfo.keys.deallocate()
    swiftToScInfo.values.deallocate()
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

  /**
   * comments
   * 
   */
  public func addStringMap(info: Dictionary<String, String>) -> Void {

    let _swiftToScInfoKey = UnsafeMutablePointer<UnsafeMutablePointer<CChar>>.allocate(
      capacity: info.count)
    let _swiftToScInfoVal = UnsafeMutablePointer<UnsafeMutablePointer<CChar>>.allocate(
      capacity: info.count)
    var swiftToScInfo = CDataMap()
    swiftToScInfo.keys = UnsafeMutableRawPointer(_swiftToScInfoKey)
    swiftToScInfo.values = UnsafeMutableRawPointer(_swiftToScInfoVal)
    swiftToScInfo.size = Int64(info.count)
    var infoIdx = 0
    for (infoKey, infoVal) in info {
      let swiftToScInfokey = strdup(infoKey)!
      let swiftToScInfoval = strdup(infoVal)!
      _swiftToScInfoKey[infoIdx] = swiftToScInfokey
      _swiftToScInfoVal[infoIdx] = swiftToScInfoval
      infoIdx += 1
    }
    var err = ErrorObj()
    _func_MapExamples_addStringMap(cself, swiftToScInfo, &err)
    
    swiftToScInfo.keys.deallocate()
    swiftToScInfo.values.deallocate()
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

  /**
   * comments
   * 
   */
  public func getStringMap() -> Dictionary<String, String> {

    var err = ErrorObj()
    let result = _func_MapExamples_getStringMap(cself, &err)
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
    let resultBufferKey = UnsafeBufferPointer<UnsafeMutablePointer<CChar>>(
      start: result.keys.assumingMemoryBound(to: UnsafeMutablePointer<CChar>.self),
      count: Int(result.size))
    let resultBufferVal = UnsafeBufferPointer<UnsafeMutablePointer<CChar>>(
      start: result.values.assumingMemoryBound(to: UnsafeMutablePointer<CChar>.self),
      count: Int(result.size))
    var scToSwiftResult: [String:String] = [:]
    defer {
      resultBufferKey.deallocate()
      resultBufferVal.deallocate()
    }
    for resultIdx in 0..<Int(result.size) {
      let resultKey = resultBufferKey[resultIdx]
      let resultVal = resultBufferVal[resultIdx]
      do {
        let scToSwiftResultkey = String(cString: resultKey)
        defer {
          resultKey.deallocate()
        }
        let scToSwiftResultval = String(cString: resultVal)
        defer {
          resultVal.deallocate()
        }
        scToSwiftResult[scToSwiftResultkey] = scToSwiftResultval
      }
    }
    return scToSwiftResult
  }

  /**
   * comments
   * 
   */
  public func getIntMap() -> Dictionary<Int, Int> {

    var err = ErrorObj()
    let result = _func_MapExamples_getIntMap(cself, &err)
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
    let resultBufferKey = UnsafeBufferPointer<CInt>(
      start: result.keys.assumingMemoryBound(to: CInt.self),
      count: Int(result.size))
    let resultBufferVal = UnsafeBufferPointer<CInt>(
      start: result.values.assumingMemoryBound(to: CInt.self),
      count: Int(result.size))
    var scToSwiftResult: [Int:Int] = [:]
    defer {
      resultBufferKey.deallocate()
      resultBufferVal.deallocate()
    }
    for resultIdx in 0..<Int(result.size) {
      let resultKey = resultBufferKey[resultIdx]
      let resultVal = resultBufferVal[resultIdx]
      do {
        let scToSwiftResultkey = Int(resultKey)
        let scToSwiftResultval = Int(resultVal)
        scToSwiftResult[scToSwiftResultkey] = scToSwiftResultval
      }
    }
    return scToSwiftResult
  }

  /**
   * comments
   * 
   */
  public func addMixedMap(info: Dictionary<String, MapItem>) -> Void {

    let _swiftToScInfoKey = UnsafeMutablePointer<UnsafeMutablePointer<CChar>>.allocate(
      capacity: info.count)
    let _swiftToScInfoVal = UnsafeMutablePointer<UnsafeMutableRawPointer>.allocate(
      capacity: info.count)
    var swiftToScInfo = CDataMap()
    swiftToScInfo.keys = UnsafeMutableRawPointer(_swiftToScInfoKey)
    swiftToScInfo.values = UnsafeMutableRawPointer(_swiftToScInfoVal)
    swiftToScInfo.size = Int64(info.count)
    var infoIdx = 0
    for (infoKey, infoVal) in info {
      let swiftToScInfokey = strdup(infoKey)!
      let swiftToScInfoval = infoVal.cself
      _swiftToScInfoKey[infoIdx] = swiftToScInfokey
      _swiftToScInfoVal[infoIdx] = swiftToScInfoval
      infoIdx += 1
    }
    var err = ErrorObj()
    _func_MapExamples_addMixedMap(cself, swiftToScInfo, &err)
    
    swiftToScInfo.keys.deallocate()
    swiftToScInfo.values.deallocate()
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

  /**
   * comments
   * 
   */
  public func getMixedMap() -> Dictionary<String, MapItem> {

    var err = ErrorObj()
    let result = _func_MapExamples_getMixedMap(cself, &err)
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
    let resultBufferKey = UnsafeBufferPointer<UnsafeMutablePointer<CChar>>(
      start: result.keys.assumingMemoryBound(to: UnsafeMutablePointer<CChar>.self),
      count: Int(result.size))
    let resultBufferVal = UnsafeBufferPointer<UnsafeMutableRawPointer>(
      start: result.values.assumingMemoryBound(to: UnsafeMutableRawPointer.self),
      count: Int(result.size))
    var scToSwiftResult: [String:MapItem] = [:]
    defer {
      resultBufferKey.deallocate()
      resultBufferVal.deallocate()
    }
    for resultIdx in 0..<Int(result.size) {
      let resultKey = resultBufferKey[resultIdx]
      let resultVal = resultBufferVal[resultIdx]
      do {
        let scToSwiftResultkey = String(cString: resultKey)
        defer {
          resultKey.deallocate()
        }
        let scToSwiftResultval = MapItem(resultVal, true)
        scToSwiftResult[scToSwiftResultkey] = scToSwiftResultval
      }
    }
    return scToSwiftResult
  }

}
