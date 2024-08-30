#include "flow_log_parser.h"
#include <fstream>
#include <sstream>
#include <string>

std::string getProtocolName(int protocolNum) {
    switch (protocolNum) {
        case 6: return "tcp";
        case 17: return "udp";
        case 1: return "icmp";
        default: return "unknown";
    }
}

std::vector<FlowLogEntry> parseFlowLogFile(const std::string &filename) {
    std::vector<FlowLogEntry> flowLogs;
    std::ifstream infile(filename);
    std::string line;

    while (std::getline(infile, line)) {
        std::stringstream ss(line);
        std::string version, accountId, eni, srcAddr, dstAddr, dstPortStr, srcPort, protocolNumStr, pktLen, pktCount, startTime, endTime, action, logStatus;

        ss >> version >> accountId >> eni >> srcAddr >> dstAddr >> dstPortStr >> srcPort >> protocolNumStr >> pktLen >> pktCount >> startTime >> endTime >> action >> logStatus;

        FlowLogEntry entry;
        entry.dstPort = std::stoi(dstPortStr);
        entry.protocol = getProtocolName(std::stoi(protocolNumStr));

        flowLogs.push_back(entry);
    }

    return flowLogs;
}

