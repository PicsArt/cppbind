/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 02/03/2022-14:57.
 * Please do not change it manually.
 */

import CWrapper
import Foundation

public class GeometricFigure {

  public let cself: IEGenCObject
  public let owner: Bool

  // internal main initializer
  internal required init(_ _cself: IEGenCObject, _ _owner: Bool = false) {
    self.cself = _cself
    self.owner = _owner
  }

  deinit {
    release_GeometricFigure(cself, owner)
  }

  public convenience init(p: Parallelogram) {
    let swifttoscp = p.cself
    var err = IEGenCObject()
    self.init(create_GeometricFigure(swifttoscp, &err), true)
    if err.type != nil {
      let errorType = String(cString: err.type!)
      switch errorType {
      case ("std::exception"):
        let excObj = StdException(IEGenCObject(type: err.type, ptr: err.ptr), true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        ExceptionHandler.handleUncaughtException("Uncaught Exception")
      }
    }
  }

  public var parallelogram: Parallelogram {
    get {
      let result = _prop_get_GeometricFigure_parallelogram(cself)
      var sctoswiftresult: Parallelogram
      let resultIndex = String(cString: result.type)
      switch(resultIndex) {
      case("iegen::example::Rectangle"):
        sctoswiftresult = RectangleImpl(result)
      case("iegen::example::Rhombus"):
        sctoswiftresult = RhombusFigureImpl(result)
      case("iegen::example::Square"):
        sctoswiftresult = Square(result)
      default:
        sctoswiftresult = ParallelogramImpl(result)
      }
      return sctoswiftresult
    }

    set(value) {
      let swifttoscvalue = value.cself
      _prop_set_GeometricFigure_parallelogram(cself, swifttoscvalue)
    }
  }

  public var nullableParallelogram: Parallelogram? {
    get {
      let result = _prop_get_GeometricFigure_nullableParallelogram(cself)
      var sctoswiftresult: Parallelogram? = nil
      let resultIndex = String(cString: result.type)
      switch(resultIndex) {
      case("iegen::example::Rectangle"):
        if (result.ptr != nil) {
          sctoswiftresult = RectangleImpl(result)
        }
      case("iegen::example::Rhombus"):
        if (result.ptr != nil) {
          sctoswiftresult = RhombusFigureImpl(result)
        }
      case("iegen::example::Square"):
        if (result.ptr != nil) {
          sctoswiftresult = Square(result)
        }
      default:
        if (result.ptr != nil) {
          sctoswiftresult = ParallelogramImpl(result)
        }
      }
      return sctoswiftresult
    }

    set(value) {
      let swifttoscvalue = value?.cself ?? IEGenCObject(type: nil, ptr: nil)
      _prop_set_GeometricFigure_nullableParallelogram(cself, swifttoscvalue)
    }
  }

}

public class MyVehicle {

  public let cself: IEGenCObject
  public let owner: Bool

  // internal main initializer
  internal required init(_ _cself: IEGenCObject, _ _owner: Bool = false) {
    self.cself = _cself
    self.owner = _owner
  }

  deinit {
    release_MyVehicle(cself, owner)
  }

  public convenience init(v: Vehicle) {
    let swifttoscv = v.cself
    var err = IEGenCObject()
    self.init(create_MyVehicle(swifttoscv, &err), true)
    if err.type != nil {
      let errorType = String(cString: err.type!)
      switch errorType {
      case ("std::exception"):
        let excObj = StdException(IEGenCObject(type: err.type, ptr: err.ptr), true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        ExceptionHandler.handleUncaughtException("Uncaught Exception")
      }
    }
  }

  public var vehicle: Vehicle? {
    get {
      let result = _prop_get_MyVehicle_vehicle(cself)
      var sctoswiftresult: Vehicle? = nil
      let resultIndex = String(cString: result.type)
      switch(resultIndex) {
      case("iegen::example::Bicycle"):
        if (result.ptr != nil) {
          sctoswiftresult = Bicycle(result, true)
        }
      default:
        if (result.ptr != nil) {
          sctoswiftresult = Vehicle(result, true)
        }
      }
      return sctoswiftresult
    }

    set(value) {
      let swifttoscvalue = value?.cself ?? IEGenCObject(type: nil, ptr: nil)
      _prop_set_MyVehicle_vehicle(cself, swifttoscvalue)
    }
  }

}

public class MyBicycle {

  public let cself: IEGenCObject
  public let owner: Bool

  // internal main initializer
  internal required init(_ _cself: IEGenCObject, _ _owner: Bool = false) {
    self.cself = _cself
    self.owner = _owner
  }

  deinit {
    release_MyBicycle(cself, owner)
  }

  public convenience init(b: Bicycle) {
    let swifttoscb = b.cself
    var err = IEGenCObject()
    self.init(create_MyBicycle(swifttoscb, &err), true)
    if err.type != nil {
      let errorType = String(cString: err.type!)
      switch errorType {
      case ("std::exception"):
        let excObj = StdException(IEGenCObject(type: err.type, ptr: err.ptr), true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        ExceptionHandler.handleUncaughtException("Uncaught Exception")
      }
    }
  }

  public var bicycle: Bicycle {
    get {
      let result = _prop_get_MyBicycle_bicycle(cself)
      var sctoswiftresult: Bicycle
      sctoswiftresult = Bicycle(result, true)
      return sctoswiftresult
    }

    set(value) {
      let swifttoscvalue = value.cself
      _prop_set_MyBicycle_bicycle(cself, swifttoscvalue)
    }
  }

}

public class MyCalendar {

  public let cself: IEGenCObject
  public let owner: Bool

  // internal main initializer
  internal required init(_ _cself: IEGenCObject, _ _owner: Bool = false) {
    self.cself = _cself
    self.owner = _owner
  }

  deinit {
    release_MyCalendar(cself, owner)
  }

  public convenience init(events: Array<MyDate>) {
    let _swifttosceventsData = UnsafeMutablePointer<IEGenCObject>.allocate(capacity: events.count)
    var swifttoscevents = IEGenCDataArray()
    swifttoscevents.data = UnsafeMutableRawPointer(_swifttosceventsData)
    swifttoscevents.size = Int64(events.count)
    for i in 0..<events.count {
      let eventsVal = events[i]
      let swifttosceventsVal = eventsVal.cself
      _swifttosceventsData[i] = swifttosceventsVal
    }
    var err = IEGenCObject()
    self.init(create_MyCalendar(swifttoscevents, &err), true)
    
    swifttoscevents.data.deallocate()
    if err.type != nil {
      let errorType = String(cString: err.type!)
      switch errorType {
      case ("std::exception"):
        let excObj = StdException(IEGenCObject(type: err.type, ptr: err.ptr), true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        ExceptionHandler.handleUncaughtException("Uncaught Exception")
      }
    }
  }

  public var events: Array<MyDate> {
    get {
      let result = _prop_get_MyCalendar_events(cself)
      let _resultBuffer = UnsafeBufferPointer<IEGenCObject>(
        start: result.data.assumingMemoryBound(to: IEGenCObject.self),
        count: Int(result.size))
      var sctoswiftresult: [MyDate] = []
      defer {
        _resultBuffer.deallocate()
      }
      for i in 0..<Int(result.size) {
        let resultValue = _resultBuffer[i]
        var sctoswiftresultValue: MyDate
        let resultValueIndex = String(cString: resultValue.type)
        switch(resultValueIndex) {
        case("iegen::example::DateTime"):
          sctoswiftresultValue = DateTime(resultValue, true)
        default:
          sctoswiftresultValue = MyDate(resultValue, true)
        }
        sctoswiftresult.append(sctoswiftresultValue)
      }
      return sctoswiftresult
    }
  }

  public func addEvent(e: MyDate) -> Void {

    let swifttosce = e.cself
    var err = IEGenCObject()
    _func_MyCalendar_addEvent(cself, swifttosce, &err)
    if err.type != nil {
      let errorType = String(cString: err.type!)
      switch errorType {
      case ("std::exception"):
        let excObj = StdException(IEGenCObject(type: err.type, ptr: err.ptr), true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        ExceptionHandler.handleUncaughtException("Uncaught Exception")
      }
    }
  }

}
