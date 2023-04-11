#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * read_textfile - reads a text file and prints it to the POSIX standard output.
 * @filename: name of the file to read.
 * @letters: number of letters to read and print.
 *
 * Return: number of letters read and printed. If it fails, returns 0.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	FILE *fp;
	ssize_t bytes_read, bytes_written;
	char *buffer;

	if (!filename)
		return (0);

	fp = fopen(filename, "r");
	if (!fp)
		return (0);

	buffer = malloc(sizeof(char) * (letters + 1));
	if (!buffer)
	{
		fclose(fp);
		return (0);
	}

	bytes_read = fread(buffer, sizeof(char), letters, fp);
	if (bytes_read == -1)
	{
		fclose(fp);
		free(buffer);
		return (0);
	}

	buffer[bytes_read] = '\0';

	bytes_written = write(STDOUT_FILENO, buffer, bytes_read);
	if (bytes_written == -1 || bytes_written != bytes_read)
	{
		fclose(fp);
		free(buffer);
		return (0);
	}

	fclose(fp);
	free(buffer);

	return (bytes_written);
}

