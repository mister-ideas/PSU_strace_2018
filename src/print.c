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

void print_params(char *name, int nb, struct user_regs_struct u_in,
                    int hexadecimal)
{
    if (!hexadecimal && strcmp(name, "write") == 0)
        printf("%d", (unsigned int)u_in.rdi);
    else
        printf("0x%x", (unsigned int)u_in.rdi);
    nb--;
    if (nb > 0)
        print_params2(name, nb, u_in, hexadecimal);
}

void print_params2(char *name, int nb, struct user_regs_struct u_in,
                    int hexadecimal)
{
    printf(", 0x%x", (unsigned int)u_in.rsi);
    nb--;
    if (nb > 0)
        print_params3(name, nb, u_in, hexadecimal);
}

void print_params3(char *name, int nb, struct user_regs_struct u_in,
                    int hexadecimal)
{
    if (!hexadecimal && strcmp(name, "write") == 0)
        printf(", %d", (unsigned int)u_in.rdx);
    else
        printf(", 0x%x", (unsigned int)u_in.rdx);
    nb--;
    if (nb > 0)
        print_params4(nb, u_in);
}

void print_params4(int nb, struct user_regs_struct u_in)
{
    printf(", 0x%x", (unsigned int)u_in.rcx);
    nb--;
    if (nb > 0)
        print_params5(nb, u_in);
}

void syscall_display(unsigned sysnum, unsigned retval,
                    struct user_regs_struct u_in, int hexadecimal)
{
    printf("%s(", syscall_table[(int)sysnum].name);
    if (syscall_table[sysnum].nb_params != 0)
        print_params(syscall_table[(int)sysnum].name,
                    syscall_table[sysnum].nb_params, u_in, hexadecimal);
    printf(") = ");
    if (retval) {
        if (!hexadecimal
        && strcmp(syscall_table[(int)sysnum].name, "write") == 0)
            printf("%d\n", (unsigned int)retval);
        else
            printf("0x%x\n", (unsigned int)retval);
    } else
        printf("?\n");
}