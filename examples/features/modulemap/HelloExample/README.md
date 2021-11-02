## Hello user example with xcode configuration.

This is a small hello user framework with a submodule for iegen generated C bindings API.

Here we have the source code(under HelloExample/cxx directory) and generated bindings under HelloExample/swift.

Configuration is defined in **HelloExample/cxx/iegen.yaml** and **HelloExample/cxx/modulemap.iegen.yaml** files.

To regenerate the wrappers use the following command from HelloExample directory:
 ```bash
 iegen run swift
 ```
Generated modulemap file can be found under HelloExample directory.

Code using the generated api can be found under `HelloExample/main.swift`.
To run the unit test for it use the following command:
 ```bash
 xcodebuild test -scheme HelloExampleTests
 ```
