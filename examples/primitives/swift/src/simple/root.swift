import Foundation

import CWrapper

/**
 * comments
 * 
 */
public class Root  {
    
    public let cself : UnsafeMutableRawPointer
    public let owner : Bool

    // internal main initializer
    internal required init(_ _cself: UnsafeMutableRawPointer , _ _owner: Bool = false) {
      self.cself = _cself
      self.owner = _owner
    }
    deinit {
      if owner {
        release_Root(cself)
      }
    }
    
    /**
     * comments
     * 
     */
    public convenience init(_path: String) {

        let swift_to_sc__path = strdup(_path)!
        self.init(create_Root(swift_to_sc__path), true)
    }
    
    /**
     * comments
     * 
     */
    public var path: String {
          get {
            let result = _prop_get_Root_path(cself);
            let sc_to_swift_result = String(cString: result)
            defer{
              result.deallocate()
            }
            return sc_to_swift_result
          }
          
          
          set(value) {
            let swift_to_sc_value = strdup(value)!
            _prop_set_Root_path(cself, swift_to_sc_value)
          }
          
    }
    
}