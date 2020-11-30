#include "../cs225/catch/catch.hpp"

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "../graph.h"
#include "../edge.h"
#include "../vertex.h"
#include "../algrithem.cpp"

vector<Graph> getTestGraph() {
    vector<Graph> g;
    Graph g1 = Graph(false, true);
    Graph g2 = Graph(false, true);
    Graph g3 = Graph(false, true);
    
    g.push_back(g2);
    g.push_back(g3);
    //g1 is a graph with three vertices, it's actaully jsut a list. This is to test the simple functionality of the algorithm.
    Vertex g1v1 = Vertex(to_string(0));
    Vertex g1v2 = Vertex(to_string(1));
    Vertex g1v3 = Vertex(to_string(2));
    g1.insertVertex(g1v1);
    g1.insertVertex(g1v2);
    g1.insertVertex(g1v3);
    g1.insertEdge(g1v1, g1v2);
    g1.insertEdge(g1v2, g1v3);
    g.push_back(g1);

    //g2 is a simple graph with several vertices and directed edges. expected 0 1 2 4 5 3
    Vertex g2v0 = Vertex(to_string(0));
    Vertex g2v1 = Vertex(to_string(1));
    Vertex g2v2 = Vertex(to_string(2));
    Vertex g2v3 = Vertex(to_string(3));
    Vertex g2v4 = Vertex(to_string(4));
    Vertex g2v5 = Vertex(to_string(5));
    g2.insertVertex(g2v0);
    g2.insertVertex(g2v1);
    g2.insertVertex(g2v2);
    g2.insertVertex(g2v3);
    g2.insertVertex(g2v4);
    g2.insertVertex(g2v5);
    g2.insertEdge(g2v0, g2v1);
    g2.insertEdge(g2v1, g2v2);
    g2.insertEdge(g2v1, g2v4);
    g2.insertEdge(g2v1, g2v5);
    g2.insertEdge(g2v2, g2v4);
    g2.insertEdge(g2v5, g2v4);
    g2.insertEdge(g2v4, g2v3);
    g.push_back(g2);

    //g3 is a simple graph with several vertices and directed edges.
    Vertex g3v0 = Vertex(to_string(0));
    Vertex g3v1 = Vertex(to_string(1));
    Vertex g3v2 = Vertex(to_string(2));
    Vertex g3v3 = Vertex(to_string(3));
    Vertex g3v4 = Vertex(to_string(4));
    Vertex g3v5 = Vertex(to_string(5));
    Vertex g3v6 = Vertex(to_string(6));
    Vertex g3v7 = Vertex(to_string(7));
    g3.insertVertex(g3v0);
    g3.insertVertex(g3v1);
    g3.insertVertex(g3v2);
    g3.insertVertex(g3v3);
    g3.insertVertex(g3v4);
    g3.insertVertex(g3v5);
    g3.insertVertex(g3v6);
    g3.insertVertex(g3v7);
    g3.insertEdge(g3v0, g3v2);
    g3.insertEdge(g3v0, g3v3);
    g3.insertEdge(g3v2, g3v1);
    g3.insertEdge(g3v3, g3v4);
    g3.insertEdge(g3v4, g3v5);
    g3.insertEdge(g3v5, g3v1);
    g3.insertEdge(g3v3, g3v6);
    g3.insertEdge(g3v6, g3v7);
    g.push_back(g3);

    return g;
}


TEST_CASE("simple graph with three nodes, expected 0 1 2") {
    vector<Graph> g = getTestGraph();
    vector<Vertex> v1 = BFS_Traversal(g[0], Vertex(to_string(0)));
    REQUIRE ( v1[0].getId() == to_string(0) );
    REQUIRE ( v1[1].getId() == to_string(1) );
    REQUIRE ( v1[2].getId() == to_string(2) );
}

TEST_CASE("graph with six nodes, expected 0 1 2 4 5 3") {
    vector<Graph> g = getTestGraph();
    vector<Vertex> v1 = BFS_Traversal(g[1], Vertex(to_string(0)));
    REQUIRE ( v1[0].getId() == to_string(0) );
    REQUIRE ( v1[1].getId() == to_string(1) );
    REQUIRE ( v1[2].getId() == to_string(2) );
    REQUIRE ( v1[3].getId() == to_string(4) );
    REQUIRE ( v1[4].getId() == to_string(5) );
    REQUIRE ( v1[5].getId() == to_string(3) );
}

TEST_CASE("graph with 8 nodes, expected 0 2 3 1 4 6 5 7") {
    vector<Graph> g = getTestGraph();
    vector<Vertex> v1 = BFS_Traversal(g[2], Vertex(to_string(0)));
    REQUIRE ( v1[0].getId() == to_string(0) );
    REQUIRE ( v1[1].getId() == to_string(2) );
    REQUIRE ( v1[2].getId() == to_string(3) );
    REQUIRE ( v1[3].getId() == to_string(1) );
    REQUIRE ( v1[4].getId() == to_string(4) );
    REQUIRE ( v1[5].getId() == to_string(6) );
    REQUIRE ( v1[6].getId() == to_string(5) );
    REQUIRE ( v1[7].getId() == to_string(7) );
}



