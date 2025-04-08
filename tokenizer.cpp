#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <regex>
#include "tokenMaker.cpp"

using namespace std;

int main() {

    ifstream file("the-verdict.txt");
    stringstream buffer;
    buffer << file.rdbuf();
    string text = buffer.str();

    regex word_regex{"\\b\\w+\\b"};
    sregex_iterator begin(text.begin(), text.end(), word_regex);
    sregex_iterator end;

    // Store words in a vector
    vector<string> words;
    for (sregex_iterator i = begin; i != end; ++i) {
        smatch match = *i;
        words.push_back(match.str());
    }   

    map<string, int> tokenPairs;
    for(auto v: words){
        tokenPairs[v] = token_from_string(v);
    }

    for (const auto & pair : tokenPairs) {
        cout << pair.first << ": " << pair.second << endl;
    }

    return 0;
}