#include "cmath"
#include <iostream>
#include "graph.h"
#include "latlng.h"
#include "edge.h"
#include <vector>
#include <queue>


std::vector<Vertex> BFS_Traversal(Graph& g_, Vertex rand_Vertex) {
    
    std::vector<Vertex> toReturn;
    
    std::vector<Vertex> visited;
    std::queue<Vertex> queue_;
    vector<Vertex> all_vertex = g_.getVertices();
    for (Vertex& s : all_vertex) {
        if (!s.visited()) {
            queue_.push(s);
        } else {
            visited.push_back(s);
        }
    }
    visited.push_back(rand_Vertex);
    queue_.push(rand_Vertex);
    vector<Vertex> neighbors = g_.getAdjacent(rand_Vertex);
    while (!queue_.empty()) {
        auto temp_ = queue_.front();
        queue_.pop();
        temp_.visit();
        toReturn.push_back(temp_);
        for (auto n : neighbors) {
            if (!n.visited()) {
                queue_.push(n);
                visited.push_back(n);
            }
        }
    }
    return toReturn;
}