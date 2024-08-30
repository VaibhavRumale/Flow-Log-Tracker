#ifndef FLOW_LOG_PARSER_H
#define FLOW_LOG_PARSER_H

#include <string>
#include <vector>

struct FlowLogEntry {
    int dstPort;
    std::string protocol;
};

std::vector<FlowLogEntry> parseFlowLogFile(const std::string &filename);

#endif

