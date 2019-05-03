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

void print_params5(int nb, struct user_regs_struct u_in)
{
    printf(", Ox%x", (unsigned int)u_in.r8);
    nb--;
    if (nb > 0)
        print_params6(nb, u_in);
}

void print_params6(int nb, struct user_regs_struct u_in)
{
    printf(", Ox%x", (unsigned int)u_in.r9);
    nb--;
}