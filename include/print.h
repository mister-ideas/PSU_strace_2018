/*
** EPITECH PROJECT, 2018
** PSU_strace_2018
** File description:
** prot_syscall.h
*/

#ifndef PRINT_H_
#define PRINT_H_


void syscall_display(unsigned sysnum, unsigned retval,
                    struct user_regs_struct u_in, int hexadecimal);
void print_params(char *name, int nb, struct user_regs_struct u_in,
                    int hexadecimal);
void print_params2(char *name, int nb, struct user_regs_struct u_in,
                    int hexadecimal);
void print_params3(char *name, int nb, struct user_regs_struct u_in,
                    int hexadecimal);
void print_params4(int nb, struct user_regs_struct u_in);
void print_params5(int nb, struct user_regs_struct u_in);
void print_params6(int nb, struct user_regs_struct u_in);

#endif