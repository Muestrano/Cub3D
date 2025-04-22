#include "../../includes/cub3D.h"

read_rsc(char *path, int fd)
{
	open(path, O_RDONLY);
    if (fd < 0) {
        perror("open");
        exit(1);
    }
}