#include <gtest/gtest.h>

#include "doubly_linked_list.hpp"

using IBusko::DoublyLinkedList;

TEST(DoublyLinkedListTest, push_back) {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    EXPECT_EQ(list.size(), 3);

}

TEST(DoublyLinkedListTest, has_item) {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    EXPECT_TRUE(list.has_item(2));
    EXPECT_FALSE(list.has_item(4));
}


TEST(DoublyLinkedListTest, remove_first) {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    EXPECT_TRUE(list.remove_first(2));
    EXPECT_EQ(list.size(), 2);
    EXPECT_FALSE(list.has_item(2));
    EXPECT_FALSE(list.remove_first(4));
}

TEST(DoublyLinkedListTest, size) {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    EXPECT_EQ(list.size(), 3);
    list.remove_first(2);
    EXPECT_EQ(list.size(), 2);
}
