import Foundation

import CWrapper

/**
 * Addressable is a base class for all the objects, that have abs path.
 */
public protocol IAddressableRoot  {

    
    var cself : UnsafeMutableRawPointer { get }
    
    
    
    /**
     * comments
     * @brief Get object's abs path based on parent's abs path and object's name
     * @return the abs path of the object
     */
    func absPath() -> String 
}
extension IAddressableRoot {
    
    /**
     * comments
     * @brief Get object's abs path based on parent's abs path and object's name
     * @return the abs path of the object
     */
    public func absPath() -> String {

        let result = _func_AddressableRoot_absPath(cself);
        let sc_to_swift_result = String(cString: result)
        defer{
          result.deallocate()
        }
        return sc_to_swift_result;
    }
}
public class AddressableRoot : IAddressableRoot {
    public let cself : UnsafeMutableRawPointer
    public let owner : Bool

    // internal main initializer
    internal required init(_ _cself: UnsafeMutableRawPointer, _ _owner: Bool = false) {
      self.cself = _cself
      self.owner = _owner
    }
    deinit {
      if owner {
        release_AddressableRoot(cself)
      }
    }

    /**
     * comments
     */
    public convenience init(parent: Root, name: String) {

        let swift_to_sc_parent = parent.cself
        let swift_to_sc_name = strdup(name)!
        self.init(create_AddressableRoot(swift_to_sc_parent, swift_to_sc_name), true)
    }
}