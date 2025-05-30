#include "../include/list.hpp"
#include "../include/colors.h"
#include "../include/emojis.h"
#include "../include/file_emoji_color.h"

#include <iostream>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <filesystem>

#include <format>
#include <chrono>
int listFiles(const CLIOptions& options) {
    std::string resolvedPath;

    // Convert relative path to absolute
    if (options.path == ".") {
        char cwd[PATH_MAX];
        if (getcwd(cwd, sizeof(cwd)) != nullptr) {
            resolvedPath = cwd;
        } else {
            std::cerr << BOLD << "Error getting current directory\n" << RESET;
            return -1;
        }
    } else {
        resolvedPath = options.path;
    }

    DIR* dir = opendir(resolvedPath.c_str());
    if (!dir) {
        std::cerr << RED << "Error: Cannot open directory " << resolvedPath << "\n" << RESET;
        return -1;
    }

    std::cout << BOLD << "Listing: " << std::filesystem::canonical(resolvedPath) << "\n" << RESET;

    struct dirent* entry;
    std::string spacer = options.longFormat ? "\n" : " ";

    while ((entry = readdir(dir)) != nullptr) {
        std::string fileName = entry->d_name;

        // Skip hidden files if not shown
        if (!options.showHidden && fileName[0] == '.') continue;

        std::string fullPath = resolvedPath + "/" + fileName;
        struct stat fileStat;
        std::string display = DOC + fileName;
            std::string color = WHITE;

        // Use lstat to get file information
        if (lstat(fullPath.c_str(), &fileStat) != 0) {
            std::cerr << RED << "Error: Cannot stat file " << fileName << "\n" << RESET;
            continue;
        }

        // Special case: hidden folders "." and ".."
        if (S_ISDIR(fileStat.st_mode) && (fileName == "." || fileName == "..")) {
           //std::cout << BOLD << MAGENTA << HIDDEN << fileName << spacer << RESET;
           display = MAGENTA HIDDEN + fileName + RESET;
        }else if (S_ISDIR(fileStat.st_mode)) {
           //std::cout << BOLD << MAGENTA << FOLDER << fileName << spacer << RESET;
           display = MAGENTA FOLDER + fileName + RESET; 
        }else{
            std::string extension;
            size_t dotPos = fileName.find_last_of('.');
            if (dotPos != std::string::npos && dotPos != 0) {
                extension = fileName.substr(dotPos);
            }

            

            // Apply emoji + color if extension matches
            if (fileColors.find(extension) != fileColors.end()) {
                display = fileColors.at(extension) + fileName;
            }
        }
        // Detect file extension
        
        if (options.longFormat) {
            
            /* Print permissions normal way
            std::cout << BOLD << WHITE
                << (S_ISDIR(fileStat.st_mode) ? "d" : "-")
                << ((fileStat.st_mode & S_IRUSR) ? "r" : "-")
                << ((fileStat.st_mode & S_IWUSR) ? "w" : "-")
                << ((fileStat.st_mode & S_IXUSR) ? "x" : "-")
                << ((fileStat.st_mode & S_IRGRP) ? "r" : "-")
                << ((fileStat.st_mode & S_IWGRP) ? "w" : "-")
                << ((fileStat.st_mode & S_IXGRP) ? "x" : "-")
                << ((fileStat.st_mode & S_IROTH) ? "r" : "-")
                << ((fileStat.st_mode & S_IWOTH) ? "w" : "-")
                << ((fileStat.st_mode & S_IXOTH) ? "x" : "-");
            */// emoji version
            std::cout << BOLD << WHITE
                << (S_ISDIR(fileStat.st_mode) ? FOLDER : DOC)
                << USER << BOLD << "->"
                << ((fileStat.st_mode & S_IRUSR) ? READ : DENIED)
                << ((fileStat.st_mode & S_IWUSR) ? WRITE : DENIED)
                << ((fileStat.st_mode & S_IXUSR) ? EXECUTE : DENIED)
                << " " << GROUP << BOLD << "->"
                << ((fileStat.st_mode & S_IRGRP) ? READ : DENIED)
                << ((fileStat.st_mode & S_IWGRP) ? WRITE : DENIED)
                << ((fileStat.st_mode & S_IXGRP) ? EXECUTE : DENIED)
                << " " << EVERYONE << BOLD << "->"
                << ((fileStat.st_mode & S_IROTH) ? READ : DENIED)
                << ((fileStat.st_mode & S_IWOTH) ? WRITE: DENIED)
                << ((fileStat.st_mode & S_IXOTH) ? EXECUTE : DENIED) << RESET;
            std::filesystem::file_time_type ftime = std::filesystem::last_write_time(fullPath);
            std::cout << CALENDAR << " " << BOLD << std::format("{:%Y/%m/%d}",ftime) << RESET;
            std::cout << TIME << BOLD << std::format("{:%H:%M}",ftime) << RESET;
            std::cout << " "  << BOLD << display << RESET; 
            std::cout << "\n";
        } else {
            std::cout << BOLD << display << spacer << RESET;
        }
    }

    std::cout << "\n";
    closedir(dir);
    return 0;
}