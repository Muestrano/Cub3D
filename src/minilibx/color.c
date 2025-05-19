#include "../../includes/cub3D.h"

int	ft_atoi_color(const char *str, int *i)
{
	int result = 0;

	while (str[*i] >= '0' && str[*i] <= '9')
	{
		result = result * 10 + (str[*i] - '0');
		(*i)++;
	}
	return result;
}
unsigned int	create_trgb(int t, int r, int g, int b)
{
	return ((t << 24) | (r << 16) | (g << 8) | b);
}

unsigned int	parse_color(char *line)
{
	int i = 0;
	int r, g, b;

	// Ignore les espaces
	while (line[i] == ' ')
		i++;

	// 1er nombre : Red
	r = ft_atoi_color(line, &i);
	if (r < 0 || r > 255)
		return (printf("Invalid red value\n"), exit(1), 0);

	if (line[i] != ',')
		return (printf("Expected ',' after red\n"), exit(1), 0);
	i++;

	// 2e nombre : Green
	g = ft_atoi_color(line, &i);
	if (g < 0 || g > 255)
		return (printf("Invalid green value\n"), exit(1), 0);

	if (line[i] != ',')
		return (printf("Expected ',' after green\n"), exit(1), 0);
	i++;

	// 3e nombre : Blue
	b = ft_atoi_color(line, &i);
	if (b < 0 || b > 255)
		return (printf("Invalid blue value\n"), exit(1), 0);

	// Vérifie qu’il ne reste que des espaces après
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\n')
			return (printf("Unexpected char after color\n"), exit(1), 0);
		i++;
	}

	return create_trgb(0, r, g, b);
}