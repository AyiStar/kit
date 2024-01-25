#include <kitten/core/allocator.h>

#include <cstdlib>

namespace kitten {
class CPUAllocator final : public Allocator {
public:
  DataPtr allocate(std::size_t nbytes) {
    void *data = malloc(nbytes);
    return {data, data, &free_data};
  }

  static CPUAllocator &get_cpu_allocator() {
    static CPUAllocator allocator;
    return allocator;
  }

private:
  // Meyer's singleton
  CPUAllocator() = default;
  ~CPUAllocator() = default;
  static void free_data(void *data) { free(data); }
};

} // namespace kitten
