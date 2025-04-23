/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picarlie <picarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:56:28 by picarlie          #+#    #+#             */
/*   Updated: 2025/04/23 17:38:27 by picarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/* Tells the sign of the steps based on the ray's angle */
/* Take the angle of a ray and the type of step (x or y) */
/* Returns the sign of the step */
int	step_sign(float	angle, char c)
{
	if (c == 'x')
	{
		if (angle > (M_PI / 2) && angle < (M_PI * 3 / 2))
			return (-1);
		else if (angle == (M_PI / 2) || angle == (M_PI * 3 / 2))
			return (0);
	}
	else
	{
		if (angle > M_PI)
			return (-1);
		else if (!angle || angle == M_PI)
			return (0);
	}
	return (1);
}

/* Set the angle between 0 and 2PI */
/* Take an angle as argument */
void norm_angle(float *angle)
{
	if (*angle >= (2 * M_PI))
		*angle -= 2 * M_PI;
}

int	horizon_check(t_ray *ray, char **map, t_player player, t_game game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while ()
	{
		
	}
	return ();
}
