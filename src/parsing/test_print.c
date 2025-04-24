#include "../../includes/cub3D.h"

void print_texture(t_texture texture)
{
    printf("NORTH: %s\n", texture.NORTH);
    printf("SOUTH: %s\n", texture.SOUTH);
    printf("WEST: %s\n", texture.WEST);
    printf("EAST: %s\n", texture.EAST);
    printf("FLOOR: %s\n", texture.floor);
    printf("CEILING: %s\n", texture.ceiling);
    printf("---------------------\n");
    printf("Texture structure printed successfully.\n");
}

void print_map(t_map *map)
{
    int i = 0;
    while (map->map_brute[i])
    {
        printf("valeur de I %d: %s\n", i, map->map_brute[i]);
        i++;
    }
    printf("---------------------\n");
    printf("position player: (%d, %d)\n", map->x_init, map->y_init);
    printf("Initial orientation: %c\n", map->init_orientation);
    printf("Map structure printed successfully.\n");
}

void max_x(t_map *map)
{
    int i = 0;
    int max = 0;
    while (map->map_brute[i])
    {
        if (ft_strlen(map->map_brute[i]) > max)
            max = ft_strlen(map->map_brute[i]);
        i++;
    }
    printf("max x: %d\n", max);
}


void max_width(t_map *map)
{
    int i = 0;
    int max = 0;
    while (map->map_brute[i])
    {
        if (ft_strlen(map->map_brute[i]) > max)
            max = ft_strlen(map->map_brute[i]);
        i++;
    }
    printf("max width: %d\n", max);
}
void check_map(t_map *map)
{
    int i = 0;
    int j;
    int max = 0;
    while (map->map_brute[i])
    {
        j = 0;
        while (map->map_brute[i][j])
        {
            if (map->map_brute[i][j] == '1')
                printf("line %d, column %d: wall\n", i, j);
            else if (map->map_brute[i][j] == '0')
                printf("line %d, column %d: empty space\n", i, j);
            else
                printf("line %d, column %d: invalid character\n", i, j);
            j++;
        }
        i++;
    }       
}
void check_line(t_map *map)
{
    int i = 0;
    int j;
    int max = 0;
    while (map->map_brute[i])
    {
        j = 0;
        while (map->map_brute[i][j])
        {
            if (map->map_brute[i][j] == '1')
                printf("line %d, column %d: wall\n", i, j);
            else if (map->map_brute[i][j] == '0')
                printf("line %d, column %d: empty space\n", i, j);
            else
                printf("line %d, column %d: invalid character\n", i, j);
            j++;
        }
        i++;
    }
}