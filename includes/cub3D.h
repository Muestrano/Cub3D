/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picarlie <picarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:54:44 by picarlie          #+#    #+#             */
/*   Updated: 2025/05/12 16:58:54 by picarlie         ###   ########.fr       */
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
# include "../ress/minilibx-linux/mlx.h" // include the mlx library
# include "../ress/minilibx-linux/mlx_int.h" 

# define TILE_SIZE 30 // Size of a tile (in pixels)
# define FOV 60 // Field of view
# define WIN_WIDTH 1920 // WIDTH of the window
# define WIN_HEIGHT 1080 // HEIGHT of the window

/*differencier les infos de la map avec les textures */
typedef struct s_map
{
	char	*path;
	char	buffer[2048];
	char	**map_brute;
	char	init_orientation;
	char	x_init;
	char	y_init;
	int		map_width;
	int		map_height;
}	t_map;

/* Texture structure */
/* Contains the path to the textures */
typedef struct s_texture
{
	char	*south;
	char	*north;
	char	*west;
	char	*east;
	char	*floor;
	char	*ceiling;
}	t_texture;

/* Ray structure */
/* Contains the angle of a ray and the distance to the wall  */
/* Contains the positions of the top and bot pixels of a wall strip (ray) */
/* Contains the height of the wall strip */
typedef struct s_ray
{
	double	angle;
	double	dist;
	int		wall_strip_height;
	int		wall_top_pixel;
	int		wall_bottom_pixel;
}	t_ray;

/* Player raycasting structure */
/* Contains the player position (x,y) in pixels (useful ??????????)*/
/* The player angle in radians */
/* The field of view in radians */
typedef struct s_player
{
	int		p_x;
	int		p_y;
	double	p_angle;
}	t_player;


/*s_data, structure for mlx img*/
typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;


// /* Player struct in the game */
// /* Define the player position in the map (in tiles) */
// /* And the player's movement's entries */
// /* Added tile size (in pixels) for zoom in/out (here to put ?????) */
// typedef struct	s_game
// {
// 	int	pos_x;
// 	int	pos_y;
// 	int	up_down;
// 	int	right_left;
// 	int	tile_size;
// }t_game;

/* Function prototypes */

void revise_buffer(t_map *map);

int		open_args(int ac, char **av, t_map *map);
int		read_args(int fd, t_map *map);
void	init_map(t_map **map);
void	init_struct(t_map *map, t_texture *texture);
void	init_texture(t_texture **texture);
char	**init_mapbrute(t_map *map);

/*Print Function*/
void	print_map(t_map *map);
void	print_texture(t_texture texture);
void	print_struct(t_map map);
void	check_border_map(char **map_brute);

// void print_player(t_player player);
// void print_game(t_game game);
// void print_ray(t_ray ray);
// void print_all(t_map map, t_texture texture, t_player player, t_game game);
/*Extract functions*/
void 	verify_texture(t_texture *texture);
void 	verify_map(t_map *map);
void	extract_texture(char *buffer, t_texture *texture);
void	extract_map(char *buffer, t_map *map);
void	parse_map(t_map *map);
void	check_opti_map(char **map_brute);
void	replace_position(t_map *map, int i, int j);
int 	invalid_wall(char **map_brute);


/*	Free function*/	
void	free_split(char **split);
// void free_texture(t_texture *texture);
// void free_map(t_map *map);
// void free_game(t_game *game);
// void free_player(t_player *player);
// void free_all(t_map *map, t_texture *texture, t_player *player, t_game *game);

/*parsing_path*/
int		ft_strcmp(char *s1, char *s2);
char	**ft_split(char *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(char *str);
char	*ft_strcpy(char *src);

/* raycasting_utils */
int		step_sign(double angle, char c);
void	norm_angle(double *angle);

/* raycasting_iteration */
// int		is_wall(double x_inter, double y_inter, t_map map);
// void	horizontal_check(t_ray *ray, t_map map, t_player player);
// void	vertical_check(t_ray *ray, t_map map, t_player player);
// void	ray_iteration(t_mlx *mlx, t_ray *ray, t_map map, t_player player);

/*MLX Function*/
/*minilibx_utils*/
void init_data(void *mlx, void *mlx_win, t_data *img);
void my_mlx_pixel_put(t_data *data, int x, int y, int color);

/*draw_wall*/
void draw_text(t_data *data, t_img *imgtext, int x, int y);

/*player_movements*/
void up_movements(t_player *player, t_map map);
void down_movements(t_player *player, t_map map);
void right_movements(t_player *player, t_map map);
void left_movements(t_player *player, t_map map);
int  ft_key(int key, t_player *player, t_map map);

/*player_rotation*/
void right_rot_angle(t_player *player);
void left_rot_angle(t_player *player);

#endif