#include "../../includes/cub3D.h"

// int ft_strcmp(char *s1, char *s2)
// {
// 	int i = 0;
// 	while(s1)
// 	{
// 		if(s1[i]!= s2[i])
// 			return(s2[i] -s1[i]);
// 	}
// }

// static size_t	ft_countword(char const *s, char c)
// {
// 	size_t	count;

// 	if (!*s)
// 		return (0);
// 	count = 0;
// 	while (*s)
// 	{
// 		while (*s == c)
// 			s++;
// 		if (*s)
// 			count++;
// 		while (*s != c && *s)
// 			s++;
// 	}
// 	return (count);
// }

// char	**ft_split(char const *s, char c)
// {
// 	char	**lst;
// 	size_t	word_len;
// 	int		i;

// 	lst = (char **)malloc((ft_countword(s, c) + 1) * sizeof(char *));
// 	if (!s || !lst)
// 		return (0);
// 	i = 0;
// 	while (*s)
// 	{
// 		while (*s == c && *s)
// 			s++;
// 		if (*s)
// 		{
// 			if (!ft_strchr(s, c))
// 				word_len = ft_strlen(s);
// 			else
// 				word_len = ft_strchr(s, c) - *s;
// 			lst[i++] = ft_substr(s, 0, word_len);
// 			s += word_len;
// 		}
// 	}
// 	lst[i] = NULL;
// 	return (lst);
// }
// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	char	*substr;
// 	size_t	i;

// 	if (!s)
// 		return (0);
// 	if (start >= ft_strlen(s))
// 		return (ft_strdup(""));
// 	if (len > ft_strlen(s) - start)
// 		len = ft_strlen(s) - start;
// 	substr = (char *)malloc((len + 1) * sizeof(char));
// 	if (!substr)
// 		return (0);
// 	i = 0;
// 	while (i < len && s[start])
// 	{
// 		substr[i] = s[start];
// 		i++;
// 		start++;
// 	}
// 	substr[i] = '\0';
// 	return (substr);
// }
// char	*ft_strdup(const char *s1)
// {
// 	char	*str;
// 	size_t	i;

// 	str = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
// 	if (!str)
// 		return (0);
// 	i = 0;
// 	while (s1[i])
// 	{
// 		str[i] = s1[i];
// 		i++;
// 	}
// 	str[i] = '\0';
// 	return (str);
// }
// char	*ft_strchr(const char *s, int c)
// {
// 	while (*s)
// 	{
// 		if (*s == (char)c)
// 			return ((char *)s);
// 		s++;
// 	}
// 	if (c == '\0')
// 		return ((char *)s);
// 	return (0);
// }
// size_t	ft_strlen(const char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	while (s[i])
// 		i++;
// 	return (i);
// }

// int ft_strncmp(const char *s1, const char *s2, size_t n)
// {
// 	size_t	i;

// 	i = 0;
// 	while (i < n && s1[i] && s2[i])
// 	{
// 		if (s1[i] != s2[i])
// 			return (s1[i] - s2[i]);
// 		i++;
// 	}
// 	if (i == n)
// 		return (0);
// 	return (s1[i] - s2[i]);
// }