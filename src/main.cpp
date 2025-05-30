
#include "../include/cli.hpp"
#include "../include/list.hpp"
#include <iostream>

int main(int argc, char** argv) {
    CLIOptions options = parseArguments(argc, argv);
    if (options.showHelp) {
    std::cout << "Usage: fls [options] [path]\n"
              << "Options:\n"
              << "  -a        Show hidden files\n"
              << "  -l        Long listing format\n"
              << "  -la/-al   Combine -l and -a\n"
              << "  -h        Show this help message\n";
    return 0;
   }

    listFiles(options);
    return 0;
}