#include "main.h"

/**
 * append_text_to_file - appends text at the end of a file.
 * @filename: the name of the file to append text to.
 * @text_content: a NULL terminated string to add at the end of the file.
 *
 * Return: 1 on success and -1 on failure.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, n_write, len;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);
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
