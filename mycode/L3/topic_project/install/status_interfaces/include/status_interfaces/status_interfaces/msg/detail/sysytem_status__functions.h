// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from status_interfaces:msg/SysytemStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "status_interfaces/msg/sysytem_status.h"


#ifndef STATUS_INTERFACES__MSG__DETAIL__SYSYTEM_STATUS__FUNCTIONS_H_
#define STATUS_INTERFACES__MSG__DETAIL__SYSYTEM_STATUS__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/action_type_support_struct.h"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_runtime_c/service_type_support_struct.h"
#include "rosidl_runtime_c/type_description/type_description__struct.h"
#include "rosidl_runtime_c/type_description/type_source__struct.h"
#include "rosidl_runtime_c/type_hash.h"
#include "rosidl_runtime_c/visibility_control.h"
#include "status_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "status_interfaces/msg/detail/sysytem_status__struct.h"

/// Initialize msg/SysytemStatus message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * status_interfaces__msg__SysytemStatus
 * )) before or use
 * status_interfaces__msg__SysytemStatus__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_status_interfaces
bool
status_interfaces__msg__SysytemStatus__init(status_interfaces__msg__SysytemStatus * msg);

/// Finalize msg/SysytemStatus message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_status_interfaces
void
status_interfaces__msg__SysytemStatus__fini(status_interfaces__msg__SysytemStatus * msg);

/// Create msg/SysytemStatus message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * status_interfaces__msg__SysytemStatus__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_status_interfaces
status_interfaces__msg__SysytemStatus *
status_interfaces__msg__SysytemStatus__create(void);

/// Destroy msg/SysytemStatus message.
/**
 * It calls
 * status_interfaces__msg__SysytemStatus__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_status_interfaces
void
status_interfaces__msg__SysytemStatus__destroy(status_interfaces__msg__SysytemStatus * msg);

/// Check for msg/SysytemStatus message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_status_interfaces
bool
status_interfaces__msg__SysytemStatus__are_equal(const status_interfaces__msg__SysytemStatus * lhs, const status_interfaces__msg__SysytemStatus * rhs);

/// Copy a msg/SysytemStatus message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_status_interfaces
bool
status_interfaces__msg__SysytemStatus__copy(
  const status_interfaces__msg__SysytemStatus * input,
  status_interfaces__msg__SysytemStatus * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_status_interfaces
const rosidl_type_hash_t *
status_interfaces__msg__SysytemStatus__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_status_interfaces
const rosidl_runtime_c__type_description__TypeDescription *
status_interfaces__msg__SysytemStatus__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_status_interfaces
const rosidl_runtime_c__type_description__TypeSource *
status_interfaces__msg__SysytemStatus__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_status_interfaces
const rosidl_runtime_c__type_description__TypeSource__Sequence *
status_interfaces__msg__SysytemStatus__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of msg/SysytemStatus messages.
/**
 * It allocates the memory for the number of elements and calls
 * status_interfaces__msg__SysytemStatus__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_status_interfaces
bool
status_interfaces__msg__SysytemStatus__Sequence__init(status_interfaces__msg__SysytemStatus__Sequence * array, size_t size);

/// Finalize array of msg/SysytemStatus messages.
/**
 * It calls
 * status_interfaces__msg__SysytemStatus__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_status_interfaces
void
status_interfaces__msg__SysytemStatus__Sequence__fini(status_interfaces__msg__SysytemStatus__Sequence * array);

/// Create array of msg/SysytemStatus messages.
/**
 * It allocates the memory for the array and calls
 * status_interfaces__msg__SysytemStatus__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_status_interfaces
status_interfaces__msg__SysytemStatus__Sequence *
status_interfaces__msg__SysytemStatus__Sequence__create(size_t size);

/// Destroy array of msg/SysytemStatus messages.
/**
 * It calls
 * status_interfaces__msg__SysytemStatus__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_status_interfaces
void
status_interfaces__msg__SysytemStatus__Sequence__destroy(status_interfaces__msg__SysytemStatus__Sequence * array);

/// Check for msg/SysytemStatus message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_status_interfaces
bool
status_interfaces__msg__SysytemStatus__Sequence__are_equal(const status_interfaces__msg__SysytemStatus__Sequence * lhs, const status_interfaces__msg__SysytemStatus__Sequence * rhs);

/// Copy an array of msg/SysytemStatus messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_status_interfaces
bool
status_interfaces__msg__SysytemStatus__Sequence__copy(
  const status_interfaces__msg__SysytemStatus__Sequence * input,
  status_interfaces__msg__SysytemStatus__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // STATUS_INTERFACES__MSG__DETAIL__SYSYTEM_STATUS__FUNCTIONS_H_
