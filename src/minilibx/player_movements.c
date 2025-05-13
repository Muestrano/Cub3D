/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picarlie <picarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:36:26 by picarlie          #+#    #+#             */
/*   Updated: 2025/05/07 17:12:00 by picarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/* Takes the player structure */
/* Change the coordinates of the player moving forward */
void	up_movements(t_player *player, t_map map)
{
	int	x;
	int	y;

	x = floor(player->p_x + (cos(player->p_angle) * step_sign(player->p_angle, 'x') * playerSpeed));
	y = floor(player->p_y + (sin(player->p_angle) * step_sign(player->p_angle, 'y') * playerSpeed));
	if (!is_wall(x, y, map))
	{
		player->p_x = x;
		player->p_y = y;
	}
	else
	{
		if (!is_wall(player->p_x, y, map))
			player->p_y = y;
		else if (!is_wall(x, player->p_y, map))
			player->p_x = x;
	}
	return ;
}

// /* Takes the player structure */
// /* Change the coordinates of the player moving backward */
void	down_movements(t_player *player, t_map map)
{
	int	x;
	int	y;

	x = floor(player->p_x - (cos(player->p_angle) * step_sign(player->p_angle, 'x') * playerSpeed));
	y = floor(player->p_y - (sin(player->p_angle) * step_sign(player->p_angle, 'y') * playerSpeed));
	if (!is_wall(x, y, map))
	{
		player->p_x = x;
		player->p_y = y;
	}
	else
	{
		if (!is_wall(player->p_x, y, map))
			player->p_y = y;
		else if (!is_wall(x, player->p_y, map))
			player->p_x = x;
	}
	return ;
}

// /* Takes the player structure */
// /* Change the coordinates of the player moving to the right */
void	right_movements(t_player *player, t_map map)
{
	int	x;
	int	y;

	x = floor(player->p_x + (cos(player->p_angle + (M_PI / 2)) * step_sign(player->p_angle, 'x') * playerSpeed));
	y = floor(player->p_y + (sin(player->p_angle + (M_PI / 2)) * step_sign(player->p_angle, 'y') * playerSpeed));
	if (!is_wall(x, y, map))
	{
		player->p_x = x;
		player->p_y = y;
	}
	else
	{
		if (!is_wall(player->p_x, y, map))
			player->p_y = y;
		else if (!is_wall(x, player->p_y, map))
			player->p_x = x;
	}
	return ;
}

// /* Takes the player structure */
// /* Change the coordinates of the player moving to the left */
void	left_movements(t_player *player, t_map map)
{
	int	x;
	int	y;

	x = floor(player->p_x + (cos(player->p_angle - (M_PI / 2)) * step_sign(player->p_angle, 'x') * playerSpeed));
	y = floor(player->p_y + (sin(player->p_angle - (M_PI / 2)) * step_sign(player->p_angle, 'y') * playerSpeed));
	if (!is_wall(x, y, map))
	{
		player->p_x = x;
		player->p_y = y;
	}
	else
	{
		if (!is_wall(player->p_x, y, map))
			player->p_y = y;
		else if (!is_wall(x, player->p_y, map))
			player->p_x = x;
	}
	return ;
}

int	ft_key(int key, t_mlx *mlx)
{
	if (key == XK_w)
		up_movements(&(mlx->player), mlx->map);
	else if (key == XK_s)
		down_movements(&(mlx->player), mlx->map);
	else if (key == XK_d)
		right_movements(&(mlx->player), mlx->map);
	else if (key == XK_a)
		left_movements(&(mlx->player), mlx->map);
	else if (key == XK_e)
		right_rot_angle(&(mlx->player));
	else if (key == XK_q)
		left_rot_angle(&(mlx->player));
	else if (key == XK_Escape)
        exit(0);
		// ft_exit(data, "Merci d'avoir joué au jeu!", EXIT_SUCCESS);
	return (1);
}

// https://ismailassil.medium.com/ray-casting-c-8bfae2c2fc13 pour les player movement
// Second, Forward/Backward Movements — it is resolved based on the current position of the player, rotation angle and the up and down direction.
// The cos(rotAngle) calculate the horizontal component of the movement direction.
// The sin(rotAngle) calculate the vertical component of the movement direction.