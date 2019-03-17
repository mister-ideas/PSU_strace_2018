/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** print
*/

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <sys/ptrace.h>
#include <sys/reg.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <sys/user.h>
#include <syscall.h>
#include <stdio.h>
#include <string.h>
#include "my_syscall.h"

void syscall_display(pid_t child, unsigned sysnum,
                                unsigned retval) {
    printf("%s(", syscall_table[(int)sysnum].name);
    printf(") = ");
    if (retval)
        printf("0x%x\n", retval);
    else
        printf("0x0\n");
}