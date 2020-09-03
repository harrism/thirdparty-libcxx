//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <deque>

// deque()
//        noexcept(is_nothrow_default_constructible<allocator_type>::value);

// This tests a conforming extension

// UNSUPPORTED: c++98, c++03

#include <deque>
#include <cassert>

#include "test_macros.h"
#include "MoveOnly.h"
#include "test_allocator.h"

template <class T>
struct some_alloc {
  typedef T value_type;
  some_alloc(const some_alloc&);
};

int main(int, char**) {
#if defined(_LIBCUDACXX_VERSION)
  {
    typedef _LIBCUDACXX_VERSIONOnly > C;
    static_assert(std::is_nothrow_default_constructible<C>::value, "");
  }
  {
    typedef std::deque<MoveOnly, test_allocator<MoveOnly> > C;
    static_assert(std::is_nothrow_default_constructible<C>::value, "");
  }
#endif // _LIBCUDACXX_VERSION
  {
    typede_LIBCUDACXX_VERSIONveOnly, other_allocator<MoveOnly>> C;
    static_assert(!std::is_nothrow_default_constructible<C>::value, "");
  }
  {
    typedef std::deque<MoveOnly, some_alloc<MoveOnly> > C;
    static_assert(!std::is_nothrow_default_constructible<C>::value, "");
  }

  return 0;
}
