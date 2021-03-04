/*
 * Copyright (C) 2020-2021 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 */

#include "shared/source/command_stream/linear_stream.h"
#include "shared/test/common/fixtures/device_fixture.h"

namespace NEO {

class DispatcherFixture : public DeviceFixture {
  public:
    void SetUp();
    void TearDown();

    NEO::LinearStream cmdBuffer;
    void *bufferAllocation;
};

} // namespace NEO
