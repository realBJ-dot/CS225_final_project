#include "edge.h"
#include "graph.h"
#include "algorithms.h"
#include <filesystem>


int main() {
  std::cout << "test main file" << std::endl;
  // initialize an empty graph
  Graph g_ = Graph(true, true);

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
      build_graph("data/airports.dat", "data/routes.dat", g_);
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
          build_graph(airport_data, route_data, g_);
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
    std::cout << "Shortest path between two points (enter shortest_path)" << std::endl;
    std::cout << "Project onto map based on Openflight dataset (enter visualization)" << std::endl;
    std::cin >> choice;
    if (choice == "DFS") {
      // will be replaced later, place holder for now
      std::cout << "running DFS" << std::endl;
      end = true;
    } else if (choice == "BFS") {
      // will be replaced later, place holder for now
      std::cout << "running BFS" << std::endl;
      end = true;
    } else if (choice == "shortest_path") {
      // will be replaced later, place holder for now
      std::cout << "running shortest path" << std::endl;
      end = true;
    } else if (choice == "visualization") {
      // will be replaced later, place holder for now
      visualization(g_);
      std::cout << "output projection onto world map based on data to \"world_map_with_airports.png\"." << std::endl;
      end = true;
    } else {
      std::cout << "invalid choice, please try again" << std::endl;
    }
  }
  return 0;
}
