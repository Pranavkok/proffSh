#include "parser.h"
#include <sstream>
using namespace std;

vector<string> split_line(const string& line) {
    vector<string> words;
    istringstream ss(line);
    string word;
    while (ss >> word) {
        if (word[0] == '#') break;
        words.push_back(word);
    }
    return words;
}