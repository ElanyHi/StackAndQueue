#pragma once
#include "queue.h"
#include "MyVector.h" 
#include <stdexcept>

// Функция обхода в ширину (BFS). Принимает граф (список смежности на базе MyVector) и стартовую вершину.
inline MyVector<int> run_bfs(const MyVector<MyVector<int>>& graph, int start_v) {
    if (start_v < 0 || static_cast<size_t>(start_v) >= graph.size()) {
        throw std::out_of_range("Invalid start v");
    }

    size_t n = graph.size();
    
    MyVector<bool> visit(n, false);
    MyVector<int> len(n, -1);

    Queue<int> q;

    q.push(start_v);
    visit[start_v] = true;
    len[start_v] = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        // Проходим по соседям текущей вершины. 
        for (int v : graph[cur]) {
            if (!visit[v]) {
                visit[v] = true;
                len[v] = len[cur] + 1;
                q.push(v);
            }
        }
    }

    return len;
}