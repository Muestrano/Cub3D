#include "../../includes/cub3D.h"

// void	draw_text(t_data *data, t_img *imgtext, int x, int y)
// {
// 	int	color;

// 	color = get_text_color(imgtext->ptr, data->ray.texx, data->ray.texy);
// 	my_mlx_pixel_put(&data->img, x, y, color);
// }

void draw_wall(t_mlx *mlx, t_ray *ray, int x)
{
    int		j;
    int		color;

    j = 0;
    while (j < WIN_HEIGHT)
    {
        if (j < ray->wall_top_pixel)
        {
            color = mlx->texture.ceiling_color; // Replace with actual texture color
            my_mlx_pixel_put(&mlx->img, x, j, color);
        }
        if (j >= ray->wall_top_pixel && j <= ray->wall_bottom_pixel)
        {
            draw_texture(mlx, ray, x); // En chantier :)
        }
        if (j > ray->wall_bottom_pixel)
        {
            color = mlx->texture.floor_color; // Replace with actual texture color
            my_mlx_pixel_put(&mlx->img, x, j, color);
        }
        j++;
    }
}

void calculate_texx(t_mlx *mlx, t_ray *ray)
{
    double wall_x;
    t_tex *tex;

    // Sélectionne la bonne texture selon l’orientation du mur
    if (ray->orientation == 'N')
        tex = &mlx->text_north;
    else if (ray->orientation == 'S')
        tex = &mlx->text_south;
    else if (ray->orientation == 'E')
        tex = &mlx->text_east;
    else // 'W'
        tex = &mlx->text_west;

    // Calcule la position précise de l’impact sur le mur (fraction de case)
    if (ray->orientation == 'N' || ray->orientation == 'S')
        wall_x = mlx->player.p_x / TILE_SIZE + ray->dist * cos(ray->angle);
    else
        wall_x = mlx->player.p_y / TILE_SIZE + ray->dist * sin(ray->angle);

    wall_x -= floor(wall_x); // on garde la partie fractionnaire

    // Convertit en coordonnée X de texture
    tex->texx = (int)(wall_x * (double)(tex->width));

    // Inversion si nécessaire pour éviter l’effet miroir
    // if ((ray->orientation == 'E' && ray->angle > M_PI) || 
    //     (ray->orientation == 'S' && ray->angle < M_PI / 2) || 
    //     (ray->orientation == 'N' && ray->angle > 3 * M_PI / 2))
    // {
    //     tex->texx = tex->width - tex->texx - 1;
    // }

    // Clamp pour éviter les débordements
    if (tex->texx < 0)
        tex->texx = 0;
    if (tex->texx >= tex->width)
        tex->texx = tex->width - 1;
}

// void draw_texture(t_mlx *mlx, t_ray *ray, t_tex *tex, int x)
// {
//     int y;
//     double step;
//     double tex_pos;

//     if (!tex || !tex->buffer)
//         return;

//     // Calcul du ratio de progression dans la texture
//     step = (double)tex->height / ray->wall_strip_height;
//     // Position de départ dans la texture (axe Y)
//     tex_pos = (ray->wall_top_pixel - WIN_HEIGHT / 2 + ray->wall_strip_height / 2) * step;

//     y = ray->wall_top_pixel;
//     while (y <= ray->wall_bottom_pixel)
//     {
//         tex->texy = (int)tex_pos;
//     // Clamp tex_y pour éviter les débordements
//         if (tex->texy < 0)
//             tex->texy = 0;
//         if (tex->texy >= tex->height)
//             tex->texy = tex->height - 1;

//     // Calcul de la position du pixel dans le buffer de la texture
//         char *pixel = tex->buffer + (tex->texy * tex->line_length + tex->texx * (tex->bits_per_pixel / 8));
//         int color = *(unsigned int *)pixel;

//         my_mlx_pixel_put(&mlx->img, x, y, color);
//         tex_pos += step;
//         y++;
//     }
// }

void draw_texture(t_mlx *mlx, t_ray *ray, int x)
{
    t_tex   *tex;
    int     y;
    double  step;
    double  tex_pos;

    // Sélectionne la bonne texture selon l’orientation du mur
    if (ray->orientation == 'N')
        tex = &mlx->text_north;
    else if (ray->orientation == 'S')
        tex = &mlx->text_south;
    else if (ray->orientation == 'E')
        tex = &mlx->text_east;
    else // 'W'
        tex = &mlx->text_west;

    if (!tex || !tex->buffer)
        return;

    // Calcul du ratio de progression dans la texture
    step = (double)tex->height / ray->wall_strip_height;
    // Position de départ dans la texture (axe Y)
    tex_pos = (ray->wall_top_pixel - WIN_HEIGHT / 2 + ray->wall_strip_height / 2) * step;

    y = ray->wall_top_pixel;
    while (y <= ray->wall_bottom_pixel)
    {
        tex->texy = (int)tex_pos;
        // Clamp tex_y pour éviter les débordements
        if (tex->texy < 0)
            tex->texy = 0;
        if (tex->texy >= tex->height)
            tex->texy = tex->height - 1;

        // Calcul de la position du pixel dans le buffer de la texture
        char *pixel = tex->buffer + (tex->texy * tex->line_length + tex->texx * (tex->bits_per_pixel / 8));
        int color = *(unsigned int *)pixel;

        my_mlx_pixel_put(&mlx->img, x, y, color);
        tex_pos += step;
        y++;
    }
}
