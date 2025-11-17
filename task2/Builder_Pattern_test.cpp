#include <iostream>
#include <chrono>
#include <stdexcept>
#include "Builder_Pattern.cpp"

int main() {

auto now = std::chrono::system_clock::now();
auto tomorrow = now + std::chrono::hours(24);
auto yesterday = now - std::chrono::hours(24);

try {
    auto project1 = Project::Builder("Website Redesign", tomorrow).build();
    std::cout << "PASS: Valid project created successfully\n";
} catch (const std::exception& e) {
    std::cout << "FAIL: " << e.what() << "\n";
}

try {
    auto project2 = Project::Builder("App Launch", tomorrow)
                    .withCompletionDate(tomorrow + std::chrono::hours(48))
                    .build();
    std::cout << "PASS: Valid completed project created\n";
} catch (const std::exception& e) {
    std::cout << "FAIL: " << e.what() << "\n";
}

try {
    auto project3 = Project::Builder("", tomorrow).build();
    std::cout << "FAIL: Empty project name was accepted\n";
} catch (const std::invalid_argument& e) {
    std::cout << "PASS: Empty name correctly rejected - " << e.what() << "\n";
}

try {
    auto project4 = Project::Builder("Test Project", yesterday).build();
    std::cout << "FAIL: Past start date was accepted\n";
} catch (const std::invalid_argument& e) {
    std::cout << "PASS: Past start date correctly rejected - " << e.what() << "\n";
}

try {
    auto project5 = Project::Builder("Test", tomorrow)
                    .withCompletionDate(yesterday) // Completion before start
                    .build();
    std::cout << "FAIL: Invalid completion date was accepted\n";
} catch (const std::invalid_argument& e) {
    std::cout << "PASS: Invalid completion date correctly rejected - " << e.what() << "\n";
}
}
