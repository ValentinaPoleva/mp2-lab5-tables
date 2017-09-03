#include <gtest.h>
#include "h_hash.h"
#include "h_sort.h"
#include "polinom.h"

TEST(hash_table, can_create_table)
{
	ASSERT_NO_THROW(htable table);
}

TEST(hash_table, can_add)
{
	htable table;
	T a = T();
	ASSERT_NO_THROW(table.insert("pol", a));
}

TEST(hash_table, can_search)
{
	htable table;
	int a = 1;
	table.insert("pol", 4);
	table.insert("poa", 1);
	table.insert("pob", 2);
	EXPECT_EQ(table.search("pob")->getkey(), "pob");
}

TEST(hash_table, can_delete)
{
	htable table;
	int a = 1;
	table.insert("pol", 4);
	table.insert("poa", 1);
	table.insert("pob", 2);
	ASSERT_NO_THROW(table.del("pob"));
}

TEST(sort_table, can_create_table)
{
	ASSERT_NO_THROW(stable table);
}

TEST(sort_table, can_add)
{
	stable table;
	int a = 1;
	ASSERT_NO_THROW(table.insert("pol", a));
}

TEST(sort_table, can_search)
{
	stable table;
	int a = 1;
	table.insert("pol", 4);
	table.insert("poa", 1);
	table.insert("pob", 2);
	EXPECT_EQ(table.search("pob")->getkey(),"pob");
}

TEST(sort_table, can_delete)
{
	stable table;
	int a = 1;
	table.insert("pol", 4);
	table.insert("poa", 1);
	table.insert("pob", 2);
	ASSERT_NO_THROW(table.del("pob"));
}