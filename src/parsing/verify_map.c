#include "../../includes/cub3D.h"

void verify_texture(t_texture *texture)
{
    if (!texture->north || !texture->south || !texture->west || !texture->east ||
        !texture->floor || !texture->ceiling)
    {
        printf( "Error\nMissing texture information\n");
        exit(1);
    }
}


void verify_map(t_map *map)
{
    int i = 0;
    int j = 0;
    int player_count = 0;

    while (map->map_brute[i])
    {
        j = 0;
        while (map->map_brute[i][j])
        {
            char c = map->map_brute[i][j];
            if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
                player_count++;
                else if (c != '0' && c != '1' && c != '\0' && c != '\n')
                {
                    printf("Error\nInvalid character '%c' in map\n", c);
                    exit(1);
                }
                j++;
        }
        i++;
    }
    if (player_count != 1)
    {
        printf("Error\nInvalid number of player start positions: %d\n", player_count);
        exit(1);
    }
}
