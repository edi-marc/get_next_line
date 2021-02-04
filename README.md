# get_next_line

Project for 42_Roma

The aim of this project is to make you code a function that returns a line ending with a newline, read from a file descriptor.

See the subjects for further information

[SUBJECTS](Resources/en.subject.pdf)

## Getting Started

The [script](Resources/fun_with_fd.sh) shows how to use the fd on bash

The repository contains a main, usefull to test the function:

### How to use the main

It is necessary to define the BUFFER_SIZE macro in the compilation process ( -D BUFFER_SIZE= )

It's possible to pass a file text to the program like this:

```
./a.out hello.txt
```

you can also execute a simple test that reads from stdin and writes on stdout

```
./a.out C
```

Or read directly from the stdin:

```
./a.out 0
```

Or create a pipeline with other tools:

```
echo "Hello\n...This is hidden" | ./a.out 0
```
