#ifndef OUTPUT_GENERATOR_H
#define OUTPUT_GENERATOR_H

#include "flow_log_parser.h"
#include <unordered_map>
#include <vector>

void generateOutputFiles(const std::vector<FlowLogEntry> &flowLogs, const std::unordered_map<std::string, std::string> &lookupTable, const std::string &outputDir);

#endif
