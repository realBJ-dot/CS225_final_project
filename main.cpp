#include "edge.h"
#include "graph.h"
#include "algorithms.h"
#include <filesystem>


int main() {
  std::cout << "test main file" << std::endl;
  // initialize an empty graph
  Graph g_ = Graph(true, true);
  // map that map id of airport to its full name
  std::map<string, string> id2name;
  // map that map airports to its id
  std::map<string, string> name2id;
  Algorithms a_;

  /**
   * collect user input to decied which dataset to use
   */ 
  string dataset_choice;
  string airport_data;
  string route_data;
  bool dataset_end = false;
  while (!dataset_end) {
    std::cout << "Do you want to run algorithms on the OpenFlights dataset (OF) we used or dataset of your choice (Y)" << std::endl;
    std::cin >> dataset_choice;
    if (dataset_choice == "OF") {
      // use openflight dataset to build the graph
      a_.build_graph("data/airports.dat", "data/routes.dat", g_, id2name, name2id);
      // finish choosing dataset
      dataset_end = true;
    } else if (dataset_choice == "Y") {
      bool file_end = false;
      bool another_choice = false;
      while (!file_end) {
        std::cout << "Please enter the filename of the airport data (also include folder name if in a different folder)" << std::endl;
        std::cout << "Or enter B to choose a different dataset" << std::endl;
        std::cin >> airport_data;
        if (airport_data == "B") {
          // if choice is B, go back to choose dataset
          another_choice = true;
        } else {
          // read filename of airport data and check if file exists
          if (!std::__fs::filesystem::exists(airport_data)) {
            std::cout << "file does not exist. Please try again" << std::endl;
            continue;
          }
          // read file name of route data and check if file exists
          std::cout << "Please enter the filename of the route data (also include folder name if in a different folder)" << std::endl;
          std::cin >> route_data;
          if (!std::__fs::filesystem::exists(route_data)) {
            std::cout << "file does not exist. Please try again" << std::endl;
            continue;
          }
          // both file exists, build graph and finish reading filename
          file_end = true;
          a_.build_graph(airport_data, route_data, g_, id2name, name2id);
        }
        if (another_choice) {
          file_end = true;
        } else {
          dataset_end = true;
        }
      }
    } else {
      std::cout << "invalid choice, please try again" << std::endl;
    }
    
  }
  
  /**
   * collect user input to decided which algorithm to run
   */
  string choice;
  bool end = false;
  while (!end) {
    std::cout << "Please choose the algorithm you want to run" << std::endl;
    std::cout << "The available algorithms are: " << std::endl;
    std::cout << "DFS/BFS traversal (enter DFS for DFS and BFS for BFS)" << std::endl;
    std::cout << "Shortest path between two points using distance as weight (enter SP)" << std::endl;
    std::cout << "Project onto map based on Openflight dataset (enter V)" << std::endl;
    std::cin >> choice;
    if (choice == "DFS") {
      // output order of node visited during DFS to "DFS.txt"
      std::cout << "running DFS" << std::endl;
      vector<Vertex> dfs_result = a_.DFS(g_);
      std::ofstream fs0("DFS.txt"); 
      if(fs0) {
        for (auto& v : dfs_result) {
          // write id of the node followed by a new line character to the txt file 
          fs0 << v.getId() << ": " << id2name[v.getId()] << std::endl;
        }
      }
      fs0.close();
      std::cout << "output order of node visited during DFS to \"DFS.txt\"" << std::endl;
      end = true;
    } else if (choice == "BFS") {
      // output order of node visited during BFS to "BFS.txt"
      // std::cout << "running BFS" << std::endl;
      vector<Vertex> bfs_result = a_.BFS(g_);
      std::ofstream fs1("BFS.txt"); 
      if(fs1) {
        for (auto& v : bfs_result) {
          // write id of the node followed by a new line character to the txt file 
          fs1 << v.getId() << ": " << id2name[v.getId()] << std::endl;
        }
      }
      fs1.close();
      std::cout << "output order of node visited during BFS to \"BFS.txt\"" << std::endl;
      end = true;
    } else if (choice == "SP") {
      // will be replaced later, place holder for now
      // std::cout << "running shortest path" << std::endl;
      a_.FloydWarshall(g_);
      string source_airport;
      string destination_airport;
      bool get_airports = false;
      while (!get_airports) {
        std::cout << "Please enter the full name of the origin airport" << std::endl;
        std::cin >> source_airport;
        if (name2id.find(source_airport) == name2id.end()) {
          std::cout << "airport not found, please try again" << std::endl;
          continue;
        }
        std::cout << "Please enter the full name of the destination airport" << std::endl;
        std::cin >> destination_airport;
        if (name2id.find(destination_airport) == name2id.end()) {
          std::cout << "airport not found, please try again" << std::endl;
          continue;
        }
        vector<string> path = a_.construct_path(source_airport, destination_airport);
        if (path.size() == 1 && path[0] == "no path") {
          std::cout << "no path found" << std::endl;
        } else {
          std::cout << "The shortest path from " << source_airport << " to " << destination_airport << "is: " << std::endl; 
          for (size_t i = 0; i < path.size() - 1; i++) {
            std::cout << id2name[path[i]] << " --> ";
          }
          std::cout << id2name[path[path.size() - 1]] << std::endl;
        }
        string again;
        std::cout << "do you want to find shortest for another two aiports (Y/N)" << std::endl;
        std::cin >> again;
        if (again == "N") {
          get_airports = true;
        }
      }
      end = true;
    } else if (choice == "V") {
      // output visualization image to "world_map_with_airports.png" and "world_map_with_airports_and_routes.png"
      a_.visualization(g_);
      std::cout << "output projection onto world map based on data to \"world_map_with_airports.png\"";
      std::cout << " and \"world_map_with_airports_and_routes.png\"" << std::endl;
      end = true;
    } else {
      std::cout << "invalid choice, please try again" << std::endl;
    }
  }
  return 0;
}
