# shell

This is a command line interpreter for Unix-like systems, which provides a user interface for using commands and interacting with the operating system.

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