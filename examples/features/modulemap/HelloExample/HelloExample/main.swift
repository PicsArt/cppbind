//
//  main.swift
//  HelloExample
//
//  Created by Liana on 26.10.21.
//

import HelloExample.CWrapper

public func greet() {

    let user = UserInfo(user_name: "John", user_age: 22)
    let young_user = UserInfo(user_name: "Kate", user_age: 18)

    let host = Host()

    assert(host.hello(user: user)  == "Hello John")
    assert(host.hello(user: young_user)  == "Hi Kate")

    assert(host.welcome(user: user)  == "Welcome John! Let me know if you want something.")
    assert(host.welcome(user: young_user)  == "Welcome Kate! Let me know if you want something.")

    user.want_a_drink = true
    young_user.want_a_drink = true
    
    assert(host.welcome(user: user)  == "Welcome John! Do you want cap of beer?")
    assert(host.welcome(user: young_user)  == "Welcome Kate! Do you want cap of juice?")

}
