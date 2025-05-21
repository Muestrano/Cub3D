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
            // draw_text(mlx->img, ?????????, x, j); // En chantier :)
            color = 0;
            my_mlx_pixel_put(&mlx->img, x, j, color);
        }
        if (j > ray->wall_bottom_pixel)
        {
            color = mlx->texture.floor_color; // Replace with actual texture color
            my_mlx_pixel_put(&mlx->img, x, j, color);
        }
        j++;
    }
}

// void	draw_oriented_text(t_data *img, t_tex *tex, int x , int y)
// {
//     if (!tex || !tex->buffer)
//         return;
//     if (tex->texx < 0 || tex->texx >= tex->width || tex->texy < 0 || tex->texy >= tex->height)
//         return;
//     char *pixel = tex->buffer + (tex->texy * tex->line_length + tex->texx * (tex->bits_per_pixel / 8));
//     int color = *(unsigned int *)pixel;
//     my_mlx_pixel_put(img, x, y, color);
// }

void print_texture_treated(t_tex *tex)
{
    if (!tex || !tex->buffer)
        return;
    printf("Texture path: %s\n", tex->path);
    printf("Width: %d, Height: %d\n", tex->width, tex->height);
    printf("Bits per pixel: %d, Line length: %d, Endian: %d\n", tex->bits_per_pixel, tex->line_length, tex->endian);
}

void	draw_oriented_text(t_data *img, t_tex *imgtext, int x, int y)
{
    if (!imgtext || !imgtext->buffer)
        return;
    if (imgtext->texx < 0 || imgtext->texx >= imgtext->width || imgtext->texy < 0 || imgtext->texy >= imgtext->height)
        return;
    char *pixel = imgtext->buffer + (imgtext->texy * imgtext->line_length + imgtext->texx * (imgtext->bits_per_pixel / 8));
    int color = *(unsigned int *)pixel;
    my_mlx_pixel_put(img, x, y, color);
}
// void free_texture(t_tex *tex)
// {
//     if (tex)
//     {
//         if (tex->img_pointer)
//             mlx_destroy_image(tex->img_pointer);
//         if (tex->buffer)
//             free(tex->buffer);
//         free(tex);
//     }
// }