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
         */
        void build_graph(string airport_data, string route_data, Graph& g);

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
         * function that project graph on to world map 
         * vertices of graph are airports and edges are routes
         * result is saved as a PNG named "world_map_with_airports.png"
         * @param g_ : graph to visualize
         */
        void visualization(Graph& g_);

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
};

#include "algorithms.cpp"



