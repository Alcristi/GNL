#include"get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*conc;
	size_t	i;
	size_t	size_s1;
	size_t	size_s2;

	i = 0;
	size_s1 = 0;
	size_s2 = 0;
	while (s1[size_s1])
		size_s1++;
	while (s2[size_s2])
		size_s2++;
	conc = malloc((size_s2 + size_s1 + 1) * sizeof(char));
	while (i < size_s1)
	{
		conc[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < size_s2)
	{
		conc[i + size_s1] = s2[i];
		i++;
	}
	conc[size_s2 + size_s1] = '\0';
	free(s1);
	return (conc);
}

char	*ft_strdup(const char *s1)
{
	char	*dup;
	int		i;
	int		size;

	size = 0;
	i = 0;
	while (s1[size])
		size++;
	dup = (char *)malloc(sizeof(char) * (size + 1));
	while (s1[i])
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	size;

	size = 0;
	while (s[size])
		size++;
	i = 0;
	if (c == '\0')
		return ((char *) s + size);
	if (c > 256)
		c -= 256;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *) &s[i]);
		i++;
	}
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	size;
	size_t	i;
	char	*sub;

	if (!s)
		return (NULL);
	i = 0;
	size = 0;
	while (s[size])
		size++;
	if ((size - 1 < start))
		len = 0;
	if ((size + 1) < len + 1)
		sub = (char *)malloc(size + 1);
	else if (len == size)
		sub = (char *)malloc((len - start) + 1);
	else
		sub = (char *)malloc(len + 1);
	if (!sub)
		return (NULL);
	while ((i < len) && (start + i) < size)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
