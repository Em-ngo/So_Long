#include "get_next_line.h"

#include <stdio.h>
#include <fcntl.h>
#include <string.h>

int main (int ac, char **av) {
	int i = 1;
	char *buff = NULL;
	int fd;
	if (ac > 1)
		fd = open(av[1], O_RDONLY);
	else 
		fd = 0;

	while ((buff = get_next_line(fd)) != NULL) {
		printf("Ligne [%d] : %s", i++, buff);
		if (strncmp(buff, "exit", 4) == 0 && fd == 0) {
			free(buff);
			return 0;
		}
		free(buff);
	}
	return (0);
}