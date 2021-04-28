import Foundation

import CWrapper

/**
 * comments
 * 
 */
public class VectorItem  {
    
    public let cself : UnsafeMutableRawPointer
    public let owner : Bool

    // internal main initializer
    internal required init(_ _cself: UnsafeMutableRawPointer , _ _owner: Bool = false) {
      self.cself = _cself
      self.owner = _owner
    }
    deinit {
      if owner {
        release_VectorItem(cself)
      }
    }
    
    /**
     * comments
     * 
     */
    public convenience init(_value: Int) {

        let swift_to_sc__value = CInt(_value)
        self.init(create_VectorItem(swift_to_sc__value), true)
    }
    
    /**
     * comments
     * 
     */
    public var value: Int {
          get {
            let result = _prop_get_VectorItem_value(cself);
            let sc_to_swift_result = Int(result)
            return sc_to_swift_result
          }
          
          
          set(value) {
            let swift_to_sc_value = CInt(value)
            _prop_set_VectorItem_value(cself, swift_to_sc_value)
          }
          
    }
    
}
/**
 * comments
 * 
 */
public class VectorExamples  {
    
    public let cself : UnsafeMutableRawPointer
    public let owner : Bool

    // internal main initializer
    internal required init(_ _cself: UnsafeMutableRawPointer , _ _owner: Bool = false) {
      self.cself = _cself
      self.owner = _owner
    }
    deinit {
      if owner {
        release_VectorExamples(cself)
      }
    }
    
    /**
     * comments
     * 
     */
    public convenience init() {

        self.init(create_VectorExamples(), true)
    }
    
    /**
     * comments
     * 
     */
    public func addIntVector(v: Array<Int>) -> Void {

        let _data_swift_to_sc_v = UnsafeMutablePointer<CInt>.allocate(capacity: v.count)
        defer {
          _data_swift_to_sc_v.deallocate()
        }
        var swift_to_sc_v = CDataArray()
        swift_to_sc_v.data = UnsafeMutableRawPointer(_data_swift_to_sc_v)
        swift_to_sc_v.size = Int64(v.count)
        for _i in 0..<v.count {
          let value = v[_i];
          let swift_to_sc_value = CInt(value)
          _data_swift_to_sc_v[_i] = swift_to_sc_value;
        }
        _func_VectorExamples_addIntVector(cself, swift_to_sc_v);
    }
    /**
     * comments
     * 
     */
    public func addObjVector(v: Array<VectorItem>) -> Void {

        let _data_swift_to_sc_v = UnsafeMutablePointer<UnsafeMutableRawPointer>.allocate(capacity: v.count)
        defer {
          _data_swift_to_sc_v.deallocate()
        }
        var swift_to_sc_v = CDataArray()
        swift_to_sc_v.data = UnsafeMutableRawPointer(_data_swift_to_sc_v)
        swift_to_sc_v.size = Int64(v.count)
        for _i in 0..<v.count {
          let value = v[_i];
          let swift_to_sc_value = value.cself
          _data_swift_to_sc_v[_i] = swift_to_sc_value;
        }
        _func_VectorExamples_addObjVector(cself, swift_to_sc_v);
    }
    /**
     * comments
     * 
     */
    public func addStringVector(v: Array<String>) -> Void {

        let _data_swift_to_sc_v = UnsafeMutablePointer<UnsafeMutablePointer<CChar>>.allocate(capacity: v.count)
        defer {
          _data_swift_to_sc_v.deallocate()
        }
        var swift_to_sc_v = CDataArray()
        swift_to_sc_v.data = UnsafeMutableRawPointer(_data_swift_to_sc_v)
        swift_to_sc_v.size = Int64(v.count)
        for _i in 0..<v.count {
          let value = v[_i];
          let swift_to_sc_value = strdup(value)!
          _data_swift_to_sc_v[_i] = swift_to_sc_value;
        }
        _func_VectorExamples_addStringVector(cself, swift_to_sc_v);
    }
    /**
     * comments
     * 
     */
    public func getStringVector() -> Array<String> {

        let result = _func_VectorExamples_getStringVector(cself);
        let _tmp_result_data = UnsafeBufferPointer<UnsafeMutablePointer<CChar>>(start: result.data.assumingMemoryBound(to: UnsafeMutablePointer<CChar>.self), count: Int(result.size))
        var sc_to_swift_result: [String] = [] 
        defer {
          _tmp_result_data.deallocate()
        }
        for _i in 0..<Int(result.size) {
          let value_result = _tmp_result_data[_i];
          let sc_to_swift_value_result = String(cString: value_result)
            defer{
              value_result.deallocate()
            }
          sc_to_swift_result.append(sc_to_swift_value_result);
        }
        return sc_to_swift_result;
    }
    /**
     * comments
     * 
     */
    public func getObjVector() -> Array<VectorItem> {

        let result = _func_VectorExamples_getObjVector(cself);
        let _tmp_result_data = UnsafeBufferPointer<UnsafeMutableRawPointer>(start: result.data.assumingMemoryBound(to: UnsafeMutableRawPointer.self), count: Int(result.size))
        var sc_to_swift_result: [VectorItem] = [] 
        defer {
          _tmp_result_data.deallocate()
        }
        for _i in 0..<Int(result.size) {
          let value_result = _tmp_result_data[_i];
          let sc_to_swift_value_result = VectorItem(value_result)
          sc_to_swift_result.append(sc_to_swift_value_result);
        }
        return sc_to_swift_result;
    }
    /**
     * comments
     * 
     */
    public func getIntVector() -> Array<Int> {

        let result = _func_VectorExamples_getIntVector(cself);
        let _tmp_result_data = UnsafeBufferPointer<CInt>(start: result.data.assumingMemoryBound(to: CInt.self), count: Int(result.size))
        var sc_to_swift_result: [Int] = [] 
        defer {
          _tmp_result_data.deallocate()
        }
        for _i in 0..<Int(result.size) {
          let value_result = _tmp_result_data[_i];
          let sc_to_swift_value_result = Int(value_result)
          sc_to_swift_result.append(sc_to_swift_value_result);
        }
        return sc_to_swift_result;
    }
}