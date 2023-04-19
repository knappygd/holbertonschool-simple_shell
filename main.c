#include "shell.h"

int main()
{
	_strlen("test");
	_strcat("first", "second");
	_strncmp("hello world", "hello there", 5);
	_strncmp("hello world", "hello there", 6);
	_getenv("PATH");
	_strcpy("hello", "world");
	_strdup("duplicate");
}
