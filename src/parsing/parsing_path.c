#include "../../includes/cub3D.h"

int ft_strcmp(char *s1, char *s2)
{
	int i = 0;
	while(s1)
	{
		if(s1[i]!= s2[i])
			return(s2[i] -s1[i]);
	}
}

static size_t	ft_countword(char const *s, char c)
{
	size_t	count;

	if (!*s)
		return (0);
	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**lst;
	size_t	word_len;
	int		i;

	lst = (char **)malloc((ft_countword(s, c) + 1) * sizeof(char *));
	if (!s || !lst)
		return (0);
	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			if (!ft_strchr(s, c))
				word_len = ft_strlen(s);
			else
				word_len = ft_strchr(s, c) - s;
			lst[i++] = ft_substr(s, 0, word_len);
			s += word_len;
		}
	}
	lst[i] = NULL;
	return (lst);
}

char *ft_strcpy(char* src, char *delim)
{
	int i = 0;
	int j = 0;

	while(src)
	{
		i++;

	}
}

int valid_carac(char c)
{

}