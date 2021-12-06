/**
 * ,--.,------. ,----.   ,------.,--.  ,--.
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  |
 * |  ||  `--, |  | .---.|  `--, |  |' '  |
 * |  ||  `---.'  '--'  ||  `---.|  | `   |
 * `--'`------' `------' `------'`--'  `--'
 * 
 * This file is generated by iegen on 12/06/2021-09:36.
 * Please do not change it manually.
 */

import CWrapper
import Foundation

public enum FruitType: CUnsignedInt {
  case Apple = 1
  case Pineapple = 2
}

public class Fruit {

  public let cself: UnsafeMutableRawPointer
  public let owner: Bool

  // internal main initializer
  internal required init(_ _cself: UnsafeMutableRawPointer, _ _owner: Bool = false) {
    self.cself = _cself
    self.owner = _owner
  }

  deinit {
    if owner {
      release_Fruit(cself)
    }
  }

  public var type: FruitType {
    get {
      let result = _prop_get_Fruit_type(cself)
      
      let scToSwiftResultOptional = FruitType(rawValue: result)
      if (scToSwiftResultOptional == nil) {
        ExceptionHandler.handleUncaughtException(
        "Internal error: unresolved reference to non existing field of FruitType enum.")
      }
      let scToSwiftResult = scToSwiftResultOptional!
      return scToSwiftResult
    }
  }

}

public class Apple: Fruit {
  public convenience init() {
    var err = ErrorObj()
    self.init(create_Apple(&err), true)
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

  public override var type: FruitType {
    get {
      let result = _prop_get_Apple_type(cself)
      
      let scToSwiftResultOptional = FruitType(rawValue: result)
      if (scToSwiftResultOptional == nil) {
        ExceptionHandler.handleUncaughtException(
        "Internal error: unresolved reference to non existing field of FruitType enum.")
      }
      let scToSwiftResult = scToSwiftResultOptional!
      return scToSwiftResult
    }
  }

}

public class Pineapple: Fruit {
  public convenience init() {
    var err = ErrorObj()
    self.init(create_Pineapple(&err), true)
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

  public override var type: FruitType {
    get {
      let result = _prop_get_Pineapple_type(cself)
      
      let scToSwiftResultOptional = FruitType(rawValue: result)
      if (scToSwiftResultOptional == nil) {
        ExceptionHandler.handleUncaughtException(
        "Internal error: unresolved reference to non existing field of FruitType enum.")
      }
      let scToSwiftResult = scToSwiftResultOptional!
      return scToSwiftResult
    }
  }

}

/**
 * An example class containing template getters.
 */
public class Fruits {

  public let cself: UnsafeMutableRawPointer
  public let owner: Bool

  // internal main initializer
  internal required init(_ _cself: UnsafeMutableRawPointer, _ _owner: Bool = false) {
    self.cself = _cself
    self.owner = _owner
  }

  deinit {
    if owner {
      release_Fruits(cself)
    }
  }

  public convenience init(fruits: Array<Fruit>) {
    let _swiftToScFruitsData = UnsafeMutablePointer<UnsafeMutableRawPointer>.allocate(capacity: fruits.count)
    var swiftToScFruits = CDataArray()
    swiftToScFruits.data = UnsafeMutableRawPointer(_swiftToScFruitsData)
    swiftToScFruits.size = Int64(fruits.count)
    for i in 0..<fruits.count {
      let fruitsVal = fruits[i]
      let swiftToScFruitsval = fruitsVal.cself
      _swiftToScFruitsData[i] = swiftToScFruitsval
    }
    var err = ErrorObj()
    self.init(create_Fruits(swiftToScFruits, &err), true)
    
    swiftToScFruits.data.deallocate()
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

  public var apples: Array<Apple> {
    get {
      let result = _prop_get_Fruits_fruitsApple(cself)
      let _resultBuffer = UnsafeBufferPointer<UnsafeMutableRawPointer>(
        start: result.data.assumingMemoryBound(to: UnsafeMutableRawPointer.self),
        count: Int(result.size))
      var scToSwiftResult: [Apple] = []
      defer {
        _resultBuffer.deallocate()
      }
      for i in 0..<Int(result.size) {
        let resultValue = _resultBuffer[i]
        let scToSwiftResultvalue = Apple(resultValue)
        scToSwiftResult.append(scToSwiftResultvalue)
      }
      return scToSwiftResult
    }
  }

  public var pineapple: Array<Pineapple> {
    get {
      let result = _prop_get_Fruits_fruitsPineapple(cself)
      let _resultBuffer = UnsafeBufferPointer<UnsafeMutableRawPointer>(
        start: result.data.assumingMemoryBound(to: UnsafeMutableRawPointer.self),
        count: Int(result.size))
      var scToSwiftResult: [Pineapple] = []
      defer {
        _resultBuffer.deallocate()
      }
      for i in 0..<Int(result.size) {
        let resultValue = _resultBuffer[i]
        let scToSwiftResultvalue = Pineapple(resultValue)
        scToSwiftResult.append(scToSwiftResultvalue)
      }
      return scToSwiftResult
    }
  }

  public var applesWithPineapples: Array<Fruit> {
    get {
      let result = _prop_get_Fruits_allFruitsApplePineapple(cself)
      let _resultBuffer = UnsafeBufferPointer<UnsafeMutableRawPointer>(
        start: result.data.assumingMemoryBound(to: UnsafeMutableRawPointer.self),
        count: Int(result.size))
      var scToSwiftResult: [Fruit] = []
      defer {
        _resultBuffer.deallocate()
      }
      for i in 0..<Int(result.size) {
        let resultValue = _resultBuffer[i]
        let scToSwiftResultvalue = Fruit(resultValue)
        scToSwiftResult.append(scToSwiftResultvalue)
      }
      return scToSwiftResult
    }

    set(value) {
      let _swiftToScValueData = UnsafeMutablePointer<UnsafeMutableRawPointer>.allocate(capacity: value.count)
      var swiftToScValue = CDataArray()
      swiftToScValue.data = UnsafeMutableRawPointer(_swiftToScValueData)
      swiftToScValue.size = Int64(value.count)
      for i in 0..<value.count {
        let valueVal = value[i]
        let swiftToScValueval = valueVal.cself
        _swiftToScValueData[i] = swiftToScValueval
      }
      _prop_set_Fruits_allFruitsApplePineapple(cself, swiftToScValue)
      
      swiftToScValue.data.deallocate()
    }
  }

}
