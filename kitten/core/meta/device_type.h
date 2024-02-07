#pragma once

#include <cstdint>

namespace kitten {
enum class DeviceType : uint8_t { CPU, Undefined, NumTypes };

constexpr int NumDeviceTypes = static_cast<uint8_t>(DeviceType::NumTypes);

} // namespace kitten
