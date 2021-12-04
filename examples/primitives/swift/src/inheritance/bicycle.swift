/**
 * ,--.,------. ,----.   ,------.,--.  ,--.
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  |
 * |  ||  `--, |  | .---.|  `--, |  |' '  |
 * |  ||  `---.'  '--'  ||  `---.|  | `   |
 * `--'`------' `------' `------'`--'  `--'
 * 
 * This file is generated by iegen on 12/04/2021-11:54.
 * Please do not change it manually.
 */

import CWrapper
import Foundation

public class Bicycle: Vehicle {
  public convenience init(numberOfSeats: Int) {
    let swiftToScNumberOfSeats = CInt(numberOfSeats)
    self.init(create_Bicycle(swiftToScNumberOfSeats), true)
  }

  public override func type() -> String {

    var err = ErrorObj()
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
    let result = _func_Bicycle_type(cself, &err)
    let scToSwiftResult = String(cString: result)
    defer {
      result.deallocate()
    }
    return scToSwiftResult
  }

}
