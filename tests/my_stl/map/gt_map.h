#ifndef SRC_TESTS_MY_STL_MAP_GT_MAP_H_
#define SRC_TESTS_MY_STL_MAP_GT_MAP_H_

#include <gtest/gtest.h>

#include <iostream>
#include <limits>
#include <map>
#include <stdexcept>

#include "../../../include/containers.h"

#define MAP_EXPECT_EQ(map1, map2)             \
  {                                           \
    auto it1 = map1.begin();                  \
    auto it2 = map2.begin();                  \
    for (; it1 != map1.end(); ++it1, ++it2) { \
      EXPECT_EQ(*it1, *it2);                  \
    }                                         \
    EXPECT_EQ(map1.size(), map2.size());      \
  }

class TestMap : public ::testing::Test {
 public:
  void SetUp() override {}
  void TearDown() override {}
};

#endif  // SRC_TESTS_MY_STL_MAP_GT_MAP_H_
