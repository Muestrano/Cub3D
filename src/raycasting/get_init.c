#include "../../includes/cub3D.h"

void	init_player(t_player *player, t_map *map)
{
	player->p_x = map->x_init;
	player->p_y = map->y_init;
	if (map->init_orientation == 'N')
		player->p_angle = M_PI * (3 / 2);
	else if (map->init_orientation == 'S')
		player->p_angle = M_PI / 2;
	else if (map->init_orientation == 'W')
		player->p_angle = M_PI;
	else if (map->init_orientation == 'E')
		player->p_angle = 0;
	return;
}
