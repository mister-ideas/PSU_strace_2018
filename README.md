# Subject
strace traces a prgram in real time and displays all of the system calls it executes in their order of appearance. Develop an alternative to strace that implementing the following options:
* -s : display the detailled arguments (see below). 

By default, your strace must only display the arguments and return values in hexadecimal form. If the system call has a void return value, display a question mark. With -s option, your program must be as close as possible to the strace command on your system, and therefore display the following:

* integers in decimal form,
* pointers on a character string in the form of a character string,
* detailed structures (value for each field).

# Forbidden
* Use of PTRACE_SYSCALL

# Building
$ make

# Usage
$ ./strace (-s) [file_path]

# Mark
**15,72/20**
