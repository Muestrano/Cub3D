/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_iteration.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picarlie <picarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:56:28 by picarlie          #+#    #+#             */
/*   Updated: 2025/04/28 16:34:59 by picarlie         ###   ########.fr       */
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
	int	Ax;
	int	Ay;
	int	xStep;
	int	yStep;

	Ay = floor(player.p_y / TILE_SIZE) * TILE_SIZE;
	Ax = player.p_x + ((Ay - player.p_y) / tan((*ray).angle));
	yStep = TILE_SIZE * step_sign((*ray).angle, 'y');
	xStep = (yStep / tan((*ray).angle)) * step_sign((*ray).angle, 'x');
	while (!is_wall(xStep, yStep, map))
	{
		Ax += xStep;
		Ay += yStep;
	}
	(*ray).dist = sqrt(pow(player.p_x - Ax, 2) + pow(player.p_y - Ay, 2));
	return ;
}
/* Take the ray, the map and the player structures */
/* Check every horizontal intersection until a wall is hit by the ray */
/* Get and save the distance of the wall hit if it is closer */
void	vertical_check(t_ray *ray, t_map map, t_player player)
{
	int	Ax;
	int	Ay;
	int	xStep;
	int	yStep;
	double	new_dist;

	Ax = floor(player.p_y / TILE_SIZE) * TILE_SIZE;
	Ay = player.p_y + ((Ax - player.p_x) / tan((*ray).angle));
	xStep = TILE_SIZE * step_sign((*ray).angle, 'x');
	yStep = (xStep / tan((*ray).angle)) * step_sign((*ray).angle, 'y');
	while (!is_wall(xStep, yStep, map))
	{
		Ax += xStep;
		Ay += yStep;
	}
	new_dist = sqrt(pow(player.p_x - Ax, 2) + pow(player.p_y - Ay, 2));
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