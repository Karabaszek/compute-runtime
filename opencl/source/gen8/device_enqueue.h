/*
 * Copyright (C) 2017-2020 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 */

#pragma once
#include "../execution_model/device_enqueue.h"

#define WA_LRI_COMMANDS_EXIST_GEN8 1
#define WA_PROFILING_PREEMPTION 1
#define WA_SCHEDULER_PREEMPTION 1
#define WA_KERNEL_PREEMPTION 1

#if defined WA_LRI_COMMANDS_EXIST_GEN8
#define WA_LRI_COMMANDS_EXIST 1
#endif

#define OCLRT_GPGPU_WALKER_CMD_DEVICE_CMD_G8 (15 * sizeof(uint))
#define OCLRT_PIPE_CONTROL_CMD_DEVICE_CMD_G8 (6 * sizeof(uint))
#define OCLRT_LOAD_REGISTER_IMM_CMD_G8 (3 * sizeof(uint))

#define OCLRT_GPGPU_WALKER_CMD_DEVICE_CMD_G8_DWORD_OFFSET (15)
#define OCLRT_PIPE_CONTROL_CMD_DEVICE_CMD_G8_DWORD_OFFSET (6)

#ifdef WA_LRI_COMMANDS_EXIST_GEN8

#define SECOND_LEVEL_BUFFER_SPACE_FOR_EACH_ENQUEUE_GEN8PLUS (OCLRT_SIZEOF_MEDIA_STATE_FLUSH + OCLRT_SIZEOF_MI_ATOMIC_CMD + OCLRT_SIZEOF_MEDIA_INTERFACE_DESCRIPTOR_LOAD_DEVICE_CMD + OCLRT_LOAD_REGISTER_IMM_CMD_G8 + OCLRT_PIPE_CONTROL_CMD_DEVICE_CMD_G8 + OCLRT_GPGPU_WALKER_CMD_DEVICE_CMD_G8 + OCLRT_SIZEOF_MEDIA_STATE_FLUSH + OCLRT_PIPE_CONTROL_CMD_DEVICE_CMD_G8 + OCLRT_LOAD_REGISTER_IMM_CMD_G8 + CS_PREFETCH_SIZE)

#else

#define SECOND_LEVEL_BUFFER_SPACE_FOR_EACH_ENQUEUE_GEN8PLUS (OCLRT_SIZEOF_MEDIA_STATE_FLUSH + OCLRT_SIZEOF_MI_ATOMIC_CMD + OCLRT_SIZEOF_MEDIA_VFE_STATE_CMD + OCLRT_SIZEOF_MEDIA_INTERFACE_DESCRIPTOR_LOAD_DEVICE_CMD + OCLRT_PIPE_CONTROL_CMD_DEVICE_CMD_G8 + OCLRT_GPGPU_WALKER_CMD_DEVICE_CMD_G8 + OCLRT_SIZEOF_MEDIA_STATE_FLUSH + OCLRT_PIPE_CONTROL_CMD_DEVICE_CMD_G8 + CS_PREFETCH_SIZE)

#endif //WA_LRI_COMMANDS_EXIST_GEN8

#define SECOND_LEVEL_BUFFER_NUMBER_OF_ENQUEUES_GEN8PLUS (128)
