#include "cmath"
#include <iostream>
#include "graph.h"
#include "util.h"
#include "edge.h"
#include <vector>
#include <queue>
#include <map>
#include <stack>

/**
 * BFS traversal
 * @param g_: graph to traverse
 * @param start_vertex: starting vertex of traversal
 * @return vector that represents order of nodes visited
 */
std::vector<Vertex> BFS_Traversal(Graph& g_, Vertex start_vertex) {
    std::vector<Vertex> toReturn;
    std::queue<Vertex> queue_;
    queue_.push(start_vertex);
    // map that maps id of Vertex to whether it is visited
    // initial value for all Vertexs are false
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

/**
 * DFS traversal
 * @param g_: graph to traverse
 * @param start_vertex: starting vertex of traversal
 * @return vector that represents order of nodes visited
 */
std::vector<Vertex> DFS_Traversal(Graph& g_, Vertex start_vertex) {
    std::vector<Vertex> toReturn;
    std::stack<Vertex> stack_;
    stack_.push(start_vertex);
    // map that maps id of Vertex to whether it is visited
    // initial value for all Vertexs are false
    std::map<string, bool> visited_;
    for (auto& v : g_.getVertices()) {
        visited_[v.getId()] = false;
    }
    visited_[start_vertex.getId()] = true;
    while (!stack_.empty()) {
        auto temp_ = stack_.top();
        stack_.pop();
        toReturn.push_back(temp_);
        for (Vertex& n : g_.getAdjacent(temp_)) {
            if (!visited_[n.getId()]) {
                stack_.push(n);
                visited_[n.getId()] = true;
            }
        }
    }
    return toReturn;
}