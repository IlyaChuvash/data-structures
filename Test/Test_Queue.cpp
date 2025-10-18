#include "Queue.h"
#include <gtest/gtest.h>

#ifndef TEST_QUEUE_CPP  
#define TEST_QUEUE_CPP
static_assert(true, "Test_Queue.cpp is being compiled");
#endif

TEST(QueueTest, IsInitiallyEmpty) {
    Queue<int> q;
    EXPECT_EQ(q.size(), 0);
}

TEST(QueueTest, AddIncreasesSize) {
    Queue<int> q;
    q.add(1);
    q.add(2);
    EXPECT_EQ(q.size(), 2);
}

TEST(QueueTest, FirstReturnsCorrectElement) {
    Queue<int> q;
    q.add(1);
    q.add(2);
    EXPECT_EQ(q.first(), 1);
}

TEST(QueueTest, RemoveDecreasesSize) {
    Queue<int> q;
    q.add(1);
    q.add(2);
    q.remove();
    EXPECT_EQ(q.size(), 1);
}

TEST(QueueTest, RemoveUpdatesFirstElement) {
    Queue<int> q;
    q.add(1);
    q.add(2);
    q.remove();
    EXPECT_EQ(q.first(), 2);
}

TEST(QueueTest, RemoveAllMakesQueueEmpty) {
    Queue<int> q;
    q.add(1);
    q.add(2);
    q.remove();
    q.remove();
    EXPECT_EQ(q.size(), 0);
}

TEST(QueueTest, RemoveEmptyThrows) {
    Queue<int> q;
    EXPECT_THROW(q.remove(), std::out_of_range);
}

TEST(QueueTest, FirstEmptyThrows) {
    Queue<int> q;
    EXPECT_THROW(q.first(), std::out_of_range);
}

TEST(QueueTest, ClearWorks) {
    Queue<int> q;
    q.add(10);
    q.add(20);
    q.clear();
    EXPECT_EQ(q.size(), 0);
    EXPECT_THROW(q.first(), std::out_of_range);
}

TEST(QueueTest, EmptyMethod) {
    Queue<int> q;
    EXPECT_TRUE(q.empty());
    q.add(5);
    EXPECT_FALSE(q.empty());
    q.remove();
    EXPECT_TRUE(q.empty());
}

TEST(QueueTest, RepackWhenArrayBecomesSparse) {
    Queue<int> q;

    for (int i = 0; i < 100; i++) {
        q.add(i);
    }

    size_t initial_capacity = q.size(); 

    for (int i = 0; i < 80; i++) {
        q.remove();
    }

    EXPECT_EQ(q.size(), 20);
    EXPECT_EQ(q.first(), 80);

    for (int i = 0; i < 10; i++) {
        q.remove();
    }
    EXPECT_EQ(q.size(), 10);
    EXPECT_EQ(q.first(), 90);
}

