#include <gtest/gtest.h>
#include "queue.h"

TEST(Queue, can_create_empty_queue) {
    Queue<int> q;
    EXPECT_TRUE(q.empty());
    EXPECT_EQ(q.size(), 0);
}

TEST(Queue, can_push_and_pop) {
    Queue<int> q;
    q.push(10);
    q.push(20);
    
    EXPECT_EQ(q.front(), 10);
    q.pop();
    EXPECT_EQ(q.front(), 20);
    EXPECT_EQ(q.size(), 1);
}

TEST(Queue, can_resize_when_full) {
    Queue<int> q(2); 
    
    q.push(1);
    q.push(2);
    q.push(3); 
    
    EXPECT_EQ(q.size(), 3);
    EXPECT_EQ(q.front(), 1);
}

TEST(Queue, circular_buffer_works_correctly) {
    Queue<int> q(3);
    
    q.push(1);
    q.push(2);
    q.push(3);
    
    q.pop(); 
    
    q.push(4); 
    
    EXPECT_EQ(q.front(), 2);
    EXPECT_EQ(q.size(), 3);
}

TEST(Queue, throws_when_empty) {
    Queue<int> q;
    EXPECT_THROW(q.pop(), std::out_of_range);
    EXPECT_THROW(q.front(), std::out_of_range);
}