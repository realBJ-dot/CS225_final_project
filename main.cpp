#include "edge.h"
#include "graph.h"
#include <fstream>

using std::ifstream;

int main() {
  std::cout << "test main file" << std::endl;
  /**
   * load airport data. use i as a counter to keep track of different part of 
   * airport information
   */
  ifstream wordsFile("data/airports.dat");
  string word;
  if (wordsFile.is_open()) {
      /* Reads a line from `wordsFile` into `word` until the file ends. */
      while (getline(wordsFile, word)) {
          std::string part;
          std::istringstream ss(word);
          int counter = 0;
          string id;
          double latitude;
          double longitude;
          /** split single line on ','.
           * process information of a single airport 
           */
          while(std::getline(ss, part, ',')) {
             if (counter == 0) {
               // std::cout << "id: " << part << std::endl;
               id = part;
             } else if (counter == 6) {
               // std::cout << "latitude: " << part << std::endl;
               latitude = std::stod(part);
             } else if (counter == 7) {
               // std::cout << "longitude: " << part << std::endl;
               longitude = std::stod(part);
             }
             counter++;
          }
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
      std::cout << "running visualization" << std::endl;
      end = true;
    } else {
      std::cout << "invalid choice, please try again" << std::endl;
    }
  }
  return 0;
}
