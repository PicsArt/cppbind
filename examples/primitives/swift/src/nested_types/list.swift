/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 02/17/2022-13:51.
 * Please do not change it manually.
 */

import CWrapper
import Foundation

public typealias Item = List.Item

/**
 * An example with multi level nested type using header_code_fragment to create an alias in target languages.
 */
public class List {

  public let cself: IEGenCObject
  public let owner: Bool
  private var refs: [AnyObject]

  // internal main initializer
  internal required init(_ _cself: IEGenCObject, _ _owner: Bool = false) {
    self.cself = _cself
    self.owner = _owner
    self.refs = []
  }

  deinit {
    release_List(cself, owner)
  }

  public func keepIEGenReference(_ object: AnyObject) {
    self.refs.append(object)
  }

  public convenience init() {
    var err = IEGenCObject()
    self.init(create_List(&err), true)
    if err.type != nil {
      let errorType = String(cString: err.type!)
      switch errorType {
      case ("std::exception"):
        let excObj = StdException(err, true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        err.type.deallocate()
        ExceptionHandler.handleUncaughtException("Uncaught Exception")
      }
    }
  }

  public var back: List.Item {
    get {
      let result = _prop_get_List_back(cself)
      var sctoswiftresult: List.Item
      sctoswiftresult = Item(result)
      return sctoswiftresult
    }
  }

  public class Item {

    public let cself: IEGenCObject
    public let owner: Bool
    private var refs: [AnyObject]

    // internal main initializer
    internal required init(_ _cself: IEGenCObject, _ _owner: Bool = false) {
      self.cself = _cself
      self.owner = _owner
      self.refs = []
    }

    deinit {
      release_List_Item(cself, owner)
    }

    public func keepIEGenReference(_ object: AnyObject) {
      self.refs.append(object)
    }

    public convenience init(v: List.Item.Value) {
      let swifttoscv = v.cself
      var err = IEGenCObject()
      self.init(create_List_Item(swifttoscv, &err), true)
      if err.type != nil {
        let errorType = String(cString: err.type!)
        switch errorType {
        case ("std::exception"):
          let excObj = StdException(err, true)
          ExceptionHandler.handleUncaughtException(excObj.what())
        default:
          err.type.deallocate()
          ExceptionHandler.handleUncaughtException("Uncaught Exception")
        }
      }
    }

    public var value: List.Item.Value {
      get {
        let result = _prop_get_List_Item_value(cself)
        var sctoswiftresult: List.Item.Value
        sctoswiftresult = Value(result)
        sctoswiftresult.keepIEGenReference(self)
        return sctoswiftresult
      }

      set(value) {
        let swifttoscvalue = value.cself
        _prop_set_List_Item_value(cself, swifttoscvalue)
      }
    }

    public class Value {

      public let cself: IEGenCObject
      public let owner: Bool
      private var refs: [AnyObject]

      // internal main initializer
      internal required init(_ _cself: IEGenCObject, _ _owner: Bool = false) {
        self.cself = _cself
        self.owner = _owner
        self.refs = []
      }

      deinit {
        release_List_Item_Value(cself, owner)
      }

      public func keepIEGenReference(_ object: AnyObject) {
        self.refs.append(object)
      }

      public convenience init(value: Int) {
        let swifttoscvalue = CInt(value)
        var err = IEGenCObject()
        self.init(create_List_Item_Value(swifttoscvalue, &err), true)
        if err.type != nil {
          let errorType = String(cString: err.type!)
          switch errorType {
          case ("std::exception"):
            let excObj = StdException(err, true)
            ExceptionHandler.handleUncaughtException(excObj.what())
          default:
            err.type.deallocate()
            ExceptionHandler.handleUncaughtException("Uncaught Exception")
          }
        }
      }

      public var value: Int {
        get {
          let result = _prop_get_List_Item_Value_value(cself)
          let sctoswiftresult = Int(result)
          return sctoswiftresult
        }

        set(value) {
          let swifttoscvalue = CInt(value)
          _prop_set_List_Item_Value_value(cself, swifttoscvalue)
        }
      }

    }

  }

  public func push_back(item: List.Item) -> Void {

    let swifttoscitem = item.cself
    var err = IEGenCObject()
    _func_List_push_back(cself, swifttoscitem, &err)
    if err.type != nil {
      let errorType = String(cString: err.type!)
      switch errorType {
      case ("std::exception"):
        let excObj = StdException(err, true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        err.type.deallocate()
        ExceptionHandler.handleUncaughtException("Uncaught Exception")
      }
    }
  }

  public func pop_back() -> Void {

    var err = IEGenCObject()
    _func_List_pop_back(cself, &err)
    if err.type != nil {
      let errorType = String(cString: err.type!)
      switch errorType {
      case ("std::exception"):
        let excObj = StdException(err, true)
        ExceptionHandler.handleUncaughtException(excObj.what())
      default:
        err.type.deallocate()
        ExceptionHandler.handleUncaughtException("Uncaught Exception")
      }
    }
  }

}

public typealias Value = List.Item.Value
