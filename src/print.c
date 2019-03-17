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
#include "print.h"

void print_params(int nb, pid_t child, struct user_regs_struct u_in)
{
    printf("%x", (unsigned)ptrace(PTRACE_PEEKTEXT, child, u_in.rdi, NULL));
    nb--;
    if (nb > 0)
        print_params2(nb, child, u_in);
}

void print_params2(int nb, pid_t child, struct user_regs_struct u_in)
{
    printf(", %x", (unsigned)ptrace(PTRACE_PEEKTEXT, child, u_in.rsi, NULL));
    nb--;
    if (nb > 0)
        print_params3(nb, child, u_in);
}

void print_params3(int nb, pid_t child, struct user_regs_struct u_in)
{
    printf(", %x", (unsigned)ptrace(PTRACE_PEEKTEXT, child, u_in.rdx, NULL));
    nb--;
    if (nb > 0)
        print_params4(nb, child, u_in);
}

void print_params4(int nb, pid_t child, struct user_regs_struct u_in)
{
    printf(", %x", (unsigned)ptrace(PTRACE_PEEKTEXT, child, u_in.rcx, NULL));
    nb--;
    if (nb > 0)
        print_params5(nb, child, u_in);
}

void syscall_display(pid_t child, unsigned sysnum, unsigned retval,
                    struct user_regs_struct u_in)
{
    printf("%s(", syscall_table[(int)sysnum].name);
    if (syscall_table[sysnum].nb_params != 0)
        print_params(syscall_table[sysnum].nb_params, child, u_in);
    printf(") = ");
    if (retval)
        printf("0x%x\n", retval);
    else
        printf("0x0\n");
}