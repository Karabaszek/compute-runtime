/*
 * Copyright (C) 2018-2020 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 */

#include "shared/source/source_level_debugger/source_level_debugger.h"

namespace NEO {

OsLibrary *SourceLevelDebugger::loadDebugger() {
    return OsLibrary::load(OsLibrary::createFullSystemPath(SourceLevelDebugger::dllName));
}
} // namespace NEO
