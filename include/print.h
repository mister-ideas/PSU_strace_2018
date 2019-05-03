/*
** EPITECH PROJECT, 2018
** PSU_strace_2018
** File description:
** prot_syscall.h
*/

#ifndef PRINT_H_
#define PRINT_H_


void syscall_display(pid_t child, unsigned sysnum, unsigned retval,
                    struct user_regs_struct u_in, int hexadecimal);
void print_params(char *name, int nb, pid_t child, struct user_regs_struct u_in, int hexadecimal);
void print_params2(char *name, int nb, pid_t child, struct user_regs_struct u_in, int hexadecimal);
void print_params3(char *name, int nb, pid_t child, struct user_regs_struct u_in, int hexadecimal);
void print_params4(char *name, int nb, pid_t child, struct user_regs_struct u_in, int hexadecimal);
void print_params5(char *name, int nb, pid_t child, struct user_regs_struct u_in, int hexadecimal);
void print_params6(char *name, int nb, pid_t child, struct user_regs_struct u_in, int hexadecimal);

#endif