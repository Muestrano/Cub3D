#include "../includes/cub3D.h"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		write(2, "Error\nWrong number of arguments\n", 33);
		return (1);
	}
	t_map *map;
	t_texture *texture;
	// t_game *game;
	// t_player *player;
	int fd;

	init_map(&map);
	init_texture(&texture);

	// init_game(&game);
	// init_player(&player);
	// init_ray(&ray);
	// init_mlx(&mlx);


	fd = open_args(ac, av, map);
	read_args(fd, map);
	printf("Buffer: %s\n", map->buffer);

	extract_texture(map->buffer, texture);
	printf("texture ok\n");
	extract_map(map->buffer, map);
	printf("map ok\n");
	print_map(map);
	printf("replace position\n");
	parse_map(map);
	print_map(map);
	printf("map ok\n");

	// test
	print_map(map);
	// print_texture(*texture);
	// test 
	// print_struct(*map);
	// printf("%s", map->path);

	close(fd);
	return (0);
}