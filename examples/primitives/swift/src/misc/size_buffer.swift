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

/**
 * comments
 * 
 */
public class SizeUsage {

  public let cself: UnsafeMutableRawPointer
  public let owner: Bool

  // internal main initializer
  internal required init(_ _cself: UnsafeMutableRawPointer, _ _owner: Bool = false) {
    self.cself = _cself
    self.owner = _owner
  }

  deinit {
    if owner {
      release_SizeUsage(cself)
    }
  }

  /**
   * comments
   * 
   */
  public static func multiplyBy(size: (Float, Float), n: Int) -> (Float, Float) {

    let swiftToScSizeFirst = UnsafeMutablePointer<Float>.allocate(capacity: 1)
    let swiftToScSizeSecond = UnsafeMutablePointer<Float>.allocate(capacity: 1)
    defer {
      swiftToScSizeFirst.deallocate()
      swiftToScSizeSecond.deallocate()
    }
    var swiftToScSize = CDataPair()
    swiftToScSize.first = UnsafeMutableRawPointer(swiftToScSizeFirst)
    swiftToScSize.second = UnsafeMutableRawPointer(swiftToScSizeSecond)
    swiftToScSizeFirst[0] = size.0
    swiftToScSizeSecond[0] = size.1
    let swiftToScN = CInt(n)
    var err = ErrorObj()
    let result = _func_SizeUsage_multiplyBy(swiftToScSize, swiftToScN, &err)
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
    let resultFirstData = UnsafeBufferPointer<Float>(start: result.first.assumingMemoryBound(to: Float.self), count: 1)
    let resultSecondData = UnsafeBufferPointer<Float>(start: result.second.assumingMemoryBound(to: Float.self), count: 1)
    defer {
      resultFirstData.deallocate()
      resultSecondData.deallocate()
    }
    let scToSwiftResultFirst = resultFirstData[0]
    let scToSwiftResultSecond = resultSecondData[0]
    let scToSwiftResult: (Float, Float) = (scToSwiftResultFirst, scToSwiftResultSecond)
    return scToSwiftResult
  }

  /**
   * comments
   * 
   */
  public static func doubleSizeF(resolution: (Float, Float)) -> (Float, Float) {

    let swiftToScResolutionFirst = UnsafeMutablePointer<Float>.allocate(capacity: 1)
    let swiftToScResolutionSecond = UnsafeMutablePointer<Float>.allocate(capacity: 1)
    defer {
      swiftToScResolutionFirst.deallocate()
      swiftToScResolutionSecond.deallocate()
    }
    var swiftToScResolution = CDataPair()
    swiftToScResolution.first = UnsafeMutableRawPointer(swiftToScResolutionFirst)
    swiftToScResolution.second = UnsafeMutableRawPointer(swiftToScResolutionSecond)
    swiftToScResolutionFirst[0] = resolution.0
    swiftToScResolutionSecond[0] = resolution.1
    var err = ErrorObj()
    let result = _func_SizeUsage_doubleSizeF(swiftToScResolution, &err)
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
    let resultFirstData = UnsafeBufferPointer<Float>(start: result.first.assumingMemoryBound(to: Float.self), count: 1)
    let resultSecondData = UnsafeBufferPointer<Float>(start: result.second.assumingMemoryBound(to: Float.self), count: 1)
    defer {
      resultFirstData.deallocate()
      resultSecondData.deallocate()
    }
    let scToSwiftResultFirst = resultFirstData[0]
    let scToSwiftResultSecond = resultSecondData[0]
    let scToSwiftResult: (Float, Float) = (scToSwiftResultFirst, scToSwiftResultSecond)
    return scToSwiftResult
  }

}
