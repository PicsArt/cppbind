import Foundation

import CWrapper

/**
 */
public protocol IRectangle : IParallelogram {

    
    
    
    /**
     */
    var area: Double { get
    }

    /**
     */
    var length: Double { get
    }

    /**
     */
    var width: Double { get
    }
    /**
     */
    func perimeter() -> Double 
}
extension IRectangle {
    
    /**
     */
    public var area: Double {
          get {
            let result = _prop_get_Rectangle_area(cself);
            
            return result
          }
          
    }

    /**
     */
    public var length: Double {
          get {
            let result = _prop_get_Rectangle_length(cself);
            
            return result
          }
          
    }

    /**
     */
    public var width: Double {
          get {
            let result = _prop_get_Rectangle_width(cself);
            
            return result
          }
          
    }
    /**
     */
    public func perimeter() -> Double {

        let result = _func_Rectangle_perimeter(cself);
        
        return result;
    }
}
public class Rectangle : IRectangle {
    public let cself : UnsafeMutableRawPointer
    public let owner : Bool

    // internal main initializer
    internal required init(_ _cself: UnsafeMutableRawPointer, _ _owner: Bool = false) {
      self.cself = _cself
      self.owner = _owner
    }
    deinit {
      if owner {
        release_Rectangle(cself)
      }
    }

    /**
     */
    public convenience init(length: Double, width: Double) {

        
        
        self.init(create_Rectangle(length, width), true)
    }
}