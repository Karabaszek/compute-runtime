/*
 * Copyright (C) 2017-2021 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 */

#include "shared/source/built_ins/built_ins.h"
#include "shared/source/built_ins/sip.h"
#include "shared/test/common/helpers/test_files.h"
#include "shared/test/common/mocks/mock_device.h"

#include "opencl/test/unit_test/global_environment.h"
#include "test.h"

#include "gtest/gtest.h"

using namespace NEO;

namespace SipKernelTests {
typedef ::testing::Test gen9SipTests;

GEN9TEST_F(gen9SipTests, givenDebugCsrSipKernelWithLocalMemoryWhenAskedForDebugSurfaceBtiAndSizeThenBtiIsZeroAndSizeGreaterThanZero) {
    auto mockDevice = std::unique_ptr<MockDevice>(MockDevice::createWithNewExecutionEnvironment<MockDevice>(nullptr));
    EXPECT_NE(nullptr, mockDevice);

    auto &builtins = *mockDevice->getBuiltIns();
    auto &sipKernel = builtins.getSipKernel(SipKernelType::DbgCsrLocal, *mockDevice);

    EXPECT_NE(nullptr, &sipKernel);
    EXPECT_EQ(SipKernelType::DbgCsrLocal, sipKernel.getType());
}

GEN9TEST_F(gen9SipTests, givenDebuggingActiveWhenSipTypeIsQueriedThenDbgCsrLocalIsReturned) {
    auto sipType = SipKernel::getSipKernelType(renderCoreFamily, true);
    EXPECT_EQ(SipKernelType::DbgCsrLocal, sipType);
}
} // namespace SipKernelTests
