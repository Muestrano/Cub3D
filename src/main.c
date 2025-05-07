#include "../includes/cub3D.h"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		write(2, "Error\nWrong number of arguments\n", 33);
		return (1);
	}

	t_data *data;
	t_map *map;
	t_texture *texture;
	// t_game *game;
	// t_player *player;
	int fd;


	init_map(&map);
	init_texture(&texture);
	init_data(&data);
	// init_game(&game);
	// init_player(&player);
	// init_ray(&ray);



	fd = open_args(ac, av, map);
	read_args(fd, map);
	extract_texture(map->buffer, texture);
	verify_texture(texture);
	extract_map(map->buffer, map);
	print_map(map);
	verify_map(map);
	parse_map(map);
	print_map(map);
	


	// test
	// print_texture(*texture);
	// test 
	// print_struct(*map);
	// printf("%s", map->path);

	close(fd);
	return (0);
}