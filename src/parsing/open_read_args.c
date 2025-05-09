#include "../../includes/cub3D.h"

int open_args(int ac, char **av, t_map *map)
{
    int fd;

    if (ac != 2)
    {
        printf("Error\nWrong number of arguments\n");
        return (1);
    }
    fd = open(av[1], O_RDONLY);
    if (fd < 0)
    {
        printf("Error\nFile not found\n");
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
        printf("Error\nFailed to read file\n");
        close(fd); // Close the file descriptor on error
        return (1);
    }
    map->buffer[ret] = '\0';
    return (0);
}

void init_map(t_map **map)
{
    *map = (t_map *)malloc(sizeof(t_map));
    if (!*map)
    {
        printf("Error\nFailed to allocate memory for map\n");
        exit(1);
    }
    (*map)->path = NULL;
    (*map)->buffer[0] = '\0';
    init_mapbrute(*map); // Initialize map_brute
    (*map)->init_orientation = 0;
}

char **init_mapbrute(t_map *map)
{
    int i = 0;

    // Allocate memory for the map_brute array
    map->map_brute = (char **)malloc(100 * sizeof(char *)); // Adjust size as needed
    if (!map->map_brute)
    {
        printf("Error\nFailed to allocate memory for map_brute\n");
        exit(1);
    }
    while (i < 100)
    {
        map->map_brute[i] = NULL; // Initialize each pointer to NULL
        i++;
    }
    return (map->map_brute);
}


void init_texture(t_texture **texture)
{
    *texture = (t_texture *)malloc(sizeof(t_texture));
    if (!*texture)
    {
        write(2, "Error\nFailed to allocate memory for texture\n", 43);
        exit(1);
    }
    (*texture)->south = NULL;
    (*texture)->north = NULL;
    (*texture)->west = NULL;
    (*texture)->east = NULL;
    (*texture)->floor =NULL;
    (*texture)->ceiling = NULL;
}


// void init_struct(t_map map, t_texture texture)
// {
//     // Initialize the map structure
//     init_map(&map);

//     // Initialize the texture structure
//     init_texture(&texture);

    // // Initialize the player structure
    // player->p_x = 0;
    // player->p_y = 0;
    // player->p_angle = 0.0;
    // player->fov = 0.0;

    // // Initialize the game structure
    // game->pos_x = 0;
    // game->pos_y = 0;
    // game->up_down = 0;
    // game->right_left = 0;
// }