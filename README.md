# C-Programming-in-a-Unix-Environment

In this class, I learned how to use the UNIX operating system interactively by using certain commands, express
algorithimic solutions using shell scripting, understand and use regular expressions, peforming input/output of binary files,
implement interprocess communication such as pipes, sockets, and signals, how to use version control system, and using the UNIX
programming environment. Below are the programs I have done to fully understand how to use a non-GUI interface and program in this
environment.

# Program 1

The first assignment was created to understand how to create a multi-file C++ programs in a non-GUI interface and allow us to be proficient in logging our console input/output using the script command. The first file that we had to create displays the value of each command line argument to stdout. The second file we had to create displays a log message stating that you are inside the procedure. We had to create two shell scripts to compile our code. The first shell echo's what it is doing at each step to the stdout. The second shell script will run the program. 

# Program 2

The second assignment was created to understand how to use TCLAP (Templatized Command Line Parser), a third party library, to parse by using the command line arguments. This program will open an input file, read and process the information, and then output the modified data into output.txt. Some of the modification features that this program includes is converting all text to lowercase, all text to uppercase, and changing the name of the output file.

# Program 3

The third assignment was created to understand how to use both UNIX utilities and C++ programs. This program uses gawk to calculate and output the specific columns in a table which is maintained in a file. Using the gawk information, a C++ program is created to capture the results of the gawk programs work and display the information. It was required for us to create a Makefile to compile this program.

# Program 4

The fourth assignment was created to understand how to scan a file using the flex lexical analyzer and parsing a file by using the bison parser package to generate an output. This program parses an input file that contains postal addresses and then ouputs the representation of these address in XML notation. If the program is called with "scanner", it will provide the lexical analysis of the file and will be sent to stdout. If the program is called with "parser", it will provide both the lexical analysis and parsing of the file and will be sent to both stdout and stderr.

# Program 5

The fifth assignment was created to understand how to incorporate some of the skills we learned in the prior assignments along learning how to use other third party library code such as Rude Config. This program creates a UNIX style daemon process that watch a particular folder and log the specific operations that occur on a particular file. The daemon will reach the parameters from the configuration file. The daemon will be able to respond to certain UNIX signals to control the operation. Some of these signals are SIGINT, SIGTERM, and SIGHUP. When the daemon starts, it will create a subfolder called .versions that will save  the modified files.

# Program 6

The sixth assignment was created to understand how to perform Binary File I/O. This program will read a Binary File and display the results in a CDK window. 
