/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 12/06/2021-14:37.
 * Please do not change it manually.
 */

import CWrapper
import Foundation
/**
 * An example interface which descendant types are templates. Used for an example of downcast in target language.
 */
public protocol Container  {

    
    var cself : CObject { get }
    
    
    
    
}
extension Container {
    
    
}
public class ContainerImpl : Container {
    public let cself : CObject
    public let owner : Bool

    // internal main initializer
    internal required init(_ _cself: CObject, _ _owner: Bool = false) {
      self.cself = _cself
      self.owner = _owner
    }
    deinit {
      if owner {
        release_ContainerImpl(cself)
        cself.type?.deallocate()
      }
    }

    
}
/**
 * An example of usage for a type which descendants are template types.
 * Used for an example of downcast in target language.
 */
public class ContainerHolder  {
    
    public let cself : CObject
    public let owner : Bool

    // internal main initializer
    internal required init(_ _cself: CObject, _ _owner: Bool = false) {
        self.cself = _cself
        self.owner = _owner
    }
    deinit {
        if owner {
            release_ContainerHolder(cself)
            cself.type?.deallocate()
        }
    }
    
    
    public convenience init(container: Container) {

        let swift_to_sc_container = container.cself
        var err = ErrorObj()
        self.init(create_ContainerHolder(swift_to_sc_container, &err), true)
        let err_type = Int(err.err_type)
        if (err_type != 0) {
            switch(err_type) {
                case(1):
                    let exc_obj = StdException(err.err_ptr, true)
                    ExceptionHandler.handleUncaughtException(exc_obj.what())
                default:
                    ExceptionHandler.handleUncaughtException("Uncaught Exception")
            }
        }
    }
    
    public var container: Container {
        get {
            let result = _prop_get_ContainerHolder_container(cself)
            var sc_to_swift_result: Container
            let resultIndex = String(cString: result.type)
            switch(resultIndex) {
              case("iegen::example::Stack<iegen::example::Project>"):
                sc_to_swift_result = StackPrj(result)
              case("iegen::example::Stack<iegen::example::Task>"):
                sc_to_swift_result = StackTask(result)
              case("iegen::example::Stack<iegen::example::Number<int>>"):
                sc_to_swift_result = StackNumInt(result)
              default:
                sc_to_swift_result = ContainerImpl(result)
            }
            return sc_to_swift_result
        }
        
    }
    
}