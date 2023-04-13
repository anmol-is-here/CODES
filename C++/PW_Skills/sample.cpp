#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    std::string letters;
    std::cin >> letters;

    // Count the number of occurrences of each letter
    std::map<char, int> count;
    for (char c : letters) {
        ++count[c];
    }

    // Find the maximum number of occurrences
    int max_count = 0;
    for (const auto &pair : count) {
        max_count = std::max(max_count, pair.second);
    }

    // Print the number of people and letters in the group with the most people
    std::cout << max_count << " ";
    for (const auto &pair : count) {
        if (pair.second == max_count) {
            std::cout << pair.first << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}
