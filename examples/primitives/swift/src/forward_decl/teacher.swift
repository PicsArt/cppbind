import Foundation

import CWrapper

/**
 * comments
 * 
 */
public class Teacher  {
    
    public let cself : UnsafeMutableRawPointer
    public let owner : Bool

    // internal main initializer
    internal required init(_ _cself: UnsafeMutableRawPointer , _ _owner: Bool = false) {
      self.cself = _cself
      self.owner = _owner
    }
    deinit {
      if owner {
        release_Teacher(cself)
      }
    }
    
    /**
     */
    public convenience init() {

        self.init(create_Teacher(), true)
    }
    
    /**
     */
    public func addStudent(s: Student) -> Void {

        let swift_to_sc_s = s.cself
        _func_Teacher_addStudent(cself, swift_to_sc_s);
    }
    /**
     */
    public func students() -> Array<Student> {

        let result = _func_Teacher_students(cself);
        let _tmp_result_data = UnsafeBufferPointer<UnsafeMutableRawPointer>(start: result.data.assumingMemoryBound(to: UnsafeMutableRawPointer.self), count: Int(result.size))
        var sc_to_swift_result: [Student] = [] 
        defer {
          _tmp_result_data.deallocate()
        }
        for _i in 0..<Int(result.size) {
          let value_result = _tmp_result_data[_i];
          let sc_to_swift_value_result = Student(value_result)
          sc_to_swift_result.append(sc_to_swift_value_result);
        }
        return sc_to_swift_result;
    }
}