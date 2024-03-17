# <img src="https://github.com/TeomanDeniz/TeomanDeniz/blob/main/images/repo_projects/125.png" style="width: 75PX;"> minitalk

**Description**: The purpose of this project is to code a small data exchange program using UNIX signals. It is an introductory project for the bigger UNIX projects that will appear later on in the cursus.

## Project Info:

This project teaches you how to communicate 2 processes using only IPC signaling protocols. Which means no file transferring, no pipe and no internet communications.

The functions you can use in this project:

| Function Name | In Code                                                       | Library                  |
| ------------- | ------------------------------------------------------------- | ------------------------ |
| write         | `ssize_t write(int, void *, size_t);`                         | `#include <unistd.h>`    |
| ft_printf     | `int ft_printf(char *, ...);`                                 | `#include "ft_printf.h"` |
| signal        | `void signal(int, void (*)(int));`                            | `#include <signal.h>`    |
| sigemptyset   | `int sigemptyset(sigset_t *);`                                | `#include <signal.h>`    |
| sigaddset     | `int sigaddset(sigset_t *, int);`                             | `#include <signal.h>`    |
| sigaction     | `int sigaction(int, struct sigaction *, struct sigaction *);` | `#include <signal.h>`    |
| kill          | `int kill(pid_t, int);`                                       | `#include <signal.h>`    |
| getpid        | `pid_t getpid(void);`                                         | `#include <unistd.h>`    |
| malloc        | `void *malloc(size_t);`                                       | `#include <stdlib.h>`    |
| free          | `void free(void *);`                                          | `#include <stdlib.h>`    |
| pause         | `int pause(void);`                                            | `#include <unistd.h>`    |
| sleep         | `unsigned sleep(unsigned int);`                               | `#include <unistd.h>`    |
| usleep        | `int usleep(useconds_t);`                                     | `#include <unistd.h>`    |
| exit          | `void exit(int);`                                             | `#include <stdlib.h>`    |

We have to use only SIGUSR1 and SIGUSR2 signals. And it is important to know, these signals are exist only for let programers do with this 2 whatever they want. [Source](https://www-uxsup.csx.cam.ac.uk/courses/moved.Building/signals.pdf)


| SIGUSR1 | Left for the programmers to do whatever they want. |
| ------- | -------------------------------------------------- |
| SIGUSR2 | Left for the programmers to do whatever they want. |

## Bonus:

In bonus part, **server** must send and information to **client** to make it aware that every byte **client** sended s successfully received.

Insted of usng `sigaction()` struct, I am combined **client** with **server** and **server** with **client**.

When you want to send your string to **server** from **client**; First, **client** sends 2 bytes (It's holding it's own PID address) to **server** for tell it to send your inform signals to this PID when any byte is successfully recieved.
