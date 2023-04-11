#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <fcntl.h>

int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);

#endif /* MAIN_H */
