// Copyright (c) Facebook, Inc. and its affiliates.
// All rights reserved.
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include <fmt/format.h>

#include <cstring>
#include <system_error>

namespace fmt {

template <>
struct formatter<std::error_category> {
  constexpr decltype(auto) parse(format_parse_context &ctx) const {
    return ctx.begin();
  }

  template <typename FormatContext>
  decltype(auto) format(const std::error_category &cat,
                        FormatContext &ctx) const {
    if (std::strcmp(cat.name(), "generic") == 0) {
      return format_to(ctx.out(), "errno");
    } else {
      return format_to(ctx.out(), "{} error", cat.name());
    }
  }
};

template <>
struct formatter<std::error_code> {
  constexpr decltype(auto) parse(format_parse_context &ctx) const {
    return ctx.begin();
  }

  template <typename FormatContext>
  decltype(auto) format(const std::error_code &err, FormatContext &ctx) const {
    return format_to(ctx.out(), "({}: {} - {})", err.category(), err.value(),
                     err.message());
  }
};

}  // namespace fmt

namespace xoscar {
namespace detail {

inline std::error_code lastError() noexcept {
  return std::error_code{errno, std::generic_category()};
}

}  // namespace detail
}  // namespace xoscar
