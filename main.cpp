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
  int i = 0;
  ifstream wordsFile("data/airports.dat");
  string word;
  if (wordsFile.is_open()) {
      /* Reads a line from `wordsFile` into `word` until the file ends. */
      while (getline(wordsFile, word)) {
          if (i > 2) {
            break;
          }
          std::string part;
          std::istringstream ss(word);
          int counter = 0;
          /* split single line on ','. */
          while(std::getline(ss, part, ',')) {
             if (counter == 0) {
               std::cout << "id: " << part << std::endl;
             } else if (counter == 6) {
               std::cout << "latitude: " << part << std::endl;
             } else if (counter == 7) {
               std::cout << "longitude: " << part << std::endl;
             }
             counter++;
          }
          i++;
      }
  }
    return 0;
}
