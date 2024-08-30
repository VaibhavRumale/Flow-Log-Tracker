#include "output_generator.h"
#include "lookup_table.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <filesystem>

void generateOutputFiles(const std::vector<FlowLogEntry> &flowLogs, const std::unordered_map<std::string, std::string> &lookupTable, const std::string &outputDir) {
    std::unordered_map<std::string, int> tagCount;
    std::unordered_map<std::string, int> portProtocolCount;

    for (const auto &entry : flowLogs) {
        std::string key = toLower(std::to_string(entry.dstPort) + "," + entry.protocol);
        std::string tag = lookupTable.count(key) ? lookupTable.at(key) : "Untagged";

        // Print untagged combinations
        if (tag == "Untagged") {
            std::cout << "Untagged combination: " << key << std::endl;
        }

        tagCount[tag]++;
        portProtocolCount[key]++;
    }

    // Write Tag Counts output
    std::ofstream tagCountFile(outputDir + "/tag_counts.csv");
    tagCountFile << "Tag,Count\n";
    for (const auto &pair : tagCount) {
        tagCountFile << pair.first << "," << pair.second << "\n";
    }

    // Write Port/Protocol Combination Counts output
    std::ofstream portProtocolCountFile(outputDir + "/port_protocol_counts.csv");
    portProtocolCountFile << "Port,Protocol,Count\n";
    for (const auto &pair : portProtocolCount) {
        std::stringstream ss(pair.first);
        std::string port, protocol;
        std::getline(ss, port, ',');
        std::getline(ss, protocol, ',');
        portProtocolCountFile << port << "," << protocol << "," << pair.second << "\n";
    }
}
