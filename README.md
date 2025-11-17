# 42_Pipex

Simple implementation of piping and redirections for the 42 school project "pipex". This project reproduces the elementary behavior of shell pipelines using low-level system calls (fork, pipe, dup2, execve, etc.).

## Features
- Execute chained commands with a pipe between them
- Redirect input from a file and output to a file
- Support for here_doc usage (if implemented)

## Build
```sh
make
```

This will produce the executable `pipex` (or the project's configured binary name).

## Usage
Basic usage:
```sh
./pipex infile "cmd1" "cmd2" outfile
```
Example:
```sh
./pipex input.txt "grep hello" "wc -l" output.txt
```

Here-document usage (if implemented):
```sh
./pipex here_doc LIMITER "cmd1" "cmd2" outfile
```
Example:
```sh
./pipex here_doc EOF "cat" "wc -l" outfile
```

Notes:
- Commands should be provided as quoted strings if they contain spaces or arguments.
- Paths and PATH resolution depend on execve and your environment.

## Testing
There is no automated test suite included here. To test:
- Create small input files and run the examples above.
- Compare results with an equivalent shell pipeline: `cat infile | cmd1 | cmd2 > outfile`

## Author
andrelencart
