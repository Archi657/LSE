#ifndef EMOJI_COLOR_MAP_HPP
#define EMOJI_COLOR_MAP_HPP

#include "colors.h"
#include "emojis.h"

#include <string>
#include <unordered_map>

const std::unordered_map<std::string, std::string> fileColors = {
    {".c",     std::string(BLUE)    + std::string(C)     + " "},
    {".cpp",   std::string(BLUE)    + std::string(C)     + " "},
    {".py",    std::string(GREEN)   + std::string(PY)    + " "},
    {".txt",   std::string(YELLOW)  + std::string(TEXT)  + " "},
    {".mp3",   std::string(CYAN)    + std::string(AUDIO) + " "},
    {".wav",   std::string(CYAN)    + std::string(AUDIO) + " "},
    {".md",    std::string(MAGENTA) + std::string(TEXT)  + " "},
    {".json",  std::string(YELLOW)  + std::string(TEXT)  + " "},
    {".html",  std::string(BRIGHT_RED) + std::string(TEXT) + " "},
    {".js",    std::string(BRIGHT_YELLOW) + std::string(TEXT) + " "}
    // Add more mappings as needed
};

#endif // EMOJI_COLOR_MAP_HPP
