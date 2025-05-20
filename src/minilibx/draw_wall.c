#include "../../includes/cub3D.h"

// void	draw_text(t_data *data, t_img *imgtext, int x, int y)
// {
// 	int	color;

// 	color = get_text_color(imgtext->ptr, data->ray.texx, data->ray.texy);
// 	my_mlx_pixel_put(&data->img, x, y, color);
// }

// void draw_wall(t_mlx *mlx, t_ray *ray, int x)
// {
//     int		i;
//     int		j;
//     int		color;

//     i = 0;
//     while (i < WIN_WIDTH)
//     {
//         j = 0;
//         while (j < WIN_HEIGHT)
//         {
//             if (j >= ray->wall_top_pixel && j <= ray->wall_bottom_pixel)
//             {
//                 color = mlx->texture.ceiling_color; // Replace with actual texture color
//                 my_mlx_pixel_put(&mlx->img, i, j, color);
//             }
//             j++;
//         }
//         i++;
//     }
// }