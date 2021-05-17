import Foundation

import CWrapper

/**
 */
public class Bicycle : Vehicle {
    
    /**
     */
    public convenience init(numberOfSeats: Int) {

        let swift_to_sc_numberOfSeats = CInt(numberOfSeats)
        self.init(create_Bicycle(swift_to_sc_numberOfSeats), true)
    }
    
    
}