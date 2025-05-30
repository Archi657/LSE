#include "../include/cli.hpp"
#include <iostream>

CLIOptions parseArguments(int argc, char** argv) {
    CLIOptions options;

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];

        if (arg == "-a") {
            options.showHidden = true;
        } else if (arg == "-l") {
            options.longFormat = true;
        } else if (arg == "-la" || arg == "-al") {
            options.showHidden = true;
            options.longFormat = true;
        } else if (arg == "--help" || arg == "-h") {
            options.showHelp = true;
        } else if (arg[0] == '-') {
            std::cerr << "Unknown option: " << arg << "\n";
            options.showHelp = true;
        } else {
            options.path = arg;  // Assume it's a path
        }
    }

    return options;
}
