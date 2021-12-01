/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 12/01/2021-14:32.
 * Please do not change it manually.
 */

import CWrapper
import Foundation

public class GeometricFigure  {
    
    public let cself : CDataObj
    public let owner : Bool

    // internal main initializer
    internal required init(_ _cself: CDataObj, _ _owner: Bool = false) {
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
            var sc_to_swift_result: Parallelogram
            let resultIndex = Int(result.index)
            switch(resultIndex) {
              case(1):
                sc_to_swift_result = RectangleImpl(result)
              case(2):
                sc_to_swift_result = RhombusFigureImpl(result)
              case(3):
                sc_to_swift_result = Square(result)
              default:
                sc_to_swift_result = ParallelogramImpl(result)
            }
            return sc_to_swift_result
        }
        
        
        set(value) {
            let swift_to_sc_value = value.cself
            _prop_set_GeometricFigure_parallelogram(cself, swift_to_sc_value)
        }
        
    }

    public var nullableParallelogram: Parallelogram? {
        get {
            let result = _prop_get_GeometricFigure_nullableParallelogram(cself)
            var sc_to_swift_result: Parallelogram? = nil
            let resultIndex = Int(result.index)
            switch(resultIndex) {
              case(1):
                if (result.ptr != nil) {
                    sc_to_swift_result = RectangleImpl(result)
                }
              case(2):
                if (result.ptr != nil) {
                    sc_to_swift_result = RhombusFigureImpl(result)
                }
              case(3):
                if (result.ptr != nil) {
                    sc_to_swift_result = Square(result)
                }
              default:
                if (result.ptr != nil) {
                sc_to_swift_result = ParallelogramImpl(result)
            }
            }
            return sc_to_swift_result
        }
        
        
        set(value) {
            let swift_to_sc_value = CDataObj(index: 0, ptr: value?.cself.ptr)
            _prop_set_GeometricFigure_nullableParallelogram(cself, swift_to_sc_value)
        }
        
    }
    
}

public class MyVehicle  {
    
    public let cself : CDataObj
    public let owner : Bool

    // internal main initializer
    internal required init(_ _cself: CDataObj, _ _owner: Bool = false) {
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
    
    public var vehicle: Vehicle? {
        get {
            let result = _prop_get_MyVehicle_vehicle(cself)
            var sc_to_swift_result: Vehicle? = nil
                let resultIndex = Int(result.index)
                switch(resultIndex) {
                  case(1):
                    if (result.ptr != nil) {
                        sc_to_swift_result = Bicycle(result, true)
                    }
                  default:
                    if (result.ptr != nil) {
                    sc_to_swift_result = Vehicle(result, true)
                }
                }
            return sc_to_swift_result
        }
        
        
        set(value) {
            let swift_to_sc_value = CDataObj(index: 0, ptr: value?.cself.ptr)
            _prop_set_MyVehicle_vehicle(cself, swift_to_sc_value)
        }
        
    }
    
}

public class MyBicycle  {
    
    public let cself : CDataObj
    public let owner : Bool

    // internal main initializer
    internal required init(_ _cself: CDataObj, _ _owner: Bool = false) {
        self.cself = _cself
        self.owner = _owner
    }
    deinit {
        if owner {
            release_MyBicycle(cself)
        }
    }
    
    
    public convenience init(b: Bicycle) {

        let swift_to_sc_b = b.cself
        self.init(create_MyBicycle(swift_to_sc_b), true)
    }
    
    public var bicycle: Bicycle {
        get {
            let result = _prop_get_MyBicycle_bicycle(cself)
            var sc_to_swift_result: Bicycle
                sc_to_swift_result = Bicycle(result, true)
            return sc_to_swift_result
        }
        
        
        set(value) {
            let swift_to_sc_value = value.cself
            _prop_set_MyBicycle_bicycle(cself, swift_to_sc_value)
        }
        
    }
    
}

public class MyCalendar  {
    
    public let cself : CDataObj
    public let owner : Bool

    // internal main initializer
    internal required init(_ _cself: CDataObj, _ _owner: Bool = false) {
        self.cself = _cself
        self.owner = _owner
    }
    deinit {
        if owner {
            release_MyCalendar(cself)
        }
    }
    
    
    public convenience init(events: Array<MyDate>) {

        let _data_swift_to_sc_events = UnsafeMutablePointer<CDataObj>.allocate(capacity: events.count)
        var swift_to_sc_events = CDataArray()
        swift_to_sc_events.data = UnsafeMutableRawPointer(_data_swift_to_sc_events)
        swift_to_sc_events.size = Int64(events.count)
        for _i in 0..<events.count {
            let value_events = events[_i]
            let swift_to_sc_value_events = value_events.cself
            _data_swift_to_sc_events[_i] = swift_to_sc_value_events
        }
        self.init(create_MyCalendar(swift_to_sc_events), true)
        
        swift_to_sc_events.data.deallocate()
    }
    
    public var events: Array<MyDate> {
        get {
            let result = _prop_get_MyCalendar_events(cself)
            let _tmp_result_data = UnsafeBufferPointer<CDataObj>(start: result.data.assumingMemoryBound(to: CDataObj.self), count: Int(result.size))
            var sc_to_swift_result: [MyDate] = []
            defer {
              _tmp_result_data.deallocate()
            }
            for _i in 0..<Int(result.size) {
                let value_result = _tmp_result_data[_i]
                var sc_to_swift_value_result: MyDate
                    let valueResultIndex = Int(value_result.index)
                    switch(valueResultIndex) {
                      case(1):
                        sc_to_swift_value_result = DateTime(value_result, true)
                      default:
                        sc_to_swift_value_result = MyDate(value_result, true)
                    }
                sc_to_swift_result.append(sc_to_swift_value_result)
            }
            return sc_to_swift_result
        }
        
    }
    
    public func addEvent(e: MyDate) -> Void {

        let swift_to_sc_e = e.cself
        var err = ErrorObj()
        _func_MyCalendar_addEvent(cself, swift_to_sc_e, &err)
        let err_type = Int(err.err_type)
        if (err_type != 0) {
            switch(err_type) {
                case(1):
                    let exc_obj = StdException(CDataObj(index: 0, ptr: err.err_ptr), true)
                    ExceptionHandler.handleUncaughtException(exc_obj.what())
                default:
                    ExceptionHandler.handleUncaughtException("Uncaught Exception")
            }
        }
    }
}