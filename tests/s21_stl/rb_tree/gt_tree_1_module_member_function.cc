#include "gt_tree.h"

/* Default constructor */
TEST_F(TestTree, Constructor_default_int) {
  s21::Tree<int, false> t1;
  EXPECT_EQ(0, (int)t1.size());
}

TEST_F(TestTree, Constructor_default_double) {
  s21::Tree<double, false> t1;
  EXPECT_EQ(0, (int)t1.size());
}

TEST_F(TestTree, Constructor_default_string) {
  s21::Tree<std::string, false> t1;
  EXPECT_EQ(0, (int)t1.size());
}

/* With Allocator */
TEST_F(TestTree, Constructor_allocator_int) {
  s21::Tree<int, false> t1;
  s21::Tree<int, false>::allocator_type t_alloc;

  t_alloc = t1.get_allocator();

  s21::Tree<int, false> t2(t_alloc);

  EXPECT_EQ(t1.size(), t2.size());
  EXPECT_EQ(t1.get_allocator(), t2.get_allocator());
}

TEST_F(TestTree, Constructor_allocator_double) {
  s21::Tree<double, false> t1;
  s21::Tree<double, false>::allocator_type t_alloc;

  t_alloc = t1.get_allocator();

  s21::Tree<double, false> t2(t_alloc);

  EXPECT_EQ(t1.size(), t2.size());
  EXPECT_EQ(t1.get_allocator(), t2.get_allocator());
}

TEST_F(TestTree, Constructor_allocator_string) {
  s21::Tree<std::string, false> t1;
  s21::Tree<std::string, false>::allocator_type t_alloc;

  t_alloc = t1.get_allocator();

  s21::Tree<std::string, false> t2(t_alloc);

  EXPECT_EQ(t1.size(), t2.size());
  EXPECT_EQ(t1.get_allocator(), t2.get_allocator());
}

/* Copy constructor*/
TEST_F(TestTree, Constructor_copy_int) {
  s21::Tree<int, false> t1;
  t1.insert(5);
  t1.insert(6);

  s21::Tree<int, false> t2(t1);

  EXPECT_EQ(*t1.begin(), *t2.begin());
  EXPECT_EQ(*t1.end(), *t2.end());
  EXPECT_EQ(t1.size(), t2.size());
  EXPECT_EQ(t1.get_allocator(), t2.get_allocator());
}

TEST_F(TestTree, Constructor_copy_double) {
  s21::Tree<double, false> t1;
  t1.insert(0.129834);
  t1.insert(-1.000001);

  s21::Tree<double, false> t2(t1);

  EXPECT_DOUBLE_EQ(*t1.begin(), *t2.begin());
  EXPECT_DOUBLE_EQ(*t1.end(), *t2.end());
  EXPECT_EQ(t1.size(), t2.size());
  EXPECT_EQ(t1.get_allocator(), t2.get_allocator());
}

TEST_F(TestTree, Constructor_copy_string) {
  s21::Tree<std::string, false> t1;
  t1.insert("Hello, ");
  t1.insert("World!");

  s21::Tree<std::string, false> t2(t1);

  EXPECT_EQ(*t1.begin(), *t2.begin());
  EXPECT_EQ(*t1.end(), *t2.end());
  EXPECT_EQ(t1.size(), t2.size());
  EXPECT_EQ(t1.get_allocator(), t2.get_allocator());
}

/* Copy equal */
TEST_F(TestTree, Constructor_copy_equal_int) {
  s21::Tree<int, false> t1;
  t1.insert(5);
  t1.insert(6);

  s21::Tree<int, false> t2 = t1;

  EXPECT_EQ(*t1.begin(), *t2.begin());
  EXPECT_EQ(*t1.end(), *t2.end());
  EXPECT_EQ(t1.size(), t2.size());
  EXPECT_EQ(t1.get_allocator(), t2.get_allocator());
}

TEST_F(TestTree, Constructor_copy_equal_double) {
  s21::Tree<double, false> t1;
  t1.insert(0.129834);
  t1.insert(-1.000001);

  s21::Tree<double, false> t2 = t1;

  EXPECT_DOUBLE_EQ(*t1.begin(), *t2.begin());
  EXPECT_DOUBLE_EQ(*t1.end(), *t2.end());
  EXPECT_EQ(t1.size(), t2.size());
  EXPECT_EQ(t1.get_allocator(), t2.get_allocator());
}

TEST_F(TestTree, Constructor_copy_equal_string) {
  s21::Tree<std::string, false> t1;
  t1.insert("Hello, ");
  t1.insert("World!");

  s21::Tree<std::string, false> t2 = t1;

  EXPECT_EQ(*t1.begin(), *t2.begin());
  EXPECT_EQ(*t1.end(), *t2.end());
  EXPECT_EQ(t1.size(), t2.size());
  EXPECT_EQ(t1.get_allocator(), t2.get_allocator());
}

/* Move constructor */
TEST_F(TestTree, Constructor_move_int) {
  s21::Tree<int, false> t1;
  t1.insert(5);
  t1.insert(6);

  s21::Tree<int, false> t2(std::move(t1));

  EXPECT_EQ(true, t1.empty());
  EXPECT_EQ(*t2.begin(), 5);
  EXPECT_EQ(*++t2.begin(), 6);
  EXPECT_EQ(0, (int)t1.size());
  EXPECT_EQ(2, (int)t2.size());
}

TEST_F(TestTree, Constructor_move_double) {
  s21::Tree<double, false> t1;
  t1.insert(-999.999212);
  t1.insert(0.000012);

  s21::Tree<double, false> t2(std::move(t1));

  EXPECT_EQ(true, t1.empty());
  EXPECT_DOUBLE_EQ(*t2.begin(), -999.999212);
  EXPECT_DOUBLE_EQ(*++t2.begin(), 0.000012);
  EXPECT_EQ(0, (int)t1.size());
  EXPECT_EQ(2, (int)t2.size());
}

TEST_F(TestTree, Constructor_move_string) {
  s21::Tree<std::string, false> t1;
  t1.insert("Hello, ");
  t1.insert("World!");

  s21::Tree<std::string, false> t2(std::move(t1));

  EXPECT_EQ(true, t1.empty());
  EXPECT_EQ(*t2.begin(), "Hello, ");
  EXPECT_EQ(*++t2.begin(), "World!");
  EXPECT_EQ(0, (int)t1.size());
  EXPECT_EQ(2, (int)t2.size());
}

/* Move equal */
TEST_F(TestTree, Constructor_move_equal_int) {
  s21::Tree<int, false> t1;
  t1.insert(5);
  t1.insert(6);

  s21::Tree<int, false> t2 = std::move(t1);

  EXPECT_EQ(0, (int)t1.size());
  EXPECT_EQ(2, (int)t2.size());
}

TEST_F(TestTree, Constructor_move_equal_double) {
  s21::Tree<double, false> t1;
  t1.insert(-999.999212);
  t1.insert(0.000012);

  s21::Tree<double, false> t2 = std::move(t1);

  EXPECT_EQ(true, t1.empty());
  EXPECT_DOUBLE_EQ(*t2.begin(), -999.999212);
  EXPECT_DOUBLE_EQ(*++t2.begin(), 0.000012);
  EXPECT_EQ(0, (int)t1.size());
  EXPECT_EQ(2, (int)t2.size());
}

TEST_F(TestTree, Constructor_move_equal_string) {
  s21::Tree<std::string, false> t1;
  t1.insert("Hello, ");
  t1.insert("World!");

  s21::Tree<std::string, false> t2 = std::move(t1);

  EXPECT_EQ(true, t1.empty());
  EXPECT_EQ(*t2.begin(), "Hello, ");
  EXPECT_EQ(*++t2.begin(), "World!");
  EXPECT_EQ(0, (int)t1.size());
  EXPECT_EQ(2, (int)t2.size());
}
