/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picarlie <picarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:34:33 by picarlie          #+#    #+#             */
/*   Updated: 2025/05/06 13:53:42 by picarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/* Update the orientation of the ray */
/* Take the ray struct pointer */
void	ray_orientation(t_ray *ray)
{
	if (ray->angle >= (M_PI / 4) && ray->angle <= (M_PI * (3 / 4)))
		ray->orientation = 'S';
	else if (ray->angle >= (M_PI * (3 / 4)) && ray->angle <= (M_PI * (5 / 4)))
		ray->orientation = 'W';
	else if (ray->angle >= (M_PI * (5 / 4)) && ray->angle <= (M_PI * (7 / 4)))
		ray->orientation = 'N';
	else /*if (ray->angle >= (M_PI * (7 / 4)) || ray->angle <= (M_PI / 4))*/
		ray->orientation = 'E';
}

/* Tells the sign of the steps based on the ray's angle */
/* Take the angle of a ray and the type of step (x or y) */
/* Returns the sign of the step */
int	step_sign(double angle, char c)
{
	float	pi;

	pi = M_PI;
	if (c == 'x')
	{
		if (angle == (pi / 2) || angle == (pi * 3 / 2))
			return (0);
		else if (angle > (pi / 2) && angle < (pi * 3 / 2))
			return (-1);
	}
	else
	{
		if (!angle || angle == pi)
			return (0);
		else if (angle > pi)
			return (-1);
	}
	return (1);
}

/* Set the angle between 0 and 2PI */
/* Take an angle as argument */
void	norm_angle(double *angle)
{
	float	pi;

	pi = M_PI;
	while (*angle >= (2 * pi)) //remplace les if par des while
		*angle -= 2 * pi;
	while (*angle < 0)
		*angle += 2 * pi;
}
