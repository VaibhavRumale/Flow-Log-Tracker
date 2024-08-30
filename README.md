# Flow-Log-Tagger

## Overview
Flow-Log-Tagger is a C++ program designed to process AWS VPC flow logs, mapping each log entry to a specific tag based on a provided lookup table. The program generates two output files: one listing the count of each tag, and another listing the count of each port/protocol combination.

## Features
- **Flow Log Parsing**: Parses flow log entries from a text file.
- **Tag Mapping**: Maps each log entry to a tag based on `dstport` and `protocol`.
- **Case Insensitivity**: Handles protocol matching in a case-insensitive manner.
- **Output Generation**: Produces two CSV files containing tag counts and port/protocol combination counts.
- **Flexible Output**: Allows specifying an output directory for the generated files.

## Assumptions
- **Log Format**: The program supports only the default AWS VPC flow log format (version 2) as specified in the problem statement. Custom formats or versions other than 2 are not supported.
- **Case Insensitivity**: Matching between the `dstport` and `protocol` from the flow logs and the lookup table is case-insensitive.
- **File Size**: The program assumes the flow log file size can be up to 10 MB and the lookup table can have up to 10,000 entries.
- **Output Directory**: If no output directory is specified, the program will create and use a default `./output` directory for generated files.

## Prerequisites
- C++17 compiler (e.g., GCC, Clang)
- CMake (optional, for building with CMake)

## How to Compile and Run

### Option 1: Using CMake

#### Step 1: Generate the Build Files
1. Navigate to the project directory.
2. Create a build directory:
   ```bash
   mkdir build
   cd build
   ```
3. Compile the program:
   ```
   cmake ..
   make 
   ```
 
4. Run the Program:
   ```
   ./flow_log_parser ../data/flow_log.txt ../data/lookup_table.csv
   ```

6. (Optional) Specify a custom output directory:
   ```
    ./flow_log_parser ../data/flow_log.txt ../data/lookup_table.csv ../custom_output_dir
   ```

### Option 2: Without CMake (Using g++ Directly)

1. Compile the program using g++:
   ```
   g++ -std=c++17 -Iinclude -o flow_log_parser src/main.cpp src/flow_log_parser.cpp src/lookup_table.cpp src/output_generator.cpp
   ```
 
2. Run the program by specifying the flow log file and lookup table file:
   ```
   ./flow_log_parser data/flow_log.txt data/lookup_table.csv
   ```

 This will generate the output files in the ./output directory by default. 

## Output Files
The program generates the following output files in the specified directory (default: `./output`):

- **`tag_counts.csv`**: Contains the counts of each tag.
- **`port_protocol_counts.csv`**: Contains the counts of each port/protocol combination.

