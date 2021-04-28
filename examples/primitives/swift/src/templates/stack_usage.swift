import Foundation

import CWrapper

/**
 * comments
 * 
 */
public class StackUsage  {
    
    public let cself : UnsafeMutableRawPointer
    public let owner : Bool

    // internal main initializer
    internal required init(_ _cself: UnsafeMutableRawPointer , _ _owner: Bool = false) {
      self.cself = _cself
      self.owner = _owner
    }
    deinit {
      if owner {
        release_StackUsage(cself)
      }
    }
    
    /**
     * comments
     * 
     */
    public convenience init() {

        self.init(create_StackUsage(), true)
    }
    
    /**
     * comments
     * 
     */
    public func firstItemOfSpecialized(p: StackProject) -> Project {

        let swift_to_sc_p = p.cself
        let result = _func_StackUsage_firstItemOfSpecialized(cself, swift_to_sc_p);
        let sc_to_swift_result = Project(result)
        return sc_to_swift_result;
    }
    /**
     * comments
     * 
     */
    public func firstItemOfTemplate(arg0: StackProject) -> Project {

        let swift_to_sc_arg0 = arg0.cself
        let result = _func_StackUsage_firstItemOfTemplateProject(cself, swift_to_sc_arg0);
        let sc_to_swift_result = Project(result)
        return sc_to_swift_result;
    }
}