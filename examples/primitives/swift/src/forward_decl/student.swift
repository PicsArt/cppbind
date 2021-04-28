import Foundation

import CWrapper

/**
 * comments
 * 
 */
public class Student  {
    
    public let cself : UnsafeMutableRawPointer
    public let owner : Bool

    // internal main initializer
    internal required init(_ _cself: UnsafeMutableRawPointer , _ _owner: Bool = false) {
      self.cself = _cself
      self.owner = _owner
    }
    deinit {
      if owner {
        release_Student(cself)
      }
    }
    
    /**
     */
    public convenience init() {

        self.init(create_Student(), true)
    }
    
    /**
     */
    public func addTeacher(t: Teacher) -> Void {

        let swift_to_sc_t = t.cself
        _func_Student_addTeacher(cself, swift_to_sc_t);
    }
    /**
     */
    public func teachers() -> Array<Teacher> {

        let result = _func_Student_teachers(cself);
        let _tmp_result_data = UnsafeBufferPointer<UnsafeMutableRawPointer>(start: result.data.assumingMemoryBound(to: UnsafeMutableRawPointer.self), count: Int(result.size))
        var sc_to_swift_result: [Teacher] = [] 
        defer {
          _tmp_result_data.deallocate()
        }
        for _i in 0..<Int(result.size) {
          let value_result = _tmp_result_data[_i];
          let sc_to_swift_value_result = Teacher(value_result)
          sc_to_swift_result.append(sc_to_swift_value_result);
        }
        return sc_to_swift_result;
    }
}