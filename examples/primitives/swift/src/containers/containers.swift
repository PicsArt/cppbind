import Foundation



/**
 * comments
 * 
 */
public class Item  {
    
    public let cself : UnsafeMutableRawPointer
    public let owner : Bool

    // internal main initializer
    internal required init(_ _cself: UnsafeMutableRawPointer , _ _owner: Bool = false) {
      self.cself = _cself
      self.owner = _owner
    }
    deinit {
      if owner {
        release_Item(cself)
      }
    }
    
    /**
     * comments
     * 
     */
    public convenience init(_value: Int) {

        let swift_to_sc__value = CInt(_value)
        self.init(create_Item(swift_to_sc__value), true)
    }
    
    /**
     * comments
     * 
     */
    public var value: Int {
          get {
            let result = _prop_get_Item_value(cself);
            let sc_to_swift_result = Int(result)
            return sc_to_swift_result
          }
          
          
          set(value) {
            let swift_to_sc_value = CInt(value)
            _prop_set_Item_value(cself, swift_to_sc_value)
          }
          
    }
    
}
/**
 * comments
 * 
 */
public class Containers  {
    
    public let cself : UnsafeMutableRawPointer
    public let owner : Bool

    // internal main initializer
    internal required init(_ _cself: UnsafeMutableRawPointer , _ _owner: Bool = false) {
      self.cself = _cself
      self.owner = _owner
    }
    deinit {
      if owner {
        release_Containers(cself)
      }
    }
    
    /**
     * comments
     * 
     */
    public convenience init() {

        self.init(create_Containers(), true)
    }
    
    /**
     * comments
     * 
     */
    public func addStringPair(info: (String, String)) -> Void {

        let _first_swift_to_sc_info = UnsafeMutablePointer<UnsafeMutablePointer<CChar>>.allocate(capacity: 1)
        let _second_swift_to_sc_info = UnsafeMutablePointer<UnsafeMutablePointer<CChar>>.allocate(capacity: 1)
        defer {
          _first_swift_to_sc_info.deallocate()
          _second_swift_to_sc_info.deallocate()
        }
        var swift_to_sc_info = CDataPair()
        swift_to_sc_info.first = UnsafeMutableRawPointer(_first_swift_to_sc_info)
        swift_to_sc_info.second = UnsafeMutableRawPointer(_second_swift_to_sc_info)
        let first_info = info.0
        let second_info = info.1
        let swift_to_sc_first_info = strdup(first_info)!
        let swift_to_sc_second_info = strdup(second_info)!
        _first_swift_to_sc_info[0] = swift_to_sc_first_info
        _second_swift_to_sc_info[0] = swift_to_sc_second_info
        _func_Containers_addStringPair(cself, swift_to_sc_info);
    }
    /**
     * comments
     * 
     */
    public func addIntMap(info: Dictionary<Int, Int>) -> Void {

        let _key_swift_to_sc_info = UnsafeMutablePointer<CInt>.allocate(capacity: info.count)
        let _val_swift_to_sc_info = UnsafeMutablePointer<CInt>.allocate(capacity: info.count)
        defer {
          _key_swift_to_sc_info.deallocate()
          _val_swift_to_sc_info.deallocate()
        } 
        var swift_to_sc_info = CDataMap()
        swift_to_sc_info.keys = UnsafeMutableRawPointer(_key_swift_to_sc_info)
        swift_to_sc_info.values = UnsafeMutableRawPointer(_val_swift_to_sc_info)
        swift_to_sc_info.size = Int64(info.count)
        var _i_info = 0
        for (key, val) in info {
            let swift_to_sc_key = CInt(key)
            let swift_to_sc_val = CInt(val)
            _key_swift_to_sc_info[_i_info] = swift_to_sc_key
            _val_swift_to_sc_info[_i_info] = swift_to_sc_val
            _i_info += 1
        }
        _func_Containers_addIntMap(cself, swift_to_sc_info);
    }
    /**
     * comments
     * 
     */
    public func addStringMap(info: Dictionary<String, String>) -> Void {

        let _key_swift_to_sc_info = UnsafeMutablePointer<UnsafeMutablePointer<CChar>>.allocate(capacity: info.count)
        let _val_swift_to_sc_info = UnsafeMutablePointer<UnsafeMutablePointer<CChar>>.allocate(capacity: info.count)
        defer {
          _key_swift_to_sc_info.deallocate()
          _val_swift_to_sc_info.deallocate()
        } 
        var swift_to_sc_info = CDataMap()
        swift_to_sc_info.keys = UnsafeMutableRawPointer(_key_swift_to_sc_info)
        swift_to_sc_info.values = UnsafeMutableRawPointer(_val_swift_to_sc_info)
        swift_to_sc_info.size = Int64(info.count)
        var _i_info = 0
        for (key, val) in info {
            let swift_to_sc_key = strdup(key)!
            let swift_to_sc_val = strdup(val)!
            _key_swift_to_sc_info[_i_info] = swift_to_sc_key
            _val_swift_to_sc_info[_i_info] = swift_to_sc_val
            _i_info += 1
        }
        _func_Containers_addStringMap(cself, swift_to_sc_info);
    }
    /**
     * comments
     * 
     */
    public func addIntPair(info: (Int, Int)) -> Void {

        let _first_swift_to_sc_info = UnsafeMutablePointer<CInt>.allocate(capacity: 1)
        let _second_swift_to_sc_info = UnsafeMutablePointer<CInt>.allocate(capacity: 1)
        defer {
          _first_swift_to_sc_info.deallocate()
          _second_swift_to_sc_info.deallocate()
        }
        var swift_to_sc_info = CDataPair()
        swift_to_sc_info.first = UnsafeMutableRawPointer(_first_swift_to_sc_info)
        swift_to_sc_info.second = UnsafeMutableRawPointer(_second_swift_to_sc_info)
        let first_info = info.0
        let second_info = info.1
        let swift_to_sc_first_info = CInt(first_info)
        let swift_to_sc_second_info = CInt(second_info)
        _first_swift_to_sc_info[0] = swift_to_sc_first_info
        _second_swift_to_sc_info[0] = swift_to_sc_second_info
        _func_Containers_addIntPair(cself, swift_to_sc_info);
    }
    /**
     * comments
     * 
     */
    public func getStringPair() -> (String, String) {

        let result = _func_Containers_getStringPair(cself);
        let _tmp_pair_first_result_data = UnsafeBufferPointer<UnsafeMutablePointer<CChar>>(start: result.first.assumingMemoryBound(to: UnsafeMutablePointer<CChar>.self), count: 1)
        let _tmp_pair_second_result_data = UnsafeBufferPointer<UnsafeMutablePointer<CChar>>(start: result.second.assumingMemoryBound(to: UnsafeMutablePointer<CChar>.self), count: 1)
        defer {
          _tmp_pair_first_result_data.deallocate()
          _tmp_pair_second_result_data.deallocate()
        }
        let first_result = _tmp_pair_first_result_data[0];
        let second_result = _tmp_pair_second_result_data[0];
        let sc_to_swift_first_result = String(cString: first_result)
            defer{
              first_result.deallocate()
            }
        let sc_to_swift_second_result = String(cString: second_result)
            defer{
              second_result.deallocate()
            }
        let sc_to_swift_result: (String, String) = ( sc_to_swift_first_result, sc_to_swift_second_result )
        return sc_to_swift_result;
    }
    /**
     * comments
     * 
     */
    public func getStringMap() -> Dictionary<String, String> {

        let result = _func_Containers_getStringMap(cself);
        let _tmp_k_result_data = UnsafeBufferPointer<UnsafeMutablePointer<CChar>>(start: result.keys.assumingMemoryBound(to: UnsafeMutablePointer<CChar>.self), count: Int(result.size))
        let _tmp_v_result_data = UnsafeBufferPointer<UnsafeMutablePointer<CChar>>(start: result.values.assumingMemoryBound(to: UnsafeMutablePointer<CChar>.self), count: Int(result.size))
        var sc_to_swift_result: [String:String] = [:] 
        defer {
          _tmp_k_result_data.deallocate()
          _tmp_v_result_data.deallocate()
        } 
        for _i in 0..<Int(result.size) {
          let key_result = _tmp_k_result_data[_i];
          let value_result = _tmp_v_result_data[_i];
          do {
            let sc_to_swift_key_result = String(cString: key_result)
            defer{
              key_result.deallocate()
            }
            let sc_to_swift_value_result = String(cString: value_result)
            defer{
              value_result.deallocate()
            }
            sc_to_swift_result[sc_to_swift_key_result] = sc_to_swift_value_result
          }
        }
        return sc_to_swift_result;
    }
    /**
     * comments
     * 
     */
    public func getIntMap() -> Dictionary<Int, Int> {

        let result = _func_Containers_getIntMap(cself);
        let _tmp_k_result_data = UnsafeBufferPointer<CInt>(start: result.keys.assumingMemoryBound(to: CInt.self), count: Int(result.size))
        let _tmp_v_result_data = UnsafeBufferPointer<CInt>(start: result.values.assumingMemoryBound(to: CInt.self), count: Int(result.size))
        var sc_to_swift_result: [Int:Int] = [:] 
        defer {
          _tmp_k_result_data.deallocate()
          _tmp_v_result_data.deallocate()
        } 
        for _i in 0..<Int(result.size) {
          let key_result = _tmp_k_result_data[_i];
          let value_result = _tmp_v_result_data[_i];
          do {
            let sc_to_swift_key_result = Int(key_result)
            let sc_to_swift_value_result = Int(value_result)
            sc_to_swift_result[sc_to_swift_key_result] = sc_to_swift_value_result
          }
        }
        return sc_to_swift_result;
    }
    /**
     * comments
     * 
     */
    public func getMap() -> Dictionary<String, Item> {

        let result = _func_Containers_getMap(cself);
        let _tmp_k_result_data = UnsafeBufferPointer<UnsafeMutablePointer<CChar>>(start: result.keys.assumingMemoryBound(to: UnsafeMutablePointer<CChar>.self), count: Int(result.size))
        let _tmp_v_result_data = UnsafeBufferPointer<UnsafeMutableRawPointer>(start: result.values.assumingMemoryBound(to: UnsafeMutableRawPointer.self), count: Int(result.size))
        var sc_to_swift_result: [String:Item] = [:] 
        defer {
          _tmp_k_result_data.deallocate()
          _tmp_v_result_data.deallocate()
        } 
        for _i in 0..<Int(result.size) {
          let key_result = _tmp_k_result_data[_i];
          let value_result = _tmp_v_result_data[_i];
          do {
            let sc_to_swift_key_result = String(cString: key_result)
            defer{
              key_result.deallocate()
            }
            let sc_to_swift_value_result = Item(value_result, true)
            sc_to_swift_result[sc_to_swift_key_result] = sc_to_swift_value_result
          }
        }
        return sc_to_swift_result;
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
        _func_Containers_addIntVector(cself, swift_to_sc_v);
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
        _func_Containers_addStringVector(cself, swift_to_sc_v);
    }
    /**
     * comments
     * 
     */
    public func getStringVector() -> Array<String> {

        let result = _func_Containers_getStringVector(cself);
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
    public func getIntVector() -> Array<Int> {

        let result = _func_Containers_getIntVector(cself);
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