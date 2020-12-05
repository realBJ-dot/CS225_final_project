#include "cmath"
#include <iostream>
#include "graph.h"
#include "util.h"
#include "edge.h"
#include <vector>
#include <queue>
#include <map>
#include <stack>

using std::vector;

/**
 * helper function for BFS traversal
 * @param g_: graph to traverse
 * @param start_vertex: starting vertex of traversal
 * @param toReturn: vector that represents orders of nodes visited
 * @param visited_: a map that keeps track of whether a node is visited
 */
void BFS_Traversal(Graph& g_, Vertex start_vertex, vector<Vertex>& toReturn, 
                    std::map<string, bool>& visited_) {
    std::queue<Vertex> queue_;
    queue_.push(start_vertex);
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
}

/**
 * BFS traversal
 * covers all connected components of the graph
 * @param g_: graph to traverse
 * @return vector that represents orders of nodes visited
 */
vector<Vertex> BFS(Graph& g_) {
    vector<Vertex> toReturn;
    // map that maps id of Vertex to whether it is visited
    // initial value for all Vertexs are false
    std::map<string, bool> visited_;
    for (auto& v : g_.getVertices()) {
        visited_[v.getId()] = false;
    }
    for (auto& v1: g_.getVertices()) {
        if (!visited_[v1.getId()]) {
            BFS_Traversal(g_, v1, toReturn, visited_);
        }
    }
    return toReturn; 
}

/**
 * helper function for BFS traversal
 * @param g_: graph to traverse
 * @param start_vertex: starting vertex of traversal
 * @param toReturn: vector that represents orders of nodes visited
 * @param visited_: a map that keeps track of whether a node is visited
 */
void DFS_Traversal(Graph& g_, Vertex start_vertex, vector<Vertex>& toReturn, 
                    std::map<string, bool>& visited_) {
    std::stack<Vertex> stack_;
    stack_.push(start_vertex);
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
}

/**
 * DFS traversal
 * covers all connected components of the graph
 * @param g_: graph to traverse
 * @return vector that represents orders of nodes visited
 */
vector<Vertex> DFS(Graph& g_) {
    vector<Vertex> toReturn;
    // map that maps id of Vertex to whether it is visited
    // initial value for all Vertices are false
    std::map<string, bool> visited_;
    for (auto& v : g_.getVertices()) {
        visited_[v.getId()] = false;
    }
    for (auto& v1: g_.getVertices()) {
        if (!visited_[v1.getId()]) {
            DFS_Traversal(g_, v1, toReturn, visited_);
        }
    } 
    return toReturn;
}



