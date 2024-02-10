#pragma once

#include <cstdint>

namespace kitten {
enum class DeviceType : uint16_t { CPU, NumTypes };

constexpr int NumDeviceTypes = static_cast<uint8_t>(DeviceType::NumTypes);

} // namespace kitten
