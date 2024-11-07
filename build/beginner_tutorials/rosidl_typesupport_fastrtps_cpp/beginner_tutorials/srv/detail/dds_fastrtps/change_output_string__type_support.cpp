// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from beginner_tutorials:srv/ChangeOutputString.idl
// generated code does not contain a copyright notice
#include "beginner_tutorials/srv/detail/change_output_string__rosidl_typesupport_fastrtps_cpp.hpp"
#include "beginner_tutorials/srv/detail/change_output_string__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace beginner_tutorials
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_beginner_tutorials
cdr_serialize(
  const beginner_tutorials::srv::ChangeOutputString_Request & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: new_string
  cdr << ros_message.new_string;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_beginner_tutorials
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  beginner_tutorials::srv::ChangeOutputString_Request & ros_message)
{
  // Member: new_string
  cdr >> ros_message.new_string;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_beginner_tutorials
get_serialized_size(
  const beginner_tutorials::srv::ChangeOutputString_Request & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: new_string
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.new_string.size() + 1);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_beginner_tutorials
max_serialized_size_ChangeOutputString_Request(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: new_string
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = beginner_tutorials::srv::ChangeOutputString_Request;
    is_plain =
      (
      offsetof(DataType, new_string) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _ChangeOutputString_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const beginner_tutorials::srv::ChangeOutputString_Request *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _ChangeOutputString_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<beginner_tutorials::srv::ChangeOutputString_Request *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _ChangeOutputString_Request__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const beginner_tutorials::srv::ChangeOutputString_Request *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _ChangeOutputString_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_ChangeOutputString_Request(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _ChangeOutputString_Request__callbacks = {
  "beginner_tutorials::srv",
  "ChangeOutputString_Request",
  _ChangeOutputString_Request__cdr_serialize,
  _ChangeOutputString_Request__cdr_deserialize,
  _ChangeOutputString_Request__get_serialized_size,
  _ChangeOutputString_Request__max_serialized_size
};

static rosidl_message_type_support_t _ChangeOutputString_Request__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_ChangeOutputString_Request__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace beginner_tutorials

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_beginner_tutorials
const rosidl_message_type_support_t *
get_message_type_support_handle<beginner_tutorials::srv::ChangeOutputString_Request>()
{
  return &beginner_tutorials::srv::typesupport_fastrtps_cpp::_ChangeOutputString_Request__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, beginner_tutorials, srv, ChangeOutputString_Request)() {
  return &beginner_tutorials::srv::typesupport_fastrtps_cpp::_ChangeOutputString_Request__handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include <limits>
// already included above
// #include <stdexcept>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
// already included above
// #include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace beginner_tutorials
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_beginner_tutorials
cdr_serialize(
  const beginner_tutorials::srv::ChangeOutputString_Response & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: output
  cdr << ros_message.output;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_beginner_tutorials
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  beginner_tutorials::srv::ChangeOutputString_Response & ros_message)
{
  // Member: output
  cdr >> ros_message.output;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_beginner_tutorials
get_serialized_size(
  const beginner_tutorials::srv::ChangeOutputString_Response & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: output
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.output.size() + 1);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_beginner_tutorials
max_serialized_size_ChangeOutputString_Response(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: output
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = beginner_tutorials::srv::ChangeOutputString_Response;
    is_plain =
      (
      offsetof(DataType, output) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _ChangeOutputString_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const beginner_tutorials::srv::ChangeOutputString_Response *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _ChangeOutputString_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<beginner_tutorials::srv::ChangeOutputString_Response *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _ChangeOutputString_Response__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const beginner_tutorials::srv::ChangeOutputString_Response *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _ChangeOutputString_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_ChangeOutputString_Response(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _ChangeOutputString_Response__callbacks = {
  "beginner_tutorials::srv",
  "ChangeOutputString_Response",
  _ChangeOutputString_Response__cdr_serialize,
  _ChangeOutputString_Response__cdr_deserialize,
  _ChangeOutputString_Response__get_serialized_size,
  _ChangeOutputString_Response__max_serialized_size
};

static rosidl_message_type_support_t _ChangeOutputString_Response__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_ChangeOutputString_Response__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace beginner_tutorials

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_beginner_tutorials
const rosidl_message_type_support_t *
get_message_type_support_handle<beginner_tutorials::srv::ChangeOutputString_Response>()
{
  return &beginner_tutorials::srv::typesupport_fastrtps_cpp::_ChangeOutputString_Response__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, beginner_tutorials, srv, ChangeOutputString_Response)() {
  return &beginner_tutorials::srv::typesupport_fastrtps_cpp::_ChangeOutputString_Response__handle;
}

#ifdef __cplusplus
}
#endif

#include "rmw/error_handling.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support_decl.hpp"

namespace beginner_tutorials
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

static service_type_support_callbacks_t _ChangeOutputString__callbacks = {
  "beginner_tutorials::srv",
  "ChangeOutputString",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, beginner_tutorials, srv, ChangeOutputString_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, beginner_tutorials, srv, ChangeOutputString_Response)(),
};

static rosidl_service_type_support_t _ChangeOutputString__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_ChangeOutputString__callbacks,
  get_service_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace beginner_tutorials

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_beginner_tutorials
const rosidl_service_type_support_t *
get_service_type_support_handle<beginner_tutorials::srv::ChangeOutputString>()
{
  return &beginner_tutorials::srv::typesupport_fastrtps_cpp::_ChangeOutputString__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, beginner_tutorials, srv, ChangeOutputString)() {
  return &beginner_tutorials::srv::typesupport_fastrtps_cpp::_ChangeOutputString__handle;
}

#ifdef __cplusplus
}
#endif
