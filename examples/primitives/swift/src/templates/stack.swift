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
public class StackTask  {
    
    public let cself : UnsafeMutableRawPointer
    public let owner : Bool

    // internal main initializer
    internal required init(_ _cself: UnsafeMutableRawPointer , _ _owner: Bool = false) {
      self.cself = _cself
      self.owner = _owner
    }
    deinit {
      if owner {
        release_StackTask(cself)
      }
    }
    
    /**
     */
    public convenience init() {

        self.init(create_StackTask(), true)
    }
    /**
     */
    public convenience init(st: Task) {

        let swift_to_sc_st = st.cself
        self.init(create_StackTask_1(swift_to_sc_st), true)
    }
    
    /**
     */
    public func push(item: Task) -> Void {

        let swift_to_sc_item = item.cself
        _func_StackTask_push(cself, swift_to_sc_item);
    }
    /**
     */
    public func pop() -> Void {

        _func_StackTask_pop(cself);
    }
    /**
     */
    public func top() -> Task {

        let result = _func_StackTask_top(cself);
        let sc_to_swift_result = Task(result)
        return sc_to_swift_result;
    }
    /**
     */
    public func empty() -> Bool {

        let result = _func_StackTask_empty(cself);
        
        return result;
    }
}