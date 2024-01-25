#include <memory>

namespace kitten {

using DeletePtrFn = void (*)(void *);

class DataPtr {
public:
  DataPtr();
  DataPtr(void *data, void *ctx, DeletePtrFn deleter)
      : data_(data), ctx_(ctx, deleter) {}

private:
  void *data_;
  std::unique_ptr<void, DeletePtrFn> ctx_;
};
} // namespace kitten
