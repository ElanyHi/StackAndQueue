#include <gtest/gtest.h>
#include "bfs.h"
#include "MyVector.h"

TEST(BFS, linear_graph) {
    MyVector<MyVector<int>> graph(4);
    graph[0].push_back(1);
    graph[1].push_back(2);
    graph[2].push_back(3);

    MyVector<int> distances = run_bfs(graph, 0);

    EXPECT_EQ(distances[0], 0);
    EXPECT_EQ(distances[1], 1);
    EXPECT_EQ(distances[2], 2);
    EXPECT_EQ(distances[3], 3);
}

TEST(BFS, disconnected_graph) {
    MyVector<MyVector<int>> graph(3);
    graph[0].push_back(1);
    graph[1].push_back(0);

    MyVector<int> distances = run_bfs(graph, 0);

    EXPECT_EQ(distances[0], 0);
    EXPECT_EQ(distances[1], 1);
    EXPECT_EQ(distances[2], -1); // Недостижимо
}

TEST(BFS, complex_tree) {
    MyVector<MyVector<int>> graph(6);
    graph[0].push_back(1);
    graph[0].push_back(2);
    
    graph[1].push_back(0);
    graph[1].push_back(3);
    graph[1].push_back(4);
    
    graph[2].push_back(0);
    graph[2].push_back(5);

    graph[3].push_back(1);
    graph[4].push_back(1);
    graph[5].push_back(2);

    MyVector<int> distances = run_bfs(graph, 0);

    EXPECT_EQ(distances[0], 0); 
    EXPECT_EQ(distances[1], 1); 
    EXPECT_EQ(distances[2], 1); 
    EXPECT_EQ(distances[3], 2); 
    EXPECT_EQ(distances[4], 2); 
    EXPECT_EQ(distances[5], 2); 
}