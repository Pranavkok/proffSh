#include "executor.h"
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include "redirector.h"
using namespace std;

void run_command(const vector<string>& args) {
    vector<char*> args_c;
    for (const string& s : args) {
        args_c.push_back(const_cast<char*>(s.c_str()));
    }
    args_c.push_back(nullptr);

    pid_t pid = fork();

    if (pid > 0) {
        wait(NULL);
    }
    else {
        if (handle_redirects(args_c) == -1 || args_c[0] == nullptr) {
            cerr << "Invalid redirect" << endl;
            _exit(1);
        }
        execvp(args_c[0], args_c.data());
        cerr << "Invalid command: " << args[0] << endl;
        _exit(1);
    }
}