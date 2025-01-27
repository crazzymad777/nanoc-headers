#ifndef NANOC_MODULE_UNISTD_H
#define NANOC_MODULE_UNISTD_H
#include <nanoc/defs.h>
// This header file for module nanoc.std.unistd autogenerated by NanoC metadata.
int fork();
int unlink(char* pathname);
long lseek(int fd, long offset, int whence);
int execve(char* pathname, char** argv, char** envp);
int getpid();
#endif
