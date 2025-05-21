

#include "../../includes/cub3D.h"

// void *draw_ceiling_floor(t_data *img, int width, int height,
//                         unsigned int ceil_color, unsigned int floor_color)
// {
//     int x = 0;
//     int y = 0;

// // On suppose que img->addr est déjà initialisé ici
// while (y < height)
// {
//     x = 0;
//     while (x < width)
//     {
//         unsigned int color;
//         if (y < height / 2)
//             color = ceil_color;
//         else
//             color = floor_color;
//         ((unsigned int *)(img->addr))[y * (img->line_length / 4) + x] = color;
//         x++;
//     }
//     y++;
// }
// return img->img;
// }


    // mlx_put_image_to_window(mlx->ptr, mlx->win_ptr, mlx->img.img, 0, 0);


void refresh_image(t_mlx *mlx)
{
    // Détruit l'ancienne image si elle existe
    if (mlx->img.img)
        mlx_destroy_image(mlx->ptr, mlx->img.img);
    // Crée une nouvelle image
    
    mlx->img.img = mlx_new_image(mlx->ptr, WIN_WIDTH, WIN_HEIGHT);
    mlx->img.addr = mlx_get_data_addr(mlx->img.img, &(mlx->img.bits_per_pixel), &(mlx->img.line_length), &(mlx->img.endian));
    // Affiche l'image dans la fenêtre

    ray_iteration(mlx);
    mlx_put_image_to_window(mlx->ptr, mlx->win_ptr, mlx->img.img, 0, 0);
}