# shell

This is a command line interpreter for Unix-like systems, which provides a user interface for using commands and interacting with the operating system. It was built according to guidelines provided and requirements necessary to comply with the Holberton School curricula.

## Usage

### How to compile it
Clone the repository and compile the `.c` files:
```
gcc *.c -o shell
```
then, you can run it as follows:
```
./shell
```

### Input modes
The shell can work both interactively and non-interactively. This means that it accepts input reading from the prompt or through another non-terminal file descriptor.

**Interactive**
```
$ pwd
/home/user
```
**Non-Interactive**
```
echo "pwd" | ./shell
/home/user
```
A command can be passed either using its executable name or its own path. In other words, an executable path is a valid command:
```
$ ls
file.txt img.png my_dir
$ /bin/ls
file.txt img.png my_dir
```
### Built-in commands
Apart from executing any executable file (such as `ls`), it also handles built-in commands, which are coded into the shell. These are:

- **cd**

If the targeted directory exists, it will change the current working directory *(cwd)* to the new one.
```
$ pwd
/home/user
$ ls
file.txt my_dir
$ cd my_dir
$ pwd
/home/user/my_dir
```

- **env**

Prints the environment variables, along with its values.
```
$ env
SHELL=/bin/bash
TERM_PROGRAM_VERSION=1.77.3
HOSTNAME=10a9634f2d2e
...
```
- **exit**

Exits the shell from whenever it is running, with the exit code 0.
```
~# ./shell
$ exit 98
~# echo $?
98
```

## How it works
The shell works by tokenizing the input, which means dividing it into strings separated by spaces, thus isolating the command and any arguments. Then, it checks if the command used is an executable or a built-in. If it is an executable, it locates the command by searching the PATH environment variable and then passes the required arguments to the `execve` function. Otherwise, if it is a built-in, it checks which one it is by searching through an index, and executes the required function. 

## Authors
Emilio Damasco <emiliodamasco@gmail.com>

Mishel Tomas <tomasmishel18@gmail.com>