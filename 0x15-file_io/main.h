#ifndef FILE_IO
#define FILE_IO

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int _putchar(char c);
ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
void print_error(char *msg);
void print_elf_header(Elf64_Ehdr *header);
void read_elf_header(int fd, Elf64_Ehdr *header);

#endif
