import Foundation

import CWrapper

/**
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
     */
    public convenience init() {

        self.init(create_StackUsage(), true)
    }
    
    /**
     */
    public func firstItemOfSpecializedStack(p: StackProject) -> Project {

        let swift_to_sc_p = p.cself
        let result = _func_StackUsage_firstItemOfSpecializedStack(cself, swift_to_sc_p);
        let sc_to_swift_result = Project(result)
        return sc_to_swift_result;
    }
    /**
     */
    public func firstItemOfTemplateStack(arg0: StackProject) -> Project {

        let swift_to_sc_arg0 = arg0.cself
        let result = _func_StackUsage_firstItemOfTemplateStackProject(cself, swift_to_sc_arg0);
        let sc_to_swift_result = Project(result)
        return sc_to_swift_result;
    }
}