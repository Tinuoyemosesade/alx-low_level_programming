#ifndef MAIN_H
#define MAIN_H

#include <elf.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* elf_header.c */
void check_elf(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf);
int main(int __attribute__((__unused__)) argc, char *argv[]);

#endif /* MAIN_H */

