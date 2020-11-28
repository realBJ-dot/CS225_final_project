#include "cmath"
#include <iostream>
#include "graph.h"
#include "latlng.h"
#include "edge.h"
#include <vector>
#include <queue>

std::vector<Vertex> BFS_Traversal(Graph& g_) {
    std::vector<Vertex> toReturn;

    Vertex rand_Vertex = g_.getStartingVertex();
    //int size = g_.getVertices().size();
    std::vector<Vertex> visited;
    std::queue<Vertex> queue_;
    for (auto s : g_.getVertices()) {
        s.unvisited();
        queue_.push(s);
    }
    visited.push_back(rand_Vertex);
    queue_.push(rand_Vertex);
    while (!queue_.empty()) {
        auto temp_ = queue_.front();
        queue_.pop();
        temp_.visit();
        toReturn.push_back(temp_);
        vector<Vertex> neighbors = g_.getAdjacent(rand_Vertex);
        for (auto n : neighbors) {
            if (!n.visited()) {
                queue_.push(n);
                visited.push_back(n);
            }
        }
    }
    return toReturn;
}