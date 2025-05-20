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

int main(int ac, char **av)
{
    if (ac != 2)
    {
        write(2, "Error\nWrong number of arguments\n", 33);
        return (1);
    }

    t_mlx	mlx;
    int fd;
    

    init_map((t_map *)&mlx.map);
    init_texture((t_texture *)&mlx.texture);
    
    fd = open_args(ac, av, &mlx.map);
    read_args(fd, &(mlx.map));
    close(fd);
    
    extract_texture(mlx.map.buffer, &mlx);
    verify_texture(&mlx.texture);
    extract_map(mlx.map.buffer, &(mlx.map));
    verify_map(&mlx.map);
    parse_map(&mlx.map);
    check_border_map(mlx.map.map_brute);
    mlx.texture.ceiling_color = parse_color(mlx.texture.ceiling);
    mlx.texture.floor_color = parse_color(mlx.texture.floor);


	init_player((&mlx.player), &mlx.map);
    init_mlx(&mlx);
    refresh_image(&mlx);

	mlx_loop(mlx.ptr);

    return (0);
}