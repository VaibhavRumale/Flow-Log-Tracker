#include "lookup_table.h"
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

// Converts a string to lowercase for case-insensitive comparisons
std::string toLower(const std::string &str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

// Loads the lookup table from a CSV file
std::unordered_map<std::string, std::string> loadLookupTable(const std::string &filename) {
    std::unordered_map<std::string, std::string> lookupTable;
    std::ifstream infile(filename);
    std::string line;
    
    while (std::getline(infile, line)) {
        std::stringstream ss(line);
        std::string dstPort, protocol, tag;

        std::getline(ss, dstPort, ',');
        std::getline(ss, protocol, ',');
        std::getline(ss, tag, ',');

        std::string key = toLower(dstPort + "," + protocol);
        lookupTable[key] = tag;
    }

    return lookupTable;
}

