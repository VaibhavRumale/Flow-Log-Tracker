cmake_minimum_required(VERSION 3.10)
project(FlowLogTagger)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)

# Include directories
include_directories(include)

# Add the executable
add_executable(flow_log_parser 
    src/main.cpp 
    src/flow_log_parser.cpp 
    src/lookup_table.cpp 
    src/output_generator.cpp
)

