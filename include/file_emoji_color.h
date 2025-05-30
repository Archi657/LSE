#ifndef EMOJI_COLOR_MAP_HPP
#define EMOJI_COLOR_MAP_HPP

#include "colors.h"
#include "emojis.h"

#include <string>
#include <unordered_map>

// Map file extensions to **bold color + emoji** (consistent, no resetting)
const std::unordered_map<std::string, std::string> fileColors = {
    {".c",     std::string(BBLUE)    + C       + " "},
    {".cpp",   std::string(BBLUE)    + C       + " "},
    {".py",    std::string(BGREEN)   + PY      + " "},
    {".txt",   std::string(BYELLOW)  + TEXT    + " "},
    {".md",    std::string(BMAGENTA) + TEXT    + " "},
    {".json",  std::string(BYELLOW)  + TEXT    + " "},
    {".html",  std::string(BRED)     + HTML    + " "},
    {".htm",   std::string(BRED)     + HTML    + " "},
    {".js",    std::string(BYELLOW)  + JS      + " "},
    {".doc",   std::string(BBLUE)    + DOC     + " "},
    {".docx",  std::string(BBLUE)    + DOC     + " "},
    {".pdf",   std::string(BYELLOW)  + TEXT     + " "},
    {".jpg",   std::string(BYELLOW)  + IMAGE   + " "},
    {".jpeg",  std::string(BYELLOW)  + IMAGE   + " "},
    {".png",   std::string(BYELLOW)  + IMAGE   + " "},
    {".gif",   std::string(BYELLOW)  + IMAGE   + " "},
    {".mp3",   std::string(BCYAN)    + AUDIO   + " "},
    {".wav",   std::string(BCYAN)    + AUDIO   + " "},
    {".mp4",   std::string(BRIGHT_CYAN) + VIDEO + " "},
    {".mov",   std::string(BRIGHT_CYAN) + VIDEO + " "},
    {".avi",   std::string(BRIGHT_CYAN) + VIDEO + " "},
    {".zip",   std::string(BMAGENTA) + ZIP     + " "},
    {".tar",   std::string(BMAGENTA) + ZIP     + " "},
    {".gz",    std::string(BMAGENTA) + ZIP     + " "},
    {".7z",    std::string(BMAGENTA) + ZIP     + " "},
    {".exe",   std::string(BGREEN)   + EXE     + " "},
    {".sh",    std::string(BGREEN)   + EXE     + " "}
};

#endif // EMOJI_COLOR_MAP_HPP
