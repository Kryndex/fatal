/*
 *  Copyright (c) 2016, Facebook, Inc.
 *  All rights reserved.
 *
 *  This source code is licensed under the BSD-style license found in the
 *  LICENSE file in the root directory of this source tree. An additional grant
 *  of patent rights can be found in the PATENTS file in the same directory.
 */

#ifndef FATAL_INCLUDE_fatal_type_impl_get_h
#define FATAL_INCLUDE_fatal_type_impl_get_h

#include <fatal/type/inherit.h>
#include <fatal/type/pair.h>

namespace fatal {
namespace impl_gt {

template <typename Key, typename Value>
static Value f(pair<Key, Value>);

template <typename...> struct g;

template <
  template <typename...> class List,
  typename... Args,
  typename Key,
  typename KeyFilter,
  typename PostFilter
>
struct g<List<Args...>, Key, KeyFilter, PostFilter> {
  using type = typename PostFilter::template apply<decltype(f<Key>(
    inherit<pair<typename KeyFilter::template apply<Args>, Args>...>())
  )>;
};

} // namespace impl_gt {
} // namespace fatal {

#endif // FATAL_INCLUDE_fatal_type_impl_get_h
