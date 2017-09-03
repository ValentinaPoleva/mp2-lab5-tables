#include <gtest.h>
#include "binary_tree.h"

TEST(bin_tree, can_create)
{
	ASSERT_NO_THROW(binary_tree tree);
}

TEST(bin_tree, can_add)
{
	binary_tree tree;
	ASSERT_NO_THROW(tree.add(5));
}

TEST(bin_tree, can_search)
{
	binary_tree tree;
	tree.add(5);
	EXPECT_EQ(tree.search(5)->getdata(),5);
}

TEST(bin_tree, can_delete1)
{
	binary_tree tree;
	tree.add(5);
	tree.add(3);
	tree.add(7);
	tree.add(1);
	tree.add(2);
	tree.add(4);
	tree.add(6);
	tree.add(8);
	ASSERT_NO_THROW(tree.del(tree.search(1)));
}
TEST(bin_tree, can_delete2)
{
	binary_tree tree;
	tree.add(5);
	tree.add(3);
	tree.add(7);
	tree.add(1);
	tree.add(2);
	tree.add(4);
	tree.add(6);
	tree.add(8);
	ASSERT_NO_THROW(tree.del(tree.search(2)));
}
TEST(bin_tree, can_delete3)
{
	binary_tree tree;
	tree.add(5);
	tree.add(3);
	tree.add(7);
	tree.add(1);
	tree.add(2);
	tree.add(4);
	tree.add(6);
	tree.add(8);
	ASSERT_NO_THROW(tree.del(tree.search(3)));
}
TEST(bin_tree, can_delete4)
{
	binary_tree tree;
	tree.add(5);
	tree.add(3);
	tree.add(7);
	tree.add(1);
	tree.add(2);
	tree.add(4);
	tree.add(6);
	tree.add(8);
	ASSERT_NO_THROW(tree.del(tree.search(4)));
}
TEST(bin_tree, can_delete5)
{
	binary_tree tree;
	tree.add(5);
	tree.add(3);
	tree.add(7);
	tree.add(1);
	tree.add(2);
	tree.add(4);
	tree.add(6);
	tree.add(8);
	ASSERT_NO_THROW(tree.del(tree.search(5)));
}
TEST(bin_tree, can_delete6)
{
	binary_tree tree;
	tree.add(5);
	tree.add(3);
	tree.add(7);
	tree.add(1);
	tree.add(2);
	tree.add(4);
	tree.add(6);
	tree.add(8);
	ASSERT_NO_THROW(tree.del(tree.search(6)));
}
TEST(bin_tree, can_delete7)
{
	binary_tree tree;
	tree.add(5);
	tree.add(3);
	tree.add(7);
	tree.add(1);
	tree.add(2);
	tree.add(4);
	tree.add(6);
	tree.add(8);
	ASSERT_NO_THROW(tree.del(tree.search(7)));
}
TEST(bin_tree, can_delete8)
{
	binary_tree tree;
	tree.add(5);
	tree.add(3);
	tree.add(7);
	tree.add(1);
	tree.add(2);
	tree.add(4);
	tree.add(6);
	tree.add(8);
	ASSERT_NO_THROW(tree.del(tree.search(8)));
}