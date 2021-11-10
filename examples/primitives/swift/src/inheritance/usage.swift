/**
 * ,--.,------. ,----.   ,------.,--.  ,--.
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  |
 * |  ||  `--, |  | .---.|  `--, |  |' '  |
 * |  ||  `---.'  '--'  ||  `---.|  | `   |
 * `--'`------' `------' `------'`--'  `--'
 * 
 * This file is generated by iegen on 11/10/2021-06:31.
 * Please do not change it manually.
 */

import CWrapper
import Foundation

public class GeometricFigure {

  public let cself: UnsafeMutableRawPointer
  public let owner: Bool

  // internal main initializer
  internal required init(_ _cself: UnsafeMutableRawPointer, _ _owner: Bool = false) {
    self.cself = _cself
    self.owner = _owner
  }

  deinit {
    if owner {
      release_GeometricFigure(cself)
    }
  }

  public convenience init(p: Parallelogram) {
    let swift_to_sc_p = p.cself
    self.init(create_GeometricFigure(swift_to_sc_p), true)
  }

  public var parallelogram: Parallelogram {
    get {
      let result = _prop_get_GeometricFigure_parallelogram(cself)
      let sc_to_swift_result = ParallelogramImpl(result)
      return sc_to_swift_result
    }

    set(value) {
      let swift_to_sc_value = value.cself
      _prop_set_GeometricFigure_parallelogram(cself, swift_to_sc_value)
    }
  }

}

public class MyVehicle {

  public let cself: UnsafeMutableRawPointer
  public let owner: Bool

  // internal main initializer
  internal required init(_ _cself: UnsafeMutableRawPointer, _ _owner: Bool = false) {
    self.cself = _cself
    self.owner = _owner
  }

  deinit {
    if owner {
      release_MyVehicle(cself)
    }
  }

  public convenience init(v: Vehicle) {
    let swift_to_sc_v = v.cself
    self.init(create_MyVehicle(swift_to_sc_v), true)
  }

  public var vehicle: Vehicle {
    get {
      let result = _prop_get_MyVehicle_vehicle(cself)
      let sc_to_swift_result = Vehicle(result, true)
      return sc_to_swift_result
    }

    set(value) {
      let swift_to_sc_value = value.cself
      _prop_set_MyVehicle_vehicle(cself, swift_to_sc_value)
    }
  }

}
