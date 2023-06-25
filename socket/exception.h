// Copyright (c) Facebook, Inc. and its affiliates.
// All rights reserved.
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include <stdexcept>

namespace xoscar {

class xoscarError : public std::runtime_error {
 public:
  using std::runtime_error::runtime_error;

  xoscarError(const xoscarError &) = default;

  xoscarError &operator=(const xoscarError &) = default;

  xoscarError(xoscarError &&) = default;

  xoscarError &operator=(xoscarError &&) = default;

  ~xoscarError() override;
};

class TimeoutError : public xoscarError {
 public:
  using xoscarError::xoscarError;

  TimeoutError(const TimeoutError &) = default;

  TimeoutError &operator=(const TimeoutError &) = default;

  TimeoutError(TimeoutError &&) = default;

  TimeoutError &operator=(TimeoutError &&) = default;

  ~TimeoutError() override;
};

}  // namespace xoscar
