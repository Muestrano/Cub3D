/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenet <mabenet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:36:26 by picarlie          #+#    #+#             */
/*   Updated: 2025/05/07 17:16:04 by mabenet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void init_data(t_data **data)
{
	
}

// /* Takes the player structure */
// /* Change the angle of the player turning to the right */
// void	right_rot_angle(t_player *player)
// {
// 	(*player).p_angle += rot_speed;
// 	norm_angle((*player).p_angle);
// }

// /* Takes the player structure */
// /* Change the angle of the player turning to the left */
// void	left_rot_angle(t_player *player)
// {
// 	(*player).p_angle -= rot_speed;
// 	norm_angle((*player).p_angle);
// }

// /* Takes the player structure */
// /* Change the coordinates of the player moving forward */
// void	up_movements(t_player *player)
// {
// 	(*player).p_x += (cos((*player).p_angle) * step_sign((*player).p_angle, x) * playerSpeed);
// 	(*player).p_y += (sin((*player).p_angle) * step_sign((*player).p_angle, y) * playerSpeed);
// }

// /* Takes the player structure */
// /* Change the coordinates of the player moving backward */
// void	down_movements(t_player *player)
// {
// 	(*player).p_x -= (cos((*player).p_angle) * step_sign((*player).p_angle, x) * playerSpeed);
// 	(*player).p_y -= (sin((*player).p_angle) * step_sign((*player).p_angle, y) * playerSpeed);
// }
//  Mettre une protection pour les mouvements (check si wall ou obstacle)
//  Coder les mouvements droite et gauche