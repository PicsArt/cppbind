#include "cxx/enums/logging.hpp"

namespace cppbind::example {
LogLevel getNextLogLevel(const LogLevel& log_level) {
    return static_cast<LogLevel>((static_cast<int>(log_level) + 1) % 5);
}
}
