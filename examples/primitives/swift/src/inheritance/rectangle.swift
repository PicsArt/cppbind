/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 08/12/2021-11:44.
 * Please do not change it manually.
 */

import Foundation
import CWrapper



public protocol Rectangle : Parallelogram {

    
    
    

    var area: Double { get
    }


    var length: Double { get
    }


    var width: Double { get
    }
    
    func perimeter() -> Double
}
extension Rectangle {
    

    public override var area: Double {
        get {
            let result = _prop_get_Rectangle_area(cself);
            
            return result
        }
        
    }


    public var length: Double {
        get {
            let result = _prop_get_Rectangle_length(cself);
            
            return result
        }
        
    }


    public var width: Double {
        get {
            let result = _prop_get_Rectangle_width(cself);
            
            return result
        }
        
    }
    
    public func perimeter() -> Double {

        var err = ErrorObj()
        let result = _func_Rectangle_perimeter(cself, &err);
        
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
        return result;
    }
}
public class RectangleImpl : Rectangle {
    public let cself : UnsafeMutableRawPointer
    public let owner : Bool

    // internal main initializer
    internal required init(_ _cself: UnsafeMutableRawPointer, _ _owner: Bool = false) {
      self.cself = _cself
      self.owner = _owner
    }
    deinit {
      if owner {
        release_RectangleImpl(cself)
      }
    }

    
    public convenience init(length: Double, width: Double) {

        
        
        self.init(create_Rectangle(length, width), true)
    }
}