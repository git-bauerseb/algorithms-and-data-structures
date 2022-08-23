#include "gtest/gtest.h"

#include "../include/i2a/elem_structures.h"

class StackTest :  public ::testing::Test {

    protected:
        void SetUp() override {
            m_stack0.push(9);
            m_stack0.push(18);
            m_stack0.push(834);

        }

        i2a::structures::Stack<int> m_stack0;
        i2a::structures::Stack<int> m_stack1;
};

TEST_F(StackTest, IsEmptyInitially) {
    EXPECT_EQ(m_stack1.is_empty(), true);
}