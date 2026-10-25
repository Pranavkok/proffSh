# proffSh

A small Unix shell written in C++ to learn how shells work under the hood.

## Features

- Runs any program on your `PATH`, with arguments (`ls -l`, `echo hello world`)
- Output redirection with `>` (`ls -l > files.txt`)
- Script mode: run commands from a file (`./main myscript`)
- `exit` command, and Ctrl + D to quit
- Skips empty lines, prints an error for invalid commands

## Build

Requires a C++17 compiler (clang++ or g++) on macOS or Linux.

```bash
clang++ -std=c++17 main.cpp parser.cpp executor.cpp redirector.cpp -o main
```

## Usage

Interactive mode:

```bash
./main
$ ls -l
$ date > today.txt
$ cat today.txt
$ exit
```

Script mode (no prompt, runs each line, then exits):

```bash
./main myscript
```

## How it works

For each line you type, the shell:

1. reads the line and splits it into words
2. forks a child process
3. in the child, handles `>` redirection and replaces itself with the program using `execvp`
4. in the parent, waits for the child to finish, then shows the prompt again

## Project structure

| File | Job |
|---|---|
| `main.cpp` | the read loop, script mode, and the `exit` command |
| `parser.h` / `parser.cpp` | splits a line into words |
| `executor.h` / `executor.cpp` | fork, exec and wait |
| `redirector.h` / `redirector.cpp` | handles `>` output redirection |

## Limitations

Work in progress. Not supported yet:

- `cd` and other built-in commands
- pipes (`ls | wc -l`)
- `>>` (append) and `<` (input redirection)
- quoted arguments (`echo "hello world"` is split into two words)
- spaces are required around `>` (`echo hi > file` works, `echo hi >file` doesn't)
- Ctrl + C stops the whole shell, not just the running command
