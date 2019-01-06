#include "G:/My Drive/data/coding/JHelperProject/tasks/AGennadyAndACardGame.cpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cctype>
#include <ctime>

namespace jhelper {

struct Test {
    std::string input;
    std::string output;
    bool active;
    bool has_output;
};

bool check(std::string expected, std::string actual) {
    while(!expected.empty() && isspace(*--expected.end()))
        expected.erase(--expected.end());
    while(!actual.empty() && isspace(*--actual.end()))
        actual.erase(--actual.end());
    return expected == actual;
}

} // namespace jhelper

int main() {
    std::vector<jhelper::Test> tests = {
        {"AS\n2H 4C TH JH AD\n", "YES", true, true},{"2H\n3D 4C AC KD AS\n", "NO\n", true, true},{"4D\nAS AC AD AH 5H\n", "YES", true, true},{"3D\n8S 4S 2C AS 6H", "NO", true, true},{"7H\nTC 4C KC AD 9S", "", true, false},
    };
    bool allOK = true;
    int testID = 0;
    std::cout << std::fixed;
    double maxTime = 0.0;
    for(const jhelper::Test& test: tests ) {
        std::cout << "Test #" << ++testID << std::endl;
        std::cout << test.input << std::endl;
        if (test.has_output) {
            std::cout << "Expected output: " << test.output << std::endl;
        }
        else {
            std::cout << "Expected output: " << "N/A" << std::endl;
        }
        if (test.active) {
            std::stringstream in(test.input);
            std::ostringstream out;
            std::clock_t start = std::clock();
            AGennadyAndACardGame solver;
            solver.solve(in, out);
            std::clock_t finish = std::clock();
            double currentTime = double(finish - start) / CLOCKS_PER_SEC;
            maxTime = std::max(currentTime, maxTime);
            std::cout << "Actual   output: " << out.str() << std::endl;
            if (test.has_output) {
                bool result = jhelper::check(test.output, out.str());
                allOK = allOK && result;
                std::cout << "Result: " << (result ? "Correct answer" : "Wrong answer") << std::endl;
            } else {
                std::cout << "OK, but is it right?" << std::endl;
            }
        }
        else {
            std::cout << "SKIPPED\n";
        }
        std::cout << "----------------------------------------------\n";
    }
    if(allOK) {
        std::cout << "\nYou're a stud (at least on the example cases)!" << std::endl;
    }
    else {
        std::cout << "Some of the test cases failed." << std::endl;
    }
    return 0;
}
