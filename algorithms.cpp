#include "cmath"
#include <iostream>
#include "graph.h"
#include "util.h"
#include "edge.h"
#include <vector>
#include <queue>
#include <map>
#include <stack>
#include <utility>

#include "cs225/PNG.h"

using std::vector;
using cs225::PNG;

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


void visualization(Graph& g_) {
    PNG p;
    p.readFromFile("world-map.png");
    /*
    for (unsigned x = 0; x < p.width(); x++) {
    for (unsigned y = 0; y < p.height(); y++) {
        cs225::HSLAPixel & pixel_in = p.getPixel(x, y);
        pixel_in.a = 1;
        pixel_in.h = 0;
        pixel_in.l = 0.5;
        pixel_in.s = .5;
    }
    }
    */
    float lat0 = p.height() / 2;
    float lng0 = p.width() / 2;
    float lat_degree = p.height()/180;
    float lng_degree = p.width()/360;
    
    vector<Vertex> v = g_.getVertices();
    //vector<std::pair<float, float>> latlng;
    for (auto e : v) {
        //latlng.push_back(pair<float, float>(e.getLatitude(), e.getLongitude()));
        float lat = e.getLatitude();
        float lng = e.getLongitude();
        float lat_p = (0-lat)*lat_degree + lat0;
        float lng_p = lng*lng_degree + lng0;
        if (lng_p == 2700 && lat_p == 2700) {
            continue;
        }
        cs225::HSLAPixel & pixel = p.getPixel((int) lng_p, (int) lat_p);
        pixel.h = 0;
        pixel.a = 1;
        pixel.l = 1;
        pixel.s = .5;
    }
    for (int x = -180; x < 180; x += 30) {
        for (unsigned y = 0; y < p.height(); y++) {
            float xi = x*lng_degree + lng0;
            cs225::HSLAPixel & pixel = p.getPixel((int) xi, (int) y);
        pixel.h = 0;
        pixel.a = 1;
        pixel.l = 1;
        pixel.s = .5;
    }
    }
    /*for (int i = 0; i < 100; i++) {
    cs225::HSLAPixel & pixel = p.getPixel((int) (-118.40799 * lng_degree + lng0 + i), (int) (-33.9425 * lat_degree + lat0));

    pixel.h = 0;
    pixel.a = 1;
    pixel.l = 1;
    pixel.s = .5;
    }*/
    
    p.writeToFile("world_map_with_airports.png");
}