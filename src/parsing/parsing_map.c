#include "../../includes/cub3D.h"

void parse_map(t_map *map)
{
    int i = 0;
    int j = 0;

    while (map->map_brute[i]) // Parcourt chaque ligne de la carte brute
    {
        printf("Processing line %d: %s\n", i, map->map_brute[i]); // Debug: Affiche la ligne actuelle
        j = 0;
        while (map->map_brute[i][j]) // Parcourt chaque caractère de la ligne
        {
            // Remplace les espaces par '0'
            if (map->map_brute[i][j] == ' ')
                map->map_brute[i][j] = '1';

            // Trouve la position initiale du joueur
            if (map->map_brute[i][j] == 'N' || map->map_brute[i][j] == 'S' || 
                map->map_brute[i][j] == 'E' || map->map_brute[i][j] == 'W')
            {
                printf("Player found at (%d, %d)\n", i, j);
                replace_position(map, i, j);
                break; // Sort de la boucle pour éviter de traiter plusieurs joueurs
            }
            j++;
        }
        i++;
    }
}

void check_opti_map(char **map_brute)
{
    int i = 0;
    int j = 0;

    // Vérifie que la carte n'est pas vide
    if (!map_brute || !map_brute[0])
    {
        printf("Error: Map is empty!\n");
        exit(1);
    }

    // Remplace les espaces par des '1' et vérifie les murs
    while (map_brute[i])
    {
        j = 0;
        while (map_brute[i][j])
        {
            // Remplace les espaces par des '1'
            if (map_brute[i][j] == ' ')
                map_brute[i][j] = '1';

            // Vérifie les murs sur les bords
            if ((i == 0 || map_brute[i + 1] == NULL || j == 0 || map_brute[i][j + 1] == '\0') &&
                map_brute[i][j] != '1')
            {
                printf("Error: Map is not surrounded by walls at (%d, %d)!\n", i, j);
                exit(1);
            }
            j++;
        }
        i++;
    }
}

void replace_position(t_map *map, int i, int j)
{
    if (map->map_brute[i][j] == 'N' || map->map_brute[i][j] == 'S' || 
        map->map_brute[i][j] == 'E' || map->map_brute[i][j] == 'W')

    {
        map->init_orientation = map->map_brute[i][j];
        map->map_brute[i][j] = '0';
        map->x_init = i;
        map->y_init = j;
    }
    printf("Initial orientation: %c\n", map->init_orientation);
    printf("Initial position:(x, y) (%d, %d)\n", map->x_init, map->y_init);
}

int invalid_wall(char **map_brute)
{
    int i = 0;
    int j = 0;

    // Vérifie que la carte n'est pas vide
    if (!map_brute || !map_brute[0])
    {
        printf("Error: Map is empty!\n");
        return (1);
    }

    // Vérifie la première et la dernière ligne
    while (map_brute[0][j])
    {
        if (map_brute[0][j] != '1')
        {
            printf("Error: Missing wall at top border (0, %d)!\n", j);
            return (1);
        }
        j++;
    }
    j = 0;
    while (map_brute[i])
        i++;
    i--; // Dernière ligne
    while (map_brute[i][j])
    {
        if (map_brute[i][j] != '1')
        {
            printf("Error: Missing wall at bottom border (%d, %d)!\n", i, j);
            return (1);
        }
        j++;
    }

    // Vérifie la première et la dernière colonne
    i = 0;
    while (map_brute[i])
    {
        if (map_brute[i][0] != '1')
        {
            printf("Error: Missing wall at left border (%d, 0)!\n", i);
            return (1);
        }
        j = 0;
        while (map_brute[i][j])
            j++;
        if (map_brute[i][j - 1] != '1')
        {
            printf("Error: Missing wall at right border (%d, %d)!\n", i, j - 1);
            return (1);
        }
        i++;
    }

    return (0); // Aucun problème détecté
}