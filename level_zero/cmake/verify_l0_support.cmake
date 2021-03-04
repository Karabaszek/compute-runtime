#
# Copyright (C) 2020 Intel Corporation
#
# SPDX-License-Identifier: MIT
#

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake${BRANCH_DIR_SUFFIX}/not_supported_platforms.cmake)

set(L0_SUPPORTED_PRODUCT_FAMILIES ${ALL_SUPPORTED_PRODUCT_FAMILY})
# Remove unsupported products
list(LENGTH L0_SUPPORTED_PRODUCT_FAMILIES L0_SUPPORTED_PRODUCT_FAMILIES_COUNT)
if(L0_SUPPORTED_PRODUCT_FAMILIES_COUNT GREATER 0)
  list(REMOVE_ITEM L0_SUPPORTED_PRODUCT_FAMILIES ${L0_NOT_SUPPORTED_PRODUCT_FAMILIES})
  list(LENGTH L0_SUPPORTED_PRODUCT_FAMILIES L0_SUPPORTED_PRODUCT_FAMILIES_COUNT)
endif()

if(L0_SUPPORTED_PRODUCT_FAMILIES_COUNT EQUAL 0)
  set(BUILD_WITH_L0 FALSE)
  message(STATUS "L0: Selected platforms are not supported.")
endif()
