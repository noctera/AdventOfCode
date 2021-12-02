#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "./TaskAlgorithms/01SonarSweep.cpp"
#include "./TaskAlgorithms/02Dive.cpp"

int main () {

    std::cout << "Sonar Sweep" << std::endl;
    auto sonarSweepData = SonarSweep::loadFile ("/home/julian/AdventOfCode/Numbers/01.txt");
    std::cout << "Part 1: " << SonarSweep::partOne (sonarSweepData) << std::endl;
    std::cout << "Part 2: " << SonarSweep::partTwo (sonarSweepData) << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
    std::cout << "Dive!" << std::endl;
    auto diveData = Dive::loadFile ("/home/julian/AdventOfCode/Numbers/02.txt");
    std::cout << "Part 1: " << Dive::partOne (diveData) << std::endl;
    std::cout << "Part 2: " << Dive::partTwo (diveData) << std::endl;
}