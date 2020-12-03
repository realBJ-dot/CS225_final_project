#include "cmath"
#include <iostream>
#include "graph.h"
#include "latlng.h"
#include "edge.h"
#include <vector>
#include <queue>
#include <map>


std::vector<Vertex> BFS_Traversal(Graph& g_, Vertex start_vertex) {
    std::vector<Vertex> toReturn;
    std::queue<Vertex> queue_;
    queue_.push(start_vertex);
    std::map<string, bool> visited_;
    for (auto& v : g_.getVertices()) {
        visited_[v.getId()] = false;
    }
    visited_[start_vertex.getId()] = true;
    while (!queue_.empty()) {
        auto temp_ = queue_.front();
        queue_.pop();
        toReturn.push_back(temp_);
        for (Vertex& n : g_.getAdjacent(temp_)) {
            if (!visited_[n.getId()]) {
                queue_.push(n);
                visited_[n.getId()] = true;
            }
        }
    }
    return toReturn;
}
std::vector<Vertex> DFS_Traversal(Graph& g_, Vertex start_vertex) {
    return vector<Vertex>();
}