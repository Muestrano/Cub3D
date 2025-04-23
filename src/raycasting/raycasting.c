/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picarlie <picarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:56:28 by picarlie          #+#    #+#             */
/*   Updated: 2025/04/23 18:14:41 by picarlie         ###   ########.fr       */
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
		if (angle == (M_PI / 2) || angle == (M_PI * 3 / 2)) //comparison doesnt seem to work
			return (0);
		else if (angle > (M_PI / 2) && angle < (M_PI * 3 / 2))
			return (-1);
	}
	else
	{
		if (!angle || angle == M_PI) //comparison doesnt seem to work
			return (0);
		else if (angle > M_PI)
			return (-1);
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

/*Test for step_sign and norm_angle
int	main ()
{
	float	angle;

	angle = 3.9 * M_PI;
	printf("Angle : %f\n", angle);
	norm_angle(&angle);
	printf("Angle norme : %f\n", angle);
	printf("x : %d\ny : %d\n", step_sign(angle, 'x'), step_sign(angle, 'y'));
	return (0);
}*/