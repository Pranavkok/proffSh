#include "redirector.h"
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;


int handle_redirects(vector<char*>& args_c) {
    for (size_t i = 0; args_c[i] != nullptr; ) {
        const char* mode = nullptr;
        FILE* stream = nullptr;

        if (strcmp(args_c[i], ">") == 0) {
            mode = "w";
            stream = stdout;
        } else if (strcmp(args_c[i], ">>") == 0) {
            mode = "a";
            stream = stdout;
        } else if (strcmp(args_c[i], "<") == 0) {
            mode = "r";
            stream = stdin;
        }

        if (mode == nullptr) {
            i++;
            continue;
        }

        if (args_c[i + 1] == nullptr) return -1;
        if (freopen(args_c[i + 1], mode, stream) == NULL) return -1;
        args_c.erase(args_c.begin() + i, args_c.begin() + i + 2);
    }
    return 0;
}