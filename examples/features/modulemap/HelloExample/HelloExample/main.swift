//
//  main.swift
//  HelloExample
//
//  Created by Liana on 26.10.21.
//

import HelloExample.CWrapper

public func greet() {

    let user = UserInfo(userName: "John", userAge: 22)
    let youngUser = UserInfo(userName: "Kate", userAge: 18)

    let host = Host()

    assert(host.hello(user: user)  == "Hello John")
    assert(host.hello(user: youngUser)  == "Hi Kate")

    assert(host.welcome(user: user)  == "Welcome John! Let me know if you want something.")
    assert(host.welcome(user: youngUser)  == "Welcome Kate! Let me know if you want something.")

    user.want_a_drink = true
    youngUser.want_a_drink = true
    
    assert(host.welcome(user: user)  == "Welcome John! Do you want cap of beer?")
    assert(host.welcome(user: youngUser)  == "Welcome Kate! Do you want cap of juice?")

}
