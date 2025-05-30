#ifndef COLORS_H
#define COLORS_H

// Regular Colors without resetting styles (no "0;")
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

// Bold modifier (can be combined with above colors)
#define BOLD    "\033[1m"

// Reset all styles
#define RESET   "\033[0m"

// Bold Colors (bold + color)
#define BBLACK   "\033[1;30m"
#define BRED     "\033[1;31m"
#define BGREEN   "\033[1;32m"
#define BYELLOW  "\033[1;33m"
#define BBLUE    "\033[1;34m"
#define BMAGENTA "\033[1;35m"
#define BCYAN    "\033[1;36m"
#define BWHITE   "\033[1;37m"

// Bright Colors (not bold, but brighter)
#define BRIGHT_BLACK   "\x1b[90m"
#define BRIGHT_RED     "\x1b[91m"
#define BRIGHT_GREEN   "\x1b[92m"
#define BRIGHT_YELLOW  "\x1b[93m"
#define BRIGHT_BLUE    "\x1b[94m"
#define BRIGHT_MAGENTA "\x1b[95m"
#define BRIGHT_CYAN    "\x1b[96m"
#define BRIGHT_WHITE   "\x1b[97m"

#endif // COLORS_H
