#include "Stack.h"
#include <gtest/gtest.h>

#ifndef TEST_STACK_CPP  
#define TEST_STACK_CPP
static_assert(true, "Test_stack.cpp is being compiled");
#endif

TEST(StackTest, PushPopTop) {
    Stack<int> s;
    EXPECT_TRUE(s.empty());
    s.push(10);
    EXPECT_FALSE(s.empty());
    EXPECT_EQ(s.top(), 10);
    s.push(20);
    EXPECT_EQ(s.top(), 20);
    s.pop();
    EXPECT_EQ(s.top(), 10);
    s.pop();
    EXPECT_TRUE(s.empty());
}

TEST(StackTest, PopEmptyThrows) {
    Stack<int> s;
    EXPECT_THROW(s.pop(), std::out_of_range);
}

TEST(StackTest, TopEmptyThrows) {
    Stack<int> s;
    EXPECT_THROW(s.top(), std::out_of_range);
}

TEST(StackTest, SizeAndClear) {
    Stack<int> s;
    s.push(1);
    s.push(2);
    EXPECT_EQ(s.size(), 2);
    s.clear();
    EXPECT_TRUE(s.empty());
    EXPECT_EQ(s.size(), 0);
}

TEST(StackMmTest, MinMaxBasic) {
    StackMm<int> s;
    s.push(5);
    EXPECT_EQ(s.getMin(), 5);
    EXPECT_EQ(s.getMax(), 5);
    s.push(3);
    EXPECT_EQ(s.getMin(), 3);
    EXPECT_EQ(s.getMax(), 5);
    s.push(7);
    EXPECT_EQ(s.getMin(), 3);
    EXPECT_EQ(s.getMax(), 7);
    s.pop();
    EXPECT_EQ(s.getMin(), 3);
    EXPECT_EQ(s.getMax(), 5);
    s.pop();
    EXPECT_EQ(s.getMin(), 5);
    EXPECT_EQ(s.getMax(), 5);
}

TEST(StackMmTest, MinMaxThrowsOnEmpty) {
    StackMm<int> s;
    EXPECT_THROW(s.getMin(), std::out_of_range);
    EXPECT_THROW(s.getMax(), std::out_of_range);
}

TEST(StackMmTest, PopThrowsOnEmpty) {
    StackMm<int> s;
    EXPECT_THROW(s.pop(), std::out_of_range);
}