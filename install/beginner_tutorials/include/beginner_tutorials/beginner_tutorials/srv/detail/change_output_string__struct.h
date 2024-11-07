// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from beginner_tutorials:srv/ChangeOutputString.idl
// generated code does not contain a copyright notice

#ifndef BEGINNER_TUTORIALS__SRV__DETAIL__CHANGE_OUTPUT_STRING__STRUCT_H_
#define BEGINNER_TUTORIALS__SRV__DETAIL__CHANGE_OUTPUT_STRING__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'new_string'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/ChangeOutputString in the package beginner_tutorials.
typedef struct beginner_tutorials__srv__ChangeOutputString_Request
{
  rosidl_runtime_c__String new_string;
} beginner_tutorials__srv__ChangeOutputString_Request;

// Struct for a sequence of beginner_tutorials__srv__ChangeOutputString_Request.
typedef struct beginner_tutorials__srv__ChangeOutputString_Request__Sequence
{
  beginner_tutorials__srv__ChangeOutputString_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} beginner_tutorials__srv__ChangeOutputString_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'output'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/ChangeOutputString in the package beginner_tutorials.
typedef struct beginner_tutorials__srv__ChangeOutputString_Response
{
  rosidl_runtime_c__String output;
} beginner_tutorials__srv__ChangeOutputString_Response;

// Struct for a sequence of beginner_tutorials__srv__ChangeOutputString_Response.
typedef struct beginner_tutorials__srv__ChangeOutputString_Response__Sequence
{
  beginner_tutorials__srv__ChangeOutputString_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} beginner_tutorials__srv__ChangeOutputString_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // BEGINNER_TUTORIALS__SRV__DETAIL__CHANGE_OUTPUT_STRING__STRUCT_H_
