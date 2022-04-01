/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 03/29/2022-15:47.
 * Please do not change it manually.
 */

import CWrapper
import Foundation

public class NestedExamples {

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
    release_IegenExample_NestedExamples(cself, owner)
  }

  public func keepIEGenReference(_ object: Any) {
    self.refs.append(object)
  }

  /**
   * comments
   * 
   */
  public convenience init() {
    var iegenErr = IEGenCObject()
    self.init(create_IegenExample_NestedExamples(&iegenErr), true)
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

  public func setNestedIntVector(v: Array<Array<Int>>) -> Void {

    let _swifttoscvData = UnsafeMutablePointer<IEGenCDataArray>.allocate(capacity: v.count)
    var swifttoscv = IEGenCDataArray()
    swifttoscv.data = UnsafeMutableRawPointer(_swifttoscvData)
    swifttoscv.size = Int64(v.count)
    for i in 0..<v.count {
      let vVal = v[i]
      let _swifttoscvValData = UnsafeMutablePointer<CInt>.allocate(capacity: vVal.count)
      var swifttoscvVal = IEGenCDataArray()
      swifttoscvVal.data = UnsafeMutableRawPointer(_swifttoscvValData)
      swifttoscvVal.size = Int64(vVal.count)
      for i in 0..<vVal.count {
        let vValVal = vVal[i]
        let swifttoscvValVal = CInt(vValVal)
        _swifttoscvValData[i] = swifttoscvValVal
      }
      _swifttoscvData[i] = swifttoscvVal
    }
    var iegenErr = IEGenCObject()
    _func_IegenExample_NestedExamples_setNestedIntVector(cself, swifttoscv, &iegenErr)
    
    let swifttoscvData = swifttoscv.data.assumingMemoryBound(to: IEGenCDataArray.self)
    for i in 0..<Int(swifttoscv.size) {
      let swifttoscvItem = swifttoscvData[i]
      
      swifttoscvItem.data.deallocate()
    }
    swifttoscv.data.deallocate()
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

  public func getNestedIntVector() -> Array<Array<Int>> {

    var iegenErr = IEGenCObject()
    let result = _func_IegenExample_NestedExamples_getNestedIntVector(cself, &iegenErr)
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
    let _resultBuffer = UnsafeBufferPointer<IEGenCDataArray>(
      start: result.data.assumingMemoryBound(to: IEGenCDataArray.self),
      count: Int(result.size))
    var sctoswiftresult: [Array<Int>] = []
    defer {
      _resultBuffer.deallocate()
    }
    for i in 0..<Int(result.size) {
      let resultValue = _resultBuffer[i]
      let _resultValueBuffer = UnsafeBufferPointer<CInt>(
        start: resultValue.data.assumingMemoryBound(to: CInt.self),
        count: Int(resultValue.size))
      var sctoswiftresultValue: [Int] = []
      defer {
        _resultValueBuffer.deallocate()
      }
      for i in 0..<Int(resultValue.size) {
        let resultValueValue = _resultValueBuffer[i]
        let sctoswiftresultValueValue = Int(resultValueValue)
        sctoswiftresultValue.append(sctoswiftresultValueValue)
      }
      sctoswiftresult.append(sctoswiftresultValue)
    }
    return sctoswiftresult
  }

  public func setNestedIntMap(m: Dictionary<Int, Dictionary<Int, Int>>) -> Void {

    let _swifttoscmKey = UnsafeMutablePointer<CInt>.allocate(
      capacity: m.count)
    let _swifttoscmVal = UnsafeMutablePointer<IEGenCDataMap>.allocate(
      capacity: m.count)
    var swifttoscm = IEGenCDataMap()
    swifttoscm.keys = UnsafeMutableRawPointer(_swifttoscmKey)
    swifttoscm.values = UnsafeMutableRawPointer(_swifttoscmVal)
    swifttoscm.size = Int64(m.count)
    var mIdx = 0
    for (mKey, mVal) in m {
      let swifttoscmKey = CInt(mKey)
      let _swifttoscmValKey = UnsafeMutablePointer<CInt>.allocate(
        capacity: mVal.count)
      let _swifttoscmValVal = UnsafeMutablePointer<CInt>.allocate(
        capacity: mVal.count)
      var swifttoscmVal = IEGenCDataMap()
      swifttoscmVal.keys = UnsafeMutableRawPointer(_swifttoscmValKey)
      swifttoscmVal.values = UnsafeMutableRawPointer(_swifttoscmValVal)
      swifttoscmVal.size = Int64(mVal.count)
      var mValIdx = 0
      for (mValKey, mValVal) in mVal {
        let swifttoscmValKey = CInt(mValKey)
        let swifttoscmValVal = CInt(mValVal)
        _swifttoscmValKey[mValIdx] = swifttoscmValKey
        _swifttoscmValVal[mValIdx] = swifttoscmValVal
        mValIdx += 1
      }
      _swifttoscmKey[mIdx] = swifttoscmKey
      _swifttoscmVal[mIdx] = swifttoscmVal
      mIdx += 1
    }
    var iegenErr = IEGenCObject()
    _func_IegenExample_NestedExamples_setNestedIntMap(cself, swifttoscm, &iegenErr)
    
    let swifttoscmData = swifttoscm.values.assumingMemoryBound(to: IEGenCDataMap.self)
    for i in 0..<Int(swifttoscm.size) {
      let swifttoscmItem = swifttoscmData[i]
      
      swifttoscmItem.keys.deallocate()
      swifttoscmItem.values.deallocate()
    }
    swifttoscm.keys.deallocate()
    swifttoscm.values.deallocate()
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

  public func getNestedIntMap() -> Dictionary<Int, Dictionary<Int, Int>> {

    var iegenErr = IEGenCObject()
    let result = _func_IegenExample_NestedExamples_getNestedIntMap(cself, &iegenErr)
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
    let resultBufferKey = UnsafeBufferPointer<CInt>(
      start: result.keys.assumingMemoryBound(to: CInt.self),
      count: Int(result.size))
    let resultBufferVal = UnsafeBufferPointer<IEGenCDataMap>(
      start: result.values.assumingMemoryBound(to: IEGenCDataMap.self),
      count: Int(result.size))
    var sctoswiftresult: [Int:Dictionary<Int, Int>] = [:]
    defer {
      resultBufferKey.deallocate()
      resultBufferVal.deallocate()
    }
    for resultIdx in 0..<Int(result.size) {
      let resultKey = resultBufferKey[resultIdx]
      let resultVal = resultBufferVal[resultIdx]
      do {
        let sctoswiftresultKey = Int(resultKey)
        let resultValBufferKey = UnsafeBufferPointer<CInt>(
          start: resultVal.keys.assumingMemoryBound(to: CInt.self),
          count: Int(resultVal.size))
        let resultValBufferVal = UnsafeBufferPointer<CInt>(
          start: resultVal.values.assumingMemoryBound(to: CInt.self),
          count: Int(resultVal.size))
        var sctoswiftresultVal: [Int:Int] = [:]
        defer {
          resultValBufferKey.deallocate()
          resultValBufferVal.deallocate()
        }
        for resultValIdx in 0..<Int(resultVal.size) {
          let resultValKey = resultValBufferKey[resultValIdx]
          let resultValVal = resultValBufferVal[resultValIdx]
          do {
            let sctoswiftresultValKey = Int(resultValKey)
            let sctoswiftresultValVal = Int(resultValVal)
            sctoswiftresultVal[sctoswiftresultValKey] = sctoswiftresultValVal
          }
        }
        sctoswiftresult[sctoswiftresultKey] = sctoswiftresultVal
      }
    }
    return sctoswiftresult
  }

  public func mixedExampleWithManyArgs(v1: Array<Array<Int>>, v2: Array<Array<Int>>, m1: Dictionary<Int, Dictionary<Int, Int>>, m2: Dictionary<Int, Dictionary<Int, Int>>) -> Void {

    let _swifttoscv1Data = UnsafeMutablePointer<IEGenCDataArray>.allocate(capacity: v1.count)
    var swifttoscv1 = IEGenCDataArray()
    swifttoscv1.data = UnsafeMutableRawPointer(_swifttoscv1Data)
    swifttoscv1.size = Int64(v1.count)
    for i in 0..<v1.count {
      let v1Val = v1[i]
      let _swifttoscv1ValData = UnsafeMutablePointer<CInt>.allocate(capacity: v1Val.count)
      var swifttoscv1Val = IEGenCDataArray()
      swifttoscv1Val.data = UnsafeMutableRawPointer(_swifttoscv1ValData)
      swifttoscv1Val.size = Int64(v1Val.count)
      for i in 0..<v1Val.count {
        let v1ValVal = v1Val[i]
        let swifttoscv1ValVal = CInt(v1ValVal)
        _swifttoscv1ValData[i] = swifttoscv1ValVal
      }
      _swifttoscv1Data[i] = swifttoscv1Val
    }
    let _swifttoscv2Data = UnsafeMutablePointer<IEGenCDataArray>.allocate(capacity: v2.count)
    var swifttoscv2 = IEGenCDataArray()
    swifttoscv2.data = UnsafeMutableRawPointer(_swifttoscv2Data)
    swifttoscv2.size = Int64(v2.count)
    for i in 0..<v2.count {
      let v2Val = v2[i]
      let _swifttoscv2ValData = UnsafeMutablePointer<CInt>.allocate(capacity: v2Val.count)
      var swifttoscv2Val = IEGenCDataArray()
      swifttoscv2Val.data = UnsafeMutableRawPointer(_swifttoscv2ValData)
      swifttoscv2Val.size = Int64(v2Val.count)
      for i in 0..<v2Val.count {
        let v2ValVal = v2Val[i]
        let swifttoscv2ValVal = CInt(v2ValVal)
        _swifttoscv2ValData[i] = swifttoscv2ValVal
      }
      _swifttoscv2Data[i] = swifttoscv2Val
    }
    let _swifttoscm1Key = UnsafeMutablePointer<CInt>.allocate(
      capacity: m1.count)
    let _swifttoscm1Val = UnsafeMutablePointer<IEGenCDataMap>.allocate(
      capacity: m1.count)
    var swifttoscm1 = IEGenCDataMap()
    swifttoscm1.keys = UnsafeMutableRawPointer(_swifttoscm1Key)
    swifttoscm1.values = UnsafeMutableRawPointer(_swifttoscm1Val)
    swifttoscm1.size = Int64(m1.count)
    var m1Idx = 0
    for (m1Key, m1Val) in m1 {
      let swifttoscm1Key = CInt(m1Key)
      let _swifttoscm1ValKey = UnsafeMutablePointer<CInt>.allocate(
        capacity: m1Val.count)
      let _swifttoscm1ValVal = UnsafeMutablePointer<CInt>.allocate(
        capacity: m1Val.count)
      var swifttoscm1Val = IEGenCDataMap()
      swifttoscm1Val.keys = UnsafeMutableRawPointer(_swifttoscm1ValKey)
      swifttoscm1Val.values = UnsafeMutableRawPointer(_swifttoscm1ValVal)
      swifttoscm1Val.size = Int64(m1Val.count)
      var m1ValIdx = 0
      for (m1ValKey, m1ValVal) in m1Val {
        let swifttoscm1ValKey = CInt(m1ValKey)
        let swifttoscm1ValVal = CInt(m1ValVal)
        _swifttoscm1ValKey[m1ValIdx] = swifttoscm1ValKey
        _swifttoscm1ValVal[m1ValIdx] = swifttoscm1ValVal
        m1ValIdx += 1
      }
      _swifttoscm1Key[m1Idx] = swifttoscm1Key
      _swifttoscm1Val[m1Idx] = swifttoscm1Val
      m1Idx += 1
    }
    let _swifttoscm2Key = UnsafeMutablePointer<CInt>.allocate(
      capacity: m2.count)
    let _swifttoscm2Val = UnsafeMutablePointer<IEGenCDataMap>.allocate(
      capacity: m2.count)
    var swifttoscm2 = IEGenCDataMap()
    swifttoscm2.keys = UnsafeMutableRawPointer(_swifttoscm2Key)
    swifttoscm2.values = UnsafeMutableRawPointer(_swifttoscm2Val)
    swifttoscm2.size = Int64(m2.count)
    var m2Idx = 0
    for (m2Key, m2Val) in m2 {
      let swifttoscm2Key = CInt(m2Key)
      let _swifttoscm2ValKey = UnsafeMutablePointer<CInt>.allocate(
        capacity: m2Val.count)
      let _swifttoscm2ValVal = UnsafeMutablePointer<CInt>.allocate(
        capacity: m2Val.count)
      var swifttoscm2Val = IEGenCDataMap()
      swifttoscm2Val.keys = UnsafeMutableRawPointer(_swifttoscm2ValKey)
      swifttoscm2Val.values = UnsafeMutableRawPointer(_swifttoscm2ValVal)
      swifttoscm2Val.size = Int64(m2Val.count)
      var m2ValIdx = 0
      for (m2ValKey, m2ValVal) in m2Val {
        let swifttoscm2ValKey = CInt(m2ValKey)
        let swifttoscm2ValVal = CInt(m2ValVal)
        _swifttoscm2ValKey[m2ValIdx] = swifttoscm2ValKey
        _swifttoscm2ValVal[m2ValIdx] = swifttoscm2ValVal
        m2ValIdx += 1
      }
      _swifttoscm2Key[m2Idx] = swifttoscm2Key
      _swifttoscm2Val[m2Idx] = swifttoscm2Val
      m2Idx += 1
    }
    var iegenErr = IEGenCObject()
    _func_IegenExample_NestedExamples_mixedExampleWithManyArgs(cself, swifttoscv1, swifttoscv2, swifttoscm1, swifttoscm2, &iegenErr)
    
    let swifttoscv1Data = swifttoscv1.data.assumingMemoryBound(to: IEGenCDataArray.self)
    for i in 0..<Int(swifttoscv1.size) {
      let swifttoscv1Item = swifttoscv1Data[i]
      
      swifttoscv1Item.data.deallocate()
    }
    swifttoscv1.data.deallocate()
    
    let swifttoscv2Data = swifttoscv2.data.assumingMemoryBound(to: IEGenCDataArray.self)
    for i in 0..<Int(swifttoscv2.size) {
      let swifttoscv2Item = swifttoscv2Data[i]
      
      swifttoscv2Item.data.deallocate()
    }
    swifttoscv2.data.deallocate()
    
    let swifttoscm1Data = swifttoscm1.values.assumingMemoryBound(to: IEGenCDataMap.self)
    for i in 0..<Int(swifttoscm1.size) {
      let swifttoscm1Item = swifttoscm1Data[i]
      
      swifttoscm1Item.keys.deallocate()
      swifttoscm1Item.values.deallocate()
    }
    swifttoscm1.keys.deallocate()
    swifttoscm1.values.deallocate()
    
    let swifttoscm2Data = swifttoscm2.values.assumingMemoryBound(to: IEGenCDataMap.self)
    for i in 0..<Int(swifttoscm2.size) {
      let swifttoscm2Item = swifttoscm2Data[i]
      
      swifttoscm2Item.keys.deallocate()
      swifttoscm2Item.values.deallocate()
    }
    swifttoscm2.keys.deallocate()
    swifttoscm2.values.deallocate()
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

  public func setVectorOfIntMaps(v: Array<Dictionary<Int, Int>>) -> Void {

    let _swifttoscvData = UnsafeMutablePointer<IEGenCDataMap>.allocate(capacity: v.count)
    var swifttoscv = IEGenCDataArray()
    swifttoscv.data = UnsafeMutableRawPointer(_swifttoscvData)
    swifttoscv.size = Int64(v.count)
    for i in 0..<v.count {
      let vVal = v[i]
      let _swifttoscvValKey = UnsafeMutablePointer<CInt>.allocate(
        capacity: vVal.count)
      let _swifttoscvValVal = UnsafeMutablePointer<CInt>.allocate(
        capacity: vVal.count)
      var swifttoscvVal = IEGenCDataMap()
      swifttoscvVal.keys = UnsafeMutableRawPointer(_swifttoscvValKey)
      swifttoscvVal.values = UnsafeMutableRawPointer(_swifttoscvValVal)
      swifttoscvVal.size = Int64(vVal.count)
      var vValIdx = 0
      for (vValKey, vValVal) in vVal {
        let swifttoscvValKey = CInt(vValKey)
        let swifttoscvValVal = CInt(vValVal)
        _swifttoscvValKey[vValIdx] = swifttoscvValKey
        _swifttoscvValVal[vValIdx] = swifttoscvValVal
        vValIdx += 1
      }
      _swifttoscvData[i] = swifttoscvVal
    }
    var iegenErr = IEGenCObject()
    _func_IegenExample_NestedExamples_setVectorOfIntMaps(cself, swifttoscv, &iegenErr)
    
    let swifttoscvData = swifttoscv.data.assumingMemoryBound(to: IEGenCDataMap.self)
    for i in 0..<Int(swifttoscv.size) {
      let swifttoscvItem = swifttoscvData[i]
      
      swifttoscvItem.keys.deallocate()
      swifttoscvItem.values.deallocate()
    }
    swifttoscv.data.deallocate()
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

  public func getVectorOfIntMaps() -> Array<Dictionary<Int, Int>> {

    var iegenErr = IEGenCObject()
    let result = _func_IegenExample_NestedExamples_getVectorOfIntMaps(cself, &iegenErr)
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
    let _resultBuffer = UnsafeBufferPointer<IEGenCDataMap>(
      start: result.data.assumingMemoryBound(to: IEGenCDataMap.self),
      count: Int(result.size))
    var sctoswiftresult: [Dictionary<Int, Int>] = []
    defer {
      _resultBuffer.deallocate()
    }
    for i in 0..<Int(result.size) {
      let resultValue = _resultBuffer[i]
      let resultValueBufferKey = UnsafeBufferPointer<CInt>(
        start: resultValue.keys.assumingMemoryBound(to: CInt.self),
        count: Int(resultValue.size))
      let resultValueBufferVal = UnsafeBufferPointer<CInt>(
        start: resultValue.values.assumingMemoryBound(to: CInt.self),
        count: Int(resultValue.size))
      var sctoswiftresultValue: [Int:Int] = [:]
      defer {
        resultValueBufferKey.deallocate()
        resultValueBufferVal.deallocate()
      }
      for resultValueIdx in 0..<Int(resultValue.size) {
        let resultValueKey = resultValueBufferKey[resultValueIdx]
        let resultValueVal = resultValueBufferVal[resultValueIdx]
        do {
          let sctoswiftresultValueKey = Int(resultValueKey)
          let sctoswiftresultValueVal = Int(resultValueVal)
          sctoswiftresultValue[sctoswiftresultValueKey] = sctoswiftresultValueVal
        }
      }
      sctoswiftresult.append(sctoswiftresultValue)
    }
    return sctoswiftresult
  }

  public func setMapOfIntVectors(m: Dictionary<Int, Array<Int>>) -> Void {

    let _swifttoscmKey = UnsafeMutablePointer<CInt>.allocate(
      capacity: m.count)
    let _swifttoscmVal = UnsafeMutablePointer<IEGenCDataArray>.allocate(
      capacity: m.count)
    var swifttoscm = IEGenCDataMap()
    swifttoscm.keys = UnsafeMutableRawPointer(_swifttoscmKey)
    swifttoscm.values = UnsafeMutableRawPointer(_swifttoscmVal)
    swifttoscm.size = Int64(m.count)
    var mIdx = 0
    for (mKey, mVal) in m {
      let swifttoscmKey = CInt(mKey)
      let _swifttoscmValData = UnsafeMutablePointer<CInt>.allocate(capacity: mVal.count)
      var swifttoscmVal = IEGenCDataArray()
      swifttoscmVal.data = UnsafeMutableRawPointer(_swifttoscmValData)
      swifttoscmVal.size = Int64(mVal.count)
      for i in 0..<mVal.count {
        let mValVal = mVal[i]
        let swifttoscmValVal = CInt(mValVal)
        _swifttoscmValData[i] = swifttoscmValVal
      }
      _swifttoscmKey[mIdx] = swifttoscmKey
      _swifttoscmVal[mIdx] = swifttoscmVal
      mIdx += 1
    }
    var iegenErr = IEGenCObject()
    _func_IegenExample_NestedExamples_setMapOfIntVectors(cself, swifttoscm, &iegenErr)
    
    let swifttoscmData = swifttoscm.values.assumingMemoryBound(to: IEGenCDataArray.self)
    for i in 0..<Int(swifttoscm.size) {
      let swifttoscmItem = swifttoscmData[i]
      
      swifttoscmItem.data.deallocate()
    }
    swifttoscm.keys.deallocate()
    swifttoscm.values.deallocate()
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

  public func getMapOfIntVectors() -> Dictionary<Int, Array<Int>> {

    var iegenErr = IEGenCObject()
    let result = _func_IegenExample_NestedExamples_getMapOfIntVectors(cself, &iegenErr)
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
    let resultBufferKey = UnsafeBufferPointer<CInt>(
      start: result.keys.assumingMemoryBound(to: CInt.self),
      count: Int(result.size))
    let resultBufferVal = UnsafeBufferPointer<IEGenCDataArray>(
      start: result.values.assumingMemoryBound(to: IEGenCDataArray.self),
      count: Int(result.size))
    var sctoswiftresult: [Int:Array<Int>] = [:]
    defer {
      resultBufferKey.deallocate()
      resultBufferVal.deallocate()
    }
    for resultIdx in 0..<Int(result.size) {
      let resultKey = resultBufferKey[resultIdx]
      let resultVal = resultBufferVal[resultIdx]
      do {
        let sctoswiftresultKey = Int(resultKey)
        let _resultValBuffer = UnsafeBufferPointer<CInt>(
          start: resultVal.data.assumingMemoryBound(to: CInt.self),
          count: Int(resultVal.size))
        var sctoswiftresultVal: [Int] = []
        defer {
          _resultValBuffer.deallocate()
        }
        for i in 0..<Int(resultVal.size) {
          let resultValValue = _resultValBuffer[i]
          let sctoswiftresultValValue = Int(resultValValue)
          sctoswiftresultVal.append(sctoswiftresultValValue)
        }
        sctoswiftresult[sctoswiftresultKey] = sctoswiftresultVal
      }
    }
    return sctoswiftresult
  }

  public func setComplexStringVector(v: Array<Array<Array<String>>>) -> Void {

    let _swifttoscvData = UnsafeMutablePointer<IEGenCDataArray>.allocate(capacity: v.count)
    var swifttoscv = IEGenCDataArray()
    swifttoscv.data = UnsafeMutableRawPointer(_swifttoscvData)
    swifttoscv.size = Int64(v.count)
    for i in 0..<v.count {
      let vVal = v[i]
      let _swifttoscvValData = UnsafeMutablePointer<IEGenCDataArray>.allocate(capacity: vVal.count)
      var swifttoscvVal = IEGenCDataArray()
      swifttoscvVal.data = UnsafeMutableRawPointer(_swifttoscvValData)
      swifttoscvVal.size = Int64(vVal.count)
      for i in 0..<vVal.count {
        let vValVal = vVal[i]
        let _swifttoscvValValData = UnsafeMutablePointer<UnsafeMutablePointer<CChar>>.allocate(capacity: vValVal.count)
        var swifttoscvValVal = IEGenCDataArray()
        swifttoscvValVal.data = UnsafeMutableRawPointer(_swifttoscvValValData)
        swifttoscvValVal.size = Int64(vValVal.count)
        for i in 0..<vValVal.count {
          let vValValVal = vValVal[i]
          let swifttoscvValValVal = strdup(vValValVal)!
          _swifttoscvValValData[i] = swifttoscvValValVal
        }
        _swifttoscvValData[i] = swifttoscvValVal
      }
      _swifttoscvData[i] = swifttoscvVal
    }
    var iegenErr = IEGenCObject()
    _func_IegenExample_NestedExamples_setComplexStringVector(cself, swifttoscv, &iegenErr)
    
    let swifttoscvData = swifttoscv.data.assumingMemoryBound(to: IEGenCDataArray.self)
    for i in 0..<Int(swifttoscv.size) {
      let swifttoscvItem = swifttoscvData[i]
      
      let swifttoscvItemData = swifttoscvItem.data.assumingMemoryBound(to: IEGenCDataArray.self)
      for i in 0..<Int(swifttoscvItem.size) {
        let swifttoscvItemItem = swifttoscvItemData[i]
        
        swifttoscvItemItem.data.deallocate()
      }
      swifttoscvItem.data.deallocate()
    }
    swifttoscv.data.deallocate()
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

  public func getComplexStringVector() -> Array<Array<Array<String>>> {

    var iegenErr = IEGenCObject()
    let result = _func_IegenExample_NestedExamples_getComplexStringVector(cself, &iegenErr)
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
    let _resultBuffer = UnsafeBufferPointer<IEGenCDataArray>(
      start: result.data.assumingMemoryBound(to: IEGenCDataArray.self),
      count: Int(result.size))
    var sctoswiftresult: [Array<Array<String>>] = []
    defer {
      _resultBuffer.deallocate()
    }
    for i in 0..<Int(result.size) {
      let resultValue = _resultBuffer[i]
      let _resultValueBuffer = UnsafeBufferPointer<IEGenCDataArray>(
        start: resultValue.data.assumingMemoryBound(to: IEGenCDataArray.self),
        count: Int(resultValue.size))
      var sctoswiftresultValue: [Array<String>] = []
      defer {
        _resultValueBuffer.deallocate()
      }
      for i in 0..<Int(resultValue.size) {
        let resultValueValue = _resultValueBuffer[i]
        let _resultValueValueBuffer = UnsafeBufferPointer<UnsafeMutablePointer<CChar>>(
          start: resultValueValue.data.assumingMemoryBound(to: UnsafeMutablePointer<CChar>.self),
          count: Int(resultValueValue.size))
        var sctoswiftresultValueValue: [String] = []
        defer {
          _resultValueValueBuffer.deallocate()
        }
        for i in 0..<Int(resultValueValue.size) {
          let resultValueValueValue = _resultValueValueBuffer[i]
          let sctoswiftresultValueValueValue = String(cString: resultValueValueValue)
          defer {
            resultValueValueValue.deallocate()
          }
          sctoswiftresultValueValue.append(sctoswiftresultValueValueValue)
        }
        sctoswiftresultValue.append(sctoswiftresultValueValue)
      }
      sctoswiftresult.append(sctoswiftresultValue)
    }
    return sctoswiftresult
  }

  public func setComplexStringMap(m: Dictionary<String, Dictionary<String, Dictionary<String, String>>>) -> Void {

    let _swifttoscmKey = UnsafeMutablePointer<UnsafeMutablePointer<CChar>>.allocate(
      capacity: m.count)
    let _swifttoscmVal = UnsafeMutablePointer<IEGenCDataMap>.allocate(
      capacity: m.count)
    var swifttoscm = IEGenCDataMap()
    swifttoscm.keys = UnsafeMutableRawPointer(_swifttoscmKey)
    swifttoscm.values = UnsafeMutableRawPointer(_swifttoscmVal)
    swifttoscm.size = Int64(m.count)
    var mIdx = 0
    for (mKey, mVal) in m {
      let swifttoscmKey = strdup(mKey)!
      let _swifttoscmValKey = UnsafeMutablePointer<UnsafeMutablePointer<CChar>>.allocate(
        capacity: mVal.count)
      let _swifttoscmValVal = UnsafeMutablePointer<IEGenCDataMap>.allocate(
        capacity: mVal.count)
      var swifttoscmVal = IEGenCDataMap()
      swifttoscmVal.keys = UnsafeMutableRawPointer(_swifttoscmValKey)
      swifttoscmVal.values = UnsafeMutableRawPointer(_swifttoscmValVal)
      swifttoscmVal.size = Int64(mVal.count)
      var mValIdx = 0
      for (mValKey, mValVal) in mVal {
        let swifttoscmValKey = strdup(mValKey)!
        let _swifttoscmValValKey = UnsafeMutablePointer<UnsafeMutablePointer<CChar>>.allocate(
          capacity: mValVal.count)
        let _swifttoscmValValVal = UnsafeMutablePointer<UnsafeMutablePointer<CChar>>.allocate(
          capacity: mValVal.count)
        var swifttoscmValVal = IEGenCDataMap()
        swifttoscmValVal.keys = UnsafeMutableRawPointer(_swifttoscmValValKey)
        swifttoscmValVal.values = UnsafeMutableRawPointer(_swifttoscmValValVal)
        swifttoscmValVal.size = Int64(mValVal.count)
        var mValValIdx = 0
        for (mValValKey, mValValVal) in mValVal {
          let swifttoscmValValKey = strdup(mValValKey)!
          let swifttoscmValValVal = strdup(mValValVal)!
          _swifttoscmValValKey[mValValIdx] = swifttoscmValValKey
          _swifttoscmValValVal[mValValIdx] = swifttoscmValValVal
          mValValIdx += 1
        }
        _swifttoscmValKey[mValIdx] = swifttoscmValKey
        _swifttoscmValVal[mValIdx] = swifttoscmValVal
        mValIdx += 1
      }
      _swifttoscmKey[mIdx] = swifttoscmKey
      _swifttoscmVal[mIdx] = swifttoscmVal
      mIdx += 1
    }
    var iegenErr = IEGenCObject()
    _func_IegenExample_NestedExamples_setComplexStringMap(cself, swifttoscm, &iegenErr)
    
    let swifttoscmData = swifttoscm.values.assumingMemoryBound(to: IEGenCDataMap.self)
    for i in 0..<Int(swifttoscm.size) {
      let swifttoscmItem = swifttoscmData[i]
      
      let swifttoscmItemData = swifttoscmItem.values.assumingMemoryBound(to: IEGenCDataMap.self)
      for i in 0..<Int(swifttoscmItem.size) {
        let swifttoscmItemItem = swifttoscmItemData[i]
        
        swifttoscmItemItem.keys.deallocate()
        swifttoscmItemItem.values.deallocate()
      }
      swifttoscmItem.keys.deallocate()
      swifttoscmItem.values.deallocate()
    }
    swifttoscm.keys.deallocate()
    swifttoscm.values.deallocate()
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

  public func getComplexStringMap() -> Dictionary<String, Dictionary<String, Dictionary<String, String>>> {

    var iegenErr = IEGenCObject()
    let result = _func_IegenExample_NestedExamples_getComplexStringMap(cself, &iegenErr)
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
    let resultBufferKey = UnsafeBufferPointer<UnsafeMutablePointer<CChar>>(
      start: result.keys.assumingMemoryBound(to: UnsafeMutablePointer<CChar>.self),
      count: Int(result.size))
    let resultBufferVal = UnsafeBufferPointer<IEGenCDataMap>(
      start: result.values.assumingMemoryBound(to: IEGenCDataMap.self),
      count: Int(result.size))
    var sctoswiftresult: [String:Dictionary<String, Dictionary<String, String>>] = [:]
    defer {
      resultBufferKey.deallocate()
      resultBufferVal.deallocate()
    }
    for resultIdx in 0..<Int(result.size) {
      let resultKey = resultBufferKey[resultIdx]
      let resultVal = resultBufferVal[resultIdx]
      do {
        let sctoswiftresultKey = String(cString: resultKey)
        defer {
          resultKey.deallocate()
        }
        let resultValBufferKey = UnsafeBufferPointer<UnsafeMutablePointer<CChar>>(
          start: resultVal.keys.assumingMemoryBound(to: UnsafeMutablePointer<CChar>.self),
          count: Int(resultVal.size))
        let resultValBufferVal = UnsafeBufferPointer<IEGenCDataMap>(
          start: resultVal.values.assumingMemoryBound(to: IEGenCDataMap.self),
          count: Int(resultVal.size))
        var sctoswiftresultVal: [String:Dictionary<String, String>] = [:]
        defer {
          resultValBufferKey.deallocate()
          resultValBufferVal.deallocate()
        }
        for resultValIdx in 0..<Int(resultVal.size) {
          let resultValKey = resultValBufferKey[resultValIdx]
          let resultValVal = resultValBufferVal[resultValIdx]
          do {
            let sctoswiftresultValKey = String(cString: resultValKey)
            defer {
              resultValKey.deallocate()
            }
            let resultValValBufferKey = UnsafeBufferPointer<UnsafeMutablePointer<CChar>>(
              start: resultValVal.keys.assumingMemoryBound(to: UnsafeMutablePointer<CChar>.self),
              count: Int(resultValVal.size))
            let resultValValBufferVal = UnsafeBufferPointer<UnsafeMutablePointer<CChar>>(
              start: resultValVal.values.assumingMemoryBound(to: UnsafeMutablePointer<CChar>.self),
              count: Int(resultValVal.size))
            var sctoswiftresultValVal: [String:String] = [:]
            defer {
              resultValValBufferKey.deallocate()
              resultValValBufferVal.deallocate()
            }
            for resultValValIdx in 0..<Int(resultValVal.size) {
              let resultValValKey = resultValValBufferKey[resultValValIdx]
              let resultValValVal = resultValValBufferVal[resultValValIdx]
              do {
                let sctoswiftresultValValKey = String(cString: resultValValKey)
                defer {
                  resultValValKey.deallocate()
                }
                let sctoswiftresultValValVal = String(cString: resultValValVal)
                defer {
                  resultValValVal.deallocate()
                }
                sctoswiftresultValVal[sctoswiftresultValValKey] = sctoswiftresultValValVal
              }
            }
            sctoswiftresultVal[sctoswiftresultValKey] = sctoswiftresultValVal
          }
        }
        sctoswiftresult[sctoswiftresultKey] = sctoswiftresultVal
      }
    }
    return sctoswiftresult
  }

}
