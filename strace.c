/*
** EPITECH PROJECT, 2019
** PSU_strace_2018
** File description:
** test
*/

#include "stdio.h"
#include "string.h"

int main(int ac, char **av)
{
    if (ac == 1 || ac > 4) {
        dprintf(2, "USAGE: ./strace [-s] [-p <pid>|<command>]\n");
        return (84);
    } else if (strcmp(av[1], "--help") == 0)
        printf("USAGE: ./strace [-s] [-p <pid>|<command>]\n");
    return (0);
}