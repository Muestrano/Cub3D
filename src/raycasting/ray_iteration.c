/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_iteration.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picarlie <picarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:56:28 by picarlie          #+#    #+#             */
/*   Updated: 2025/05/21 17:57:10 by picarlie         ###   ########.fr       */
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

	x = floor((double)x_inter / TILE_SIZE);
	y = floor((double)y_inter / TILE_SIZE);
	if (x < 0)
		x = 0;
	if (y < 0)
		y = 0;
	// printf("DEBUG***WALL\n");
	// printf("***********************\n");
	// printf("x = %d\n", x);
	// printf("y = %d\n", y);
	// printf("x inter = %f\n", x_inter);
	// printf("y inter = %f\n", y_inter);
	// printf("map.map_brute[x][y] - 48 = %d\n", map.map_brute[x][y] - 48);
	// printf("map width = %d\n", map.map_width);
	// printf("map height = %d\n", map.map_height);
	// printf("***********************\n\n");
	if (x >= map.map_width || y >= map.map_height)
		return (1);
	return (map.map_brute[y][x] - 48);
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

	a_y = floor((double)player.p_y / TILE_SIZE) * TILE_SIZE;
	// norm_angle(&(ray->angle));
	a_x = player.p_x + floor((double)(a_y - player.p_y) / tan(ray->angle));
	y_step = TILE_SIZE * step_sign(ray->angle, 'y');
	x_step = floor((double)y_step / tan(ray->angle)) * step_sign(ray->angle, 'x');
	// printf("DEBUG\n");
	while (!is_wall(a_x, a_y, map))
	{
		a_x += x_step;
		a_y += y_step;
	}
	ray->dist = (double)sqrt(pow(player.p_x - a_x, 2) + pow(player.p_y - a_y, 2)); //Checker si la valeur est bien sauvegardee grace au ptr
	// printf("***********************\n");
	// printf("HORIZONTAL CHECK\n");
	// printf("ax = %d\n", a_x);
	// printf("ay = %d\n", a_y);
	// printf("px = %d\n", player.p_x);
	// printf("py = %d\n", player.p_y);
	// printf("x step = %d\n", x_step);
	// printf("y step = %d\n", y_step);
	// printf("step sign y = %d\n", step_sign(ray->angle, 'y'));
	// printf("tan ray angle = %f\n", tan(ray->angle));
	// printf("dist = %f\n", ray->dist);
	// printf("***********************\n");
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

	a_x = floor((double)player.p_y / TILE_SIZE) * TILE_SIZE;
	// norm_angle(&(ray->angle));
	a_y = player.p_y + floor((double)(a_x - player.p_x) / tan(ray->angle));
	x_step = TILE_SIZE * step_sign(ray->angle, 'x');
	y_step = floor((double)x_step / tan(ray->angle)) * step_sign(ray->angle, 'y');
	while (!is_wall(a_x, a_y, map))
	{
		a_x += x_step;
		a_y += y_step;
	}
	new_dist = (double)sqrt(pow(player.p_x - a_x, 2) + pow(player.p_y - a_y, 2));
	
	printf("ray dist = %f\n", ray->dist);
	if (new_dist < ray->dist)
		ray->dist = new_dist;
	printf("***********************\n");
	printf("VERTICAL CHECK\n");
	printf("ax = %d\n", a_x);
	printf("ay = %d\n", a_y);
	printf("xstep = %d\n", x_step);
	printf("ystep = %d\n", y_step);
	printf("px = %d\n", player.p_x);
	printf("py = %d\n", player.p_y);
	printf("tan ray angle = %f\n", tan(ray->angle));
	printf("dist = %f\n", ray->dist);
	printf("new dist = %f\n", new_dist);
	printf("***********************\n");
	return;
}

/* Caculates the top and bottom pixels of a wall strip */
/* Takes a ray structure pointer */
void	wall_strips(t_ray *ray)
{
	ray->wall_strip_height = WIN_HEIGHT / ray->dist;
	ray->wall_top_pixel = (WIN_HEIGHT / 2) - (ray->wall_strip_height / 2);
	ray->wall_bottom_pixel = (WIN_HEIGHT / 2) + (ray->wall_strip_height / 2);
	// printf("***********************\n");
	// printf("ray->wall_strip_height = %d\n", ray->wall_strip_height);
	// printf("ray->wall_top = %d\n", ray->wall_top_pixel);
	// printf("ray->wall_bot = %d\n", ray->wall_bottom_pixel);
	if (ray->wall_top_pixel < 0)
		ray->wall_top_pixel = 0;

	if (ray->wall_bottom_pixel > WIN_HEIGHT)
		ray->wall_bottom_pixel = WIN_HEIGHT;
}

/* Takes the mlx, ray, map and player structures */
/* Cast each ray of the FOV with fisheye effect corrected */
void	ray_iteration(t_mlx *mlx)
{
	int		nb_ray;
	double	fish_angle;
	t_ray	ray;

	nb_ray = 0;
    // printf("***********************\n");
	// printf("player angle = %f\n", mlx->player.p_angle);
	// printf("player orientation = %c\n", mlx->map.init_orientation);
	// printf("wall height = %d\n", mlx->map.map_height);
	// printf("wall width = %d\n", mlx->map.map_width);
	// printf("nb ray = %d\n", nb_ray);
    // printf("***********************\n");
	ray.angle = mlx->player.p_angle - (FOV * (double)M_PI / 360);
	// printf("angle = %f\n", ray.angle);
	norm_angle(&(ray.angle));
	while (nb_ray < WIN_WIDTH)
	{
		// printf("***********************\n");
		// printf("nb ray = %d\n", nb_ray);
		// printf("wall height = %d\n", ray.wall_strip_height);
		// printf("wall top = %d\n", ray.wall_top_pixel);
		// printf("wall bot = %d\n", ray.wall_bottom_pixel);
		// printf("orientation = %c\n", ray.orientation);
		// printf("player angle = %f\n", mlx->player.p_angle);
		// printf("angle = %f\n", ray.angle);
		// printf("wall width = %d\n", mlx->map.map_width);
		// printf("nb ray = %d\n", nb_ray);
  		// printf("***********************\n");
		// printf("H1nb ray = %d\n", nb_ray);
		horizontal_check(&ray, mlx->map, mlx->player);
		vertical_check(&ray, mlx->map, mlx->player);
		fish_angle = ray.angle - mlx->player.p_angle;
		norm_angle(&fish_angle);
		// printf("dist = %f\n", ray.dist);
		// ray.dist = ray.dist * cos(fish_angle);
		ray.dist = ray.dist * (double)cos(fish_angle) / TILE_SIZE;
		// printf("fish = %f\n", fish_angle);
		// printf("dist = %f\n", ray.dist);
		// ray.dist = ray.dist * cos(fish_angle);
		wall_strips(&ray);
		ray_orientation(&ray); //donner fish angle a la place ?
		calculate_texx(mlx, &ray);
		draw_wall(mlx, &ray, nb_ray);
		nb_ray++;
		ray.angle += FOV * (double)M_PI / (180 * WIN_WIDTH);
		norm_angle(&(ray.angle));
		// printf("***********************\n");
		// // printf("nb ray = %d\n", nb_ray);
		// printf("wall height = %d\n", ray.wall_strip_height);
		// printf("wall top = %d\n", ray.wall_top_pixel);
		// printf("wall bot = %d\n", ray.wall_bottom_pixel);
		// printf("orientation = %c\n", ray.orientation);
		// printf("player angle = %f\n", mlx->player.p_angle);
		// printf("angle = %f\n", ray.angle);
		// printf("fish = %f\n", fish_angle);
		// printf("dist = %f\n", ray.dist);
		// printf("wall width = %d\n", mlx->map.map_width);
		// printf("nb ray = %d\n", nb_ray);
  		// printf("***********************\n");
	}
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
