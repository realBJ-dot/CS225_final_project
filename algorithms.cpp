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
#include <fstream>

#include "cs225/PNG.h"

using std::vector;
using cs225::PNG;
using std::ifstream;

/**
 * function that build graph based on airport data and route data
 * @param airport_data: filename of airport data
 * @param route_data: filename of route data
 * @param g: empty graph to built on
 */
void build_graph(string airport_data, string route_data, Graph& g) {
   /**
   * load airport data. use counter to keep track of different part of 
   * airport information.
   * airports are used as vertices of the graph
   */
  ifstream wordsFile(airport_data);
  string word;
  if (wordsFile.is_open()) {
      /* Reads a line from `wordsFile` into `word` until the file ends. */
      while (getline(wordsFile, word)) {
          std::string part;
          std::istringstream ss(word);
          int counter = 0;
          string id;
          float latitude;
          float longitude;
          /** split single line on ','.
           * process information of a single airport 
           */
          while(std::getline(ss, part, ',')) {
            if (counter == 0) {
                id = part;
            } else if (counter == 6) {
                latitude = atof(part.c_str());
            } else if (counter == 7) {
                longitude = atof(part.c_str());
            }
            counter++;
          }
          Vertex v_ = Vertex(id, latitude, longitude);
          g.insertVertex(v_);
      }
      
  }
  /**
   * load route data. use counter to keep track of different part of 
   * routes information
   * routes are used as edge of the graph. distance between source and destination
   * airport is used as weight of the edges
   */
  ifstream wordsFile_(route_data);
  string word_;
  if (wordsFile_.is_open()) {
      /* Reads a line from `wordsFile` into `word` until the file ends. */
      while (getline(wordsFile_, word_)) {
          std::string part_;
          std::istringstream ss_(word_);
          int counter_ = 0;
          string source;
          string destination;
          /** split single line on ','.
          * process information of a single route 
           */
          while(std::getline(ss_, part_, ',')) {
            if (counter_ == 3) {
              source = part_;
            } else if (counter_ == 5) {
              destination = part_;
            }
            counter_++;  
          }
          Vertex s = Vertex(source);
          Vertex d = Vertex(destination);
          bool insert = g.insertEdge(s, d);
          if (insert) {
            /*set weight of edges as of distance*/
            Edge e = g.getEdge(s, d);
            float lat1 = e.source.getLatitude();
      
            float lng1 = e.source.getLongitude();
            float lat2 = e.dest.getLatitude();
            float lng2 = e.dest.getLongitude();
            float weight = distance_helper(lat1, lng1, lat2, lng2);
      
            g.setEdgeWeight(e.source, e.dest, weight);
          }
      }
  }
}

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
    p.writeToFile("world_map_with_airports.png");
}