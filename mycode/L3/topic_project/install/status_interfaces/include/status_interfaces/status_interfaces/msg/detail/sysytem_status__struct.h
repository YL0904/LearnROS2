// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from status_interfaces:msg/SysytemStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "status_interfaces/msg/sysytem_status.h"


#ifndef STATUS_INTERFACES__MSG__DETAIL__SYSYTEM_STATUS__STRUCT_H_
#define STATUS_INTERFACES__MSG__DETAIL__SYSYTEM_STATUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"
// Member 'host_name'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/SysytemStatus in the package status_interfaces.
typedef struct status_interfaces__msg__SysytemStatus
{
  /// 记录时间戳
  builtin_interfaces__msg__Time stamp;
  /// 主机名字
  rosidl_runtime_c__String host_name;
  /// CPU使用率
  float cpu_percent;
  /// 内存使用率
  float memory_percent;
  /// 内存总大小
  float memory_total;
  /// 内存剩余量
  float memory_avaliable;
  /// 网络数据发送总量
  double net_sent;
  /// 网络数据接收总量
  double net_recv;
} status_interfaces__msg__SysytemStatus;

// Struct for a sequence of status_interfaces__msg__SysytemStatus.
typedef struct status_interfaces__msg__SysytemStatus__Sequence
{
  status_interfaces__msg__SysytemStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} status_interfaces__msg__SysytemStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // STATUS_INTERFACES__MSG__DETAIL__SYSYTEM_STATUS__STRUCT_H_
