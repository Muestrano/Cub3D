

#include "../../includes/cub3D.h"
#include "../../includes/cub3D.h"

#include "../../includes/cub3D.h"

void draw_ceiling_floor(t_mlx *mlx, t_texture *texture)
{
    int x, y;

    y = 0;
    while (y < WIN_HEIGHT) // Parcourt la hauteur de la fenêtre
    {
        x = 0;
        while (x < WIN_WIDTH) // Parcourt la largeur de la fenêtre
        {
            if (y < WIN_HEIGHT / 2) // Si on est dans la moitié supérieure (plafond)
                my_mlx_pixel_put(&mlx->img, x, y, texture->ceiling_color);
            else // Si on est dans la moitié inférieure (sol)
                my_mlx_pixel_put(&mlx->img, x, y, texture->floor_color);
            x++;
        }
        y++;
    }
}