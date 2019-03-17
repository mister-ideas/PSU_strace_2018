/*
** EPITECH PROJECT, 2018
** PSU_strace_2018
** File description:
** prot_syscall.h
*/

#ifndef PRINT_H_
#define PRINT_H_


void syscall_display(pid_t child, unsigned long long sysnum,
                                unsigned long long retval);

#endif