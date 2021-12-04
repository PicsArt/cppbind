/**
 * ,--.,------. ,----.   ,------.,--.  ,--.
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  |
 * |  ||  `--, |  | .---.|  `--, |  |' '  |
 * |  ||  `---.'  '--'  ||  `---.|  | `   |
 * `--'`------' `------' `------'`--'  `--'
 * 
 * This file is generated by iegen on 12/04/2021-19:30.
 * Please do not change it manually.
 */

import CWrapper
import Foundation

public protocol Animal {
  var cself: UnsafeMutableRawPointer { get }

  func typeName() -> String
}

extension Animal {
  public func typeName() -> String {

    var err = ErrorObj()
    let result = _func_Animal_typeName(cself, &err)
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
    let scToSwiftResult = String(cString: result)
    defer {
      result.deallocate()
    }
    return scToSwiftResult
  }

}

public class AnimalImpl: Animal {
  public let cself: UnsafeMutableRawPointer
  public let owner: Bool

  // internal main initializer
  internal required init(_ _cself: UnsafeMutableRawPointer, _ _owner: Bool = false) {
    self.cself = _cself
    self.owner = _owner
  }

  deinit {
    if owner {
      release_AnimalImpl(cself)
    }
  }

  public convenience init() {
    self.init(create_Animal(), true)
  }

}

public protocol TerrestrialAnimal: Animal {
  func typeName() -> String
}

extension TerrestrialAnimal {
  public func typeName() -> String {

    var err = ErrorObj()
    let result = _func_TerrestrialAnimal_typeName(cself, &err)
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
    let scToSwiftResult = String(cString: result)
    defer {
      result.deallocate()
    }
    return scToSwiftResult
  }

}

public class TerrestrialAnimalImpl: TerrestrialAnimal {
  public let cself: UnsafeMutableRawPointer
  public let owner: Bool

  // internal main initializer
  internal required init(_ _cself: UnsafeMutableRawPointer, _ _owner: Bool = false) {
    self.cself = _cself
    self.owner = _owner
  }

  deinit {
    if owner {
      release_TerrestrialAnimalImpl(cself)
    }
  }

  public convenience init() {
    self.init(create_TerrestrialAnimal(), true)
  }

}

public class AquaticAnimal: Animal {

  public let cself: UnsafeMutableRawPointer
  public let owner: Bool

  // internal main initializer
  internal required init(_ _cself: UnsafeMutableRawPointer, _ _owner: Bool = false) {
    self.cself = _cself
    self.owner = _owner
  }

  deinit {
    if owner {
      release_AquaticAnimal(cself)
    }
  }

  public convenience init() {
    self.init(create_AquaticAnimal(), true)
  }

  public func typeName() -> String {

    var err = ErrorObj()
    let result = _func_AquaticAnimal_typeName(cself, &err)
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
    let scToSwiftResult = String(cString: result)
    defer {
      result.deallocate()
    }
    return scToSwiftResult
  }

}

public class Frog: AquaticAnimal, TerrestrialAnimal {
  public convenience init() {
    self.init(create_Frog(), true)
  }

  public override func typeName() -> String {

    var err = ErrorObj()
    let result = _func_Frog_typeName(cself, &err)
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
    let scToSwiftResult = String(cString: result)
    defer {
      result.deallocate()
    }
    return scToSwiftResult
  }

}

public class AnimalUsage {

  public let cself: UnsafeMutableRawPointer
  public let owner: Bool

  // internal main initializer
  internal required init(_ _cself: UnsafeMutableRawPointer, _ _owner: Bool = false) {
    self.cself = _cself
    self.owner = _owner
  }

  deinit {
    if owner {
      release_AnimalUsage(cself)
    }
  }

  public convenience init() {
    self.init(create_AnimalUsage(), true)
  }

  public static func getAnimalTypeName(animal: Animal) -> String {

    let swiftToScAnimal = animal.cself
    var err = ErrorObj()
    let result = _func_AnimalUsage_getAnimalTypeName(swiftToScAnimal, &err)
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
    let scToSwiftResult = String(cString: result)
    defer {
      result.deallocate()
    }
    return scToSwiftResult
  }

  public static func getAquaticAnimalTypeName(animal: AquaticAnimal) -> String {

    let swiftToScAnimal = animal.cself
    var err = ErrorObj()
    let result = _func_AnimalUsage_getAquaticAnimalTypeName(swiftToScAnimal, &err)
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
    let scToSwiftResult = String(cString: result)
    defer {
      result.deallocate()
    }
    return scToSwiftResult
  }

  public func getAnimal() -> Animal {

    var err = ErrorObj()
    let result = _func_AnimalUsage_getAnimal(cself, &err)
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
    let scToSwiftResult = AnimalImpl(result)
    return scToSwiftResult
  }

  public func getAquaticAnimal() -> AquaticAnimal {

    var err = ErrorObj()
    let result = _func_AnimalUsage_getAquaticAnimal(cself, &err)
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
    let scToSwiftResult = AquaticAnimal(result)
    return scToSwiftResult
  }

  public func getFrog() -> Frog {

    var err = ErrorObj()
    let result = _func_AnimalUsage_getFrog(cself, &err)
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
    let scToSwiftResult = Frog(result)
    return scToSwiftResult
  }

}
