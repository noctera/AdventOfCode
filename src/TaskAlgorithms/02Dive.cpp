#include <fstream>
#include <iostream>
#include <string>
#include <vector>

namespace Dive {

inline std::vector<std::pair<std::string, int>> loadFile (const char* path) {
    std::ifstream file (path);

    std::vector<std::pair<std::string, int>> parsedOutput;

    if (file.is_open ()) {
        std::string tempStr;
        int tempNum;

        while (file >> tempStr >> tempNum) {
            parsedOutput.push_back ({ tempStr, tempNum });
        }
    }
    else {
        std::cout << "Error opening Dive file" << std::endl;
    }
    return parsedOutput;
}

inline int partOne (std::vector<std::pair<std::string, int>> input) {

    int xPosition = 0;
    int depth = 0;

    for (auto it = input.begin (); it != input.end (); ++it) {
        if (it->first == "forward") {
            xPosition += it->second;
        }
        else if (it->first == "down") {
            depth -= it->second;
        }
        else if (it->first == "up") {
            depth += it->second;
        }
        else {
            std::cout << "there was some unknown commands" << std::endl;
        }
    }
    // make y position absolute, as there should be no negative depth
    return xPosition * abs (depth);
}

inline int partTwo (std::vector<std::pair<std::string, int>> input) {

    int xPosition = 0;
    int depth = 0;
    int aim = 0;

    for (auto it = input.begin (); it != input.end (); ++it) {
        if (it->first == "down") {
            aim += it->second;
        }
        else if (it->first == "up") {
            aim -= it->second;
        }
        else if (it->first == "forward") {
            xPosition += it->second;
            depth += it->second * aim;
        }
        else {
            std::cout << "there was some unknown commands" << std::endl;
        }
    }
    // make y position absolute, as there should be no negative depth
    return xPosition * abs (depth);
}
} // namespace Dive