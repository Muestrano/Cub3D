#include "../includes/cub3D.h"

int close_window(void *param)
{
    (void)param;
    exit(0); // Quitte proprement le programme
}


// void    my_mlx_pixel_put(t_datadata, int x, int y, int color)
// {
//     char    dst;

//     dst = data->addr + (y data->line_length + x * (data->bits_per_pixel / 8));
//     (unsigned int)dst = color;
// }

int main(int ac, char **av)
{
    if (ac != 2)
    {
        write(2, "Error\nWrong number of arguments\n", 33);
        return (1);
    }

    t_map *map;
    t_texture *texture;
    int fd;

    init_map(&map);
    init_texture(&texture);

    void *mlx;
    void *mlx_win;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");

    // Exemple d'utilisation de mlx_win : gestion de la fermeture de la fenêtre
    mlx_hook(mlx_win, 17, 0, close_window, NULL); // Fermer avec la croix
   

    fd = open_args(ac, av, map);
    read_args(fd, map);
    extract_texture(map->buffer, texture);
    verify_texture(texture);
    extract_map(map->buffer, map);
    print_map(map);
    verify_map(map);
    parse_map(map);
	check_opti_map(map->map_brute);
	if(invalid_wall(map->map_brute) == 0)
	{
		printf("Error\nInvalid wall in the map\n");
		exit(1);
	}
    print_map(map);

	mlx_loop(mlx);
    close(fd);
    return (0);
}