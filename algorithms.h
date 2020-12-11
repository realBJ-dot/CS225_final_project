#pragma once

#include "graph.h"
#include "util.h"
#include "edge.h"
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <stack>
#include <utility>
#include <fstream>
#include "cs225/PNG.h"

class Algorithms {

    public:
        /**
         * function that build graph based on airport data and route data
         * @param airport_data: filename of airport data
         * @param route_data: filename of route data
         * @param g: empty graph to built on
         * @param id2name: map that map id of airport to its full name
         * @param name2id: map that map name of airport to its id
         */
        void build_graph(string airport_data, string route_data, Graph& g, 
                            std::map<string, string>& id2name, std::map<string, string>& name2id);

        /**
         * BFS traversal
         * covers all connected components of the graph
         * @param g_: graph to traverse
         * @return vector that represents orders of nodes visited
         */
        vector<Vertex> BFS(Graph& g_);

        /**
         * DFS traversal
         * covers all connected components of the graph
         * @param g_: graph to traverse
         * @return vector that represents orders of nodes visited
         */
        vector<Vertex> DFS(Graph& g_);

        /**
         * graphic output of graph
         * function that project airports and routes on to world map 
         * result is saved as "world_map_with_airports.png" 
         * and "world_map_with_airports_and_routes.png"
         * @param g_ : graph to visualize
         */
        void visualization(Graph& g_);

        /**
         * Floyd Warshall's algorithm
         * Constructs a distance matrix D that demonstrate the shortest distance
         * between every pair of vertices
         * and a path matrix P that helps reconstructs the shortest path
         * @param g_: graph to run Floyd Warshall's algorithm on
        */
        void FloydWarshall(Graph& g_);

        /**
         * function that reconstructs the shortest path between two vertices 
         * using the path matrix created in Floyd-Warshall's algorithm
         * @param source: id of the source vertex
         * @param dest: id of the dest vertex
         * @return: a vector that contains id of vertices in the shrotest path 
         */
        vector<string> construct_path(string source, string dest);

        /**
         * calculate the distance of the shrotest path between source and dest
         * @param source: id of the source vertex
         * @param dest: id of the dest vertex
         * @return: shortest distance betwee source and dest
         */
        float shortest_distance(string source, string dest);
   
    private:
    
        /**
         * private helper function for BFS
         */
        void BFS_Traversal(Graph& g_, Vertex start_vertex, vector<Vertex>& toReturn, 
                    std::map<string, bool>& visited_);
        /**
         * private helper function for DFS
         */
        void DFS_Traversal(Graph& g_, Vertex start_vertex, vector<Vertex>& toReturn, 
                    std::map<string, bool>& visited_);   
        
        /**
         * 2d vector used to store the distance matrix created by Floyd-Warshall's algorithm
         * also used by shortest_distance function
         */
        vector<vector<float>> D; 
        /**
         * 2d vector used to store the path matrix created by Floyd-Warshall's algorithm
         * also used by construct_path function
         */ 
        vector<vector<string>> P; 
        /**
         * map that maps vertex id to its index in vertex vector returned by getVertices function
         * help construct distance and path matrix in Floyd-Warshall's algorithm
         */
        std::map<string, int> M;
};

#include "algorithms.cpp"



