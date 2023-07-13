# Get_next_line
## Description
The get_next_line function reads a line from a file descriptor (fd) and returns that line as a dynamically allocated string. It allows reading a text file one line at a time by making repeated calls to the get_next_line function.
## Prototype
```C
int  get_next_line(int fd, char **line)
```
## Return Value
The functions returns the line that was read from the file descriptor. If there is nothing else to read, it returns 0. On error, it return -1.
## Compilation
To compile the code, add the option -D BUFFER_SIZE=n to define the buffer size for read(). The value of BUFFER_SIZE can be modified to test different buffer sizes. Here is an example compilation command with a buffer size of 42:
```shell
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c
```
