#ifndef CUB3D_H
# define CUB3D_H

#include <stdio.h>
#include <unistd.h>
typedef struct s_map {
	char* south_tex;
	char* north_tex;
	char* west_tex;
	char* est_tex;
	char* floor;
	char* ceiling;
	char** map;
} t_map;

#endif