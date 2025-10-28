#include "gtest/gtest.h"
#include "table.hpp"

TEST(Constructor, Init) {
	ASSERT_NO_THROW(Table<int> x);
}
TEST(Constructor, ValueInit) {
	ASSERT_NO_THROW(Table<int> x(2,2));
}

TEST(Access, at) {
	Table<int> t(2, 2);
	ASSERT_NO_THROW(t.at(1, 0));
}
TEST(Access, thrown) {
	Table<int> t(2, 2);
	ASSERT_THROW(t.at(2, 0), std::out_of_range);
}
TEST(Access, data) {
	Table<int> t(2, 2);
	ASSERT_NO_THROW(int *tptr = t.data());
}

TEST(Copy, init) {
	Table<int> t(2, 2);
	Table<int> t2 = t;
	ASSERT_NO_THROW(t.at(1, 0));
}
TEST(Copy, assign) {
	Table<int> t(1,1);
	Table<int> t2(2,2);
	t2 = t;
	ASSERT_NO_THROW(t2.at(0, 0));
}

TEST(Move, init) {
	Table<int> t(2, 2);
	Table<int> t2 = std::move(t);
	ASSERT_TRUE(t2.data() != nullptr);
	ASSERT_TRUE(t.data() == nullptr);
}
TEST(Move, assign) {
	Table<int> t(2, 2);
	Table<int> t2(1, 1);
	t2 = std::move(t);
	ASSERT_TRUE(t2.data() != nullptr);
	ASSERT_TRUE(t.data() == nullptr);
}

TEST(Resize, resize) {

}