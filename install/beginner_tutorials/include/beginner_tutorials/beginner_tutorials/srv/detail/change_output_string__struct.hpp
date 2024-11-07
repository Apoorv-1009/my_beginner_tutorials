// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from beginner_tutorials:srv/ChangeOutputString.idl
// generated code does not contain a copyright notice

#ifndef BEGINNER_TUTORIALS__SRV__DETAIL__CHANGE_OUTPUT_STRING__STRUCT_HPP_
#define BEGINNER_TUTORIALS__SRV__DETAIL__CHANGE_OUTPUT_STRING__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__beginner_tutorials__srv__ChangeOutputString_Request __attribute__((deprecated))
#else
# define DEPRECATED__beginner_tutorials__srv__ChangeOutputString_Request __declspec(deprecated)
#endif

namespace beginner_tutorials
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ChangeOutputString_Request_
{
  using Type = ChangeOutputString_Request_<ContainerAllocator>;

  explicit ChangeOutputString_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->new_string = "";
    }
  }

  explicit ChangeOutputString_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : new_string(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->new_string = "";
    }
  }

  // field types and members
  using _new_string_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _new_string_type new_string;

  // setters for named parameter idiom
  Type & set__new_string(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->new_string = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    beginner_tutorials::srv::ChangeOutputString_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const beginner_tutorials::srv::ChangeOutputString_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<beginner_tutorials::srv::ChangeOutputString_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<beginner_tutorials::srv::ChangeOutputString_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      beginner_tutorials::srv::ChangeOutputString_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<beginner_tutorials::srv::ChangeOutputString_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      beginner_tutorials::srv::ChangeOutputString_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<beginner_tutorials::srv::ChangeOutputString_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<beginner_tutorials::srv::ChangeOutputString_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<beginner_tutorials::srv::ChangeOutputString_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__beginner_tutorials__srv__ChangeOutputString_Request
    std::shared_ptr<beginner_tutorials::srv::ChangeOutputString_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__beginner_tutorials__srv__ChangeOutputString_Request
    std::shared_ptr<beginner_tutorials::srv::ChangeOutputString_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ChangeOutputString_Request_ & other) const
  {
    if (this->new_string != other.new_string) {
      return false;
    }
    return true;
  }
  bool operator!=(const ChangeOutputString_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ChangeOutputString_Request_

// alias to use template instance with default allocator
using ChangeOutputString_Request =
  beginner_tutorials::srv::ChangeOutputString_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace beginner_tutorials


#ifndef _WIN32
# define DEPRECATED__beginner_tutorials__srv__ChangeOutputString_Response __attribute__((deprecated))
#else
# define DEPRECATED__beginner_tutorials__srv__ChangeOutputString_Response __declspec(deprecated)
#endif

namespace beginner_tutorials
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ChangeOutputString_Response_
{
  using Type = ChangeOutputString_Response_<ContainerAllocator>;

  explicit ChangeOutputString_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->output = "";
    }
  }

  explicit ChangeOutputString_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : output(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->output = "";
    }
  }

  // field types and members
  using _output_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _output_type output;

  // setters for named parameter idiom
  Type & set__output(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->output = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    beginner_tutorials::srv::ChangeOutputString_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const beginner_tutorials::srv::ChangeOutputString_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<beginner_tutorials::srv::ChangeOutputString_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<beginner_tutorials::srv::ChangeOutputString_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      beginner_tutorials::srv::ChangeOutputString_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<beginner_tutorials::srv::ChangeOutputString_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      beginner_tutorials::srv::ChangeOutputString_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<beginner_tutorials::srv::ChangeOutputString_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<beginner_tutorials::srv::ChangeOutputString_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<beginner_tutorials::srv::ChangeOutputString_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__beginner_tutorials__srv__ChangeOutputString_Response
    std::shared_ptr<beginner_tutorials::srv::ChangeOutputString_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__beginner_tutorials__srv__ChangeOutputString_Response
    std::shared_ptr<beginner_tutorials::srv::ChangeOutputString_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ChangeOutputString_Response_ & other) const
  {
    if (this->output != other.output) {
      return false;
    }
    return true;
  }
  bool operator!=(const ChangeOutputString_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ChangeOutputString_Response_

// alias to use template instance with default allocator
using ChangeOutputString_Response =
  beginner_tutorials::srv::ChangeOutputString_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace beginner_tutorials

namespace beginner_tutorials
{

namespace srv
{

struct ChangeOutputString
{
  using Request = beginner_tutorials::srv::ChangeOutputString_Request;
  using Response = beginner_tutorials::srv::ChangeOutputString_Response;
};

}  // namespace srv

}  // namespace beginner_tutorials

#endif  // BEGINNER_TUTORIALS__SRV__DETAIL__CHANGE_OUTPUT_STRING__STRUCT_HPP_
