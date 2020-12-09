#include "../cs225/catch/catch.hpp"

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "../graph.h"
#include "../edge.h"
#include "../vertex.h"
#include "../algorithms.cpp"

// function that generates test graphs
vector<Graph*> getTestGraph() {
    vector<Graph*> g;
    Graph* g1 = new Graph(false, true);
    Graph* g2 = new Graph(false, true);
    Graph* g3 = new Graph(false, true);
    Graph* g4 = new Graph(false, true);
    Graph* g5 = new Graph(false, true);
    Graph* g6 = new Graph(false, true);

    Graph* g7 = new Graph(true, true);
    Graph* g8 = new Graph(true, true);

    Vertex v0 = Vertex("0");
    Vertex v1 = Vertex("1");
    Vertex v2 = Vertex("2");
    Vertex v3 = Vertex("3");
    Vertex v4 = Vertex("4");
    Vertex v5 = Vertex("5");
    Vertex v6 = Vertex("6");
    Vertex v7 = Vertex("7");
    
    // g1 is a graph with 3 vertices. This is to test the simple functionality of the algorithm.
    // 0 --> 1 --> 2
    g1 -> insertVertex(v2);
    g1 -> insertVertex(v1);
    g1 -> insertVertex(v0);
    g1 -> insertEdge(v0, v1);
    g1 -> insertEdge(v1, v2);
    g.push_back(g1);

    // g2 is a simple graph with 6 vertices and directed edges.
    g2 -> insertVertex(v5);
    g2 -> insertVertex(v4);
    g2 -> insertVertex(v3);
    g2 -> insertVertex(v2);
    g2 -> insertVertex(v1);
    g2 -> insertVertex(v0);
    g2 -> insertEdge(v0, v1);
    g2 -> insertEdge(v1, v2);
    g2 -> insertEdge(v1, v4);
    g2 -> insertEdge(v1, v5);
    g2 -> insertEdge(v2, v4);
    g2 -> insertEdge(v5, v4);
    g2 -> insertEdge(v4, v3);
    g.push_back(g2);

    // g3 is a simple graph with 8 vertices and directed edges.
    g3 -> insertVertex(v7);
    g3 -> insertVertex(v6);    
    g3 -> insertVertex(v5);
    g3 -> insertVertex(v4);
    g3 -> insertVertex(v3);
    g3 -> insertVertex(v2);
    g3 -> insertVertex(v1);
    g3 -> insertVertex(v0);
    g3 -> insertEdge(v0, v2);
    g3 -> insertEdge(v0, v3);
    g3 -> insertEdge(v2, v1);
    g3 -> insertEdge(v3, v4);
    g3 -> insertEdge(v4, v5);
    g3 -> insertEdge(v5, v1);
    g3 -> insertEdge(v3, v6);
    g3 -> insertEdge(v6, v7);
    g.push_back(g3);

//////// test traversal on graph with more than 1 connected components //////

    // g4 is a graph with 3 vertices, all disconnected
    g4 -> insertVertex(v2);
    g4 -> insertVertex(v1);
    g4 -> insertVertex(v0);
    g.push_back(g4);

    // g5 is a graph with 6 vertices, directed edges, and 2 connected components.
    g5 -> insertVertex(v5);
    g5 -> insertVertex(v4);
    g5 -> insertVertex(v3);
    g5 -> insertVertex(v2);
    g5 -> insertVertex(v1);
    g5 -> insertVertex(v0);
    g5 -> insertEdge(v0, v3);
    g5 -> insertEdge(v1, v2);
    g5 -> insertEdge(v2, v4);
    g5 -> insertEdge(v2, v5);
    g5 -> insertEdge(v4, v1);
    g.push_back(g5);

    // g6 is a simple graph with 8 vertices, directed edges, and 4 connected components.
    g6 -> insertVertex(v7);
    g6 -> insertVertex(v6);    
    g6 -> insertVertex(v5);
    g6 -> insertVertex(v4);
    g6 -> insertVertex(v3);
    g6 -> insertVertex(v2);
    g6 -> insertVertex(v1);
    g6 -> insertVertex(v0);
    g6 -> insertEdge(v4, v1);
    g6 -> insertEdge(v1, v5);
    g6 -> insertEdge(v5, v4);
    g6 -> insertEdge(v2, v7);
    g6 -> insertEdge(v2, v6);
    g6 -> insertEdge(v6, v7);
    g.push_back(g6);

    //g7 is a weighted simple graph
    g7 -> insertVertex(v2);
    g7 -> insertVertex(v1);
    g7 -> insertVertex(v0);
    g7 -> insertEdge(v0, v1);
    g7 -> setEdgeWeight(v0, v1, 1);
    g7 -> insertEdge(v1, v2);
    g7 -> setEdgeWeight(v1, v2, 2);
    g.push_back(g7);

    //g8 is a weighted graph with 8 nodes
    g8 -> insertVertex(v7);
    g8 -> insertVertex(v6);    
    g8 -> insertVertex(v5);
    g8 -> insertVertex(v4);
    g8 -> insertVertex(v3);
    g8 -> insertVertex(v2);
    g8 -> insertVertex(v1);
    g8 -> insertVertex(v0);
    g8 -> insertEdge(v4, v1);
    g8 -> setEdgeWeight(v4, v1, 2);
    g8 -> insertEdge(v1, v5);
    g8 -> setEdgeWeight(v1, v5, 5);
    g8 -> insertEdge(v5, v4);
    g8 -> setEdgeWeight(v5, v4, 3);
    g8 -> insertEdge(v2, v7);
    g8 -> setEdgeWeight(v2, v7, 1);
    g8 -> insertEdge(v2, v6);
    g8 -> setEdgeWeight(v2, v6, 0);
    g8 -> insertEdge(v6, v7);
    g8 -> setEdgeWeight(v6, v7, 0);
    g.push_back(g8);

    return g;
}

// function that prevents memory leak
void clear(vector<Graph*> g) {
    for (size_t i = 0; i < g.size(); i++) {
        delete g[i];
    }
}


TEST_CASE("BFS: simple graph with 3 nodes, expected 0 1 2") {
    vector<Graph*> g = getTestGraph();
    Algorithms a;
    vector<Vertex> v1 = a.BFS(*g[0]);
    REQUIRE ( v1.size() == 3 ) ;
    REQUIRE ( v1[0].getId() == "0" );
    REQUIRE ( v1[1].getId() == "1" );
    REQUIRE ( v1[2].getId() == "2" );
    clear(g);
}

TEST_CASE("BFS: graph with 6 nodes, expected 0 1 5 4 2 3") {
    vector<Graph*> g = getTestGraph();
    Algorithms a;
    vector<Vertex> v1 = a.BFS(*g[1]);
    REQUIRE ( v1.size() == 6 ) ;
    REQUIRE ( v1[0].getId() == "0" );
    REQUIRE ( v1[1].getId() == "1" );
    REQUIRE ( v1[2].getId() == "5" );
    REQUIRE ( v1[3].getId() == "4" );
    REQUIRE ( v1[4].getId() == "2" );
    REQUIRE ( v1[5].getId() == "3" );
    clear(g);
}

TEST_CASE("BFS: graph with 8 nodes, expected 0 3 2 6 4 1 7 5") {
    vector<Graph*> g = getTestGraph();
    Algorithms a;
    vector<Vertex> v1 = a.BFS(*g[2]);
    REQUIRE ( v1.size() == 8 ) ;
    REQUIRE ( v1[0].getId() == "0" );
    REQUIRE ( v1[1].getId() == "3" );
    REQUIRE ( v1[2].getId() == "2" );
    REQUIRE ( v1[3].getId() == "6" );
    REQUIRE ( v1[4].getId() == "4" );
    REQUIRE ( v1[5].getId() == "1" );
    REQUIRE ( v1[6].getId() == "7" );
    REQUIRE ( v1[7].getId() == "5" );
    clear(g);
}

TEST_CASE("BFS: graph with 3 disconnected nodes, expected 0 1 2") {
    vector<Graph*> g = getTestGraph();
    Algorithms a;
    vector<Vertex> v1 = a.BFS(*g[3]);
    REQUIRE ( v1.size() == 3 ) ;
    REQUIRE ( v1[0].getId() == "0" );
    REQUIRE ( v1[1].getId() == "1" );
    REQUIRE ( v1[2].getId() == "2" );
    clear(g);
}

TEST_CASE("BFS: graph with 6 nodes and 2 connected components, expected 0 3 1 2 5 4") {
    vector<Graph*> g = getTestGraph();
    Algorithms a;
    vector<Vertex> v1 = a.BFS(*g[4]);
    REQUIRE ( v1.size() == 6 ) ;
    REQUIRE ( v1[0].getId() == "0" );
    REQUIRE ( v1[1].getId() == "3" );
    REQUIRE ( v1[2].getId() == "1" );
    REQUIRE ( v1[3].getId() == "2" );
    REQUIRE ( v1[4].getId() == "5" );
    REQUIRE ( v1[5].getId() == "4" );
    clear(g);
}

TEST_CASE("BFS: graph with 8 nodes and 4 connected components,  expected 0 1 5 4 2 6 7 3") {
    vector<Graph*> g = getTestGraph();
    Algorithms a;
    vector<Vertex> v1 = a.BFS(*g[5]);
    REQUIRE ( v1.size() == 8 ) ;
    REQUIRE ( v1[0].getId() == "0" );
    REQUIRE ( v1[1].getId() == "1" );
    REQUIRE ( v1[2].getId() == "5" );
    REQUIRE ( v1[3].getId() == "4" );
    REQUIRE ( v1[4].getId() == "2" );
    REQUIRE ( v1[5].getId() == "6" );
    REQUIRE ( v1[6].getId() == "7" );
    REQUIRE ( v1[7].getId() == "3" );
    clear(g);
}


//////////////////////DFS test cases////////////////////
TEST_CASE("DFS:simple graph with three nodes, expected 0 1 2") {
    vector<Graph*> g = getTestGraph();
    Algorithms a;
    vector<Vertex> v1 = a.DFS(*g[0]);
    REQUIRE ( v1.size() == 3 ) ;
    REQUIRE ( v1[0].getId() == "0" );
    REQUIRE ( v1[1].getId() == "1" );
    REQUIRE ( v1[2].getId() == "2" );
    clear(g);
}

TEST_CASE("DFS:graph with six nodes, expected 0 1 2 4 3 5") {
    vector<Graph*> g = getTestGraph();
    Algorithms a;
    vector<Vertex> v1 = a.DFS(*g[1]);
    REQUIRE ( v1.size() == 6 ) ;
    REQUIRE ( v1[0].getId() == "0" );
    REQUIRE ( v1[1].getId() == "1" );
    REQUIRE ( v1[2].getId() == "2" );
    REQUIRE ( v1[3].getId() == "4" );
    REQUIRE ( v1[4].getId() == "3" );
    REQUIRE ( v1[5].getId() == "5" );
    clear(g);
}

TEST_CASE("DFS:graph with 8 nodes, expected 0 2 1 3 4 5 6 7") {
    vector<Graph*> g = getTestGraph();
    Algorithms a;
    vector<Vertex> v1 = a.DFS(*g[2]);
    REQUIRE ( v1.size() == 8 ) ;
    REQUIRE ( v1[0].getId() == "0" );
    REQUIRE ( v1[1].getId() == "2" );
    REQUIRE ( v1[2].getId() == "1" );
    REQUIRE ( v1[3].getId() == "3" );
    REQUIRE ( v1[4].getId() == "4" );
    REQUIRE ( v1[5].getId() == "5" );
    REQUIRE ( v1[6].getId() == "6" );
    REQUIRE ( v1[7].getId() == "7" );
    clear(g);
}

TEST_CASE("DFS: graph with 3 disconnected nodes, expected 0 1 2") {
    vector<Graph*> g = getTestGraph();
    Algorithms a;
    vector<Vertex> v1 = a.DFS(*g[3]);
    REQUIRE ( v1.size() == 3 ) ;
    REQUIRE ( v1[0].getId() == "0" );
    REQUIRE ( v1[1].getId() == "1" );
    REQUIRE ( v1[2].getId() == "2" );
    clear(g);
}

TEST_CASE("DFS: graph with 6 nodes and 2 connected components, expected 0 3 1 2 4 5") {
    vector<Graph*> g = getTestGraph();
    Algorithms a;
    vector<Vertex> v1 = a.DFS(*g[4]);
    REQUIRE ( v1.size() == 6 ) ;
    REQUIRE ( v1[0].getId() == "0" );
    REQUIRE ( v1[1].getId() == "3" );
    REQUIRE ( v1[2].getId() == "1" );
    REQUIRE ( v1[3].getId() == "2" );
    REQUIRE ( v1[4].getId() == "4" );
    REQUIRE ( v1[5].getId() == "5" );
    clear(g);
}

TEST_CASE("DFS: graph with 8 nodes and 4 connected components,  expected 0 1 5 4 2 7 6 3") {
    vector<Graph*> g = getTestGraph();
    Algorithms a;
    vector<Vertex> v1 = a.DFS(*g[5]);
    REQUIRE ( v1.size() == 8 ) ;
    REQUIRE ( v1[0].getId() == "0" );
    REQUIRE ( v1[1].getId() == "1" );
    REQUIRE ( v1[2].getId() == "5" );
    REQUIRE ( v1[3].getId() == "4" );
    REQUIRE ( v1[4].getId() == "2" );
    REQUIRE ( v1[5].getId() == "7" );
    REQUIRE ( v1[6].getId() == "6" );
    REQUIRE ( v1[7].getId() == "3" );
    clear(g);
}

//////////weighted graph test cases////////////
TEST_CASE("weighted BFS: graph with 3 nodes and two weighted edges, expected 0, 1, 2") {
    vector<Graph*> g = getTestGraph();
    Algorithms a;
    vector<Vertex> v1 = a.BFS(*g[6]);
    REQUIRE ( v1.size() == 3 ) ;
    REQUIRE ( v1[0].getId() == "0" );
    REQUIRE ( v1[1].getId() == "1" );
    REQUIRE ( v1[2].getId() == "2" );
    clear(g);
}

TEST_CASE("weighted DFS: graph with 8 nodes and 4 connected components") {
    vector<Graph*> g = getTestGraph();
    Algorithms a;
    vector<Vertex> v1 = a.DFS(*g[7]);
    REQUIRE ( v1.size() == 8 ) ;
    REQUIRE ( v1[0].getId() == "0" );
    REQUIRE ( v1[1].getId() == "1" );
    REQUIRE ( v1[2].getId() == "5" );
    REQUIRE ( v1[3].getId() == "4" );
    REQUIRE ( v1[4].getId() == "2" );
    REQUIRE ( v1[5].getId() == "7" );
    REQUIRE ( v1[6].getId() == "6" );
    REQUIRE ( v1[7].getId() == "3" );
    clear(g);
}



