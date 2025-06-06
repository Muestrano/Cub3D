#include "../../includes/cub3D.h"

void	init_player(t_player *player, t_map *map)
{
	player->p_x = map->x_init * TILE_SIZE;
	player->p_y = map->y_init * TILE_SIZE;
	if (map->init_orientation == 'N')
		player->p_angle = M_PI * 1.5;
	else if (map->init_orientation == 'S')
		player->p_angle = M_PI / 2;
	else if (map->init_orientation == 'W')
		player->p_angle = M_PI;
	else if (map->init_orientation == 'E')
		player->p_angle = 0;
	return;
}

void treatment_texture(t_mlx *mlx)
{
	treat_text(mlx->ptr, &mlx->text_east, mlx->texture.north);
	treat_text(mlx->ptr, &mlx->text_west, mlx->texture.south);
	treat_text(mlx->ptr, &mlx->text_north, mlx->texture.west);
	treat_text(mlx->ptr, &mlx->text_south, mlx->texture.east);
}

void treat_text(void *mlx_ptr, t_tex *tex, char* path)
{
    tex->path = path;
	if (!tex || !tex->path)
        return;
    tex->img_pointer = mlx_xpm_file_to_image(mlx_ptr, tex->path, &tex->width, &tex->height);
    if (!tex->img_pointer)
    {
        printf("Error: Failed to load texture: %s\n", tex->path);
        return;
    }
    tex->buffer = mlx_get_data_addr(tex->img_pointer, &tex->bits_per_pixel, &tex->line_length, &tex->endian);

	if (!tex->buffer)
	{
		printf("Error: Failed to get data address for texture: %s\n", tex->path);
		return;
	}
	tex->texx = 0; // Initialize texx
	tex->texy = 0; // Initialize texy
}