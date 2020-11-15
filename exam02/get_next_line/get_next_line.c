#include "get_next_line.h"

/*
** Util
*/

static size_t		ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static char			*ft_strchr(const char *s, int c)
{
	if (!s)
		return (0);
	while (*s != (unsigned char)c)
	{
		if (*s == 0)
			return (0);
		++s;
	}
	return ((char*)s);
}

static char			*ft_strdup(const char *s)
{
	char	*ret;
	int		i;

	if (!(ret = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (0);
	i = 0;
	while (s[i])
	{
		ret[i] = s[i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}

static char			*ft_strjoin(char *s1, char *s2)
{
	int		len;
	char	*str;
	int		i;

	if (!s1 && !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	i = -1;
	if (str)
	{
		while (*s1)
			str[++i] = *s1++;
		while (*s2)
			str[++i] = *s2++;
	}
	str[++i] = 0;
	return (str);
}

static char			*ft_strappend(char *s1, char *s2)
{
	char *tmp;

	if (!s1)
	{
		s1 = ft_strdup(s2);
		return (s1);
	}
	else
	{
		tmp = ft_strjoin(s1, s2);
		free(s1);
		s1 = tmp;
		return (s1);
	}
}

/*
** get_next_line
*/

static int		ft_getline(char *strs, char **line, char *ptr, int fd)
{
	char *tmp;

	if (ptr != 0)
	{
		*ptr = 0;
		*line = ft_strdup(strs);
		tmp = ft_strdup(ptr + 1);
		free(strs);
		strs = tmp;
		return (1);
	}
	if (strs[fd] != 0)
	{
		*line = strs;
		strs = 0;
	}
	else
		*line = ft_strdup("");
	return (0);
}

int		get_next_line(char **line)
{
	static char		*strs;
	char			buf[BUFFER_SIZE + 1];
	int				rd_size;
	char			*ptr;

	if (!line || BUFFER_SIZE < 1)
		return (-1);
	while ((ptr = ft_strchr(strs, '\n')) == 0
			&& (rd_size = read(0, buf, BUFFER_SIZE)) > 0)
	{
		buf[rd_size] = 0;
		strs = ft_strappend(strs, buf);
	}
	if (rd_size < 0)
		return (-1);
	return (ft_getline(strs, line, ptr, 0));
}
