import Foundation

import CWrapper

/**
 * 
 */
public protocol IRhombus : IParallelogram {

    
    
    
    
}
extension IRhombus {
    
    
}
public class Rhombus : IRhombus {
    public let cself : UnsafeMutableRawPointer
    public let owner : Bool

    // internal main initializer
    internal required init(_ _cself: UnsafeMutableRawPointer, _ _owner: Bool = false) {
      self.cself = _cself
      self.owner = _owner
    }
    deinit {
      if owner {
        release_Rhombus(cself)
      }
    }

    /**
     * 
     */
    public convenience init(diagonal1: Double, diagonal2: Double) {

        
        
        self.init(create_Rhombus(diagonal1, diagonal2), true)
    }
}