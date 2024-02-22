#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <locale> // for std::locale, std::wcout, std::wcin
#include <sstream> // for std::wistringstream
#include <codecvt> // for std::codecvt_utf8

std::vector<std::wstring> loadDictionary(const std::string& filename) {
    std::vector<std::wstring> dictionary;
    std::wifstream file(filename);
    file.imbue(std::locale(file.getloc(), new std::codecvt_utf8<wchar_t>));
    std::wstring word;
    while (std::getline(file, word)) {
        dictionary.push_back(word);
    }
    return dictionary;
}

bool isValidWord(const std::wstring& word, const std::vector<std::wstring>& dictionary) {
    return std::binary_search(dictionary.begin(), dictionary.end(), word);
}

void generateCombinations(const std::wstring& letters, std::wstring prefix, size_t wordLength, const std::vector<std::wstring>& dictionary, std::set<std::wstring>& result) {
    if (prefix.size() == wordLength && isValidWord(prefix, dictionary)) {
        result.insert(prefix);
        return;
    }

    if (prefix.size() >= wordLength) {
        return;
    }

    for (wchar_t letter : letters) {
        std::wstring newPrefix = prefix + letter;
        std::wstring newLetters = letters;
        newLetters.erase(std::find(newLetters.begin(), newLetters.end(), letter));
        generateCombinations(newLetters, newPrefix, wordLength, dictionary, result);
    }
}

int main() {
    // Set UTF-8 encoding for input and output streams
    std::locale::global(std::locale("en_US.UTF-8"));
    std::wcout.imbue(std::locale());

    // Load dictionary
    std::vector<std::wstring> dictionary = loadDictionary("dictionary.txt");
    std::sort(dictionary.begin(), dictionary.end()); // Dictionary should be sorted for binary search

    // Input letters from user
    std::wstring input;
    std::wcout << L"Enter letters: ";
    std::getline(std::wcin, input);
    std::vector<wchar_t> letters;
    for (wchar_t letter : input) {
        if (letter != L'.')
            letters.push_back(letter);
    }

    // Input word length from user
    size_t wordLength;
    std::wstring wordLengthStr;
    std::wcout << L"Enter word length: ";
    std::getline(std::wcin, wordLengthStr);

    // Convert input string to integer
    std::wistringstream iss(wordLengthStr);
    if (!(iss >> wordLength)) {
        std::wcerr << L"Invalid input for word length!" << std::endl;
        return 1; // Return error code
    }

    // Generate combinations and filter based on dictionary and word length
    std::set<std::wstring> combinations;
    generateCombinations(input, L"", wordLength, dictionary, combinations);

    // Print filtered combinations
    for (const std::wstring& combination : combinations) {
        std::wcout << combination << std::endl;
    }

    return 0;
}
