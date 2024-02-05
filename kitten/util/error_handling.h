#pragma once

#include <cstdint>
#include <cstring>
#include <exception>
#include <iostream>
#include <string>
#include <utility>
#include <variant>
#include <vector>

namespace kitten {

// TODO constraint on T
template <typename T>
std::string concat_strings(T str) {
  return std::string(std::forward<T>(str));
}

template <typename T, typename... Args>
std::string concat_strings(T first, Args... rest) {
  return std::string(std::forward<T>(first)) + concat_strings(rest...);
}

template <typename... Args>
const char *assertMsg(const char *default_msg, const Args &...args) {
  if constexpr (sizeof...(args) == 0) {
    return default_msg;
  } else {
    std::string msg = concat_strings(args...);
    return strdup(msg.c_str());
  }
}

[[noreturn]] void handleAssertFail(const char *func, const char *file,
                                   uint32_t line, const char *msg) {
  std::cout << file << ":" << line << ": [" << func << "]:\n"
            << msg << std::endl;
  abort();
}

} // namespace kitten
