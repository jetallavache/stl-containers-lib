#include "gt_set.h"

/*
    bool empty()
*/

TEST_F(TestSet, Empty_int) {
  my_stl::Set<int> s;
  s.insert({3, 6, 6, 6, -1, 0, -26, 55, 3, 6, -1, 0, -26, 55, 55, 55, 55});
  EXPECT_EQ(s.empty(), false);

  s.clear();
  EXPECT_EQ(s.empty(), true);
}

TEST_F(TestSet, Empty_double) {
  my_stl::Set<double> s;
  s.insert({3.21, 6.92929, 6.92929, 6.92929, -1, 0, -26.9876, 55.111111, 3.21,
            6.92929, -1, 0, -26.9876, 55.111111});
  EXPECT_EQ(s.empty(), false);

  s.clear();
  EXPECT_EQ(s.empty(), true);
}

TEST_F(TestSet, Empty_string) {
  my_stl::Set<std::string> s;
  s.insert({"my_stl", "::", "::", "::", "alloc_sential_and_proxy", "()",
            "{-26.9876}", "return", "my_stl", "::", "alloc_sential_and_proxy"});
  EXPECT_EQ(s.empty(), false);

  s.clear();
  EXPECT_EQ(s.empty(), true);
}

/*
    size_type size()
*/

TEST_F(TestSet, Size_int) {
  my_stl::Set<int> s;
  EXPECT_EQ((int)s.size(), 0);

  s.insert({3, 6, 6, 6, -1, 0, -26, 55, 3, 6, -1, 0, -26, 55, 55, 55, 55});
  EXPECT_EQ((int)s.size(), 6);

  s.clear();
  EXPECT_EQ((int)s.size(), 0);
}

/*
    size_type max_size()
*/

TEST_F(TestSet, Max_size_int) {
  my_stl::Set<int> s;
  s.insert({3, 6, 6, 6, -1, 0, -26, 55, 3, 6, -1, 0, -26, 55, 55, 55, 55});

  EXPECT_EQ(s.max_size() > 1000000000, true);
}