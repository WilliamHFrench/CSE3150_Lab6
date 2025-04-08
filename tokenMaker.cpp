#include "tokenMaker.h"
#include <functional>

using namespace std;


int token_from_string(const string& word) {
    hash<string> hasher;
    return static_cast<int>(hasher(word));
}