#include <gtest/gtest.h>
#include "stack.h"

TEST(Stack, can_create_empty_stack) {
    Stack<int> st;
    EXPECT_TRUE(st.empty());
    EXPECT_EQ(st.size(), 0);
}

TEST(Stack, can_push_element) {
    Stack<int> st;
    st.push(42);
    EXPECT_FALSE(st.empty());
    EXPECT_EQ(st.size(), 1);
    EXPECT_EQ(st.top(), 42);
}

TEST(Stack, can_pop_element) {
    Stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);

    EXPECT_EQ(st.top(), 3);
    st.pop();
    
    EXPECT_EQ(st.top(), 2);
    EXPECT_EQ(st.size(), 2);
}

TEST(Stack, throws_when_top_empty_stack) {
    Stack<int> st;
    EXPECT_THROW(st.top(), std::out_of_range);
}

TEST(Stack, throws_when_pop_empty_stack) {
    Stack<int> st;
    EXPECT_THROW(st.pop(), std::out_of_range);
}