#include <gtest/gtest.h>

#include "vector.hpp"

using IBusko::Vector;

TEST(default_constructor, size) {
    Vector<int> vector;
    ASSERT_EQ(vector.ssize(), 0);
}

TEST(size, one) {
    Vector<int> vector;
    vector.push_back(10);
    ASSERT_EQ(vector.ssize(), 1);
}

TEST(size, many) {
    Vector<int> vector;
    for (int i = 0; i < 10; i++) {
        vector.push_back(i);
    }
    ASSERT_EQ(vector.ssize(), 10);
}

TEST(has_item, positive) {
    Vector<int> vector;
    vector.push_back(10);
    ASSERT_TRUE(vector.has_item(10));
}

TEST(has_item, negative) {
    Vector<int> vector;
    vector.push_back(10);
    ASSERT_FALSE(vector.has_item(20));
}

TEST(insert, positive) {
    Vector<int> vector;
    vector.push_back(10);
    vector.insert(0, 5);
    ASSERT_EQ(vector.ssize(), 2);
    EXPECT_TRUE(vector.has_item(5));
    EXPECT_TRUE(vector.has_item(10));
}

TEST(insert, negative) {
    Vector<int> vector;
    vector.push_back(10);
    ASSERT_FALSE(vector.insert(-1, 3));
    ASSERT_FALSE(vector.insert(2, 5));
}

TEST(remove_first, positive) {
    Vector<int> vector;
    vector.push_back(10);
    vector.push_back(20);
    ASSERT_TRUE(vector.remove_first(10));
    ASSERT_EQ(vector.ssize(), 1);
    EXPECT_TRUE(vector.has_item(20));
}

TEST(remove_first, negative) {
    Vector<int> vector;
    vector.push_back(10);
    ASSERT_FALSE(vector.remove_first(20));
    ASSERT_EQ(vector.ssize(), 1);
    EXPECT_TRUE(vector.has_item(10));
}


