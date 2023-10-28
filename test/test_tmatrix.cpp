#include "tmatrix.h"

#include "gtest.h"

TEST(TDynamicMatrix, can_create_matrix_with_positive_length)
{
  EXPECT_NO_THROW(TDynamicMatrix<int> m(5));
}

TEST(TDynamicMatrix, cant_create_too_large_matrix)
{
  EXPECT_ANY_THROW(TDynamicMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TDynamicMatrix, throws_when_create_matrix_with_negative_length)
{
  EXPECT_ANY_THROW(TDynamicMatrix<int> m(-5));
}

TEST(TDynamicMatrix, can_create_copied_matrix)
{
  TDynamicMatrix<int> m(5);

  EXPECT_NO_THROW(TDynamicMatrix<int> m1(m));
}

TEST(TDynamicMatrix, copied_matrix_is_equal_to_source_one)
{
	const TDynamicMatrix<int> m(5);
	const TDynamicMatrix<int> tmp(m);
	EXPECT_EQ(m[0], tmp[0]);
}

TEST(TDynamicMatrix, compare_equal_matrices_return_true)
{
	TDynamicMatrix<int> m(5);
	TDynamicMatrix<int> tmp(m);
	int flag = 0;
	if (m == tmp)
		flag = 1;
	EXPECT_EQ(1, flag);
}

TEST(TDynamicMatrix, compare_matrix_with_itself_return_true)
{
	TDynamicMatrix<int> m(5);
	int flag = 0;
	if (m == m)
		flag = 1;
	EXPECT_EQ(1, flag);
}

TEST(TDynamicMatrix, matrices_with_different_size_are_not_equal)
{
	TDynamicMatrix<int> m(5);
	TDynamicMatrix<int> tmp(3);
	int flag = 0;
	if (m == tmp)
		flag = 1;
	EXPECT_EQ(0, flag);
}

TEST(TDynamicMatrix, copied_matrix_has_its_own_memory)
{
	TDynamicMatrix<int> m(10);
	TDynamicMatrix<int> tmp(m);
	tmp[0] = 1;
	EXPECT_NE(m[0], tmp[0]);
}

TEST(TDynamicMatrix, can_get_size)
{
	TDynamicMatrix<int> m(5);
	EXPECT_EQ(5, m.size());
}

TEST(TDynamicMatrix, can_set_and_get_element)
{
	TDynamicMatrix<int> m(10);
	m[2] = 2;
	EXPECT_EQ(2, m[2]);
}

TEST(TDynamicMatrix, throws_when_set_element_with_negative_index)
{
	TDynamicMatrix<int> m(5);
	EXPECT_ANY_THROW(m[-1] = 2);
}

TEST(TDynamicMatrix, throws_when_set_element_with_too_large_index)
{
	TDynamicMatrix<int> m(5);
	EXPECT_ANY_THROW(m[6] = 1);
}

TEST(TDynamicMatrix, can_assign_matrix_to_itself)
{
	TDynamicMatrix<int> m(5);
	EXPECT_NO_THROW(m = m);
}

TEST(TDynamicMatrix, can_assign_matrices_of_equal_size)
{
	TDynamicMatrix<int> m(5);
	m[0] = 1;
	TDynamicMatrix<int> tmp(5);
	tmp = m;
	EXPECT_EQ(m[0], tmp[0]);
}

TEST(TDynamicMatrix, assign_operator_change_matrix_size)
{
	TDynamicMatrix<int> m(5);
	TDynamicMatrix<int> tmp(3);
	tmp = m;
	EXPECT_EQ(m.size(), tmp.size());
}

TEST(TDynamicMatrix, can_assign_matrices_of_different_size)
{
	TDynamicMatrix<int> m(3);
	m[1] = 1;
	TDynamicMatrix<int> tmp(5);
	tmp = m;
	EXPECT_EQ(m[0], tmp[0]);
	EXPECT_EQ(m[1], tmp[1]);
}

TEST(TDynamicMatrix, can_add_matrices_with_equal_size)
{
	TDynamicMatrix<int> m(10);
	m[0] = 1;
	TDynamicMatrix<int> tmp(10);
	TDynamicMatrix<int> res(10);
	res = m + tmp;
	EXPECT_EQ(1, res[0]);
}

TEST(TDynamicMatrix, cant_add_matrices_with_not_equal_size)
{
	TDynamicMatrix<int> m(10);
	TDynamicMatrix<int> tmp(5);
	EXPECT_ANY_THROW(m+tmp);
}

TEST(TDynamicMatrix, can_subtract_matrices_with_equal_size)
{
	TDynamicMatrix<int> m(10);
	m[0] = 5;
	TDynamicMatrix<int> tmp(10);
	tmp[0] = 1;
	TDynamicMatrix<int> res(10);
	res = m - tmp;
	EXPECT_EQ(4, res[0]);
}

TEST(TDynamicMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TDynamicMatrix<int> m(10);
	TDynamicMatrix<int> tmp(5);
	EXPECT_ANY_THROW(m - tmp);
}

