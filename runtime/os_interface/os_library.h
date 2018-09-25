/*
 * Copyright (C) 2017-2018 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 */

#pragma once
#include <string>
#include <type_traits>

namespace OCLRT {

class OsLibrary {
  protected:
    OsLibrary() = default;

  public:
    struct ConvertibleProcAddr {
        template <typename T>
        operator T *() const {
            static_assert(std::is_function<T>::value, "Cannot convert to non-function and non-void* type");
            return reinterpret_cast<T *>(ptr);
        }

        operator void *() const {
            return ptr;
        }
        void *ptr = nullptr;
    };
    virtual ~OsLibrary() = default;

    static OsLibrary *load(const std::string &name);

    ConvertibleProcAddr operator[](const std::string &name) {
        return ConvertibleProcAddr{getProcAddress(name)};
    }
    virtual void *getProcAddress(const std::string &procName) = 0;
    virtual bool isLoaded() = 0;
};
} // namespace OCLRT
