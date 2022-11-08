char	*ft_strchr(const char *s, int c)
{
	char	*str;

	if (c > 256)
		c %= 256;
	while (*s != c && *s != 0)
		s++;
	if (*s == 0 && c != 0)
		return (0);
	str = (char *)s;
	return (str);
}
void	*ft_calloc(int count, int size)
{
	char	*str;
	int		i;

	str = malloc(size * count);
	if (!str)
		return (0);
	i = -1;
	while (++i < (size * count))
		str[i] = 0;
	return ((void *)str);
}

