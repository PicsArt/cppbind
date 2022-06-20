#ifndef logging_hpp
#define logging_hpp

namespace cppbind::example {

// [example]
/**
 * __API__
 * action: gen_enum
 * package: enums
 * enum_case_name_prefix: log_
 * enum_case_names:
 *   debug_level: DEBUG
 *   warning_level: WARNING
 *   error_level: ERROR
 *   critical_level: "{{enum_case_name_prefix|upper}}CRITICAL"
 */
enum class LogLevel {
    debug_level = 0,
    info_level = 1,
    warning_level = 2,
    error_level = 3,
    critical_level = 4
};
// [example]

namespace {

/**
 * __API__
 * action: gen_function
 * package: enums
 * throws: no_throw
 */
LogLevel getNextLogLevel(const LogLevel& log_level) {
    return static_cast<LogLevel>((static_cast<int>(log_level) + 1) % 5);
}

}

}

#endif
