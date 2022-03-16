# UCLA_209_CTF_Problems

This project includes two types of problems: buffer overflow and symbolic execution.
In Buffer Overflow part. I referenced some ideas from [Smashing The Stack For Fun And Profit](http://phrack.org/issues/49/14.html#article) to build these 2 problems.
And in the symbolic execution part, I referenced some ideas from [angr_ctf](https://github.com/jakespringer/angr_ctf) to build these 2 problems.

But the example solution was totally make by myself.

I tested buffer overflow problems and my solution for it on Ubuntu 14.04 (32bits).
And I tested the symbolic execution part and my solution for it on Ubunto20.04 (64bits)

## Before Start

If you are running a 64bit Linux, to support 32-bit programs and 32-bit compiles, you need to do the following set-up.

    sudo apt-get install build-essential module-assistant 
    sudo apt-get install gcc-multilib g++-multilib

    sudo dpkg --add-architecture i386
    sudo apt-get update

***This is really important:***
Moden Linux has ASLR (Address Space Layout Randomization). To do a buffer overflow attack, you need to close it.

It can be closed by: 

    sudo sh -c "echo 0 > /proc/sys/kernel/randomize_va_space"
    
**Notice:** After each time you restart the system, it will automatically be set to active, so you need to turn it off after each restart.

**angr**
For the example solution of symbloc execuation, you need to install angr to run it.

Install instructions can be found at [angr e-book](https://docs.angr.io/introductory-errata/install)

When you have finished all the above steps, you are ready to start to crack the problems.

## Buffer Overflow

### How to set up
Under buffer_overflow folder, there is a `init.sh` shell scrip. You can simply run it to initialize those 2 buffer overflow problems.

It will ask you to input a username which is used to generate a random seed.

Also, it will ask you to give a permission of sudo, and it is used to execute chmod and chown.

After the script finished, you can see the source code `problem1.c` `problem2.c` under the buffer_overflow folder. 
And the executable files of these problems can be found in problems folder. Also, you can find my solutions source code and executable files in it.
A suggestion about building executable files from C is using `gcc -m32 -O0` flags to make it easy to be trackt in gdb or other debuggers.

### Success conditions

If you succeed performed an attack, you will see you have got root  permission. (a '#' in front of the command line, or you can use whoami to see you become root!)

### Example solutions

You can just simply run `./solution1` and `solution2` to see the result.


## Symbolic Execution

### How to set up
Same as buffer overflow, you can find a `init.sh` shell script under symbolic_execuation folder.

Run it and you will get the source code `problem1.c` and `problem2.c` in symbolic_execuation folder.
And the executable targets and my solution will be under problems folder.

Even though I call them symbolic execution problems, but it may be cracked by other ways. Feel free to use other way to crack it.

### Success conditions
When you move to problems folder, you can run the target files by `./problem1` and `./problem2`. Then they will ask you to input a password.
If the password you entered is correct, then you will get a flag in this format: flag{xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx}.

If the password you entered is wrong, then the program will display "Try again"

### Example solutions

You can run the solution.py with a target file as an argument to do symbolic execuation.

For example:
`python ./solution.py problem1`

