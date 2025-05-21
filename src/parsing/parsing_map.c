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
				calc_map_size(map);
                replace_position(map, i, j);
				
                break; // Sort de la boucle pour éviter de traiter plusieurs joueurs
            }
            j++;
        }
        i++;
    }
}

void	calc_map_size(t_map *map)
{
    int i = 0;
    int max_width = 0;
    int width;

    while (map->map_brute && map->map_brute[i])
    {
        width = (int)strlen(map->map_brute[i]);
        if (width > max_width)
            max_width = width;
        i++;
    }
    map->map_height = i;
    map->map_width = max_width;
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

int	is_player(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

int	is_open_char(char c)
{
	return (c == '0' || is_player(c));
}

int	is_invalid_surrounding(char **map, int i, int j)
{

	// Vérifie la case du haut
	if (i == 0 || j >= (int)strlen(map[i - 1]) || map[i - 1][j] == ' ')
		return 1;

	// Vérifie la case du bas
	if (map[i + 1] == NULL || j >= (int)strlen(map[i + 1]) || map[i + 1][j] == ' ')
		return 1;

	// Vérifie la case à gauche
	if (j == 0 || map[i][j - 1] == ' ')
		return 1;

	// Vérifie la case à droite
	if (map[i][j + 1] == '\0' || map[i][j + 1] == ' ')
		return 1;

	return 0;
}

void	check_border_map(char **map)
{
	int i = 0;
	int j;

	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (is_open_char(map[i][j]))
			{
				if (is_invalid_surrounding(map, i, j))
				{
					printf("Error\nMap not closed at (%d, %d)\n", i, j);
					exit(1);
				}
			}
			j++;
		}
		i++;
	}
}
