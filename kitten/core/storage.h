#include <kitten/core/storage_impl.h>

#include <memory>

class Storage {

private:
  std::shared_ptr<StorageImpl> storage_impl_;
};
