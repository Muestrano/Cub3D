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

// Fonction pour remplacer la position initiale du joueur dans la carte brute

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

