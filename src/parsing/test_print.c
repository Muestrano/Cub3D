#include "../../includes/cub3D.h"

void print_texture(t_texture texture)
{
    printf("NORTH: %s\n", texture.north);
    printf("SOUTH: %s\n", texture.south);
    printf("WEST: %s\n", texture.west);
    printf("EAST: %s\n", texture.east);
    printf("FLOOR: %d\n", texture.floor_color);
    printf("CEILING: %d\n", texture.ceiling_color);
    printf("---------------------\n");
    printf("Texture structure printed successfully.\n");
}

void print_map(t_map *map)
{
    int i = 0;
    while (map->map_brute[i] != NULL)
    {
        printf("valeur de I %d: %s\n", i, map->map_brute[i]);
        i++;
    }
    printf("---------------------\n");
    printf("position player: (%d, %d)\n", map->x_init, map->y_init);
    printf("Initial orientation: %c\n", map->init_orientation);
    printf("Map structure printed successfully.\n");
}

