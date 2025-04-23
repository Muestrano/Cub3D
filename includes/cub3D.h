/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picarlie <picarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:54:44 by picarlie          #+#    #+#             */
/*   Updated: 2025/04/22 14:45:05 by picarlie         ###   ########.fr       */
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
/*differencier les infos de la map avec les textures */
typedef struct s_map {
	char* path;
	char buffer[2048];
	char** map_brute;
	char init_orientation;
}t_map;

/* Texture structure */
/* Contains the path to the textures */
typedef struct s_texture
{
	char *SOUTH;
	char *NORTH;
	char *WEST;
	char *EAST;
	int floor;
	int ceiling;
}t_texture;


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
/* And the player's movement's entries */
/* Added tile size (in pixels) for zoom in/out (here to put ?????) */
typedef struct	s_game
{
	int	pos_x;
	int	pos_y;
	int	up_down;
	int	right_left;
	int	tile_size;
}t_game;

/* Function prototypes */
int open_args(int ac, char **av, t_map *map);
int read_args(int fd, t_map *map);
void init_map(t_map **map);
void init_struct(t_map *map, t_texture *texture);
void init_texture(t_texture **texture);
/*Print Function*/
void print_map(char **map);
void print_texture(t_texture texture);
void print_struct(t_map map);
// void print_player(t_player player);
// void print_game(t_game game);
// void print_ray(t_ray ray);
// void print_all(t_map map, t_texture texture, t_player player, t_game game);
/*Extract functions*/
void extract_texture(char *buffer, t_texture *texture);
void extract_map(char *buffer, t_map *map);
/*	Free function*/	
void free_split(char **split);
// void free_texture(t_texture *texture);
// void free_map(t_map *map);
// void free_game(t_game *game);
// void free_player(t_player *player);
// void free_all(t_map *map, t_texture *texture, t_player *player, t_game *game);

/*parsing_path*/
int ft_strcmp(char *s1, char *s2);
char	**ft_split(char *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
int ft_strncmp(const char *s1, const char *s2, size_t n);
int ft_atoi(char *str);

#endif