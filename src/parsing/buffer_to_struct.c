#include "../../includes/cub3D.h"

void extract_texture(char *buffer, t_texture *texture)
{
    char **lines;
    int i;

    lines = ft_split(buffer, '\n');
    if (!lines)
        return;

    i = 0;
    while (lines[i])
    {
        if (ft_strncmp(lines[i], "NO ", 3) == 0)
            texture->NORTH = ft_strdup(lines[i] + 3);
         if (ft_strncmp(lines[i], "SO ", 3) == 0)
            texture->SOUTH = ft_strdup(lines[i] + 3);
        if (ft_strncmp(lines[i], "WE ", 3) == 0)
            texture->WEST = ft_strdup(lines[i] + 3);
        if (ft_strncmp(lines[i], "EA ", 3) == 0)
            texture->EAST = ft_strdup(lines[i] + 3);
        if (ft_strncmp(lines[i], "F ", 2) == 0)
            texture->floor = ft_atoi(lines[i] + 2);
        if (ft_strncmp(lines[i], "C ", 2) == 0)
            texture->ceiling = ft_atoi(lines[i] + 2);
        i++;
        }
        free_split(lines);
        
}

void extract_map(char *buffer, t_map *map)
{
    char **lines;
    int i;

    lines = ft_split(buffer, '\n');
    if (!lines)
        return;

    i = 0;
    while (lines[i])
    {
        if (ft_strncmp(lines[i], "NO ", 3) != 0 && ft_strncmp(lines[i], "SO ", 3) != 0 &&
            ft_strncmp(lines[i], "WE ", 3) != 0 && ft_strncmp(lines[i], "EA ", 3) != 0 &&
            ft_strncmp(lines[i], "F ", 2) != 0 && ft_strncmp(lines[i], "C ", 2) != 0)
        {
            map->map_brute[i] = lines[i];
            break;
        }
        i++;
    }
    free_split(lines);
}
void free_split(char **split)
{
    int i;

    if (!split)
        return;

    i = 0;
    while (split[i])
    {
        free(split[i]);
        i++;
    }
    free(split);
}