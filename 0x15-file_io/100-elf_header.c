#include "main.h"
#include <elf.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * print_error - Prints an error message to stderr and exits with status code 98
 * @msg: The error message to display
 */
void print_error(char *msg)
{
	fprintf(stderr, "%s\n", msg);
	exit(98);
}

/**
 * print_elf_header - Prints the information contained in the ELF header
 * @header: Pointer to the ELF header structure
 */
void print_elf_header(Elf64_Ehdr *header)
{
	printf("  Magic:   ");
	for (int i = 0; i < EI_NIDENT; i++)
		printf("%02x ", header->e_ident[i]);
	printf("\n");
	printf("  Class:                             %s\n",
	       header->e_ident[EI_CLASS] == ELFCLASS64 ? "ELF64" : "Invalid");
	printf("  Data:                              %s\n",
	       header->e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" :
	       header->e_ident[EI_DATA] == ELFDATA2MSB ? "2's complement, big endian" : "Invalid");
	printf("  Version:                           %d (current)\n", header->e_ident[EI_VERSION]);
	printf("  OS/ABI:                            %s\n",
	       header->e_ident[EI_OSABI] == ELFOSABI_SYSV ? "UNIX - System V" :
	       header->e_ident[EI_OSABI] == ELFOSABI_HPUX ? "HP-UX" :
	       header->e_ident[EI_OSABI] == ELFOSABI_NETBSD ? "NetBSD" :
	       header->e_ident[EI_OSABI] == ELFOSABI_LINUX ? "Linux" : "Invalid");
	printf("  ABI Version:                       %d\n", header->e_ident[EI_ABIVERSION]);
	printf("  Type:                              0x%04x\n", header->e_type);
	printf("  Entry point address:               0x%lx\n", (unsigned long)header->e_entry);
}

/**
 * read_elf_header - Reads the ELF header from the specified file
 * @fd: The file descriptor of the ELF file
 * @header: Pointer to the ELF header structure to populate
 */
void read_elf_header(int fd, Elf64_Ehdr *header)
{
	if (read(fd, header, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr))
		print_error("Error: Unable to read ELF header");

	if (lseek(fd, 0, SEEK_SET) == -1)
		print_error("Error: Unable to seek to the beginning of the file");
}

/**
 * main - Entry point of the program
 * @argc: The argument count
 * @argv: The argument vector
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char **argv)
{
	int fd;
	Elf64_Ehdr header;

	if (argc != 2)
		print_error("Usage: elf_header elf_filename");

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		print_error("Error: Unable to open file");

	read_elf_header(fd, &header);
	print_elf_header(&header);

	if (close(fd) == -1)
		print_error("Error: Unable to close file");

	return 0;
