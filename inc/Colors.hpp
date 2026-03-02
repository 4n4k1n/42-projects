#pragma once

#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

// Bright (high-intensity) foreground
#define BRIGHT_BLACK   "\033[90m"
#define BRIGHT_RED     "\033[91m"
#define BRIGHT_GREEN   "\033[92m"
#define BRIGHT_YELLOW  "\033[93m"
#define BRIGHT_BLUE    "\033[94m"
#define BRIGHT_MAGENTA "\033[95m"
#define BRIGHT_CYAN    "\033[96m"
#define BRIGHT_WHITE   "\033[97m"

// Backgrounds
#define BG_BLACK   "\033[40m"
#define BG_RED     "\033[41m"
#define BG_GREEN   "\033[42m"
#define BG_YELLOW  "\033[43m"
#define BG_BLUE    "\033[44m"
#define BG_MAGENTA "\033[45m"
#define BG_CYAN    "\033[46m"
#define BG_WHITE   "\033[47m"

// Bright backgrounds
#define BG_BRIGHT_BLACK   "\033[100m"
#define BG_BRIGHT_RED     "\033[101m"
#define BG_BRIGHT_GREEN   "\033[102m"
#define BG_BRIGHT_YELLOW  "\033[103m"
#define BG_BRIGHT_BLUE    "\033[104m"
#define BG_BRIGHT_MAGENTA "\033[105m"
#define BG_BRIGHT_CYAN    "\033[106m"
#define BG_BRIGHT_WHITE   "\033[107m"

// Styles
#define BOLD       "\033[1m"
#define DIM        "\033[2m"
#define UNDERLINE  "\033[4m"
#define REVERSED   "\033[7m"
#define RESET      "\033[0m"

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>

// #include <iostream>
// #include <vector>
// #include <utility>
// #include "../inc/Colors.hpp"

// int main()
// {
//     using std::cout;
//     using std::endl;

//     // Foreground colors
//     std::vector<std::pair<const char*, const char*>> colors = {
//         {"BLACK", BLACK}, {"RED", RED}, {"GREEN", GREEN}, {"YELLOW", YELLOW},
//         {"BLUE", BLUE}, {"MAGENTA", MAGENTA}, {"CYAN", CYAN}, {"WHITE", WHITE}
//     };

//     // Bright foregrounds
//     std::vector<std::pair<const char*, const char*>> bright_colors = {
//         {"BRIGHT_BLACK", BRIGHT_BLACK}, {"BRIGHT_RED", BRIGHT_RED},
//         {"BRIGHT_GREEN", BRIGHT_GREEN}, {"BRIGHT_YELLOW", BRIGHT_YELLOW},
//         {"BRIGHT_BLUE", BRIGHT_BLUE}, {"BRIGHT_MAGENTA", BRIGHT_MAGENTA},
//         {"BRIGHT_CYAN", BRIGHT_CYAN}, {"BRIGHT_WHITE", BRIGHT_WHITE}
//     };

//     // Backgrounds
//     std::vector<std::pair<const char*, const char*>> backgrounds = {
//         {"BG_BLACK", BG_BLACK}, {"BG_RED", BG_RED}, {"BG_GREEN", BG_GREEN},
//         {"BG_YELLOW", BG_YELLOW}, {"BG_BLUE", BG_BLUE}, {"BG_MAGENTA", BG_MAGENTA},
//         {"BG_CYAN", BG_CYAN}, {"BG_WHITE", BG_WHITE}
//     };

//     // Bright backgrounds
//     std::vector<std::pair<const char*, const char*>> bright_backgrounds = {
//         {"BG_BRIGHT_BLACK", BG_BRIGHT_BLACK}, {"BG_BRIGHT_RED", BG_BRIGHT_RED},
//         {"BG_BRIGHT_GREEN", BG_BRIGHT_GREEN}, {"BG_BRIGHT_YELLOW", BG_BRIGHT_YELLOW},
//         {"BG_BRIGHT_BLUE", BG_BRIGHT_BLUE}, {"BG_BRIGHT_MAGENTA", BG_BRIGHT_MAGENTA},
//         {"BG_BRIGHT_CYAN", BG_BRIGHT_CYAN}, {"BG_BRIGHT_WHITE", BG_BRIGHT_WHITE}
//     };

//     // Styles
//     std::vector<std::pair<const char*, const char*>> styles = {
//         {"BOLD", BOLD}, {"DIM", DIM}, {"UNDERLINE", UNDERLINE}, {"REVERSED", REVERSED}
//     };

//     cout << "Foreground colors:\n";
//     for (auto &p : colors) {
//         cout << p.second << p.first << RESET << "  ";
//     }
//     cout << "\n\n";

//     cout << "Bright foreground colors:\n";
//     for (auto &p : bright_colors) {
//         cout << p.second << p.first << RESET << "  ";
//     }
//     cout << "\n\n";

//     cout << "Background colors (with white foreground):\n";
//     for (auto &p : backgrounds) {
//         cout << WHITE << p.second << " " << p.first << " " << RESET << "  ";
//     }
//     cout << "\n\n";

//     cout << "Bright background colors (with black foreground):\n";
//     for (auto &p : bright_backgrounds) {
//         cout << BLACK << p.second << " " << p.first << " " << RESET << "  ";
//     }
//     cout << "\n\n";

//     cout << "Styles (combined with a sample color):\n";
//     for (auto &p : styles) {
//         cout << p.second << RED << p.first << RESET << "  ";
//     }
//     cout << "\n\n";

//     // Combined examples
//     cout << "Some combined examples:\n";
//     cout << BOLD << BRIGHT_GREEN << "BOLD BRIGHT_GREEN" << RESET << "  ";
//     cout << UNDERLINE << BLUE << "UNDERLINE BLUE" << RESET << "  ";
//     cout << REVERSED << BRIGHT_MAGENTA << "REVERSED BRIGHT_MAGENTA" << RESET << "  ";
//     cout << "\n";

//     return 0;
// }