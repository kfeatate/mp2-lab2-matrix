﻿#include "tmatrix.h"

#include "gtest.h"

TEST(TDynamicVector, can_create_vector_with_positive_length)
{
  EXPECT_NO_THROW(TDynamicVector<int> v(5));
}

TEST(TDynamicVector, cant_create_too_large_vector)
{
  EXPECT_ANY_THROW(TDynamicVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TDynamicVector, throws_when_create_vector_with_negative_length)
{
   EXPECT_ANY_THROW(TDynamicVector<int> v(-5));
}

TEST(TDynamicVector, can_create_copied_vector)
{
  TDynamicVector<int> v(10);

  EXPECT_NO_THROW(TDynamicVector<int> v1(v));
}

TEST(TDynamicVector, copied_vector_is_equal_to_source_one)
{
    TDynamicVector<int> v(10);
    TDynamicVector<int> tmp(v);
    EXPECT_EQ(v[0], tmp[0]);
}

TEST(TDynamicVector, compare_equal_vectors_return_true)
{
    TDynamicVector<int> v(10);
    TDynamicVector<int> tmp(v);
    int flag = 0;
    if (v == tmp)
        flag = 1;
    EXPECT_EQ(1, flag);
}

TEST(TDynamicVector, compare_vector_with_itself_return_true)
{
    TDynamicVector<int> v(10);
    int flag = 0;
    if (v == v) {
        flag = 1;
    }
    EXPECT_EQ(1, flag);
}

TEST(TDynamicVector, vectors_with_different_size_are_not_equal)
{
    TDynamicVector<int> v(10);
    TDynamicVector<int> tmp(5);
    int flag = 0;
    if (v == tmp) {
        flag = 1;
    }
    EXPECT_EQ(0, flag);
}

TEST(TDynamicVector, copied_vector_has_its_own_memory)
{
    TDynamicVector<int> v(10);
    TDynamicVector<int> tmp(v);
    tmp[0] = 1;
    EXPECT_NE(v[0], tmp[0]);
}

TEST(TDynamicVector, can_get_size)
{
  TDynamicVector<int> v(4);

  EXPECT_EQ(4, v.size());
}

//TEST(TDynamicVector, can_set_and_get_element)
//{
//  TDynamicVector<int> v(4);
//  v[0] = 4;
//
//  EXPECT_EQ(4, v[0]);
//}

TEST(TDynamicVector, throws_when_set_element_with_negative_index)
{
    TDynamicVector<int> v(5);
    EXPECT_ANY_THROW(v[-1] = 2);
}

TEST(TDynamicVector, throws_when_set_element_with_too_large_index)
{
    TDynamicVector<int> v(5);
    EXPECT_ANY_THROW(v[10] = 1);
}

TEST(TDynamicVector, can_assign_vector_to_itself)
{
    TDynamicVector<int> v(5);
    EXPECT_NO_THROW(v = v);
}

TEST(TDynamicVector, can_assign_vectors_of_equal_size)
{  
    TDynamicVector<int> v(10);
    v[1] = 4;
    TDynamicVector<int> tmp(10);
    tmp = v;
    EXPECT_EQ(4, tmp[1]);
}

TEST(TDynamicVector, assign_operator_change_vector_size)
{
    TDynamicVector<int> v(10);
    TDynamicVector<int> tmp(5);
    tmp = v;
    EXPECT_EQ(v.size(), tmp.size());
}

TEST(TDynamicVector, can_assign_vectors_of_different_size)
{
    TDynamicVector<int> v(5);
    v[1] = 1;
    TDynamicVector<int> tmp(10);
    tmp = v;
    EXPECT_EQ(v[0], tmp[0]);
    EXPECT_EQ(v[1], tmp[1]);
}

TEST(TDynamicVector, can_add_scalar_to_vector)
{
    TDynamicVector<int> v(10);
    v = v + 5;
    EXPECT_EQ(5, v[0]);
    EXPECT_EQ(5, v[9]);
}

TEST(TDynamicVector, can_subtract_scalar_from_vector)
{
    TDynamicVector<int> v(10);
    v = v + 10;
    v = v - 5;
    EXPECT_EQ(5, v[0]);
    EXPECT_EQ(5, v[9]);
}

TEST(TDynamicVector, can_multiply_scalar_by_vector)
{
    TDynamicVector<int> v(10);
    v = v + 2;
    v = v * 2;
    EXPECT_EQ(4, v[0]);
    EXPECT_EQ(4, v[9]);
}

TEST(TDynamicVector, can_add_vectors_with_equal_size)
{
    TDynamicVector<int> v(10);
    v[2] = 2;
    TDynamicVector<int> tmp(10);
    tmp[2] = 1;
    v = v + tmp;
    EXPECT_EQ(3, v[2]);
}

TEST(TDynamicVector, cant_add_vectors_with_not_equal_size)
{
    TDynamicVector<int> v(10);
    TDynamicVector<int> tmp(5);
    EXPECT_ANY_THROW(v + tmp);
}

TEST(TDynamicVector, can_subtract_vectors_with_equal_size)
{
    TDynamicVector<int> v(10);
    v[5] = 5;
    TDynamicVector<int> tmp(10);
    tmp[5] = 3;
    v = v - tmp;
    EXPECT_EQ(2, v[5]);
}

TEST(TDynamicVector, cant_subtract_vectors_with_not_equal_size)
{
    TDynamicVector<int> v(10);
    TDynamicVector<int> tmp(5);
    EXPECT_ANY_THROW(v - tmp);
}

TEST(TDynamicVector, can_multiply_vectors_with_equal_size)
{
    TDynamicVector<int> v(10);
    v[0] = 5;
    TDynamicVector<int> tmp(10);
    tmp[0] = 2;
    v = v * tmp;
    EXPECT_EQ(10, v[0]);
}

TEST(TDynamicVector, cant_multiply_vectors_with_not_equal_size)
{
    TDynamicVector<int> v(10);
    TDynamicVector<int> tmp(5);
    EXPECT_ANY_THROW(v * tmp);
}
