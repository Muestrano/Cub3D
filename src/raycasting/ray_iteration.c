/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_iteration.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picarlie <picarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:56:28 by picarlie          #+#    #+#             */
/*   Updated: 2025/04/28 16:49:35 by picarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/* Takes the coordinates of a tile (in pixels) */
/* Returns 1 if it is a wall or out of bounds */
/* Returns 0 if not */
int	is_wall(double x_inter, double y_inter, t_map map)
{
	int	x;
	int	y;

	x = floor(x_inter / TILE_SIZE);
	y = floor(y_inter / TILE_SIZE);
	if (x < 0)
		x = 0;
	if (y < 0)
		y = 0;
	if (x >= map.map_width || y >= map.map_height)
		return (1);
	return (map.map_brute[x][y] - 48);
}

/* Take the ray, the map and the player structures */
/* Check every horizontal intersection until a wall is hit by the ray */
/* Get and save the distance of the wall hit */
void	horizontal_check(t_ray *ray, t_map map, t_player player)
{
	int	a_x;
	int	a_y;
	int	x_step;
	int	y_step;

	a_y = floor(player.p_y / TILE_SIZE) * TILE_SIZE;
	a_x = player.p_x + ((a_y - player.p_y) / tan((*ray).angle));
	y_step = TILE_SIZE * step_sign((*ray).angle, 'y');
	x_step = (y_step / tan((*ray).angle)) * step_sign((*ray).angle, 'x');
	while (!is_wall(a_x, a_y, map))
	{
		a_x += x_step;
		a_y += y_step;
	}
	(*ray).dist = sqrt(pow(player.p_x - a_x, 2) + pow(player.p_y - a_y, 2)); //Checker si la valeur est bien sauvegardee grace au ptr
	return ;
}

/* Take the ray, the map and the player structures */
/* Check every horizontal intersection until a wall is hit by the ray */
/* Get and save the distance of the wall hit if it is closer */
void	vertical_check(t_ray *ray, t_map map, t_player player)
{
	int		a_x;
	int		a_y;
	int		x_step;
	int		y_step;
	double	new_dist;

	a_x = floor(player.p_y / TILE_SIZE) * TILE_SIZE;
	a_y = player.p_y + ((a_x - player.p_x) / tan((*ray).angle));
	x_step = TILE_SIZE * step_sign((*ray).angle, 'x');
	y_step = (x_step / tan((*ray).angle)) * step_sign((*ray).angle, 'y');
	while (!is_wall(a_x, a_y, map))
	{
		a_x += x_step;
		a_y += y_step;
	}
	new_dist = sqrt(pow(player.p_x - a_x, 2) + pow(player.p_y - a_y, 2));
	if (new_dist < (*ray).dist)
		(*ray).dist = new_dist;
	return ;
}

// Test for step_sign and norm_angle
/*int	main ()
{
	float	angle;

	angle = 1.5 * M_PI;
	printf("Angle : %f\n", angle);
	norm_angle(&angle);
	printf("Angle norme : %f\n", angle);
	printf("x : %d\ny : %d\n", step_sign(angle, 'x'), step_sign(angle, 'y'));
	return (0);
}*/