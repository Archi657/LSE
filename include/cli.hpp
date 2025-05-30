#ifndef CLI_HPP
#define CLI_HPP

#include <string>

// Struct to hold all CLI options
struct CLIOptions {
    std::string path = ".";       // Default to current directory
    bool showHidden = false;
    bool longFormat = false;
    bool showHelp = false;
};

// Function to parse command-line arguments
CLIOptions parseArguments(int argc, char** argv);

#endif // CLI_HPP
