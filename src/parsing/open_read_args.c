#include "../../includes/cub3D.h"

int open_args(int ac, char **av, t_map *map)
{
    int fd;

    if (ac != 2)
    {
        write(2, "Error\nWrong number of arguments\n", 33);
        return (1);
    }
    fd = open(av[1], O_RDONLY);
    if (fd < 0)
    {
        write(2, "Error\nFile not found\n", 22);
        return (1);
    }
    map->path = av[1];
    return (fd);
}

int read_args(int fd, t_map *map)
{
    int ret;

    // Ensure buffer is large enough (e.g., allocated with at least 2049 bytes)
    ret = read(fd, map->buffer, 2048);
    if (ret < 0)
    {
        write(2, "Error\nFailed to read file\n", 27);
        close(fd); // Close the file descriptor on error
        return (1);
    }
    map->buffer[ret] = '\0';
    return (0);
}

int print_struct(t_map map)
{
    printf("Path: %s\n", map.path);
    printf("Buffer: %s\n", map.buffer);
    return (0);
}

void init_map(t_map **map)
{
    *map = (t_map *)malloc(sizeof(t_map));
    if (!*map)
    {
        write(2, "Error\nFailed to allocate memory for map\n", 40);
        exit(1);
    }
    (*map)->path = NULL;
    (*map)->south_tex = NULL;
    (*map)->north_tex = NULL;
    (*map)->west_tex = NULL;
    (*map)->est_tex = NULL;
    (*map)->floor = NULL;
    (*map)->ceiling = NULL;
    (*map)->map_data = NULL;
}
