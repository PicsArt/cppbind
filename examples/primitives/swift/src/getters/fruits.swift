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

public enum FruitType: CUnsignedInt {
  case Apple = 1
  case Pineapple = 2
}

public class Fruit {

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
    release_IegenExample_Fruit(cself, owner)
  }

  public func keepIEGenReference(_ object: Any) {
    self.refs.append(object)
  }

  public var type: FruitType {
    var iegenErr = IEGenCObject()
    let result = _prop_get_IegenExample_Fruit_type(cself, &iegenErr)
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
    guard let sctoswiftresult = FruitType(rawValue: result) else {
       ExceptionHandler.handleUncaughtException(
          "Internal error: unresolved reference to non existing field of FruitType enum.")
    }
    return sctoswiftresult
  }

  class func iegenDowncast(_ iegenObj: IEGenCObject, _ owner: Bool = false) -> Fruit {
    let typeName = String(cString: iegenObj.type)
    switch(typeName) {
    case("iegen::example::Apple"):
      return Apple(iegenObj, owner)
    case("iegen::example::Pineapple"):
      return Pineapple(iegenObj, owner)
    default:
      return Fruit(iegenObj, owner)
    }
  }
}

public class Apple: Fruit {
  /// internal main initializer
  internal required init(_ _cself: IEGenCObject, _ _owner: Bool = false) {
    super.init(_cself, _owner)
  }

  public convenience init() {
    var iegenErr = IEGenCObject()
    self.init(create_IegenExample_Apple(&iegenErr), true)
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

  public override var type: FruitType {
    var iegenErr = IEGenCObject()
    let result = _prop_get_IegenExample_Apple_type(cself, &iegenErr)
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
    guard let sctoswiftresult = FruitType(rawValue: result) else {
       ExceptionHandler.handleUncaughtException(
          "Internal error: unresolved reference to non existing field of FruitType enum.")
    }
    return sctoswiftresult
  }

}

public class Pineapple: Fruit {
  /// internal main initializer
  internal required init(_ _cself: IEGenCObject, _ _owner: Bool = false) {
    super.init(_cself, _owner)
  }

  public convenience init() {
    var iegenErr = IEGenCObject()
    self.init(create_IegenExample_Pineapple(&iegenErr), true)
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

  public override var type: FruitType {
    var iegenErr = IEGenCObject()
    let result = _prop_get_IegenExample_Pineapple_type(cself, &iegenErr)
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
    guard let sctoswiftresult = FruitType(rawValue: result) else {
       ExceptionHandler.handleUncaughtException(
          "Internal error: unresolved reference to non existing field of FruitType enum.")
    }
    return sctoswiftresult
  }

}

/**
 * An example class containing template getters.
 */
public class Fruits {

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
    release_IegenExample_Fruits(cself, owner)
  }

  public func keepIEGenReference(_ object: Any) {
    self.refs.append(object)
  }

  public convenience init(fruits: Array<Fruit>) {
    let _swifttoscfruitsData = UnsafeMutablePointer<IEGenCObject>.allocate(capacity: fruits.count)
    var swifttoscfruits = IEGenCDataArray()
    swifttoscfruits.data = UnsafeMutableRawPointer(_swifttoscfruitsData)
    swifttoscfruits.size = Int64(fruits.count)
    for i in 0..<fruits.count {
      let fruitsVal = fruits[i]
      let swifttoscfruitsVal = fruitsVal.cself
      _swifttoscfruitsData[i] = swifttoscfruitsVal
    }
    var iegenErr = IEGenCObject()
    self.init(create_IegenExample_Fruits(swifttoscfruits, &iegenErr), true)
    
    swifttoscfruits.data.deallocate()
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

  public var apples: Array<Apple> {
    var iegenErr = IEGenCObject()
    let result = _prop_get_IegenExample_Fruits_fruitsApple(cself, &iegenErr)
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
    var sctoswiftresult: [Apple] = []
    defer {
      _resultBuffer.deallocate()
    }
    for i in 0..<Int(result.size) {
      let resultValue = _resultBuffer[i]
      var sctoswiftresultValue: Apple
      sctoswiftresultValue = Apple(resultValue)
      sctoswiftresult.append(sctoswiftresultValue)
    }
    return sctoswiftresult
  }

  public var pineapple: Array<Pineapple> {
    var iegenErr = IEGenCObject()
    let result = _prop_get_IegenExample_Fruits_fruitsPineapple(cself, &iegenErr)
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
    var sctoswiftresult: [Pineapple] = []
    defer {
      _resultBuffer.deallocate()
    }
    for i in 0..<Int(result.size) {
      let resultValue = _resultBuffer[i]
      var sctoswiftresultValue: Pineapple
      sctoswiftresultValue = Pineapple(resultValue)
      sctoswiftresult.append(sctoswiftresultValue)
    }
    return sctoswiftresult
  }

  public var applesWithPineapples: Array<Fruit> {
    get {
      var iegenErr = IEGenCObject()
      let result = _prop_get_IegenExample_Fruits_allFruitsApplePineapple(cself, &iegenErr)
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
      var sctoswiftresult: [Fruit] = []
      defer {
        _resultBuffer.deallocate()
      }
      for i in 0..<Int(result.size) {
        let resultValue = _resultBuffer[i]
        var sctoswiftresultValue: Fruit
        sctoswiftresultValue = Fruit.iegenDowncast(resultValue)
        sctoswiftresult.append(sctoswiftresultValue)
      }
      for valuesctoswiftresult in sctoswiftresult {
        valuesctoswiftresult.keepIEGenReference(self)
      }
      return sctoswiftresult
    }

    set(value) {
      let _swifttoscvalueData = UnsafeMutablePointer<IEGenCObject>.allocate(capacity: value.count)
      var swifttoscvalue = IEGenCDataArray()
      swifttoscvalue.data = UnsafeMutableRawPointer(_swifttoscvalueData)
      swifttoscvalue.size = Int64(value.count)
      for i in 0..<value.count {
        let valueVal = value[i]
        let swifttoscvalueVal = valueVal.cself
        _swifttoscvalueData[i] = swifttoscvalueVal
      }
      var iegenErr = IEGenCObject()
      _prop_set_IegenExample_Fruits_allFruitsApplePineapple(cself, swifttoscvalue, &iegenErr)
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
      
      swifttoscvalue.data.deallocate()
    }
  }

}
