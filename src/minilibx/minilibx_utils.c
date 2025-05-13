/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picarlie <picarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:36:26 by picarlie          #+#    #+#             */
/*   Updated: 2025/05/07 17:17:13 by picarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

// Now we have the image address, but still no pixels.
// Before we start with this, we must understand that the bytes are not aligned,
// this means that the line_length differs from the actual window width.
// We therefore should ALWAYS calculate the memory offset using the line length set by mlx_get_data_addr.
// int	offset;
// offset = (y * img.line_length + x * (img.bits_per_pixel / 8));
// https://github.com/raveriss/cub3D/blob/main/srcs/draw/wall.c   Pour implementer le draw textures
void	init_mlx(t_mlx *mlx)
{
	
	int		img_width;
	int		img_height;
	char	*relative_path = "./ress/textures/mewtwo.xpm";
	mlx->ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->ptr, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	mlx->img.img = mlx_new_image(mlx->ptr, WIN_WIDTH, WIN_HEIGHT);
	mlx->img.img = mlx_xpm_file_to_image(mlx->ptr, relative_path, &img_width, &img_height);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img, &(mlx->img.bits_per_pixel), &(mlx->img.line_length), &(mlx->img.endian));
	mlx_put_image_to_window(mlx->ptr, mlx->win_ptr, mlx->img.img, 0, 0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}