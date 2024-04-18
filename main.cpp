#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>
#include <cctype>


double averageSentenceLength(const std::string& text) {
    std::istringstream iss(text);
    std::string sentence;
    int numSentences = 0;
    int totalSentenceLength = 0;
    while (std::getline(iss, sentence, '.')) {
        totalSentenceLength += sentence.length();
        numSentences++;
    }
    if (numSentences == 0) {
        return 0;
    }
    return static_cast<double>(totalSentenceLength) / numSentences;
}
double averageWordLength(const std::string& text) {
    std::istringstream iss(text);
    std::string word;
    int numWOrds = 0;
    int totalWordLength = 0;
    while (iss >> word) {
        word.erase(std::remove_if(word.begin(), word.end(), ispunct), word.end());
        totalWordLength += word.length();
        numWOrds++;
    }
    if (numWOrds == 0) {
        return 0;
    }
    return static_cast<double>(totalWordLength) / numWOrds;
}


// Function to count the occurrence of each letter in the text
std::map<char, int> count_Letters(const std::string& text) {
    std::map<char, int> letterCount;
    for (char c : text) {
        if (std::isalpha(c)) {
            letterCount[std::tolower(c)]++;
        }
    }
    return letterCount;
}
std::string findMostFrequentLetters(const std::string& text, int numLetters) {
    std::map<char, int> letterCount = count_Letters(text);

    std::string mostFrequentLetters;
    int maxCount = 0;
    for (const auto& pair : letterCount){
        if (pair.second > maxCount) {
            maxCount = pair.second;
            mostFrequentLetters = pair.first;
        } else if (pair.second == maxCount) {
            mostFrequentLetters += pair.first;
        }
    }
    return mostFrequentLetters;
}

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
size_t countBytes(const std::string& text) {
    return text.size();
}
std::pair<int, int> countVowelsAndConsonants(const std::string& text) {
    int numVowels = 0;
    int numConsonants = 0;
    for (char c : text) {
        if (std::isalpha(c)) {
            c = std::tolower(c);
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                numVowels++;
            } else {
                numConsonants++;
            }
        }
    }
    return std::make_pair(numVowels, numConsonants);
}


int main() {
    std::cout << "Please enter a text:\n";
    std::string text;
    std::getline(std::cin, text);

    analyzeText(text);

    std::string mostFrequentLettes = findMostFrequentLetters(text, 5);
    std::cout << "Most frequent letter(s):" << mostFrequentLettes << std::endl;

    size_t numBytes = countBytes(text);
    std::cout << "Number of bytes in the text:" << numBytes << std::endl;
    auto vowelsAndConsonants = countVowelsAndConsonants(text);

    std::cout << "Number of vowels in the text:" << vowelsAndConsonants.first << std::endl;
    std::cout << "Number of consonants in the text:" << vowelsAndConsonants.second << std::endl;

    double avgSentenceLen = averageSentenceLength(text);
    double avgWordLen = averageWordLength(text);

    std::cout << "Average sentence length:" << avgSentenceLen << "characters per sentence." << std::endl;
    std::cout << "Average word length:" << avgWordLen << "characters per word:" << std::endl;


    return 0;
}
