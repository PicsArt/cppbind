import Foundation

import CWrapper

/**
 */
public class StackProject  {
    
    public let cself : UnsafeMutableRawPointer
    public let owner : Bool

    // internal main initializer
    internal required init(_ _cself: UnsafeMutableRawPointer , _ _owner: Bool = false) {
      self.cself = _cself
      self.owner = _owner
    }
    deinit {
      if owner {
        release_StackProject(cself)
      }
    }
    
    /**
     */
    public convenience init() {

        self.init(create_StackProject(), true)
    }
    /**
     */
    public convenience init(st: Project) {

        let swift_to_sc_st = st.cself
        self.init(create_StackProject_1(swift_to_sc_st), true)
    }
    
    /**
     */
    public func push(item: Project) -> Void {

        let swift_to_sc_item = item.cself
        _func_StackProject_push(cself, swift_to_sc_item);
    }
    /**
     */
    public func pop() -> Void {

        _func_StackProject_pop(cself);
    }
    /**
     */
    public func top() -> Project {

        let result = _func_StackProject_top(cself);
        let sc_to_swift_result = Project(result)
        return sc_to_swift_result;
    }
    /**
     */
    public func empty() -> Bool {

        let result = _func_StackProject_empty(cself);
        
        return result;
    }
}
/**
 */
public class StackRoot  {
    
    public let cself : UnsafeMutableRawPointer
    public let owner : Bool

    // internal main initializer
    internal required init(_ _cself: UnsafeMutableRawPointer , _ _owner: Bool = false) {
      self.cself = _cself
      self.owner = _owner
    }
    deinit {
      if owner {
        release_StackRoot(cself)
      }
    }
    
    /**
     */
    public convenience init() {

        self.init(create_StackRoot(), true)
    }
    /**
     */
    public convenience init(st: Root) {

        let swift_to_sc_st = st.cself
        self.init(create_StackRoot_1(swift_to_sc_st), true)
    }
    
    /**
     */
    public func push(item: Root) -> Void {

        let swift_to_sc_item = item.cself
        _func_StackRoot_push(cself, swift_to_sc_item);
    }
    /**
     */
    public func pop() -> Void {

        _func_StackRoot_pop(cself);
    }
    /**
     */
    public func top() -> Root {

        let result = _func_StackRoot_top(cself);
        let sc_to_swift_result = Root(result)
        return sc_to_swift_result;
    }
    /**
     */
    public func empty() -> Bool {

        let result = _func_StackRoot_empty(cself);
        
        return result;
    }
}