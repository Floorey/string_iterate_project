#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>

// Function to split a sentence into words
std::vector<std::string> splitSentence(const std::string& sentence) {
    std::vector<std::string> words;
    std::istringstream iss(sentence);
    std::string word;
    while (iss >> word) {
        words.push_back(word);
    }
    return words;
}
std::map<char, int> countLetters(const std::string& text) {
    std::map<char, int> letterCount;
    for (char c: text) {
        if (std::isalpha(c)) {
            letterCount[std::tolower(c)]++;
        }
    }
    return letterCount;
}

int main() {
    std::cout << "Please enter a text:\n";
    std::string text;
    std::getline(std::cin, text);

    // Split text into individual sentences
    std::istringstream textStream(text);
    std::string sentence;
    while (std::getline(textStream, sentence)) {
        // Split sentence into words and output
        std::vector<std::string> words = splitSentence(sentence);
        std::cout << "Words in the sentence:\n";
        for (const std::string& word : words) {
            std::cout << word << "\n";
        }
    }
    std::map<char, int> letterCount = countLetters(text);

    int maxCount = 0;
    std::vector<char> mostFrequentLetter;
    for (const auto& pair : letterCount) {
        if (pair.second > maxCount) {
            maxCount = pair.second;
            mostFrequentLetter.clear();
            mostFrequentLetter.push_back(pair.first);
        }
    }
    std::cout << "Most frequent letter: \n";
    for (char c: mostFrequentLetter) {
        std::cout << c << "\n";
    }
    std::cout << "Most frequent letter count: " << maxCount << "\n";

    return 0;
}
