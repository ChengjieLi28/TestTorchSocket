//
// Created by 李成杰 on 2023/6/14.
//

#pragma once

namespace c10d {

enum class DebugLevel { Off = 0, Info = 1, Detail = 2 };

void setDebugLevel(DebugLevel level);

// Sets the debug level based on the value of the `TORCH_DISTRIBUTED_DEBUG`
// environment variable.
void setDebugLevelFromEnvironment();

DebugLevel debug_level() noexcept;

}  // namespace c10d
