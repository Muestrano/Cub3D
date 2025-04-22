#include "../includes/cub3D.h"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		write(2, "Error\nWrong number of arguments\n", 33);
		return (1);
	}
	t_map *map;
	int fd;
	init_map(&map);
	fd = open_args(ac, av, map);
	read_args(fd, map);
	print_struct(*map);
	close(fd);
	return (0);
}