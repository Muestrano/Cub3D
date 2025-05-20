

#include "../../includes/cub3D.h"

void *draw_ceiling_floor(t_data *img, int width, int height,
                        unsigned int ceil_color, unsigned int floor_color)
{
    int x = 0;
    int y = 0;

// On suppose que img->addr est déjà initialisé ici
while (y < height)
{
    x = 0;
    while (x < width)
    {
        unsigned int color;
        if (y < height / 2)
            color = ceil_color;
        else
            color = floor_color;
        ((unsigned int *)(img->addr))[y * (img->line_length / 4) + x] = color;
        x++;
    }
    y++;
}
return img->img;
}


    // mlx_put_image_to_window(mlx->ptr, mlx->win_ptr, mlx->img.img, 0, 0);

void draw_wall(t_mlx *mlx, t_ray *ray)
{
    int x = 0;
    while (x < WIN_WIDTH)
    {
        int y = 0;
        // 1. Plafond
        while (y < ray->wall_strip_height)
        {
            my_mlx_pixel_put(&mlx->img, x, y, mlx->texture.ceiling_color);
            y++;
        }
        // 2. Mur
        while (y <= ray->wall_bottom_pixel && y < WIN_HEIGHT)
        {
            // Ici tu peux mettre la couleur du mur ou la texture
            my_mlx_pixel_put(&mlx->img, x, y, 0xAAAAAA); // gris pour exemple
            y++;
        }
        // 3. Sol
        while (y < WIN_HEIGHT)
        {
            my_mlx_pixel_put(&mlx->img, x, y, mlx->texture.floor_color);
            y++;
        }
        x++;
    }
}



void refresh_image(t_mlx *mlx, t_ray *ray)
{
    // Détruit l'ancienne image si elle existe
    if (mlx->img.img)
        mlx_destroy_image(mlx->ptr, mlx->img.img);
    // Crée une nouvelle image
    
    mlx->img.img = mlx_new_image(mlx->ptr, WIN_WIDTH, WIN_HEIGHT);
    mlx->img.addr = mlx_get_data_addr(mlx->img.img, &(mlx->img.bits_per_pixel), &(mlx->img.line_length), &(mlx->img.endian));

    // Dessine ce que tu veux ici (ex: draw_ceiling_floor, draw_player, etc.)
    draw_ceiling_floor(&mlx->img, WIN_WIDTH, WIN_HEIGHT, mlx->texture.ceiling_color, mlx->texture.floor_color);

    draw_wall(mlx, ray);
    // render_wall(mlx, ray);
    // Dessine le joueur   

    // Affiche l'image dans la fenêtre
    mlx_put_image_to_window(mlx->ptr, mlx->win_ptr, mlx->img.img, 0, 0);
}