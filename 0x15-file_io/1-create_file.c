#include "main.h"

/**
 * create_file - creates a file.
 * @filename: the name of the file to create.
 * @text_content: a NULL terminated string to write to the file.
 *
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
	int fd, n_write, len;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd == -1)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len] != '\0'; len++)
			;

		n_write = write(fd, text_content, len);
		if (n_write == -1 || n_write != len)
		{
			close(fd);
			return (-1);
		}
	}

	close(fd);
	return (1);
}
