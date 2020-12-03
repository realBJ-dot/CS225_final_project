#include "cmath"
#include <iostream>
#include "graph.h"
#include "latlng.h"
#include "edge.h"
#include <vector>
#include <queue>


std::vector<Vertex> BFS_Traversal(Graph& g_, Vertex start_vertex) {
    std::cout << "new test" << std::endl;
    std::vector<Vertex> toReturn;
    std::queue<Vertex> queue_;
    queue_.push(start_vertex);
    start_vertex.visit();
    std::cout << g_.getVertices()[2].getId() << " visited: " << g_.getVertices()[3].visited() << std::endl;
    while (!queue_.empty()) {
        auto temp_ = queue_.front();
        queue_.pop();
        toReturn.push_back(temp_);
        for (Vertex& n : g_.getAdjacent(temp_)) {
            std::cout << "neighbor of " << temp_.getId() << ": " << n.getId() << std::endl;
            std::cout << g_.getVertices()[2].getId() << " visited: " << g_.getVertices()[3].visited() << std::endl;
            if (!n.visited()) {
                std::cout << "visit " << n.getId() << std::endl;
                queue_.push(n);
                n.visit();
            }
        }
    }
    std::cout << g_.getVertices()[4].getId() << " visited: " << g_.getVertices()[4].visited() << std::endl;
    std::cout << "node: " << toReturn.size() << std::endl;
    return toReturn;
}