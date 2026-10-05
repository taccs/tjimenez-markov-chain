#include "markov.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    
    srand(time(0));

    std::string filename;
    int order;
    int numWords;

    std::cout << "Enter input filename: ";
    std::cin >> filename;

    std::cout << "Enter order (1, 2, or 3): ";
    std::cin >> order;

    std::cout << "Enter maximum number of words to generate: ";
    std::cin >> numWords;

    const int MAX_WORDS = 5000;

    std::string words[MAX_WORDS];
    std::string prefixes[MAX_WORDS];
    std::string suffixes[MAX_WORDS];

    int count = readWordsFromFile(filename, words, MAX_WORDS);

    int chainSize = buildMarkovChain(
        words,
        count,
        order,
        prefixes,
        suffixes,
        MAX_WORDS
    );

    std::string output =
    generateText(prefixes, suffixes, chainSize, order, numWords);

    std::cout << output << std::endl;

    return 0;
}