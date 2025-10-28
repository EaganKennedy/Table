#include "gtest/gtest.h"
#include "table.hpp"

TEST(Constructor, Init) {
	ASSERT_NO_THROW(Table<int> x);
}
TEST(Constructor, ValueInit) {
	ASSERT_NO_THROW(Table<int> x(2,2));
}

TEST(Access, at) {

}
TEST(Access, thrown) {

}
TEST(Access, data) {

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