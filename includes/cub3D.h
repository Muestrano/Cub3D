/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picarlie <picarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:54:44 by picarlie          #+#    #+#             */
/*   Updated: 2025/04/21 16:58:42 by picarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
//# include "MLX/MLX42.h" // include the mlx library

typedef struct s_map {
	char* south_tex;
	char* north_tex;
	char* west_tex;
	char* est_tex;
	char* floor;
	char* ceiling;
	char** map;
} t_map;

/* Ray structure */
/* Constains the angle of a ray and the distance to the wall  */
typedef	struct s_ray
{
	double	angle;
	double	dist;
}t_ray;

/* Player raycasting structure */
/* Contains the player position (x,y) in pixels */
/* The player angle in radians */
/* The Field of view in radians */
typedef struct	s_player
{
	int		p_x;
	int		p_y;
	double	p_angle;
	double	fov;
}t_player;

/* Player struct in the game */
/* Define the player position in the map (in tiles) */
/* And the player's movement (with mlx hook) */
typedef struct	s_game
{
	int	pos_x;
	int	pos_y;
	int	up_down;
	int	right_left;
}t_game;

#endif