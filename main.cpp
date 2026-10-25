#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include "parser.h"
#include "executor.h"
using namespace std;

int main(int argc, char* argv[]) {
    bool interactive = true;

    if (argc > 1) {
        if (freopen(argv[1], "r", stdin) == NULL) {
            cerr << "Can't read from script file " << argv[1] << endl;
            cerr << "Exiting." << endl;
            return 1;
        }
        interactive = false;
    }
    
    while (true) {
        string buff;

        cout << "$ " << flush;
        if (!getline(cin, buff)) break;

        vector<string> args = split_line(buff);

        if (args.empty()) continue;

        if (args[0] == "exit") {
            _exit(0);
        }

        run_command(args);
    }
    return 0;
}