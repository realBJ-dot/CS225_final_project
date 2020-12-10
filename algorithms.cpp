#include "algorithms.h"

using std::vector;
using cs225::PNG;
using std::ifstream;

/**
 * function that build graph based on airport data and route data
 * @param airport_data: filename of airport data
 * @param route_data: filename of route data
 * @param g: empty graph to built on
 */
void Algorithms::build_graph(string airport_data, string route_data, Graph& g) {
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
void Algorithms::BFS_Traversal(Graph& g_, Vertex start_vertex, vector<Vertex>& toReturn, 
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
vector<Vertex> Algorithms::BFS(Graph& g_) {
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
 * helper function for DFS traversal
 * @param g_: graph to traverse
 * @param start_vertex: starting vertex of traversal
 * @param toReturn: vector that represents orders of nodes visited
 * @param visited_: a map that keeps track of whether a node is visited
 */
void Algorithms::DFS_Traversal(Graph& g_, Vertex start_vertex, vector<Vertex>& toReturn, 
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
vector<Vertex> Algorithms::DFS(Graph& g_) {
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

/**
 * graphic output of graph
 * function that project graph on to world map 
 * vertices of graph are airports and edges are routes
 * result is saved as a PNG named "world_map_with_airports.png"
 * @param g_ : graph to visualize
 */
void Algorithms::visualization(Graph& g_) {
    PNG p;
    // use world-map.png as background
    p.readFromFile("world-map.png");
    // calculate position of 0 degree latitude and longitude
    float lat0 = p.height() / 2;
    float lng0 = p.width() / 2;
    // calculate num of pixels for one degree
    float lat_degree = p.height()/180;
    float lng_degree = p.width()/360;
    
    // get all the vertices of the graph. i.e. all the airports
    vector<Vertex> vertices = g_.getVertices();
    for (auto& v : vertices) {
        float lat = v.getLatitude();
        float lng = v.getLongitude();
        float lat_p = (0-lat)*lat_degree + lat0;
        float lng_p = lng*lng_degree + lng0;
        // check point is in bound
        
        
        if ((unsigned) lng_p  < p.width() && (unsigned) lat_p < p.height()) {
            cs225::HSLAPixel & pixel = p.getPixel((int) lng_p, (int) lat_p);
            pixel.h = 0;
            pixel.a = 1;
            pixel.l = .5;
            pixel.s = .5;
        }
        if ((unsigned) lng_p + 1  < p.width() && (unsigned) lat_p < p.height()) {
            cs225::HSLAPixel & pixel = p.getPixel((int) lng_p + 1, (int) lat_p);
            pixel.h = 0;
            pixel.a = 1;
            pixel.l = .5;
            pixel.s = .5;
        }
        if ((unsigned) lng_p  < p.width() && (unsigned) lat_p - 1 < p.height()) {
            cs225::HSLAPixel & pixel = p.getPixel((int) lng_p, (int) lat_p - 1);
            pixel.h = 0;
            pixel.a = 1;
            pixel.l = .5;
            pixel.s = .5;
        }
        if ((unsigned) lng_p + 1  < p.width() && (unsigned) lat_p - 1 < p.height()) {
            cs225::HSLAPixel & pixel = p.getPixel((int) lng_p + 1, (int) lat_p - 1);
            pixel.h = 0;
            pixel.a = 1;
            pixel.l = .5;
            pixel.s = .5;
        }
        if ((unsigned) lng_p + 2 < p.width() && (unsigned) lat_p < p.height()) {
            cs225::HSLAPixel & pixel = p.getPixel((int) lng_p + 2, (int) lat_p);
            pixel.h = 0;
            pixel.a = 1;
            pixel.l = .5;
            pixel.s = .5;
        }
        if ((unsigned) lng_p + 2 < p.width() && (unsigned) lat_p - 1 < p.height()) {
            cs225::HSLAPixel & pixel = p.getPixel((int) lng_p + 2, (int) lat_p - 1);
            pixel.h = 0;
            pixel.a = 1;
            pixel.l = .5;
            pixel.s = .5;
        }
        if ((unsigned) lng_p + 2  < p.width() && (unsigned) lat_p - 2 < p.height()) {
            cs225::HSLAPixel & pixel = p.getPixel((int) lng_p + 2, (int) lat_p - 2);
            pixel.h = 0;
            pixel.a = 1;
            pixel.l = .5;
            pixel.s = .5;
        }
        if ((unsigned) lng_p + 1  < p.width() && (unsigned) lat_p - 2 < p.height()) {
            cs225::HSLAPixel & pixel = p.getPixel((int) lng_p + 1, (int) lat_p - 2);
            pixel.h = 0;
            pixel.a = 1;
            pixel.l = .5;
            pixel.s = .5;
        }
        if ((unsigned) lng_p  < p.width() && (unsigned) lat_p - 2 < p.height()) {
            cs225::HSLAPixel & pixel = p.getPixel((int) lng_p, (int) lat_p - 2);
            pixel.h = 0;
            pixel.a = 1;
            pixel.l = .5;
            pixel.s = .5;
        }
    }

    for (auto& e : g_.getEdges()) {
        // Edge e = g_.getEdge(Vertex("3484"), Vertex("3877"));
        float source_lat = e.source.getLatitude();
        float source_lng = e.source.getLongitude();

        float source_lat_p = (0-source_lat)*lat_degree + lat0;
        float source_lng_p = source_lng*lng_degree + lng0;

        float dest_lat = e.dest.getLatitude();
        float dest_lng = e.dest.getLongitude();

        float dest_lat_p = (0-dest_lat)*lat_degree + lat0;
        float dest_lng_p = dest_lng*lng_degree + lng0;

        int lat_change = abs((int) dest_lat_p - (int) source_lat_p);
        int lng_change = abs((int) dest_lng_p - (int) source_lng_p);

        if (lng_change > lat_change) {

            int start_lat = source_lat_p;
            int start_lng = source_lng_p;
            int end_lat = dest_lat_p;
            int end_lng = dest_lng_p;

            if (source_lng_p > dest_lng_p) {
                start_lat = dest_lat_p;
                start_lng = dest_lng_p;
                end_lng = source_lng_p;
                end_lat = source_lat_p;
            }

            int A = 2*lat_change;
            int B = A - 2*lng_change;
            int P = A - lng_change;

            

            int j = start_lat;
            
            for (int i = start_lng+1; i <= end_lng; i++) {
                if (P < 0) {
                    cs225::HSLAPixel & pixel = p.getPixel(i, j);
                    pixel.h = 0;
                    pixel.a = 1;
                    pixel.l = 1;
                    pixel.s = .5;
                    P+=A;
                } else {
                    if (end_lat < start_lat) {
                        j--;
                    } else {
                        j++;
                    }
                    cs225::HSLAPixel & pixel = p.getPixel(i, j);
                    pixel.h = 0;
                    pixel.a = 1;
                    pixel.l = 1;
                    pixel.s = .5;
                    P+=B;
                    
                }
            }
        } else {

            int start_lat = source_lat_p;
            int start_lng = source_lng_p;
            int end_lat = dest_lat_p;
            int end_lng = dest_lng_p;

            if (source_lat_p > dest_lat_p) {
                start_lat = dest_lat_p;
                start_lng = dest_lng_p;
                end_lng = source_lng_p;
                end_lat = source_lat_p;
            }

            int A = 2 * lng_change;
            int B = A - 2 * lat_change;
            int P = A - lat_change;

            int j = start_lng;

            for (int i = start_lat + 1; i <= end_lat; i++) {
                if (P < 0) {
                    cs225::HSLAPixel & pixel = p.getPixel(j, i);
                    pixel.h = 0;
                    pixel.a = 1;
                    pixel.l = 1;
                    pixel.s = .5;
                    P+=A;
                } else {
                    if (end_lng < start_lng) {
                        j--;
                    } else {
                        j++;
                    }
                    cs225::HSLAPixel & pixel = p.getPixel(j, i);
                    pixel.h = 0;
                    pixel.a = 1;
                    pixel.l = 1;
                    pixel.s = .5;
                    P+=B;
                    
                }
            }
        }
    }
        
            
        
    

    p.writeToFile("world_map_with_airports.png");
}


 /**
 *Floyd_Warshall algorithm.
*/

void Algorithms::FloydWarshall(Graph& g_) {
    float inf = 99999999;
    size_t vertices_size = g_.getVertices().size();
    D = vector<vector<float>>(vertices_size, vector<float>(vertices_size, inf));
    P = vector<vector<string>>(vertices_size, vector<string>(vertices_size, "-1"));
    
    for (size_t i = 0; i < vertices_size; i++) {
        D[i][i] = 0;
        P[i][i] = g_.getVertices()[i].getId();
    }
    for (size_t i = 0; i < vertices_size; i++) {
        M[g_.getVertices()[i].getId()] = i;
        for (size_t j = 0; j < vertices_size; j++) {
            if (g_.edgeExists(g_.getVertices()[i], g_.getVertices()[j])) {
                D[i][j] = g_.getEdgeWeight(g_.getVertices()[i], g_.getVertices()[j]);
                P[i][j] = g_.getVertices()[j].getId();
            } else {
                continue;
            }
        }
    }
   
    for (size_t w = 0; w < vertices_size; w++) {
        for (size_t u = 0; u < vertices_size; u++) {
            for (size_t v = 0; v < vertices_size; v++) {
                if (D[u][v] > D[u][w] + D[w][v]) {
                    D[u][v] = D[u][w] + D[w][v];
                    P[u][v] = P[u][w];
                }
            }
        }
    }
}

/**
 * to result a list of vertices of the shortest path.
 */
vector<string> Algorithms::construct_path(string source, string dest) {
    vector<string> shortest;
    string curr = source;
    
    while (curr != dest) {
        shortest.push_back(curr);
        curr = P[M[curr]][M[dest]];
    }
    return shortest;
}