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

}
TEST(Copy, assign) {

}

TEST(Move, init) {

}
TEST(Move, assign) {

}

TEST(Resize, resize) {

}