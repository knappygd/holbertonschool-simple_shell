# shell

This is a command line interpreter for Unix-like systems, which provides a user interface for using commands and interacting with the operating system. It was built according to guidelines provided and requirements necessary to comply with the Holberton School curricula.

## Usage

### How to compile it
Clone the repository and and compile the `.c` files:
```
gcc *.c -o shell
```
then, you can run it as follows:
```
./shell
```

### Executing commands
The shell accepts commands with arguments, including built-in commands, such as:
```
 - cd
 - env
 - exit
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
LANGUAGE=en_US:enPWD=/root/dev/holbertonschool-simple_shell
TZ=America/Los_Angeles
VSCODE_GIT_ASKPASS_NODE=/root/.vscode-server/bin/704ed70d4fd1c6bd6342c436f1ede30d1cff4710/node
HOME=/root
LANG=en_US.UTF-8
LC_ALL=C.UTF-8
PATH=/root/.vscode-server/bin/704ed70d4fd1c6bd6342c436f1ede30d1cff4710/bin/remote-cli:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin
TERM_PROGRAM=vscode
_=./shell
...
```
- **exit**

Exits the shell from whenever its running. If no exit code is passed as an argument, it will exit with 0. Else, if a positive integer is used, it will exit with that one.
```
~# ./shell
$ exit 98
~# echo $?
98
```

## Authors
Emilio Damasco <emiliodamasco@gmail.com>

Mishel Tomas <tomasmishel18@gmail.com>