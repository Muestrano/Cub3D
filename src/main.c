/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picarlie <picarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:45:14 by picarlie          #+#    #+#             */
/*   Updated: 2025/05/12 17:57:48 by picarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int close_window(void *param)
{
    (void)param;
    exit(0); // Quitte proprement le programme
    //close (fd) et frees.
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
    t_mlx	mlx;

    init_map(&map);
    init_texture(&texture);
    init_mlx(&mlx);

    // Exemple d'utilisation de mlx_win : gestion de la fermeture de la fenêtre
    mlx_hook(mlx.win_ptr, 17, 0, close_window, NULL); // Fermer avec la croix
   

    fd = open_args(ac, av, map);
    // read_args(fd, map);
    // extract_texture(map->buffer, texture);
    // verify_texture(texture);
    // extract_map(map->buffer, map);
    // print_map(map);
    // verify_map(map);
    // parse_map(map);
    // check_border_map(map->map_brute);
    // print_map(map);

	mlx_loop(mlx.ptr);
    close(fd);
    return (0);
}