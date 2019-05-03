/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** print_params
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
#include "print.h"

void print_params5(char *name, int nb, pid_t child, struct user_regs_struct u_in, int hexadecimal)
{
    printf(", Ox%x", (unsigned int)u_in.r8);
    nb--;
    if (nb > 0)
        print_params6(name, nb, child, u_in, hexadecimal);
}

void print_params6(char *name, int nb, pid_t child, struct user_regs_struct u_in, int hexadecimal)
{
    printf(", Ox%x", (unsigned int)u_in.r9);
    nb--;
}