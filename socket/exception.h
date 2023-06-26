// Copyright (c) Facebook, Inc. and its affiliates.
// All rights reserved.
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include <stdexcept>

namespace xoscar {

class XoscarError : public std::runtime_error {
public:
    using std::runtime_error::runtime_error;

    XoscarError(const XoscarError &) = default;

    XoscarError &operator=(const XoscarError &) = default;

    XoscarError(XoscarError &&) = default;

    XoscarError &operator=(XoscarError &&) = default;

    ~XoscarError() override;
};

class TimeoutError : public XoscarError {
public:
    using XoscarError::XoscarError;

    TimeoutError(const TimeoutError &) = default;

    TimeoutError &operator=(const TimeoutError &) = default;

    TimeoutError(TimeoutError &&) = default;

    TimeoutError &operator=(TimeoutError &&) = default;

    ~TimeoutError() override;
};

}  // namespace xoscar
