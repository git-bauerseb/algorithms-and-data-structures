#include <gtest/gtest.h>

#include "../include/i2a/elem_structures.h"

class DLListTest : public ::testing::Test {

    protected:
        DLListTest() : m_list_0({1,2,3,4,5}) {}

        i2a::structures::DLList<int> m_list_0;
};

TEST_F(DLListTest, testSearching) {
    // Search non-existing element
    EXPECT_EQ(nullptr, m_list_0.search(6));

    // Search existing element
    auto node = m_list_0.search(5);

    ASSERT_NE(nullptr, node);
    EXPECT_EQ(5, node->key);
}

TEST_F(DLListTest, testCorrectPointers) {
    auto node = m_list_0.search(3);

    ASSERT_EQ(node->previous, m_list_0.search(2));
    ASSERT_EQ(nullptr, m_list_0.search(5)->next);
    ASSERT_EQ(nullptr, m_list_0.search(1)->previous);
}

TEST_F(DLListTest, testInsertionAtFront) {

    EXPECT_EQ(nullptr, m_list_0.search(-1));
    m_list_0.insertBegin(-1);
    ASSERT_NE(nullptr, m_list_0.search(-1));

    auto node = m_list_0.search(-1);
    ASSERT_EQ(-1, node->key);
}

TEST_F(DLListTest, testDeletion) {

    auto lambda = [&](i2a::structures::DLList<int>::DLNode& node) {
        std::cout << node.key << "\n";
    };

    m_list_0.traverse<decltype(lambda)>(lambda);

    /*
    EXPECT_NE(nullptr, m_list_0.search(1));
    m_list_0.deleteElement(1);
    EXPECT_EQ(nullptr, m_list_0.search(1));
     */
}