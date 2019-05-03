/*
** EPITECH PROJECT, 2019
** PSU_strace_2018
** File description:
** test
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

int do_child(int ac, char **av, char **envp)
{
    char *ag[ac + 1];

    memcpy(ag, av, ac * sizeof(char *));
    ag[ac] = NULL;
    ptrace(PTRACE_TRACEME);
    kill(getpid(), SIGSTOP);
    return execve(ag[0], ag, envp);
}

int do_tracer(pid_t child, int hexadecimal)
{
    int status = 0;
    struct user_regs_struct u_in;

    waitpid(child, &status, 0);
    while ((WSTOPSIG(status) == SIGTRAP
        || WSTOPSIG(status) == SIGSTOP) && WIFSTOPPED(status)) {
        if (ptrace(PTRACE_GETREGS, child, NULL, &u_in))
            perror("ptrace getregs");
        if (ptrace(PTRACE_SINGLESTEP, child, 0, 0) == -1)
            perror("ptrace singlestep");
        waitpid(child, &status, 0);
        if ((WSTOPSIG(status) == SIGTRAP
        || WSTOPSIG(status) == SIGSTOP) && WIFSTOPPED(status)) {
            if (ptrace(PTRACE_GETREGS, child, NULL, &u_in))
                perror("ptrace");
            if (u_in.orig_rax < 334 && u_in.orig_rax > 0)
                syscall_display(u_in.orig_rax, u_in.rax, u_in, hexadecimal);
        }
    }
    printf("+++ exited with 0 +++\n");
    return (0);
}

int main(int ac, char **av, char **envp)
{
    pid_t child;
    int hexadecimal = 1;
    char **program = av + 1;

    if (ac == 1 || ac > 4) {
        dprintf(2, "USAGE: ./strace [-s] [-p <pid>|<command>]\n");
        return (84);
    } else if (strcmp(av[1], "--help") == 0)
        printf("USAGE: ./strace [-s] [-p <pid>|<command>]\n");
    else if (strcmp(av[1], "-s") == 0) {
        hexadecimal = 0;
        program = av + 2;
    }
    child = fork();
    if (child == 0) {
        if (do_child(ac - 1, program, envp) == -1)
            return (84);
        return (0);
    }
    return (do_tracer(child, hexadecimal));
}