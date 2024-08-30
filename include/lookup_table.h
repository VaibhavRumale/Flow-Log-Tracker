#ifndef LOOKUP_TABLE_H
#define LOOKUP_TABLE_H

#include <unordered_map>
#include <string>

std::unordered_map<std::string, std::string> loadLookupTable(const std::string &filename);
std::string toLower(const std::string &str);  

#endif

