#include <fstream>
#include <iostream>
#include <string>
#include <vector>

namespace SonarSweep {

inline std::vector<int> loadFile (const char* path) {
    std::ifstream file (path);

    std::vector<int> parsedOutput;

    if (file.is_open ()) {
        std::string tempNum;
        while (std::getline (file, tempNum)) {
            parsedOutput.push_back (std::stoi (tempNum));
        }
    }
    return parsedOutput;
}

inline const int partOne (std::vector<int> numbers) {
    int count = 0;
    for (int i = 0; i < numbers.size (); ++i) {
        if (i == 0 || i == numbers.size ()) {
            continue;
        }
        if (numbers[i] > numbers[i - 1]) {
            ++count;
        }
    }
    return count;
}

inline const int partTwo (std::vector<int> numbers) {
    int count = 0;
    for (int i = 0; i < numbers.size (); ++i) {
        if (i == 0 || i >= numbers.size () - 1) {
            continue;
        }
        if ((numbers[i] + numbers[i + 1] + numbers[i + 2]) > (numbers[i - 1] + numbers[i] + numbers[i + 1])) {
            ++count;
        }
    }
    return count;
}
} // namespace SonarSweep