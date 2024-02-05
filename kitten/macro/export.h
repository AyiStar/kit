#ifdef _WIN32
#define KITTEN_HIDDEN
#if defined(KITTEN_BUILD_SHARED_LIBS)
#define KITTEN_EXPORT __declspec(dllexport)
#define KITTEN_IMPORT __declspec(dllimport)
#else
#define KITTEN_EXPORT
#define KITTEN_IMPORT
#endif
#else // _WIN32
#if defined(__GNUC__)
#define KITTEN_EXPORT __attribute__((__visibility__("default")))
#define KITTEN_HIDDEN __attribute__((__visibility__("hidden")))
#else // defined(__GNUC__)
#define KITTEN_EXPORT
#define KITTEN_HIDDEN
#endif // defined(__GNUC__)
#define KITTEN_IMPORT KITTEN_EXPORT
#endif // _WIN32

#ifdef NO_EXPORT
#undef KITTEN_EXPORT
#define KITTEN_EXPORT
#endif

#define KITTEN_API KITTEN_EXPORT
