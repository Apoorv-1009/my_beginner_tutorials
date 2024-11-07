// generated from rosidl_typesupport_c/resource/idl__type_support.cpp.em
// with input from beginner_tutorials:srv/ChangeOutputString.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "beginner_tutorials/srv/detail/change_output_string__struct.h"
#include "beginner_tutorials/srv/detail/change_output_string__type_support.h"
#include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/message_type_support_dispatch.h"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_c/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace beginner_tutorials
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _ChangeOutputString_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ChangeOutputString_Request_type_support_ids_t;

static const _ChangeOutputString_Request_type_support_ids_t _ChangeOutputString_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _ChangeOutputString_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ChangeOutputString_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ChangeOutputString_Request_type_support_symbol_names_t _ChangeOutputString_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, beginner_tutorials, srv, ChangeOutputString_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, beginner_tutorials, srv, ChangeOutputString_Request)),
  }
};

typedef struct _ChangeOutputString_Request_type_support_data_t
{
  void * data[2];
} _ChangeOutputString_Request_type_support_data_t;

static _ChangeOutputString_Request_type_support_data_t _ChangeOutputString_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ChangeOutputString_Request_message_typesupport_map = {
  2,
  "beginner_tutorials",
  &_ChangeOutputString_Request_message_typesupport_ids.typesupport_identifier[0],
  &_ChangeOutputString_Request_message_typesupport_symbol_names.symbol_name[0],
  &_ChangeOutputString_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t ChangeOutputString_Request_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ChangeOutputString_Request_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace beginner_tutorials

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, beginner_tutorials, srv, ChangeOutputString_Request)() {
  return &::beginner_tutorials::srv::rosidl_typesupport_c::ChangeOutputString_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "beginner_tutorials/srv/detail/change_output_string__struct.h"
// already included above
// #include "beginner_tutorials/srv/detail/change_output_string__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace beginner_tutorials
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _ChangeOutputString_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ChangeOutputString_Response_type_support_ids_t;

static const _ChangeOutputString_Response_type_support_ids_t _ChangeOutputString_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _ChangeOutputString_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ChangeOutputString_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ChangeOutputString_Response_type_support_symbol_names_t _ChangeOutputString_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, beginner_tutorials, srv, ChangeOutputString_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, beginner_tutorials, srv, ChangeOutputString_Response)),
  }
};

typedef struct _ChangeOutputString_Response_type_support_data_t
{
  void * data[2];
} _ChangeOutputString_Response_type_support_data_t;

static _ChangeOutputString_Response_type_support_data_t _ChangeOutputString_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ChangeOutputString_Response_message_typesupport_map = {
  2,
  "beginner_tutorials",
  &_ChangeOutputString_Response_message_typesupport_ids.typesupport_identifier[0],
  &_ChangeOutputString_Response_message_typesupport_symbol_names.symbol_name[0],
  &_ChangeOutputString_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t ChangeOutputString_Response_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ChangeOutputString_Response_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace beginner_tutorials

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, beginner_tutorials, srv, ChangeOutputString_Response)() {
  return &::beginner_tutorials::srv::rosidl_typesupport_c::ChangeOutputString_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "beginner_tutorials/srv/detail/change_output_string__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/service_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace beginner_tutorials
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _ChangeOutputString_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ChangeOutputString_type_support_ids_t;

static const _ChangeOutputString_type_support_ids_t _ChangeOutputString_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _ChangeOutputString_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ChangeOutputString_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ChangeOutputString_type_support_symbol_names_t _ChangeOutputString_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, beginner_tutorials, srv, ChangeOutputString)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, beginner_tutorials, srv, ChangeOutputString)),
  }
};

typedef struct _ChangeOutputString_type_support_data_t
{
  void * data[2];
} _ChangeOutputString_type_support_data_t;

static _ChangeOutputString_type_support_data_t _ChangeOutputString_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ChangeOutputString_service_typesupport_map = {
  2,
  "beginner_tutorials",
  &_ChangeOutputString_service_typesupport_ids.typesupport_identifier[0],
  &_ChangeOutputString_service_typesupport_symbol_names.symbol_name[0],
  &_ChangeOutputString_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t ChangeOutputString_service_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ChangeOutputString_service_typesupport_map),
  rosidl_typesupport_c__get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace beginner_tutorials

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_c, beginner_tutorials, srv, ChangeOutputString)() {
  return &::beginner_tutorials::srv::rosidl_typesupport_c::ChangeOutputString_service_type_support_handle;
}

#ifdef __cplusplus
}
#endif
