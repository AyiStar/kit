#include <kitten/util/error_handling.h>

#define KITTEN_ASSERT_MSG(cond, type, ...)                                     \
  (::kitten::assertMsg("Expected " #cond " to be true, but got false.",        \
                       ##__VA_ARGS__))

#define KITTEN_ASSERT(cond, ...)                                               \
  do {                                                                         \
    if (!(cond)) {                                                             \
      ::kitten::handleAssertFail(__func__, __FILE__,                           \
                                 static_cast<uint32_t>(__LINE__),              \
                                 KITTEN_ASSERT_MSG(cond, "", ##__VA_ARGS__));  \
    }                                                                          \
  } while (0)

#ifndef NDEBUG
#define KITTEN_ASSERT_DEBUG(...) KITTEN_ASSERT(__VA_ARGS__)
#else
#define KITTEN_ASSERT_DEBUG(...)                                               \
  while (false)                                                                \
  KITTEN_ASSERT(__VA_ARGS__)
#endif // NDEBUG

// TODO KITTEN_STATIC_ASSERT
