#include "../../includes/cub3D.h"

void extract_texture(char *buffer, t_mlx *mlx)
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
            mlx->texture.north = ft_strdup(lines[i] + 3);
        else if (ft_strncmp(lines[i], "SO ", 3) == 0)
            mlx->texture.south = ft_strdup(lines[i] + 3);
        else if (ft_strncmp(lines[i], "WE ", 3) == 0)
            mlx->texture.west = ft_strdup(lines[i] + 3);
        else if (ft_strncmp(lines[i], "EA ", 3) == 0)
            mlx->texture.east = ft_strdup(lines[i] + 3);
        else if (ft_strncmp(lines[i], "F ", 2) == 0)
            mlx->texture.floor = ft_strdup(lines[i] + 2); 
        else if (ft_strncmp(lines[i], "C ", 2) == 0)
            mlx->texture.ceiling = ft_strdup(lines[i] + 2);
        i++;
        // printf("Line %d: %s\n", i, lines[i - 1]);
        }
        // free_split(lines);
        
}

int count_map_lines(char **lines)
{
    int i = 0, count = 0;
    while (lines[i])
    {
        if (!(ft_strncmp(lines[i], "NO ", 3) == 0 || ft_strncmp(lines[i], "SO ", 3) == 0 ||
              ft_strncmp(lines[i], "WE ", 3) == 0 || ft_strncmp(lines[i], "EA ", 3) == 0 ||
              ft_strncmp(lines[i], "F ", 2) == 0 || ft_strncmp(lines[i], "C ", 2) == 0))
            count++;
        i++;
    }
    return count;
}

void extract_map(char *buffer, t_map *map)
{
    char **lines;
    int i, j, map_lines;

    lines = ft_split(buffer, '\n');
    if (!lines)
        return;

    map_lines = count_map_lines(lines);
    map->map_brute = malloc(sizeof(char *) * (map_lines + 1));
    if (!map->map_brute)
        return;

    i = 0;
    j = 0;
    while (lines[i])
    {
        if (ft_strncmp(lines[i], "NO ", 3) == 0 || ft_strncmp(lines[i], "SO ", 3) == 0 ||
            ft_strncmp(lines[i], "WE ", 3) == 0 || ft_strncmp(lines[i], "EA ", 3) == 0 ||
            ft_strncmp(lines[i], "F ", 2) == 0 || ft_strncmp(lines[i], "C ", 2) == 0)
        {
            i++;
            continue;
        }
        map->map_brute[j] = ft_strdup(lines[i]);
        j++;
        i++;
    }
    map->map_brute[j] = NULL; // Null-terminate the map array

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