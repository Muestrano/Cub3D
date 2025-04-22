/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picarlie <picarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:54:44 by picarlie          #+#    #+#             */
/*   Updated: 2025/04/21 16:59:58 by picarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
//# include "MLX/MLX42.h" // include the mlx library

typedef struct s_map {
	char* path;
	char buffer[2048];
	char* south_tex;
	char* north_tex;
	char* west_tex;
	char* est_tex;
	char* floor;
	char* ceiling;
	char** map_data;
}t_map;

/* Ray structure */
/* Contains the angle of a ray and the distance to the wall  */
typedef	struct s_ray
{
	double	angle;
	double	dist;
}t_ray;

/* Player raycasting structure */
/* Contains the player position (x,y) in pixels */
/* The player angle in radians */
/* The field of view in radians */
typedef struct	s_player
{
	int		p_x;
	int		p_y;
	double	p_angle;
	double	fov;
}t_player;

/* Player struct in the game */
/* Define the player position in the map (in tiles) */
/* And the player's movement (with mlx hook) */
typedef struct	s_game
{
	int	pos_x;
	int	pos_y;
	int	up_down;
	int	right_left;
}t_game;

/* Function prototypes */
int open_args(int ac, char **av, t_map *map);
int read_args(int fd, t_map *map);
int print_struct(t_map map);
void init_map(t_map **map);

/*parsing_path*/
int ft_strcmp(char *s1, char *s2);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
int ft_strncmp(const char *s1, const char *s2, size_t n);

#endif