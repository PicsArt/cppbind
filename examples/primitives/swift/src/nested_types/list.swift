/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 01/25/2022-14:10.
 * Please do not change it manually.
 */

import CWrapper
import Foundation

public typealias Item = List.Item

/**
 * An example with multi level nested type using header_code_fragment to create an alias in target languages.
 */
public class List {

  public let cself: CObject
  public let owner: Bool

  // internal main initializer
  internal required init(_ _cself: CObject, _ _owner: Bool = false) {
    self.cself = _cself
    self.owner = _owner
  }

  deinit {
    release_List(cself, owner)
  }

  public convenience init() {
    var err = ErrorObj()
    self.init(create_List(&err), true)
    let errorType = Int(err.err_type)
    if errorType != 0 {
      switch errorType {
      case (1):
        let excObj = StdException(CObject(type: strdup("std::exception"), ptr: err.err_ptr), true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        ExceptionHandler.handleUncaughtException("Uncaught Exception")
      }
    }
  }

  public var back: Item {
    get {
      let result = _prop_get_List_back(cself)
      var sctoswiftresult: Item
      sctoswiftresult = Item(result)
      return sctoswiftresult
    }
  }

  public class Item {

    public let cself: CObject
    public let owner: Bool

    // internal main initializer
    internal required init(_ _cself: CObject, _ _owner: Bool = false) {
      self.cself = _cself
      self.owner = _owner
    }

    deinit {
      release_Item(cself, owner)
    }

    public convenience init(v: Value) {
      let swifttoscv = v.cself
      var err = ErrorObj()
      self.init(create_Item(swifttoscv, &err), true)
      let errorType = Int(err.err_type)
      if errorType != 0 {
        switch errorType {
        case (1):
          let excObj = StdException(CObject(type: strdup("std::exception"), ptr: err.err_ptr), true)
          ExceptionHandler.handleUncaughtException(excObj.what())
        default:
          ExceptionHandler.handleUncaughtException("Uncaught Exception")
        }
      }
    }

    public var value: Value {
      get {
        let result = _prop_get_Item_value(cself)
        var sctoswiftresult: Value
        sctoswiftresult = Value(result)
        return sctoswiftresult
      }

      set(value) {
        let swifttoscvalue = value.cself
        _prop_set_Item_value(cself, swifttoscvalue)
      }
    }

    public class Value {

      public let cself: CObject
      public let owner: Bool

      // internal main initializer
      internal required init(_ _cself: CObject, _ _owner: Bool = false) {
        self.cself = _cself
        self.owner = _owner
      }

      deinit {
        release_Value(cself, owner)
      }

      public convenience init(value: Int) {
        let swifttoscvalue = CInt(value)
        var err = ErrorObj()
        self.init(create_Value(swifttoscvalue, &err), true)
        let errorType = Int(err.err_type)
        if errorType != 0 {
          switch errorType {
          case (1):
            let excObj = StdException(CObject(type: strdup("std::exception"), ptr: err.err_ptr), true)
            ExceptionHandler.handleUncaughtException(excObj.what())
          default:
            ExceptionHandler.handleUncaughtException("Uncaught Exception")
          }
        }
      }

      public var value: Int {
        get {
          let result = _prop_get_Value_value(cself)
          let sctoswiftresult = Int(result)
          return sctoswiftresult
        }

        set(value) {
          let swifttoscvalue = CInt(value)
          _prop_set_Value_value(cself, swifttoscvalue)
        }
      }

    }

  }

  public func push_back(item: Item) -> Void {

    let swifttoscitem = item.cself
    var err = ErrorObj()
    _func_List_push_back(cself, swifttoscitem, &err)
    let errorType = Int(err.err_type)
    if errorType != 0 {
      switch errorType {
      case (1):
        let excObj = StdException(CObject(type: strdup("std::exception"), ptr: err.err_ptr), true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        ExceptionHandler.handleUncaughtException("Uncaught Exception")
      }
    }
  }

  public func pop_back() -> Void {

    var err = ErrorObj()
    _func_List_pop_back(cself, &err)
    let errorType = Int(err.err_type)
    if errorType != 0 {
      switch errorType {
      case (1):
        let excObj = StdException(CObject(type: strdup("std::exception"), ptr: err.err_ptr), true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        ExceptionHandler.handleUncaughtException("Uncaught Exception")
      }
    }
  }

}

public typealias Value = List.Item.Value
