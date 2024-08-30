#include "flow_log_parser.h"
#include "lookup_table.h"
#include "output_generator.h"
#include <iostream>
#include <filesystem>  

int main(int argc, char *argv[]) {
    if (argc < 3 || argc > 4) {
        std::cerr << "Usage: " << argv[0] << " <flow_log_file> <lookup_table_file> [output_directory]\n";
        return 1;
    }

    std::string flowLogFile = argv[1];
    std::string lookupTableFile = argv[2];
    std::string outputDir = argc == 4 ? argv[3] : "./output";  // Default to ./output

    // Create the output directory if it doesn't exist
    if (!std::filesystem::exists(outputDir)) {
        std::filesystem::create_directories(outputDir);
    }

    auto lookupTable = loadLookupTable(lookupTableFile);
    auto flowLogs = parseFlowLogFile(flowLogFile);

    generateOutputFiles(flowLogs, lookupTable, outputDir);

    std::cout << "Processing complete. Check '" << outputDir << "' for results.\n";

    return 0;
}
