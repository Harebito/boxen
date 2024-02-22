#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

std::vector<std::string> loadDictionary(const std::string& filename) {
    std::vector<std::string> dictionary;
    std::ifstream file(filename);
    std::string word;
    while (file >> word) {
        dictionary.push_back(word);
    }
    return dictionary;
}

bool isValidWord(const std::string& word, const std::vector<std::string>& dictionary) {
    return std::binary_search(dictionary.begin(), dictionary.end(), word);
}

void generateCombinations(const std::string& letters, std::string prefix, size_t wordLength, const std::vector<std::string>& dictionary, std::set<std::string>& result) {
    if (prefix.size() == wordLength && isValidWord(prefix, dictionary)) {
        result.insert(prefix);
        return;
    }

    if (prefix.size() >= wordLength) {
        return;
    }

    for (char letter : letters) {
        std::string newPrefix = prefix + letter;
        std::string newLetters = letters;
        newLetters.erase(std::find(newLetters.begin(), newLetters.end(), letter));
        generateCombinations(newLetters, newPrefix, wordLength, dictionary, result);
    }
}

int main() {
    // Load dictionary
    std::vector<std::string> dictionary = loadDictionary("dictionary.txt");
    std::sort(dictionary.begin(), dictionary.end()); // Dictionary should be sorted for binary search

    // Input letters and their counts from user
    std::string input;
    std::cout << "Enter letters (type '.' when done): ";
    std::getline(std::cin, input);
    std::vector<char> letters;
    for (char letter : input) {
        if (letter != '.')
            letters.push_back(letter);
    }

    // Input word length from user
    size_t wordLength;
    std::cout << "Enter word length: ";
    std::cin >> wordLength;

    // Generate combinations and filter based on dictionary and word length
    std::set<std::string> combinations;
    generateCombinations(input, "", wordLength, dictionary, combinations);

    // Print filtered combinations
    for (const std::string& combination : combinations) {
        std::cout << combination << std::endl;
    }

    return 0;
}
