# Standard library types supported by CppBind

This section covers all C++ standard data types and corresponding examples supported by CppBind.


| C++ Data Type                 | Kotlin Data Type  | Swift Data Type    | Python Data Type     | 
| ----------------------------  | ----------------- | -----------------  | -----------------    |
| `std::string`                 |`String`           |`String`            |`str`                 |
| `std::string_view`            |`String`           |`String`            |`str`                 |
| `std::vector<T>`              |`List<T>`          |`Array<T>`          |`List[T]`             |
| `std::array<T, Size>`         |`List<T>`          |`Array<T>`          |`List[T]`             |
| `std::map<T1, T2>`            |`Map<T1, T2>`      |`Dictionary<T1, T2>`|`Dict[T1, T2]`        |
| `std::unordered_map<T1, T2>`  |`Map<T1, T2>`      |`Dictionary<T1, T2>`|`Dict[T1, T2]`        |
| `std::shared_ptr<T>`          |`T`                |`T`                 |`T`                   |
| `std::pair<T1, T2>`           |`Pair<T1, T2>`     |`(T1, T2)`          |`Tuple[T1, T2]`       |
| `std::optional<T>`            |`T?`               |`T?`                |`T?`                  |
| `std::span<T>`                |`List<T>`          |`Array<T>`          |Not Supported         |
| `std::function<R(Args...)>`   |Not Supported      |Not Supported       |`Callable[[*Args], R]`|    


!!! Note 
    During standard data types conversion CppBind copies original 
    data to the target language.

!!! Note
    In case of `std::optional` we are using type specific structures in Swift
    to send the data to the target language. See `CppBindOptional*` structures in [src/cppbind/config/std_helpers/swift/cxx/c_helpers.h](https://github.com/PicsArt/cppbind/blob/master/src/cppbind/config/std_helpers/swift/cxx/c_helpers.h)

!!! Examples
    You can find standard data types examples on [examples/primitives/cxx/stl_types](https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/stl_types)
    and [examples/primitives/cxx/containers](https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/containers) directories.
