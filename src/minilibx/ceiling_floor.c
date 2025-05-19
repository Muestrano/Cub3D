

#include "../../includes/cub3D.h"


#include "../../includes/cub3D.h"

void init_color(t_mlx *mlx, t_texture *texture)
{
    texture->ceiling_color = parse_color(texture->ceiling);
    texture->floor_color = parse_color(texture->floor);

    mlx->img.img = mlx_new_image(mlx->ptr, WIN_WIDTH, WIN_HEIGHT);
    draw_ceiling_floor(&mlx->img, WIN_WIDTH, WIN_HEIGHT,
                       texture->ceiling_color, texture->floor_color);

    mlx->img.addr = mlx_get_data_addr(mlx->img.img, &(mlx->img.bits_per_pixel), &(mlx->img.line_length), &(mlx->img.endian));
    mlx_put_image_to_window(mlx->ptr, mlx->win_ptr, mlx->img.img, 0, 0);
}

void *draw_ceiling_floor(t_data *img, int width, int height,
                        unsigned int ceil_color, unsigned int floor_color)
{
    int x, y;

    // On suppose que img->addr est déjà initialisé ici
    for (y = 0; y < height; y++)
    {
        for (x = 0; x < width; x++)
        {
            unsigned int color = (y < height / 2) ? ceil_color : floor_color;
            ((unsigned int *)(img->addr))[y * (img->line_length / 4) + x] = color;
        }
    }
    return img->img;
}

void refresh_image(t_mlx *mlx)
{
    // Détruit l'ancienne image si elle existe
    if (mlx->img.img)
        mlx_destroy_image(mlx->ptr, mlx->img.img);

    // Crée une nouvelle image
    mlx->img.img = mlx_new_image(mlx->ptr, WIN_WIDTH, WIN_HEIGHT);
    mlx->img.addr = mlx_get_data_addr(mlx->img.img, &(mlx->img.bits_per_pixel), &(mlx->img.line_length), &(mlx->img.endian));

    // Dessine ce que tu veux ici (ex: draw_ceiling_floor, draw_player, etc.)
    draw_ceiling_floor(&mlx->img, WIN_WIDTH, WIN_HEIGHT, mlx->texture.ceiling_color, mlx->texture.floor_color);

    // Affiche l'image dans la fenêtre
    mlx_put_image_to_window(mlx->ptr, mlx->win_ptr, mlx->img.img, 0, 0);
}