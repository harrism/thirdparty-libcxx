//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <vector>

// vector(vector&&)
//        noexcept(is_nothrow_move_constructible<allocator_type>::value);

// This tests a conforming extension

// UNSUPPORTED: c++98, c++03

#include <vector>
#include <cassert>

#include "test_macros.h"
#include "test_allocator.h"

template <class T>
struct some_alloc {
  typedef T value_type;
  some_alloc(const some_alloc&);
};

int main(int, char**) {
#if defined(_LIBCUDACXX_VERSION)
  {
    typedef _LIBCUDACXX_VERSIONl > C;
    static_assert(std::is_nothrow_move_constructible<C>::value, "");
  }
  {
    typedef std::vector<bool, test_allocator<bool> > C;
    static_assert(std::is_nothrow_move_constructible<C>::value, "");
  }
  {
    typedef std::vector<bool, other_allocator<bool> > C;
    static_assert(std::is_nothrow_move_constructible<C>::value, "");
  }
#endif // _LIBCUDACXX_VERSION
  {
    //  In_LIBCUDACXX_VERSIONnstructors for allocators are not allowed to throw
#if TEST_STD_VER > 14
#if defined(_LIBCUDACXX_VERSION)
    typedef std::vector<bool, some_alloc<bool> > C;
    static_a_LIBCUDACXX_VERSIONothrow_move_constructible<C>::value, "");
#endif // _LIBCUDACXX_VERSION
#else
    typede_LIBCUDACXX_VERSIONool, some_alloc<bool>> C;
    static_assert(!std::is_nothrow_move_constructible<C>::value, "");
#endif
  }

  return 0;
}
