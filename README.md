# UCLA_209_CTF_Problems

This project includes two types of problems: buffer overflow and symbolic execution.
In Buffer Overflow part. I referenced some ideas from [Smashing The Stack For Fun And Profit](http://phrack.org/issues/49/14.html#article) to build these 2 problems.
And in the symbolic execution part, I referenced some ideas from [angr_ctf](https://github.com/jakespringer/angr_ctf) to build these 2 problems.

But the example solution was totally make by myself.

I tested buffer overflow problems and my solution for it on Ubuntu 14.04 (32-bits).
And I tested the symbolic execution part and my solution for it on Ubuntu 20.04 (64-bits)

### More details please read Tutorial for UCLA_209_CTF_Problems.pdf

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

**about angr:**
For the example solution of symbloc execuation, you need to install angr to run it.

Install instructions can be found at [angr e-book](https://docs.angr.io/introductory-errata/install)

When you have finished all the above steps, you are ready to start to crack the problems.

## Buffer Overflow

### How to set up
Under buffer_overflow folder, there is a `init.sh` shell scrip. You can simply run it to initialize those 3 buffer overflow problems.

It will ask you to input a username which is used to generate a random seed.

Also, it will ask you to give a permission of sudo, and it is used to execute chmod and chown.

After the script finished, you can see the source code problem0.c problem1.c problem2.c under the buffer overflow folder. And the executable files of these problems can be found in problems folder. Also, you can find my solutions source code and executable files in it (the solution for problem0’s input is ”aaaaaaaaaaaaaaaaaaaaeaaa” which is 20 ’a’s and ’eaaa’). 

A suggestion about building executable files from C is using gcc -m32 -O0 flags to make it easy to be tracked in gdb or other debuggers.

And for you reference, I put a useful hex shellcode string in shellcode.h. If you want to use it, you can just include it in your c file.


### Success conditions
For problem0, if you succeed perform the buffer overflow attack, you will get the flag from problem0’s output in this format: flag{xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx}. 

And for problem1 and problem2, if you succeed perform the attack you will be changed to root user. There is a ’#’ symbol in front of your command line or you can check it by typing ’whoami’ and it should display root. Normally, in real ctf challenge, you need to get the root permission to find some file can only read by root

### Example solutions
For problem0, you need to run problem0 by moving to /buffer overlfow/problems and run ./problem0. When it ask you to input something, you can input ”aaaaaaaaaaaaaaaaaaaaeaaa” which is 20 ’a’s and ’eaaa’. Then you should get the flag. And for problem1 and problem2, you can just simply run ./solution1 and ./solution2 to see the result.

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

