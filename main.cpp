#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>
#include <cctype>

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

// Function to count the occurrence of each letter in the text
std::map<char, int> countLetters(const std::string& text) {
    std::map<char, int> letterCount;
    for (char c : text) {
        if (std::isalpha(c)) {
            letterCount[std::tolower(c)]++;
        }
    }
    return letterCount;
}

// Function to analyze the text
void analyzeText(const std::string& text) {
    // Count the number of sentences
    int numSentences = std::count(text.begin(), text.end(), '.');

    // Count the number of words
    std::istringstream iss(text);
    std::string word;
    int numWords = 0;
    while (iss >> word) {
        numWords++;
    }

    // Count the occurrence of each word
    std::map<std::string, int> wordCount;
    std::istringstream wordStream(text);
    while (wordStream >> word) {
        word.erase(std::remove_if(word.begin(), word.end(), ispunct), word.end());
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);
        wordCount[word]++;
    }

    // Find the most common words
    std::vector<std::pair<std::string, int>> mostCommonWords(wordCount.begin(), wordCount.end());
    std::sort(mostCommonWords.begin(), mostCommonWords.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
    });
    std::vector<std::pair<std::string, int>> top5Words(mostCommonWords.begin(), mostCommonWords.begin() + std::min<int>(5, mostCommonWords.size()));

    // Calculate the average word length
    double totalWordLength = 0;
    for (const auto& pair : wordCount) {
        totalWordLength += pair.first.length();
    }
    double averageWordLength = totalWordLength / numWords;

    // Output analysis results
    std::cout << "Analysis Results:\n";
    std::cout << "Number of sentences: " << numSentences << "\n";
    std::cout << "Number of words: " << numWords << "\n";
    std::cout << "Most common words:\n";
    for (const auto& pair : top5Words) {
        std::cout << pair.first << " (occurs " << pair.second << " times)\n";
    }
    std::cout << "Average word length: " << averageWordLength << "\n";
}

int main() {
    std::cout << "Please enter a text:\n";
    std::string text;
    std::getline(std::cin, text);

    analyzeText(text);

    return 0;
}
