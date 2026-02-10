# Simple C Shell

A minimal Unix shell written in C that can execute commands with arguments. This project demonstrates the basics of process creation, input parsing, and command execution in C.

## Features

- Displays a prompt: `$ `
- Reads user input using `getline()`
- Splits input into command and arguments
- Executes external programs using `fork()` and `execvp()`
- Waits for commands to complete before showing the prompt
- Handles empty input gracefully
- Ends on `EOF` (Ctrl+D)

## Requirements

- GCC (or any C compiler)
- Unix-like operating system (Linux, macOS)

## Compilation

Compile the shell using `gcc`:

```bash
gcc -o my_shell minishell.c
```
