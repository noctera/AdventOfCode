#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main () {
    std::ifstream file ("/home/julian/HelloWorld/src/numbers.txt");

    std::vector<int> parsedNumbers;

    if (file.is_open ()) {
        std::string tempNum;
        while (std::getline (file, tempNum)) {
            parsedNumbers.push_back (std::stoi (tempNum));
        }
    }

    int increasedNumbersOne = 0;
    int increasedNumbersTwo = 0;

    // increased numbers part two
    for (int i = 0; i < parsedNumbers.size (); ++i) {
        if (i == 0 || i == parsedNumbers.size ()) {
            continue;
        }
        if (parsedNumbers[i] > parsedNumbers[i - 1]) {
            ++increasedNumbersOne;
        }
    }

    // increased numbers part two
    for (int i = 0; i < parsedNumbers.size (); ++i) {
        if (i == 0 || i >= parsedNumbers.size () - 1) {
            continue;
        }
        if ((parsedNumbers[i] + parsedNumbers[i + 1] + parsedNumbers[i + 2]) > (parsedNumbers[i - 1] + parsedNumbers[i] + parsedNumbers[i + 1])) {
            ++increasedNumbersTwo;
        }
    }

    std::cout << "Part 1: " << increasedNumbersOne << std::endl;
    std::cout << "Part 2: " << increasedNumbersTwo << std::endl;
}