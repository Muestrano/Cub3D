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
	if (ray->angle >= (M_PI * ((double)1 / 4)) && ray->angle <= (M_PI * ((double)3 / 4)) && ray->vertical == 0)
		ray->orientation = 'N';
	else if (ray->angle >= (M_PI * ((double)3 / 4)) && ray->angle <= (M_PI * ((double)5 / 4)) && ray->vertical == 1)
		ray->orientation = 'E';
	else if (ray->angle >= (M_PI * ((double)5 / 4)) && ray->angle <= (M_PI * ((double)7 / 4)) && ray->vertical == 0)
		ray->orientation = 'S';
	else /*if (ray->angle >= (M_PI * (7 / 4)) || ray->angle <= (M_PI / 4))*/
		ray->orientation = 'W';
	// printf("***ORIENTATION*******\n");
	// printf("angle = %f\n", ray->angle);
	// printf("orientation = %c\n", ray->orientation);
	// printf("***ORIENTATION*******\n");
}
/* Update the orientation of the ray */
/* Take the ray struct pointer */
// void	ray_orientation(t_ray *ray)
// {
// 	double	check_angle;

// 	check_angle = ray->angle / M_PI;
// 	if (check_angle >= (0.25) && check_angle <= (0.75))
// 		ray->orientation = 'N';
// 	else if (check_angle >= (0.75) && check_angle <= (1.25))
// 		ray->orientation = 'E';
// 	else if (check_angle >= (1.25) && check_angle <= (1.75))
// 		ray->orientation = 'S';
// 	else /*if (ray->angle >= (M_PI * (7 / 4)) || ray->angle <= (M_PI / 4))*/
// 		ray->orientation = 'W';

// 	printf("***ORIENTATION*******\n");
// 	printf("angle = %f\n", ray->angle);
// 	printf("checkangle = %f\n", check_angle);
// 	printf("orientation = %c\n", ray->orientation);
// 	printf("***ORIENTATION*******\n");
// }

/* Tells the sign of the steps based on the ray's angle */
/* Take the angle of a ray and the type of step (x or y) */
/* Returns the sign of the step */
int	step_sign(double angle, char c)
{
	if (c == 'x')
	{
		if (angle == (M_PI * ((double) 1/ 2)) || angle == (M_PI * ((double)3 / 2)))
			return (0);
		else if (angle > (M_PI * ((double)1 / 2)) && angle < (M_PI * ((double)3 / 2)))
			return (-1);
	}
	else
	{
		if (!angle || angle == M_PI)
			return (0);
		else if (angle > M_PI)
			return (-1);
	}
	return (1);
}

/* Set the angle between 0 and 2PI */
/* Take an angle as argument */
void	norm_angle(double *angle)
{
	while (*angle >= (double)(2 * M_PI)) //remplace les if par des while
		*angle -= (double)2 * M_PI;
	while (*angle < 0)
		*angle += (double)2 * M_PI;
}
