/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picarlie <picarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:45:14 by picarlie          #+#    #+#             */
/*   Updated: 2025/05/12 16:30:52 by picarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int close_window(void *param)
{
    (void)param;
    exit(0); // Quitte proprement le programme
    //close (fd) et frees.
}


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

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

	void	*mlx;
	void	*mlx_win;
	t_data	img;
	t_data	*AAA;
	char	*relative_path = "./ress/textures/redbrick.xpm";
	int		img_width;
	int		img_height;

	// Now we have the image address, but still no pixels.
	// Before we start with this, we must understand that the bytes are not aligned,
	// this means that the line_length differs from the actual window width.
	// We therefore should ALWAYS calculate the memory offset using the line length set by mlx_get_data_addr.


	// int	offset;
	// offset = (y * img.line_length + x * (img.bits_per_pixel / 8));

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	img.img = mlx_new_image(mlx, WIN_WIDTH, WIN_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	// AAA->img = mlx_new_image(mlx, WIN_WIDTH, WIN_HEIGHT);
	// AAA->addr = mlx_get_data_addr(AAA->img, &(AAA->bits_per_pixel), &(AAA->line_length),
	// 		&(AAA->endian));
	AAA = &img;
	AAA++;
	AAA--;
	AAA = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	// printf("AAA : %p\n", AAA);
	// printf("AAA : %s\n", relative_path);
	// my_mlx_pixel_put(AAA, WIN_WIDTH / 2, WIN_HEIGHT / 2, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, AAA->img, 0, 0);

	
	// my_mlx_pixel_put(&img, WIN_WIDTH / 2, WIN_HEIGHT / 2, 0x00FF0000);
	// mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	

	
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
	if(invalid_wall(map->map_brute) == 1)
	{
		printf("Error\nInvalid wall in the map\n");
		exit(1);
	}
    print_map(map);

	mlx_loop(mlx);
    close(fd);
    return (0);
}