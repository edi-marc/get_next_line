# get_next_line

Project for 42_Roma

The aim of this project is to make you code a function that returns a line ending with a newline, read from a file descriptor.

See the subjects for further information

[SUBJECTS](Resources/en.subject.pdf)

## Getting Started

- The [script](Resources/fun_with_fd.sh) shows how to use the fd on bash

- This simple [program](Resources/main_test_o_max.c) shows the value of OPEN_MAX

- The [Makefile](Makefile) is optional, it's possible to use this for build the program with a given BUFFER_SIZE:

compile the program with BUFFER_SIZE=42:

```
make bf=42
```

compile the program with the bonus files with BUFFER_SIZE=42:

```
make bonus bf=42
```

- The *.txt files are for testing purpose.

- The repository contains a main, usefull to test the function:

### How to use the main

It is necessary to define the BUFFER_SIZE macro in the compilation process ( -D BUFFER_SIZE= )

It's possible to pass a text file to the program like this:

```
./gnl file.txt
```

Or like this, reading a text file line by line until an error or EOF:

```
./gnl file.txt E
```

you can also execute a simple test that reads from stdin and writes on stdout

```
./gnl C
```

Or read directly from the stdin:

```
./gnl 0
```

Or create a pipeline with other tools:

```
echo "Hello\n...This is hidden" | ./gnl 0
```

It's also possible to pass 3 or more text files to the program like this:

```
./gnl_b file.txt eof.txt canto_V.txt
```
In this case the program reads a line of each file following the order in wich the arguments
are passed, then it does the same thing but in reverse order and again in the first order.

You can also trigger the undefined behavior mentioned in the subject:

```
./gnl_b canto_V.txt file.txt S
```
Read a line on the first file than close the corresponding fd and open the second file on the same fd of the first and read a line

The main treats each argument passed with a different fd, therefore each reading made on a fd does not affect the others.
