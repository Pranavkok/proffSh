#include "redirector.h"
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;


int handle_redirects(vector<char*>& args_c) {
    for (size_t i = 0; args_c[i] != nullptr; i++) {
        if (strcmp(args_c[i], ">") == 0) {
            if (args_c[i + 1] == nullptr) return -1;
            if (freopen(args_c[i + 1], "w", stdout) == NULL) return -1;
            args_c.erase(args_c.begin() + i, args_c.begin() + i + 2);
            return 1;
        }
    }
    return 0;
}