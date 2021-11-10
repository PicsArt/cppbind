/**
 * ,--.,------. ,----.   ,------.,--.  ,--.
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  |
 * |  ||  `--, |  | .---.|  `--, |  |' '  |
 * |  ||  `---.'  '--'  ||  `---.|  | `   |
 * `--'`------' `------' `------'`--'  `--'
 * 
 * This file is generated by iegen on 11/09/2021-13:37.
 * Please do not change it manually.
 */

import CWrapper
import Foundation

/**
 * Class Frame.
 */
public class Frame {

  public let cself: UnsafeMutableRawPointer
  public let owner: Bool

  // internal main initializer
  internal required init(_ _cself: UnsafeMutableRawPointer, _ _owner: Bool = false) {
    self.cself = _cself
    self.owner = _owner
  }

  deinit {
    if owner {
      release_Frame(cself)
    }
  }

  public convenience init() {
    self.init(create_Frame(), true)
  }

  public var backgroundColor: Color {
    get {
      let result = _prop_get_Frame_backgroundColor(cself)
      let sc_to_swift_result_optional = Color(rawValue: result)
      if (sc_to_swift_result_optional == nil) {
        ExceptionHandler.handleUncaughtException("Internal error: unresolved reference to non existing field of Color enum.")
      }
      let sc_to_swift_result = sc_to_swift_result_optional!
      return sc_to_swift_result
    }

    set(value) {
      let swift_to_sc_value = value.rawValue
      _prop_set_Frame_backgroundColor(cself, swift_to_sc_value)
    }
  }

  public var backgroundColorShade: ColorShade {
    get {
      let result = _prop_get_Frame_backgroundColorShade(cself)
      let sc_to_swift_result_optional = ColorShade(rawValue: result)
      if (sc_to_swift_result_optional == nil) {
        ExceptionHandler.handleUncaughtException("Internal error: unresolved reference to non existing field of ColorShade enum.")
      }
      let sc_to_swift_result = sc_to_swift_result_optional!
      return sc_to_swift_result
    }

    set(value) {
      let swift_to_sc_value = value.rawValue
      _prop_set_Frame_backgroundColorShade(cself, swift_to_sc_value)
    }
  }

}
