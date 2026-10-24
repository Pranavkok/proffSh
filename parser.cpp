#include "parser.h"
#include <sstream>
using namespace std;

vector<string> split_line(const string& line) {
    vector<string> words;
    istringstream ss(line);
    string word;
    while (ss >> word) {
        words.push_back(word);
    }
    return words;
}