import Foundation

import CWrapper

/**
 * comments
 * 
 */
public class TemplateFunctions  {
    
    public let cself : UnsafeMutableRawPointer
    public let owner : Bool

    // internal main initializer
    internal required init(_ _cself: UnsafeMutableRawPointer , _ _owner: Bool = false) {
      self.cself = _cself
      self.owner = _owner
    }
    deinit {
      if owner {
        release_TemplateFunctions(cself)
      }
    }
    
    /**
     * comments
     * 
     */
    public convenience init() {

        self.init(create_TemplateFunctions(), true)
    }
    
    /**
     * comments
     * 
     */
    public func max(arg0: Int, arg1: Int) -> Int {

        let swift_to_sc_arg0 = CInt(arg0)
        let swift_to_sc_arg1 = CInt(arg1)
        let result = _func_TemplateFunctions_maxInt(cself, swift_to_sc_arg0, swift_to_sc_arg1);
        let sc_to_swift_result = Int(result)
        return sc_to_swift_result;
    }
    /**
     * comments
     * 
     */
    public func max(arg0: String, arg1: String) -> String {

        let swift_to_sc_arg0 = strdup(arg0)!
        let swift_to_sc_arg1 = strdup(arg1)!
        let result = _func_TemplateFunctions_maxString(cself, swift_to_sc_arg0, swift_to_sc_arg1);
        let sc_to_swift_result = String(cString: result)
        defer{
          result.deallocate()
        }
        return sc_to_swift_result;
    }
    /**
     * comments
     * 
     */
    public func makePair(arg0: Project, arg1: Project) -> (Project, Project) {

        let swift_to_sc_arg0 = arg0.cself
        let swift_to_sc_arg1 = arg1.cself
        let result = _func_TemplateFunctions_makePairProjectProject(cself, swift_to_sc_arg0, swift_to_sc_arg1);
        let _tmp_pair_first_result_data = UnsafeBufferPointer<UnsafeMutableRawPointer>(start: result.first.assumingMemoryBound(to: UnsafeMutableRawPointer.self), count: 1)
        let _tmp_pair_second_result_data = UnsafeBufferPointer<UnsafeMutableRawPointer>(start: result.second.assumingMemoryBound(to: UnsafeMutableRawPointer.self), count: 1)
        defer {
          _tmp_pair_first_result_data.deallocate()
          _tmp_pair_second_result_data.deallocate()
        }
        let first_result = _tmp_pair_first_result_data[0];
        let second_result = _tmp_pair_second_result_data[0];
        let sc_to_swift_first_result = Project(first_result)
        let sc_to_swift_second_result = Project(second_result)
        let sc_to_swift_result: (Project, Project) = ( sc_to_swift_first_result, sc_to_swift_second_result )
        return sc_to_swift_result;
    }
    /**
     * comments
     * 
     */
    public func makePair(arg0: Task, arg1: Project) -> (Task, Project) {

        let swift_to_sc_arg0 = arg0.cself
        let swift_to_sc_arg1 = arg1.cself
        let result = _func_TemplateFunctions_makePairTaskProject(cself, swift_to_sc_arg0, swift_to_sc_arg1);
        let _tmp_pair_first_result_data = UnsafeBufferPointer<UnsafeMutableRawPointer>(start: result.first.assumingMemoryBound(to: UnsafeMutableRawPointer.self), count: 1)
        let _tmp_pair_second_result_data = UnsafeBufferPointer<UnsafeMutableRawPointer>(start: result.second.assumingMemoryBound(to: UnsafeMutableRawPointer.self), count: 1)
        defer {
          _tmp_pair_first_result_data.deallocate()
          _tmp_pair_second_result_data.deallocate()
        }
        let first_result = _tmp_pair_first_result_data[0];
        let second_result = _tmp_pair_second_result_data[0];
        let sc_to_swift_first_result = Task(first_result)
        let sc_to_swift_second_result = Project(second_result)
        let sc_to_swift_result: (Task, Project) = ( sc_to_swift_first_result, sc_to_swift_second_result )
        return sc_to_swift_result;
    }
}